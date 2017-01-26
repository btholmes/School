#include <stdio.h>
//need standard for malloc and random
#include <stdlib.h>
#include <time.h>

//In header files use
//#ifndef Stack_H
//#define Stack_H

//put typedef and function declarations here
//#endif

//This is a forward reference which lets you tell the compiler this exists, so
//you can define these types inside themselves
typedef struct stack_node stack_node_t; 

typedef struct stack_node {

  int value;
  //Pointer to next stack value, has to be a pointer because struct
  //stack_node isn't defined until after this declaration
  //This is using a forward reference
  stack_node_t *next; 
  
}stack_node_t; 

/* 
   This is without using the forward reference
   typedef struct stack_node {
   int value; 
   struct stack_node *next; 
   } stack_node_t; 
 */

//Can declare a structure in both of these two ways
struct stack_node node;
stack_node_t node;

typedef struct stack {
  int size;
  stack_node_t *top;
  
} stack_t; 

int stack_init(stack_t *s);
int stack_delete(stack_t *s); 
int stack_push(stack_t *s, int value);
int stack_pop(stack_t *s, int *v); 
int stack_is_empty(stack_t *s);
int stack_size(stack_t *s);

int stack_init(stack_t *s){
  s->size = 0;
  s->top = NULL;

  return 0; 
}

int stack_delete(stack_t *s){

  stack_node_t *tmp; 
  s->size = 0;

  while(s->top){
    tmp = s->top;
    s->top = s->top->next;
    free(tmp); 
  }
  return 0; 
  
}

int stack_push(stack_t *s, int value){
  stack_node_t *n;
  //*n is an instance of stack_node_t
  n = malloc(sizeof(*n));

  if(n == NULL){
    return 1; 
  }
  
  n->value = value;
  s->size++;
  n->next = s->top;
  s->top = n;

  return 0; 
}

int stack_pop(stack_t *s, int *v){

  stack_node_t *tmp; 
  
  if(!s->top){
    return 1; 
  }

  *v = s->top->value;
  s->size--; 
  tmp = s->top; 
  s->top = s->top->next;
  free(tmp); 

  return 0; 
  
}

int stack_is_empty(stack_t *s){
  return !s->top; 
}

int stack_size(stack_t *s){

  return s->size; 
}

int main(int argc, char * argv[]){

  //You cannot dereference a type of void *
  //void *malloc(sizeof(int)* 6)

  stack_t s;
  stack_init(&s);

  stack_push(&s, 0);
  stack_push(&s, 1);
  stack_push(&s, 2);
  stack_push(&s, 3);

  int i;
  while(!stack_is_empty(&s)){
    stack_pop(&s, &i);
    printf("%d\n", i); 
  }
  
  
}
