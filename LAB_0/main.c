#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROUND_SIZE 100

float randomize(){

	float a = 1.0;
	float x = ((float)rand()/(float)(RAND_MAX)) * a;
	//printf("%f\n", x);
	float xR = round(x*ROUND_SIZE)/ROUND_SIZE;
	//printf ("%.2f\n" ,xR);

	return xR;
}

int main(){

	srand((unsigned int)time(NULL));

	int counting[101];

	for (int i = 0; i < 101; i++){
		counting[i] = 0;
	}

	printf("Randomizing ....\n");

	for (int i = 0; i < 1000000; i++){
		float rand_num = randomize();
		int k = rand_num * ROUND_SIZE;
		counting[k]++;
	}

	for (int i = 0; i <= ROUND_SIZE; i++){
		float k = (float)i / ROUND_SIZE;
		printf("%.2f %d\n", k, counting[i]);
	}

	return 0;
}