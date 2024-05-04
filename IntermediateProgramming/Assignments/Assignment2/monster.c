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
    printf("Name: %s\n", monster.name);
    printf("Type: %s\n", monster.type);
    printf("HP: %d\n", monster.hp);
    printf("Level: %d\n", monster.level);
}
void save_monster(struct Monster monster, FILE *stream)
{
    fwrite(&monster, sizeof(struct Monster), 1, stream);
    if(fwrite != 0)
    {
        printf("\nContents to file written successfully !\n");
    }
    else
    {
        printf("error writing file !\n");
    }
}


void print_monsters(struct Monster monsters[STRUCT_SIZE], int element)
{
   printf("Name\tType\t\tHP\tLevel\n");
    printf("--------------------------------------\n");
    for(int i = 0; i < element - 1 ; i++)
    {
        printf("%s \t%-9s \t%d \t%d\n",monsters[i].name, monsters[i].type, monsters[i].hp, monsters[i].level);

    }
}

struct Monster load_monster(FILE *stream)
{
    struct Monster monster;
    fread(&monster, sizeof(struct Monster), 1, stream);
    return monster;
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
//=============================================
    stream = fopen("monsters.dat", "rb");
    int element = 0;
    struct Monster monsters[STRUCT_SIZE+1];
     while (!feof(stream)) 
    {
        monsters[element] = load_monster(stream);
        element++;
    }
    print_monsters(monsters, element);
    fclose(stream);
    return 0;
}