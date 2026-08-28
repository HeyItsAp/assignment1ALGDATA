# Analyse av Algoritmen

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

- for-løkkene:
  - Indre-løkken ($j$) kjører som av funksjon av den ytre ($i$).
  - For hver $i$ går $j$, fra $i+1$ til $n-1$.
  - Altså indre løkken kjører $n-i-1$ ganger
  - Summert over alle verdiene av $i$, $0$ til $n-1$. Får vi $n(n-1)/2$
  - Hver iterasjon gjør et konstant arbeid.
  - Dette er et trekanttall og hvis vi utledder det får vi et polynom med et dominerende ledd på $n^2$.

Algoritmen inneholder ikke et brudd (`break`) i algoritmen. All arbeidet gjøres uansett.

> Vi får et tidskompleksistet på $Θ(n^2)$

# Bekreftelse gjennom testing

**Runde 1:**

| n     | Tid (s)  |
| ----- | -------- |
| 500   | 0.000644 |
| 1000  | 0.002011 |
| 2000  | 0.006121 |
| 4000  | 0.023915 |
| 8000  | 0.088313 |
| 16000 | 0.402213 |

**Runde 2:**

| n     | Tid (s)  |
| ----- | -------- |
| 500   | 0.000556 |
| 1000  | 0.001688 |
| 2000  | 0.007727 |
| 4000  | 0.024704 |
| 8000  | 0.093093 |
| 16000 | 0.411764 |

**Runde 3:**

| n     | Tid (s)  |
| ----- | -------- |
| 500   | 0.000513 |
| 1000  | 0.002262 |
| 2000  | 0.005479 |
| 4000  | 0.022521 |
| 8000  | 0.098079 |
| 16000 | 0.403652 |

## Tolkning

Vi ser på forholdene av gjennomsnittet av tidene ved alle runder:
Vi regner forholdet med å dele på tidene hos datamengdene $n_2/n_1$

| n     | Gjennomsnittlig Tid (s) | Forhold (s) |
| ----- | ----------------------- | ----------- |
| 500   | 0.000571                | N/A         |
| 1000  | 0.001981                | 3.480       |
| 2000  | 0.006442                | 3.242       |
| 4000  | 0.023713                | 3.681       |
| 8000  | 0.093162                | 3.928       |
| 16000 | 0.405876                | 4.357       |

Vi kan se en stigende forhold mellom hver av datamengende stiger mot $2^2=4$ eller mer spesfikt havner mellom **3.1-4.5**. Dette stemmer i praksis: Ved små datamengder er andre faktorer sett mer merkbare, og maskinen eller kernel klarer å effektisere. Ved større datamengder, nærmer forholdet $4$

# Konklusjon

Algoritmen som brukes i denne oppgaven er teoretisk analysert og bevisst på at den ligger på tidskompleksitet $Θ(n^2)$.
