

#include <iostream>

bool resize(int*& arr, size_t oldSize, size_t newSize) {

    int* tempArr = new (std::nothrow) int[newSize];
    if (!tempArr)
    {
        return false;
    } 

    size_t size = oldSize < newSize ? oldSize : newSize;

    for (size_t i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;

    return true;
}

// frees the allocated memory for a matrix
void clearMat(int**& mat, size_t& rowsCnt, int*& rowsLensArr) {

    delete[] rowsLensArr;
    rowsLensArr = nullptr;

    if (!mat)
    {
        return;
    } 

    // free the memory for each line
	for (size_t i = 0; i < rowsCnt; i++)
    {
		delete[] mat[i];
    }

	// free the memory for the array of pointers
	delete[] mat;

    // if we don't have this line, we can pass the pointer without ref,
    // but we want to assure that `mat` is in a valid state, it just
    // doesn't point to an allocated memory
	mat = nullptr;
	rowsCnt = 0;
}

// task_01
void pushBack(int*& arr, size_t& size, int elem) 
{

    if (resize(arr, size, size + 1)) 
    {
        arr[size] = elem;
        size++;
    }
}

void popBack(int*& arr, size_t& size) 
{
    if (resize(arr, size, size - 1))
    {
        size--;
    }
}

// task_02
void insertAt(int*& arr, size_t& size, size_t index, int elem) {

    int* tempArr = new(std::nothrow) int[size + 1];
    if (!tempArr)
    {
        return;
    } 

    for (size_t i = 0; i < index; i++)
    {
        tempArr[i] = arr[i];
    }

    tempArr[index] = elem;

    for (; index < size; index++)
    {
        tempArr[index + 1] = arr[index];
    }

    delete[] arr;
    arr = tempArr;
    size++;
}

void removeAt(int*& arr, size_t& size, size_t index) {

    int* tempArr = new(std::nothrow) int[size - 1];
    if (!tempArr)
    {
        return;
    } 

    for (size_t i = 0; i < index; i++)
    {
        tempArr[i] = arr[i];
    }

    for (; index < size - 1; index++)
    {
        tempArr[index] = arr[index + 1];
    }

    delete[] arr;
    arr = tempArr;
    size--;
}

bool isPrime(unsigned num) 
{
    // smallest prime is 2
    if(num < 2) 
    {
        return false;
    }

    // all even numbers are not prime except 2
    if(num % 2 == 0) 
    {
        return num == 2;
    }
 
    for(size_t i = 3; i*i <= num; i += 2) 
    {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

// task_03
void filterPrime(int*& arr, size_t& size) {

    size_t primes = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(isPrime(arr[i]))
        {
            primes++;
        }
    }

    int* tempArr = new(std::nothrow) int[primes];
    if(!tempArr)
    {
        return;
    }
    int tempCnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(isPrime(arr[i]))
        {
            tempArr[tempCnt++] = arr[i];
        }
    }

    delete[] arr;
    arr = tempArr;
    size = primes;
}

// task_04
void unite(int* sourceArr, int*& destArr, size_t fSize, size_t& sSize) {

    size_t newSize = fSize + sSize;
    int* tempArr = new(std::nothrow) int[newSize];
    if(!tempArr)
    {
        return;
    }

    size_t tempCnt = 0;
    size_t i = 0, j = 0;
    
    for (; i < fSize && j < sSize; ) 
    {
        if(sourceArr[i] <= destArr[j])
        {
            tempArr[tempCnt++] = sourceArr[i++];
        }
        else
        {
            tempArr[tempCnt++] = destArr[j++];
        }
    }

    while (i < fSize)
    {
        tempArr[tempCnt++] = sourceArr[i++];
    }
    while (j < sSize)
    {
        tempArr[tempCnt++] = destArr[j++];
    }

    delete[] destArr;
    destArr = tempArr;
    sSize = newSize;
}

//task_05
bool isRowWithOddSum(int* row, size_t rowSize) {
    if (!row) 
    {
        return false;
    }

    int sum = 0;
    for (size_t i = 0; i < rowSize; i++)
        sum += row[i];

    return (sum % 2 != 0);
}

void rollBackRowToEnd(int** mat, int* rowsLensArr,
                          size_t startRowInd, size_t endRowInd) {

    if (!mat || !endRowInd)
    {
        return;
    } 

    // change the pointers only, so the array on index start_row_ind, will
    // finally be on index end_row_index, and all others will be moved one
    // position forwards
    for (size_t i = startRowInd; i < endRowInd - 1; i++)
    {
        std::swap(mat[i], mat[i + 1]);
        std::swap(rowsLensArr[i], rowsLensArr[i + 1]);
    }
}


void clearAllOddSumRows(int**& mat, size_t& rowsCnt, int*& rowsLensArr) {

    if (!mat || !rowsLensArr) return;

    if (rowsCnt == 1 && isRowWithOddSum(mat[0], rowsLensArr[0])) {
        clearMat(mat, rowsCnt, rowsLensArr);
        return;
    }

    size_t lastRowInd = rowsCnt - 1;

    // we are going through the rows and move each odd sum row to
    // the end, there we release the memory for it
    for (size_t i = 0; i <= lastRowInd; i++) {
        if (isRowWithOddSum(mat[i], rowsLensArr[i])) {
            rollBackRowToEnd(mat, rowsLensArr, i, lastRowInd + 1);
            // release the memory for that row
            delete[] mat[lastRowInd];
            lastRowInd--;
        }
    }

    rowsCnt = lastRowInd + 1;
}

//task_06
void sortSawMatrixByRowsSize(int** mat, size_t rowsCnt,
                                  int* rowsLensArr) {
    // the task here is actually quite simple, we just sort
    // the array of sizes, and swap the corresponding pointers
    // for rows on each step
    int minVal;
    int minInd;
    // selection sort
    for (size_t i = 0; i < rowsCnt; i++) {
        minVal = rowsLensArr[i];
        minInd = i;
        for (size_t j = i + 1; j < rowsCnt; j++) {
            if (rowsLensArr[j] < minVal) {
                minVal = rowsLensArr[j];
                minInd = j;
            }
        }
        // swap only if there is a smaller element
        if (minInd != (int)i) {
            std::swap(rowsLensArr[i], rowsLensArr[minInd]);
            // here the sorting of rows happens
            std::swap(mat[i], mat[minInd]);
        }
    }
}


int main() 
{

//TODO: Write some tests

    return 0;
}