#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>
#include <sys/stat.h>

//htobe32()
//be32toh()
#include <endian.h> 


typedef struct room {

  uint8_t  hardness;
  char display; 

}room_t;

const int X = 21;
const int Y = 80; 
int dimensions[7][4];
int others[1680][4];
int spot = 0; 
uint8_t rockValues[21][80]; 
int rooms = 0;
int centerPoints[7][2];


void placeRooms(uint8_t roomX, uint8_t xSize, uint8_t roomY, uint8_t ySize, room_t grid[21][80]);

int alreadyRoom(int, int, int, int);
int closestRoom(int, int, int, int, int);
int alreadyConnected(int, int, int[7][2]); 
int* center(int, int, int, int);
int* distance(int, int);
int roomInWay(int, int, room_t grid[X][Y]);
 

/*
typedef struct dungeon {
  uint32_t num_rooms;
  room_t rooms[MAX_ROOMS];
  terrain_type_t map[DUNGEON_Y][DUNGEON_X];
  uint8_t hardness[DUNGEON_Y][DUNGEON_X]; 
}dungeon_t; 
*/

void outerHardness(room_t grid[X][Y]){
  int i;
  int j;
  //Top Row & bottom row
  for(i = 0; i < 80; i++){
    rockValues[0][i] = 255;
    rockValues[20][i] = 255; 
    grid[0][i].hardness = 255;   
    grid[20][i].hardness = 255;
    grid[0][i].display  = ' ';    
    grid[20][i].display = ' ';
  }
  //Left & right end rows
  for(j = 0; j < 21; j++){
    rockValues[j][0] = 255;
    rockValues[j][79] = 255; 
    grid[j][0].hardness = 255;
    grid[j][79].hardness = 255;
    grid[j][0].display = ' ';
    grid[j][79].display = ' '; 
  }
}
//Fills room with random hardness, then assigns outer hardness 255
void fillRoomGrid(room_t grid[X][Y]){
  int i, j;
  for(i = 0; i < X; i++){
    for(j = 0; j < Y; j++){
      room_t room;
      room.display = ' ';
      room.hardness = (rand() % 253)+1;
      rockValues[i][j] = (rand() % 253) + 1; 
      grid[i][j] = room;
    }
  }
  outerHardness(grid); 
}



//This function gets 4 random numbers for startX, startY, sizeX, and sizeY
int* getRandoms() {
  static int numbers[4];

      numbers[0]  = (rand() % 55) + 10;
      numbers[1]  = (rand() % 8) + 5; 
      numbers[2]  = (rand() % 6) + 4;
      numbers[3]  = (rand() % 4) + 3;      
    
  
  return numbers; 
  
}

//This function attempts to create a room with the given random numbers, if it succeeds,
//the room dimensions are added to dimensions array, and rooms variable is added by 1, otherwise,
//nothing happens
void createRoom(int startX, int startY, int xSize, int ySize, room_t grid[X][Y]){

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
		  if(grid[i][j].display != '.'){
		    grid[i][j].hardness = 0;
		    rockValues[i][j] = 0; 
		    grid[i][j].display = '.'; 
		   
		  }
				    
		}
       }

          if(roomCreated)
	  {
	    
	//    dimensions = malloc(sizeof(roomSize_t)); 	  	    

	    // spot = spot-1; 		       
	    //  printf("Size of dimensions %d\n", spot);

	    dimensions[rooms][0] = startX;
	    dimensions[rooms][1]= startY;
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


void connectY(int startY, int endSpotY, int endSpotX, room_t grid[X][Y]){
      //Start Y is above connecting block
    if(startY < endSpotY){
      while(startY <= endSpotY){
	if(roomInWay(endSpotX, startY, grid)){
	  startY++;  
	}else{
	  grid[startY][endSpotX].hardness  = 0;
	  rockValues[startY][endSpotX] = 0; 
	  grid[startY][endSpotX].display = '#';
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
	  grid[startY][endSpotX].hardness = 0;
	  rockValues[startY][endSpotX] = 0; 
	  grid[startY][endSpotX].display = '#';
	  startY--; 
	}

      }
    } 
}

void connectX(int startX, int endSpotX, int endSpotY, room_t grid[X][Y]){
    //Start X is left of EndX
    if(startX < endSpotX){
      while(startX <= endSpotX){
	if(roomInWay(startX, endSpotY, grid)){
	  startX++; 
	}else{
	    grid[endSpotY][startX].hardness = 0;
	    rockValues[endSpotY][startX] = 0; 
	    grid[endSpotY][startX].display = '#';
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
	  grid[endSpotY][startX].hardness = 0;
	  rockValues[endSpotY][startX] = 0; 
	  grid[endSpotY][startX].display = '#';
	  startX--; 
	}

      }
    } 
}

int roomInWay(int startX, int startY, room_t grid[X][Y]){

  if(grid[startY][startX].display == '.' ){
    return 1; 
  }
  
  return 0; 
}

void connectRooms(int i, int nearestRoom, room_t grid[X][Y]){

  int X1 = dimensions[i][0];
  int Y1 = dimensions[i][1];
  int endX = X1 + dimensions[i][2]- 1;
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
        grid[startY][startX].hardness = 0;
	rockValues[startY][startX] = 0; 
	grid[startY][startX].display = '#';
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
	grid[startY][startX].hardness = 0;
	rockValues[startY][startX] = 0; 
       	grid[startY][startX].display = '#';
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
	 grid[startY][startX].hardness = 0;
	 rockValues[startY][startX] = 0; 
	 grid[startY][startX].display = '#';
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
	grid[startY][startX].hardness = 0;
	rockValues[startY][startX] = 0; 
	grid[startY][startX].display = '#';
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

void printGrid(room_t grid[21][80]){
  int i;
  int j;
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      printf("%c", grid[i][j].display); 
    }
    printf("\n"); 
  }
  
}

