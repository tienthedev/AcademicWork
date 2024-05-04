/*
    compile:
gcc -g scores.c
    run with valgrind:
valgrind --leak-check=full ./a.out
*/

#include <stdlib.h>
#include <stdio.h>

// functions that work with a 1D array to test the student function
void print_1D(int sz, int * arr);
void test_scores();
int test_scores_1(int thresh, int sz_in, int* arr_in, int sz_e_res, int* e_res);

int* get_scores_below(int thresh, int sz_arr, int * arr, int* sz_res);

int main(){
	test_scores();
}

// You do not need to change this print_1D function. It is included here for
// your convenience, in case you need to call it while debugging.
void print_1D(int sz, int * arr){
	for(int k = 0; k< sz; k++){
		printf("%8d", arr[k]);
	}
	printf("\n");
}

void test_scores(){
	printf("\n---------- test_scores - started -----------\n");
	int input1[9]    = {92, 57, 100, 95, 38, 10, 85, 91, 20};
	int expected1[4] = {57, 38, 10, 20};  // expected array returned by
                                          // get_scores_below(60,..., input1 )

	int input2[5]    = {22, 45, 30, 49, 38};
	int expected2[5] = {22, 45, 30, 49, 38};    // expected array returned by
                                                // get_scores_below(50 , ..., input2 )

	int input3[5]    = {3, 0, 3, 1, 3};
	int expected3[2] = {0, 1};              // expected array returned by
                                            // get_scores_below(2, ... , input3 )

	int total_tests = 4;
	int passed_ct = 0;
	passed_ct += test_scores_1(60, 9, input1, 4, expected1);
	passed_ct += test_scores_1(50, 5, input2, 5, expected2);
	passed_ct += test_scores_1(22, 5, input2, 0, NULL);  // here the expected result array is empty (there is no score under threshold 22)
	passed_ct += test_scores_1(2,  5, input3, 2, expected3);

	printf ("\nPassed tests:  %d out of %d\n", passed_ct, total_tests);
	printf("\n---------- test_scores - finished -----------\n");
}



/* runs one test where arr_in is the input array, and it has size sz_in and
   e_res is the expected result array and sz_e_res is the size of the expected result array
   It calls get_fail_grades() on arr_in and compares the content of the array returned by it
   with the content of the array e_res.
   It will free the dynamic array returned by get_fail_grades().
   Returns:
   1 - if passed given test
   0 - if falied given test
*/
int test_scores_1(int thresh, int sz_in, int* arr_in, int sz_e_res, int* e_res){
	int k, passed=0, size_res = -1;
	int * student_res;	// will store pointer to result array

	// call student function
	student_res = get_scores_below(thresh, sz_in, arr_in, &size_res);

	// print array retruned by student function
	print_1D(size_res, student_res);

	// check that every item returned matches what is expected
	if (size_res == sz_e_res) {
		passed = 1;
		for(k = 0; k<size_res; k++){
			if (student_res[k] != e_res[k] ) {  // missmatch found
				passed = 0;     // mark that this test failed
			}
		}
	}
	else {
		passed = 0; // test failed because student result did not find as many values as expected
	}

	if (passed==1) {  // this test passed
		printf("get_scores_below passed the sample test. \n");
	}
	else {            // this test failed
		printf("get_scores_below *** failed *** the sample test.\n");
	}

	free (student_res);

	return passed;
}




/* dynamically allocates an array and populates it with all values from arr
	that are strictly smaller than thresh.
	Returns:
		- the pointer to the dynamically allocated array.
		- NULL if all elements of arr are greater or equal to thres. In this case it does not allocate any memory, and sets content of sz_res to 0.
*/
int* get_scores_below(int thresh, int sz_arr, int* arr, int* sz_res) {
    if (sz_arr > 0) {
        int count = 0;
        int* res = NULL;

        for (int i = 0; i < sz_arr; i++) {
            if (arr[i] < thresh) {
                count++;
                res = (int*)realloc(res, count * sizeof(int));
                res[count - 1] = arr[i];
            }
        }

        if (count > 0) {
            *sz_res = count;
            return res;
        } else {
            // If count is still 0, no elements were found, free the allocated memory.
            free(res);
        }
    }

    *sz_res = 0;
    return NULL;
}


