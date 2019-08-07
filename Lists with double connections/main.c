#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct list {
	char* movie;
	struct list* previous;
	struct list* next;
};
void menu();
int select();
bool addElementToEndOfList(struct list **, struct list **);
void showList(struct list **);
bool addElementToBeginningOfList(struct list **, struct list **);
int numberOfElementsOfAList(struct list **);
bool emptyList(struct list **);
bool deletingFirstElement(struct list **, struct list**);
bool deletingLastelement(struct list **, struct list **);
bool deletingAllElements(struct list**, struct list **);
bool enteringString(char**);
bool searchElementOfAList(struct list**, struct list **, char*);
bool deletingNeededElement(struct list**, struct list **, char*);
bool deletingAllNeededElements(struct list**, struct list **, char*);
bool changingNeededElements(struct list**, struct list **, char*,char*);
bool findBiggestElement(struct list**, struct list **);
bool findLowestElement(struct list**, struct list **);
bool reverseElements(struct list**, struct list **);
int main() {
	struct list *head=NULL, *tail=NULL;
	int numberofelements = 0, selection = 0;
	char*string=NULL, *newstring = NULL;
	menu();
	selection=select();
	do {
		switch (selection) {
			case 1:
				printf("\nEnter List:");
				if (!addElementToEndOfList(&head, &tail)) {
					return 0;
				}
				menu();
				selection = select();
				break;
			case 2:
				printf("\nEnter List:");
				if (!addElementToBeginningOfList(&head, &tail)) {
					return 0;
				}
				menu();
				selection = select();
				break;
			case 3:
				showList(&head);
				menu();
				selection = select();
				break;
			case 4:
				if (!deletingFirstElement(&head, &tail)) {
					selection = 1;
					break;
				}
				printf("\nElement has been deleted\n");
				menu();
				selection = select();
				break;
			case 5:
				if (!deletingLastelement(&head, &tail)) {
					selection = 1;
					break;
				}
				printf("\nElement has been deleted\n");
				menu();
				selection = select();
				break;
			case 6:
				if (!deletingAllElements(&head, &tail)) {
					selection = 1;
					break;
				}
				menu();
				selection = select();
				break;
			case 7:
				if (emptyList(&head)) {
					printf("\nList is empty\n");
				} else{ printf("\nList is not empty\n"); }
				menu();
				selection = select();
				break;
			case 8:
				numberofelements = numberOfElementsOfAList(&head);
				printf("\nnumber of elements is %d\n", numberofelements);
				menu();
				selection = select();
				break;
			case 9:
				if (emptyList(&head)){
					printf("\nList is empty\n");
					selection = 1;
					break;
				}
				if (!enteringString(&string)) {
					return 0;
				}
				if (!searchElementOfAList(&head, &tail,string)) {
					printf("\nElement has not been found\n");
				}
				menu();
				selection = select();
				break;
			case 10:
				if (emptyList(&head)) {
					printf("\nList is empty\n");
					selection = 1;
					break;
				}
				if (!enteringString(&string)) {
					return 0;
				}

				if (!deletingNeededElement(&head, &tail,string)) {
					printf("\nNeeded element has not been found\n");
				}
				menu();
				selection = select();
				break;
			case 11:
				if (emptyList(&head)) {
					selection = 1;
					break;
				}
				if (!enteringString(&string)) {
					return 0;
				}

				if (!deletingAllNeededElements(&head, &tail, string)) {
					printf("\nNeeded element has not been found\n");
				}
				menu();
				selection = select();
				break;
			case 12:
				if (emptyList(&head)) {
					selection = 1;
					break;
				}
				printf("\nEnter old title:");
				if (!enteringString(&string)) {
					return 0;
				}
				printf("\nEnter new title:");
				if (!enteringString(&newstring)) {
					return 0;
				}
				if (!changingNeededElements(&head, &tail, string,newstring)) {
					return 0;
				} else { printf("\nList has been changed\n"); }
				menu();
				selection = select();
				break;
			case 13:
				if (!findBiggestElement(&head, &tail)) {
					selection = 1;
					break;
				}
				menu();
				selection = select();
				break;
			case 14:
				if (!findLowestElement(&head, &tail)) {
					selection = 1;
					break;
				}
				menu();
				selection = select();
				break;
			case 15:
				if (emptyList(&head)) {
					selection = 1;
					break;
				}
				if (!reverseElements(&head, &tail)) {
					return 0;
				}
				menu();
				selection = select();
				break;
		}
	} while (selection != 16);
	return 0;
}
void menu() {
	printf("\n");
	printf("1. Enter element to the end of a list\n"
		   "2. Enter element to the beginning of a list\n"
		   "3. Show list\n"
		   "4. Delete first element of a list\n"
		   "5. Delete last element  of a list\n"
		   "6. Delete all elements of a list\n"
		   "7. Check list for emptiness\n"
		   "8. Number of elements of a list\n"
		   "9. Find needed element of a list\n"
		   "10. Delete needed element of a list\n"
		   "11. Delete all needed elements of a list\n"
		   "12. Change title of needed elements of a list\n"
		   "13. Find the biggest element\n"
		   "14. Find the lowest element\n"
		   "15. Reverse order of elements.\n"
		   "16. exit\n"
		   "select:");
}
int select() {
	rewind(stdin);
	int i;
	do {
		while (!scanf("%d", &i)) {
			rewind(stdin);
		}
	} while (i<1 || i>16);
	rewind(stdin);
	return i;
}
bool addElementToEndOfList(struct list **head, struct list **tail) {
	struct list *temp;
	int i;
	do
	{
		if (!(temp = (struct list *)calloc(1, sizeof(struct list)))) {
			printf("not enough memory");
			return false;
		}
		if (!enteringString(&temp->movie)) {
			return false;
		}
		if (!*tail || !*head) {
			*tail = *head = temp;
		}
		else {
			(*tail)->next = temp;
			temp->previous = *tail;

			(*tail) = temp;
		}
		printf("\n1)add one more element");
		printf("\n2)exit\n");
		rewind(stdin);
		do {
			while (!scanf("%d", &i)) {
				rewind(stdin);
			}
		} while (i<1 || i>2);
	} while (i != 2);
	return true;
}
void showList(struct list **head) {
	struct list *temp;
	if (!*head) { printf("\nList is empty\n"); }
	temp = *head;
	while (temp) {
		printf("%s\n", temp->movie);
		temp = temp->next;
	}
}
bool addElementToBeginningOfList(struct list **head, struct list **tail) {
	struct list *temp;
	int i;
	do
	{
		if (!(temp = (struct list *)calloc(1, sizeof(struct list)))) {
			printf("not enough memory");
			return false;
		}
		if (!enteringString(&temp->movie)) {
			return false;
		}
		if (!*tail || !*head) {
			*tail = *head = temp;
		}
		else {
			(*head)->previous = temp;
			temp->next = *head;
			(*head) = temp;
		}
		printf("\n1)add one more element");
		printf("\n2)exit\n");
		rewind(stdin);
		do {
			while (!scanf("%d", &i)) {
				rewind(stdin);
			}
		} while (i<1 || i>2);
	} while (i != 2);
	return true;
}
int  numberOfElementsOfAList(struct list **head) {
	int number=0;
	struct list *temp;
	temp = *head;
	while (temp) {
		number++;
		temp = temp->next;
	}
	return number;
}
bool emptyList(struct list **head) {
	if (*head == NULL) {
		return true;
	} else {
		return false;
	}
}
bool deletingFirstElement(struct list **head, struct list**tail) {
	struct list* temp;
	if (!*head) {
		printf("\nList is empty\n");
		return false;
	}
	if (*tail == *head) {
		free(*tail);
		*head = *tail = NULL;
		printf("\nList has been become empty\n");
		return true;
	}
	temp = *head;
	(*head) = (*head)->next;
	(*head)->previous=NULL;
	free(temp);
	return true;
}
bool deletingLastelement(struct list**head, struct list **tail) {
	struct list* temp;
	if (!*tail) {
		printf("\nList is empty\n");
		return false;
	}
	if (*tail==*head) {
		free(*tail);
		*head = *tail = NULL;
		printf("\nList has been become empty\n");
		return true;
	}
	temp = *tail;
	(*tail) = (*tail)->previous;
	(*tail)->next = NULL;
	free(temp);
	return true;
}
bool deletingAllElements(struct list**head, struct list **tail) {
	struct list*temp;
	if (!*head) {
		printf("\nList is empty\n");
		return false;
	}
	while (*head){
		if (*tail == *head) {
			free(*tail);
			*head = *tail = NULL;
			printf("\nList has been become empty\n");
			return true;
		}
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
	return true;
}
bool enteringString(char** newstring) {
	char*string;
	printf("\nenter title of a movie:");
	if (!(string = (char*)calloc(1, sizeof(char)))) {
		printf("not enough memory");
		return false;
	}
	int k = 0;
	rewind(stdin);
	while (1) {
		string[k++] = (char)getchar();
		if (string[0] == '\n' || string[0] == ' ') { k = 0; continue; }
		if (string[k - 1] == ' ' && string[k - 2] == ' ') {
			string[k - 2] = '\0';
			break;
		}
		if (string[k - 2] == ' ' && string[k - 1] == '\n') {
			string[k - 2] = '\0';
			break;
		}
		if (string[k - 1] == '\n') {
			string[k - 1] = '\0';
			break;
		}
		if (!(string = (char*)realloc(string, k + 1))) {
			printf("not enough memory");
			return false;
		}
	}
	*newstring = string;
	rewind(stdin);
	return true;
}
bool searchElementOfAList(struct list** head, struct list** tail, char* string) {
	struct list* temp;
	temp = *head;
	while (temp) {
		if (strcmp(string, temp->movie) == 0) {
			printf("\nElement has been founded\n");
			return true;
		}
		temp = temp->next;
	}
	return false;
}
bool deletingNeededElement(struct list** head, struct list **tail, char *string) {
	struct list* temp;
	temp = *head;
	while (temp) {
		if (strcmp(string, temp->movie) == 0) {
			if (*head == *tail) {
				free(temp);
				*head = *tail = NULL;
				printf("\nNeeded element has been deleted\n");
				printf("\nList is empty\n");
				return true;
			}
			if (temp ==*head) {
				temp->next->previous = NULL;
				*head = temp->next;
				free(temp);
				printf("\nNeeded element has been deleted\n");
				return true;
			}
			if (temp == *tail) {
				temp->previous->next = NULL;
				*tail = temp->previous;
				free(temp);
				printf("\nNeeded element has been deleted\n");
				return true;
			}
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			free(temp);
			printf("\nNeeded element has been deleted\n");
			return true;
		}
		temp = temp->next;
	}
	return false;
}
bool deletingAllNeededElements(struct list**head, struct list **tail, char*string) {
	struct list*temp, *deletingelement;
	temp = *head;
	int flag = 0,secondflag=0;
	while (temp) {
		flag = 0;
		if (strcmp(string, temp->movie) == 0) {
			if (*head == *tail) {
				free(temp);
				*head = *tail = NULL;
				printf("\nNeeded elements has been deleted\n");
				printf("\nList is empty\n");
				return true;
			}
			deletingelement = temp;
			if (temp->previous == NULL) {
				temp->next->previous = NULL;
				*head=temp=temp->next;
				free(deletingelement);
				secondflag = 1;
				flag = 1;
			}
			if (temp->next == NULL && flag==0) {
				temp->previous->next = NULL;
				*tail = temp->previous;
				free(deletingelement);
				printf("\nNeeded elements has been deleted\n");
				return true;
			}
			if (flag == 0) {
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				temp = temp->next;
				free(deletingelement);
				secondflag = 1;
			}
		} else { temp = temp->next; }

	}
	if (secondflag == 0) {
		return false;
	} else {
		printf("\nNeeded elements has been deleted\n");
		return true;
	}
}
bool changingNeededElements(struct list**head, struct list **tail, char*string, char*newstring) {
	struct list*temp;
	temp = *head;
	while (temp) {
		if (strcmp(string, temp->movie) == 0) {
			if (!(temp->movie = (char*)realloc(temp->movie, strlen(newstring)))){
				printf("\nNot enough memory\n");
				return false;
			}
			strcpy(temp->movie, newstring);
		}
		temp = temp->next;
	}
	return true;
}
bool findBiggestElement(struct list**head, struct list **tail) {
	struct list*temp,*neededtemp;
	temp = neededtemp=*head;
	if (!*head) {
		printf("\nList is empty\n");
		return false;
	}
	while (temp) {
		if (strcmp(neededtemp->movie, temp->movie) < 0) {
			neededtemp = temp;
		}
		temp = temp->next;
	}
	printf("The biggest element is %s\n", neededtemp->movie);
	return true;
}
bool findLowestElement(struct list**head, struct list **tail) {
	struct list*temp, *neededtemp;
	temp = neededtemp = *head;
	if (!*head) {
		printf("\nList is empty\n");
		return false;
	}
	while (temp) {
		if (strcmp(neededtemp->movie, temp->movie) > 0) {
			neededtemp = temp;
		}
		temp = temp->next;
	}
	printf("The lowest element is %s\n", neededtemp->movie);
	return true;
}
bool reverseElements(struct list**head, struct list **tail) {
	struct list*firsttemp, *secondtemp;
	int number = 0, i = 0;
	char*string=NULL;
	firsttemp=*head;
	secondtemp = *tail;
	number = numberOfElementsOfAList(head);
	while (i < number / 2) {
		if (!(string = (char*)realloc(string, strlen(firsttemp->movie)))) {
			printf("\nNot enough memory\n");
			return false;
		}
		strcpy(string, firsttemp->movie);
		if (!(firsttemp->movie = (char*)realloc(firsttemp->movie, strlen(secondtemp->movie)))) {
			printf("\nNot enough memory\n");
			return false;
		}
		strcpy(firsttemp->movie, secondtemp->movie);
		if (!(secondtemp->movie = (char*)realloc(secondtemp->movie, strlen(string)))) {
			printf("\nNot enough memory\n");
			return false;
		}
		strcpy(secondtemp->movie, string);
		i++;
		firsttemp = firsttemp->next;
		secondtemp = secondtemp->previous;
	}
	printf("\nList has been reversed\n");
	return true;
}