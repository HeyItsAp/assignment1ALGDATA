#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void BestProfit(int *numbers, int length);

int main(){
	int testNumb[] = {-1, 3, -9, 2, 2, -1, 2, -1, -5};
	
	// Create DIFFERENT big arrays and run it
	int sizes[] = {500,1000,2000,4000,8000,16000};
	size_t lengthOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    	for (int s = 0; s < lengthOfSizes; s++) {
        	int n = sizes[s];
        	int *arr = malloc(n * sizeof(int));
    
		for (int i = 0; i < n; i++)
            		arr[i] = (rand() % 21) - 10;

        	clock_t start = clock();
        	BestProfit(arr, n);
        	clock_t end = clock();

        	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        	printf("n = %d, time = %f seconds\n", n, seconds);

        	free(arr);
    	}
	exit(0);
}

void BestProfit(int *numbers, int length){
//	printf("%d\n", length);
	int Best[] = {0,0,0}; // BuyDay, SellDay, ProfitDifferance
	for (int i = 0; i < length; i++){
		// Note that every print will print out the index+1, accordance to Tabell 1.1
//		printf("Trying Day %d.\n", i+1);
		int profitBase = 0;
		for ( int j = i+1; j < length; j++){
			profitBase += numbers[j];
//			printf("Buy: Day %d, Sell: Day %d, Profit so far: %d\n",i+1,j+1,profitBase); 
			if (profitBase > Best[2]){
				Best[0] = i+1;
				Best[1] = j+1;
				Best[2] = profitBase;
			}
		}
	}
//	printf("Best so far: Buy on Day %d, Sell on Day %d and Profit will be, %d\n", Best[0], Best[1],  Best[2]); 


}

