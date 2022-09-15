/*
Name: Alicia Domingo
Class: CPSC 122, Section 2
Date: September 9, 2022
Assignment: Project 1
Description:
    1. Develop a program that generates the first n prime numbers, where n is a positive integer
    gotten from the command line
    2. Display the numbers on the console in c columns, where c is a positive integer gotten from
    the command line
    3. Includes simple error for checking n and c
*/

#include <iostream> // for cout, endl;
#include <iomanip> // uses setw()
#include <cstdlib> // uses stroul
#include <cstring>
#include <cmath> // to use sqrt()
 
using namespace std;
 
#define FIRST_PRIME 2
 
static bool test1 = false;


/*
	Description: Determines whether input integer is prime
	Input: integer whose primality is to be judged
    Returns: true if num is prime, false otherwise
*/
bool isPrime(int num)
{
    bool ret = true;
    static int primeNumbers[1000] = {0};
    static int index = 0;
 
    int sqRoot = sqrt(num);
    int i;
    for ( i = 0; i < index; i++)
    {
        if ( ( primeNumbers[i] <= sqRoot ) &&
             ( 0 == num % primeNumbers[i] ) )
        {
            ret = false;
            break;
        }
    }
 
    if ( ret )
    {
        primeNumbers[index++] = num;
    }
 
    return ret;
}
 
/*
    Description: Loops over all necessary candidate primes, invoking isPrime on each, 
	            displaying in column fashion those that are prime
    Input:      integer, totalPrimes, indicating the number of primes to display; integer 
	            cols, indicating over how many columns the primes are to be displayed
*/
void display(int totalPrimes, int numCols)
{
    int numPrimes = 0;
    int col = 0;
 
    int num = FIRST_PRIME;
 
    cout << endl;
 
    while (numPrimes < totalPrimes)
    {
        if ( isPrime(num) )
        {
            numPrimes++;
            if ( !test1 )
            {
                cout << setw(6) << num; // sets width of 6 between each number
                col++;
                if ( col == numCols )
                {
                    cout << endl;
                    col = 0;
                }
            }
        }
        num++; // adds 1 to num
    }
 
    cout << endl;
}
 
int main(int argc, char* argv[])
{
    int numPrimes = 0;
    int numCols = 0;
 
    numPrimes = strtoul(argv[1], NULL, 10); // convert string to unsigned long integer
    numCols = strtoul(argv[2], NULL, 10); // convert string to unsigned long integer

    // to check the parameters of the ./a.out numPrimes numCols to make sure there in the specific area 
    if ( (numPrimes < 0) || (numPrimes > 1000) || (numCols < 0) || (numCols > 60) )
    {
        cout << "Invalid. Please try again." << endl;
        exit (1);
    }
 
    // display the results on the screen
    cout << "===============================================================" << endl;
    cout << "Displaying " << numPrimes << " prime numbers in " << numCols << " columns." << endl;
    cout << "===============================================================";
    display(numPrimes, numCols);
    cout << "===============================================================" << endl;
}