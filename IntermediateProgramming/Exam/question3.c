#include <stdio.h>
/*The code given in the question does 2 main tasks and they are to check for file existance with the filename
provided from commandline arguments while compiling(gcc) the program in the terminal, and the other task is to calculation */

/*I created a new function called <PrintResults(double data[128])> which take in a double array size of 128 as the parameter.
This function will replace the calculation task in main() by being called in main(). No need for return type because the results
can be printed inside PrintResults as well. 
This led to better readabilty of the code for other people if you are working with Agile or DevOps Engineers*/
void PrintResults(double data[128])
{
    double sum = 0;
    for (int i = 0; i < 128; i++) {
        sum += data[i];
    }
    
    for (int i = 0; i < 128; i++) {
        data[i] /= sum;
    }
    
    for (int i = 0; i < 128; i++) {
        printf("data[%d] = %.4lf\n", i, data[i]);
    }
}
int main(int argc, char *argv[]) {
    double data[128] = { 0 };
    
    if (argc != 2) {
        printf("USAGE: ./a.out FILENAME\n");
        return 1;
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file \"%s\"\n", argv[1]);
        return 1;
    }
    
    fread(data, sizeof(double), 128, fp);
    fclose(fp);
    PrintResults(data);
    
    return 0;
}