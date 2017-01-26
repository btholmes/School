#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int X = 21;
const int Y = 80; 
int dimensions[7][4];
int rooms = 0;
int centerPoints[7][2]; 

int alreadyRoom(int, int, int, int);
int closestRoom(int, int, int, int, int);
int alreadyConnected(int, int, int[7][2]); 
int* center(int, int, int, int);
int* distance(int, int);
int roomInWay(int, int, char[X][Y]); 


void fillGrid(char grid[X][Y]){
  int i, j;
  for(i = 0; i < X; i++){
    for(j = 0; j < Y; j++){
      grid[i][j] = ' '; 
    }
  }
}

void printGrid(char grid[X][Y]){
  int i, j;
  for(i = 0; i < X; i++){
    for(j = 0; j < Y; j++){
      printf("%c", grid[i][j]); 
    }
    printf("\n"); 
  }
}


//This function gets 4 random numbers for startX, startY, sizeX, and sizeY
int* getRandoms() {
  static int numbers[4];

      numbers[0]  = (rand() % 60) + 10;
      numbers[1]  = (rand() % 10) + 5; 
      numbers[2]  = (rand() % 6) + 4;
      numbers[3]  = (rand() % 7) + 3;      
    
  
  return numbers; 
  
}

//This function attempts to create a room with the given random numbers, if it succeeds,
//the room dimensions are added to dimensions array, and rooms variable is added by 1, otherwise,
//nothing happens
void createRoom(int startX, int startY, int xSize, int ySize, char grid[X][Y]){

    int roomCreated = 0; 

    int i = 0;
    int j = 0;

    if(alreadyRoom(startX, startY, xSize, ySize)){
      
    }else{
      roomCreated = 1; 

      for(i = startY; i < (startY + ySize); i++)
       {
	 for(j = startX; j < (startX +  xSize); j++)
		{
		  if(grid[i][j] != '.'){
		    grid[i][j] = '.'; 
		   
		  }
				    
		}
       }

          if(roomCreated)
	  {
      
	    dimensions[rooms][0] = startX;
	    dimensions[rooms][1] = startY;
	    dimensions[rooms][2] = xSize;
	    dimensions[rooms][3] = ySize; 
	    rooms += 1;
	
	  }
    }
 
}

//Make sure dimensions extend to one space on each side. 
int alreadyRoom(int x, int y, int xSize, int ySize) {

  int i, j,k;
  for(i = 0; i < rooms; i++){
    int xPoint  = dimensions[i][0] - 1;
    int xSpan = dimensions[i][2];
    int endX = xPoint + (xSpan+1);

    int yPoint  = dimensions[i][1] - 1;
    int ySpan  = dimensions[i][3];
    int endY = yPoint  + (ySpan + 1);

    int newEndX = x + (xSize - 1);
    int newEndY = y + (ySize - 1);

    //x range is x to newEndX
    //y range is y to newEndY

    //if new X value is within current room dimension x range
 
    for(j =x; j <= newEndX; j++){
      for(k = y; k <= newEndY; k++){
	if((j >= xPoint && j <= endX)){
	  //if y value is also within current room range, then rooms overlap
	  if((k >= yPoint && k <= endY)){
	    return 1; 
	  }
	}
      }
    }
    
  }
  return 0; 
}
//This method just finds whatever rooms needs a connection still
int nextClosestRoom( int room, int connection,  int connections[7][2]){
  int placeInDimension;
  int i;
  int totalDistance = 100000; 
  
  for(i = 0; i < rooms; i++){
    if(i != room){
      if(!alreadyConnected(room, i, connections)){
	 int* distances =  distance(room, i);
	 if((distances[0] + distances[1]) < totalDistance){
	   totalDistance = distances[0] + distances[1];
	   
	   placeInDimension = i; 
	 }
      }
    }
  }
  return placeInDimension; 
}

