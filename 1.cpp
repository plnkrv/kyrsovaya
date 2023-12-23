#include "course.h"
#include <iostream>

using namespace std;

void course1() {
    cout << "int: " << sizeof(int) << '\n' << "short int: " << sizeof(short int) << '\n' << "long int: " << sizeof(long int) << '\n' << "float: " << sizeof(float) << '\n' << "double: " << sizeof(double) << '\n' << "long double: " << sizeof(long double) << '\n' << "char: " << sizeof(char) << '\n' << "bool: " << sizeof(bool) << '\n';
    int inpint;
    cout << "input int: ";
    cin >> inpint;
    int numdig = sizeof(inpint) * 8;
    unsigned int mask = 1 << numdig - 1;
    for (int i = 1; i <= numdig; i++)
    {
        putchar(inpint & mask ? '1' : '0');
        mask >>= 1;
        if (i % 8 == 0)
        {
            cout << ' ';
        }
        if (i % numdig - 1 == 0)
        {
            cout << ' ';
        }
    }
    union {
        float inpflt;
        int intflt;
    };
    cout << '\n' << "input float: ";
    cin >> inpflt;
    numdig = sizeof(inpflt) * 8;
    mask = 1 << numdig - 1;
    for (int i = 1; i <= numdig; i++)
    {
        putchar(intflt & mask ? '1' : '0');
        mask >>= 1;
        if (i == 9)
        {
            cout << ' ';
        }
        if (i == 1)
        {
            cout << ' ';
        }
    }
    union {
        double inpdbl;
        int intdbl[2];
    };
    cout << '\n' << "input double: ";
    cin >> inpdbl;
    numdig = sizeof(int) * 8;
    mask = 1 << numdig - 1;
    for (int i = 1; i <= numdig; i++)
    {
        putchar(intdbl[1] & mask ? '1' : '0');
        mask >>= 1;
        if (i == 12)
        {
            cout << ' ';
        }
        if (i == 1)
        {
            cout << ' ';
        }
    }
    mask = 1 << numdig - 1;
    for (int i = 1; i <= numdig; i++)
    {
        putchar(intdbl[0] & mask ? '1' : '0');
        mask >>= 1;
    }
}
