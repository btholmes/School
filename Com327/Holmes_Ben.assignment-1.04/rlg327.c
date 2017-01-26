#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>

#include "heap.h"

#define MAX 1681

int deletedMonsters[20];
int deletePosition = 0; 

/* Returns true if random float in [0,1] is less than *
 * numerator/denominator.  Uses only integer math.    */
# define rand_under(numerator, denominator) \
  (rand() < ((RAND_MAX / denominator) * numerator))

/* Returns random integer in [min, max]. */
# define rand_range(min, max) ((rand() % (((max) + 1) - (min))) + (min))
#define event_queue_size 99999


int gameTurn = 0;
int gameOver = 0;
int win = 0;
int monstersLeft = 0;


typedef enum dim {
  dim_x,
  dim_y,
  num_dims
} dim_t;

typedef enum direction {
  north,
  south,
  west,
  east,
  nw,
  ne,
  sw,
  se
} dirtection_t; 

typedef int16_t pair_t[num_dims];

typedef struct priority {
  pair_t position;
  int distance; 
} priority_t; 



void insert_by_priority(priority_t);
void delete_by_priority(priority_t);
void create();
void check(priority_t);
void display_pqueue();
void clear_pqueue(); 
priority_t pop();


priority_t pri_que[MAX];
int front, rear;

typedef struct corridor_path {
  heap_node_t *hn;
  uint8_t pos[2];
  uint8_t from[2];
  int32_t cost;
} corridor_path_t;

typedef struct distance {
  int dist;
  pair_t previous;
  pair_t next; 
}dist_t;

int visited[21][80];
dist_t distances[21][80];
pair_t shortestPath[110]; 

int queueSize = 0; 

#define DUNGEON_X              80
#define DUNGEON_Y              21
#define MIN_ROOMS              6
#define MAX_ROOMS              10
#define ROOM_MIN_X             4
#define ROOM_MIN_Y             3
#define ROOM_MAX_X             14
#define ROOM_MAX_Y             8
#define SAVE_DIR               ".rlg327"
#define DUNGEON_SAVE_FILE      "dungeon"
#define DUNGEON_SAVE_SEMANTIC  "RLG327"
#define DUNGEON_SAVE_VERSION   0U

//MONSTER SKILLS DEFINITIONS
const int monsterType0[4] = {0,0,0,0};
const int monsterType1[4] = {0,0,0,1};
const int monsterType2[4] = {0,0,1,0};
const int monsterType3[4] = {0,0,1,1};
const int monsterType4[4] = {0,1,0,0};
const int monsterType5[4] = {0,1,0,1};
const int monsterType6[4] = {0,1,1,0};
const int monsterType7[4] = {0,1,1,1};
const int monsterType8[4] = {1,0,0,0};
const int monsterType9[4] = {1,0,0,1};
const int monsterTypea[4] = {1,0,1,0};
const int monsterTypeb[4] = {1,0,1,1};
const int monsterTypec[4] = {1,1,0,0};
const int monsterTyped[4] = {1,1,0,1};
const int monsterTypee[4] = {1,1,1,0};
const int monsterTypef[4] = {1,1,1,1};


#define mappair(pair) (d->map[pair[dim_y]][pair[dim_x]])
#define mapxy(x, y) (d->map[y][x])
#define hardnesspair(pair) (d->hardness[pair[dim_y]][pair[dim_x]])
#define hardnessxy(x, y) (d->hardness[y][x])

priority_t tunnels[DUNGEON_Y][DUNGEON_X];
priority_t nonTunnels[DUNGEON_Y][DUNGEON_X]; 

typedef enum __attribute__ ((__packed__)) terraintype {
  ter_debug,
  ter_wall,
  ter_wall_immutable,
  ter_floor,
  ter_floor_room,
  ter_floor_hall,
  player,
  monster0,
  monster1,
  monster2,
  monster3,
  monster4,
  monster5,
  monster6,
  monster7,
  monster8,
  monster9,
  monstera,
  monsterb,
  monsterc,
  monsterd,
  monstere,
  monsterf,
} terrain_type_t;

typedef struct room {
  pair_t position;
  pair_t size;
  uint32_t connected;
} room_t;

typedef struct PC {
  pair_t position; 
}PC_t;

typedef struct Monster {

  pair_t position;
  pair_t lastPC; 
  int skills[4];
  terrain_type_t type; 
  int speed;
  int id;
  int view;
  int tunneling;
  int tunnelingX;
  int tunnelingY;
  int dead; 
  
}Monster_t;


typedef struct moveEvent {
  //boolean value to tell me if this event is for a monster or the player
  int isMonster; 
  int priority;  //gameTurn + turn; 
  //This is it's location in the Monster Array
  int id;
  int speed; 
  int turn; // 100\speed
  //use pointer to monster to determine whom to give the move too
} move_t; 

void insert_by_event_priority(move_t);
void delete_by_event_priority(move_t);
void create_event_queue();
void check_event(move_t);
void display_event_queue();
move_t event_pop(); 

move_t event_queue[event_queue_size];
int eventFront, eventRear;
int eventSize = 0; 
terrain_type_t dungeonCopy[DUNGEON_Y][DUNGEON_X];
Monster_t monsterArray[200]; 

typedef struct dungeon {
  uint32_t num_rooms;
  room_t *rooms;
  terrain_type_t map[DUNGEON_Y][DUNGEON_X];
  /* Since hardness is usually not used, it would be expensive to pull it *
   * into cache every time we need a map cell, so we store it in a        *
   * parallel array, rather than using a structure to represent the       *
   * cells.  We may want a cell structure later, but from a performanace  *
   * perspective, it would be a bad idea to ever have the map be part of  *
   * that structure.  Pathfinding will require efficient use of the map,  *
   * and pulling in unnecessary data with each map cell would add a lot   *
   * of overhead to the memory system.                                    */
  uint8_t hardness[DUNGEON_Y][DUNGEON_X];
} dungeon_t;


void putTunneling(PC_t* PC, dungeon_t *d);
void putNonTunnels(PC_t *PC, dungeon_t *d); 

/********************************START PRIORTY QUEUE *********************/


/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
}
void clear_pqueue(){

  int i;
  for(i = 0; i < 1681; i++){
    pop(); 
  }
  queueSize = 0; 
}

/* Function to insert value into priority queue */
void insert_by_priority(priority_t data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
	queueSize++; 
        return;
    }    
    else
        check(data);
    rear++;
}
priority_t pop(){

  //    printf("Popped %d\n", pri_que[front].distance);
  
    delete_by_priority(pri_que[front]); 
    return pri_que[front]; 
}
 
/* Function to check priority and place element */
void check(priority_t data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data.distance <= pri_que[i].distance)
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
	    queueSize++; 
            return;
        }
    }
    queueSize++; 
    pri_que[i] = data;
}
 
/* Function to delete an element from queue */
void delete_by_priority(priority_t data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
      //     printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data.distance == pri_que[i].distance)
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
 
        pri_que[i].distance = 99999;
	queueSize--; 
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data.distance);
}
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
      //      printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front].distance);
    }
 
    front = 0;
}

/********************************END PRIORTY QUEUE***************************/



/****************************************EVENT QUEUE START******************/

/* Function to create an empty priority queue */
void create_event_queue()
{
    eventFront = eventRear = -2;
   
}
 
/* Function to insert value into priority queue */
void insert_by_event_priority(move_t data)
{
  //   printf("in insert by priority  event player x %d, and y %d \n", data.monster->position[dim_x], data.monster->position[dim_y]);
  
    if (eventRear >= event_queue_size - 2)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((eventFront == -2) && (eventRear == -2))
    {
        eventFront++;
        eventRear++;
        event_queue[eventRear] = data;
	eventSize++; 
        return;
    }    
    else
        check_event(data);
    eventRear++;
}

move_t event_pop(){

  //  printf("Popped at 1 %d\n", event_queue[1].PC->position[dim_x]);
   move_t front = event_queue[eventFront];

   //printf("Front is %d\n", eventFront); 
  
    delete_by_event_priority(event_queue[eventFront]); 
    return front; 
}
 
/* Function to check priority and place element */
void check_event(move_t data)
{
  
    int i,j;
 
    for (i = 0; i <= eventRear; i++)
    {
        if (data.priority <= event_queue[i].priority)
        {
            for (j = eventRear + 1; j > i; j--)
            {
                event_queue[j] = event_queue[j - 1];
            }
            event_queue[i] = data;

	    
	    eventSize++; 
            return;
        }
    }
    eventSize++; 
    event_queue[i] = data;



}
 
/* Function to delete an element from queue */
void delete_by_event_priority(move_t data)
{

  //   printf("in top of delete x %d, y %d \n", data.PC->position[dim_x], data.PC->position[dim_y]); 

    int i;
 
    if ((eventFront==-2) && (eventRear==-2))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= eventRear; i++)
    {
        if (data.priority == event_queue[i].priority)
        {
            for (; i < eventRear; i++)
            {
                event_queue[i] = event_queue[i + 1];
            }

	    //   printf("in delete x %d, y %d \n", event_queue[i].PC->position[dim_x], event_queue[i].PC->position[dim_y]); 
        event_queue[i].priority = 99999;
        eventRear--;
	eventSize--;
	
	if (eventRear == -2) 
            eventFront = -2;
        return;
        }

    }
    //  printf("\n%d not found in queue to delete\n", data.priority);
}
 
/* Function to display queue elements */
void display_event_queue()
{
    if ((eventFront == -2) && (eventRear == -2))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; eventFront <= eventRear; eventFront++)
    {
      printf(" %d + id is %d\n", event_queue[eventFront].priority, event_queue[eventFront].id);
    }
 
    eventFront = 0;
}



/*****************************************EVENT QUEUE END********************/

void clearTunnels(){
  int i, j;
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      tunnels[i][j].distance = 0;
      nonTunnels[i][j].distance = 0; 
    }
  }
}


