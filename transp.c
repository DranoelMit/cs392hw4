#include <stdio.h>
#include <stdlib.h>

void fillMatrix(float *arr, int size){
	int count =0;
	while(count++ < size){
		arr[count] = (float)rand()/(float)(RAND_MAX/100);
	}
	return;
	
}



int main(int argc, char *argv[]){

	if(argc!=3){
	printf("Invalid number of arguments\n Proper format: transp <matrix width> <block width>\n");
	exit(1);	
	}

	int matrixSize = atoi(argv[1])  * atoi(argv [1]);
	float *input = malloc(matrixSize * sizeof(float));
	float *output = malloc(matrixSize * sizeof(float));
	
	fillMatrix(input, matrixSize);
	exit(0);
}
