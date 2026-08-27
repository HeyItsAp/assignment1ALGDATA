#include <stdio.h>

void BestProfit(int numbers[], int counter, int best[]);

int main(){
	int testNumb[] = {-1, 3, -9, 2, 2, -1, 2, -1, -5};
	int best[] = {0,0,0};
	BestProfit(testNumb, 0, best);
	return 0;
}

void BestProfit(int numbers[], int counte, int best[]){
	size_t length = sizeof(numbers); 
	printf("%zu", length);
}
