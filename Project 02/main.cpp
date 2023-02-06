/*
Title: Project 02: 
Class: Computer Science I
Author: Cole Barach
Date Created: 22.11.24
*/

// Library Includes ---------------------------------------------------------------------------------------
#include <iostream>
using std::cout;
using std::cin;

#include <iomanip>
using std::ios;
using std::setw;
using std::setfill;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <limits>

// Constants
const int FLOOR_COUNT = 5; // Total Number of Floors in Building
const int ROOM_COUNT  = 8; // Number of Rooms per Floor

const int DISPLAY_WIDTH   = 104; // Width of Console Display
const int WIDTH_ROOM_NAME = 10;  // Width of Printed Room Names

// Data Types
enum RoomState          // Room State Data Type
{
	VACANT        = 0,  // Room is empty, Can be occupied
	CHECKOUT      = 1,  // Patient is checking out, room can be emptied
	OCCUPIED      = 2,  // Room is occupied
	NURSE_STATION = 3,  // Room cannot be occupied
	TRANSFER      = 4,  // Patient is moving to another room
	UTILITY_ROOM  = 5   // Room cannot be occupied
};

enum InputType          // Input Data Type
{
	I_OCCUPY     = 'O', // Occupy a Room
	I_CHECKOUT   = 'C', // Mark Room for Checkout
	I_TRANSFER   = 'T', // Mark Room for Transfer
	I_VACANT     = 'V', // Vacate a Room
	I_MAP        = 'M', // Display Map
	I_QUIT_S     = 'S', // Save & Quit
	I_QUIT_NS    = 'Q'  // Quit
};
const string INPUT_OPTIONS = "OCTVMSQ";

// Read Room States
// - Call to Read the Room States from given Input Stream
// - Loads Stream Data into the Room States Matrix
void ReadRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], fstream &input);
// Print Room States
// - Call to Print the Room States Data
// - Prints the Room States Matrix to Standard Output Stream
void PrintRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Write Room States
// - Call to Write the Room States Data
// - Writes the Room States Matrix to the given Output Stream
void WriteRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], fstream &output);

// Handle Rooms
// - Call to Handle any Pending operations on rooms
// - Handles Checkouts and Transfers sequentially
void HandleRooms(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Handle Checkouts
// - Call to Handle any Checkout in the Room States
// - Removes Checked Out Patients from Room States
void HandleCheckouts(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Handle Transfers
// - Call to Handle any Transfers in the Room States
// - Moves Transfer Patients to a vacant Room if possible
void HandleTransfers(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);

// Prompt Input
// - Call to Prompt User Input
// - Prints Options to Console
void PromptInput();
// Read User Input
// - Call to Prompt and Get Input from the User
// - Assigns the input to selection
void ReadInput(InputType &selection);
// Handle Input
// - Call to Handle input from the user
// - Calls Appropriate Handler Functions
void HandleInput(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], InputType selection, bool &continueLoop, bool &save);
// Verify Input
// - Call to Verify User Input
// - Returns true for valid input, false otherwise
bool VerifyInput(char selectionId, string options);

// Handle Input Occupy
// - Call to Handle Occupy Input
// - Allows user to Occupy selected Room 
void HandleInputOccupy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Handle Input Checkout
// - Call to Handle Checkout Input
// - Allows user to Checkout selected Room
void HandleInputCheckout(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Handle Input Transer
// - Call to Handle Transfer Input
// - Allows user to Transfer selected Room
void HandleInputTransfer(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);
// Handle Input Vacant
// - Call to Handle Vacant Input
// - Allows user to Vacate selected Room
void HandleInputVacant(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT]);

// Find Vacancy
// - Call to Find a Vacant Room, use target floor to specify a desired location
// - Assigns vacancy position to vacantRoom and vacantFloor. Returns false if no room is found.
bool FindVacancy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], int targetFloor, int &vacantRoom, int &vacantFloor);
bool FindVacancy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], int &vacantRoom, int &vacantFloor);

// Prompt Input File Stream
// - Call to Prompt the Opening of an input file stream
// - Opens the appropriate stream, returning the name of the file
string PromptInputFileStream(fstream &file);
// Prompt Output File Stream
// - Call to Prompt the Opening of an output file stream
// - Opens the appropriate stream, returning the name of the file
string PromptOutputFileStream(fstream &file);

