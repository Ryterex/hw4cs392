/* Caleb Obeng
	I pledge my honor that I have abided by the stevens honor system. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv){
	if (argc != 4) {
		fprintf(stderr, "Wrong number of command-line arguments\n usage: %s <height of matrix> <width of matrix> <width of block>\n", argv[0]);
		return -1;
	}

	int matrix_height = atoi(argv[1]);
	int matrix_width = atoi(argv[2]);
	int block_size = atoi(argv[3]);
	if(matrix_width < block_size || matrix_height < block_size){
		fprintf(stderr, "block cannot be bigger than the matrix\n");
		return -1;
	}

	float *A = (float *) malloc(matrix_width*matrix_height*sizeof(float));
	float *AT = (float *) malloc(matrix_width*matrix_height*sizeof(float));
	srand(time(NULL));
/*
	//input matrix creation
	printf("input matrix\n");
	for(int i=0; i<matrix_height*matrix_width; i++){
		if((i!=0) && (i%matrix_width == 0)){
			printf("\n");
		}
		float x = (float)( (rand()) / (float)RAND_MAX);
		float y = (x * ( 100 + 100 ));
		printf("%f ", y);
		A[i] = y;
	}
	printf("\n\n");
*/
	//transpose the thing
	struct timeval start, end;
	gettimeofday(&start, NULL);
	printf("Start Time: %ld\n", (start.tv_sec * 1000000 + start.tv_usec));
	for(int i=0; i<matrix_height;i+=block_size){
		for(int j=0; j<matrix_width; j+=block_size){
			for(int k=i; k<i + block_size; k++){
				if(k>=matrix_height){
					break;
				}
				for(int l = j; l < j + block_size; l++){
					if(l>=matrix_width){
						break;
					}
					AT[k + l*matrix_height] = A[k*matrix_width + l];
				}
			}
		}

	}
	//float elems = matrixx * matrixx;

	gettimeofday(&end,NULL);
	printf("End Time: %ld\n", (end.tv_sec * 1000000 + end.tv_usec));

	long difference = ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec));
	printf("Time Difference in MicroSeconds: %ld\n\n", difference);
/*
	//print output matrix
	printf("transposed matrix\n");
	for(int i=0; i<matrix_height*matrix_width; i++){
		if((i!=0) && (i%matrix_height == 0)){
			printf("\n");
		}
		printf("%f ", AT[i]);
	}
	printf("\n");
	*/
	free(A);
	free(AT);
	return 0;

}
