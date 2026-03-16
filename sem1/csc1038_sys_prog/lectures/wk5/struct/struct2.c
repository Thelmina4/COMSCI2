#include<stdio.h>
#include<stdlib.h>

typedef struct Player Player; //Define Player as a type name

struct Player //Structure type definition
{
  char name[30];
  int goal_scored;
  char position[5];
  float price;
};

int main(int argc, char*argv[])
{

	Player player[50]; //Declare a variable type Player. This variable has no initial values assignes to the members of the struct.

	//Input a player
	int pcount = 0; //to count the player
	int selection; //This is to store the decision of the user if he/she wants to add more player
	
    // do while loop
    do
	{
		printf("Player name:\n");
		scanf("%s", player[pcount].name); //Get an input from keyboard, store it to the struct member of the variable. Note that no need the operatore & because player1.name is already a pointer (to an array of character)

		printf("Preferred position:\n");
		scanf("%s", player[pcount].position);

		printf("Market price:\n");
		scanf("%f", &player[pcount].price); //We need & in this case because player1.price acts like a floating variable

		printf("Goal scored:\n");
		scanf("%d", &player[pcount].goal_scored);

		++pcount; //Increase the player count variable by 1;

		printf("Do you want to add more player (1 = Y, 0 = N)?\n");
        // selection is an interger, so put in the &
		scanf("%d", &selection);

		if(selection == 0)
			break;

	} while (selection == 1) && (count <= 50);

	//Print all players:
	printf("-------------------\n");
	printf("You have input the following players:\n");

	for(int i = 0; i < pcount; ++i)
	{
		printf("Player %d:\n", i+1); //Just a signal
		printf("Name: %s\n", player[i].name);
		printf("Position: %s\n", player[i].position);
		printf("Goal scored: %d\n", player[i].goal_scored);
		printf("Market price: %.2f\n", player[i].price);
		printf("\n");
	}

	return 0;
}