# include <string>
# include <ncurses.h> 

# include <stdlib.h> //for getenv
# include <iostream>
# include <fstream> // for std::ifstream
# include <vector> 

//using namespace st


class dice{
	private: 
  int base;
  int number;
  int sides;
	  
	public:
  dice() : base(0), number(0), sides(0)
  {
  }
  dice(int base, int number, int sides) :
    base(base), number(number), sides(sides)
  {
  }

    void setDice(int base, int number, int sides)
	{
		this->base = base; 
		this->number = number; 
		this->sides = sides; 
	}
	int getBase(){
		return base; 
	}
	int getSides(){
		return sides; 
	}
	int getNumber(){
		return number; 
	}
};




class monster_info {
	private: 
        int color; 
	std::string name; 
	std::string description; 
	char symbol; 
        std::vector<int>  abilities; 
	dice  damage; 
	dice  hitpoints; 
	dice  speed; 

	public:
  monster_info() : color(), name(), description(), symbol(), abilities(), damage(), hitpoints(), speed()
  {
  }
  
  void setMonster(int color, std::string name,
		     std::string description, char symbol,
		     std::vector<int> &abilities, dice &damage,
		     dice &hitpoints, dice &speed){

	  this->color = color;
	  this->name = name;
	  this->description = description;
	  this->symbol = symbol;
	  this->abilities = abilities;
	  this->damage = damage;
	  this->hitpoints = hitpoints;
	  this->speed = speed; 
	  
	}

	int get_color() {return color; }
	std::string get_name() {return name; }
	std::string get_description() {return description; }
	char get_symbol() {return symbol; }
        std::vector<int> &get_abilities() {return abilities; }
	dice &get_damage() {return damage; }
	dice &get_hitpoints()  {return hitpoints; }
	dice &get_speed() {return speed; }
    

}; 


