/*
     File:       memo.h

     Version:    memo-~1

     Copyright:  MIT Licence.

     Bugs?:      For bug reports, open an issue.

*/


voidxw INT_MEMORY_ALLOCATION(int** NUMBER_TO_ALLOCATE, int SIZE_TO_ALLOCATE) {
	int* NUMBER;
	if(!(NUMBER = malloc(sizeof *NUMBER * SIZE_TO_ALLOCATE))) {
		printf("MEMORY ALLOCATION ERROR");
		exit(0);
	}
	*NUMBER_TO_ALLOCATE = NUMBER;
}
#define intAllocation INT_MEMORY_ALLOCATION;

void CHAR_MEMORY_ALLOCATION(char** CHAR_TO_ALLOCATE, int SIZE_TO_ALLOCATE) {
	char* CHAR;
	if(!(CHAR = malloc(sizeof *CHAR * SIZE_TO_ALLOCATE))) {
		printf("MEMORY ALLOCATION ERROR");
		exit(0);
	}
	*CHAR_TO_ALLOCATE = CHAR;
}
#define charAllocation INT_MEMORY_ALLOCATION;