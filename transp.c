#include <stdio.h>
#include <stdlib.h>

void fillMatrix(float *arr, int size){
	int count =0;
	while(count++ < size){
		arr[count] = (float)rand()/(float)(RAND_MAX/100);
	}
	return;
	
}

int transpose(float *input, float *output, int N, int blockSize){
		
	//row i column j input[i*N + j]
	return 0;
}



int main(int argc, char *argv[]){

	if(argc!=3){
	printf("Invalid number of arguments\n Proper format: transp <matrix width> <block width>\n");
	return -1;	
	}
	//both argv[1] and argv[2] should be powers of 2
	int matrixSize = atoi(argv[1])  * atoi(argv [1]);
	float *input = malloc(matrixSize * sizeof(float));
	float *output = malloc(matrixSize * sizeof(float));
	
	fillMatrix(input, matrixSize);

	if(transpose(input, output, atoi(argv[1]), atoi(argv[2])) < 0){
		printf("error");
		return -1;
	}

	return 0;
}
