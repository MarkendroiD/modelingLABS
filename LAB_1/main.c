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

float autoCor(int counting[], float all_numbers[]){
	float max_exp = 0.0;
	float max2_exp = 0.0;

	for (int i = 1; i <= INTERVAL; i++){
		max_exp += (i / INTERVAL) * counting[i];
		max2_exp += pow((i / INTERVAL), 2) * counting[i];
	}

	max_exp /= N;
	max2_exp /= N;

	float dispers = max2_exp - pow(max_exp, 2);

	float p1, p2;

	float aver_cor = 0.0;
	float auto_cor;
	for (int offset = 1; offset < 10; offset++){
		auto_cor = 0.0;
		for (int pos = 0; pos < N; pos++){
			p1 = (all_numbers[pos] - max_exp);
			p2 = (all_numbers[(pos + offset) % N] - max_exp);

			auto_cor += p1 * p2;
		}
		auto_cor /= (dispers * N);
		aver_cor += fabs(auto_cor);

		printf("autocor = %f\n", fabs(auto_cor));

	}

	printf("average autocor = %f\n", aver_cor / 10);

	return 0;

}

int main(){

	FILE *result;

	srand((unsigned int)time(NULL));

	int counting[101];

	for (int i = 0; i <= INTERVAL; i++){
		counting[i] = 0;
	}

	printf("Randomizing ....\n");

	float all_numbers[N + 1];

	for (int i = 0; i <= N; i++){
		int x = rand() % (INTERVAL + 1);
		all_numbers[i] = x / INTERVAL;
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

	autoCor(counting, all_numbers);

	return 0;
}