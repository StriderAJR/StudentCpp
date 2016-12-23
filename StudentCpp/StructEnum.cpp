#include <iostream>
using namespace std;

namespace StructEnum
{
    struct Point
    {
        int X;
        int Y;
    };

    enum MoneyType
    {
        Dollar,
        Euro,
        Ruble
    };

    struct MyStruct
    {
        int Num;
        MoneyType Money;
    };

    int StructEnum_Main()
    {
        Point p1; // —татическое создание переменной типа структура
        Point* p2 = new Point; // ƒинамическое создание переменной типа структура

        p1.X = 1; // ќператор "." - получение доступа к внутреннему содержимому переменной составного типы
        p1.Y = 2;

        p2->X = 3; // ќператор "->" - то же, что и ".", но примен€етс€, если переменна€ состоавного типа - это указатель
        p2->Y = 4; // (*p2).Y = 4 - это аналогична€ запись, т.е. "->" просто более компактна€ запись

        cout << p2->X << endl; // 3
        cout << (*p2).X << endl; // 3

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
        // “.е. каждый элемент массива pArray3 - указатель (т.е. адрес),
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

        // ѕеречислени€ штука несложна€
        MyStruct s;
        s.Num = 666;
        s.Money = Dollar;

        if (s.Money == Dollar)
            cout << "$";
        if (s.Money == Euro)
            cout << "Yohoo";
        if (s.Money == Ruble)
            cout << "Loser";
    }
}