char* append(char* str1, char* str2){

  char* HOME  = malloc(sizeof(char) * strlen(str1) + sizeof(char) * strlen(str2)); 

  strcat(HOME, str1);
  strcat(HOME, str2);
  
  return HOME; 
}
char* getFolderLocation(){

  char* environment = getenv("HOME");
  char* rlg = "/rlg327/";
   //NOW HOME STRING HAS RLG327 APPENDED TO IT
  char* HOME = append(environment, rlg);

  return HOME; 
}
uint32_t  loadDungeon(room_t grid[21][80], uint32_t fileSize){

  //  char* smile = "/home/student/.rlg327/hello.rlg327";
   char* smile = "/home/student/.rlg327/dungeon";
   
  FILE* f = fopen(smile, "rb");


  char charArray[7]; 
  uint32_t version;
  uint32_t size; 
  uint8_t byte;
  uint8_t roomX;
  uint8_t xSize;
  uint8_t roomY;
  uint8_t ySize; 
  
  if(f){
    
    //     fseek(f, 0, SEEK_END);
    //   int  sz = ftell(f);
	 
    fread(charArray, 6, 1, f);
    printf("%s\n", charArray); 
    fread(&version,sizeof(version), 1,f);
    version = be32toh(version);
    printf("%d\n", version); 
    fread(&size, sizeof(size), 1, f);
 
    size = be32toh(size);
    fileSize = size;

    int i;
    int j; 
    for(i = 0; i < 21; i++){
      for(j = 0; j < 80; j++){
       fread(&byte, sizeof(byte), 1, f);
       rockValues[i][j] = byte;
       grid[i][j].hardness = byte; 
          if(byte == 0){
	    grid[i][j].display = '#'; 
          }else{
     	    grid[i][j].display = ' '; 
          }
      }
    }

    for(i = 1694; i < size; i+=4){
         fread(&roomX, sizeof(roomX), 1, f);
	 fread(&xSize, sizeof(xSize), 1, f);
	 fread(&roomY, sizeof(roomY), 1, f);
	 fread(&ySize, sizeof(ySize), 1, f);
	 others[spot][0] = roomX;
	 others[spot][1] = roomY;
	 others[spot][2] = xSize;
	 others[spot][3] = ySize;
	 spot++; 
	 placeRooms(roomX, xSize, roomY, ySize, grid); 
    }
    printGrid(grid); 
    
  }

  fclose(f);
  return fileSize; 
}

void placeRooms(uint8_t roomX, uint8_t xSize, uint8_t roomY, uint8_t ySize, room_t grid[21][80]){
  int i;
  int j;
  for(i = roomY; i < (roomY + ySize); i++){
    for(j = roomX; j < (roomX + xSize); j++){
      grid[i][j].display  = '.'; 
    }
  }
  
}