//Returns 1 number which is the location of the closest room in dimensions
int closestRoom(int startX, int startY, int xSize, int ySize, int room){
  int placeInDimension;
  int i;
  int totalDistance = 10000; 
  
  for(i = 0; i < rooms; i++){
    if(i != room){
      int* distances =  distance(room, i);
      if((distances[0] + distances[1]) < totalDistance){
	totalDistance = distances[0] + distances[1];
	placeInDimension = i; 
      }
    }
  }
  return placeInDimension; 
}

//Returns array where first number is X distance, and 2nd number is Y distance total distance is
//these two numbers added together
//Parameters are two positions in the dimensions array
int* distance(int room, int i){
  
  static int distances[2];
  int X1 = centerPoints[room][0];
  int Y1 = centerPoints[room][1];

  int X2 = centerPoints[i][0];
  int Y2 = centerPoints[i][1];

  distances[0] = abs(X2 - X1);
  distances[1] = abs(Y2 - Y1); 
  
  return distances; 
}

//Helper method for getAllCenters returns a single center point
int* center(int startX, int startY, int xSize, int ySize){
  static int center[2];

  int endX = startX + (xSize - 1);
  int endY = startY + (ySize - 1);
  int middleX = startX + (endX - startX)/2 + 1;
  int middleY = startY + (endY - startY)/2 + 1;

  center[0] = middleX;
  center[1] = middleY;

  return center; 
  
}

void getAllCenters(){
  
  int i;

  //Get all center points for the rooms
  for(i = 0; i < rooms; i++){
    int* centerPoint = center(dimensions[i][0], dimensions[i][1], dimensions[i][2], dimensions[i][3]);
    centerPoints[i][0]  = centerPoint[0];
    centerPoints[i][1] = centerPoint[1]; 
  }
}


void connectY(int startY, int endSpotY, int endSpotX, char grid[X][Y]){
      //Start Y is above connecting block
    if(startY < endSpotY){
      while(startY <= endSpotY){
	if(roomInWay(endSpotX, startY, grid)){
	  startY++;  
	}else{
	  grid[startY][endSpotX] = '#';
	  startY++; 
	}

      }
    }
    //Start Y is below endSpotY
    else if(startY > endSpotY){
      while(startY >= endSpotY){
	if(roomInWay(endSpotX, startY, grid)){
	  startY--; 
	}else{
	  grid[startY][endSpotX] = '#';
	  startY--; 
	}

      }
    } 
}

void connectX(int startX, int endSpotX, int endSpotY, char grid[X][Y]){
    //Start X is left of EndX
    if(startX < endSpotX){
      while(startX <= endSpotX){
	if(roomInWay(startX, endSpotY, grid)){
	  startX++; 
	}else{
	    grid[endSpotY][startX] = '#';
	    startX++; 
	}

      }
    }
    //Start X is to the right of endSpotX
    else if(startX  > endSpotX){
      while(startX >= endSpotX){
	if(roomInWay(startX, endSpotY, grid)){
	  startX--; 
	}else{
	  grid[endSpotY][startX] = '#';
	  startX--; 
	}

      }
    } 
}

int roomInWay(int startX, int startY, char grid[X][Y]){

  if(grid[startY][startX] == '.' ){
    return 1; 
  }
  
  return 0; 
}

