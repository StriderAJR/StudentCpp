#pragma once

#include <iostream>
using namespace std;

namespace LocalGlobalFormalVariable
{
    int count;

    void func1();
    void func2();

    void LocalGlobalFormalVariable_Main()
    {
        count = 0;

        setlocale(LC_ALL, "rus");

        int t;
        scanf("%d%*c", &t);

        if (t == 1)
        {
            char buf[80];

            printf("¬ведите им€:");
            scanf(buf);
        }

        func1(); func2(); func1();

        cout << count << endl;

        system("pause");
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