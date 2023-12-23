#include <iostream>
#include "course.h"

using namespace std;

int main()
{
    setlocale(0, "");
    char input;

Menu: {
    system("cls");
    cout << "Выберите номер лабораторной:" << endl 
         << "1 лабораторная" << endl
         << "2 лабораторная" << endl
         << "3 лабораторная" << endl
         << "4 лабораторная" << endl;
    }
cin >> input;

switch (input) {
case '1': {
    system("cls");
    course1();
    system("pause");
    goto Menu;
}
case '2': {
    system("cls");
    course2();
    system("pause");
    goto Menu;
}
case '3': {
    system("cls");
    course3();
    system("pause");
    goto Menu;
}
case '4': {
    system("cls");
    course4();
    system("pause");
    goto Menu;
}
default: {
    goto Menu;
}
case '5': {
    exit;
}
}
}
