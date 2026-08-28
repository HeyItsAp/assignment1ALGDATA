# Analyse av Algortimen

Algoritmen som brukes i `main.c`

```Shell
void BestProfit(int *numbers, int length){

	printf("%d\n", length);

	int Best[] = {0,0,0}; // BuyDay, SellDay, ProfitDifferance

	for (int i = 0; i < length; i++){

		// Note that every print will print out the index+1, accordance to Tabell 1.1

		printf("Trying Day %d.\n", i+1);

		int profitBase = 0;

		for ( int j = i+1; j < length; j++){

			profitBase += numbers[j];

			printf("Buy: Day %d, Sell: Day %d, Profit so far: %d\n",i+1,j+1,profitBase);

			if (profitBase > Best[2]){

				Best[0] = i+1;

				Best[1] = j+1;

				Best[2] = profitBase;

			}

		}

	}

	printf("Best so far: Buy on Day %d, Sell on Day %d and Profit will be, %d\n", Best[0], Best[1],  Best[2]);
}
```

Vi prøver å regne tidskompleksitet til algoritmen. Vi trenger ikke å se på noen annet enn for-løkken:

* for-løkkene:

  * Indre-løkken ($j$) kjører som av funksjon av den ytre ($i$). Altså  $j=i+1$
  * Det er det samme som $j=n-1$
  * Summert over alle veridene av $i$, $0$ til $n-1$. Får vi $n(n-1)/2$
  * Hver iterasjon gjør et konstant arbeid.
  * Dette er et trekanttall or hvis vi utledder det får vi et polynom med et dominerende ledd på $n^2$.

> Vi får et tidskompleksistet på $O(n^2)$

Algoritmen inneholder ikke et brudd (`break`) i algoritmen. All arbeidet gjøres uansett.

# Bekreftelse gjennom testing

| n | Tid (s) |
| --------| -------- |
| 1000    | 0.000644   |    
| 2000    | 0.002011   |    
| 4000    | 0.006121   |    
| 8000    | 0.023915   |    
| 16000   | 0.402213 |    
