// –ассматриваемые темы:
// ћассив структур    

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

        Point pArray1[5]; // —татическое выделение пам€ти под массив структур
        pArray1[0] = p1;

        Point* pArray2 = new Point[5]; // ƒинамическое выделение пам€ти под массив структур
        pArray2[0] = *p2; // »спользуем оператор "*", чтобы преобразовать указатель в стуктуру, т.е. извлечь по адресу содержимое €чейки пам€ти

        Point** pArray3 = new Point*[5]; // ƒинамическое выделение пам€ти под массив указателей на структуру
                                         // ¬ этом массиве хран€тс€ не сами структуры, а указатели (т.е. адреса) на эти структуры
                                         // —ами структуры размещаютс€ в пам€ти в другом месте, массив хранит только эти адреса

        pArray3[0] = p2;

        cout << pArray1[0].X << "; " << pArray1[0].Y << endl; // 1; 2
        cout << pArray2[0].X << "; " << pArray2[0].Y << endl; // 3; 4
        cout << pArray3[0]->X << "; " << pArray3[0]->Y << endl; // 3; 4
        //  аждый элемент массива pArray3 - указатель (т.е. адрес),
        // то использовать оператор "." нельз€, а нужно использовать оператор "->",
        // чтобы указатель сначала разыменовалс€ и только потом мы "лезли" внутрь объекта.

        delete p2;
        delete[] pArray3;
        delete[] pArray2;

        //  ак заполнить массив стуктур?
        Point* pArray = new Point[2];
        for (int i = 0; i < 2; i++)
        {
            Point p;

            cout << "pArray[" << i << "].X: "; cin >> p.X;
            cout << "pArray[" << i << "].Y: "; cin >> p.Y;

            pArray[i] = p;
        }
        // »ли можно еще короче:
        for (int i = 0; i < 2; i++)
        {
            cout << "pArray[" << i << "].X: "; cin >> pArray[i].X;
            cout << "pArray[" << i << "].Y: "; cin >> pArray[i].Y;
        }
        delete[] pArray;
    }
}