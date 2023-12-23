#include "course.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int choise;
const int size_matr = 8;

//рандомная генерация чисел от 1 до 64
int randArr()
{
    return (rand() % 64) + 1;
}

//создание матрицы
void matr(int arr[][size_matr])
{
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < size_matr; i++)
    {
        for (int j = 0; j < size_matr; j++)
        {
            destCoord.X = j * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(arr + i) + j);
            Sleep(100);
        }
        cout << endl << endl;
    }
}
//вывод матрицы змейкой
void snake(int arr[][size_matr])
{
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int top = 0, bot = size_matr - 1, left = 0, right = size_matr - 1;
    while (left <= right && top <= bot)
    {
        //сверху вниз
        for (int i = top; i <= bot; i++)
        {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            Sleep(100);
        }
        left++;
        //снизу вверх
        for (int i = bot; i >= top; i--)
        {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = size_matr * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}
//вывод матрицы спиралью
void spiral(int arr[][size_matr])
{
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int num = 0;
    int top = 0, bot = size_matr - 1, left = 0, right = size_matr - 1;
    while (left <= right && top <= bot)
    {
        //верхняя строка
        for (int i = left; i <= right; i++)
        {
            destCoord.X = i * 4;
            destCoord.Y = top * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + top) + i) = randArr();
            cout << *(*(arr + top) + i);
            cout.flush();
            Sleep(100);
        }
        top++;
        //правый столбец
        for (int i = top; i <= bot; i++)
        {
            destCoord.X = right * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + right) = randArr();
            cout << *(*(arr + i) + right);
            cout.flush();
            Sleep(100);
        }
        right--;
        //нижняя строка
        for (int i = right; i >= left; (i--))
        {
            destCoord.X = i * 4;
            destCoord.Y = bot * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + bot) + i) = randArr();
            cout << *(*(arr + bot) + i);
            cout.flush();
            Sleep(100);
        }
        bot--;
        //левый столбец
        for (int i = bot; i >= top; i--)
        {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = size_matr * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void smena(int arr[][size_matr])
{
    cout << endl << "Способ смены: ";
    cin >> choise;
    //смена по часовой
    if (choise == 1) {
        for (int i = 0; i < (size_matr / 2); i++)
        {
            for (int j = 0; j < size_matr; j++)
            {
                swap(*(*(arr + i + (size_matr / 2)) + j), *(*(arr + i) + j));
            }
        }
        for (int i = 0; i < (size_matr / 2); i++)
        {
            for (int j = 0; j < (size_matr / 2); j++)
            {
                swap(*(*(arr + i + (size_matr / 2)) + j + (size_matr / 2)), *(*(arr + i) + j));
            }
        }
    }
    //смена по диагонали
    else if (choise == 2)
    {
        for (int i = 0; i < (size_matr / 2); i++)
        {
            for (int j = 0; j < size_matr; j++)
            {
                if (j < (size_matr / 2))
                {
                    swap(*(*(arr + i) + j), *(*(arr + i + (size_matr / 2)) + j + (size_matr / 2)));
                }
                else
                {
                    swap(*(*(arr + i) + j), *(*(arr + i + (size_matr / 2)) + j - (size_matr / 2)));
                }
            }
        }
    }
    //смена (верхние и нижние)
    else if (choise == 3)
    {
        for (int i = 0; i < (size_matr / 2); i++)
        {
            for (int j = 0; j < size_matr; j++)
            {
                swap(*(*(arr + i) + j), *(*(arr + i + (size_matr / 2)) + j));
            }
        }
    }
    //смена (правые и левые)
    else if (choise == 4)
    {
        for (int i = 0; i < size_matr; i++)
        {
            for (int j = 0; j < (size_matr / 2); j++)
            {
                swap(*(*(arr + i) + j), *(*(arr + i) + j + (size_matr / 2)));
            }
        }
    }
    else
    {
        cout << endl << "Неправильно выбран способ, выберите тот, который надо!";
    }
}

//сортировка
void insert(int* ptr, int* end)
{
    int j;
    for (int* i = ptr + 1; i <= end; i++)
    {
        if (*i < *(i - 1))
        {
            for (j = *i; i > ptr && *(i - 1) > j; i--)
            {
                *i = *(i - 1);
            }
            *i = j;
        }

    }
}

void mathar(int arr[][size_matr]) {
    char sign;
    int number;
    cout << endl << "Введите действие('+', '-', '*', '/') и число: " << endl;
    cin >> sign >> number;

    if (sign == '+')
    {
        for (int i = 0; i < size_matr; i++)
        {
            for (int j = 0; j < size_matr; j++)
                *(*(arr + i) + j) += number;
        }
    }
    else if (sign == '-') {
        for (int i = 0; i < size_matr; i++)
        {
            for (int j = 0; j < size_matr; j++)
                *(*(arr + i) + j) -= number;
        }
    }
    else if (sign == '*')
    {
        for (int i = 0; i < size_matr; i++)
        {
            for (int j = 0; j < size_matr; j++)
                *(*(arr + i) + j) *= number;
        }
    }
    else if (sign == '/')
    {
        for (int i = 0; i < size_matr; i++)
        {
            for (int j = 0; j < size_matr; j++)
                *(*(arr + i) + j) /= number;
        }
    }
    else
    {
        cout << "Выбрано неправильное число или знак";
    }
}

//идз
// Инициализация генератора случайных чисел
const int N = 8;
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Функция для заполнения матрицы случайными числами от 1 до 64
void fillMatrix(int matrix[][N], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = getRandomNumber(1, 36);
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int matrix[][N], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для перемножения матрицы A на матрицу B
void multiplyMatrices(const int matrixA[][N], const int matrixB[][N], int resultMatrix[][N]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}


void course3() {
    setlocale(0, "RU");
    int arr[size_matr][size_matr];
    int* ptr = *arr, * end = *arr + size_matr * size_matr - 1;
    while (true)
    {
        cout << "Выберите пункт: " << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:

            cout << endl;
            cout << "Выберите способ заполнения(1-2): ";
            cin >> choise;
            if (choise == 1)
            {
                spiral(arr);
            }
            else if (choise == 2)
            {
                snake(arr);
            }
            else
                cout << endl << "Такого варинта нет(" << endl;
            break;

        case 2:
            matr(arr);
            smena(arr);
            matr(arr);
            break;

        case 3:
            insert(ptr, end);
            matr(arr);
            break;

        case 4:
            mathar(arr);
            matr(arr);
            break;

        case 5:
            srand(time(nullptr));

            int matrixA[N][N];
            int matrixB[N][N];
            int resultMatrix[N][N];

            fillMatrix(matrixA, N, N);
            fillMatrix(matrixB, N, N);

            cout << "Матрица A: " << endl;
            printMatrix(matrixA, N, N);

            cout << endl << "Матрица B: " << endl;
            printMatrix(matrixB, N, N);

            multiplyMatrices(matrixA, matrixB, resultMatrix);

            cout << endl << "Результирующая матрица: " << endl;
            printMatrix(resultMatrix, N, N);

        case 6:
            exit(0);
            break;
        }
    }

}