static uint32_t in_room(dungeon_t *d, int16_t y, int16_t x)
{
  int i;

  for (i = 0; i < d->num_rooms; i++) {
    if ((x >= d->rooms[i].position[dim_x]) &&
        (x < (d->rooms[i].position[dim_x] + d->rooms[i].size[dim_x])) &&
        (y >= d->rooms[i].position[dim_y]) &&
        (y < (d->rooms[i].position[dim_y] + d->rooms[i].size[dim_y]))) {
      return 1;
    }
  }

  return 0;
}

static int32_t corridor_path_cmp(const void *key, const void *with) {
  return ((corridor_path_t *) key)->cost - ((corridor_path_t *) with)->cost;
}

static void dijkstra_corridor(dungeon_t *d, pair_t from, pair_t to)
{
  static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < DUNGEON_Y; y++) {
      for (x = 0; x < DUNGEON_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, corridor_path_cmp, NULL);

  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      if (mapxy(x, y) != ter_wall_immutable) {
        path[y][x].hn = heap_insert(&h, &path[y][x]);
      } else {
        path[y][x].hn = NULL;
      }
    }
  }

  while ((p = heap_remove_min(&h))) {
    p->hn = NULL;

    if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
      for (x = to[dim_x], y = to[dim_y];
           (x != from[dim_x]) || (y != from[dim_y]);
           p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
        if (mapxy(x, y) != ter_floor_room) {
          mapxy(x, y) = ter_floor_hall;
          hardnessxy(x, y) = 0;
        }
      }
      heap_delete(&h);
      return;
    }

    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         p->cost + hardnesspair(p->pos))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        p->cost + hardnesspair(p->pos);
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         p->cost + hardnesspair(p->pos))) {
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost =
        p->cost + hardnesspair(p->pos);
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         p->cost + hardnesspair(p->pos))) {
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost =
        p->cost + hardnesspair(p->pos);
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         p->cost + hardnesspair(p->pos))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        p->cost + hardnesspair(p->pos);
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }
  }
}

/* This is a cut-and-paste of the above.  The code is modified to  *
 * calculate paths based on inverse hardnesses so that we get a    *
 * high probability of creating at least one cycle in the dungeon. */
static void dijkstra_corridor_inv(dungeon_t *d, pair_t from, pair_t to)
{
  static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
  static uint32_t initialized = 0;
  heap_t h;
  uint32_t x, y;

  if (!initialized) {
    for (y = 0; y < DUNGEON_Y; y++) {
      for (x = 0; x < DUNGEON_X; x++) {
        path[y][x].pos[dim_y] = y;
        path[y][x].pos[dim_x] = x;
      }
    }
    initialized = 1;
  }
  
  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      path[y][x].cost = INT_MAX;
    }
  }

  path[from[dim_y]][from[dim_x]].cost = 0;

  heap_init(&h, corridor_path_cmp, NULL);

  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      if (mapxy(x, y) != ter_wall_immutable) {
        path[y][x].hn = heap_insert(&h, &path[y][x]);
      } else {
        path[y][x].hn = NULL;
      }
    }
  }

  while ((p = heap_remove_min(&h))) {
    p->hn = NULL;

    if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
      for (x = to[dim_x], y = to[dim_y];
           (x != from[dim_x]) || (y != from[dim_y]);
           p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
        if (mapxy(x, y) != ter_floor_room) {
          mapxy(x, y) = ter_floor_hall;
          hardnessxy(x, y) = 0;
        }
      }
      heap_delete(&h);
      return;
    }

#define hardnesspair_inv(p) (in_room(d, p[dim_y], p[dim_x]) ? \
                             224                            : \
                             (255 - hardnesspair(p)))

    if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
         p->cost + hardnesspair_inv(p->pos))) {
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
        p->cost + hardnesspair_inv(p->pos);
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
                                           [p->pos[dim_x]    ].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
         p->cost + hardnesspair_inv(p->pos))) {
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost =
        p->cost + hardnesspair_inv(p->pos);
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] - 1].hn);
    }
    if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
        (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
         p->cost + hardnesspair_inv(p->pos))) {
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost =
        p->cost + hardnesspair_inv(p->pos);
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
                                           [p->pos[dim_x] + 1].hn);
    }
    if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
        (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
         p->cost + hardnesspair_inv(p->pos))) {
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
        p->cost + hardnesspair_inv(p->pos);
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
      path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
      heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
                                           [p->pos[dim_x]    ].hn);
    }
  }
}

/* Chooses a random point inside each room and connects them with a *
 * corridor.  Random internal points prevent corridors from exiting *
 * rooms in predictable locations.                                  */
static int connect_two_rooms(dungeon_t *d, room_t *r1, room_t *r2)
{
  pair_t e1, e2;

  e1[dim_y] = rand_range(r1->position[dim_y],
                         r1->position[dim_y] + r1->size[dim_y] - 1);
  e1[dim_x] = rand_range(r1->position[dim_x],
                         r1->position[dim_x] + r1->size[dim_x] - 1);
  e2[dim_y] = rand_range(r2->position[dim_y],
                         r2->position[dim_y] + r2->size[dim_y] - 1);
  e2[dim_x] = rand_range(r2->position[dim_x],
                         r2->position[dim_x] + r2->size[dim_x] - 1);

  /*  return connect_two_points_recursive(d, e1, e2);*/
  dijkstra_corridor(d, e1, e2);

  return 0;
}

static int create_cycle(dungeon_t *d)
{
  /* Find the (approximately) farthest two rooms, then connect *
   * them by the shortest path using inverted hardnesses.      */

  int32_t max, tmp, i, j, p, q;
  pair_t e1, e2;

  for (i = max = 0; i < d->num_rooms - 1; i++) {
    for (j = i + 1; j < d->num_rooms; j++) {
      tmp = (((d->rooms[i].position[dim_x] - d->rooms[j].position[dim_x])  *
              (d->rooms[i].position[dim_x] - d->rooms[j].position[dim_x])) +
             ((d->rooms[i].position[dim_y] - d->rooms[j].position[dim_y])  *
              (d->rooms[i].position[dim_y] - d->rooms[j].position[dim_y])));
      if (tmp > max) {
        max = tmp;
        p = i;
        q = j;
      }
    }
  }

  /* Can't simply call connect_two_rooms() because it doesn't *
   * use inverse hardnesses, so duplicate it here.            */
  e1[dim_y] = rand_range(d->rooms[p].position[dim_y],
                         (d->rooms[p].position[dim_y] +
                          d->rooms[p].size[dim_y] - 1));
  e1[dim_x] = rand_range(d->rooms[p].position[dim_x],
                         (d->rooms[p].position[dim_x] +
                          d->rooms[p].size[dim_x] - 1));
  e2[dim_y] = rand_range(d->rooms[q].position[dim_y],
                         (d->rooms[q].position[dim_y] +
                          d->rooms[q].size[dim_y] - 1));
  e2[dim_x] = rand_range(d->rooms[q].position[dim_x],
                         (d->rooms[q].position[dim_x] +
                          d->rooms[q].size[dim_x] - 1));

  dijkstra_corridor_inv(d, e1, e2);

  return 0;
}

static int connect_rooms(dungeon_t *d)
{
  uint32_t i;

  for (i = 1; i < d->num_rooms; i++) {
    connect_two_rooms(d, d->rooms + i - 1, d->rooms + i);
  }

  create_cycle(d);

  return 0;
}

int gaussian[5][5] = {
  {  1,  4,  7,  4,  1 },
  {  4, 16, 26, 16,  4 },
  {  7, 26, 41, 26,  7 },
  {  4, 16, 26, 16,  4 },
  {  1,  4,  7,  4,  1 }
};

typedef struct queue_node {
  int x, y;
  struct queue_node *next;
} queue_node_t;

