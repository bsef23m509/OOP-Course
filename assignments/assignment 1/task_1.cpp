#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Prints the matrix
void printMatrix(int **M, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
}

// Calculates the sum of a sub matrix given original matrix, start of row and col and size of submatrix
int calulateMatrixSum(int **M, int startRow, int startCol, int size)
{
    int sum = 0;

    for (int i = startRow; i < (startRow + size); i++)
    {
        for (int j = startCol; j < (startCol + size); j++)
        {
            sum += M[i][j];
        }
    }

    return sum;
}

// prints the max sum of submatrix of size k
void printMaxSumSubMatrix(int **M, int n, int k)
{
    int loop = n - k + 1;
    int maxSum = -100, tempSum;

    for (int i = 0; i < loop; i++)
    {
        for (int j = 0; j < loop; j++)
        {
            tempSum = calulateMatrixSum(M, i, j, k);

            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
        }
    }

    cout << endl;
    cout << "Max sum: " << maxSum << endl;
}

int main()
{
    ifstream file;
    file.open("matrix.txt");

    int n, k;

    file >> n;

    do
    {
        cout << "Enter size of sub-matrix (must be less then size of the matrix (" << n << ") ) : ";
        cin >> k;
    } while (k >= n);

    // Making matrix of size n x n
    int **matrix = new int *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    // initializing matrix with values from file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matrix[i][j];
        }
    }

    // closing the file
    file.close();

    // printing matriz and max sum of submatrix of size k
    printMatrix(matrix, n);
    cout << endl;
    printMaxSumSubMatrix(matrix, n, k);

    // deleting dynamic matrix
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}