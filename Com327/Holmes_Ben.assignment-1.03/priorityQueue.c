/* 
 * C Program to Implement Priority Queue to Add and Delete Elements
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
#define MAX 1680

typedef enum dim {
  dim_x,
  dim_y,
  num_dims
} dim_t;

typedef int16_t pair_t[num_dims];

typedef struct room {
  pair_t position;
  pair_t size;
  uint32_t connected;
} room_t;

typedef struct dungeon {
  uint32_t num_rooms;
  room_t *rooms;
  //  terrain_type_t map[DUNGEON_Y][DUNGEON_X];
  /* Since hardness is usually not used, it would be expensive to pull it *
   * into cache every time we need a map cell, so we store it in a        *
   * parallel array, rather than using a structure to represent the       *
   * cells.  We may want a cell structure later, but from a performanace  *
   * perspective, it would be a bad idea to ever have the map be part of  *
   * that structure.  Pathfinding will require efficient use of the map,  *
   * and pulling in unnecessary data with each map cell would add a lot   *
   * of overhead to the memory system.                                    */
  uint8_t hardness[21][80];
} dungeon_t;

typedef struct priority {
  pair_t position;
  uint8_t distance;
} priority_t; 

void insert_by_priority(priority_t);
void delete_by_priority(priority_t);
void create();
void check(priority_t);
void display_pqueue();
priority_t pop(); 
 
priority_t pri_que[MAX];
int front, rear;
int queueSize = 0; 
 
void main()
{
    int n, ch, i;
   

    create();
    
    for(i = 100; i >0; i--){
       priority_t item;
      item.distance = i; 
      insert_by_priority(item); 
    }

    priority_t item;
    item.distance = 55; 
    delete_by_priority(item);
    
    pop();
    pop(); 
    printf("Size %d \n", queueSize);
    display_pqueue();

}
 
/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
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

  //   printf("Popped %d\n", pri_que[front].distance);
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
        printf("\nQueue is empty no elements to delete");
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
 
        pri_que[i].distance = -99;
        rear--;
	queueSize--;

	if (rear == -1) 
            front = -1;
        return;
        }

    }
    printf("\n%d not found in queue to delete\n", data.distance);
}
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front].distance);
    }
 
    front = 0;
}