static int smooth_hardness(dungeon_t *d)
{
  int32_t i, x, y;
  int32_t s, t, p, q;
  queue_node_t *head, *tail, *tmp;
  uint8_t hardness[DUNGEON_Y][DUNGEON_X];

#ifdef DUMP_HARDNESS_IMAGES
  FILE *out;
#endif

  memset(&hardness, 0, sizeof (hardness));

  /* Seed with some values */
  for (i = 1; i < 255; i++) {
    do {
      x = rand() % DUNGEON_X;
      y = rand() % DUNGEON_Y;
    } while (hardness[y][x]);
    hardness[y][x] = i;
    if (i == 1) {
      head = tail = malloc(sizeof (*tail));
    } else {
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
    }
    tail->next = NULL;
    tail->x = x;
    tail->y = y;
  }

#ifdef DUMP_HARDNESS_IMAGES
  out = fopen("seeded.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
  fwrite(&hardness, sizeof (hardness), 1, out);
  fclose(out);
#endif

  /* Diffuse the vaules to fill the space */
  while (head) {
    x = head->x;
    y = head->y;
    i = hardness[y][x];

    if (x - 1 >= 0 && y - 1 >= 0 && !hardness[y - 1][x - 1]) {
      hardness[y - 1][x - 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y - 1;
    }
    if (x - 1 >= 0 && !hardness[y][x - 1]) {
      hardness[y][x - 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y;
    }
    if (x - 1 >= 0 && y + 1 < DUNGEON_Y && !hardness[y + 1][x - 1]) {
      hardness[y + 1][x - 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x - 1;
      tail->y = y + 1;
    }
    if (y - 1 >= 0 && !hardness[y - 1][x]) {
      hardness[y - 1][x] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y - 1;
    }
    if (y + 1 < DUNGEON_Y && !hardness[y + 1][x]) {
      hardness[y + 1][x] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x;
      tail->y = y + 1;
    }
    if (x + 1 < DUNGEON_X && y - 1 >= 0 && !hardness[y - 1][x + 1]) {
      hardness[y - 1][x + 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y - 1;
    }
    if (x + 1 < DUNGEON_X && !hardness[y][x + 1]) {
      hardness[y][x + 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y;
    }
    if (x + 1 < DUNGEON_X && y + 1 < DUNGEON_Y && !hardness[y + 1][x + 1]) {
      hardness[y + 1][x + 1] = i;
      tail->next = malloc(sizeof (*tail));
      tail = tail->next;
      tail->next = NULL;
      tail->x = x + 1;
      tail->y = y + 1;
    }

    tmp = head;
    head = head->next;
    free(tmp);
  }

  /* And smooth it a bit with a gaussian convolution */
  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      for (s = t = p = 0; p < 5; p++) {
        for (q = 0; q < 5; q++) {
          if (y + (p - 2) >= 0 && y + (p - 2) < DUNGEON_Y &&
              x + (q - 2) >= 0 && x + (q - 2) < DUNGEON_X) {
            s += gaussian[p][q];
            t += hardness[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
          }
        }
      }
      d->hardness[y][x] = t / s;
    }
  }

#ifdef DUMP_HARDNESS_IMAGES
  out = fopen("diffused.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
  fwrite(&hardness, sizeof (hardness), 1, out);
  fclose(out);

  out = fopen("smoothed.pgm", "w");
  fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
  fwrite(&d->hardness, sizeof (d->hardness), 1, out);
  fclose(out);
#endif

  return 0;
}

static int empty_dungeon(dungeon_t *d)
{
  uint8_t x, y;

  smooth_hardness(d);
  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      mapxy(x, y) = ter_wall;
      if (y == 0 || y == DUNGEON_Y - 1 ||
          x == 0 || x == DUNGEON_X - 1) {
        mapxy(x, y) = ter_wall_immutable;
        hardnessxy(x, y) = 255;
      }
    }
  }

  return 0;
}

static int place_rooms(dungeon_t *d)
{
  pair_t p;
  uint32_t i;
  int success;
  room_t *r;
  uint8_t hardness[DUNGEON_Y][DUNGEON_X];
  uint32_t x, y;

  memcpy(&hardness, &d->hardness, sizeof (hardness));

  for (success = 0; !success; ) {
    success = 1;
    for (i = 0; success && i < d->num_rooms; i++) {
      r = d->rooms + i;
      r->position[dim_x] = 1 + rand() % (DUNGEON_X - 2 - r->size[dim_x]);
      r->position[dim_y] = 1 + rand() % (DUNGEON_Y - 2 - r->size[dim_y]);
      for (p[dim_y] = r->position[dim_y] - 1;
           success && p[dim_y] < r->position[dim_y] + r->size[dim_y] + 1;
           p[dim_y]++) {
        for (p[dim_x] = r->position[dim_x] - 1;
             success && p[dim_x] < r->position[dim_x] + r->size[dim_x] + 1;
             p[dim_x]++) {
          if (mappair(p) >= ter_floor) {
            success = 0;
            /* empty_dungeon() regenerates the hardness map, which   *
             * is prohibitively expensive to do in a loop like this, *
             * so instead, we'll use a copy.                         */
            memcpy(&d->hardness, &hardness, sizeof (hardness));
            for (y = 1; y < DUNGEON_Y - 1; y++) {
              for (x = 1; x < DUNGEON_X - 1; x++) {
                mapxy(x, y) = ter_wall;
              }
            }
          } else if ((p[dim_y] != r->position[dim_y] - 1)              &&
                     (p[dim_y] != r->position[dim_y] + r->size[dim_y]) &&
                     (p[dim_x] != r->position[dim_x] - 1)              &&
                     (p[dim_x] != r->position[dim_x] + r->size[dim_x])) {
            mappair(p) = ter_floor_room;
            hardnesspair(p) = 0;
          }
        }
      }
    }
  }

  return 0;
}

static int make_rooms(dungeon_t *d)
{
  uint32_t i;

  for (i = MIN_ROOMS; i < MAX_ROOMS && rand_under(6, 8); i++)
    ;

  d->num_rooms = i;
  d->rooms = malloc(sizeof (*d->rooms) * d->num_rooms);

  for (i = 0; i < d->num_rooms; i++) {
    d->rooms[i].size[dim_x] = ROOM_MIN_X;
    d->rooms[i].size[dim_y] = ROOM_MIN_Y;
    while (rand_under(3, 4) && d->rooms[i].size[dim_x] < ROOM_MAX_X) {
      d->rooms[i].size[dim_x]++;
    }
    while (rand_under(3, 4) && d->rooms[i].size[dim_y] < ROOM_MAX_Y) {
      d->rooms[i].size[dim_y]++;
    }
    /* Initially, every room is connected only to itself. */
    d->rooms[i].connected = i;
  }

  return 0;
}

int gen_dungeon(dungeon_t *d)
{
  do {
    make_rooms(d);
  } while (place_rooms(d));
  connect_rooms(d);

  return 0;
}

void render_dungeon(dungeon_t *d)
{
  pair_t p;

  for (p[dim_y] = 0; p[dim_y] < DUNGEON_Y; p[dim_y]++) {
    for (p[dim_x] = 0; p[dim_x] < DUNGEON_X; p[dim_x]++) {
      switch (mappair(p)) {
      case ter_wall:
      case ter_wall_immutable:
        putchar(' ');
        break;
      case ter_floor:
      case ter_floor_room:
        putchar('.');
        break;
      case ter_floor_hall:
        putchar('#');
        break;
      case ter_debug:
        fprintf(stderr, "Debug character at %d, %d\n", p[dim_y], p[dim_x]);
        putchar('*');
        break;
      case player:
	putchar('@');
	break;
      case monster0:
	putchar('0');
	break;
      case monster1:
	putchar('1');
	break;
      case monster2:
	putchar('2');
	break;
      case monster3:
	putchar('3');
	break;
      case monster4:
	putchar('4');
	break;
      case monster5:
	putchar('5');
	break;
      case monster6:
	putchar('6');
	break;
      case monster7:
	putchar('7');
	break;
      case monster8:
	putchar('8');
	break;
      case monster9:
	putchar('9');
	break;
      case monstera:
	putchar('a');
	break;
      case monsterb:
	putchar('b');
	break;
      case monsterc:
	putchar('c');
	break;
      case monsterd:
	putchar('d');
	break;
      case monstere:
	putchar('e');
	break;
      case monsterf:
	putchar('f');
	break;
      }
    }
    putchar('\n');
  }
}

void delete_dungeon(dungeon_t *d)
{
  free(d->rooms);
}

void init_dungeon(dungeon_t *d)
{
  empty_dungeon(d);
}

int write_dungeon_map(dungeon_t *d, FILE *f)
{
  uint32_t x, y;

  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      fwrite(&d->hardness[y][x], sizeof (unsigned char), 1, f);
    }
  }

  return 0;
}

int write_rooms(dungeon_t *d, FILE *f)
{
  uint32_t i;
  uint8_t p;

  for (i = 0; i < d->num_rooms; i++) {
    /* write order is xpos, ypos, width, height */
    p = d->rooms[i].position[dim_x];
    fwrite(&p, 1, 1, f);
    p = d->rooms[i].size[dim_x];
    fwrite(&p, 1, 1, f);
    p = d->rooms[i].position[dim_y];
    fwrite(&p, 1, 1, f);
    p = d->rooms[i].size[dim_y];
    fwrite(&p, 1, 1, f);
  }

  return 0;
}

uint32_t calculate_dungeon_size(dungeon_t *d)
{
  return (14 /* The semantic, version, and size */     +
          (DUNGEON_X * DUNGEON_Y) /* The hardnesses */ +
          (d->num_rooms * 4) /* Four bytes per room */);
}

int makedirectory(char *dir)
{
  char *slash;

  for (slash = dir + strlen(dir); slash > dir && *slash != '/'; slash--)
    ;

  if (slash == dir) {
    return 0;
  }

  if (mkdir(dir, 0700)) {
    if (errno != ENOENT && errno != EEXIST) {
      fprintf(stderr, "mkdir(%s): %s\n", dir, strerror(errno));
      return 1;
    }
    if (*slash != '/') {
      return 1;
    }
    *slash = '\0';
    if (makedirectory(dir)) {
      *slash = '/';
      return 1;
    }

    *slash = '/';
    if (mkdir(dir, 0700) && errno != EEXIST) {
      fprintf(stderr, "mkdir(%s): %s\n", dir, strerror(errno));
      return 1;
    }
  }

  return 0;
}

int write_dungeon(dungeon_t *d)
{
  char *home;
  char *filename;
  FILE *f;
  size_t len;
  uint32_t be32;

  if (!(home = getenv("HOME"))) {
    fprintf(stderr, "\"HOME\" is undefined.  Using working directory.\n");
    home = ".";
  }

  len = (strlen(home) + strlen(SAVE_DIR) + strlen(DUNGEON_SAVE_FILE) +
         1 /* The NULL terminator */                                 +
         2 /* The slashes */);

  filename = malloc(len * sizeof (*filename));
  sprintf(filename, "%s/%s/", home, SAVE_DIR);
  makedirectory(filename);
  strcat(filename, DUNGEON_SAVE_FILE);

  if (!(f = fopen(filename, "w"))) {
    perror(filename);
    free(filename);

    return 1;
  }
  free(filename);

  /* The semantic, which is 6 bytes, 0-5 */
  fwrite(DUNGEON_SAVE_SEMANTIC, 1, strlen(DUNGEON_SAVE_SEMANTIC), f);

  /* The version, 4 bytes, 6-9 */
  be32 = htobe32(DUNGEON_SAVE_VERSION);
  fwrite(&be32, sizeof (be32), 1, f);

  /* The size of the file, 4 bytes, 10-13 */
  be32 = htobe32(calculate_dungeon_size(d));
  fwrite(&be32, sizeof (be32), 1, f);

  /* The dungeon map, 61440 bytes, 14-1495 */
  write_dungeon_map(d, f);

  /* And the rooms, num_rooms * 4 bytes, 1496-end */
  write_rooms(d, f);

  fclose(f);

  return 0;
}

int read_dungeon_map(dungeon_t *d, FILE *f)
{
  uint32_t x, y;

  for (y = 0; y < DUNGEON_Y; y++) {
    for (x = 0; x < DUNGEON_X; x++) {
      fread(&d->hardness[y][x], sizeof (d->hardness[y][x]), 1, f);
      if (d->hardness[y][x] == 0) {
        /* Mark it as a corridor.  We can't recognize room cells until *
         * after we've read the room array, which we haven't done yet. */
        d->map[y][x] = ter_floor_hall;
      } else if (d->hardness[y][x] == 255) {
        d->map[y][x] = ter_wall_immutable;
      } else {
        d->map[y][x] = ter_wall;
      }
    }
  }


  return 0;
}

int read_rooms(dungeon_t *d, FILE *f)
{
  uint32_t i;
  uint32_t x, y;
  uint8_t p;

  for (i = 0; i < d->num_rooms; i++) {
    fread(&p, 1, 1, f);
    d->rooms[i].position[dim_x] = p;
    fread(&p, 1, 1, f);
    d->rooms[i].size[dim_x] = p;
    fread(&p, 1, 1, f);
    d->rooms[i].position[dim_y] = p;
    fread(&p, 1, 1, f);
    d->rooms[i].size[dim_y] = p;
    /* After reading each room, we need to reconstruct them in the dungeon. */
    for (y = d->rooms[i].position[dim_y];
         y < d->rooms[i].position[dim_y] + d->rooms[i].size[dim_y];
         y++) {
      for (x = d->rooms[i].position[dim_x];
           x < d->rooms[i].position[dim_x] + d->rooms[i].size[dim_x];
           x++) {
        mapxy(x, y) = ter_floor_room;
      }
    }
  }

  return 0;
}

int calculate_num_rooms(uint32_t dungeon_bytes)
{
  return ((dungeon_bytes -
          (14 /* The semantic, version, and size */       +
           (DUNGEON_X * DUNGEON_Y) /* The hardnesses */)) /
          4 /* Four bytes per room */);
}

int read_dungeon(dungeon_t *d, char *file)
{
  char semantic[6];
  uint32_t be32;
  FILE *f;
  char *home;
  size_t len;
  char *filename;
  struct stat buf;

  if (!file) {
    if (!(home = getenv("HOME"))) {
      fprintf(stderr, "\"HOME\" is undefined.  Using working directory.\n");
      home = ".";
    }

    len = (strlen(home) + strlen(SAVE_DIR) + strlen(DUNGEON_SAVE_FILE) +
           1 /* The NULL terminator */                                 +
           2 /* The slashes */);

    filename = malloc(len * sizeof (*filename));
    sprintf(filename, "%s/%s/%s", home, SAVE_DIR, DUNGEON_SAVE_FILE);

    if (!(f = fopen(filename, "r"))) {
      perror(filename);
      free(filename);
      exit(-1);
    }

    if (stat(filename, &buf)) {
      perror(filename);
      exit(-1);
    }

    free(filename);
  } else {
    if (!(f = fopen(file, "r"))) {
      perror(file);
      exit(-1);
    }
    if (stat(file, &buf)) {
      perror(file);
      exit(-1);
    }

  }

  d->num_rooms = 0;

  fread(semantic, sizeof(semantic), 1, f);
  semantic[6] = '\0';
  if (strncmp(semantic, DUNGEON_SAVE_SEMANTIC, 6)) {
    fprintf(stderr, "Not an RLG327 save file.\n");
    exit(-1);
  }
  fread(&be32, sizeof (be32), 1, f);
  if (be32toh(be32) != 0) { /* Since we expect zero, be32toh() is a no-op. */
    fprintf(stderr, "File version mismatch.\n");
    exit(-1);
  }
  fread(&be32, sizeof (be32), 1, f);
  if (buf.st_size != be32toh(be32)) {
    fprintf(stderr, "File size mismatch.\n");
    exit(-1);
  }
  read_dungeon_map(d, f);
  d->num_rooms = calculate_num_rooms(buf.st_size);
  d->rooms = malloc(sizeof (*d->rooms) * d->num_rooms);
  read_rooms(d, f);

  fclose(f);

  return 0;
}

int read_pgm(dungeon_t *d, char *pgm)
{
  FILE *f;
  char s[80];
  uint8_t gm[19][78];
  uint32_t x, y;
  uint32_t i;

  if (!(f = fopen(pgm, "r"))) {
    perror(pgm);
    exit(-1);
  }

  if (!fgets(s, 80, f) || strncmp(s, "P5", 2)) {
    fprintf(stderr, "Expected P5\n");
    exit(-1);
  }
  if (!fgets(s, 80, f)) {
    fprintf(stderr, "Expected comment\n");
    exit(-1);
  }
  if (!fgets(s, 80, f) || strncmp(s, "78 19", 5)) {
    fprintf(stderr, "Expected 78\n");
    exit(-1);
  }
  if (!fgets(s, 80, f) || strncmp(s, "255", 2)) {
    fprintf(stderr, "Expected 255\n");
    exit(-1);
  }

  fread(gm, 1, 19 * 78, f);

  fclose(f);

  /* In our gray map, treat black (0) as corridor, white (255) as room, *
   * all other values as a hardness.  For simplicity, treat every white *
   * cell as its own room, so we have to count white after reading the  *
   * image in order to allocate the room array.                         */
  for (d->num_rooms = 0, y = 0; y < 19; y++) {
    for (x = 0; x < 78; x++) {
      if (!gm[y][x]) {
        d->num_rooms++;
      }
    }
  }
  d->rooms = malloc(sizeof (*d->rooms) * d->num_rooms);

  for (i = 0, y = 0; y < 19; y++) {
    for (x = 0; x < 78; x++) {
      if (!gm[y][x]) {
        d->rooms[i].position[dim_x] = x + 1;
        d->rooms[i].position[dim_y] = y + 1;
        d->rooms[i].size[dim_x] = 1;
        d->rooms[i].size[dim_y] = 1;
        i++;
        d->map[y + 1][x + 1] = ter_floor_room;
        d->hardness[y + 1][x + 1] = 0;
      } else if (gm[y][x] == 255) {
        d->map[y + 1][x + 1] = ter_floor_hall;
        d->hardness[y + 1][x + 1] = 0;
      } else {
        d->map[y + 1][x + 1] = ter_wall;
        d->hardness[y + 1][x + 1] = gm[y][x];
      }
    }
  }

  for (x = 0; x < 80; x++) {
    d->map[0][x] = ter_wall_immutable;
    d->hardness[0][x] = 255;
    d->map[20][x] = ter_wall_immutable;
    d->hardness[20][x] = 255;
  }
  for (y = 1; y < 20; y++) {
    d->map[y][0] = ter_wall_immutable;
    d->hardness[y][0] = 255;
    d->map[y][79] = ter_wall_immutable;
    d->hardness[y][79] = 255;
  }

  return 0;
}

void usage(char *name)
{
  fprintf(stderr,
          "Usage: %s [-r|--rand <seed>] [-l|--load [<file>]] [-s|--save]\n",
          name);

  exit(-1);
}

void createPlayerEvent(PC_t *player, int first){

  //Turn doesn't need to be added the first time around
  move_t event;
  event.isMonster = 0;
  event.speed = 10;
  event.turn = 10;
  event.id = -1; 

  if(first == 1){   
      event.priority = 0;
   
  }else{
    //Calculate move priority, and insert into event queue
    event.priority = gameTurn + event.turn;  
  }


  insert_by_event_priority(event); 
}
void createMonsterEvent(Monster_t monster, int i, int first){
  //Turn doesn't need to be added the first time around
  //   printf("in monster event  x %d, and y %d \n", monster->position[dim_x], monster->position[dim_y]); 

   move_t event;
   event.isMonster = 1;

  if(first == 1){   
    event.priority = 0; 
    event.id = i;
    event.speed = monster.speed;
    event.turn = 100/event.speed;    
   }else{
     //Calculate real priority and then add it to priority queue
     //Now priority is gameTurn + turn;
    event.id = monster.id;
    event.speed = monster.speed;
    event.turn = 100/event.speed;
    event.priority = gameTurn + event.turn; 
   }
   
  insert_by_event_priority(event); 
}

int compareSkills(int array1[4], const int array2[4]){

  int result = 0; 
  if((memcmp(array1, array2, sizeof(int)*4) == 0)){
    result = 1; 
  }
  
  return result;
}

void putCharacter(PC_t* PC, dungeon_t* d){
  int place;
  place = rand() % d->num_rooms;

  PC->position[dim_x] = d->rooms[place].position[dim_x] + (d->rooms[place].size[dim_x]/2);
  PC->position[dim_y] = d->rooms[place].position[dim_y] + (d->rooms[place].size[dim_y]/2);

  mapxy(PC->position[dim_x], PC->position[dim_y]) = player; 
  
}

//Just puts the playerCharacter in the queue
void fillQueue(dungeon_t *d, int x, int y, int tunnel){
  int  i, j;

  if(tunnel){
    for(i = 0; i < DUNGEON_Y; i++){
      for(j = 0; j < DUNGEON_X; j++){
	priority_t item;
	if(d->hardness[i][j] < 255){	
	  item.position[dim_x] = j;
	  item.position[dim_y] = i;
	  if(i == y  && j == x ){ 
	    item.distance = 0;
	    insert_by_priority(item); 
	  }else{
	    item.distance = 100; 
	  }
	  tunnels[i][j] = item;
	  //	 printf("Tunnels is %d\n", tunnels[i][j].distance); 
	  //	 insert_by_priority(item); 
	}        
      }
    }
  }else{

      for(i = 0; i < DUNGEON_Y; i++){
	for(j = 0; j < DUNGEON_X; j++){
	  priority_t item;
	  if(d->hardness[i][j] == 0){	
	    item.position[dim_x] = j;
	    item.position[dim_y] = i;
	    if(i == y  && j == x ){
	      //    printf("item x, y here is %d, %d \n", item.position[dim_x], item.position[dim_y]); 
	      item.distance = 0;
	      insert_by_priority(item); 
	    }else{
	      item.distance = 100; 
	    }
	    nonTunnels[i][j] = item;
	    //	 printf("Tunnels is %d\n", tunnels[i][j].distance); 
	    //	 insert_by_priority(item); 
	}        
      }
    }
    
  }
  //  printf("size is %d \n", queueSize); 
}

int getChar(int dist, int PC){

   if( PC == 1){
      return 48;
   }
  if(dist < 10){
    if(dist  == 0){
      return 32; 
    }else{
      return dist + 48; 
    }
  }
  if(dist > 9 && dist < 36 ){
    return dist + 87; 
  }
  if(dist > 35 && dist < 62){
    return dist + 29; 
  }
  return 90; 
}

void print_tunnels(priority_t tunnels[DUNGEON_Y][DUNGEON_X], int tunnel, PC_t *PC){

  //  printf("tunnels ranmdo %d\n", tunnels[10][10].distance); 
  int i, j; 
  for(i = 0; i < DUNGEON_Y; i++){
    for(j = 0; j < DUNGEON_X; j++){
      if(i == 0 || i == 20){
	printf("%c", '-'); 
      }
      else if(j == 0 || j == 79){
	printf("%c", '|'); 
      }else{
	//32 is a space
	int value; 
	if(i == PC->position[dim_y] && j ==  PC->position[dim_x]){
	  //  printf("found player"); 
	  value = getChar(tunnels[i][j].distance, 1); 
	}else{
	  value = getChar(tunnels[i][j].distance, 0); 
	}         
	printf("%c", value); 
      }
     
    }
    printf("\n"); 
  }
}

void find_neighbor_distance(priority_t item, dungeon_t *d, int tunnel){

  // printf("%d hardness \n", d->hardness[item.position[dim_x]][item.position[dim_y]]);  
  //   printf("item in neighbor dist: %d,   x :%d, item in dik y : %d \n", item.distance, item.position[dim_x], item.position[dim_y]);
  
  int i, j;
  if(tunnel){
    for(i = item.position[dim_y]-1; i <= item.position[dim_y] + 1; i++){
      for(j = item.position[dim_x] -1; j <= item.position[dim_x] + 1; j++){
	if(d->hardness[i][j] < 255){
	  int weight = d->hardness[i][j]/85 + 1; 
	  int newDist = item.distance + weight;	
	  if(newDist < tunnels[i][j].distance){
	    tunnels[i][j].distance = newDist;
	    insert_by_priority(tunnels[i][j]); 
	    //printf("found match %d, queu is : %d" , tunnels[i][j].distance,queueSize);
	  }
	}      
      }
    }
  }else{
       for(i = item.position[dim_y]-1; i <= item.position[dim_y] + 1; i++){
	 for(j = item.position[dim_x] -1; j <= item.position[dim_x] + 1; j++){
	   if(d->hardness[i][j] == 0){
	     //  printf("in loop"); 
	     int newDist = item.distance + 1;
	     //  printf("new Dist %d \n", newDist); 
	     if(newDist < nonTunnels[i][j].distance){
	       nonTunnels[i][j].distance = newDist;
	       //   printf("new Dist %d\n", newDist); 
	       insert_by_priority(nonTunnels[i][j]); 
	       //        printf("found match %d, queu is : %d" , tunnels[i][j].distance,queueSize);
	     }
	   }      
	 }
       }
  }
   
}

void dijkstra_priority(dungeon_t *d, PC_t *PC, int tunnel){

  int first = 1; 
  if(tunnel){
    while(queueSize > 0 ){
      priority_t item = pop();
      if(item.distance == 0){
	item.position[dim_x] = PC->position[dim_x];
	item.position[dim_y] = PC->position[dim_y];
	//printf("item in dik dist %d,  x :%d, item in dik y : %d \n",item.distance,  item.position[dim_x], item.position[dim_y]);
      }       
      find_neighbor_distance(item, d, 1);
      //     find_neighbor_distance(item, d, 0); 
    }
    // printf("Queusize at end %d\n", queueSize); 
    //    print_tunnels(tunnels,1, PC);
  }else{
    
     while(queueSize > 0 ){
       priority_t item; 
       if(first){
	 item = pop();
	 item.distance = 0;
	 first = 0; 
       }else{
	 item = pop(); 
       }
       //  printf("Item x y is %d, %d ", item.position[dim_x], item.position[dim_y]); 
      if(item.distance == 0){
	item.position[dim_x] = PC->position[dim_x];
	item.position[dim_y] = PC->position[dim_y];
	//	printf("item in dik dist %d,  x :%d, item in dik y : %d \n",item.distance,  item.position[dim_x], item.position[dim_y]);
      }       
      find_neighbor_distance(item, d, 0); 
    }
     //  printf("Queusize at end %d\n", queueSize); 
     //   print_tunnels(nonTunnels,0, PC);
  }
  
}
void fillVisited(int visited[21][80]){
  int i, j;
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      visited[i][j] = 0; 
    }
  }
}

