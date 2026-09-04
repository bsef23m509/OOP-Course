#include <iostream>
using namespace std;

// Q! (a)

// int main()
// {

//     int size, i;

//     // taking input of size of array
//     cout << "Enter size of array: ";
//     cin >> size;

//     //  creating an array with given size
//     int *arr = new int[size];

//     //  taking elements of the array from user
//     cout << "Enter elements of array: " << endl;
//     for (i = 0; i < size; i++)
//     {
//         cin >> arr[i];
//     }

//     //  printing the even elements of array
//     cout << "Even elements of array are: " << endl;
//     for (i = 0; i < size; i++)
//     {
//         if (arr[i] % 2 == 0)
//             cout << arr[i] << endl;
//     }

//     return 0;
// }

// Q! (b)

// int main()
// {

//     int size = 100, count = 0, i;

//     //  creating an array with given size
//     int *arr = new int[size];

//     //  taking elements of the array from user

//     cout << "Enter elements of array (enter -1 to exit): " << endl;
//     while (true)
//     {

//         // terminating loop count exceeds 99 which is maximum index in our case.
//         if (count > 99)
//             break;

//         cin >> arr[count];

//         // terminating loop if number entered is -1 or count exceeds 99 which is maximum index in our case.
//         if (arr[count] == -1)
//             break;

//         count++;
//     }

//     //  printing the elements of even indexes of array
//     cout << "Even index elements of array are: " << endl;

//     for (i = 0; i < count; i++)
//     {
//         if (i % 2 == 0)
//             cout << arr[i] << endl;
//     }

//     return 0;
// }

// Q2
int getMin(int *ptr, int size)
{

    // setting min_val and min_val_index varible to first element
    int min_val = ptr[0], min_val_index = 0, i;

    //  traversing through each element of array
    for (i = 1; i < size; i++)
    {
        //  If current element is smaller than min_val then update min_val and min_val_index
        if (ptr[i] < min_val)
        {
            min_val = ptr[i];
            min_val_index = i;
        }
    }

    return min_val_index;
}

int main()
{

    int size, i;

    // taking input of size of array
    cout << "Enter size of array: ";
    cin >> size;

    //  creating an array with given size
    int *arr = new int[size];

    //  taking elements of the array from user
    cout << "Enter elements of array: " << endl;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    //  printing the index of minimum value of array by calling getMin function
    cout << "Index of minimum value of array is: " << getMin(arr, size) << endl;

    return 0;
}