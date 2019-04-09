#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

struct globalArgs {
	char *dataStructureType;
	bool addFunction;
	bool findFunction;
	bool deleteFunction;
	bool showFunction;
} globalArgs;


static const char *optString = "suadflh";


bool taskPicker(struct globalArgs);
int numberInput();

int main(int argc, char** argv) {
	while (!(globalArgs.dataStructureType = malloc(100))) {
		return 1;
	}
	// default values
	globalArgs.addFunction = true;
	globalArgs.deleteFunction = false;
	globalArgs.findFunction = false;
	globalArgs.showFunction = true;
	int option;
	// end of default values
	option = getopt(argc, argv, optString);
	while (option != -1) {
		switch (option) {
			case 's':
				globalArgs.dataStructureType = "structure";
				break;
			case 'u':
				globalArgs.dataStructureType = "union";
				break;
			case 'a':
				globalArgs.addFunction = true;
				break;
			case 'l':
				globalArgs.showFunction = true;
				break;
			case 'd':
				globalArgs.deleteFunction = true;
				break;
			case 'f':
				globalArgs.findFunction = true;
				break;
			case 'h':
				printf("helpa");
				break;
			default:
				break;
		}
		option = getopt(argc, argv, optString);
	}
	taskPicker(globalArgs);
	return 0;
}

//functions
int numberInput() {
	int number;
	while (!(scanf("%d", &number))) {
		printf("Input error. Try again\n");
		rewind(stdin);
	}
	return number;
}// input for numbers


bool taskPicker(struct globalArgs args) {
	bool task = true;
	int taskNumber;
	printf("Enter your task to perform.\n");
	if (strcmp(globalArgs.dataStructureType, "structure")) {
		printf("Type of your data structure is union.\n");
	} else {
		printf("Type of your data structure is struct.\n");
	}
	if (globalArgs.addFunction) {
		printf("1. Add student.\n");
	}
	if (globalArgs.showFunction) {
		printf("2. Show list of students.\n");
	}
	if (globalArgs.findFunction) {
		printf("3. Find student.\n");
	}
	if (globalArgs.deleteFunction) {
		printf("4. Delete student.\n");
	}
	printf("5. Exit.");
	taskNumber = numberInput();
}// task picker function