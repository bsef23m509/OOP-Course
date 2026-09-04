#include <iostream>
using namespace std;

int main()
{

    int m, n;

    do
    {
        cout << "Enter rows (Must be positive): ";
        cin >> m;
    } while (m <= 0);

    do
    {
        cout << "Enter coloumns (Must be positive): ";
        cin >> n;
    } while (n <= 0);

    int arr[m][n];

    cout << "Enter values for the matrix between 1 and 100" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            do
            {
                cout << "Enter value for " << i << "," << j << " :";
                cin >> arr[i][j];

            } while (arr[i][j] < 1 || arr[i][j] > 100);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}