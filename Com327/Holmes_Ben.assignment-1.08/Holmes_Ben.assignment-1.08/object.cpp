#include <vector>
#include <cstring>
#include <ncurses.h> 

#include "object.h"
#include "dungeon.h"
#include "utils.h"

object::object(const object_description &objectDesc, pair_t place) :

  hit(objectDesc.get_hit().roll()),
  dodge(objectDesc.get_dodge().roll()),
  value(objectDesc.get_value().roll()),
  weight(objectDesc.get_weight().roll()),
  speed(objectDesc.get_speed().roll()),
  defense(objectDesc.get_defence().roll()),
  attribute(objectDesc.get_attribute().roll()),
  isVisible(0),
  
  description(objectDesc.get_description()),
  name(objectDesc.get_name()),
  type(objectDesc.get_type()),
  color(objectDesc.get_color()),
  damage(objectDesc.get_damage())
{
  position[dim_x] = place[dim_x];
  position[dim_y] = place[dim_y];
}


void make_the_weapons(dungeon_t *d)
{
  int i;
  int num = d->max_objects;
  //  uint32_t num = 100; 

  memset(d->objectMap, 0, sizeof (d->objectMap));

  d->num_objects = num;
  for (i = 0; i < num; i++) {
    
    uint32_t room;
    pair_t place;
    int y, x; 
    const std::vector<object_description> descVector = d->object_descriptions;
    const object_description description = descVector[rand_range(0, descVector.size() - 1)];

    room = rand_range(0, d->num_rooms - 1);
    y = rand_range(d->rooms[room].position[dim_y],
			  (d->rooms[room].position[dim_y] +
			   d->rooms[room].size[dim_y] - 1));
    x = rand_range(d->rooms[room].position[dim_x],
			  (d->rooms[room].position[dim_x] +
			   d->rooms[room].size[dim_x] - 1));

    place[dim_y] = y;
    place[dim_x] = x;
    
    object *objectThing;
    objectThing = new object(description, place);

    d->objectMap[y][x] = objectThing;
  }
}

char object::get_symbol()
{
  if(type == objtype_no_type){
    return '*'; 
  }else if(type == objtype_WEAPON){
    return '|'; 
  }
    else if(type == objtype_LIGHT){
    return '~'; 
  }
    else if(type == objtype_ARMOR){
    return '['; 
  }
    else if(type == objtype_HELMET){
    return ']'; 
  }
    else if(type == objtype_CLOAK){
    return '('; 
  }
    else if(type == objtype_GLOVES){
    return '{'; 
  }
    else if(type == objtype_BOOTS){
    return '\\'; 
  }
   else if(type == objtype_BOOK){
    return '?'; 
  }
    else if(type == objtype_AMULET){
    return '"'; 
  }
    else if(type == objtype_RING){
    return '='; 
  }
   else if(type == objtype_SCROLL){
    return '`'; 
  }
   else if(type == objtype_AMMUNITION){
    return '/'; 
  }
   else if(type == objtype_GOLD){
    return '!'; 
  }
   else if(type == objtype_FLASK){
    return '}'; 
  }
    else if(type == objtype_OFFHAND){
    return ')'; 
  }
    else if(type == objtype_RANGED){
    return '}'; 
  }
   else if(type == objtype_CONTAINER){
    return '%'; 
  }
   else if(type == objtype_WAND){
    return '-'; 
  }
   else if(type == objtype_FOOD){
    return ','; 
  }

  return '+'; 
  
}

int object::get_type()
{
  return type;
}
int object::roll_damage_dice()
{
  return damage.roll();
}
int object::get_speed()
{
  return speed;
}

uint32_t object::get_color()
{
  return color;
}

const char *object::get_name()
{
  return name.c_str();
}








