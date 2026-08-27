#include <stdio.h>

void BestProfit(int *numbers, int length, int *bestProfit);

int main(){
	int testNumb[] = {-1, 3, -9, 2, 2, -1, 2, -1, -5};
	int best[] = {0,0,0};
	size_t length = sizeof(testNumb) / sizeof(testNumb[0]);

	BestProfit(testNumb, length, best);
	return 0;
}

void BestProfit(int *numbers, int length, int *bestProfit){
	printf("%d", length);
}
