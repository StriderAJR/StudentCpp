// Рассматриваемые темы:
// Массив структур    

#pragma once
#include <iostream>
using namespace std;

namespace StructArray
{
    struct Point
    {
        int X;
        int Y;
    };

    void main()
    {
        Point p1;
        Point* p2 = new Point; 

        p1.X = 1;
        p1.Y = 2;

        p2->X = 3;
        (*p2).Y = 4;

        Point pArray1[5]; // Статическое выделение памяти под массив структур
        pArray1[0] = p1;

        Point* pArray2 = new Point[5]; // Динамическое выделение памяти под массив структур
        pArray2[0] = *p2; // Используем оператор "*", чтобы преобразовать указатель в стуктуру, т.е. извлечь по адресу содержимое ячейки памяти

        Point** pArray3 = new Point*[5]; // Динамическое выделение памяти под массив указателей на структуру
                                         // В этом массиве хранятся не сами структуры, а указатели (т.е. адреса) на эти структуры
                                         // Сами структуры размещаются в памяти в другом месте, массив хранит только эти адреса

        pArray3[0] = p2;

        cout << pArray1[0].X << "; " << pArray1[0].Y << endl; // 1; 2
        cout << pArray2[0].X << "; " << pArray2[0].Y << endl; // 3; 4
        cout << pArray3[0]->X << "; " << pArray3[0]->Y << endl; // 3; 4
        // Каждый элемент массива pArray3 - указатель (т.е. адрес),
        // то использовать оператор "." нельзя, а нужно использовать оператор "->",
        // чтобы указатель сначала разыменовался и только потом мы "лезли" внутрь объекта.

        delete p2;
        delete[] pArray3;
        delete[] pArray2;

        // Как заполнить массив стуктур?
        Point* pArray = new Point[2];
        for (int i = 0; i < 2; i++)
        {
            Point p;

            cout << "pArray[" << i << "].X: "; cin >> p.X;
            cout << "pArray[" << i << "].Y: "; cin >> p.Y;

            pArray[i] = p;
        }
        // Или можно еще короче:
        for (int i = 0; i < 2; i++)
        {
            cout << "pArray[" << i << "].X: "; cin >> pArray[i].X;
            cout << "pArray[" << i << "].Y: "; cin >> pArray[i].Y;
        }
        delete[] pArray;
    }
}