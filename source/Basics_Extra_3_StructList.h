// Рассматриваемые темы:
// Список структур

#pragma once

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

namespace StructList
{
    struct Book
    {
        char* Name;
        int Year;
    };

    struct Node
    {
        Book data;
        Node* next;
    };

    // Используем глобальную переменную в качестве исключения,
    // потому что вам еще не вычитан материал по ООП.
    // В будущем использования глобальных переменных
    // избегаем всеми правдами и неправдами.
    // Их использование оправдано только в сложных и запутанных алгоритмах.
    Node* head = nullptr;
    // Если мы хотим добавлять новые элементы в конец списка,
    // то для удобства можно еще хранить указатель на последний элемент списка
    Node* last = nullptr;
    // NULL = 0
    // nullptr - пустой указатель
    // Разница в том, что
    // NULL - это число, а
    // nullptr - ключевое слово и обозначает тип данных УКАЗАТЕЛЬ, значение которого равно 0
    // Например, nullptr используется для  перегрузок библиотечных функций, где явно нужно использовать тип данных указатель

    void add(Book book)
    {
        Node* temp = new Node;
        temp->data = book;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            last = temp;
            return;
        }

        last->next = temp;
        last = temp;
    }

    void print()
    {
        if(head == nullptr)
        {
            cout << "List is empty";
            return;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data.Name << " (" << temp->data.Year << ")" << endl;
            // Помним, что указатель - это просто адрес, т.е. число
            // В этой строчке мы сохраняем в переменную адрес следующего элемента
            temp = temp->next;
        }

    }

    void clear()
    {
        while (head != nullptr)
        {
            // Сначала высвобождаем всю память, выделенную
            // под поля структуры
            delete[] head->data.Name;

            Node* temp = head;
            head = head->next;

            // После этого можно высвободить память самого элемента списка
            delete temp;
        }
    }

    void main()
    {
        setlocale(LC_ALL, "Rus");

        // Вводить книги будем до тех пор, пока пользователь не скажет "хватит"
        char answer = 'y';
        while(answer == 'y' || answer == 'Y')
        {
            char* buf = new char[255];
            Book newBook;

            cout << "Creating new book." << endl;

            cout << "Name: ";
            cin >> buf;
            newBook.Name = new char[strlen(buf)];
            strcpy(newBook.Name, buf);

            cout << "Year: ";
            cin >> newBook.Year;

            add(newBook);

            cout << "Continue? y/n ";
            cin >> answer;
        }

        print();

        // Как удалить весь список?
        clear();

        // Домашнее задание
        // 1. Реализовать вставку в список по индексу
        // 2. Сделать список двусвязным
        // 2.1. Сделать вывод сначала до конца
        // 2.2. Сделать вывод с конца в начало
    }
}
