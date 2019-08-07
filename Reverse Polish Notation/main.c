#include <stdio.h>
#include <stdlib.h>


struct stack {
	char symbol;
	struct stack *next;
};


struct stack *push(struct stack *, char);
char pop(struct stack **);
int priority(char);


int main() {
	struct stack *head = NULL;
	char *inputString,
		 *outputString,
		 placeHolder = 'p';
	int k, m, textSize = 0;
	do {
		puts("Enter your math operation: ");
		rewind(stdin);
		while (!(inputString = malloc(textSize))){
			return 1;
		}
		while (placeHolder != '\n'){
			placeHolder = getchar();
			inputString = realloc(inputString, ++textSize);
			inputString[textSize - 1] = placeHolder;
			inputString[textSize] = '\0';
		}
		while (!(outputString = malloc(textSize))){
			return 1;
		}
		k = m = 0;
		while (inputString[k] != '\0' && inputString[k] != '=') {
			if (inputString[k] == ')') {
				while ((head->symbol) != '(') {
					outputString[m++] = pop(&head);
				}
				pop(&head);
			}
			if (inputString[k] >= 'a' && inputString[k] <= 'z' || inputString[k] >= 'A' && inputString[k] <= 'Z') {
				outputString[m++] = inputString[k];
			}
			if (inputString[k] == '(') {
				head = push(head, '(');
			}
			if (inputString[k] == '+' || inputString[k] == '-' || inputString[k] == '/' || inputString[k] == '*') {
				while ((head != NULL) && (priority(head->symbol) >= priority(inputString[k]))) {
					outputString[m++] = pop(&head);
				}
				head = push(head, inputString[k]);
			}
			k++;
		}
		while (head) {
			outputString[m++] = pop(&head);
		}
		outputString[m] = '\0';
		printf("\n%s\n", outputString);
		rewind(stdin);
		puts("\nRepeat(y/n)?");
	} while (getchar() != 'n');
}


struct stack *push(struct stack *head, char a) {
	struct stack *pointer;
	if (!(pointer = (struct stack *)malloc(sizeof(struct stack)))) {
		puts("Нет памяти.");
		exit(1);
	}
	pointer->symbol = a;
	pointer->next = head;
	return pointer;
}


char pop(struct stack **head) {
	struct stack *pointer;
	char a;
	if (!(*head)) {
		return '\0';
	}
	pointer = *head;
	a = pointer->symbol;
	*head = pointer->next;
	free(pointer);
	return a;
}


int priority(char a) {
	switch (a) {
		case '*':case '/': return 3;
		case '-':case '+': return 2;
		case '(': return 1;
	}
	return 0;
}