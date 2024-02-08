#include <ncurses.h>
#include "entity.h"

Entity entity_new(char name[], int health) {
    Entity e;
    e.name = name;
    e.health = health;
    e.max_health = health;

    return e;
}

void entity_stats(Entity entity) {
    const char line[] = "+-----------------";
    printw(
        "%s\n| name: %s\n| health: %d/%d\n%s\n",
        line,
        entity.name,
        entity.health,
        entity.max_health,
        line
    );
}

void entity_set_damage(Entity *entity, int damage) {
    entity->health -= damage;
}
