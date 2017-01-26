#include <stdlib.h>
#include<ncurses.h> 
#include "string.h"
#include "dungeon.h"
#include "pc.h"
#include "utils.h"
#include "move.h"
#include "path.h"
#include "npc.h"

int distArray[1000][2];
char xDirectionArray[1000][10];
char yDirectionArray[1000][10];
char symbolArray[1000]; 

int displayedMonsters = 0; 
int scrollPosTop = 0;
int monsterCount = 0; 
int spot = 0; 

void pc_delete(pc_t *pc)
{
  if (pc) {
    free(pc);
  }
}

uint32_t pc_is_alive(dungeon_t *d)
{
  return d->pc.alive;
}

void place_pc(dungeon_t *d)
{
  d->pc.position[dim_y] = rand_range(d->rooms->position[dim_y],
                                     (d->rooms->position[dim_y] +
                                      d->rooms->size[dim_y] - 1));
  d->pc.position[dim_x] = rand_range(d->rooms->position[dim_x],
                                     (d->rooms->position[dim_x] +
                                      d->rooms->size[dim_x] - 1));
}

void config_pc(dungeon_t *d)
{
  memset(&d->pc, 0, sizeof (d->pc));
  d->pc.symbol = '@';

  place_pc(d);

  d->pc.speed = PC_SPEED;
  d->pc.alive = 1;
  d->pc.sequence_number = 0;
  d->pc.pc = calloc(1, sizeof (*d->pc.pc));
  d->pc.npc = NULL;

  d->character[d->pc.position[dim_y]][d->pc.position[dim_x]] = &d->pc;

  dijkstra(d);
  dijkstra_tunnel(d);
}

void addToList(char symbol, int xDist, char* xDirection, int yDist, char* yDirection){

  symbolArray[spot] = symbol;
  distArray[spot][0] = xDist;
  distArray[spot][1] = yDist;
  strcpy(xDirectionArray[spot], xDirection);
  strcpy(yDirectionArray[spot], yDirection); 
  
  spot++;
  monsterCount++; 
  
}

void calculate_pc_distance(dungeon_t *d,char symbol,  int* x, int*y){

 
  char xDirection[10];
  char yDirection[10]; 
  int a = d->pc.position[dim_x];
  int b = d->pc.position[dim_y];
  if(*x < a){
    strcpy(xDirection, "West");
  }else{
    strcpy(xDirection, "East");
  }
  if(*y < b){
      strcpy(yDirection, "North"); 
  }else{
      strcpy(yDirection, "South"); 
  }
  int xDist = abs(*x - a); 
  int yDist = abs(*y - b);

  addToList(symbol, xDist, xDirection, yDist, yDirection);
  
  if(displayedMonsters < 24){
     printw("%c, is %d %s, %d %s distance \n",symbol, xDist,xDirection,  yDist, yDirection );
     displayedMonsters++; 
  }
 

}

void display_monsters(dungeon_t *d){

  clear(); 
  int i, j;
  for(i = 0; i < DUNGEON_Y; i++){
    for(j = 0; j < DUNGEON_X; j++){
     if (d->character[i][j]) {
	 char symbol = d->character[i][j]->symbol;
	 if(symbol != '@'){
	   int x = j;
	   int y = i;
	   calculate_pc_distance(d,symbol,  &x, &y);
	 }
	 
       }
    }
  }
  refresh();
  getch(); 
  
}

