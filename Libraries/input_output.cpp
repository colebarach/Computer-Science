#include "input_output.hpp"

// Integers -----------------------------------------------------------------------------------
int GetInt(std::istream &stream, std::string errorMessage)
{
    int number;
    while(true)
    {
        stream >> number;

        if(!stream.fail()) break;
        
        std::cout << errorMessage;
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    stream.ignore();
    return number;
}

int GetInt(std::istream &stream, int lowerBound, std::string errorMessage)
{
    int number;
    while(true)
    {
        number = GetInt(stream, errorMessage);
        
        if(number >= lowerBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}

int GetInt(std::istream &stream, std::string errorMessage, int upperBound)
{
    int number;
    while(true)
    {
        number = GetInt(stream, errorMessage);
        
        if(number < upperBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}

int GetInt(std::istream &stream, int lowerBound, std::string errorMessage, int upperBound)
{
    int number;
    while(true)
    {
        number = GetInt(stream, errorMessage);
        
        if(number < upperBound && number >= lowerBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}


// Doubles ------------------------------------------------------------------------------------
double GetDouble(std::istream &stream, std::string errorMessage)
{
    double number;
    while(true)
    {
        stream >> number;

        if(!stream.fail()) break;
        
        std::cout << errorMessage;
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    stream.ignore();
    return number;
}

double GetDouble(std::istream &stream, double lowerBound, std::string errorMessage)
{
    double number;
    while(true)
    {
        number = GetDouble(stream, errorMessage);
        
        if(number >= lowerBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}

double GetDouble(std::istream &stream, std::string errorMessage, double upperBound)
{
    int number;
    while(true)
    {
        number = GetDouble(stream, errorMessage);
        
        if(number < upperBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}

double GetDouble(std::istream &stream, double lowerBound, std::string errorMessage, double upperBound)
{
    double number;
    while(true)
    {
        number = GetDouble(stream, errorMessage);
        
        if(number < upperBound && number >= lowerBound) break;

        std::cout << errorMessage;
        stream.clear();
    }
    return number;
}

// Characters ---------------------------------------------------------------------------------
char GetChar(std::istream &stream, std::string errorMessage)
{
    char selection;
    while(true)
    {
        stream.get(selection);
        stream.ignore();
        if(!stream.fail()) return selection;
        
        std::cout << errorMessage;
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

char GetChar(std::istream &stream, std::string charOptions, std::string errorMessage)
{
    char selection;
    while(true)
    {
        selection = GetChar(stream, errorMessage);
        for(int index = 0; index < charOptions.length(); index++)
        {
            if(selection == charOptions[index]) return selection;
        }

        std::cout << errorMessage;
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Printing -----------------------------------------------------------------------------------
void PrintLine(std::ostream &stream, int width, char fill)
{
    stream << std::setw(width) << std::setfill(fill) << "" << std::endl << std::setfill(' ');
}

void PrintBlock(std::ostream &stream, int width, char fill)
{
    stream << std::setw(width) << std::setfill(fill) << "" << std::setfill(' ');
}

void PrintCentered(std::ostream &stream, std::string message, int width)
{
    int half = message.size()/2;
    std::string left, right;
    
    Split(message, half, left, right);
    
    stream << std::right << std::setw(width/2) << left;
    stream << std::left  << std::setw(width/2) << right;
}

void PrintArray(std::ostream &stream, int *array, int size)
{
    stream << "{";
    for(int x = 0; x < size; x++)
    {
        stream << array[x];
        if(x != size-1) stream << ", ";
    }
    stream << "}";
}

void PrintArray(std::ostream &stream, double *array, int size)
{
    stream << "{";
    for(int x = 0; x < size; x++)
    {
        stream << array[x];
        if(x != size-1) stream << ", ";
    }
    stream << "}";
}

void PrintArray(std::ostream &stream, char *array, int size)
{
    stream << "{";
    for(int x = 0; x < size; x++)
    {
        stream << array[x];
        if(x != size-1) stream << ", ";
    }
    stream << "}";
}

void Split(std::string message, int index, std::string &left, std::string &right)
{
    int width = message.size();
    for(int x = 0; x < width; x++)
    {
        if(x < index)  left  += message[x];
        if(x >= index) right += message[x];
    }
}

// File Stream --------------------------------------------------------------------------------
bool GetFileByName(std::fstream &file, std::string fileName, std::ios_base::openmode mode)
{
    file.open(fileName, mode);
    return !file.fail();
}

void InputFileByName(std::fstream &file, std::ios_base::openmode mode)
{
    std::string fileName;
    
    while(true)
    {
        std::cout << "File Name: ";
        std::getline(std::cin, fileName);
        
        if(std::cin.fail() || !GetFileByName(file, fileName, mode))
        {
            std::cout << "Failed to Open File.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return;
        }
    }
}