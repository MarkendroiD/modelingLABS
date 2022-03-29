#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INTERVAL 100 // Точность после запятой
#define N 10000000    // Кол-во сгенерированных чисел
#define DOOM 100	 // Диапозон от 0 до DOOM \ 100

float math(float E){
	float result;
	if (E <= 0.5){
		result = sqrtf(sqrtf(E/8));
		//result = 1 - sqrtf(sqrtf((1 - E) / 8));
		//printf("%.2f  |||   %f  \n", E,result);
	} else {
		result = 1 - sqrtf(sqrtf((1 - E) / 8));
		//result = sqrtf(sqrtf(E/8));
		//printf("%f  ", result);
	}
	//printf("HELLO %f %f\n", E, result);
	return result;
}

int main(){

	FILE *result;

	srand((unsigned int)time(NULL));

	int counting[DOOM+1];

	for (int i = 0; i <= DOOM; i++){
		counting[i] = 0;
	}

	printf("Randomizing ....\n");

	for (int i = 0; i <= N; i++){
		int x = rand() % (DOOM + 1);
		float k = (float)x / INTERVAL;
		float result = math(k) * INTERVAL;
		//printf("BYE %d\n", (int)result);
		counting[(int)result]++;
		//printf("BYE\n");

	}

	result = fopen ("LAB_1/result.txt", "w");
	fprintf (result, "Num Count\n");
	printf("Writing result ....\n");

	for (int i = 0; i < DOOM; i++){
		float k = (float)i / INTERVAL;
		printf("%.2f %d\n", k, counting[i]);
		fprintf (result, "%.2f %d\n", k, counting[i]);
	}
	printf("Ready!\n");
	fclose(result);

	return 0;
}