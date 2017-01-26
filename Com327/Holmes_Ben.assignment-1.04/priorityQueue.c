/* 
 * C Program to Implement Priority Queue to Add and Delete Elements
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 
#define event_queue_size 99999
#define MAX 5

int spot = 0; 

typedef enum dim {
  dim_x,
  dim_y,
  num_dims
} dim_t;

typedef int16_t pair_t[num_dims];

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

typedef struct Monster {

  pair_t position;
  int skills[4];
  terrain_type_t type; 
  int speed; 
  
}Monster_t;

typedef struct moveEvent {
  //boolean value to tell me if this is the player character
  int isMonster; 
  int priority;  //gameTurn + turn; 
  // int speed;
  int turn; // 100\speed
  //use pointer to monster to determine whom to give the move too
  Monster_t* monster;
  int PC; 
  
} move_t; 


int eventFront, eventRear;
int eventSize = 0; 

void moveMonster(Monster_t* monster){
  //printf("rand is %d\n", rand()%100); 
  monster->position[dim_x] += rand() %100; 
}


move_t createMonsterEvent(Monster_t *monster){
  //Turn doesn't need to be added the first time around
  //   printf("in monster event  x %d, and y %d \n", monster->position[dim_x], monster->position[dim_y]); 

  move_t event;
  event.isMonster = 1; 
  event.priority = 0;
  event.monster = monster;
  event.monster->position[dim_x] = spot;
  // printf("in create monster x is %d \n", event.monster->position[dim_x]); 
  spot++; 
  // insert_by_event_priority(event);

  return event; 
}


void addMonsterPosition(Monster_t*  monster){


  int xVal = rand() % 66;
  int yVal = rand() % 66; 
  
  //  printf("x coord is %d, x size is %d, rand x is %d \n ",d->rooms[place].position[dim_y],d->rooms[place].size[dim_y], yVal  ); 
  
   monster->position[dim_x] = xVal;
   monster->position[dim_y] = yVal;

   //THIS IS WHERE I SHOULD CREATE THE MONSTER EVENT ****************
   createMonsterEvent(monster); 

}

void addMonster(Monster_t *monster){

   move_t event = createMonsterEvent(monster);
   event.priority = spot;
   spot++; 
   //   insert_by_event_priority(event); 
}


struct data
{
    char job[MAX] ;
    int prno ;
    int ord ;
} ;

struct pque
{
    move_t d[MAX] ;
    int front ;
    int rear ;
} ;

void initpque ( struct pque * ) ;
void add ( struct pque *, move_t data ) ;
move_t delete ( struct pque * ) ;
void printQueue(struct pque *); 

void main( )
{

  struct pque q ;
   initpque ( &q ) ;
  
    
    Monster_t mon;
    move_t temp ;
    int i, j = 0 ;

    for(i = 0; i < MAX; i++){
      move_t move;
      move =  createMonsterEvent(&mon);
      move.priority = i;

      //   printf("in main move x is %d \n", move.monster->position[dim_x]); 
      
      add(&q, move); 
    }

    printQueue(&q); 
    



    /*   printf ( "Enter Job description (max 4 chars) and its priority\n" ) ;
    printf ( "Lower the priority number, higher the priority\n" ) ;
    printf ( "Job     Priority\n" ) ;  */

    /*    for ( i = 0 ; i < MAX ; i++ )
    {
        scanf ( "%s %d", &dt.job, &dt.prno ) ;
        dt.ord = j++ ;
        add ( &q, dt ) ;
    }
    printf ( "\n" ) ;

    printf ( "Process jobs prioritywise\n" ) ;
    printf ( "Job\tPriority\n" ) ;*/


    for ( i = 0 ; i < MAX ; i++ )
    {
        temp  = delete ( &q ) ;
        printf ( "i is %d ,priority  %d, x is %d\n", i, temp.priority, temp.monster->position[dim_x] ) ;
    }
    printf ( "\n" ) ;

}

/* initialises data members */
void initpque ( struct pque *pq )
{
    int i ;

    pq -> front = pq -> rear = -1 ;
    /*    for ( i = 0 ; i < MAX ; i++ )
    {
        strcpy ( pq -> d[i].job, '\0' ) ;
        pq -> d[i].prno = pq -> d[i].ord = 0 ;
	}*/
}

/* adds item to the priority queue */
void add ( struct pque *pq, move_t dt )
{
    move_t temp ;
    int i, j ;

    //  printf("In ADD move x is %d \n", dt.monster->position[dim_x]); 

    if ( pq -> rear == MAX - 1 )
    {
        printf ( "\nQueue is full." ) ;
        return ;
    }

    pq -> rear++ ;
    pq -> d[pq -> rear] = dt ;

    if ( pq -> front == -1 )
        pq -> front = 0 ;

    for ( i = pq -> front ; i <= pq -> rear ; i++ )
    {
        for ( j = i + 1 ; j <= pq -> rear ; j++ )
        {
            if ( pq -> d[i].priority > pq -> d[j].priority )
            {
                temp = pq -> d[i] ;
                pq -> d[i] = pq -> d[j] ;
                pq -> d[j] = temp ;
            }
	    /*    else
            {
                if ( pq -> d[i].prno == pq -> d[j].prno )
                {
                    if ( pq -> d[i].ord > pq -> d[j].ord )
                    {
                        temp = pq -> d[i] ;
                        pq -> d[i] = pq -> d[j] ;
                        pq -> d[j] = temp ;
                    }
                }
		}*/
        }
    }
}

/* removes item from priority queue */
move_t  delete ( struct pque *pq )
{
    move_t  t ;
    //    strcpy ( t.job, "" ) ;
    t.priority = 0 ;
    // t.ord = 0 ;

    if ( pq -> front == -1 )
    {
        printf ( "\nQueue is Empty.\n" ) ;
        return t ;
    }

    t = pq -> d[pq -> front] ;
    pq -> d[pq -> front] = t ;
    if ( pq -> front == pq -> rear )
         pq -> front = pq -> rear = -1 ;
    else
         pq -> front++ ;

    return  t ;
}

void printQueue(struct pque *pq){
  int i; 
    for(i = 0; i < MAX; i++){
      printf("After initial ADD i is %d, priority is %d, x is %d \n",i,  pq->d[i].priority, pq->d[i].monster->position[dim_x]); 
    }
}
 
