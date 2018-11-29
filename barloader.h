#include <stdio.h>

#define N_DECIMAL_POINTS_PRECISION (100)
#define BARWEIGHT 20.0
#define PLATESQTY  8
#define MAX_NUM_PLATES 13

int
platesQty[PLATESQTY] = {
	0, 0, 0, 0,
	0, 0, 0, 0
};

float
values[PLATESQTY] = {
	25.0, 20.0, 15.0, 10.0,
	5.0, 2.5, 1.25, 0.5
};

int
ChckDecimalLength (float f)
{
	return ((int) (f*N_DECIMAL_POINTS_PRECISION) % N_DECIMAL_POINTS_PRECISION);
}

void
PrintWeights (float f)
{
	int i;
	for (i=0; i<PLATESQTY; i++) {
		if (platesQty[i]!=0) {
			if (ChckDecimalLength(values[i])==0)
				printf("%.0f", values[i]);
			else
				printf("%.2f", values[i]);

			if (platesQty[i]>1)
				printf("x%d ", platesQty[i]);
			else
				printf(" ");
		}
		if (platesQty[i+1]!=0)
			printf("+ ");
	}

	if (ChckDecimalLength(f) == 0)
		printf("= %.0f kg (%5.2f lb)\n", f, (f*2.2046));
	else
		printf("= %.1f kg (%5.2f lb)\n", f, (f*2.2046));

	return;
}