void setDistances(dist_t distances[21][80]){
  int i, j;
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      distances[i][j].dist = 99999;  
    }
  }
}

void printPath(Monster_t source, PC_t* destination){

  int i, j; 
  i = destination->position[dim_y];
  j = destination->position[dim_x];
  int x, y;
  
  // printf("path backwards is %d, %d\n", j, i);
   distances[source.position[dim_y]][source.position[dim_x]].next[dim_x] = j;
   distances[source.position[dim_y]][source.position[dim_x]].next[dim_y] = i;
   int search = 1; 
  while(search){
    y = distances[i][j].previous[dim_y];
    x = distances[i][j].previous[dim_x];
     
    if(y == source.position[dim_y] && x == source.position[dim_x]){
      search = 0;
     
    }else{
      distances[source.position[dim_y]][source.position[dim_x]].next[dim_x] = x;
      distances[source.position[dim_y]][source.position[dim_x]].next[dim_y] = y;
    }
    
    i = y;
    j = x; 
    //  printf("path backwards is %d, %d\n", x, y);
    //  printf("source is %d, %d \n", source.position[dim_x], source.position[dim_y]); 
  }

}

void modifyHardness(priority_t tunnelType[21][80], PC_t* destination){
  int i, j;
  for(i  =0; i < 21; i++){
    for(j = 0; j < 80; j++){
      if(tunnelType[i][j].distance == 0){
	visited[i][j] = 1; 
      }
    }
  }

  visited[destination->position[dim_y]][destination->position[dim_x]]  = 0; 
  
}

