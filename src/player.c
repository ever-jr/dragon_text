#include <ncurses.h>
#include "../include/entity.h"

Entity player;
WINDOW *player_stats;

void init_player() {
    player = entity_new("PLAYER", 20);
}
