#include <stdio.h>
#define ROW 5
#define COL 3

float columnAverages(float columnSum, float time)
{
    return columnSum / time;
}
float rowAverages(float rowSum, float time)
{
    return rowSum / time;
}
float regionAverages(float mtx[ROW][COL],int left, int right, int bot, int top)
{
    float regionSum = 0;
    float time = 0;
    for(int r = top; r <= bot; r++)
    {
        for(int c = left; c <= right; c++)
        {
            regionSum = regionSum + mtx[r][c];
            time++;
        }
    }
    return regionSum / time;
}
void generateMtx(float mtx[ROW][COL])
{
    float value = 0;
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            printf("Enter row %d, column %d: ", r,c);
            scanf("%f", &value);
            mtx [r][c] = value;
        }
    }
}
void printMtx(float mtx[ROW][COL], float rowAverages[5])
{
    printf("        Col 0   Col 1   Col 2");
    for(int r = 0; r < ROW; r++)
    {
        printf("\nRow %d", r);
        for(int c = 0; c < COL; c++)
        {
            printf("%8.1f", mtx[r][c]);
        }
    }
    printf("\n\n        Col 0   Col 1   Col 2     Avg");
    for(int r = 0; r < ROW; r++)
    {
        printf("\nRow %d", r);
        for(int c = 0; c < COL; c++)
        {
            printf("%8.1f", mtx[r][c]);
        }
        printf("%8.1f", rowAverages[r]);
    }
}
int main()
{
    int left, right, bot, top;
    float mtx[ROW][COL]={};
    generateMtx(mtx);
    float columnAvg[COL] = {};
    float columnSum, time = 0;
    for(int c = 0; c < COL; c++)
    {
        columnSum = 0;
        time = 0;
        for(int r = 0; r < ROW; r++)
        {
            columnSum = columnSum + mtx[r][c];
            time++;
        }
        columnAvg[c] = columnAverages(columnSum, time);
    }
    float rowAvg[ROW] = {};
    float rowSum = 0;
    for(int r = 0; r < ROW; r++)
    {
        rowSum = 0;
        time = 0;
        for(int c = 0; c < COL; c++)
        {
            rowSum = rowSum + mtx[r][c];
            time++;
        }
        rowAvg[r] = rowAverages(rowSum, time);
    }
    printMtx(mtx, rowAvg);
    printf("\n  Avg%8.1f%8.1f%8.1f", columnAvg[0],columnAvg[1],columnAvg[2]);
    printf("\nEnter top region boundary: ");
        scanf("%d", &top);
    printf("Enter bottom region boundary: ");
        scanf("%d", &bot);
    printf("Enter left region boundary: ");
        scanf("%d", &left);
    printf("Enter right region boundary: ");
        scanf("%d", &right);
    double rAvg = regionAverages(mtx, left, right, bot, top);
    printf("Region average: %.1f", rAvg);
}
