// Input/Output
// - Interface for the C++ Standard Input and Output Streams

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

// Libraries ----------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

// Get Integer
// - Call to get an Integer from a given Input Stream.
// - Will iterate until a valid input is given. Returns said input.
int GetInt(std::istream &stream,                 std::string errorMessage);
int GetInt(std::istream &stream, int lowerBound, std::string errorMessage);
int GetInt(std::istream &stream,                 std::string errorMessage, int upperBound);
int GetInt(std::istream &stream, int lowerBound, std::string errorMessage, int upperBound);

// Get Double
// - Call to get a Double from a given Input Stream.
// - Will iterate until a valid input is given. Returns said input.
double GetDouble(std::istream &stream,                    std::string errorMessage);
double GetDouble(std::istream &stream, double lowerBound, std::string errorMessage);
double GetDouble(std::istream &stream,                    std::string errorMessage, double upperBound);
double GetDouble(std::istream &stream, double lowerBound, std::string errorMessage, double upperBound);

// Get Char
// - Call to get a Character from a given Input Stream.
// - Will iterate until a valid character is given. Returns said character.
char GetChar(std::istream &stream, std::string errorMessage);
char GetChar(std::istream &stream, std::string charOptions, std::string errorMessage);

// Print Line
// - Call to print a solid line of characters
// - Prints a line of given width and content
void PrintLine(std::ostream &stream, int width, char fill);

// Print Block
// - Call to print a solid block of characters
// - Prints a block of given width and content
void PrintBlock(std::ostream &stream, int width, char fill);

// Print Centered
// - Call to print text with center justification
// - Prints to given stream the centered text
void PrintCentered(std::ostream &stream, std::string message, int width);

// Print Array
// - Call to print the elements of an array
// - Prints the elements to the given stream
void PrintArray(std::ostream &stream, int *array, int size);
void PrintArray(std::ostream &stream, double *array, int size);
void PrintArray(std::ostream &stream, char *array, int size);

// Split
// - Call to split a message in half about an index.
// - Writes to the left and right strings
void Split(std::string message, int index, std::string &left, std::string &right);

// Get File by Name
// - Call to open a file stream by file name
// - Returns true for success, false for failure
bool GetFileByName(std::fstream &file, std::string fileName, std::ios_base::openmode mode);

// Input File by Name
// - Call when a user defined file stream is required
// - Returns the validated file stream
void InputFileByName(std::fstream &file, std::ios_base::openmode mode);

#endif // INPUT_OUTPUT_H