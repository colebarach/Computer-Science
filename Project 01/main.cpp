/*
Title: Project 01: Seven Days Toss Up
Class: Computer Science I
Author: Cole Barach
Date Created: 22.10.19
*/

// Library Includes
#include <iostream>
#include <iomanip>
#include <limits>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program Output -----------------------------------------------------------------------------------------

// Display Introduction
// -Call when the intro to the program should be printed
// -Prints the intro of the program
void DisplayIntro();
// Display Outro
// -Call when the outro to the program should be printed
// -Prints the outro of the program
void DisplayOutro();
// Display Scores
// -Call when the scores of each should be printed
// -Prints the two scores passed as parameters
void DisplayScores(int, int);
// Display Winner
// -Call when the winner should be printed
// -Prints the user of the greater score
void DisplayWinner(int, int);
// Display Battle Name
// -Call when the name of the battle should be printed
// -Prints the name of the battle based on its index
void DisplayBattle(int);
// Get Coin Alias
// -Call when the alias for a coin side is required
// -Returns the alias of the coin side
string GetCoinAlias(char);

// Program Simulation -------------------------------------------------------------------------------------

// Simulate Battle
// -Call when a battle is started 
// -Increments the score of the winner
void SimulateBattle(int &, int &);
// Input Coin
// -Call when the user input for the coin toss is required
// -Returns the user inputted selection
char InputCoin();
// Flip Coin
// -Call a coin flip is requited
// -Returns the side of the coin flipped
char FlipCoin();
// Prompt Loop
// -Call to give user the option to loop the program
// -Returns true if yes, false if no
bool PromptLoop();

// Pseudorandom Number Generation -------------------------------------------------------------------------

// Random Number Seeding
// - Must be called to initialize random number generation
// - Seeds the <random> library
void SeedRandom();
// Get Random Int
// - Called when a random integer is required
// - Returns a pseudorandom number between 0 and max
int RandomInt(int max);
// Get Random Bool
// - Called when a random boolean is required
// - Returns a pseudorandom boolean
char RandomChar(string);
// Get Random Char
// - Called when a random character is required
// - Returns a pseudorandom character

// Input Validation ---------------------------------------------------------------------------------------

// Char Input Validation
// - Called when valid char is required
// - Returns the validated char
char    InputChar(                     string error);
char    InputChar(  string options,    string error);
// Int Input Validation
// - Called when valid int is required
// - Returns the validated int
int     InputInt(                      string error);
int     InputInt(   int lowerBound,    string error);
int     InputInt(                      string error, int    upperBound);
int     InputInt(   int lowerBound,    string error, int    upperBound);
// Double Input Validation
// - Called when valid double is required
// - Returns the validated double
double  InputDouble(                   string error);
double  InputDouble(double lowerBound, string error);
double  InputDouble(                   string error, double upperBound);
double  InputDouble(double lowerBound, string error, double upperBound);
// Print Input Error
// - Called when invalid data is input
// - Notifies the user and clears the stream
void PrintInputError(string error);

// Constants ----------------------------------------------------------------------------------------------

const string COIN_SELECTION   = "HTht";
const string COIN_VALUES      = "HT";
const char   COIN_HEADS       = 'H';
const char   COIN_TAILS       = 'T';
const string YES_NO_SELECTION = "YNyn";
const char   YES              = 'Y';
const char   NO               = 'N';

const string BATTLE_NAMES[] = {"",
                               "Little Round Top",
                               "Cemetery Ridge",
                               "Devils Den",
                               "The Wheatfield",
                               "The Peach Orchard",
                               "Culps Hill",
                               "Zieglers Grove",
                               "Seminary Ridge",
                               "Gettysburg"};

// Main Program -------------------------------------------------------------------------------------------

int main()
{
    // Initialization
    SeedRandom();

    // Program Header
	cout << "Title: Project 01: Seven Days Toss Up"                     << endl;
	cout << "Class: Computer Science I"									<< endl;
	cout << "Author: Cole Barach"										<< endl;
	cout << "Date Created: 22.10.19"									<< endl;
	cout <<                                                                endl;
	cout << "Function: Simulation of the Battle of Seven Days using "
         << "pseudorandom number generation."                           << endl;
	cout <<    															   endl;

    while(true)
    {
        // Declarations
        int scoreMcClellan = 0;
        int scoreLee       = 0;

        // Program Start
        DisplayIntro();

        // Battle Loop
        for(int battle = 1; battle <= 9; battle++) {
            DisplayBattle(battle);
            SimulateBattle(scoreMcClellan, scoreLee);
            DisplayScores(scoreMcClellan, scoreLee);
        }

        // Program End
        DisplayWinner(scoreMcClellan, scoreLee);
        DisplayOutro();

        if(!PromptLoop()) return 0;
    }
}

