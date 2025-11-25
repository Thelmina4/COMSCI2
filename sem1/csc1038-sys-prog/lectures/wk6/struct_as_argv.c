#include<string.h>
#include<stdio.h>


typedef struct Player Player;
typedef struct Date Date;
typedef struct Name Name;
typedef struct DOB DOB;

struct DOB
{
	int day;
	int month;
	int year;
};

struct Name
{
	char firstName[30];
	char lastName[30];
};


struct Player //Structure type definition
{
  Name name;   //the member name is an instance of the structure Name
  int goal_scored;
  char position[5];
  float price;
  DOB date_of_birth;  //the member date_of_birth is an instance of the structure DOB
};

/*function prototype*/
int countGoal(Player p1, Player p2);
int countGoalWithPointers(Player *p1, Player *p2);
Player addPlayer();

int main()
{
	Player p1, p2, p3;
	int goals = 0;
    int goalsp = 0;

    p3 = addPlayer();

	/* fill data for p1 */
	strcpy(p1.name.firstName, "Cristiano");
	strcpy(p1.name.lastName, "Ronaldo");
	p1.goal_scored = 500;

	/*fill data for p2 */
	strcpy(p2.name.firstName, "Lionel");
	strcpy(p2.name.lastName, "Messi");
	p2.goal_scored = 501;

	/* call the function to calculate the total of goals */
	goals = countGoal(p1, p2);
    printf("Goals: %d\n", goals);

    goalsp = countGoalWithPointers(&p1, &p2);

    printf("Goals w pointers: %d\n", goalsp);
    
	return 0;
}

int countGoal(Player p1, Player p2)
{
	return p1.goal_scored + p2.goal_scored;
}

int countGoalWithPointers(Player *p1, Player *p2)
{
	return p1->goal_scored + p2->goal_scored;
}

//  no input as we are asking the user for the input
Player addPlayer()
{
	// Initialize the player
    Player p;
	printf("First name:\n");
    // this is an array of char, so not need for the &
	scanf("%s", p.name.firstName);

	printf("Last name:\n");
	scanf("%s", p.name.lastName);

    // goals_scored are an int, so I need to use the reference operator
    // &
	printf("Goal scored:\n");
	scanf("%d", &p.goal_scored);

    // array, no need for &
	printf("Preferred position:\n");
	scanf("%s", p.position);

	printf("Market price:\n");
	scanf("%f", &p.price);

	printf("Date of birth:\n");
    // can make the user input a certain format
    // DD/MM/YYYY
    // so the / inbetween the %d's
    // can use another function to check the formatting, make sure that the user input the correct data
	scanf("%d/%d/%d",&p.date_of_birth.day,&p.date_of_birth.month,&p.date_of_birth.year);

	return p;
}