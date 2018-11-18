#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void fillMatrix(float *arr, int size){
	for(int i=0; i<size; i++){
		arr[i] = (float)rand();
	}
	return;
}

int transpose(float *input, float *output, int H, int W, int B){
	for(int r=0; r<((H/B)+1); r++)
		for(int c=0; c<((W/B)+1); c++)
			for(int br=0; br<B; br++)
				if( ((r*B)+br) < H){
					for(int bc=0; bc<B; bc++){
						if( ((c*B)+bc) < W)	
							output[((c*B)+bc)*H + ((r*B)+br) ] = input[((r*B)+br)*W + ((c*B)+bc)];							
					}
				}		
	return 0;
}



int main(int argc, char *argv[]){

	if(argc!=4){
		printf("Invalid number of arguments\n Proper format: transpif <matrix height> <matrix width> <block width>\n");
		return -1;	
	}

	int matrixSize = atoi(argv[1])  * atoi(argv[2]);
	float *input = malloc(matrixSize * sizeof(float));
	float *output = malloc(matrixSize * sizeof(float));
	
	fillMatrix(input, matrixSize);
	
	struct timeval before;
	struct timeval after;

	gettimeofday(&before, NULL);
	if(transpose(input, output, atoi(argv[1]), atoi(argv[2]), atoi(argv[3])) < 0){
		printf("error");
		return -1;
	}
	gettimeofday(&after, NULL);

	long difference =  ((long)(after.tv_sec)*1000000+after.tv_usec )  - ((long)(before.tv_sec)*1000000+before.tv_usec );
	printf("T: %li microseconds\n", difference); 
	
	return 0;
}
