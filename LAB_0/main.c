#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

	srand((unsigned int)time(NULL));

	int counting[101];

	for (int i = 0; i < 101; i++){
		counting[i] = 0;
	}

	printf("Randomizing ....\n");

	for (int i = 0; i < 1000000; i++){
		int x = rand() % 101;
		counting[x]++;
	}

	for (int i = 0; i <= 100; i++){
		float k = (float)i / 100;
		printf("%.2f %d\n", k, counting[i]);
	}

	return 0;
}