class splitstring : public std::string {
  std::vector<std::string> flds;
public:
  splitstring(char *s) : std::string(s) { };
  std::vector<std::string>& split(char delim, int rep=0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
std::vector<std::string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    std::string work = data();
    std::string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}



std::vector<int> colorsVector;
std::vector<monster_info> monstersVector; 


std::string trim(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;

    return std::string(it, rit.base());
}

void ignoreBlankSpace(std::ifstream &fileRead){

  bool found = false; 
  while (!found) {
    if(isblank(fileRead.peek())){
      fileRead.get();
    }   
    else{
      found = true; 
      break; 
    }
  }  
}
bool parseSymbol(std::string *identifier, std::string *line,  char *symbol, std::ifstream &fileRead ){

  std::string item = ""; 
  *symbol = line->at(0); 

  // std::cout << "in symbol " + item << *symbol <<  + "\n"; 
  return true; 
  
}

bool parseDesc(std::string *identifier, std::string *line,  std::string *description, std::ifstream &fileRead ){
  

  getline(fileRead, *line);
   *description += *line + "\n";
  
  while(!fileRead.eof()){
     getline(fileRead, *line); 

     //   std::cout <<"description at top of while is " + *description + "\n"; 
      *line = trim(*line);
      // std::cout << "line in descript while is " + *line + "\n"; 
      if(*line == "."){
	//	std::cout << "Found lone period"; 
	break; 
      }
      
      *description += *line + "\n" ;
      if(line->length() > 77){
        printf("%d \n", description->length()); 
	//	std::cout << "too much length \n"; 
	return false; 
      }
  }

  description->erase(description->length()-1); 
  
  if(*line != "."){
    //  std::cout << "in last if \n"; 
    return false; 
   }
  

  return true; 

}
bool parseColor(std::string *identifier, std::string *line,  std::string *color, std::ifstream &fileRead ){
//********NCURSES COLORS
  //COLOR_BLACK
  //COLOR_BLUE
  //COLOR_GREEN
  //COLOR_CYAN
  //COLOR_RED
  //COLOR_MAGENTA
  //COLOR_YELLOW
  //COLOR_WHITE

  int monsterColor; 
  bool found = false; 
  
  // std::cout << "In parse color color is " + *line + "\n"; 

  if(*line == "BLACK"){
    monsterColor = COLOR_BLACK; 
    found = true; 
  }
  else if(*line == "WHITE"){
    monsterColor = COLOR_WHITE;
    found = true; 
  }
  else if(*line == "BLUE"){
    monsterColor = COLOR_BLUE;
    found = true; 
  }
  else if(*line == "GREEN"){
    monsterColor = COLOR_GREEN;
    found = true; 
  }
  else if(*line == "RED"){
    monsterColor = COLOR_RED;
    found = true; 
  }
  else if(*line == "CYAN"){
    monsterColor = COLOR_CYAN;
    found = true; 
  }
  else if(*line == "YELLOW"){
    monsterColor = COLOR_YELLOW;
    found = true; 
  }
  else if(*line == "MAGENTA"){
    monsterColor = COLOR_MAGENTA; 
    found = true; 
  }
 
  if(found){
     colorsVector.push_back(monsterColor); 
  }else{
    return false; 
  }
  
  *color = *line;
  return true; 

}
bool parseSpeed(std::string *identifier, std::string *line,  std::string *speed, std::ifstream &fileRead, dice *d ){

  int base, number, sides;

  if(sscanf(line->c_str(), "%d+%ud%u", &base, &number, &sides) != 3) {
    return false;
  }

  d->setDice(base, number, sides); 
  
  *speed = *line; 
  return true; 
}
bool parseAbil(std::string *identifier, std::string *line,  std::string *ability, std::ifstream &fileRead, std::vector<int>* monsterAbil ){

  //Abilites are defined as
  // 0 = SMART
  // 1 = TELE
  // 2 = TUNNEL
  // 3 = ERRATIC
  // 4 = PASS
  bool found = false; 
  splitstring s((char*)line->c_str());
  
  std::vector<std::string> flds = s.split(' ');
  for (int i = 0; i < flds.size(); i++){
    // std::cout << "Fields are " +  flds[i] + "\n";
    found = false;
    
    if(flds[i] == "SMART"){
      found = true;
      monsterAbil->push_back(0); 
    }
    else if(flds[i] == "TELE"){
      found = true;
      monsterAbil->push_back(1); 
    }
    else if(flds[i] == "TUNNEL"){
      found = true;
      monsterAbil->push_back(2); 
    }
    else if(flds[i] == "ERRATIC"){
      found = true;
      monsterAbil->push_back(3); 
    }
    else if(flds[i] == "PASS"){
      found = true;
      monsterAbil->push_back(4); 
    }
    if(!found){
      return false; 
    }

  }
      
   *ability = *line; 
   return true; 

}
bool parseHp(std::string *identifier, std::string *line,  std::string *hitpoints, std::ifstream &fileRead , dice* d){

  int base, number, sides;

  if(sscanf(line->c_str(), "%d+%ud%u", &base, &number, &sides) != 3) {
    return false;
  }

  d->setDice(base, number, sides); 
  
  *hitpoints = *line; 
  return true; 
}
bool parseDam(std::string *identifier, std::string *line,  std::string *damage, std::ifstream &fileRead, dice *d ){

   int base, number, sides;

  if(sscanf(line->c_str(), "%d+%ud%u", &base, &number, &sides) != 3) {
    return false;
  }

  d->setDice(base, number, sides); 
  
  *damage = *line;
  return true; 
}

bool parseName(std::string *identifier, std::string *line,  std::string *name, std::ifstream &fileRead ){

  *name = *line;  

  return true; 
  
}

int read_descriptions(std::ifstream& fileRead){

  bool metaData, beginMonster, seeName, seeSymbol,seeColor, seeDescription,
    seeSpeed, seeDamage, seeHp, seeAbilities, endMonster, readingDesc, firstMonster;

  std::string color, name, description, abilities, damage, speed, hitpoints; 
  char symbol;
  std::vector<int> abilityValue; 
  dice hpDice, speedDice, damageDice;
  monster_info monsterStuff; 

  int fields = 0; 

  metaData = beginMonster = seeName = seeSymbol = seeColor = seeDescription =
    seeSpeed = seeDamage = seeHp = seeAbilities = endMonster =
    readingDesc = firstMonster = false; 
  
  std::string line = ""; 
  getline(fileRead, line); 

  line = trim(line);
  // std::cout << "new line is " + line + "\n"; 
	
  if(trim(line) != "RLG327 MONSTER DESCRIPTION 1"){
     std::cout << "File should start with RLG327 MONSTER.. \n "; 
      	return 0; 
  }else{
    metaData = true; 
  }

 
  
  while(!fileRead.eof()){

  std::string identifier;
  fileRead  >> identifier;
  identifier = trim(identifier);

  ignoreBlankSpace(fileRead);
  //Get line ends at \n so I have to use get() until something that isn't a blank space is encountered
  if(fileRead.peek() == '\n' && identifier != "DESC" && identifier != "END"){
    std::cout << "Found a new line in a bad place \n";
    return 0; 
  }

  std::getline(fileRead, line); 
  line = trim(line);
     
  // std::cout << "line is " + line + "\n";
  //std::cout << "identifier is " + identifier + "\n"; 
     
     if(line == "RLG327 MONSTER DESCRIPTION 1" && metaData){
       std::cout << "RLG327 was read more than once \n";
       return 0; 
     }

     if(identifier + " " + line  == "BEGIN MONSTER"){

       //   std::cout << "in begin monster \n";
       
       if(firstMonster){
	 std::cout << "\n"; 
       }else{
	 firstMonster = true; 
       }
       
       metaData = beginMonster = seeName = seeSymbol = seeColor = seeDescription =
	 seeSpeed = seeDamage = seeHp = seeAbilities = endMonster =
	 readingDesc = false;

       color = name = description = abilities = damage = hitpoints = speed = ""; 
       symbol = ' ';
       abilityValue.clear();   
       // hpDice = speedDice = damageDice = NULL;
       // monsterStuff = NULL; 

       fields = 0; 

       
       beginMonster = true;
        continue; 
     }

     if(identifier == "NAME" && beginMonster && parseName(&identifier, &line, &name, fileRead )){
       
       seeName = true;
       fields++;
       continue; 
     }
     else if(identifier == "NAME" && (!beginMonster || seeName || !parseName(&identifier, &line, &name, fileRead )))
     {
       //    std::cout << "line in read is " << std::boolalpha << !beginMonster <<  "\n";
       // std::cout << "identifier in read is "<<std::boolalpha<< seeName << "\n";
       
       std::cout << "Error parsing Name \n";
       return 0; 
     }

     if(identifier == "SYMB" && beginMonster && parseSymbol(&identifier, &line, &symbol, fileRead)){
	 // symbol = line;
       //   std::string item = ""; 
       //  
       seeSymbol = true;
       fields++;
       continue; 
     }
     else if(identifier == "SYMB" &&(!beginMonster || seeSymbol || ! parseSymbol(&identifier, &line, &symbol, fileRead))){

       std::cout << "Error parsing symbol \n";
       return 0; 
     }

     if(identifier == "COLOR" && beginMonster && parseColor(&identifier, &line, &color, fileRead)){
       //  color = line;
      
       seeColor = true;
       fields++;
       continue; 
     }
     else if(identifier == "COLOR" &&(!beginMonster || seeColor || ! parseColor(&identifier, &line, &color, fileRead))){

       std::cout << "Error parsing color \n"; 
       return 0; 
     }

     if(identifier == "DESC" && beginMonster && parseDesc(&identifier, &line, &description, fileRead)){
       
       seeDescription  = true;
       fields++;
       continue; 
     }
     else if(identifier == "DESC" &&(!beginMonster || seeDescription || ! parseDesc(&identifier, &line, &description, fileRead))){

       std::cout << "Error parsing description \n"; 
       return 0; 
       
     }

     if(identifier == "SPEED" && beginMonster && parseSpeed(&identifier, &line, &speed, fileRead, &speedDice) ){

       
       seeSpeed  = true;
       fields++;
       continue; 
     }
     else if(identifier == "SPEED" &&( !beginMonster || seeSpeed || !parseSpeed(&identifier, &line, &speed, fileRead, &speedDice))){

        std::cout << "Error parsing speed \n"; 
       return 0; 
     }

     if(identifier == "DAM" && beginMonster && parseDam(&identifier, &line, &damage, fileRead, &damageDice) ){

        
       seeDamage  = true;
       fields++;
       continue; 
     }
     else if(identifier == "DAM" &&( !beginMonster || seeDamage || !parseDam(&identifier, &line, &damage, fileRead, &damageDice))){

        std::cout << "Error parsing damage \n"; 
       return 0; 
     }

      if(identifier == "HP" && beginMonster && parseHp(&identifier, &line, &hitpoints, fileRead,&hpDice ) ){

      
       seeHp  = true;
       fields++;
       continue; 
     }
      else if(identifier == "HP" &&( !beginMonster || seeHp || !parseHp(&identifier, &line, &hitpoints, fileRead, &hpDice))){

        std::cout << "Error parsing hitpoints \n"; 
       return 0; 
     }

      if(identifier == "ABIL" && beginMonster && parseAbil(&identifier, &line, &abilities, fileRead, &abilityValue)){
       
       seeAbilities  = true;
       fields++;
       continue; 
     }
      else if(identifier == "ABIL" &&(!beginMonster || seeAbilities ||  !parseAbil(&identifier, &line, &abilities, fileRead, &abilityValue))){

       std::cout << "Error parsing abilities \n"; 
       return 0; 
     }

     if(identifier == "END" && fields == 8){

       std::string item = ""; 
       std::cout <<  name + "\n";
       std::cout <<  description + "\n";
       std::cout <<  item << symbol << "\n";
       std::cout <<  color + "\n"; 
       std::cout <<  speed  + "\n"; 
       std::cout <<  abilities  + "\n"; 
       std::cout <<  hitpoints  + "\n";
       std::cout <<  damage  + "\n";

       //  printf("Color is %d\n", COLOR_CYAN);

       //         void setMonster(int color, std::string &name,
       //		     std::string &description, char symbol,
       //		     std::vector<int> &abilities, dice &damage,
       //		     dice &hitpoints, dice &speed){
       int currentColor = colorsVector[colorsVector.size() -1]; 
       
       monsterStuff.setMonster(currentColor, name, description, symbol, abilityValue, damageDice, hpDice, speedDice );
       monstersVector.push_back(monsterStuff); 
       continue; 
       
     }
     else if(identifier == "END" && fields != 8){
       std::cout << "Reached end before getting all fields \n";
       return 0; 
     }    
		
   }

   return 1; 
  
}

int main(int, char*[]){
  

  std::string file; 
  std::ifstream fileRead; 
	
  file = getenv("HOME"); 
  file += std::string("/") + ".rlg327" + "/" + "monster_desc.txt";

  fileRead.open(file.c_str()); 
	
  int readCorrect = read_descriptions(fileRead);

  
  //  monster_info myMonster = monstersVector[0];
  // std::string myName = myMonster.get_name();
  // std::string myDesc = myMonster.get_description();
  // char mySymbol = myMonster.get_symbol();
  // int myColor = myMonster.get_color();
  // std::vector<int> myAbil = myMonster.get_abilities();
  // dice myDamage = myMonster.get_damage();
  // dice myHp = myMonster.get_hitpoints();
  // dice mySpeed = myMonster.get_speed(); 
  
  // std::cout << "Monster name is " + myName + "\n";
  //std::cout << "Monster desc is " + myDesc + "\n";
  // printf("Symbol is %c \n", mySymbol);
  //printf("Color is %d \n", myColor);
  //printf("Abil at 1 is %d \n",  myAbil[0]);
  //printf("My damage is %d, %d, %d\n", myDamage.getBase(), myDamage.getSides(), myDamage.getNumber());
  //printf("My hp is %d, %d, %d \n", myHp.getBase(), myHp.getSides(), myHp.getNumber());
  //printf("My speed is %d, %d, %d\n", mySpeed.getBase(), mySpeed.getSides(), mySpeed.getNumber()); 
  

  
  
  fileRead.close();
  return 0; 
}


	
	



  
