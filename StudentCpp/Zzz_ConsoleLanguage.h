// Рассматриваемые темы:
// Переключение языка отображения консоли

#pragma once

#include <iostream>
using namespace std;

namespace ConsoleLanguage
{
    void main()
    {
        cout << "Привет!" << endl; // Выведутся кракозябры
        setlocale(0, "Rus");
        cout << "Привет!" << endl; // А вот теперь будет нормально
    }
}
