#include<iostream>
#include<iomanip>
using namespace std;

void printArr (int** arr, int n) {

    int i, j;

    for(i = n-1; i >= 0; i--) {
        for(j = 0; j < i; j++)
                cout << setw(2) << " ";
            
        for(j = 0; j < n-i; j++)
             cout << setw(4) << arr[i+j][j];
            

        cout << endl;
    }
}

void createAndPrintTriangle (int n) {
    
    int** arr = new int*[n];

    for(int i = 0; i < n; i++)
        arr[i] = new int[i+1];

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            if(i == n-1 || j == 0)
                arr[i][j] = 1;

    for(int i = n-2; i > 0; i--)
        for (int j = 1; j <= i; j++)
            arr[i][j] = arr[i][j-1] + arr[i+1][j];


    printArr(arr, n);




    for(int i = 0; i < n; i++)
        delete[] arr[i];

    delete[] arr;
    
}

int main()
{
    int n;
    
    
    do {
        cout << "Enter n (Greater than 0): " ;
        cin >> n;
    } while (n < 1);
    
    createAndPrintTriangle(n);

    return 0;
}