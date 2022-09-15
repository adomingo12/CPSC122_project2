#include <iostream>
#include <fstream>
#include <cmath> // for pow()
using namespace std;

int myStrnLen(char str[]);
int myAtoi(char str[]);

int main(int argc, char* argv[])
{

    ofstream outFile;
    outFile.open(argv[3]);

    outFile << myAtoi(argv[1]) * myAtoi(argv[2]) << endl;

    outFile.close();

    return 0;
}

/*
	Description: Computes the number of characters in a c-string excluding the null
		terminator (‘\0’) 
	Input: c-string
	Returns: number of characters in the c-string excluding the null terminator (‘\0’)
*/
int myStrnLen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

/*
	Description: Transforms a digit string stored as a c-string to an int. 
	The function is invoked from main like this:
	int num atoiMy(argv[1]) or int num atoiMy(argv[2])
	argv[1] might look like this: ‘1’ ‘2’ ‘3’ ‘\0’   where each of the four characters
	are stored in a character array
    Input: c-string containing  digits
    Returns: integer value of the c- string
*/
int myAtoi(char str[])
{
    int numDigits = myStrnLen(str);
    int num = 0;

    for (int i = 0; i < numDigits; i++)
    {
        num = num * 10 + str[i] - '0';
    }

    return num;
}