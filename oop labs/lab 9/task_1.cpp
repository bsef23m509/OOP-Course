#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows;
    int cols;

public:
    Matrix()
    {
        data = NULL;
        rows = 0;
        cols = 0;
    }

    Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
            return;

        this->rows = rows;
        this->cols = cols;

        this->data = new int *[cols];
        for (int i = 0; i < cols; i++)
        {
            this->data[i] = new int[rows];
        }
    }

    ~Matrix()
    {
        if (data == NULL)
            return;

        for (int i = 0; i < cols; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix(Matrix &other)
    {

        if (other.getDataPtr() == NULL)
            return;

        // if (this->data != NULL)
        // {
        //     for (int i = 0; i < cols; i++)
        //     {
        //         delete[] data[i];
        //     }
        //     delete[] data;
        // }

        this->rows = other.getRows();
        this->cols = other.getCols();

        this->data = new int *[cols];
        for (int i = 0; i < cols; i++)
        {
            this->data[i] = new int[rows];
        }

        int **otherData = other.getDataPtr();

        this->fillData(this->rows, this->cols, otherData);
    }

    int getRows() const
    {
        return this->rows;
    }

    int getCols() const
    {
        return this->cols;
    }

    int **getDataPtr() const
    {
        return this->data;
    }

    void print() const
    {

        if (this->data == NULL)
        {
            cout << "No Values" << endl;
            cout << endl;
            return;
        }

        cout << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
                cout << this->data[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    void fillData(const int rows, const int cols, int **data)
    {

        if (this->rows != rows || this->cols != cols)
            return;

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                this->data[i][j] = data[i][j];
    }

    Matrix operator+(Matrix &other) const
    {

        if (this->rows != other.getRows() || this->cols != other.getCols())
            return Matrix();

        Matrix res(this->rows, this->cols);

        int **resData = res.getDataPtr();
        int **otherData = other.getDataPtr();

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                resData[i][j] = this->data[i][j] + otherData[i][j];

        return res;
    }

    Matrix &operator+=(Matrix &other)
    {

        if (this->rows != other.getRows() || this->cols != other.getCols())
            return *this;

        int **otherData = other.getDataPtr();

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                this->data[i][j] += otherData[i][j];

        return *this;
    }

    Matrix operator-(Matrix &other) const
    {
        if (this->rows != other.getRows() || this->cols != other.getCols())
            return Matrix();

        Matrix res(this->rows, this->cols);

        int **resData = res.getDataPtr();
        int **otherData = other.getDataPtr();

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                resData[i][j] = this->data[i][j] - otherData[i][j];

        return res;
    }

    Matrix &operator-=(Matrix &other)
    {
        if (this->rows != other.getRows() || this->cols != other.getCols())
            return *this;

        int **otherData = other.getDataPtr();

        for (int i = 0; i < cols; i++)
            for (int j = 0; j < rows; j++)
                this->data[i][j] -= otherData[i][j];

        return *this;
    }
};

int main()
{

    int rows, cols;
    int **matrixData;

    cout << "Initialize First Matrix" << endl;

    cout << "Enter Rows (greater than 0)" << endl;
    do
    {
        cin >> rows;
    } while (rows <= 0);

    cout << "Enter Cols (greater than 0)" << endl;
    do
    {
        cin >> cols;
    } while (cols <= 0);

    Matrix m1(rows, cols);

    matrixData = m1.getDataPtr();

    cout << "Enter Values" << endl;
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
        {
            cin >> matrixData[i][j];
        }

    cout << "Initialize Second Matrix" << endl;

    cout << "Enter Rows (greater than 0)" << endl;
    do
    {
        cin >> rows;
    } while (rows <= 0);

    cout << "Enter Cols (greater than 0)" << endl;
    do
    {
        cin >> cols;
    } while (cols <= 0);

    Matrix m2(rows, cols);

    matrixData = m2.getDataPtr();

    cout << "Enter Values" << endl;
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
        {
            cin >> matrixData[i][j];
        }

    cout << "Original Matrices" << endl;
    m1.print();
    m2.print();

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
    {
        cout << "Rows and Coloumn not Equal" << endl;
        return 0;
    }

    cout << "+= first and second matrix" << endl;
    m1 += m2;
    m1.print();
    cout << "-= first and second matrix" << endl;
    m1 -= m2;
    m1.print();

    cout << "Adding both matrices" << endl;
    Matrix res1 = m1 + m2;
    res1.print();

    cout << "Subtracting both matrices" << endl;
    Matrix res2 = m1 - m2;
    res2.print();

    return 0;
}