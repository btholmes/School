#ifndef CHARACTER_H
# define CHARACTER_H

# include <stdlib.h>
# include <stdint.h>
# include <vector>
# include <ncurses.h> 

# include "dims.h"
# include "utils.h"

class dice;

class character {
 public:
  char symbol;
  pair_t position;
  int32_t speed;
  uint32_t alive;
  uint32_t sequence_number;

  uint32_t aColor; 
  int hp;
  const dice* damage;
  const char *name;
  std::vector<uint32_t> color;
 
    uint32_t get_color()
    {
       if(symbol == '@'){
	 return COLOR_BLUE;
       }
       return color[rand_range(0, color.size() - 1)]; 
    }
  char get_symbol() { return symbol; }
};

typedef struct dungeon dungeon_t;

int32_t compare_characters_by_next_turn(const void *character1,
                                        const void *character2);
uint32_t can_see(dungeon_t *d, pair_t voyeur, pair_t exhibitionist, int is_pc);
void character_delete(character *c);
int8_t *character_get_pos(character *c);
int8_t character_get_y(const character *c);
int8_t character_set_y(character *c, int8_t y);
int8_t character_get_x(const character *c);
int8_t character_set_x(character *c, int8_t x);
uint32_t character_get_next_turn(const character *c);
void character_die(character *c);
int character_is_alive(const character *c);
void character_next_turn(character *c);
void character_reset_turn(character *c);
char character_get_symbol(const character *c);
uint32_t character_get_speed(const character *c);

#endif