// Print Centered
// - Call to print text with center justification
// - Prints to cout the centered text
void PrintCentered(string message, int width);
// Split
// - Call to split a message in half about an index.
// - Writes to the left and right strings
void Split(string message, int index, string &left, string &right);

// Input Integer
// - Call to generic integer input
// - Returns verified input
int InputInt(                string error);
int InputInt(int lowerBound, string error);
int InputInt(                string error, int upperBound);
int InputInt(int lowerBound, string error, int upperBound);
// Print Input Error
// - Called when invalid data is input
// - Notifies the user and clears the stream
void PrintInputError(string error);

// Main Program -------------------------------------------------------------------------------------------
int main()
{
    // Program Header
	cout << "Title: Project 02: Bed Assignments"                        << endl;
	cout << "Class: Computer Science I"									<< endl;
	cout << "Author: Cole Barach"										<< endl;
	cout << "Date Created: 22.11.24"									<< endl;
    cout << endl;

	// Variable Declarations
	RoomState roomStates[ROOM_COUNT][FLOOR_COUNT];

	// Stream Initialization
	cout << "Select an input file." << endl;
	fstream input;
	PromptInputFileStream(input);

	// Load Data
	ReadRoomStates(roomStates, input);
	input.close();

	// Display Loaded Data
	cout << endl;
	PrintCentered("--- Loaded Rooms ---", DISPLAY_WIDTH);
	cout << endl;
	PrintRoomStates(roomStates);

	// Handle Data
	HandleRooms(roomStates);

	// Display Modified Data
	cout << endl;
	PrintCentered("--- Modified Rooms ---", DISPLAY_WIDTH);
	cout << endl;
	PrintRoomStates(roomStates);

	// Handle Input
	bool loop = true;
	bool save = false;
	while(loop)
	{
		InputType selection;
		PromptInput();
		ReadInput(selection);
		HandleInput(roomStates, selection, loop, save);
	}

	// Save Changes
	if(save) {
		fstream output;
		PromptOutputFileStream(output);
		WriteRoomStates(roomStates, output);
		output.close();
	}

	// Quit
	return 0;
}

// Room States --------------------------------------------------------------------------------------------
void ReadRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], fstream &input)
{
	RoomState state;
	int stateId;
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			input >> stateId;
			state = static_cast<RoomState>(stateId);
			if(input.fail() || input.eof()) 
			{
				cout << "Invalid Data." << endl;
				return;
			}
			roomStates[room][floor] = state;
		}
	}
}

void PrintRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	int vacancyCount = 0;
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			cout << "[";
			switch (roomStates[room][floor])
			{
			case VACANT:
				PrintCentered("", WIDTH_ROOM_NAME);
				vacancyCount++;
				break;
			case CHECKOUT:
				PrintCentered("Checkout", WIDTH_ROOM_NAME);
				break;
			case OCCUPIED:
				PrintCentered("Occupied", WIDTH_ROOM_NAME);
				break;
			case NURSE_STATION:
				PrintCentered("NurseStn", WIDTH_ROOM_NAME);
				break;
			case TRANSFER:
				PrintCentered("Transfer", WIDTH_ROOM_NAME);
				break;
			case UTILITY_ROOM:
				PrintCentered("Utility", WIDTH_ROOM_NAME);
				break;
			}
			cout << "] ";
		}
		cout << endl;
	}
	cout << "There are " << vacancyCount << " vacant rooms remaining." << endl;
}

void WriteRoomStates(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], fstream &output)
{
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			output << static_cast<int>(roomStates[room][floor]) << " ";
		}
		output << endl;
	}
}

// Data Handlers ------------------------------------------------------------------------------------------
void HandleRooms(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	HandleCheckouts(roomStates);
	HandleTransfers(roomStates);
}

void HandleCheckouts(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			if(roomStates[room][floor] == CHECKOUT)
			{
				roomStates[room][floor] = VACANT;
			}
		}
	}
}

void HandleTransfers(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			if(roomStates[room][floor] == TRANSFER)
			{
				int nextRoom, nextFloor;
				if(FindVacancy(roomStates, floor, nextRoom, nextFloor))
				{
					roomStates[room][floor] = VACANT;
					roomStates[nextRoom][nextFloor] = OCCUPIED;
				}
				else
				{
					cout << "Warning: Cannot transfer patient. No vacant rooms found.";
				}
			}
		}
	}
}

