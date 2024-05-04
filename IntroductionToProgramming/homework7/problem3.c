#include <stdio.h>
#define ROWS 4
#define COLS 3

void generateMtx(int mtx[ROWS][COLS])
{
    int value = 0;

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("Enter row %d, column %d: ", r,c);
            scanf("%d", &value);
            mtx [r][c] = value;
        }
    }

}
int matrixSmallest(int mtx[ROWS][COLS])
{
    int oldR = 0;
    int oldC = 0;
    int smallest = 0;
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if(mtx[r][c] <= mtx[oldR][oldC])
            {
                smallest = mtx[r][c];
            }
            oldC = c;
        }
        oldR = r;
    }
    return smallest;
}

int matrixLargest(int mtx[ROWS][COLS])
{
    int oldR = 0;
    int oldC = 0;
    int largest = 0;
    for (int r = 0; r < 4; r++)
    {

        for (int c = 0; c < 3; c++)
        {

            if(mtx[r][c] > mtx[oldR][oldC])
            {
                largest = mtx[r][c];
            }
            oldC = c;
        }
        oldR = r;
    }
    return largest;
}
void elementPosition(int mtx[ROWS][COLS],  int num, int position[2])
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if(num == mtx[r][c])
            {
                position[0] = r;
                position[1] = c;
            }
        }
    }
}

int main()
{
    int mtx[ROWS][COLS];
    generateMtx(mtx);

    int smallest = matrixSmallest(mtx);
    int smallPosition[2] = {-1, -1};
    elementPosition(mtx, smallest, smallPosition);

    int largest = matrixLargest(mtx);
    int largePosition[2] = {-1, -1};
    elementPosition(mtx, largest, largePosition);

    printf("Largest element: %d\n", largest);
    printf(" found at row %d, column %d\n", largePosition[0], largePosition[1]);
    printf("Smallest element: %d\n", smallest);
    printf(" found at row %d, column %d\n", smallPosition[0], smallPosition[1]);
    return 0;
}
