#include <stdio.h>
#include <math.h>


#define MAX_NUM_OF_EL 1000


long double input_array[MAX_NUM_OF_EL];


int calculation_func(long long int num_of_el, long double *max_el_ptr, long double *min_el_ptr, long double *average_ptr, long double *standart_dev_ptr) {

	*max_el_ptr = input_array[0];
	*min_el_ptr = input_array[0];
	*average_ptr = 0;
	*standart_dev_ptr = 0;

	long double sum_of_squares = 0;
	long double sum_of_el = 0;

	for (long long int i = 0; i < num_of_el; i++) {

		if (input_array[i] < *min_el_ptr) {
			*min_el_ptr = input_array[i];
		}
		else {

			if (input_array[i] > *max_el_ptr) {
				*max_el_ptr = input_array[i];
			}

		}

		sum_of_squares += input_array[i] * input_array[i];
		sum_of_el += input_array[i];
	}

	*average_ptr = sum_of_el / num_of_el;
	*standart_dev_ptr = sqrt(sum_of_squares / num_of_el - *average_ptr * *average_ptr);

	return 0;

}


int main() {

	printf("This programm searches maximun and minimun elements and calculates average and standard deviation in static array.\n\n");

	for (int cont = 1; cont;) {
		printf("In all following inputs extra elements will be ignored but if you input invalid element insted of expected it will be a mistake.\n");
		printf("Input the number of elements in your array \(less than %d\)\n", MAX_NUM_OF_EL);

		long long int num_of_el = 0;

		if (scanf_s("%lli", &num_of_el) == 1) {
			fseek(stdin, 0, SEEK_END);	//Плохой вариант, но для лучшего впору писать библиотеку...
			printf("\n");

			if (num_of_el <= 0) {
				printf("You input invalid number of element. It should be more then 0. Please, try again...\n\n");
			}
			else {

				if (num_of_el > MAX_NUM_OF_EL) {
					printf("You input invalid number of element. It should be less then %d. Please, try again...\n\n", MAX_NUM_OF_EL);
				}
				else {
					printf("Input the elements of your array through the gap.\n", MAX_NUM_OF_EL);

					int err = 0;

					for (long long int i = 0; i < num_of_el && err != 1; i++) {

						if (scanf_s("%Lf", &input_array[i]) != 1) {
							err = 1;
						}

					}

					fseek(stdin, 0, SEEK_END);

					if (!(err)) {
						printf("\n");

						long double max_el = 0;
						long double min_el = 0;
						long double average = 0;
						long double standart_div = 0;

						if (!(calculation_func(num_of_el, &max_el, &min_el, &average, &standart_div))) {
							printf("Maximum element is %.10Lf\nMinimum element is %.10Lf\nAverage is %.10Lf\nStandard deviation is %.10Lf\n\n", max_el, min_el, average, standart_div);

							printf("If you want to it again with another parameters input 1, else input 0\n");
							scanf_s("%d", &cont);
							printf("\n");
						}

					}
					else {
						printf("You input not a number. Please, try again...\n\n");
					}
				}

			}

		}

		else {
			fseek(stdin, 0, SEEK_END);
			printf("You input not a number. Please, try again...\n\n");
		}


	}

	return 0;
}