bool FindVacancy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], int targetFloor, int &vacantRoom, int &vacantFloor)
{
	for(int room = 0; room < ROOM_COUNT; room++)
	{
		if(roomStates[room][targetFloor] == VACANT)
		{
			vacantRoom  = room;
			vacantFloor = targetFloor;
			return true;
		}
	}
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		if(floor == targetFloor) continue;
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			if(roomStates[room][floor] == VACANT)
			{
				vacantRoom  = room;
				vacantFloor = floor;
				return true;
			}
		}
	}
	return false;
}
bool FindVacancy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], int &vacantRoom, int &vacantFloor)
{
	for(int floor = 0; floor < FLOOR_COUNT; floor++)
	{
		for(int room = 0; room < ROOM_COUNT; room++)
		{
			if(roomStates[room][floor] == VACANT)
			{
				vacantRoom  = room;
				vacantFloor = floor;
				return true;
			}
		}
	}
	return false;
}

// User Input ---------------------------------------------------------------------------------------------
void PromptInput()
{
	cout << endl;
	cout << "Please Select an Option: "         << endl;
	cout << "  O - Enter a New Patient"         << endl;
	cout << "  C - Mark a Patient for Checkout" << endl;
	cout << "  T - Mark a Patient for Transfer" << endl;
	cout << "  V - Vacate a Room"               << endl;
	cout << "  M - Display Current Room Map"    << endl;
	cout << "  S - Save and Quit"               << endl;
	cout << "  Q - Quit"                        << endl;
}

void ReadInput(InputType &selection)
{
	char selectionId;
	while(true)
	{
		cin >> selectionId;
		if(cin.fail() || !VerifyInput(selectionId, INPUT_OPTIONS))
		{
			PrintInputError("Please Select a Valid Option.");
		}
		else
		{
			selection = static_cast<InputType>(toupper(selectionId));
			return;
		}
	}
}

void HandleInput(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT], InputType selection, bool &continueLoop, bool &save)
{
	switch(selection)
	{
		case I_OCCUPY:
			HandleInputOccupy(roomStates);
			break;
		case I_CHECKOUT:
			HandleInputCheckout(roomStates);
			break;
		case I_TRANSFER:
			HandleInputTransfer(roomStates);
			break;
		case I_VACANT:
			HandleInputVacant(roomStates);
			break;
		case I_MAP:
			PrintRoomStates(roomStates);
			break;
		case I_QUIT_S:
			continueLoop = false;
			save = true;
			break;
		case I_QUIT_NS:
			continueLoop = false;
			save = false;
			break;
	}
}

void HandleInputOccupy(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	cout << "Please Select a Room to Occupy" << endl;
	string errorMessage = "Please Enter a number within room bounds.";
	cout << "Enter the Floor Number (1-5): ";
	int floor = InputInt(1, errorMessage, FLOOR_COUNT);
	cout << "Enter the Room Number (1-8): ";
	int room  = InputInt(1, errorMessage, ROOM_COUNT);

	switch(roomStates[room-1][floor-1])
	{
		case OCCUPIED:
		case CHECKOUT:
		case TRANSFER:
			cout << "Room is Already Occupied" << endl;
			break;
		case NURSE_STATION:
		case UTILITY_ROOM:
			cout << "Room cannot be Occupied" << endl;
			break;
		case VACANT:
			roomStates[room-1][floor-1] = OCCUPIED;
			cout << "Room " << room << " of floor " << floor << " is now Occupied.";
			break;
	}
}

