//#include <iostream>
//#include <cstdlib>
//#include <string.h>
//using namespace std;
//
//struct Book
//{
//	char* Name;
//	int Year;
//};
//
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//
//	int arraySize = 3;
//	Book* array = new Book[arraySize];
//
//	for(int i = 0; i < arraySize; i++)
//	{
//		Book book;
//
//		char* buff = new char[255];
//		cout << "Книга " << i << ". Название: "; 
//		cin >> buff;
//
//		book.Name = new char[strlen(buff)+1];
//		strcpy(book.Name, buff);
//		book.Name[strlen(buff)] = '\0';
//
//		cout << "Книга " << i << ". Год: "; 
//		cin >> book.Year;
//
//		array[i] = book;
//	}
//
//	cout << endl;
//
//	cout << "Список книг:" << endl;
//	for(int i = 0; i < arraySize; i++)
//		cout << array[i].Name << " (" << array[i].Year << ")" << endl;
//
//	// На каждый NEW - свой DELETE!!!
//
//	// Когда массив больше не нужен,
//	// память нужно высвободить
//
//	// Сначала высвобождаем всю память, выделенную
//	// под поля структуры
//	for(int i = 0; i < arraySize; i++)
//		delete[] array[i].Name;
//
//	// После этого можно высвободить память самого массива
//	delete[] array;
//}
