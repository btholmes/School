# include <string> 

# include "descriptions.h" 
# include "dungeon.h"
# include "dice.h"




class monster_info {
	private: 
	std::string color; 
	std::string name; 
	std::string description; 
	char symbol; 
	std::string  abilities; 
	std::string  damage; 
	std::string  hitpoints; 
	std::string  speed; 

	public:
        monster_info(std::string &color, std::string &name,
		     std::string &description, char symbol,
		     std::string &abilities, std::string &damage,
		     std::string &hitpoints, std::string &speed){

	  this->color = color;
	  this->name = name;
	  this->description = description;
	  this->symbol = symbol;
	  this->abilities = abilities;
	  this->damage = damage;
	  this->hitpoints = hitpoints;
	  this->speed = speed; 
	  
	}

	std::string &get_color() {return color; }
	std::string &get_name() {return name; }
	std::string &get_description() {return description; }
	char get_symbol() {return symbol; }
	std::string &get_abilities() {return abilities; }
	std::string &get_damage() {return damage; }
	std::string &get_hitpoints()  {return hitpoints; }
	std::string &get_speed() {return speed; }

}







void monster_info::set_color(std::vector<int> &color){
	this->color = color; 
}

void monster_info::set_name(std::string &name){
	this->name = name; 
}
void monster_info::set_description(std::string &description){
	this->description = description; 
}
void monster_info::set_symbol(char symbol){
	this->symbol = symbol; 
}
void monster_info::set_abilities(int abilities){
	this->abilities = abilities; 
}
void monster_info::set_hitpoints(dice &hitpoints){
	this->hitpoints = hitpoints; 
}
void monster_info::set_damage(dice &damage){
	this->damage = damage; 
}
void monster_info::set_speed(dice &speed){
	this->speed = speed; 
}



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

  *color = *line;
  return true; 

}
bool parseSpeed(std::string *identifier, std::string *line,  std::string *speed, std::ifstream &fileRead ){

  *speed = *line; 
  return true; 
}
bool parseAbil(std::string *identifier, std::string *line,  std::string *ability, std::ifstream &fileRead ){

  *ability = *line; 

  return true; 
}
bool parseHp(std::string *identifier, std::string *line,  std::string *hitpoints, std::ifstream &fileRead ){

  *hitpoints = *line; 
  return true; 
}
bool parseDam(std::string *identifier, std::string *line,  std::string *damage, std::ifstream &fileRead ){

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

  std::string color, name, description, abilities, damage, hitpoints,
    speed;
  char symbol; 

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

     if(identifier == "SPEED" && beginMonster && parseSpeed(&identifier, &line, &speed, fileRead) ){

       
       seeSpeed  = true;
       fields++;
       continue; 
     }
     else if(identifier == "SPEED" &&( !beginMonster || seeSpeed || !parseSpeed(&identifier, &line, &speed, fileRead))){

        std::cout << "Error parsing speed \n"; 
       return 0; 
     }

      if(identifier == "DAM" && beginMonster && parseDam(&identifier, &line, &damage, fileRead) ){

        
       seeDamage  = true;
       fields++;
       continue; 
     }
     else if(identifier == "DAM" &&( !beginMonster || seeDamage || !parseDam(&identifier, &line, &damage, fileRead))){

        std::cout << "Error parsing damage \n"; 
       return 0; 
     }

     if(identifier == "HP" && beginMonster && parseHp(&identifier, &line, &hitpoints, fileRead) ){

      
       seeHp  = true;
       fields++;
       continue; 
     }
     else if(identifier == "HP" &&( !beginMonster || seeHp || !parseHp(&identifier, &line, &hitpoints, fileRead))){

        std::cout << "Error parsing hitpoints \n"; 
       return 0; 
     }

     if(identifier == "ABIL" && beginMonster && parseAbil(&identifier, &line, &abilities, fileRead)){
       
       seeAbilities  = true;
       fields++;
       continue; 
     }
     else if(identifier == "ABIL" &&(!beginMonster || seeAbilities ||  !parseAbil(&identifier, &line, &abilities, fileRead))){

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

       continue; 
       
     }
     else if(identifier == "END" && fields != 8){
       std::cout << "Reached end before getting all fields \n";
       return 0; 
     }
     
     
		
   }

   return 1; 
  
}




int parse_monster_info(dungeon_t *d){
	std::string file; 
	std::ifstream fileRead; 
	
	file = getenv("HOME"); 
	file += std::string("/") + ".rlg327" + "/" + "monster_desc.txt"; 

	fileRead.open(file.c_str()); 
	
	read_descriptions(fileRead); 

	fileRead.close();
	return 1; 
}




























