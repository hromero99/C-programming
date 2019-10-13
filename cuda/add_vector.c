#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float * create_array(int N){

	float * vector = (float *)calloc(N, sizeof(float));
	if (vector == NULL){
		printf("Error creating vector");
		exit(EXIT_FAILURE);
	}
	return vector;
}

void fill_vector(float* h_a, float* h_b,int size){
	srand(time(NULL));
	for (int i=0; i<size;i++){
		*(h_a+i) =rand()%50;
		*(h_b+i) =rand()%50;
	}

}

void add_vector(float* h_a, float* h_b, float* h_c, int size){
	
	for (int i=0; i<size;i++){
		*(h_c+i) = *(h_a+i) + *(h_b+i);
	}

}
int main(int argc, char* argv[]){

	float* h_a;
	float* h_b;
	float* h_c;
	int size = 4;
	h_a = create_array(size);
	h_b = create_array(size);
	h_c = create_array(size);
	fill_vector(h_a,h_b,size);
	add_vector(h_a,h_b,h_c,size);
	for (int i=0; i<size;i++){
		printf("%f\n",*(h_c+i));
	}
	return EXIT_SUCCESS;
}
