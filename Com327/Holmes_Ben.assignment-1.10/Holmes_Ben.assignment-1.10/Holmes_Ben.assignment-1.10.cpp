#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <thread>

int gameOver = 0;
int gameTurns = 100;
char symbols[16][60];
int matches = 0;
int matchedArray[41];


class Card {
    public:
	    char symbol;
        int x, y;
        int matched;
        int pos;
	public:
	    void createCard(char, int);
        void setXY(int, int);
        void setMatch();
};

void Card::createCard(char sym, int num){
	symbol = sym;
    pos = num;
}

void Card::setXY(int xPos, int yPos){
    x = xPos;
    y = yPos;
}

void Card::setMatch(){
    matched = 1;
}


void printSymbol(int x, int y, Card card);
void printCardNum(int x, int y, int num);
void printHint(std::string message);


Card cards[40];
std::vector<Card> currentCards;


void printCard(int x, int y, Card card, int pos){


    int i;

    for(i = x; i < x+6; i++){
        attron(COLOR_PAIR(1));
        mvprintw(y, i, "%c", '-');
        mvprintw(y + 3, i, "%c", '-');
        attroff(COLOR_PAIR(1));
    }
    for(i = y+1; i < y+3; i++){
        attron(COLOR_PAIR(1));
        mvprintw(i, x, "%c", '|');
        mvprintw(i, x+5, "%c", '|');
        attroff(COLOR_PAIR(1));
    }

    card = cards[pos];
    printSymbol(x, y, card);


    printCardNum(x, y, card.pos);


}

void printSymbol(int x, int y, Card card){

    char symbol = cards[card.pos].symbol;
    int pointA = (x + x+6) /2;
    int pointB = (y+1 + y + 4)/ 2;

    attron(COLOR_PAIR(2));
    mvprintw(pointB,pointA, "%c", symbol);
    cards[card.pos].setXY(pointA, pointB);
    symbols[pointB][pointA] = symbol;
    attroff(COLOR_PAIR(2));
}

void printCardNum(int x, int y, int num){

    if(num > 9 && num < 36){
        num += 87;
        mvprintw(y+3,x, "%c", num);
    }else if(num >= 36){
        num += 29;
        mvprintw(y+3,x, "%c", num);
    }else{
        mvprintw(y+3,x, "%d", num);
    }
}

int getCardPos(int value){
    printHint("");
    if(value >= 48 && value <= 57){
        return value - 48;
    }
    else if(value >= 97 && value <= 122){
        return value - 87;
    }
    else if(value >= 65 && value <= 90){
        return value - 29;
    }
    else{
        printHint("The card value pressed is not correct.");
        refresh();
    }

    return -1;
}

char getSymbol(){
    char symbolArray[27] = {
            '!',
            '@',
            '#',
            '$',
            '%',
            '^',
            '&',
            '*',
            '(',
            ')',
            '_',
            '-',
            '+',
            '=',
            '~',
            '`',
            ',',
            ':',
            '{',
            '}',
            '[',
            ']',
            '|',
            '/',
            '?',
            '<',
            '>'
    };

    int ran = random() % 27;

    return symbolArray[ran];

}

int createMatch( int pos){

    matchedArray[pos] = 1;
    int found = 0;

    int ran;
    while(!found){
        ran = rand() % 20 + 20;
        if(!matchedArray[ran]){
            matchedArray[ran] = 1;
            found = 1;
        }
    }

    return ran;

}

void createBoard(int numCards){

	int i;
	for(i = 0; i < numCards/2; i++){
        Card card;
        Card twinCard;
        char symbol = getSymbol();
        int match = createMatch(i);
        twinCard.createCard(symbol, match);
        card.createCard(symbol, i);


        cards[card.pos] = card;
        cards[twinCard.pos] = twinCard;


	}

    int a = 0;
    int b = 0;
    for(i = 1; i <= 40; i++){
        printCard(a, b, cards[i-1], i-1);
        a += 7;
        if(i % 10 == 0 && i != 0){
            b += 4;
            a = 0;
        }
    }


}

