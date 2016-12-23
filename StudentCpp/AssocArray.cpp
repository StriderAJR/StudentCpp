#include <iostream>
using namespace std;

namespace AssocArray
{
    class AssocArray
    {
    private:
        struct ArrayData
        {
            int Data;
            char* Key;

            ArrayData() {}

            ArrayData(char* key)
            {
                Key = new char[strlen(key) + 1];
                strcpy(Key, key);
                Key[strlen(key)] = '\0';
            }
        };

        ArrayData* _Array;
        unsigned int _Memory = 5; // Кол-во элементов, под которые выделена память
        int _Index = -1; // Индекс последнего элемента
    public:
        AssocArray()
        {
            _Array = new ArrayData[_Memory];
        }

        ~AssocArray()
        {
            delete[] _Array;
        }

        int& operator [](char* key)
        {
            for (int i = 0; i <= _Index; i++)
            {
                if (strcmp(_Array[i].Key, key) == 0)
                {
                    return _Array[i].Data;
                }
            }

            if (_Index + 1 < _Memory)
            {
                _Array[++_Index] = ArrayData(key);
                return _Array[_Index].Data;
            }
            else
            {
                // Array Resize
            }
        }
    };

    void AssocArray_Main()
    {
        AssocArray arr;
        arr["First"] = 555;

        cout << arr["First"] << endl;
    }
}