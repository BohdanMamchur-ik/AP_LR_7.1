#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void SortCols(int** a, const int rowCount, const int colCount);
void ChangeCols(int** a, const int rowCount, const int col1, const int col2);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    
    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -12;
    int High = 37;
    int rowCount = 7;
    int colCount = 9;

   
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        R[i] = new int[colCount];
    }

   
    Create(R, rowCount, colCount, Low, High);
    cout << "Pochatkova matrytsia R:";
    Print(R, rowCount, colCount);

   
    SortCols(R, rowCount, colCount);
    cout << "Modyfikovana matrytsia (pislya vporadkuvannya stovpzykiv):";
    Print(R, rowCount, colCount);

   
    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);

    cout << "Suma (S) = " << S << endl;
    cout << "Kilkist (k) = " << k << endl;

    cout << "Kintseva matrytsia (z zaminoyu elementiv nuliamy za kryteriyem):";
    Print(R, rowCount, colCount);

    
    for (int i = 0; i < rowCount; i++) {
        delete[] R[i];
    }
    delete[] R;

    return 0;
}


void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}


void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функція сортування стовпчиків за ключами -> -> -> 
void SortCols(int** a, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++) {
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++) {
            if (
                //перший рядок за зростанням
                (a[0][j1] > a[0][j1 + 1])
                ||
                //якщо в першому рядку елементи рівні, порівнюємо другий рядок за зростанням
                (a[0][j1] == a[0][j1 + 1] && a[1][j1] > a[1][j1 + 1])
                ||
                //якщо в першому і другому рядках елементи рівні, порівнюємо третій рядок за зростанням
                (a[0][j1] == a[0][j1 + 1] && a[1][j1] == a[1][j1 + 1] && a[2][j1] > a[2][j1 + 1])
                )
            {
                ChangeCols(a, rowCount, j1, j1 + 1);
            }
        }
    }
}


void ChangeCols(int** a, const int rowCount, const int col1, const int col2)
{
    int tmp;
    for (int i = 0; i < rowCount; i++) {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}


void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            // всі додатні або крім кратних 3 
            if (a[i][j] > 0 || !(a[i][j] % 3 == 0)) {
                S += a[i][j];
                k++;
                a[i][j] = 0; 
            }
        }
    }
}