void monster_dijkstra(Monster_t source, PC_t* destination, dungeon_t *d, priority_t tunnelType[21][80], int tunnel){


  //  printf("in diks destination is  %d, %d \n", destination->position[dim_x], destination->position[dim_y]); 
  //  printf("source is %d, %d \n", source.position[dim_x], source.position[dim_y]); 

  //If monster is intelligent/remember this as last position you saw the player
  if(source.skills[3] == 1){
    monsterArray[source.id].lastPC[dim_x] = destination->position[dim_x];
    monsterArray[source.id].lastPC[dim_y] = destination->position[dim_y]; 
    monsterArray[source.id].view = 1;
  }

  //actually just marks all out of bounds as visited
   modifyHardness(tunnelType, destination); 


  //  tunnelType[destination->position[dim_x]][destination->position[dim_y]].distance = -1; 
  
  //sets all visited to 0 [][]
  fillVisited(visited);
  //Sets distances to 999 [][]
  setDistances(distances);
  // tunnelType[destination->position[dim_y]][destination->position[dim_x]].distance = 1;
  // tunnels[destination->position[dim_y]][destination->position[dim_x]].distance = 1; 

  int found = 0;
  pair_t start;

    distances[source.position[dim_y]][source.position[dim_x]].dist = 0; 
    while(found == 0){
    //check if we visited the destination

    if(visited[destination->position[dim_y]][destination->position[dim_x]] == 1){ 
      
      //    printf("***********************************************************"); 
      printPath(source, destination);
      found = 1;
    }
    //Haven't visited source yet
    if(visited[source.position[dim_y]][source.position[dim_x]] == 0){
      //   printf("working with source\n"); 
      start[dim_x] = source.position[dim_x];
      start[dim_y] = source.position[dim_y];
      visited[source.position[dim_y]][source.position[dim_x]] = 1;
    }else{
      //Find shortest non visited length on distances map
      //   printf("searching in else\n");
      int i, j, x, y;
      int visit = 0;
      dist_t min;
      min.dist = 99999; 
      for(i = 0; i < 21; i++){
	for(j = 0; j < 80; j++){
	  if(distances[i][j].dist < min.dist && visited[i][j] == 0){
	    //   printf("working with %d, %d, \n", j, i); 
	    min = distances[i][j];
	    visit = 1; 
	    y = i;
	    x = j; 
	  }
	}
      }
      if(visit == 1){
	visited[y][x] = 1;
	start[dim_x] = x;
	start[dim_y] = y;
	//	printf("found visit, %d, %d, distance %d\n", x, y, distances[y][x].dist);
	
	//	return; 
      }
    
    }

    //  printf("distance at source %d\n", distances[start[dim_y]][start[dim_x]].dist); 
    //calculate neighbor distances
    int i, j;
    for(i = start[dim_y] - 1; i < start[dim_y] + 2; i++){
      for(j = start[dim_x] - 1; j < start[dim_x] + 2; j++){
	if(i > 0 && i < 21 && j > 0 && j < 80 && (d->hardness[i][j] == 0 || tunnel == 1)){
	  int alt = distances[start[dim_y]][start[dim_x]].dist + tunnelType[i][j].distance;
	  if(alt < distances[i][j].dist){
	    distances[i][j].dist = alt;
	    distances[i][j].previous[dim_x] = start[dim_x];
	    distances[i][j].previous[dim_y] = start[dim_y]; 
	  }
	}	 
      }
    }
    //    printf("Best next choice is %d, %d \n", j, i);
    //  printf("Best next is visited : %d, and distance %d \n", visited[i][j], distances[i][j].dist); 
    //  printf("destination x y is  %d, %d \n", destination->position[dim_x], destination->position[dim_y]);
    //  printf("hardness is %d, \n", tunnelType[i][j].distance);


    
    }
 

}

