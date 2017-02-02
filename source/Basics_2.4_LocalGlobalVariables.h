// Рассматриваемые темы:
// Подробнее про локальные и глобальные переменные

#pragma once

#include <iostream>
using namespace std;

namespace LocalGlobalVariables
{
    int count;

    void func1();
    void func2();

    void main()
    {
        count = 0;

        setlocale(LC_ALL, "rus");

        int t;
        cin >> t;

        if (t == 1)
        {
            char buf[80];

            cout << "Введите имя:";
            cin >> buf;
        }

        func1(); func2(); func1();

        cout << count << endl;

//        system("pause");
    }

    void func1()
    {
        int x = 10;

        count++;
    }

    void func2()
    {
        int x = -199;

        count++;
    }
}