void DisplayIntro()
{
    cout <<                                                                                         endl;
    cout << "                     Let the Flip of the Coin Rewrite History                     " << endl;
    cout <<                                                                                         endl;
    cout << "                             /----------------------\\                            " << endl;
    cout << "                             | RETURN TO SEVEN DAYS |                             " << endl;
    cout << "                             \\----------------------/                            " << endl;
    cout <<                                                                                         endl;
    cout << "It is July 1st, 1862, the final day of the Battle of Seven Days..."                 << endl;
    cout <<                                                                                         endl;
    cout << "In this re-enactment of the second day of battle, you are George B. McClellan in"   << endl;
    cout << "charge of the Unionists."                                                           << endl;
    cout <<                                                                                         endl;
    cout << "We will flip a coin to determine the outcome of the small battles for territories"  << endl;
    cout << "within the Seven Days area"                                                         << endl;
    cout <<                                                                                         endl;
    cout << "You will have to predict whether the coin will come up heads ot tails..."           << endl;
    cout <<                                                                                         endl;
}
void DisplayOutro()
{
    cout << "In the actual Battle of Seven Days, the Northern troops turned back Lee's final"    << endl;
    cout << "assault at Malvern Hill (July 1st)..."                                              << endl;
    cout <<                                                                                         endl;
    cout << "The Confederates lost about 16,000 men..."                                          << endl;
    cout << "The Unionists lost about 20,000 men..."                                             << endl;
    cout <<                                                                                         endl;
    cout << "McClellan's failure to capture Richmond, and the subsequent withdrawal of the"      << endl;
    cout << "Union's Arms from the Yorktown Penisula, signified the end of the Penisular"        << endl;
    cout << "Campaign."                                                                          << endl;
    cout <<                                                                                         endl;
}
void DisplayScores(int scoreMcClellan, int scoreLee)
{
    cout << "So far: McClellan " << scoreMcClellan << " victories, " << endl;
    cout << "        Lee       " << scoreLee       << " victories"   << endl;
    cout <<                                                             endl;
}
void DisplayWinner(int scoreMcClellan, int scoreLee)
{
    if(scoreMcClellan > scoreLee)
    {
        cout << "The results show that George B. McClellan won the majority of the battles and is"   << endl;
        cout << "thus declared the victor on July 2nd, 1863."                                        << endl;
        cout <<                                                                                         endl;
    }
    else
    {
        cout << "The results show that Robert E. Lee won the majority of the battles and is thus"    << endl;
        cout << "declared the victor on July 2nd, 1863."                                             << endl;
        cout <<                                                                                         endl;
    }
}
void DisplayBattle(int battle)
{
    cout << "          --- The Battle of " << BATTLE_NAMES[battle] << " ---" << endl;
    cout << "                      Battle No." << battle << endl;
    cout << endl;
}

void SimulateBattle(int &scoreCorrect, int &scoreIncorrect)
{
    // Prompt User
    cout << "Now General McClellan,"                << endl;
    cout << "Do you predict the coin will come out" << endl;
    cout << "'H' - Heads or 'T' - Tails"            << endl;
    // Get User Selection
    char selection = InputCoin();
    // Flip Coin
    char coin = FlipCoin();
    // Determine Results
    if(selection == coin)
    {
        // Win Condition
        scoreCorrect++;
        cout << "Well done, General McClellan,"  << endl;
        cout << "you have defeated General Lee." << endl;
        cout << endl;
    }
    else
    {
        // Lose Condition
        scoreIncorrect++;
        cout << "I am sorry, General McClellan,"  << endl;
        cout << "the battle goes to General Lee." << endl;
        cout << endl;
    }
}
char InputCoin()
{
    // Get Input
    cout << "Choose: ";
    char selection = toupper(InputChar(COIN_SELECTION, "Please choose 'H' or 'T': "));
    // Echo Input
    string alias = GetCoinAlias(selection);
    cout << "You have chosen " << alias              << endl;
    cout << "  Stand by to fight, General McClellan" << endl;
    cout <<                                             endl;
    return selection;
}
char FlipCoin()
{
    // Get Random
    char coin = RandomChar(COIN_VALUES);
    string alias = GetCoinAlias(coin);
    // Print Results
    cout << "The result of the coin toss was " << alias << "." << endl;
    return coin;
}
string GetCoinAlias(char coin)
{
    //Return Name
    if(coin == COIN_HEADS) return "Heads";
    if(coin == COIN_TAILS) return "Tails";
    return "";
}

bool PromptLoop()
{
    cout << "The Program has ended. Would you like to repeat? (Y/N) ";
    char selection = toupper(InputChar(YES_NO_SELECTION, "Please choose (Y/N)"));
    return selection == YES;
}

// Pseudorandom Number Generation -------------------------------------------------------------------------
void SeedRandom()
{
    srand(time(nullptr));
}
int RandomInt(int max)
{
    return static_cast<double>(max * rand()) / RAND_MAX;
}
bool RandomBool()
{
    return RandomInt(2);
}
char RandomChar(string options)
{
    int length = options.length();
    int selection = RandomInt(length);
    return options[selection];
}

// Generic Input Validation -------------------------------------------------------------------------------
char InputChar(string error)
{
    char selection;
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
char InputChar(string options, string error)
{
    char selection;
    while(true)
    {
        selection = InputChar(error);
        for(int index = 0; index < options.length(); index++)
        {
            if(selection == options[index]) return selection;
        }
        PrintInputError(error);
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
        if(selection > upperBound || selection < upperBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}

double InputDouble(string error)
{
    double selection;
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
double InputDouble(double lowerBound, string error) {
    double selection;
    while(true)
    {
        selection = InputDouble(error);
        if(selection < lowerBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}
double InputDouble(string error, double upperBound)
{
    double selection;
    while(true)
    {
        selection = InputDouble(error);
        if(selection > upperBound)
        {
            PrintInputError(error);
        } else
        {
            return selection;
        }
    }
}
double InputDouble(double lowerBound, string error, double upperBound)
{
    double selection;
    while(true)
    {
        selection = InputDouble(error);
        if(selection < lowerBound || selection > upperBound)
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