#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <vector> 


std::vector<Card> cards; 

class Board {
    int width, height, cards;
  public:
    void createBoard (int x,int y, int c);
};

void Board::createBoard (int x, int y, int c) {
  width = x;
  height = y;
  cards = c; 
}


class Card {
	
	char symbol; 
	public: 
	void createCard(char); 
}; 

void Card::createCard(char sym){
	symbol = sym; 
}

void printCard(int x, int y){
	
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));

	mvprintw(y, x, "%c", symbol);
	attroff(COLOR_PAIR(1));

}

void printChar(int x, int y, char symbol){
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));

	mvprintw(y, x, "%c", symbol);
	attroff(COLOR_PAIR(1));
}

void createBoard(int x, int y, int cards){
	
	
	
	int i;
	int j = 0;  
	for(i = 0; i < cards; i++){
		printCard(j, i); 
		j += 5; 
	}


	

	refresh(); 
	getch(); 

}


int main(int argc, char** argv)
{
	initscr();			
	start_color();			
		
   	int width, height, cards; 

	createBoard(40, 20, 20); 

}
