#include <iostream>
using namespace std;

namespace SuperString
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

        void Print()
        {
            cout << "(" << X << ", " << Y << ")" << endl;
        }
    };

    template<class T>
    struct ListElem
    {
        T Obj;
        ListElem* Next;
    };

    template<class T>
    class List
    {
        ListElem<T>* Head;
        ListElem<T>* Last;

    public:
        List() : Head(NULL)
        {}

        void Add(T elem)
        {
            if (Head == NULL)
            {
                Head = new ListElem<T>();
                Head->Obj = elem;
                Head->Next = NULL;
                Last = Head;
            }
            else
            {
                Last->Next = new ListElem<T>();
                Last->Next->Obj = elem;
                Last->Next->Next = NULL;
                Last = Last->Next;
            }
        }

        ListElem<T>* GetIterator()
        {
            return Head;
        }
    };


    void SuperString_Main()
    {
        // Список чисел
        List<int> list;
        list.Add(1);
        list.Add(2);
        list.Add(3);
        list.Add(4);
        list.Add(5);

        auto iterator = list.GetIterator();
        // Используйте auto только если вы знаете, что это такое.
        // Потому что на защите вас обязательно спросят, что это такое.
        // Если эта материя для вас еще сложна, используйте стандартное:
        // ListElem<int>* iterator = list.GetIterator();
        while (iterator != NULL)
        {
            cout << iterator->Obj << ' ';
            iterator = iterator->Next;
        }
        cout << endl;

        // Список векторов
        List<Vector> list2;
        list2.Add(Vector(10, 20));
        list2.Add(Vector(30, 40));

        auto iterator2 = list2.GetIterator();
        while (iterator2 != NULL)
        {
            iterator2->Obj.Print();
            iterator2 = iterator2->Next;
        }
    }
}