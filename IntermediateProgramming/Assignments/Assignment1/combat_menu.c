#include <stdio.h>

int main() {
    //declear choice variables for main and sub menus
    int mainChoice, subChoice = 0;
    //nested while loop, since we want the play to decide when do stop
    //for loop doesn't sounds like a good choice for that due to the condition requirements.

    do
    {
        mainChoice = 0;
        printf("1. Attack\n2. Defend\n3. Use Item\n4. Exit\n> ");
        scanf("%d", &mainChoice);
        
        //enter Attack
        while(mainChoice == 1)
        {
            printf("1. Weapon Attack\n2. Magic Attack\n3. Back\n> ");
            scanf("%d", &subChoice);
            if(subChoice == 3)
            {
                break;
            }
            else
            {
                printf("Success!\n");
            }
            mainChoice = 0;
        }

        //enter Defense
        while(mainChoice == 2)
        {
            printf("Success!\n");
            break;
        }
        
        //enter Item
        while(mainChoice == 3)
        {
            printf("1. Potion\n2. Elixir\n3. Back\n> ");
            scanf("%d", &subChoice);
            if(subChoice == 3)
            {
                break;
            }
            else
            {
                printf("Success!\n");
            }
            mainChoice = 0;
        }
    } while (mainChoice != 4);
    return 0;
}