void createHints(){

    int i, j;
    for(i = 71; i < 121; i++){
        mvprintw(0, i, "%c", '-');
        mvprintw(4, i, "%c", '-');
    }
    for(j = 1; j < 4; j++){
        mvprintw(j, 71, "%c", '|');
        mvprintw(j, 121, "%c", '|');
    }

    attron(COLOR_PAIR(1));
    mvprintw(1, 92, "%s", "Help Box");
    attroff(COLOR_PAIR(1));

}

void printHint(std::string message){

    mvprintw(2, 72, "- %-46s", message.c_str());
}
void printClock(){

}

void turnOverCards(){

    int i, j;
    for(i = 0; i < 16; i++){
        for(j = 0; j < 80; j++){
            if(symbols[i][j]){
                mvprintw(i, j, "%c", ' ');
            }
        }
    }
}

void showCard(int key){

    Card card = cards[key];
    char symbol = card.symbol;
    int x = cards[key].x;
    int y = cards[key].y;

    attron(COLOR_PAIR(2));
    mvprintw(y,x, "%c", symbol);
    attroff(COLOR_PAIR(2));

    currentCards.push_back(card);

}

void getCard(){

    int key = -1;

    while(key == -1) {
        key = getch();
        key = getCardPos(key);
    }

    showCard(key);
    refresh();
}

void flipCard(Card card){

    int x = card.x;
    int y = card.y;

    mvprintw(y, x, "%c", ' ');

}

void printTurns(int turns){
    mvprintw(3,72, "- Turns Left: %-3d", gameTurns);
    refresh();
}

void printMatches(int matches){
    mvprintw(5,72, "Matches: %d", matches);
    refresh();

}

void checkMatch(){
    Card card1 = cards[currentCards[0].pos];
    Card card2 = cards[currentCards[1].pos];
    gameTurns--;
    printTurns(gameTurns);

    if(card1.symbol != card2.symbol || card1.matched || card2.matched
       || card1.pos == card2.pos ){
        if(card1.matched && !card2.matched && currentCards[2].pos != card2.pos){
            flipCard(card2);
        }else if(card2.matched && !card1.matched && currentCards[2].pos != card1.pos){
            flipCard(card1);
        }else if(!card1.matched && !card2.matched){
            if(currentCards[2].pos == card1.pos){
                flipCard(card2);
            }else if(currentCards[2].pos == card2.pos){
                flipCard(card1);
            }else{
                    flipCard(card1);
                    flipCard(card2);

            }

        }
    }else if(card1.matched == 0 && card2.matched == 0
             && card1.symbol == card2.symbol
            && card1.pos != card2.pos){

        //Set matched values in cards vector
        cards[card1.pos].matched = 1;
        cards[card2.pos].matched = 1;
        matches++;
        printMatches(matches);
    }

    if(matches == 20){
        gameOver = 1;
    }

    currentCards.erase(currentCards.begin(), currentCards.begin()+2);
}


int main(int argc, char** argv)
{
    srand(time(NULL));
	initscr();
    noecho();
    curs_set(0);
	start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);


   	int width, height;

	createBoard( 40);
    createHints();

    printHint("You Have 5 seconds to memorize the cards");

    refresh();
    sleep(5);
    //getch();
    turnOverCards();
    printHint("Type card number on keypad to match");
    printMatches(matches);
    printTurns(gameTurns);
    refresh();


    int success = 0;

    while(!gameOver && gameTurns > 0){

    getCard();
        if(success){
            checkMatch();
        }
    getCard();

    refresh();
    success = 1;

    }
    clear();
    if(gameTurns > 0){
        mvprintw(10,80, "\n Congratulations, You Won in %d turns \n \n", 100 -gameTurns);
        refresh();
        sleep(2);
    }else{
        mvprintw(10,80, "\n Thanks For Playing! \n \n");
        refresh();
        sleep(2);
    }

    endwin();
    exit(0);

}
