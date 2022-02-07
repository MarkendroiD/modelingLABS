#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INTERVAL 100 // Точность после запятой
#define N 1000000    // Кол-во сгенерированных чисел


float x2(int counting[]){

	float x2_result;  //эксперементальное x^2
	float p_i;        //𝑝𝑖 – теоретическая вероятность попадания чисел в i-ый интервал равна 𝑝𝑖=1/𝑘

	x2_result = 0;
	p_i = 1.0 / (INTERVAL + 1);

	for (int i = 0; i <= INTERVAL; i++){
		x2_result += (pow(counting[i], 2) / p_i);
	}

	//printf("%.f\n", x2_result);
	x2_result = (x2_result / N) - N;

	return x2_result;

}

int main(){

	FILE *result;

	srand((unsigned int)time(NULL));

	int counting[101];

	for (int i = 0; i <= INTERVAL; i++){
		counting[i] = 0;
	}

	printf("Randomizing ....\n");

	for (int i = 0; i <= N; i++){
		int x = rand() % (INTERVAL + 1);
		counting[x]++;
	}

	result = fopen ("LAB_0/result.txt", "w");
	fprintf (result, "Num Count\n");
	printf("Writing result ....\n");

	for (int i = 0; i < INTERVAL; i++){
		float k = (float)i / INTERVAL;
		//printf("%.2f %d\n", k, counting[i]);
		fprintf (result, "%.2f %d\n", k, counting[i]);
	}
	printf("Ready!\n");
	fclose(result);

	float res_x2 = x2(counting);

	printf ("x^2 = %f \n", res_x2);

	return 0;
}