void connectRooms(int i, int nearestRoom, char grid[X][Y]){

  int X1 = dimensions[i][0];
  int Y1 = dimensions[i][1];
  int endX = X1 + dimensions[i][2] - 1;
  int endY = Y1 + dimensions[i][3] - 1;

  int X2 = dimensions[nearestRoom][0];
  int Y2 = dimensions[nearestRoom][1];
  int endX2 = X2 + dimensions[nearestRoom][2]-1;
  int endY2 = Y2 + dimensions[nearestRoom][3]-1;


  int startX;
  int endSpotX;
  int startY;
  int endSpotY; 

  //First block end  point is to the left of X2
  if( endX < (X2-1)){
    //X connection span
    startX = endX + 1;
    endSpotX = X2 - 1;
    //Start Y is in middle of block
    startY = Y1 + (endY - Y1)/2;
    //End spot Y is in the middle of second block
    endSpotY = Y2 + (endY2 - Y2)/2; 


    while(startX <= endSpotX){
      if(roomInWay(startX, startY, grid)){
        startY--;
	startX--; 
      }else{
	grid[startY][startX] = '#';
	startX++;
      }
      
    }
    connectY(startY, endSpotY, endSpotX, grid); 
  }
  //First block beginning is to the right of 2nd block ending
  else if(X1 > endX2){
    startX = X1 - 1;
    endSpotX = endX2 + 1;
    endSpotY = Y2 + (endY2 - Y2)/2;
    startY = Y1 + (endY - Y1)/2;

    while(startX >= endSpotX){
      if(roomInWay(startX, startY, grid)){
	startX++;
	startY--;
      }else{
       	grid[startY][startX] = '#';
	startX--;  
      }   
    }
    connectY(startY, endSpotY, endSpotX, grid);     
  }
  //First block endY is above beginning of second block
  else if(endY < Y2){
    //Now X starts in the middle of first block
    startX = X1 + (endX - X1)/2;
    endSpotX = X2 + (endX2 - X2)/2;
    startY = endY + 1;
    endSpotY = Y2 - 1;

    while(startY <= endSpotY){
      if(roomInWay(startX, startY, grid)){
	startX++;
	startY--;
      }else{
	 grid[startY][startX] = '#';
	 startY++; 
      }

    }
    connectX(startX, endSpotX, endSpotY, grid); 
  }
  //Second block ending is above first block beginning
  else if(endY2 < Y1){
      //X starts in the middle of 2nd block
    startX = X2 + (endX2 - X2)/2;
    endSpotX = X1 + (endX - X1)/2;
    startY = endY2 + 1;
    endSpotY = Y1 - 1;

    while(startY <= endSpotY){
      if(roomInWay(startX, startY, grid)){
	startX++;
	startY--;
      }else{
	grid[startY][startX] = '#';
	startY++; 
      }
      
    }
    connectX(startX, endSpotX, endSpotY, grid); 
  }
  
}



int alreadyConnected(int a, int b, int connections[7][2]){

  int i;
  for(i = 0; i < 7; i++){
    if(connections[i][0] == a){
      if(connections[i][1] == b){
	return 1; 
      }
    }
    if(connections[i][0] == b){
      if(connections[i][1] == a){
	return 1; 
      }
    }
  }

  return 0; 
}

int main(int argc, char * argv[]){
  srand(time(NULL)); 
  char grid[X][Y];
  int* numbers;
  //This is an array which stores all the room connections
  int connections[7][2];
  int needsConnection[7]; 

  numbers = getRandoms();
  int i;
  
  fillGrid(grid);

  while(rooms < 7){
    numbers = getRandoms();
    createRoom(numbers[0], numbers[1], numbers[2], numbers[3], grid);    
  }

  getAllCenters();
   int nearestRoom;
   int nextClosest; 
  //Now find the closest rooms
  for( i = 0; i < rooms; i++){
        nearestRoom =  closestRoom(dimensions[i][0], dimensions[i][1], dimensions[i][2], dimensions[i][3], i);
    //If the two rooms aren't already connected, connect them
     if(!alreadyConnected(i, nearestRoom, connections)){
      
        connections[i][0] = i;
      connections[i][1] = nearestRoom;
      
        connectRooms(i, nearestRoom, grid);
      //If the rooms are connected already, find a different room that only has one connection
      }else {
          needsConnection[i] = i;
         nextClosest = nextClosestRoom( i, nearestRoom, connections);
      connectRooms(i, nextClosest, grid);
    }
        if(i == rooms - 1){
           connectRooms(i, 0, grid);      
        }
        else{
          connectRooms(i, i+1, grid); 
         }   
  }
  printGrid(grid); 
    printf("\n"); 
  
}
