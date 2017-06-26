#include<stdio.h>
#define SIZE 25 //DEFINE the size of the arrays

void addTicket(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[], int ticketType, int plateIndex);
int searchPlates(int Plates[], int plateNum);
void printCarHistory(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[], int plateIndex);
void printAllHistory(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[]);
int getPlateNum(void);
int validatePlateEntry(int Plates[]);

int main()
{
	int Plates[SIZE] = {
		102241,
		102242,
		992943,
		992944,
		112200,
		112201,
		112202,
		102203,
		102204,
		102205,
		102206,
		102207,
		102208,
		102209,
		102210,
		102211,
		102212,
		102213,
		102214,
		102215,
		102216,
		102217,
		102218,
		102219,
		102220 };

	int ParkingTicket[SIZE] =
	{
		10,
		4,
		20,
		8,
		10,
		4,
		20,
		2,
		5,
		10,
		11,
		22,
		0,
		0,
		1,
		2,
		4,
		6,
		8,
		9,
		21,
		13,
		4,
		4,
		34 };

	int DrunkTicket[SIZE] = {
		1,
		0,
		2,
		0,
		1,
		0,
		1,
		2,
		2,
		1,
		1,
		3,
		0,
		0,
		1,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		4 };

	int SpeedTicket[SIZE] = {
		3,
		0,
		7,
		2,
		3,
		0,
		7,
		3,
		3,
		3,
		2,
		8,
		0,
		0,
		3,
		2,
		2,
		2,
		1,
		1,
		2,
		2,
		1,
		1,
		22 };

	int ticketType; // Variable to select the type of ticket
	char commandSelect; // Variable to select the command to run
	int quit = 0; // Variable used to quit the program
	int plateIndex; // Variable to store the index of the corresponding License Plate number

	// Perform this main loop while the quit variable has not been set by the user
	while (quit == 0) {
		// Print the main screen prompt
		printf("P:\tAdding a parking ticket\n");
		printf("S:\tAdding a speeding ticket\n");
		printf("D:\tAdding a drunk driving ticket\n");
		printf("R:\tPrint history of a particular car\n");
		printf("A:\tPrint history of all cars\n");
		printf("Q:\tQuit the program\n");
		printf("----------------------------------------------\n");
		printf("Enter a Command: ");
		// Accept user input for the command
		scanf_s(" %c", &commandSelect, 1);
		// Validity check on the user input
		while (!(commandSelect == 'P' || commandSelect == 'S' || commandSelect == 'D' || commandSelect == 'R' || commandSelect == 'A' || commandSelect == 'Q' || commandSelect == 'p' || commandSelect == 's' || commandSelect == 'd' || commandSelect == 'r' || commandSelect == 'a' || commandSelect == 'q'))
		{
			printf("\nInvalid entry, please select based on the following:\n\n");
			printf("P:\tAdding a parking ticket\n");
			printf("S:\tAdding a speeding ticket\n");
			printf("D:\tAdding a drunk driving ticket\n");
			printf("R:\tPrint history of a particular car\n");
			printf("A:\tPrint history of all cars\n");
			printf("Q:\tQuit the program\n");
			printf("----------------------------------------------\n");
			printf("Enter a Command: ");
			scanf_s(" %c", &commandSelect, 1);
		}
		// Switch cases based on user input
		switch (commandSelect) {
		case 'P':
		case 'p': 
			ticketType = 1; // Ticket type 1 is Parking Ticket
			plateIndex = validatePlateEntry(Plates); // Get the license plate number
			if (plateIndex == -2) break; // If user inputs "0", exit to main menu
			addTicket(Plates, ParkingTicket, SpeedTicket, DrunkTicket, ticketType, plateIndex); // Add a parking ticket
			printf("Parking Ticket added succesfully!\n"); // Print success
			printCarHistory(Plates, ParkingTicket, SpeedTicket, DrunkTicket, plateIndex); // Print the updated history for that vehicle

			break;
		case 'S':
		case 's':
			ticketType = 2; // Ticket type 2 is Speeding Ticket
			plateIndex = validatePlateEntry(Plates); // Get the license plate number
			if (plateIndex == -2) break; // If user inputs "0", exit to main menu
			addTicket(Plates, ParkingTicket, SpeedTicket, DrunkTicket, ticketType, plateIndex); // Add a speeding ticket
			printf("Speeding Ticket added succesfully!\n"); // Print success
			printCarHistory(Plates, ParkingTicket, SpeedTicket, DrunkTicket, plateIndex); // Print the updated history for that vehicle
			break;
		case 'D':
		case 'd':
			ticketType = 3; // Ticket type 3 is Drunk Driving Ticket
			plateIndex = validatePlateEntry(Plates); // Get the license plate number
			if (plateIndex == -2) break; // If user inputs "0", exit to main menu
			addTicket(Plates, ParkingTicket, SpeedTicket, DrunkTicket, ticketType, plateIndex); // Add a drunk driving ticket
			printf("Drunk Driving Ticket added succesfully!\n"); // Print success 
			printCarHistory(Plates, ParkingTicket, SpeedTicket, DrunkTicket, plateIndex); // Print the updated history for that vehicle

			break;
		case 'R':
		case 'r':
			plateIndex = validatePlateEntry(Plates); // Get the license plate number
			if (plateIndex == -2) break; // If user inputs "0", exit to main menu
			printCarHistory(Plates, ParkingTicket, SpeedTicket, DrunkTicket, plateIndex); // Print the history for that vehicle
			break;
		case 'A':
		case 'a':
			printAllHistory(Plates, ParkingTicket, SpeedTicket, DrunkTicket); // Print the history of all vehicles
			break;
		case 'Q':
		case 'q':
			quit = 1; // Quit program
			break;
		}
	}
}
// Function addTicket -- increments the ticket counters
// Inputs: 4 initialization arrays, ticket type, and license plate index
// Output: Updated initialization array with incremented ticket value
void addTicket(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[], int ticketType, int plateIndex)
{
	switch (ticketType)
	{
	case 1:
		ParkingTicket[plateIndex] += 1; // If Parking ticket selected, increment by 1 for that vehicle
		break;
	case 2:
		SpeedTicket[plateIndex] += 1; // If Speeding ticket selected, increment by 1 for that vehicle
		break;
	case 3:
		DrunkTicket[plateIndex] += 1; // If Drunk driving ticket selected, increment by 1 for that vehicle
		break;
	}
	return;
}
// Function validatePlateEntry -- checks if the plate selected by user is valid
// Inputs: Plates array
// Output: Index of selected plate
int validatePlateEntry(int Plates[])
{
	int plateNum = getPlateNum();
	int plateIndex = searchPlates(Plates, plateNum);// Outputs -2 if plate is 0, -1 if plate not found
	while (plateIndex == -1 && plateNum != 0) // Iterate through loop until valid plate number or "0" is entered
	{
		plateNum = getPlateNum();
		plateIndex = searchPlates(Plates, plateNum);
	}
	if (plateNum == 0) // Set index to -2 so we can exit the case statement
		plateIndex = -2;
	return plateIndex;
}
// Function getPlateNum -- gets plate number from the user
// Inputs: None
// Output: Plate number as selected by the user
//**called by validatePlateEntry**
int getPlateNum(void) {
	int plateNum;
	printf("\n\nEnter a plate number (or 0 to return to Main Menu): ");
	scanf_s("%d", &plateNum); // User selects plate number
	while ((getchar()) != '\n');
	return plateNum;
}
// Function searchPlates -- find the index of the selected license plate 
// Inputs: list of license plates, selected license plate number
// Output: index of the selected plate 
//**called by validatePlateEntry**
int searchPlates(int Plates[], int plateNum)
{
	int plateIndex = -1;
	for (int i = 0; i < SIZE; i++)
	{
		if (Plates[i] == plateNum) { // Iterate through the Plates array until we find the index of the selected plate
			plateIndex = i;
			return plateIndex;
		}
		else if (plateNum == 0) // In case user enters "0", set index to -2 so we can exit the case statements
		{
			plateIndex = -2;
			return plateIndex;
		}
	}
	printf("Plate %d cannot be found, please enter a valid plate number.\n", plateNum); // If the plate is not found, output -1 so we can ask for another plate number
	return plateIndex;
}
// Function printCarHistory -- prints the data for a selected license plate
// Inputs: 4 initialization arrays, index of the selected license plate
// Output: Prints data for the selected plate
void printCarHistory(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[], int plateIndex)
{
	printf("\nThe plate number is:\t\t\t%d\n", Plates[plateIndex]); // Print selected plate data
	printf("Number of parking tickets:\t\t%d\n", ParkingTicket[plateIndex]);
	printf("Number of speed tickets:\t\t%d\n", SpeedTicket[plateIndex]);
	printf("Number of speed tickets:\t\t%d\n\n\n", DrunkTicket[plateIndex]);
	return;

}
// Function printAllHistory -- prints the data for all license plates
// Inputs: 4 initialization arrays
// Output: Prints data for all plates
void printAllHistory(int Plates[], int ParkingTicket[], int SpeedTicket[], int DrunkTicket[])
{
	printf("\n\nPlate\t\tNo of\t\tNo of\t\tNo of\n");
	printf("Number\t\tParking\t\tSpeeding\tDrinking\n");
	printf("---------------------------------------------------------\n");
	for (int i = 0; i < SIZE; i++) // Prints all data
	{
		printf("%d\t\t", Plates[i]);
		printf("%d\t\t", ParkingTicket[i]);
		printf("%d\t\t", SpeedTicket[i]);
		printf("%d\n", DrunkTicket[i]);
	}
	printf("\n\n");
		return;
}

