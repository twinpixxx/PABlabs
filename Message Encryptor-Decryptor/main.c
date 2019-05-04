#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


//start of functions definition
int numberInput();
bool isMessageEncrypted();
bool isMessageDecrypted();
//end of functions definition


int main() {
	int taskNumber;
	printf("What task would you like to perform?\n");
	printf("Encrypt(0) | Decrypt(1)\n");
	taskNumber = numberInput();
	switch (taskNumber) {
		case 0:
			if (isMessageEncrypted()) {
				printf("\nSuccess.\n");
				return 0;
			} else {
				printf("\nError.\n");
				return 1;
			}
		case 1:
			if (isMessageDecrypted()) {
				printf("\nSuccess.\n");
				return 0;
			} else {
				printf("\nError.\n");
				return 1;
			}
	}
	return 0;
}


// functions
int numberInput() {
	int number;
	while (!(scanf("%d", &number))) {
		printf("Input error. Try again\n");
		rewind(stdin);
	}
	return number;
}// input for numbers


bool isMessageEncrypted() {
	FILE *message, *output;
	int count = 0;
	char *string;
	string = (char*)malloc(count * sizeof(char));
	char p;
	message = fopen("input.txt","r");
	while ( (p=fgetc(message) ) != EOF)
	{
		string[count] = p;
		count++;
	}
	fclose(message);
	int stringLength = strlen(string) - 1, posString = 0;
	const int matrixSize = ceil(sqrt(stringLength));
	char **arr;
	arr = (char**)malloc(matrixSize * sizeof(char*));
	for(int i = 0; i<matrixSize; i++) {
		arr[i] = (char*)malloc(matrixSize * sizeof(char));
		for(int  j = 0; j < matrixSize; j++) {
			arr[i][j] = ' ';
		}
	}
	for(int i = 0; i < matrixSize; i++) {
		arr[i][0] = string[posString++];
	}
	int pos_x = matrixSize-1, pos_y = 0;
	for(int i = 1; i<=matrixSize; i++) {
		if(i%2 == 1) {
			for(int j = 1; j<=matrixSize-i && posString < stringLength; j++) {
				arr[pos_x][pos_y+j] = string[posString++];
			}
			pos_y += matrixSize-i;
			for(int j = 1; j<=matrixSize-i && posString < stringLength; j++) {
				arr[pos_x-j][pos_y] = string[posString++];
			}
			pos_x -= matrixSize-i;
		} else {
			for(int j = 1; j<=matrixSize-i && posString < stringLength; j++) {
				arr[pos_x][pos_y-j] = string[posString++];
			}
			pos_y -= matrixSize-i;
			for (int j = 1; j <= matrixSize - i && posString < stringLength; j++) {
				arr[pos_x + j][pos_y] = string[posString++];
			}
			pos_x += matrixSize-i;
		}
	}
	output = fopen("output.txt", "w");
	char *outputString = malloc(matrixSize*matrixSize);
	count = 0;
	for(int i = 0; i < matrixSize; i++) {
		for(int  j = 0; j < matrixSize; j++) {
			outputString[count] = arr[i][j];
			count++;
		}
	}
	fprintf(output, outputString);
	fclose(output);
	free(arr);
	return true;
}// function that encrypt your message


bool isMessageDecrypted() {
	FILE *message, *output;
	int count = 0;
	char *string;
	string = (char*)malloc(count * sizeof(char));
	char p;
	message = fopen("output.txt","r");
	while ( (p=fgetc(message) ) != EOF)
	{
		string[count] = p;
		count++;
	}
	fclose(message);
	int stringLength = strlen(string) - 1, posString = 0;
	const int matrixSize = ceil(sqrt(stringLength));
	char **arr;
	arr = (char**)malloc(matrixSize * sizeof(char*));
	for(int i = 0; i<matrixSize; i++) {
		arr[i] = (char*)malloc(matrixSize * sizeof(char));
		for(int  j = 0; j<matrixSize; j++) {
			arr[i][j] = ' ';
		}
	}
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++)
			arr[i][j] = string[posString++];
	}
	int pos_x = 0, pos_y = 0, rigthMargin = matrixSize - 1, topMargin = 0;
	count = 0;
	char *outputString = malloc(matrixSize*matrixSize);
	for (int i = 0; i < matrixSize * matrixSize; ++i) {
		outputString[count] = arr[pos_x][pos_y];
		count++;
		if ((pos_y == (topMargin + 1)) && (pos_x == topMargin)) {           //to middle
			rigthMargin--;
			topMargin++;
		}
		if ((pos_x == rigthMargin) && (pos_y < rigthMargin)) {            //to bottom
			pos_y++;
			continue;
		}
		if ((pos_x < rigthMargin) && (pos_y == topMargin)) {               //to right
			pos_x++;
			continue;
		}
		if ((pos_y == rigthMargin) && (pos_x > topMargin)) {               //to left
			pos_x--;
			continue;
		}
		if ((pos_x == topMargin) && (pos_y > topMargin)) {                  //to top
			pos_y--;
			continue;
		}
	}
	output = fopen("output.txt", "w");
	fprintf(output, outputString);
	fclose(output);
	free(arr);
	return true;
}// function that decrypt your message

