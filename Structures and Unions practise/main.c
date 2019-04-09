#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define consoleClear system("clear");


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
bool isStudentDeleted();
void delay(int);
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
		consoleClear
		printf("\nSuccess.\n");
		printf("Bye-Bye.\n");
		delay(250);
		return 0;
	} else {
		consoleClear
		printf("\nError.\n");
		delay(250);
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
	while (task) {
		delay(500);
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
		switch (taskNumber) {
			case 1:
				consoleClear
				if (isStudentAdded()) {
					printf("Success.\n");
				} else {
					printf("Error.\n");
					return false;
				}
				consoleClear
				break;
			case 2:
				consoleClear
				if (isListShowed()) {
					printf("Success.\n");
				} else {
					printf("Error.\n");
					return false;
				}
				consoleClear
				break;
			case 3:
				consoleClear
				if (isStudentFound()) {
					printf("Success.\n");
				} else {
					printf("Error.\n");
					return false;
				}
				consoleClear
				break;
			case 4:
				consoleClear
				if (isStudentDeleted()) {
					printf("Success.\n");
				} else {
					printf("Error.\n");
					return false;
				}
				consoleClear
				break;
			case 5:
				return true;
		}
	}
	return true;
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
	rewind(stdin);
	struct listItem* student = HEAD;
	while (student != NULL){
		printf("Student's first name: %s", student->studentData->firstName);
		printf("Student's second name: %s", student->studentData->secondName);
		printf("Student's middle name: %s", student->studentData->middleName);
		printf("---------------------------\n");
		student = student->nextElement;
	}
	printf("Press any key to continue.");
	getchar();
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


bool isStudentDeleted() {
	struct listItem* student = HEAD;
	struct listItem* backward = NULL;
	struct listItem* forward;
	char placeHolder = 'p',
			*nameForDelete;
	int textSize = 0;
	printf("\nEnter student's first name: ");
	while (!(nameForDelete = malloc(1))){
		return false;
	}
	rewind(stdin);
	while (placeHolder != '\n') {
		placeHolder = getchar();
		nameForDelete = realloc(nameForDelete, ++textSize);
		nameForDelete[textSize - 1] = placeHolder;
		nameForDelete[textSize] = '\0';
	}
	rewind(stdin);
	while (student != NULL) {
		if (!strcmp(student->studentData->firstName, nameForDelete)) {
			printf("deleting student: %s %s %s\n", student->studentData->firstName, student->studentData->secondName, student->studentData->middleName);
			if (backward == NULL){
				HEAD = student->nextElement;
			}
			else {
				backward->nextElement = student->nextElement;
			}
			forward = student->nextElement;
			free(student->studentData->firstName);
			free(student->studentData);
			free(student);
			student = forward;
		} else {
			backward = student;
			student = student->nextElement;
		}
	}
}


void delay(int number_of_seconds) {
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time
	clock_t start_time = clock();

	// looping till required time is not acheived
	while (clock() < start_time + milli_seconds);
} // delay function