void putTunneling(PC_t* PC, dungeon_t *d){
  // printf("tunneling %d\n", PC->position[dim_x]); 
  fillQueue(d,PC->position[dim_x], PC->position[dim_y], 1);
  dijkstra_priority(d, PC, 1);
  //  printf("x is %d, and y is %d", PC->position[dim_x], PC->position[dim_y]); 
}

void putNonTunnels(PC_t *PC, dungeon_t *d){

  fillQueue(d, PC->position[dim_x], PC->position[dim_y], 0); 
  dijkstra_priority(d, PC, 0); 
}
void getSkills(Monster_t *monster){

  int i;
  for(i = 0; i < 4; i++){
    if(0){
      monster->skills[i] = rand() % 2;

    }else{
      if(i == 3){
	monster->skills[i] = 0;
      }
      if(i == 2){
	monster->skills[i] = 0;
      }
      if(i == 1){
	monster->skills[i] = 1;
      }
      if(i == 0){
	monster->skills[i] = 0;
      }
    }
  }
  
}
void compareMonsterSkills(Monster_t *monster){
  if(compareSkills(monster->skills, monsterType0)){
      monster->type = monster0;
  }
  else if(compareSkills(monster->skills, monsterType1)){
      monster->type = monster1; 
  }
   else if(compareSkills(monster->skills, monsterType2)){
      monster->type = monster2; 
  }
  else if(compareSkills(monster->skills, monsterType3)){
      monster->type = monster3; 
  }
  else if(compareSkills(monster->skills, monsterType4)){
      monster->type = monster4; 
  }
  else if(compareSkills(monster->skills, monsterType5)){
      monster->type = monster5; 
  }
  else if(compareSkills(monster->skills, monsterType6)){
      monster->type = monster6; 
  }
  else if(compareSkills(monster->skills, monsterType7)){
      monster->type = monster7; 
  }
  else if(compareSkills(monster->skills, monsterType8)){
      monster->type = monster8; 
  }
  else if(compareSkills(monster->skills, monsterType9)){
      monster->type = monster9; 
  }
  else if(compareSkills(monster->skills, monsterTypea)){
      monster->type = monstera; 
  }
  else if(compareSkills(monster->skills, monsterTypeb)){
      monster->type = monsterb; 
  }
  else if(compareSkills(monster->skills, monsterTypec)){
      monster->type = monsterc; 
  }
  else if(compareSkills(monster->skills, monsterTyped)){
      monster->type = monsterd; 
  }
  else if(compareSkills(monster->skills, monsterTypee)){
      monster->type = monstere; 
  }
  else if(compareSkills(monster->skills, monsterTypef)){
      monster->type = monsterf; 
  }
}
void addMonsterSpeed(Monster_t *monster){
  int speed = rand() % 16 + 5;
  monster->speed = speed; 
}

void addMonster( dungeon_t *d, int placement){

  Monster_t monster; 
  int place;
  place = rand() % d->num_rooms;

  int xVal = rand() % ( d->rooms[place].size[dim_x]);
  xVal = xVal + d->rooms[place].position[dim_x];
  int yVal = rand() % ( d->rooms[place].size[dim_y]);
  yVal = yVal + d->rooms[place].position[dim_y]; 
  
  //  printf("x coord is %d, x size is %d, rand x is %d \n ",d->rooms[place].position[dim_y],d->rooms[place].size[dim_y], yVal  ); 
   getSkills(&monster);

   compareMonsterSkills(&monster);
   addMonsterSpeed(&monster); 
  
   monster.position[dim_x] = xVal;
   monster.position[dim_y] = yVal;

   monster.dead = 0; 
   monster.id = placement; 
   monsterArray[placement] = monster; 


   mapxy(monster.position[dim_x], monster.position[dim_y]) = monster.type; 

}

void  placeMonsters(int nummon, dungeon_t *d){

  //Won't necessarily place nummon quantity because it doesn't check to see if monster is already there
  int i;
  for(i = 0; i < nummon; i++){
    addMonster( d, i); 
  }

  //  int k;
  // for(k = 0; k < 20; k++){
  //   printf("monsterArray at %d, x is %d, y is %d ****************\n", k, monsterArray[k].position[dim_x], monsterArray[k].position[dim_y]); 
  // }

 
}
void replaceXY(dungeon_t* d, int x, int y){

    switch (dungeonCopy[y][x]) {
      case ter_wall:
      case ter_wall_immutable:
        mapxy(x,y) = ter_wall; 
        break;
      case ter_floor:
      case ter_floor_room:
	mapxy(x,y) = ter_floor;
        break;
      case ter_floor_hall:
        mapxy(x,y) = ter_floor_hall;
        break;
      case ter_debug:
	//  fprintf(stderr, "Debug character at %d, %d\n", p[dim_y], p[dim_x]);
	// putchar('*');
        break;
      case player:
	mapxy(x,y) = player;
	break;
      case monster0:
	mapxy(x,y) = monster0;
	break;
      case monster1:
	mapxy(x,y) = monster1;
	break;
      case monster2:
	mapxy(x,y) = monster2;
	break;
      case monster3:
	mapxy(x,y) = monster3;
	break;
      case monster4:
	mapxy(x,y) = monster4;
	break;
      case monster5:
	mapxy(x,y) = monster5;
	break;
      case monster6:
	mapxy(x,y) = monster6;
	break;
      case monster7:
	mapxy(x,y) = monster7;
	break;
      case monster8:
	mapxy(x,y) = monster8;
	break;
      case monster9:
	mapxy(x,y) = monster9;
	break;
      case monstera:
	mapxy(x,y) = monstera;
	break;
      case monsterb:
	mapxy(x,y) = monsterb;
	break;
      case monsterc:
	mapxy(x,y) = monsterc;
	break;
      case monsterd:
	mapxy(x,y) = monsterd;
	break;
      case monstere:
	mapxy(x,y) = monstere;
	break;
      case monsterf:
	mapxy(x,y) = monsterf;
	break;
      }
} 
void deleteMonster(int i){

  deletedMonsters[deletePosition] = i;
  deletePosition++;
  monsterArray[i].dead = 1; 
  
}

void deleteEvent(int i){
  int j;
  for(j = 0; j < eventSize; j++){
    if(event_queue[j].id == i){
      //  deleteEventById(j); 
    }
  }
}

void identifyMonster(dungeon_t* d, int x, int y){

  //  printf("\nIdentify Monster at %d, %d \n", x, y); 
  //  printf("\nThere are %d Monsters left\n", monstersLeft); 
  int i;
  for(i = 0; i < 20; i++){
    //    printf("Monster array at %d, %d, %d is dead : %d\n", i, monsterArray[i].position[dim_x], monsterArray[i].position[dim_y],monsterArray[i].dead ); 
    if(monsterArray[i].position[dim_x] == x && monsterArray[i].position[dim_y] == y && monsterArray[i].dead == 0){
      monstersLeft--;
      //   deleteEvent(i);
      replaceXY(d, x, y); 
      deleteMonster(i);

      if(monstersLeft == 0){
	gameOver = 1;
	win = 1; 
      }
      return; 
      
    }
 
  }
}

void movePlayer(move_t move, dungeon_t* d, PC_t *PC){

  int x, y; 
  if(d->hardness[PC->position[dim_y]][PC->position[dim_x]+1] == 0){
    x = PC->position[dim_x]+1;
    y = PC->position[dim_y]; 
  }
  else if(d->hardness[PC->position[dim_y]][PC->position[dim_x] - 1] == 0){
    x = PC->position[dim_x]-1;
    y = PC->position[dim_y]; 
  }
  else if(d->hardness[PC->position[dim_y]-1][PC->position[dim_x]] == 0){
    x = PC->position[dim_x];
    y = PC->position[dim_y]-1; 
  }
  else if(d->hardness[PC->position[dim_y]+1][PC->position[dim_x]] == 0){
    x = PC->position[dim_x];
    y = PC->position[dim_y]+1; 
  }

  identifyMonster(d,x,y);
  replaceXY(d,PC->position[dim_x], PC->position[dim_y]); 	     
  mapxy(x,y) = player;
  PC->position[dim_x] = x;
  PC->position[dim_y] = y;

  //Create events here because this has new player updated coordinates 
  createPlayerEvent(PC, 0); 
}

void identifyPC(dungeon_t *d, int x, int y, PC_t *PC){
  if(PC->position[dim_x] == x && PC->position[dim_y] == y){
    gameOver = 1;
    printf("Game Over, you Lose\n"); 
  }
}

int sameRoom(Monster_t monster, PC_t *PC, dungeon_t *d){
  int result = 0; 
  int roomCount = d->num_rooms;
  int i;

  // printf("same room x, y, %d, %d\n", monster.position[dim_x], monster.position[dim_y]); 
  for(i = 0; i < roomCount; i++){
    int xBound = d->rooms[i].size[dim_x] +  d->rooms[i].position[dim_x];
    int yBound =  d->rooms[i].size[dim_y] +  d->rooms[i].position[dim_y];
    if(PC->position[dim_x] >= d->rooms[i].position[dim_x] && PC->position[dim_x] <= xBound ){
      if(PC->position[dim_y] >= d->rooms[i].position[dim_y] && PC->position[dim_y] <= yBound ){
	//	printf("\nfound PC in a room\n"); 
         if(monster.position[dim_x] >= d->rooms[i].position[dim_x] && monster.position[dim_x] <= xBound ){
	   if(monster.position[dim_y] >= d->rooms[i].position[dim_y] && monster.position[dim_y] <= yBound ){
	     //	     printf("\nin same room\n"); 
	     result = 1;
	   }
	 }
      }     
    }
  }

  return result; 
}

