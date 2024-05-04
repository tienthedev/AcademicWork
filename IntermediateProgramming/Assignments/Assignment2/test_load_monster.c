#include "monster.h"

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
//=============================================
    FILE *stream = fopen("monsters.dat", "rb");
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