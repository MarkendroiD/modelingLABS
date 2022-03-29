#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INTERVAL 100 // Точность после запятой
#define N 1000000    // Кол-во сгенерированных чисел
#define DOOM 100	 // Диапозон от 0 до DOOM \ 100


int main(){

	FILE *result;

	srand((unsigned int)time(NULL));

	int counting[DOOM+1];

	for (int i = 0; i <= DOOM; i++){
		counting[i] = 0;
	}

	int withOut[4];

	for (int i = 0; i <= 3; i++){
		withOut[i] = 0;
	}
	int with[4];

	for (int i = 0; i <= 3; i++){
		with[i] = 0;
	}

	printf("Randomizing ....\n");

	for (int i = 0; i <= N; i++){
		int x = rand() % (DOOM + 1);
		float res = (float)x / INTERVAL;

		if (res < 0.083){
			withOut[0]++;
		} else if (res <= 0.5){
			withOut[1]++;
		} else if (res < 0.92){
			withOut[2]++;
		} else {
			withOut[3]++;
		}

		if (res < 0.125){
			with[0]++;
		} else if (res <= 0.5){
			with[1]++;
		} else if (res < 0.875){
			with[2]++;
		} else {
			with[3]++;
		}

		//counting[(int)result]++;
		//printf("BYE\n");

	}

	result = fopen ("LAB_2/result.txt", "w");
	fprintf (result, "Num Count Teor\n");
	/*
	for (int i = 0; i < DOOM; i++){
		float k = (float)i / INTERVAL;
		printf("%.2f %d\n", k, counting[i]);
		fprintf (result, "%.2f %d\n", k, counting[i]);
	}
	*/
	printf("Без возврата:\n");
	for (int i = 0; i < 4; i++){
		printf("%d %d\n", i, withOut[i]);
		fprintf(result, "%d %f", i, (float)withOut[i] / N);
		switch(i){
			case 0: fprintf(result, " 0.0833\n"); break;
			case 1: fprintf(result, " 0.4166\n"); break;
			case 2: fprintf(result, " 0.4166\n"); break;
			case 3: fprintf(result, " 0.0833\n");
		}
	}

	fprintf (result, "Num Count Teor\n");

	printf("С возвратом:\n");
	for (int i = 0; i < 4; i++){
		printf("%d %d\n", i, with[i]);
		fprintf(result, "%d %f", i, (float)with[i] / N);
		switch(i){
			case 0: fprintf(result, " 0.1250\n"); break;
			case 1: fprintf(result, " 0.3750\n"); break;
			case 2: fprintf(result, " 0.3750\n"); break;
			case 3: fprintf(result, " 0.1250\n");
		}
	}

	printf("Ready!\n");
	fclose(result);

	return 0;
}