int checkY(int x, int y, dungeon_t *d){
  if( d->hardness[y-1][x] == 0){
    y = y - 1; 
  }
  else if( d->hardness[y+1][x] == 0){
    y = y + 1; 
  }
  return y; 
}

int checkX(int x, int y, dungeon_t* d){

  if(d->hardness[x-1][x] == 0){
    x = x - 1; 
  }
  else if( d->hardness[x+1][x] == 0){
    x = x + 1; 
  }
  return x; 
}


void moveType0(move_t move, int i, PC_t *PC, dungeon_t* d){

    Monster_t monster = monsterArray[move.id];
  int x, y;
  x = monster.position[dim_x];
  y = monster.position[dim_y]; 

  if( d->hardness[y][x+1] == 0){
    x = monster.position[dim_x] +1;
    y = monster.position[dim_y]; 
  }
  else if(d->hardness[y][x-1] == 0){
     x = monster.position[dim_x] - 1;
     y = monster.position[dim_y];  
  }
  else if(d->hardness[y+1][x] == 0){
    x = monster.position[dim_x];
    y = monster.position[dim_y]+1; 
  }
  else if( d->hardness[y-1][x] == 0){
     x = monster.position[dim_x];
     y = monster.position[dim_y]-1; 
  }
  
    identifyMonster(d,x,y);

    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x;
    monsterArray[move.id].position[dim_y] = y;
    mapxy(x,y) = monster.type;  		
    identifyPC(d,x,y, PC);
  
}
void moveType1(move_t move, int i, PC_t *PC,  dungeon_t* d){
  //Intelligent
  Monster_t monster = monsterArray[move.id];
  int x, y;
  //  printf("monster lastPC %d \n", monster.view); 
  //IF same room, or previously seen monster.view
  if(sameRoom(monster, PC, d) ==  1){
      //Line of sight is same room
    // printf("line of sight"); 
    monsterArray[monster.id].view = 1;
    monsterArray[monster.id].lastPC[dim_x] = PC->position[dim_x]; 
    monsterArray[monster.id].lastPC[dim_y] = PC->position[dim_y];  

    monster_dijkstra(monster, PC, d, nonTunnels, 0); 

  //Monster item
   x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
   y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];
   //   printf("\nFinal next move was %d, %d \n", x, y); 
   }
  else if(monster.view == 1){

    //  printf("\nHave a last view\n"); 
    PC_t lastView;
    lastView.position[dim_x] = monster.lastPC[dim_x]; 
    lastView.position[dim_y] = monster.lastPC[dim_y]; 
    monster_dijkstra(monster, &lastView, d, nonTunnels, 0); 
      //Monster item
    x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
    y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];
  }
  else{
        if(d->hardness[monster.position[dim_y]][monster.position[dim_x]+1] == 0){
	  x = monster.position[dim_x] + 1;
	  y = monster.position[dim_y]; 
    
	}
	else if(d->hardness[monster.position[dim_y]][monster.position[dim_x]-1] == 0){
	  x = monster.position[dim_x] - 1;
	  y = monster.position[dim_y]; 
	}

  }
     identifyMonster(d, x, y);
    //THis uses a copy dungeon map to replace map with previous value
    //means when tunneling monsters extend rooms, copy dungeon needs to be updated
    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x;
    monsterArray[move.id].position[dim_y] = y;
    
    mapxy(monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y]) = monster.type;
    identifyPC(d,monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y], PC); 
  
}


void moveType2(move_t move, int i, PC_t *PC, dungeon_t* d){
  //Telepathic always moves towards PC
  Monster_t monster = monsterArray[move.id];
  int x = monster.position[dim_x];
  int y = monster.position[dim_y]; 

  if(x < PC->position[dim_x]){
     if( d->hardness[y][x+1] == 0){
        x = x + 1;
    }else{
       y = checkY(x, y, d); 
    }    
  }
  else if(x > PC->position[dim_x]){
    if( d->hardness[y][x-1] == 0){
        x = x - 1;
    }else{
      y = checkY(x, y, d); 
    } 
  }
  else if(y > PC->position[dim_y]){
    if( d->hardness[y-1][x] == 0){
      y = y - 1; 
    }else{
      x = checkX(x, y, d); 
    }
  }
  else if(y <  PC->position[dim_y]){
     if( d->hardness[y+1][x] == 0){
      y = y + 1; 
    }else{
       x = checkX(x, y, d); 
    }
  }
  else{
    //Take a position in the right direction
  }

   identifyMonster(d, x, y);
    //THis uses a copy dungeon map to replace map with previous value
    //means when tunneling monsters extend rooms, copy dungeon needs to be updated
    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x;
    monsterArray[move.id].position[dim_y] = y;
    
    mapxy(x,y) = monster.type;
    identifyPC(d,monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y], PC); 
  
  
}
void moveType3(move_t move, int i, PC_t *PC, dungeon_t* d){
  //Intelligence and telepathy
    Monster_t monster = monsterArray[move.id];
    int x, y; 
  
    monster_dijkstra(monster, PC, d, nonTunnels, 0); 
      //Monster item
    x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
    y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];

    identifyMonster(d, x, y);
    //THis uses a copy dungeon map to replace map with previous value
    //means when tunneling monsters extend rooms, copy dungeon needs to be updated
    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x;
    monsterArray[move.id].position[dim_y] = y;
    
    mapxy(x,y) = monster.type;
    identifyPC(d,monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y], PC); 
  
}

void tunnelThrough(Monster_t monster, int x, int y, dungeon_t* d, PC_t *PC){

  if(d->hardness[y][x] - 85 <= 0){
    d->hardness[y][x] = 0;
    //Change space to corridor, move in
    //Tunneling and non Tunneling distance map recalculations
    monsterArray[monster.id].tunneling = 0;
    dungeonCopy[y][x]  = ter_floor_hall;

    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);

        
    identifyPC(d,x, y, PC);
    identifyMonster(d, x, y);
    mapxy(x,y) = monster.type;
    
    monsterArray[monster.id].position[dim_x] = x;
    monsterArray[monster.id].position[dim_y] = y;
    
  }else{
    //subtract 85 and wait for next turn
    // printf("\nTunneling %d", d->hardness[y][x]);
    monsterArray[monster.id].tunneling = 1; 
    d->hardness[y][x] = d->hardness[y][x] - 85; 
  }
  
}
int moveRandomX(move_t move, dungeon_t* d){

  Monster_t monster = monsterArray[move.id];
  int x;
  x = monster.position[dim_x];

    if(x + 1 < 80){
       x = x+1; 
     }    
    else if(x-1 > 0){
       x = x-1; 
     }

    return x; 
  
}

int moveRandomY(move_t move, dungeon_t* d){

  Monster_t monster = monsterArray[move.id];
  int y;
  y = monster.position[dim_y];

     if(y + 1 < 21){
       y = y+1; 
     }    
     else if(y -1 > 0){
       y = y-1; 
     }

  return y; 
}


