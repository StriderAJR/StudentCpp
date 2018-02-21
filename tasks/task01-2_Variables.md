# Лабораторная 1-2. Переменные и операторы
Изучаемые темы: переменная, типы данных, оператор, приведение типов

### Теория
* [Переменные и операторы](https://github.com/StriderAJR/StudentCpp/wiki/Переменные-и-операторы)
* [Локальные и глобальные переменные](https://github.com/StriderAJR/StudentCpp/wiki/Локальные-и-глобальные-переменные)

### Пример
```C++
#include <iostream>
using namespace std;

int globalVariable;

void main()
{ // НАЧАЛО БЛОКА КОДА
    globalVariable = 1;

    { // НАЧАЛО БЛОКА КОДА
        int localVariable1 = 10;
        double localVariable2 = 2.5;
        
        { // НАЧАЛО БЛОКА КОДА
            localVariable2 = 4.5;

            cout << localVariable1 << endl;
            cout << localVariable2 << endl;
            cout << globalVariable << endl;
        } // КОНЕЦ БЛОКА КОДА

        localVariable1++;
        globalVariable++;

        cout << localVariable1 << endl;
        cout << localVariable2 << endl;
        cout << globalVariable << endl;
    } // КОНЕЦ БЛОКА КОДА

//    cout << localVariable1 << endl; // ОШИБКА
//    cout << localVariable2 << endl; // ОШИБКА
    cout << globalVariable << endl;


    //////////////////////
    // ОПЕРАТОРЫ
    //////////////////////

    int aa = 10, bb = 5;
    aa++;
    bb--;    
    aa *= 5;
    bb /= 2;

    bool flag = aa && bb;
    flag = aa && false;
    flag = aa || false;

    int bit = ~aa;
    bit = aa & bb;
    bit = aa | bb; 

    //////////////////////
    // Приведение типов
    //////////////////////
    cout << endl << "TYPE CASTING" << endl << endl;
    double var1 = 10.25;
    cout << var1 << endl;

    int var2 = var1;
    cout << var2 << endl;

    char var3 = 'Z';
    var2 = var3;
    cout << var3 << " = " << var2 << endl;

    float var5 = 4.9999;
    cout << var5 << endl;
    double var6 = 4.9999;
    cout << var6 << endl;

    int a, c; double b;
    cin >> a >> b >> c;

    double result1 = (a + b) / c;

    cout << result1 << endl;

    int d, e;
    cin >> d >> e;

    double result2 = d / e;
    double result3 = (double) d / e;

    cout << result2 << endl << result3 << endl;
} // КОНЕЦ БЛОКА КОДА
```
### Приступая к работе...
1. Что такое оператор
1. Оператор ++, -- и т.д. Это краткие записи каких операторов
1. Что хранит тип данных bool
1. Разница между операторами && и &, || и |. Что делает оператор ~
1. Узнать значения каждой переменной на каждом этапе выполнения программы
1. Разница между типом данных float и double
1. Что такое приведение типов
1. Почему result2 и result3 хранят разное значение, хотя имеют один и тот же тип данных и им присваивается результат одного и того же математического выражения.

### Задание
Исправить ошибку в коде и вычислить выражение:
```
float c = 1.2;
double d = 4;
int a = 5;
unsigned int b = -10;
long l = 10000;
int floatedNumber = l / c;
int integerPart = floatedNumber;

a = a++;

... result = integerPart * b - c/d;
cout << result;

```
