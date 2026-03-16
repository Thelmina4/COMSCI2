#include<stdio.h>
#include<stdlib.h>

typedef struct Player Player; //Define Player as a type name

struct Player //Structure type definition
{
	//Define struct members
  char name[30];
  int goal_scored;
  char position[2]; // only need 2 character to denote their pos on the field
  float price;
};

int main(int argc, char*argv[])
{
    // declare  a new vairable player1 with "type" Player
	Player player1; //Declare a variable type Player. This variable has no initial values assignes to the members of the struct.

	//Input a player
	printf("Player name:\n");
    // don't need &player1.name array as that would be the address. we have scanf and that is an address already
    // the array would be "Messi" or what ever their name is
	scanf("%s", player1.name); // Get an input from keyboard, store it to the struct member of the variable. Note that no need the operatore & because player1.name is already a pointer (to an array of character)

    // again this is an array, scanf is a pointer to the address, so no need to put in &
    // & would be looking for the address
	printf("Preferred position?\n");
	scanf("%s", player1.position);

    // need &player1 because we are using scanf to refer to a float
	printf("Market price:\n");
	scanf("%f", &player1.price); //We need & in this case because player1.price acts like a floating variable

    // need &player1.goal_scored as we are refering to the int value at the address
	printf("Goal scored:\n");
	scanf("%d", &player1.goal_scored);

	//Print a player by accessing to each members of the struct variable:
	printf("-------------------\n");
	printf("You have input the following player:\n");
	printf("Name: %s\n", player1.name);
	printf("Position: %s\n", player1.position);
	printf("Goal scored: %d\n", player1.goal_scored);
	printf("Market price: %.2f\n", player1.price);

	return 0;
}