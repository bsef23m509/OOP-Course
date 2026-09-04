#include <iostream>
using namespace std;

struct MovieData
{
    char Title[100];
    char Director[100];
    int Year;
};

void inputMovieData(MovieData &mv)
{
    cout << "Enter Title: ";
    cin >> mv.Title;
    cout << "Enter Director: ";
    cin >> mv.Director;
    cout << "Enter Year: ";
    cin >> mv.Year;
}

void displayMovieData(MovieData mv)
{

    cout << "----------------" << endl;
    cout << "Movie Title: " << mv.Title << endl;
    cout << "Movie Director: " << mv.Director << endl;
    cout << "Movie Release Year: " << mv.Year << endl;

    cout << "----------------" << endl;
    cout << endl;
}

int main()
{

    MovieData mv1, mv2;

    inputMovieData(mv1);
    displayMovieData(mv1);

    inputMovieData(mv2);
    displayMovieData(mv2);

    return 0;
}