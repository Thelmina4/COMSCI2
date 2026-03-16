#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Student */
typedef struct Student Student;

struct Student {
	char name[20];
	char programme[20];
	float grade;
	Student *next;   // add the type Student with Addess for next link
};

/*Functional prototype */
Student* get_students(); /* You may notice that the function get_students return the type Student*, implying that the function will return a pointer that points to a Student */
// 
int printStudentList(Student *start); /*to print the student list */

float meanGrade(Student *start);


int main()
{
	Student *start = NULL;

	start = get_students();
	printStudentList(start);
    float m = meanGrade(start);
    printf("Mean: %.2f\n", m);

	return 0;
}

Student* get_students() /* This mean that the function will return a pointer that points to the structure Student */
{
	Student *current, *first; /*declare two pointers */
	int selection; /* to ask if the user keep entering new student data or stop */


	first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	current = first; /*Now the current node is also the first node */
	// at the begining there is only 1 student, so current is first

	/*fill data for the first node */
	printf("Student name: \n");
	scanf("%s", current->name);
	printf("Programme: \n");
	scanf("%s", current->programme);
	printf("Grade: \n");
	scanf("%f",  &current->grade);  // grade is an int, so need "&"

	printf("Add more student? (1=Y, 0 = N): \n");
	scanf("%d", &selection);

	/*create the following nodes until the user select No */
	while(selection) //while selection is 1 (Yes)
	{
		/* allocate node and change the current point */
		current->next = (Student*)calloc(1, sizeof(Student));
		// at the beginning, there is no next, so we need to make the space for one more student
		current = current->next;

		/*fill the new node */
		printf("Student name: \n");
		scanf("%s", current->name);
		printf("Programme: \n");
		scanf("%s", current->programme);
		printf("Grade: \n");
		scanf("%f",  &current->grade);

		printf("Add more student? (1=Y, 0 = N): \n");
		scanf("%d", &selection);
	}
	// if the selection is 0, then you exit the loop and then finally the next node is NULL. 
	current->next = NULL; /* in case the last node */
	return first; /* return the address of the first node */
}

/* This is the function to display the list of the students. Pay attention on how we can iterate over all nodes in the linked list */

int printStudentList(Student *start)
{
	int count = 0;
    // initialise an empty student, like saying int i= 0;
	Student* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		++count;
		printf("Student #%d: ", count);
		printf("%s, %s, %d\n", p->name, p->programme, p->grade);
	}
}

float meanGrade(Student *start) {
    int count = 0;
    int sum = 0;
    Student  * p = NULL;
	for(p = start; p != NULL; p = p->next) {
        ++count;
        sum += p->grade;
    }
    return (float)sum/count;

}