uint32_t pc_next_pos(dungeon_t *d, pair_t dir)
{
  dir[dim_y] = dir[dim_x] = 0;

  int x = d->pc.position[dim_x]; 
  int y = d->pc.position[dim_y]; 
  /* Tunnel to the nearest dungeon corner, then move around in hopes *
   * of killing a couple of monsters before we die ourself.          */
  int move = getch();
  refresh(); 
  
   //Upper left
  if(inMonsterDisplay == 0){
    if(move == 55 || move == 121 ){
      if(d->hardness[y-1][x-1] == 0){
	dir[dim_x] = -1;
	dir[dim_y] = -1; 
      }
    }
    //Move up
    else if(move == 56 || move == 107){
      if(d->hardness[y-1][x] == 0){
	dir[dim_y] = -1;  
      }
    }
    //Upper right
    else if(move == 57 || move == 117){
      if(d->hardness[y-1][x+1] == 0){
	dir[dim_y] = -1;
	dir[dim_x] = 1;  
      }
    }
    //right
    else if(move == 54 || move == 108){
      if(d->hardness[y][x+1] == 0){
	dir[dim_x] = 1; 
      }
    }
    //Lower right
    else if(move == 51 || move == 110){
      if(d->hardness[y+1][x+1] == 0){
	dir[dim_y] =1;
	dir[dim_x] = 1;  
      }
    }
    //Down
    else if(move == 50 || move == 106){
      if(d->hardness[y+1][x] == 0){
	dir[dim_y] = 1;  
      }
    }
    //Lower left
    else if(move == 49 || move == 98){
      if(d->hardness[y+1][x-1] == 0){
	dir[dim_y] = 1; 
	dir[dim_x] = -1; 
      }
    }
    //Left
    else if(move == 52 || move == 104){
      if(d->hardness[y][x-1] == 0){
	dir[dim_x] = -1;  
      }
    }
    //Down Stairs
    else if(move == 62 && x == downStairCase[dim_x] && y == downStairCase[dim_y]){
     
      // gen_monsters(&basementDungeon);
      delete_dungeon(d);
      init_dungeon(d);
      gen_dungeon(d);
      placeStairs(d, 1);
      placeStairs(d, 0);
      config_pc(d);
      gen_monsters(d); 
      render_dungeon(d);
   
    }
    //Up stairs
    else if(move == 60 && x == upStairCase[dim_x] && y == upStairCase[dim_y]){
      //Remember basement is actually upstairs now
      delete_dungeon(d);
      init_dungeon(d);
      gen_dungeon(d);
      placeStairs(d, 1);
      placeStairs(d, 0);
      config_pc(d);
      gen_monsters(d); 
      render_dungeon(d);
   
    }
    //rest a turn
    else if(move == 53 || move == 32){
      //do nothing 
    }
    //quit game
    else if(move == 81){
          
      printf("Thanks for playing\n");
      exit(-1);
    }
  }
    //109 Display monsters
  if(move == 109){
    display_monsters(d);
    inMonsterDisplay = 1; 
  }

  while(inMonsterDisplay){
    //27 escape monster list
    int move = getch(); 
    if(move == 27 && inMonsterDisplay == 1){
      render_dungeon(d);
      inMonsterDisplay = 0; 
    }
    //65 is scroll up
    else if(move == 65 && inMonsterDisplay == 1){
      getch(); 
      scrollPosTop--;
   
      if(abs(scrollPosTop) >= 0 && abs(scrollPosTop) <= monsterCount){
	spot = abs(scrollPosTop);
	int i;
	clear(); 
	for(i = spot; i < spot+24; i++){
	  printw("%c, is %d %s, %d %s distance \n",symbolArray[i], distArray[i][0],xDirectionArray[i], distArray[i][1], yDirectionArray[i] );
	  
	}
       	refresh(); 
      }else{
	scrollPosTop++; 
      }
       
    }
    //66 is scroll down monster window
    else if(move == 66 && inMonsterDisplay == 1){
       getch(); 
      scrollPosTop++;
      
      if(abs(scrollPosTop) >= 0  && abs(scrollPosTop) <= monsterCount && (scrollPosTop - 1 != 0)){
	spot = abs(scrollPosTop);
	int i;
	clear(); 
	for(i = spot; i < spot+24; i++){
	  printw("%c, is %d %s, %d %s distance \n",symbolArray[i], distArray[i][0],xDirectionArray[i], distArray[i][1], yDirectionArray[i] );	  
	}
       	refresh(); 
      }else{
	scrollPosTop--; 
      }
      
    }
  }
  
   
  return 0;
}
