//Student TIEN DUNG LE
//ID 100202497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int depth_first_search(int **adjmatrix,int index,int *res);
int depth_first_visit(int ** adjmatrix,int vertex, int *color, int *pred,int index,int *res,int *position);

int main()
{
    char filename[30] = "";
    char coursename[30] = "";
    char c;
    char fileline[1000] = "";
    char courses[50][30] = {0};
    char *token = NULL;
    char tempstring[1000] = "";
    printf("This program will read, from a file, a list of courses and their \nprerequisites and will print the list in which to take courses.\n");
    printf("Enter filename: ");
    scanf("%s%c",filename,&c);
    int index = 0;
    FILE *file = fopen(filename,"r");
    if(file == NULL)
    {
        printf("Could not open file badName. Exit\n");
        printf("\nFailed to read from file. Program will terminate.\n");
        return 0;
    }
   
    while(fgets(fileline,sizeof(fileline)-1,file))
    {
        strcpy(tempstring,fileline);
        token = strtok(tempstring," \n");//Only accounting for LF
        strcpy(courses[index],token);
        index++;
    }
    printf("Number of vertices in built graph: N = %d\n",index);
    printf("Vertex - course name correspondence\n");
    for(int a = 0; a < index; a++)
    {
        printf("%d - %s\n",a,courses[a]);
    }
    int **adjgraph = malloc(index * sizeof(int*));
    for(int b = 0; b < index; b++)
    {
        
        adjgraph[b] = malloc(index * sizeof(int));
        for(int a = 0; a < index; a++)
        {
            adjgraph[b][a] = 0;
        }
        
    }

    rewind(file);
    int column = 0;
    while(fgets(fileline,sizeof(fileline)-1,file))
    {
        fileline[strlen(fileline)-1] = '\0';
        token = strtok(fileline," ");

        while(token != NULL)
        {
            token = strtok(NULL," \n");
            if(token != NULL)
            {
                if(token[strlen(token)-1] == '\n')
                {
                    token[strlen(token)-1] = '\0';
                }
                for(int a = 0; a < index; a++)
                {
                    if(strncmp(courses[a],token,strlen(token)) == 0)
                    {
                        adjgraph[a][column] = 1;
                    }
                    
                }
            }
        }
        column++;
    }
    fclose(file);
    printf("\nAdjacency matrix:\n");
    for(int a = 0; a < index; a++)
    {
        if(a == 0)
        {
            printf("    |   %d",a);

        }
        else
        {
            if(a >= 10)
            printf("  %d",a);
            else
            printf("   %d",a);
        }
    }
    printf("\n");

    for(int a = 0; a <= index; a++)
    {
        if(a == 0)
        printf("-----");
        else
        printf("----");
    }
    printf("\n");

    for(int a = 0; a < index;a++)
    {
        for(int b = 0; b < index; b++)
        {
            if(b == 0)
            {
                if(a >= 10)
                printf("  %d|   %d",a,adjgraph[a][b]);
                else
                printf("   %d|   %d",a,adjgraph[a][b]);
            }
            else
            {
                printf("   %d", adjgraph[a][b]);
            }
        }  
        printf("\n");
    }
    int *res = malloc(index * sizeof(int));
    int *topsorted = malloc(index *sizeof(int));
    for(int a = 0; a < index; a++)
    {
        res[a] = 0;
    }

    int cyclecheck = depth_first_search(adjgraph,index,res);
    for(int a = 0,b = (index - 1);a < index;a++)
    {
        topsorted[a] = res[b];
        b--;
    }

    if( cyclecheck == -1)
    {
        printf("\nThere was at least one cycle. There is no possible ordering of the courses.\n\n");
    }
    else
    {
        printf("\nOrder in which to take courses:\n");
        for(int a = 0; a < index; a++)
        {
            printf("%d. - %s (corresponds to graph vertex %d)\n",(a+1),courses[topsorted[a]],topsorted[a]);
        }
        printf("\n");

    }
    free(res);
    free(topsorted);
    for(int a = 0; a < index; a++)
    {
        free(adjgraph[a]);
    }
    free(adjgraph);
}

int depth_first_search(int **adjmatrix,int index,int *res)
{
    int *color = malloc(index * sizeof(int));
    int *pred = malloc(index * sizeof(int));
    int position = 0;
    for(int a = 0; a < index; a++)
    {
        color[a] = 0;
        pred[a] = -1;
    }
    for(int u = 0; u < index;u++)
    {
        if(color[u] == 0) //0 for white, 1 for gray, and 2 for black
        {
            if(!(depth_first_visit(adjmatrix,u,color,pred,index,res,&position)))
            {
                free(color);
                free(pred);
                return -1;
            }
        }
    }
    free(color);
    free(pred);
    return 1;
}

int depth_first_visit(int ** adjmatrix,int vertex, int *color, int *pred,int index,int *res,int *position)
{
    color[vertex] = 1;
    for(int i = 0; i < index; i++)
    {
        if(adjmatrix[vertex][i] == 1)
        {
            if(color[i] == 0)
            {
                pred[i] = vertex;
                depth_first_visit(adjmatrix,i,color,pred,index,res,position);
            }

            if(color[i] == 1)
            {
                return 0;
            }
            
        }
    }
    color[vertex] = 2;
    res[*position] = vertex;
    (*position)++;
}