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


struct student {
	char* firstName;
	char* middleName;
	char* secondName;
	union studentSiblings* siblings;
};


struct listItem {
	struct student* studentData;
	struct listItem* nextElement;
} *HEAD = NULL;


union studentSiblings {
	char* studentFather;
	char* studentMother;
	char* studentBrother;
};


//start of functions definition
bool taskPicker(struct globalArgs);
int numberInput();
bool isStudentAdded();
bool isListShowed();
bool isStudentFound();
//end of functions definition


int main(int argc, char** argv) {
	system("clear");
	// default values
	globalArgs.dataStructureType =  malloc(1);
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
				while (!(globalArgs.dataStructureType = malloc(10))) {
					return 1;
				}
				globalArgs.dataStructureType = "structure";
				break;
			case 'u':
				while (!(globalArgs.dataStructureType = malloc(6))) {
					return 1;
				}
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
				printf("These are common console arguments used in various situations:\n"
					   "   -s        [data structure type] Struct\n"
					   "   -u        [data structure type] Union\n"
					   "   -a        Add students function\n"
					   "   -l        Show all students function\n"
					   "   -d        Delete student function\n"
					   "   -f        Find student function\n");
				return 0;
			default:
				break;
		}
		option = getopt(argc, argv, optString);
	}
	if (taskPicker(globalArgs)) {
		system("clear");
		printf("\nSuccess.\n");
		printf("Bye-Bye.\n");
		return 0;
	} else {
		system("clear");
		printf("\nError.\n");
		return 1;
	}
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
	printf("5. Exit.\n");
	printf("Enter your task to perform: ");
	taskNumber = numberInput();
}// task picker function


bool isStudentAdded() {
	struct student* student;
	struct listItem* instance;
	int textSize = 0;
	char placeHolder = 'p';
	if (!(student = malloc(sizeof(struct student)))){
		return false;
	}
	if (!(instance = malloc(sizeof(struct listItem)))){
		return false;
	}
	instance->studentData = student;
	instance->nextElement = HEAD;
	HEAD = instance;
	rewind(stdin);
	printf("\nEnter student's first name: ");
	while (!(student->firstName = malloc(textSize))){
		return false;
	}
	while (placeHolder != '\n'){
		placeHolder = getchar();
		student->firstName = realloc(student->firstName, ++textSize);
		student->firstName[textSize - 1] = placeHolder;
		student->firstName[textSize] = '\0';
	}
	rewind(stdin);
	placeHolder = 'p';
	textSize = 0;
	printf("\nEnter student's second name: ");
	while (!(student->secondName = malloc(textSize))){
		return false;
	}
	while (placeHolder != '\n'){
		placeHolder = getchar();
		student->secondName = realloc(student->secondName, ++textSize);
		student->secondName[textSize - 1] = placeHolder;
		student->secondName[textSize] = '\0';
	}
	rewind(stdin);
	placeHolder = 'p';
	textSize = 0;
	printf("\nEnter student's middle name: ");
	while (!(student->middleName = malloc(textSize))){
		return false;
	}
	while (placeHolder != '\n'){
		placeHolder = getchar();
		student->middleName = realloc(student->middleName, ++textSize);
		student->middleName[textSize - 1] = placeHolder;
		student->middleName[textSize] = '\0';
	}
	rewind(stdin);
	return true;
}// function that add student to the list


bool isListShowed() {
	struct listItem* student = HEAD;
	while (student != NULL){
		printf("Student's first name: %s", student->studentData->firstName);
		printf("Student's second name: %s", student->studentData->secondName);
		printf("Student's middle name: %s", student->studentData->middleName);
		printf("---------------------------\n");
		student = student->nextElement;
	}
	return true;
}// function that show list of students


bool isStudentFound() {
	system("clear");
	struct listItem* student = HEAD;
	char placeHolder = 'p',
		*secondNameForSearch;
	int textSize = 0;
	printf("\nEnter student's second name: ");
	while (!(secondNameForSearch = malloc(1))){
		return false;
	}
	rewind(stdin);
	while (placeHolder != '\n'){
		placeHolder = getchar();
		secondNameForSearch = realloc(secondNameForSearch, ++textSize);
		secondNameForSearch[textSize - 1] = placeHolder;
		secondNameForSearch[textSize] = '\0';
	}
	rewind(stdin);
	while (student != NULL){
		if (!strcmp(student->studentData->secondName, secondNameForSearch)){
			printf("Student's first name: %s", student->studentData->firstName);
			printf("Student's second name: %s", student->studentData->secondName);
			printf("Student's middle name: %s", student->studentData->middleName);
			printf("---------------------------\n");
		}
		student = student->nextElement;
	}
}