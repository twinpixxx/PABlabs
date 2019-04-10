## Structures and unions practise task

### Task description:

> Two signs are set in the command line. The first attribute determines the type of information entered: simply a structure or structure that includes the union and the names of the functions that need to be performed. Functions output information (from a simple structure or from a structure that includes the union), depending on the second feature in the command line. The structures store information about students: last name, first name, middle name. In an association, the structure stores one of the types of information: father, mother, brother;

### Functions list:

~~~c
int numberInput();
bool taskPicker(struct globalArgs);
bool isStudentAdded(struct globalArgs args, bool);
bool isListShowed();
bool isStudentFound();
bool isStudentDeleted();
void delay(int);
/* bool functions were imperative */
~~~

### Structions list:

##### Task structures:

~~~c
/* main structure with basic information about student */
struct student {
	char* firstName;
	char* middleName;
	char* secondName;
	union studentSiblings* siblings;
};

/* additional union with information about student's siblings */
union studentSiblings {
	char* studentFather;
	char* studentMother;
	char* studentBrother;
};


/* implementation of the list */
struct listItem {
	struct student* studentData;
	struct listItem* nextElement;
} *HEAD = NULL; 
~~~

##### Special structures:

~~~c
/* structure with global arguments, that help us to work with command line arguments */
struct globalArgs {
	char* dataStructureType;
	bool addFunction;
	bool findFunction;
	bool deleteFunction;
	bool showFunction;
	char* sibling;
} globalArgs;
~~~



### How does arguments parser works:

> Program can work with such arguments as:
>
> ​	-a — add student
>
> ​	-l — show list of students
>
> ​	-f — search student
>
> ​	-d — delete student
>
> ​	-h — help menu

~~~c
	/* arguments to work with */
	static const char *optString = "suadfdlh";

	/* code for parse command line arguments */
	/* using getopt() from unistd.h */
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
~~~

