#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void fillMatrix(float *arr, int size){
	for(int i=0; i<size; i++){
		arr[i] = i;
	}
	return;
	
}

int transpose(float *input, float *output, int N, int B){
	//N is width of matrix, B is width of block	
	//row r column c input[r*N + c]
	int binr = N/B;
	for(int r=0; r<binr; r++)
		for(int c=0; c<binr; c++)
			for(int br=0; br<B; br++)
				for(int bc=0; bc<B; bc++){
					//printf("%d\t%d\n", (((c*B)+bc)*N + ((r*B) + br)),( ((r*B)+br)*N + ((c*B)+bc)) );
					output[((c*B)+bc)*N + ((r*B)+br) ] = input[((r*B)+br)*N + ((c*B)+bc)];							
					//printf("%f\t%d\n", input[((r*B)+br)*N + ((c*B)+bc)], (((r*B)+br)*N + ((c*B)+bc)) );
				}		
	//print input and output matrices
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
	int count =0;
	/*
	while(count< matrixSize){
		printf("%f\t%d\n", input[count], count);
		count++;
	}
	printf("-----------\n"); */
	struct timeval before;
	struct timeval after;
	gettimeofday(&before, NULL);
	if(transpose(input, output, atoi(argv[1]), atoi(argv[2])) < 0){
		printf("error");
		return -1;
	}
	gettimeofday(&after, NULL);

//	printf("\tbefore %ld\n\tafter %ld\n", before.tv_sec*1000 + before.tv_usec, after.tv_sec*1000 + after.tv_usec);
	long difference =  ((long)(after.tv_sec)*1000000+after.tv_usec )  - ((long)(before.tv_sec)*1000000+before.tv_usec );
	printf("T: %li microseconds\n", difference); 
	
	/*
	count=0;
	while(count < matrixSize){
		printf("%f\t%d\n", output[count], count);
		count++;
	}
	*/
	
	return 0;
}
