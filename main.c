#include <stdio.h>

void BestProfit(int *numbers, int length);

int main(){
	int testNumb[] = {-1, 3, -9, 2, 2, -1, 2, -1, -5};
	size_t length = sizeof(testNumb) / sizeof(testNumb[0]);

	BestProfit(testNumb, length);
	return 0;
}

void BestProfit(int *numbers, int length){
	printf("%d\n", length);
	int Best[] = {0,0,0}; // BuyDay, SellDay, ProfitDifferance
	for (int i = 0; i <= length; i++){
		printf("Trying Day %d.\n", i);
		int profitBase = 0;
		for ( int j = i+1; j <= length; j++){
			profitBase += numbers[j];
			printf("Buy: Day %d, Sell: Day %d, Profit so far: %d",i,j,profitBase); 
			if (profitBase > Best[2]){
				Best[0] = i+1;
				Best[1] = j+1;
				Best[2] = profitBase;
			}
		}
	}
	printf("Best so far: Buy on Day %d, Sell on Day %d and Profit will be, %d", Best[0], Best[1],  Best[2]); 


}

