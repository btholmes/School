#ifndef OBJECT_H
# define OBJECT_H

# include <string>

# include "descriptions.h"
# include "dims.h"

class object {
 private:
  int hit, dodge, value, weight, speed, defense, attribute;
  int isVisible; 
  const std::string &description;
  const std::string &name;
  object_type_t type;
  uint32_t color;
  pair_t position;
  const dice &damage;

 public:
  object(const object_description &objectDesc, pair_t p);
  inline int get_damage_base() const
  {
    return damage.get_base();
  }
  inline int get_damage_number() const
  {
    return damage.get_number();
  }
  inline int get_damage_sides() const
  {
    return damage.get_sides();
  }
  char get_symbol();
  int get_type();
  int roll_damage_dice();
  int get_speed();
  uint32_t get_color();
  const char* get_name();
   
  
  int visible() { return isVisible; }
  void saw_object() { isVisible = 1; }
};

void make_the_weapons(dungeon_t* d);

#endif

