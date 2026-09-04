#include <iostream>
using namespace std;

struct MovieData
{
    char Title[100];
    char Director[100];
    int Year;
    int production_cost;
    int firstyear_revenue;
    int running_time;
};

void inputMovieData(MovieData &mv)
{
    cout << "Enter Title: ";
    cin >> mv.Title;
    cout << "Enter Director: ";
    cin >> mv.Director;
    cout << "Enter Year: ";
    cin >> mv.Year;
    cout << "Enter Production Cost: ";
    cin >> mv.production_cost;
    cout << "Enter Revenue of first year: ";
    cin >> mv.firstyear_revenue;
    cout << "Enter Running Time of movie: ";
    cin >> mv.running_time;
}

void displayMovieData(MovieData mv)
{

    int gross = mv.firstyear_revenue - mv.production_cost;

    cout << "----------------" << endl;
    cout << "Movie Title: " << mv.Title << endl;
    cout << "Movie Director: " << mv.Director << endl;
    cout << "Movie Release Year: " << mv.Year << endl;
    cout << "Movie Running time: " << mv.running_time << " minutes" << endl;
    ;

    if (gross > 0)
        cout << "Movie's first year's profit: " << gross << endl;
    else
        cout << "Movie's first year's loss: " << abs(gross) << endl;

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