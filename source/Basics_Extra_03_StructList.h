// Рассматриваемые темы:
// Список структур

#pragma once

#include <iostream>
#include <string.h>
using namespace std;

namespace StructList
{
    struct Book
    {
        char* Name;
        int Year;
    };
    struct List
    {
        struct Node
        {
            Book data;

            Node* next;
            Node* prev;
        };
        Node* head = nullptr;
        // NULL = 0
        // nullptr - пустой указатель
        // Разница в том, что
        // NULL - это число, а
        // nullptr - ключевое слово и обозначает тип данных УКАЗАТЕЛЬ, значение которого равно 0
        // Например, nullptr используется для  перегрузок библиотечных функций, где явно нужно использовать тип данных указатель

        void addFirst(Book book)
        {
            Node* temp = new Node;
            temp->data = book;
            temp->next = NULL;
            temp->prev = NULL;

            if (head == NULL)
            {
                head = temp;
                return;
            }

            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        void print()
        {
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
    };

    void main()
    {
        int arraySize = 3;
        List list;
        
        for (int i = 0; i < arraySize; i++)
        {
            Book book;

            char* buff = new char[255];
            cout << "Книга " << i << ". Название: ";
            cin >> buff;

            book.Name = new char[strlen(buff) + 1];
            strcpy(book.Name, buff);
            book.Name[strlen(buff)] = '\0';

            cout << "Книга " << i << ". Год: ";
            cin >> book.Year;

            list.addFirst(book);
        }

        list.print();

        // Как удалить весь список?
        list.clear();
    }
}
