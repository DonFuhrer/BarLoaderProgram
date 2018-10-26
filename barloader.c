#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NPLATES    8
#define BARWEIGHT 20.0

void
discCounter (float);


int
main ()
{
	float
	requiredWeight = 0;		// this is the weight to be lifting

	// get the user input, that is the weight to lift
	do scanf("%f", &requiredWeight);
	while (requiredWeight==0);

	// if the weight is equal to the bar weight, only use the bar
	// else, if the weight is less than the bar weight, exit the program
	if (requiredWeight < BARWEIGHT) {
		printf("ERROR: the weight need to be greater than or equal to the weight bar.\n");
		exit(EXIT_FAILURE);
	} else
	if (requiredWeight == BARWEIGHT) {
		printf("Only use the bar weight, that is 20 kg.\n");
		exit(EXIT_FAILURE);
	}

	printf("Weight loaded: %.2f kg (%.2f lb)\n", requiredWeight, (requiredWeight*2.2046));
	discCounter(requiredWeight);

	return 0;
}

void
discCounter (float weight)
{
	float
	remainderWeight = 0;	     // the remainder weight without the bar weight

	float
	values[NPLATES] = {	     // each value of the plates
		25.0, 20.0, 15.0, 10.0,
		5.0, 2.5, 1.25, 0.5
	};

	int
	platesInUse[NPLATES] = {     // record the number of plates by side for each weight/value
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	platesAmount[NPLATES] = {    // store the maximum number of plates that you can use
		6, 6, 2, 2,
		2, 2, 2, 2
	};

	int i;			     // for loops


	// calculate the weight that will be added without the bar weight
	remainderWeight = weight-BARWEIGHT;

	// calculate the number of plates to use by side
	for (i=0; (remainderWeight!=0) && (i<NPLATES); i++) {
		if (platesInUse[i] == platesAmount[i])
			continue;

		if (remainderWeight < (values[i]*2))
			continue;

		do {
			remainderWeight -= (values[i]*2);
			platesInUse[i]++;
		} while ((remainderWeight>=(values[i]*2)) && (platesInUse[i]<platesAmount[i]/2));
	}

	if (i==NPLATES) {
		printf("There are not enough plates.\n");
		exit(EXIT_FAILURE);
	}

	printf("Weight breakdown:\n");
	for (i=0; i<NPLATES; i++)
		if (platesInUse[i]!=0)
			printf("\t%d of %5.2f kg (%5.2f lb)\n", platesInUse[i], values[i], (values[i]*2.2046));

	return;
}
