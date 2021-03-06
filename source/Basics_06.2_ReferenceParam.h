// Рассматриваемые темы:
// Передача параметров по значени и по ссылке

#pragma once

#include <iostream>
using namespace std;

namespace ReferenceParam
{
    // Существует 2 способа передачи параметров:
    // По занчению и по ссылке.

    // ============================= Передача по занчению ===========================
    // При передаче параметра по значению происходит КОПИРОВАНИЕ переменной
    // У вас есть переменная, вы хотите передать ее в ф-цию, как параметр
    // В этом случае при запуске ф-ции в памяти создастся вторая ячейка памяти
    // того же типа, что и ваша переменная, а значение переменной скопируется в параметр
    // Работа внутри ф-ции будет происходить с КОПИЕЙ вашей оригинальной переменной
    // Как и любая локальная переменная, параметр после выполнения ф-ции будет уничтожен
    // Все изменения, которые были внутри ф-ции, над параметром соответственно не сохранятся.

    // ============================== Передача по ссылке ============================
    // При передаче параметра по ссылке создается АЛЬТЕРНАТИВНОЕ ИМЯ переменной, т.е. ссылка
    // Соответственно копия, как при передаче по значению не создается.
    // Внутри ф-ции вы работаете с той же ячейкой памяти, которую передаете как параметр
    // Все изменения, которые производились над параметров ВЛИЯЮТ на оригинальную ячейку памяти
    // После завершения ф-ции уничтожается только параметр-ссылка - второе имя чсейки памяти
    // Сама же ячейка памяти остается в памяти. Если она была изменена в ф-ции, то эти изменения
    // сохраняюься. Поэтому нужно быть осторожным.

    // ================================= Использование ===============================
    // Чаще всего передача параметра по ссылке может использоваться в 2-х ситуациях:
    // 1. Когда необходимо вернуть из ф-ции измененное значение параметра
    // Например, если нужно возвращать из ф-ции 2 значения. Одно через return, второе как параметр-ссылку
    // 2. Когда нужно избежать копирования большого объема данных
    // В дальнейшем при использовании структур или классов переменная может заниматься много памяти
    // Чтобы каждый раз не копировать такую переменную при передаче в ф-цию,
    // ее можно передавать как ссылку

    // ==================================== Примеры ==================================

    // Напишем 2 варианта ф-ции нахождения

    int getDigitsSumByValue(unsigned int);      // Прототип ф-ции с параметром по значению
    int getDigitsSumByReference(unsigned int&); // Прототип ф-ции с параметром-ссылкой

    int exampleWithConstParam(const int& a);    // Прототип ф-ции с константным параметром ссылкой
    // ^^^
    // Реализации этих ф-ций будут ниже

    // Обратите внимание
    // 1. В ф-ции getDigitsSumByValue параметр это обычная переменная типа беззнаковое целое
    // Передача такого параметра идет по значению. Т.е. будет создана копия переменной,
    // для которой будет вызов ф-ции
    // 2. А в getDigitsSumByReference - параметром является ссылка
    // Копирования оригинальной переменной не будет, а создастся ссылка на эту переменную

    int main()
    {
        unsigned int a = 123;
        int sum = getDigitsSumByValue(a);
        cout << "sum = " << sum << endl; // Выведется 6
        cout << "a = " << a << endl;     // Выведется 123

        // Итак значение переменной a не изменилось

        a = 123;
        sum = getDigitsSumByReference(a);
        cout << "sum = " << sum << endl; // Выведется 6
        cout << "a = " << a << endl;     // Выведется 0 (!!!)

        // Значение переменной а изменилось!
        // Внутри ф-ции происходило изменение переменной-параметра
        // Но если в случае getDigitsSumByValue внутри ф-ции была копия переменной,
        // которая ни на что не влияла, она была самодостаточной

        // То для ф-ции getDigitsSumByReference создалась ссылка на оригинальную переменную a
        // И внутри ф-ции мы меняли ячейку в памяти самой переменной a,
        // поэтому изменения заметны и в ф-ции main, откуда был вызов ф-ции подсчета суммы цифр

        // А теперь, допустим, мы хотим использовать передачу по ссылке, чтобы передавать большой
        // объем данных без копирования. В этом случае без ссылки не обойтись. Но теперь мы знаем
        // про опасность использования ссылок и не хотим случайно изменить значение параметра!

        // Для такой ситуации можно использовать модификатор const у параметра.
        int b = 10;
        cout << "some test: " << exampleWithConstParam(b) << endl;

        // А еще у ф-ций с параметром-ссылкой есть недостаток:
        // ее нельзя использовать с константами.
        // getDigitsSumByReference(123); // Вызовет ошибку

        // P.S.
        // Все то же самое касается и для возврата значения из ф-ции по значению и по ссылке
        // Попробуйте написать собственные примеры кода и разобраться как и почему они работают

        return 1;
    }

    // А теперь посмотрите на сами ф-ции
    // Обратите внимание - они АБСОЛЮТНО ОДИНАКОВЫЕ
    // Кроме типа данных параметра

    int getDigitsSumByValue(unsigned int num)
    {
        int sum = 0;
        while(num != 0)
        {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }
    int getDigitsSumByReference(unsigned int& num)
    {
        int sum = 0;
        while(num != 0)
        {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }

    int exampleWithConstParam(const int& num)
    {
        // num++; // Вызовет ошибку. Потому что нельзя менять константу
        return num * 2;
    }
}