void saveDungeon(room_t grid[21][80], int dimensions[7][4], int mine){
  int i;
  int j;

    char* HOME =  getenv("HOME");
    HOME = append(HOME, "/.rlg327/dungeon");

   
    //  char* HOME = "/home/student/.rlg327/dungeon"; 
  FILE *file;
  file = fopen(HOME, "w");
  
  uint32_t version = 0;
    //I always have 7 rooms
    uint32_t size = 1694 + 28;
    //get the size of rooms
  char semantic[7]  = "RLG327";
  
  fwrite(semantic, 1, 6, file );
  version = htobe32(version); 
  fwrite(&version, 4, 1, file); //Needs to be manipulated write bytes in right order
  size = htobe32(size); 
  fwrite(&size, 4, 1, file);    //Also needs to be manipulated write bytes in right order


  // uint8_t max = 255; 
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      fwrite(&grid[i][j].hardness, 1, 1, file);
    }
  }

  // fwrite(dimensions, 1, 28, file);
  // if(mine){
    //USe my dimensions
    for(i = 0; i < 7; i++){
	uint8_t startX = dimensions[i][0];
	uint8_t startY = dimensions[i][1];
	uint8_t xSize = dimensions[i][2];
	uint8_t ySize = dimensions[i][3];
	fwrite(&startX, 1, 1, file);
	fwrite(&xSize, 1, 1, file);
	fwrite(&startY, 1, 1, file);
	fwrite(&ySize, 1, 1, file);
      
    }
  
  
  fclose(file); 
    
}
void loadAndSave(room_t grid[X][Y], char* HOME){

   uint32_t fileSize; 
   fileSize  = loadDungeon(grid, fileSize);
   
   int i, j; 

  FILE *file;
  file = fopen(HOME, "wb");
  
  uint32_t version = 0;
  uint32_t size = fileSize; 
  char semantic[6]  = "RLG327";
  
  
  fwrite(semantic, 1, 6, file );
  version = htobe32(version); 
  fwrite(&version, 4, 1, file); //Needs to be manipulated write bytes in right order
  size = htobe32(fileSize); 

  fwrite(&size, 4, 1, file);    //Also needs to be manipulated write bytes in right order
  size = fileSize; 

 
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
         fwrite(&grid[i][j].hardness, 1, 1, file);
    }
  }


  int init = 1694; 
    for(i = 1694; i < size; i++){
      //    fread(&startX, sizeof(startX), 1, f);
	uint8_t startX = others[i-1694][0];
	uint8_t startY = others[i-1694][1];
	uint8_t xSize = others[i-1694][2];
	uint8_t ySize = others[i-1694][3];

	fwrite(&startX, 1, 1, file);
	fwrite(&xSize, 1, 1, file);
	fwrite(&startY, 1, 1, file);
	fwrite(&ySize, 1, 1, file);
      
    }
 
  fclose(file); 
   
}

int checkEmpty( uint8_t saveGrid[sizeof(uint8_t)*21][sizeof(uint8_t)*80]){
  int i;
  int j;
  for(i = 0; i < 21; i++){
    for(j = 0; j < 80; j++){
      if(saveGrid[i][j] != 0){
	printf("%d\n", saveGrid[i][j]); 
      }
    }
  }
  return 1; 
}
void createDungeon(room_t roomGrid[X][Y]){
  // room_t roomGrid[X][Y]; 
  int* numbers;
  //This is an array which stores all the room connections
  int connections[7][2];
  int needsConnection[7];

  numbers = getRandoms();
  int i;

  fillRoomGrid(roomGrid); 
  while(rooms < 7){
    numbers = getRandoms();
    createRoom(numbers[0], numbers[1], numbers[2], numbers[3], roomGrid);
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
      
        connectRooms(i, nearestRoom, roomGrid);
      //If the rooms are connected already, find a different room that only has one connection
      }else {
          needsConnection[i] = i;
         nextClosest = nextClosestRoom( i, nearestRoom, connections);
      connectRooms(i, nextClosest, roomGrid);
    }
        if(i == rooms - 1){
           connectRooms(i, 0, roomGrid);      
        }
        else{
          connectRooms(i, i+1, roomGrid); 
         }   
  }
    printGrid(roomGrid); 
    printf("\n"); 
}

int main(int argc, char* argv[]){

  srand(time(NULL)); 
  room_t grid[21][80];
  uint32_t fileSize;

  printf("Main fileSize %d\n", fileSize); 
  
  if(argc == 1){
    printf("%s \n ", "Please provide either --save or --load switch"); 
  }
  if(argc ==  2){
    if(strcmp(argv[1], "--save") == 0){
      //Save a dungeon
      createDungeon(grid);
      
      saveDungeon(grid, dimensions, 1);
    }else if(strcmp(argv[1], "--load") == 0){
      //Load dungeon
      fileSize =  loadDungeon(grid, fileSize);
    }
  }
  if(argc == 3){
    //both switches, read dungeon from disk, display it, and rewrite
    //basically load first, then save
     char* HOME = getenv("HOME"); 
     HOME = append(HOME, "/.rlg327/smile.rlg327");
     
     loadAndSave(grid,HOME); 
  }

}

