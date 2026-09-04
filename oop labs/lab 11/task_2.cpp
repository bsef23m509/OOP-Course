#include <iostream>
using namespace std;

class ScoreKeeper
{
private:
    string course;
    int scoresCount;
    int *scores;

public:
    ScoreKeeper()
    {
        this->course = "";
        this->scoresCount = 0;
        this->scores = NULL;
    }

    ~ScoreKeeper()
    {
        if (scores != NULL)
            delete[] scores;
    }

    ScoreKeeper(string course, int scoreCount)
    {
        this->course = course;
        this->scoresCount = scoreCount;
        this->scores = new int[scoreCount];

        this->fillScores();
    }

    void fillScores()
    {
        cout << "Enter the scores for " << course << ": " << endl;
        for (int i = 0; i < scoresCount; i++)
        {
            do
            {
                cout << "Enter Score Number " << i << " (From 0 to 100) : ";
                cin >> scores[i];
            } while (scores[i] < 0 || scores[i] > 100);
        }
    }

    friend ostream &operator<<(ostream &out, const ScoreKeeper &obj)
    {
        out << "Course: " << obj.course << endl;
        out << "Scores Count: " << obj.scoresCount << endl;
        out << "Scores: ";
        for (int i = 0; i < obj.scoresCount; i++)
            out << obj.scores[i] << " ";

        out << endl;

        return out;
    }

    void operator=(ScoreKeeper &other)
    {
        if (&other == this)
            return;

        this->course = other.course;
        this->scoresCount = other.scoresCount;

        if (this->scores != NULL)
        {
            delete[] scores;
        }

        this->scores = new int[this->scoresCount];

        for (int i = 0; i < this->scoresCount; i++)
            this->scores[i] = other.scores[i];
    }

    int operator[](int k)
    {

        if (k >= scoresCount || k < 0)
            return -1;

        return this->scores[k];
    }
};

int main()
{

    string course;
    int scoresCount;

    cout << "Enter course: ";
    cin >> course;
    cout << "Enter ScoresCount: ";
    cin >> scoresCount;

    ScoreKeeper s1(course, scoresCount);
    ScoreKeeper s2;

    s2 = s1;

    cout << s2 << s2[2] << " " << s2[10];

    return 0;
}