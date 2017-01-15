// Рассматриваемые темы:
// Массив объектов

#pragma once
#include <iostream>

using namespace std;

namespace ClassArray
{
    class Book
    {
        char* _name;
        char* _author;
        short _year;

        char*  setString(char* source)
        {
            if (source == nullptr)
            {
                char* dest = new char[strlen("Unknown")];
                strcpy(dest, "Unknown");

                return dest;
            }

            char* dest = new char[strlen(source)];
            strcpy(dest, source);
            return dest;
        }

    public:
        Book() : _name(nullptr), _author(nullptr), _year(0)
        {
        }

        Book(char* name, char* author, short year)
        {
            setName(name);
            setAuthor(author);
            setYear(year);
        }

        ~Book()
        {
            delete[] _name;
            delete[] _author;
        }

        void setName(char* name)
        {
            _name = setString(name);
        }

        void setAuthor(char* author)
        {
            _author = setString(author);
        }

        void setYear(short year)
        {
            _year = year;
        }

        char* getName() const
        {
            return _name;
        }

        char* getAuthor() const
        {
            return _author;
        }

        short getYear() const
        {
            return _year;
        }
    };


    char* setStr(char* source)
    {
        if (source == nullptr)
        {
            char* dest = new char[strlen("Unknown")];
            strcpy(dest, "Unknown");

            return dest;
        }

        char* dest = new char[strlen(source)];
        strcpy(dest, source);

        return dest;
    }

    Book* readBook()
    {
        char* name = nullptr, *author = nullptr;
        short year;

        char* buf = new char[255];

        cout << "Введите название книги:";

        cin.getline(buf, 255);
        name = setStr(buf);

        cout << "Введите автора книги:";

        cin.getline(buf, 255);
        author = setStr(buf);

        cout << "Введите год издания книги:";

        cin.getline(buf, 255);
        year = (short)atoi(buf);

        delete[] buf;

        Book* b = new Book(name, author, year);
        return b;
    }

    void printBooks(Book** books, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". "
                << books[i]->getAuthor()
                << " \"" << books[i]->getName() << "\""
                << " (" << books[i]->getYear() << ")" << endl;
        }
    }

    void main()
    {
        setlocale(0, "RUS");

        Book** books = new Book*[10];
        int size = 0;

        Book* newBook = readBook();
        books[size++] = newBook;
        newBook = readBook();
        books[size++] = newBook;

        printBooks(books, size);

        system("pause");
    }
}


