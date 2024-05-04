#include "monster.h"

struct Monster create_monster() {
    struct Monster monster;
    printf("Enter monster name: ");
    scanf("%s", monster.name);
  
    printf("Enter monster type: ");
    scanf("%s", monster.type);
  
    printf("Enter monster HP: ");
    scanf("%d", &monster.hp);
  
    printf("Enter monster level: ");
    scanf("%d", &monster.level);
  
    return monster;
}
void print_monster(struct Monster monster)
{
    printf("Name: %s\n",monster.name);
    printf("Type: %s\n",monster.type);
    printf("HP: %d\n", monster.hp);
    printf("Level: %d\n", monster.level);
}
int main()
{
    struct Monster monster = create_monster();
    print_monster(monster);
    
    return 0;
}