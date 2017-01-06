// Рассматриваемые темы:
// Абстрактный класс, чисто виртуальные функции, полиморфизм

#pragma once

#include <iostream>
using namespace std;

namespace Polymorph
{
    class Base
    {
    public:
        virtual void Print() = 0;
        virtual void Type() = 0;
    };

    class Element : public Base
    {
    public:
        void Print() override
        {
            cout << "I'm Element!" << endl;
        }

        virtual void Type()
        {
            cout << "Element" << endl;
        }
    };

    class Container : public Base
    {
        Base** elements;
        int index;
    public:
        Container()
        {
            elements = new Base*[100];
            index = 0;
        }

        void Add(Base* b)
        {
            elements[index++] = b;
        }

        virtual void Type()
        {
            cout << "Container" << endl;
        }
        void Print() override
        {
            cout << "I'm Conrainer!" << endl;
            for (int i = 0; i < index; i++)
            {
                elements[i]->Type();
            }
        }
    };

    void main()
    {
        Element* e = new Element();
        Base* pb = (Base*)e;
        pb->Print();

        Base* pb2 = (Base*) new Container();
        pb2->Print();

        Container c;
        c.Add(new Element());
        c.Add(new Container());
        c.Print();

        Element e2;
//        Base b; // Здесь выдаст ошибку, что невозможно создать объект абстрактного класса
    }
}