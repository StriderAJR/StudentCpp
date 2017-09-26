// Рассматриваемые темы:
// Виртуальные функции

#pragma once

#include <iostream>

using namespace std;

namespace VirtualFunctions
{
    class Base
    {
    public:
        virtual void  function1() { cout << "Base::function1()" << endl; }
        void          function2() { cout << "Base::function2()" << endl; }
    };

    class Child : public Base
    {
    public:
        virtual void  function1() { cout << "Child::function1()" << endl; }
        void          function2() { cout << "Child::function2()" << endl; }
    };

    void main()
    {
        Child*  pointer = new Child();
        Base*    pointer_copy = pointer;

        pointer->function1();
        pointer->function2();

        pointer_copy->function1();
        pointer_copy->function2();

        cout << "=========================" << endl;

        Child d; Base a;
        d.function1(); d.function2();
        a.function1(); a.function2();

        system("pause");
    }
}