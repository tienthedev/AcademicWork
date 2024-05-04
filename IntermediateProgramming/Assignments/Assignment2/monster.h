#include <stdio.h>
#include <string.h>
#define STRUCT_SIZE 128
struct Monster
{
    char name[32];
    char type[16];
    int hp;
    int level;

} monster;
struct Monster load_monster(FILE *stream);
void save_monster(struct Monster monster, FILE *stream);
void print_monster(struct Monster monster);
void print_monsters(struct Monster monsters[129], int element);
struct Monster create_monster();





