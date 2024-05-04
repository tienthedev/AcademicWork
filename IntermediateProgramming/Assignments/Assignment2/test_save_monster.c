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
void save_monster(struct Monster monster, FILE *stream)
{
    fwrite(&monster, sizeof(struct Monster), 1, stream);
    if(fwrite != 0)
    {
        printf("contents to file written successfully !\n");
    }
    else
    {
        printf("error writing file !\n");
    }
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
    FILE *stream = fopen("monsters.dat", "ab+");
    if(stream == NULL)  
    {
        printf("Cannot open file.");
        return 1;
    }
    struct Monster monster = create_monster();
    print_monster(monster);
    save_monster(monster,stream);
    fclose(stream);
    return 0;
}