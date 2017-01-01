/*
#include <iostream>
#include <string.h>
using namespace std;
 
int sum_by_value(int );// суммирование по значению
int sum_by_reference(int &);// суммирование по ссылке
int sum_by_pointer(int *); // суммирование по указателю
 
int main()
{
	int value = 15;
    int& reference = value; // объ€вление и инициализаци€ ссылки значением переменной value

    cout << "value     = " << value     << endl;
    cout << "reference = " << reference << endl;

	char* string = NULL;

    reference+=15; // измен€ем значение переменной value посредством изменени€ значени€ в ссылке

    cout << "value     = " << value     << endl; // смотрим, что получилось, как будет видно дальше значение помен€лось как в ссылке,
    cout << "reference = " << reference << endl; //  так и в ссылочной переменной

    system("pause");

    value = 10;

    cout << "sum_by_value     = " << sum_by_value(value)     << endl;
    cout << "value = " << value   << endl; // значение переменной осталось неизменным
    cout << "sum_by_reference = " << sum_by_reference(value) << endl;
    cout << "value = " << value   << endl; // значение переменной изменилось
    cout << "sum_by_pointer     = " << sum_by_pointer(&value)  << endl;
    cout << "value = " << value   << endl; // значение переменной изменилось ещЄ раз

    system("pause");

    return 0;
}
 
int sum_by_value(int value)// функци€ принимающа€ аргумент по значению
{
    value += value;
    return value;
}
 
int sum_by_reference(int& reference) // функци€ принимающа€ аргумент по ссылке
{
    reference += reference;
    return reference;
}
 
int sum_by_pointer(int* ptrvalue)// функци€ принимающа€ аргумент через указатель
{
    *ptrvalue += *ptrvalue; // арифметика с указателем
    return *ptrvalue;
}
*/