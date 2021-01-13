#include <iostream>
#include <cmath>

//task_01
unsigned factorial(unsigned n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}


// task_02
bool isPrimeRec(unsigned n, unsigned stop, unsigned i) 
{

	if (n == 1 || n == 2)
    {
		return true;
    }
	
    if (n % i == 0)
    {
		return false;
    }

	if (i == stop)
    {
		return true;
    }

	return isPrimeRec(n, stop, i + 1);
}

// wrapper function
bool isPrime(unsigned number) 
{

	return isPrimeRec(number, std::sqrt(number), 2);
}

//task_03
void printBitsRec(unsigned n, unsigned int position) 
{

	unsigned mask = 1 << (position - 1);
	std::cout << ((n & mask) ? "1" : "0");

	if (position == 1)
    {
		return;
    }
	else
    {
		return printBitsRec(n, position - 1);
    }
}

// wrapper function
void printBits(unsigned int n) 
{
	unsigned position = sizeof(unsigned) * 8;
	return printBitsRec(n, position);
}

//task_04
void countBitsRec(unsigned n, unsigned position, int &zeroes, int &ones) 
{

	unsigned mask = 1 << (position - 1);
	((n & mask) ? ones++ : zeroes++);

	if (position == 1)
    {
		return;
    }
	else
    {
		return countBitsRec(n, position - 1, zeroes, ones);
    }
}

void countBits(unsigned int n) 
{

	int zeroes = 0;
	int ones = 0;
	unsigned position = sizeof(unsigned) * 8;
	countBitsRec(n, position,zeroes,ones);
	std::cout << "In number: " << n << " we have " << zeroes << " zeroes and " << ones << " ones!" << std::endl;
}

//task_05
void printForward(unsigned n) 
{

	if (n <= 0) 
    {
        return;
    }

	printForward(n / 10);
	std::cout << (n % 10) << " ";
}

//task_06
void printBackward(unsigned n) {

	if (n <= 0) 
    {
        return;
    }

	std::cout << (n % 10) << " ";
	printBackward(n / 10);
}

//task_07
void printLineRec(unsigned k, unsigned it, unsigned long long result) {

	std::cout << result << ' ';

	if (it < k)
		printLineRec(k, it + 1, result * 10);

	std::cout << result << ' ';
}

// wrapper function
void printLine(unsigned int k) {
	printLineRec(k, 1, 10);
}

//task_08
int gcd(int a, int b) {
    if(b == 0)
    {
        return a;
    }
	return gcd(b, a % b);
}

int main()
{

    return 0;
}