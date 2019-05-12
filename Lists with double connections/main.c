#include <stdio.h>

struct cars {
	char* carModelName;
	int* carPower;
	struct cars* nextCar;
	struct cars* previousCar;
}; //cars structure


int main() {
	printf("Hello, World!\n");
	return 0;
}