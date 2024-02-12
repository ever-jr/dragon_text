#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    char *name;
    int max_health;
    int health;
} Entity;

Entity entity_new(char name[], int health);
void entity_stats(Entity entity); 
void entity_set_damage(Entity *entity, int damage);

#endif
