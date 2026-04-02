#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Declare a structure of Student */
typedef struct Student Student;

struct Student {
	char name[20];
	char programme[20];
	float grade;
	Student *next;
	Student *prev;
};

/*Functional prototype */
Student* get_students(); /* You may notice that the function get_students return the type Student*, implying that the function will return a pointer that points to a Student */
void printStudentListInReverse(Student *last); /*to print the student list */
void deleteStudentByName(char* name, Student *first);

int main()
{
	Student *start = NULL;
	start = get_students();
	printStudentListInReverse(start);
	printStudentList(start);
    Student *first = NULL;
	printf("Student name to delete: \n");
    char a[100];
	scanf("%s", a);
    deleteStudentByName(a, first);
	printStudent(start);

	return 0;
}

Student* get_students() /* This mean that the function will return a pointer that points to the structure Student */
{
	Student *current, *first, *prev; /*declare two pointers */
	int selection; /* to ask if the user keep entering new student data or stop */


	first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	current = first; /*Now the current node is also the first node */

	/*fill data for the first node */
	printf("Student name: \n");
	scanf("%s", current->name);
	printf("Programme: \n");
	scanf("%s", current->programme);
	printf("Grade: \n");
	scanf("%f",  &current->grade);
	current->prev = NULL;

	printf("Add more student? (1=Y, 0 = N): \n");
	scanf("%d", &selection);

	/*create the following nodes until the user select No */
	while(selection) //while selection is 1 (Yes)
	{
		/* allocate the new node */
        // using calloc allows you to make a mistake in the data, 
        // eg. you forget to input the data for one of the points
        // if you dont input the data for something then you would get a random number back
        // but by using calloc, then it is initialised to 0
		current->next = (Student*)calloc(1, sizeof(Student));

		/*get the previous node before move the current pointer to the next */
		prev = current;

		/* move the current pointer to the next node */
		current = current->next;

		/*fill the new node */
		printf("Student name: \n");
		scanf("%s", current->name);
		printf("Programme: \n");
		scanf("%s", current->programme);
		printf("Grade: \n");
		scanf("%f",  &current->grade);
		current->prev = prev;

		printf("Add more student? (1=Y, 0 = N): \n");
		scanf("%d", &selection);
	}

	current->next = NULL; /* in case the last node */
	return current; /* return the address of the last node */
}

void printStudentListInReverse(Student *last)
{
	int count = 0;
	Student* p = NULL;
	for(p = last; p != NULL; p = p->prev)
	{
		++count;
		printf("Student #%d: ", count);
		printf("%s, %s, %.2f\n", p->name, p->programme, p->grade);
	}
}void printStudent(Student *first)
{
	int count = 0;
	Student* p = NULL;
	for(p = first; p != NULL; p = p->next)
	{
		++count;
		printf("Student #%d: ", count);
		printf("%s, %s, %.2f\n", p->name, p->programme, p->grade);
	}
}

void deleteStudentByName(char* name, Student *first)
{
	Student* p = first;
	Student *temp = NULL;

	for(p = first; p != NULL; p = p->next)
	{
		printf("Check %s ...\n", p->name );
		if(strcmp(p->name, name) == 0)
		{
			/* link the previous item with the next item */
			p->prev->next = p->next;
			p->next->prev = p->prev;
			temp = p->prev; /* this is used for marking the new position of p after delete the found item */
			free(p); /*delete the item */
			p = temp; /* new position of p */
		}
		/* then p will move to the next node from here before starting a new cycle */
	}

}