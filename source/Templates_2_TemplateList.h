#pragma once

#include <iostream>
using namespace std;

namespace TemplateList
{
    class Vector
    {
        int x, y;
    public:
        Vector() : x(0), y(0)
        {
        }

        Vector(int x, int y) : x(x), y(y)
        {
        }

        friend ostream& operator<<(ostream& os, Vector& v)
        {
            return os << "(" << v.x << ", " << v.y << ")";
        }
    };

    template<class T>
    class List
    {
        struct ListElem
        {
            T obj;
            ListElem* next;
        };

        ListElem* head;
        ListElem* last;
        ListElem* iterator;

    public:
        List() : head(nullptr)
        {}

        void Add(T elem)
        {
            if (head == nullptr)
            {
                head = new ListElem;
                head->obj = elem;
                head->next = nullptr;
                last = head;
            }
            else
            {
                last->next = new ListElem;
                last->next->obj = elem;
                last->next->next = nullptr;
                last = last->next;
            }
        }

        void begin()
        {
            iterator = head;
        }

        void next()
        {
            iterator = iterator->next;
        }

        T& getCurrent()
        {
            return iterator->obj;
        }

        bool isEnd()
        {
            return iterator == nullptr;
        }
    };


    void main()
    {
        // Список чисел
        List<int> list;
        list.Add(1);
        list.Add(2);
        list.Add(3);
        list.Add(4);
        list.Add(5);

        for (list.begin(); !list.isEnd(); list.next())
        {
            cout << list.getCurrent() << ' ';
        }
        cout << endl;

        // Список векторов
        List<Vector> list2;
        list2.Add(Vector(10, 20));
        list2.Add(Vector(30, 40));

        for (list2.begin(); !list2.isEnd(); list2.next())
        {
            cout << list2.getCurrent() << ' ';
        }
    }
}