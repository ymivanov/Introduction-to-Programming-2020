 /**
  * @file   solutions.cpp
  * @author Kristian Ekov
  * @author Dimitar Kolev
  * @author Yosif Ivanov
  * @date   12.2020
  * @brief  Solution for the tasks from practice 8.
  */

#include <iostream>

const int ROWS = 100;
const int COLS = 100;

//task 01
void inputMatrix(int matrix[][COLS], size_t rowSize, size_t colSize)
{
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < colSize; j++)
            std::cin >> matrix[i][j];
}

void printMatrix(int matrix[][COLS], size_t rowSize, size_t colSize)
{
    std::cout << std::endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}


//task 02
int biggestElement(int matrix[][COLS], size_t rowSize, size_t colSize)
{
    int maxElem = matrix[0][0];

    for (int i = 1; i < rowSize; i++)
        for (int j = 1; j < colSize; j++)
        {
            if (maxElem < matrix[i][j])
                maxElem = matrix[i][j];
        }

    return maxElem;
}


//task 03
void multiplyWithScalar(int matrix[][COLS], size_t rowSize, size_t colSize, int h)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            matrix[i][j] *= h;
        }
    }
}

//task 04
void addTwoMatrices(int A[][COLS], int B[][COLS], size_t m, size_t n) {
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			A[i][j] += B[i][j];
		}
	}
}


//task 05
// Оnly for single-digit values
void printFrame(int mat[][COLS], size_t m, size_t n) {
    //int cell_size = find_max_cell_size(mat, m, n);
	for (size_t row = 0; row < m; row++) {
		for (size_t col = 0; col < n; col++)
			if ((row == 0 || row == m - 1) || (col == 0 || col == n - 1)) {
				std::cout << mat[row][col] << ' ';
			} else {
				std::cout << ' ';
			}
		std::cout << std::endl;
	}
}


//task 06
//Оnly for single-digit values
void printDiagonals(int mat[][COLS], size_t n) {
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < n; col++) {
			if (row == col || row + col == n - 1) {
				std::cout <<  mat[row][col] << ' ';
			} else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}


//task 07
void belowAboveDiagonal(int mat[][COLS], size_t rows, size_t cols) {

	int sumAbove = 0;
	int cntOddBelow = 0;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			// above the main diagonal
			if (i < j) {
				sumAbove += mat[i][j];
			}

			// below the main diagonal
			if ((i > j) && (mat[i][j] % 2 != 0)) { 
				cntOddBelow++;
			}
		}
	}

	std::cout << sumAbove * cntOddBelow;
}


//task 08
bool isMaxInRow(int elem, int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] > elem) {
			return false;
		}
	}
	return true;
}
void saddle_point(int mat[][COLS], size_t rows, size_t cols) {

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
				// we pass the whole row as a parameter to a function
			if (isMaxInRow(mat[i][j], mat[i], cols)) {
				// we can't pass the column as a parameter to a function, 
                // so we check it here
				bool isMinInCol = true;
				for (size_t k = 0; k < rows && isMinInCol; k++) {
					if (mat[k][j] < mat[i][j]) {
						isMinInCol = false;
					}
				}
				// we have found the saddle point
				if (isMinInCol) {
					std::cout << "The saddle point is : matrix("
						      << i << ", " << j << ") = " << mat[i][j] << std::endl;
					return; // there can be only one saddle
				}
			}
		}
	}

	// if we reach here there isn't a saddle point
	std::cout << "There isn't a saddle point in the given matrix!!!" << std::endl;
}

int main() {

    int matrix[ROWS][COLS];
    size_t n, m;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    std::cout << "Enter number of rows: ";
    std::cin >> m;

	if (n >= ROWS || m >= COLS) {
		std::cout << "Invalid input!!" << std::endl;
		return -1;
	}

    std::cout << "TASK 1: " << std::endl;
    inputMatrix(matrix, 3, 3);
    printDiagonals(matrix, 3);


    std::cout << "TASK 2: " << std::endl;
    std::cout << "Тhe largest element in the matrix is 10: " << biggestElement(matrix, n, m) << '\n';
    

    std::cout << "TASK 3: " << std::endl;
    int scalar;
    std::cout << "Enter a scalar: ";
    std::cin >> scalar;
    multiplyWithScalar(matrix, n, m, scalar);
    printMatrix(matrix, n, m);


    std::cout << "TASK 4: " << std::endl;
    int matrix2[ROWS][COLS];
    std::cout << "Enter second matrix data: " << std::endl;
	inputMatrix(matrix2, m, n);
    
    std::cout << "First matrix + Second matrix =" << std::endl;
	addTwoMatrices(matrix, matrix2, n, m);
	printMatrix(matrix, n, m);


    std::cout << "TASK 5: " << std::endl;
    printFrame(matrix, n, m);
	std::cout << std::endl;
    

    std::cout << "TASK 6: " << std::endl;  
    std::cout << "Printing matrix's diagonals: " << std::endl;
	printDiagonals(matrix, n); 


    std::cout << "TASK 7: " << std::endl;  
    std::cout << "The sum of the element above the main diagonal,\nmultiplied by"
			     " the count of odd element below the main diagonal is: ";
	belowAboveDiagonal(matrix, m, n);
	std::cout << std::endl;


    std::cout << "TASK 8: " << std::endl;
	saddle_point(matrix, m, n);
    
    return 0;
}