void moveType4(move_t move, int i, PC_t *PC,  dungeon_t* d){
  //Tunneling
  Monster_t monster = monsterArray[move.id];
  int x, y;
  x = monster.position[dim_x];
  y = monster.position[dim_y];
  
  if(monster.tunneling == 1){
    tunnelThrough(monster, monster.tunnelingX, monster.tunnelingY, d, PC); 
  }
  else{
    int direction = rand() % 4 + 1;
     if(direction == 1 && x + 1 < 80){
       x = monster.position[dim_x] +1;
       y = monster.position[dim_y]; 
     }
     else if(direction == 2 && x -1 > 0){
       x = monster.position[dim_x] - 1;
       y = monster.position[dim_y]; 
     }
     else if(direction == 3 && y -1 > 0 ){
       x = monster.position[dim_x];
       y = monster.position[dim_y] - 1; 
     } 
     else if(direction == 4 && y + 1 < 21){ 
       x = monster.position[dim_x];
       y = monster.position[dim_y] + 1;
     }
     else{
       x = moveRandomX(move, d);
       y = moveRandomY(move, d); 
     }

    if(d->hardness[y][x] > 0){
      monsterArray[monster.id].tunneling = 1;
      monsterArray[monster.id].tunnelingX = x;
      monsterArray[monster.id].tunnelingY = y; 
      tunnelThrough(monster, x, y, d, PC); 
    }else{
    //Just move to the spot      
      
      identifyPC(d,x, y, PC);
      identifyMonster(d, x, y);
      replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
      mapxy(x,y) = monster.type;
      
      monsterArray[monster.id].position[dim_x] = x;
      monsterArray[monster.id].position[dim_y] = y; 
     
    }
  }
 
  
}
void moveType5(move_t move, int i, PC_t *PC, dungeon_t* d){
  //Tunneling and Intelligent
   //Intelligent
  int choice = 0; 
  Monster_t monster = monsterArray[move.id];
  int x, y;
  //  printf("monster lastPC %d \n", monster.view); 
  //IF same room, or previously seen monster.view
  if(sameRoom(monster, PC, d) ==  1){
    choice = 1; 
      //Line of sight is same room
    // printf("line of sight"); 
    monsterArray[monster.id].view = 1;
    monsterArray[monster.id].lastPC[dim_x] = PC->position[dim_x]; 
    monsterArray[monster.id].lastPC[dim_y] = PC->position[dim_y];  

    monster_dijkstra(monster, PC, d, nonTunnels, 0); 

  //Monster item
   x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
   y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];
   //  printf("\nFinal next move was %d, %d \n", x, y); 
   }
  else if(monster.view == 1){
    choice = 1; 
    //    printf("\nHave a last view\n"); 
    PC_t lastView;
    lastView.position[dim_x] = monster.lastPC[dim_x]; 
    lastView.position[dim_y] = monster.lastPC[dim_y]; 
    monster_dijkstra(monster, &lastView, d, nonTunnels, 0); 
      //Monster item
    x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
    y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];
  }
  else{
    //Just move tunneling since you're intelligence doesn't matter right now
    moveType4(move, i, PC, d); 
  }
  if(choice == 1){
     identifyMonster(d, x, y);
    //THis uses a copy dungeon map to replace map with previous value
    //means when tunneling monsters extend rooms, copy dungeon needs to be updated
    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x; 
    monsterArray[move.id].position[dim_y] = y;
    
    mapxy(monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y]) = monster.type;
    identifyPC(d,monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y], PC); 
  }
}
void moveType6(move_t move, int i, PC_t *PC, dungeon_t* d){
  //Tunneling and telepathic
    Monster_t monster = monsterArray[move.id];
    int x, y; 
  
    monster_dijkstra(monster, PC, d, tunnels, 0); 
      //Monster item
    x = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_x];
    y = distances[monster.position[dim_y]][monster.position[dim_x]].next[dim_y];

    identifyMonster(d, x, y);
    //THis uses a copy dungeon map to replace map with previous value
    //means when tunneling monsters extend rooms, copy dungeon needs to be updated
    replaceXY(d, monster.position[dim_x], monster.position[dim_y]);
    
    monsterArray[move.id].position[dim_x] = x;
    monsterArray[move.id].position[dim_y] = y;
    
    mapxy(x,y) = monster.type;
    identifyPC(d,monsterArray[move.id].position[dim_x], monsterArray[move.id].position[dim_y], PC); 
  
  
}
void moveType7(move_t move, int i, PC_t *PC, dungeon_t* d){
  //Tunneling telepathic and Intelligent
  moveType6(move, i, PC, d); 
  
}
void moveType8(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic behavior
  int coin = rand() % 2; 

  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType2(move, i, PC, d); 
  }
  
}
void moveType9(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic and inteligent
   int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType1(move, i, PC, d); 
  }
  
}
void moveTypea(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic and telepathic
  int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType3(move, i, PC, d); 
  }
  
}
void moveTypeb(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic telepathic and intelligent
   int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType3(move, i, PC, d); 
  }
  
}
void moveTypec(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic and tunneling
   int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType4(move, i, PC, d); 
 }
  
}
void moveTyped(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic tunneling and intelligent
  int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType5(move, i, PC, d); 
 }
}
void moveTypee(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic tunneling and telepathic
   int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType6(move, i, PC, d); 
 }
}
void moveTypef(move_t move, int i, PC_t *PC, dungeon_t* d){
  //erratic tunneling telepathic and intelligent
     int coin = rand() % 2;
  if(coin){
    moveType0(move, i, PC, d); 
  }
  else{
    moveType7(move, i, PC, d); 
 }
}
void moveMonster(move_t move, dungeon_t* d, PC_t *PC){

  int i = move.id; 
 
    switch (monsterArray[i].type) {
         case ter_wall:
      case ter_wall_immutable:
        break;
      case ter_floor:
      case ter_floor_room:
        break;
      case ter_floor_hall:
        break;
      case ter_debug:
        break;
      case player:
	break;
      case monster0:
	moveType0(move, i, PC, d); 
	break;
      case monster1:
	moveType1(move, i, PC, d); 
	break;
      case monster2:
	moveType2(move, i, PC, d); 
	break;
      case monster3:
	moveType3(move, i, PC, d);
	break;
      case monster4:
	moveType4(move, i, PC, d); 
	break;
      case monster5:
	moveType5(move, i, PC, d); 
	break;
      case monster6:
	moveType6(move, i, PC, d);
	break;
      case monster7:
	moveType7(move, i, PC, d);
	break;
      case monster8:
	moveType8(move, i, PC, d);
	break;
      case monster9:
	moveType9(move, i, PC, d);
	break;
      case monstera:
	moveTypea(move, i, PC, d);
	break;
      case monsterb:
	moveTypeb(move, i, PC, d);
	break;
      case monsterc:
	moveTypec(move, i, PC, d);
	break;
      case monsterd:
	moveTyped(move, i, PC, d);
	break;
      case monstere:
	moveTypee(move, i, PC, d);
	break;
      case monsterf:
	moveTypef(move, i, PC, d);
	break;

    }
  createMonsterEvent(monsterArray[move.id] , move.id , 0); 
}

void playGame(dungeon_t* d, PC_t* PC){

  // display_event_queue(); 
    move_t move = event_pop();
      //If the event contains a move for a valid monster or player
      gameTurn++; 
      int i;
      int play = 1; 
      for(i = 0; i < 20; i++){
	if(deletedMonsters[i] == move.id && monsterArray[move.id].dead == 1){
	  play = 0; 
	}
      }

      
	if(move.isMonster == 0 && play == 1){
	  movePlayer(move, d, PC);
	  render_dungeon(d);
	  sleep(1);
	}else if(move.isMonster == 1 && play == 1){
	  moveMonster(move, d, PC); 
	}
 
}

void copyDungeon(dungeon_t *d){
  int i, j;
  for(i = 0; i < DUNGEON_Y; i++){
    for(j = 0; j < DUNGEON_X; j++){
      dungeonCopy[i][j] = d->map[i][j]; 
    }
  }
}

int main(int argc, char *argv[])
{
  dungeon_t d;
  time_t seed;
  struct timeval tv;
  uint32_t i;
  uint32_t do_load, do_save, do_seed, do_image;
  uint32_t long_arg;
  char *save_file;
  char *pgm_file;
  int nummon = 0; 

  /* Default behavior: Seed with the time, generate a new dungeon, *
   * and don't write to disk.                                      */
  do_load = do_save = do_image = 0;
  do_seed = 1;
  save_file = NULL;

  /* The project spec requires '--load' and '--save'.  It's common  *
   * to have short and long forms of most switches (assuming you    *
   * don't run out of letters).  For now, we've got plenty.  Long   *
   * forms use whole words and take two dashes.  Short forms use an *
`   * abbreviation after a single dash.  We'll add '--rand' (to     *
   * specify a random seed), which will take an argument of it's    *
   * own, and we'll add short forms for all three commands, '-l',   *
   * '-s', and '-r', respectively.  We're also going to allow an    *
   * optional argument to load to allow us to load non-default save *
   * files.  No means to save to non-default locations, however.    *
   * And the final switch, '--image', allows me to create a dungeon *
   * from a PGM image, so that I was able to create those more      *
   * interesting test dungeons for you.                             */

  if (argc == 3 && (strcmp(argv[1], "--nummon")== 0)){
    nummon = atoi(argv[2]);
  }
  
 else if (argc > 1) {
    for (i = 1, long_arg = 0; i < argc; i++, long_arg = 0) {
      if (argv[i][0] == '-') { /* All switches start with a dash */
        if (argv[i][1] == '-') {
          argv[i]++;    /* Make the argument have a single dash so we can */
          long_arg = 1; /* handle long and short args at the same place.  */
        }
        switch (argv[i][1]) {
        case 'r':
          if ((!long_arg && argv[i][2]) ||
              (long_arg && strcmp(argv[i], "-rand")) ||
              argc < ++i + 1 /* No more arguments */ ||
              !sscanf(argv[i], "%lu", &seed) /* Argument is not an integer */) {
            usage(argv[0]);
          }
          do_seed = 0;
          break;
        case 'l':
          if ((!long_arg && argv[i][2]) ||
              (long_arg && strcmp(argv[i], "-load"))) {
            usage(argv[0]);
          }
          do_load = 1;
          if ((argc > i + 1) && argv[i + 1][0] != '-') {
            /* There is another argument, and it's not a switch, so *
             * we'll treat it as a save file and try to load it.    */
            save_file = argv[++i];
          }
          break;
        case 's':
          if ((!long_arg && argv[i][2]) ||
              (long_arg && strcmp(argv[i], "-save"))) {
            usage(argv[0]);
          }
          do_save = 1;
          break;
        case 'i':
          if ((!long_arg && argv[i][2]) ||
              (long_arg && strcmp(argv[i], "-image"))) {
            usage(argv[0]);
          }
          do_image = 1;
          if ((argc > i + 1) && argv[i + 1][0] != '-') {
            /* There is another argument, and it's not a switch, so *
             * we'll treat it as a save file and try to load it.    */
            pgm_file = argv[++i];
          }
          break;
        default:
          usage(argv[0]);
        }
      } else { /* No dash */
        usage(argv[0]);
      }
    }
  }

  if (do_seed) {
    /* Allows me to generate more than one dungeon *
     * per second, as opposed to time().           */
    gettimeofday(&tv, NULL);
    seed = (tv.tv_usec ^ (tv.tv_sec << 20)) & 0xffffffff;
  }

  printf("Seed is %ld.\n", seed);
  srand(seed);

  init_dungeon(&d);

  if (do_load) {
    read_dungeon(&d, save_file);
  } else if (do_image) {
    read_pgm(&d, pgm_file);
  } else {
    gen_dungeon(&d);
  }

  //copy dungeon before characters get put in
  copyDungeon(&d); 

  if(nummon > 0){
    //Make monster events inside addMonster function
    monstersLeft = nummon; 
    placeMonsters(nummon, &d);

    int k;
    for(k = 0; k < nummon; k++){
      createMonsterEvent(monsterArray[k], k, 1); 
    }
  }

  
   //Put the player character
  PC_t player;
  putCharacter(&player, &d);
  createPlayerEvent(&player, 1); 
  
   putTunneling(&player, &d); 
   putNonTunnels(&player, &d); 
   
   render_dungeon(&d);
   print_tunnels(nonTunnels, 0, &player); 

   while(gameOver == 0){
      clear_pqueue(); 
      playGame(&d, &player);     
      //  render_dungeon(&d);
      clearTunnels();
      putTunneling(&player, &d); 
      putNonTunnels(&player, &d);
      //  print_tunnels(tunnels, 1, &player);
      //  print_tunnels(nonTunnels, 0, &player);      
   }
   if(win == 1){
     printf("\nYou Win!\n"); 
   }
   
  if (do_save) {
    write_dungeon(&d);
  }

  delete_dungeon(&d);

  return 0;
}

