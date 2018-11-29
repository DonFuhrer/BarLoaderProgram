#include "barloader.h"

int
main()
{
	float
	weight=0, weightLoaded=0;

	int
	platesCounter=0, i;

	while (1) {
		scanf("%f", &weight);

		if (platesCounter==MAX_NUM_PLATES || weight==0)
			break;

		for (i=0; i<PLATESQTY; i++) {
			if (weight==values[i]) {
				platesCounter++;
				platesQty[i]++;
				weightLoaded += (weight*2);
				break;
			}
		}
		weight = 0;
	}

	weightLoaded += BARWEIGHT;

	PrintWeights(weightLoaded);

	return 0;
}
