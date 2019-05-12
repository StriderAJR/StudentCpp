#pragma once

#include <iostream>
#include <list>
using namespace std;

namespace Templates
{
    class Vector
    {
        int X, Y;
    public:
        Vector() : X(0), Y(0)
        {
        }

        Vector(int x, int y) : X(x), Y(y)
        {
        }

        friend ostream& operator<<(ostream& os, Vector& v)
        {
            return os << "(" << v.X << ", " << v.Y << ")";
        }
    };

    template <class T>
    class List
    {
        T* Elements;
        unsigned int Size;
        int LastIndex;

        void Resize()
        {
            int newSize = Size + Size / 2;
            if (Size == 0)
                newSize = 2;

            Resize(newSize);
        }

        void Resize(int size)
        {
            T* newElements = new T[size];

            for (int i = 0; i < Size; i++)
                newElements[i] = Elements[i];

            delete Elements;
            Elements = newElements;
            Size = size;
        }

    public:
        List() : Size(0), LastIndex(-1)
        {
            Elements = new T[Size];
        }

        List(int size) : Size(size), LastIndex(-1)
        {
            Elements = new T[Size];
        }

        unsigned int GetSize() const
        {
            return Size;
        }

        unsigned int GetLastIndex() const
        {
            return LastIndex;
        }

        void Add(T elem)
        {
            if (LastIndex >= Size - 1)
                Resize();

            Elements[++LastIndex] = elem;
        }

        List operator+(List<T> list)
        {
            int newSize = Size + list.GetSize();
            if (LastIndex > newSize - 1)
                Resize(newSize);

            for (int i = 0; i <= list.GetLastIndex(); i++)
            {
                Elements[++LastIndex] = list[i];
            }

            return *this;
        }

        T operator[](unsigned int index) const
        {
            if (index > LastIndex)
            {
                throw new exception("Index is out of range.");
            }
            return Elements[index];
        }

        T GetElement(unsigned int index)
        {
            if (index > LastIndex)
            {
                throw new exception("Index is out of range.");
            }
            return Elements[index];
        }

        template <class T2>
        friend ostream& operator<<(ostream& os, const List<T2>& l);
    };

    template <class T>
    ostream& operator<<(ostream& os, const List<T>& l)
    {
        for (int i = 0; i <= l.LastIndex; i++)
        {
            os << l.Elements[i];
            if (i != l.LastIndex)
                os << ", ";
        }

        return os;
    }

    void main()
    {
        cout << "HellO!" << endl;

        List<int> list;
        int Num = 10;
        list.Add(Num);
        list.Add(20);
        list.Add(30);
        list.Add(40);
        list.Add(50);
        list.Add(60);

        cout << list[0] << endl;
        cout << list << endl;

        for (int i = 0; i < 100; i++)
            list.Add(i);

        cout << list << endl;

        List<int> list2;
        list2.Add(11);

        list = list + list2;

        cout << endl;
        cout << list << endl;


        List<Vector> list3;
        list3.Add(Vector(1, 2));

        cout << endl << list3 << endl;
    }
}