void HandleInputCheckout(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	cout << "Please Select a Room to Checkout" << endl;
	string errorMessage = "Please Enter a number within room bounds.";
	cout << "Enter the Floor Number (1-5): ";
	int floor = InputInt(1, errorMessage, FLOOR_COUNT);
	cout << "Enter the Room Number (1-8): ";
	int room  = InputInt(1, errorMessage, ROOM_COUNT);

	switch(roomStates[room-1][floor-1])
	{
		case CHECKOUT:
			cout << "Room is already marked for Checkout" << endl;
			break;
		case NURSE_STATION:
		case UTILITY_ROOM:
			cout << "Room cannot be marked for Checkout" << endl;
			break;
		case VACANT:
			cout << "Room is Vacant, cannot be marked for Checkout" << endl;
			break;
		case OCCUPIED:
		case TRANSFER:
			roomStates[room-1][floor-1] = CHECKOUT;
			cout << "Room " << room << " of floor " << floor << " is now marked for Checkout.";
			break;
	}
}
void HandleInputTransfer(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	cout << "Please Select a Room to Transfer" << endl;
	string errorMessage = "Please Enter a number within room bounds.";
	cout << "Enter the Floor Number (1-5): ";
	int floor = InputInt(1, errorMessage, FLOOR_COUNT);
	cout << "Enter the Room Number (1-8): ";
	int room  = InputInt(1, errorMessage, ROOM_COUNT);

	switch(roomStates[room-1][floor-1])
	{
		case TRANSFER:
			cout << "Room is already marked for Transfer" << endl;
			break;
		case NURSE_STATION:
		case UTILITY_ROOM:
			cout << "Room cannot be marked for Transfer" << endl;
			break;
		case VACANT:
			cout << "Room is Vacant, cannot be marked for Transfer" << endl;
			break;
		case OCCUPIED:
		case CHECKOUT:
			roomStates[room-1][floor-1] = TRANSFER;
			cout << "Room " << room << " of floor " << floor << " is now marked for Transfer.";
			break;
	}
}
void HandleInputVacant(RoomState roomStates[ROOM_COUNT][FLOOR_COUNT])
{
	cout << "Please Select a Room to Vacate" << endl;
	string errorMessage = "Please Enter a number within room bounds.";
	cout << "Enter the Floor Number (1-5): ";
	int floor = InputInt(1, errorMessage, FLOOR_COUNT);
	cout << "Enter the Room Number (1-8): ";
	int room  = InputInt(1, errorMessage, ROOM_COUNT);

	switch(roomStates[room-1][floor-1])
	{
		case VACANT:
			cout << "Room is already Vacant" << endl;
			break;
		case NURSE_STATION:
		case UTILITY_ROOM:
			cout << "Room cannot be Vacant" << endl;
			break;
		case OCCUPIED:
		case CHECKOUT:
		case TRANSFER:
			roomStates[room-1][floor-1] = VACANT;
			cout << "Room " << room << " of floor " << floor << " is now Vacant.";
			break;
	}
}

bool VerifyInput(char selectionId, string options)
{
	for(int index = 0; index < options.length(); index++)
	{
		if(toupper(selectionId) == options.at(index)) return true;
	}
	return false;
}

// IO -----------------------------------------------------------------------------------------------------
string PromptInputFileStream(fstream &file)
{
    string selection;
    while(true)
    {
        cout << "File Name: ";
        cin >> selection;
        file.open(selection, ios::in);
        if(!cin.fail() && !file.fail()) return selection;;
        cout << "Invalid File" << endl;
    }
}

string PromptOutputFileStream(fstream &file)
{
    string selection;
    while(true)
    {
        cout << "Warning: If file already exists it will be deleted." << endl;
        cout << "File Name: ";
        cin >> selection;
        file.open(selection, ios::out);
        if(!cin.fail() && !file.fail()) return selection;;
        cout << "Invalid File" << endl;
    }
}

void PrintCentered(string message, int width)
{
    int half = message.size()/2;
    string left, right;
    Split(message, half, left, right);
    cout << std::right << setw(width/2) << left;
    cout << std::left  << setw(width/2) << right;
}
void Split(string message, int index, string &left, string &right)
{
    int width = message.size();
    for(int x = 0; x < width; x++)
    {
        if(x < index)  left  += message[x];
        if(x >= index) right += message[x];
    }
}

int InputInt(string error)
{
    int selection;
    while(true)
    {
        cin >> selection;
        if(cin.fail())
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}
int InputInt(int lowerBound, string error)
{
    int selection;
    while(true)
    {
        selection = InputInt(error);
        if(selection < lowerBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}
int InputInt(string error, int upperBound)
{
    int selection;
    while(true)
    {
        selection = InputInt(error);
        if(selection > upperBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}
int InputInt(int lowerBound, string error, int upperBound)
{
    int selection;
    while(true)
    {
        selection = InputInt(error);
        if(selection > upperBound || selection < lowerBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}

void PrintInputError(string error)
{
    cout << error;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}