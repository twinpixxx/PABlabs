#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>


struct globalArgs {
	bool encryptTask;
	bool decryptTask;
} globalArgs;


static const char *optString = "edh";

//start of functions definition
int numberInput();
//end of functions definition


int main(int argc, char** argv) {
	// default values
	globalArgs.encryptTask = false;
	globalArgs.decryptTask = false;
	// end of default values
	int option;
	if (argc > 1) {
		option = getopt(argc, argv, optString);
		while (option != -1) {
			switch (option) {
				case 'e':
					globalArgs.encryptTask = true;
					break;
				case 'd':
					globalArgs.decryptTask = true;
					break;
				case 'h':
					printf("These are common console arguments used in various situations:\n"
						   "   -e        Encrypt your message\n"
						   "   -d        Decrypt your message\n"
						   "   -e/-d <file path>        Encrypt/Decrypt file in different directory\n");
					return 0;
				default:
					break;
			}
			option = getopt(argc, argv, optString);
		}
	} else {
		int taskNumber;
		printf("1. Encrypt Message\n"
		       "2. Decrypt Message\n");
		printf("Enter task number: ");
		taskNumber = numberInput();
		switch (taskNumber) {
		}
	}
	return 0;
}