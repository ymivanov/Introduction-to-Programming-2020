#include <iostream>

// task_01
bool isAlpha(char c) {

	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// task_02
bool isDigit(char c) {

	return (c >= '0' && c <= '9');
}

bool isUpper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

// task_03
void toLower(char* str) {

	// protects our function
	// from invalid usage
	if (!str)
    {
		return;
    }

	// the standard way of iterating a string
	size_t i = 0;

	// loop until the terminating symbol
	while (str[i] != '\0') 
    {
		if (isUpper(str[i]))
        {                       
			str[i] += 'a' - 'A';
        }		                
        i++;                        
    }                              
}

//task_04
void changeSpSymbol(char* str, char toChange, char changeWith) 
{
	if (!str)
    {
		return;
    }

	size_t i = 0;

	while (str[i] != '\0') 
    {
		if (str[i] == toChange)
        {
			str[i] = changeWith;
        }
		i++;
	}
}

// task_05
int customAtoi(const char* str) // we will not change the string's
{                               // contain so passing it by const 
								// is the right way to go  

	if (!str)
    {
		return 0; // maybe
    }

	int result = 0;
	int sign = 1;

	if (*str == '-') // the first char is -
    { 
		sign = -1;
		str++; // moves the pointer one position forward
	}

	size_t i = 0;
	while (str[i] != '\0') 
    {
		result *= 10;			// a new space at the end of the number
		result += str[i] - '0';	// putting the new digit at the end
		i++;
	}

	return result * sign;
}

// task_06
bool isPalindrome(const char* str) 
{

	if (!str)
    {
		return false;
    }

	size_t len = strlen(str);
	size_t i = 0;

	while (i < len / 2)	// looking at the front and at the end
    {					
		if (str[i] != str[len - (i + 1)])// the last element is on index str[len-1]
        {
			return false;
        }	
		else
        {
			i++;    
        }
	}

	// if the first half is the reversed second
	return true;
}

// task_07
void reverse(char* str) 
{

	size_t len = strlen(str);
	size_t i = 0;

	while (i < len / 2) //looking at the front and at the end
    { 
		std::swap(str[i], str[len - (i + 1)]);
		i++;
	}
}

// task_08
// returns false if there was some kind of memory problem
bool dynamicConcat(char*& dest, const char* src) // the dest pointer will be redirected,
{                                               // so taking it by ref is essential
													

	char* newMemBuff = new (std::nothrow) char[strlen(dest) + strlen(src) + 1];
	// enough memory for both strings' contain + '\0'

	if (!newMemBuff)
    {
		return false;
    }

	strcpy(newMemBuff, dest); // copy the first part
	strcat(newMemBuff, src);  // appends the second part

	// clear the unneeded memory
	delete[] dest;

	dest = newMemBuff; // redirecting the pointer from main/other function

	return true;
}

// task_09
bool isVowel(char c) 
{

	if (!isAlpha(c))
    {
		return false;
    }

	c = tolower(c);

	return c == 'a' || c == 'e' ||
		   c == 'i' || c == 'u' ||
		   c == 'o';
}

void compact(char*& str) // will redirect str -> reference!
{ 

	if (str == nullptr)
    {
		return;
    }

	char* buff = new (std::nothrow) char[strlen(str) + 1]; //alloc a buff
	if (!buff)
    {
		return;
    }

	size_t i = 0, iBuff = 0;

	while (str[i] != '\0') 
    {
		if (isVowel(str[i])) // skipping the vowels
        { 
			i++;
			continue;
		}
		// copying other symbols
		buff[iBuff++] = str[i++];
	}

	buff[iBuff] = '\0';

	delete[] str; // we don't need this mem anymore

	// new memory as we need
	str = new (std::nothrow) char[strlen(buff) + 1];

	if (!str)
    {
		str = buff;
		return;
	}

	// taking everything from the buffer
	strcpy(str, buff);

	delete[] buff;
}

// task_10
void mostCommonAlpha(const char* str) {
    
    const unsigned int LETTERS_COUNT = 26;

	if (!str)
    {
		return;
    }

    // how many times each
	// letter occurs
	// mapping index 0 - 'a'
	// index 1 - 'b' and etc
	size_t timesOcc[LETTERS_COUNT] = { 0, };
	size_t i = 0;

	while (str[i] != '\0') {
		if (isAlpha(str[i]))
        {
            char current = str[i];
            if(isUpper(str[i]))
            {
                current += 'a' - 'A'; 
            }
			timesOcc[current - 'a']++;
        }
		// counts the current letter by adding one
		// on its index in the array
		i++;
	}

	// now the task is to find a maximum in an array
	size_t max_index = 0;
	for (i = 1; i < LETTERS_COUNT; i++)
    {
		if (timesOcc[max_index] < timesOcc[i])
        {
			max_index = i;
        }
    }

	// re-mapping to find which char that is
	std::cout << '\'' << char(max_index + 'a') << "\' - "
		      << timesOcc[max_index] << "(times)";
}

int main()
{
//TODO: Write some tests
    return 0;
}