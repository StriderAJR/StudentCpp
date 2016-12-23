//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <cstdio>
//#include <string.h>
//#include <conio.h>
//
//using namespace std;
//
//const char* FILE_NAME = "Employees.txt";
//
//class Employee // класс Сотрудник, немного оптимизирован
//{
//private:
//	char* _name;
//	int _birthYear;
//	float _pay;
//
//	int _lName, _lYear;
//
//public:
//	Employee(int lName = 32, int lYear = 5) : _lName(lName), _lYear(lYear)
//	{  
//		_name = NULL; // нулевой (пустой) указатель
//	}
//
//	Employee(const Employee &empl) // конструктор копирования
//	{
//		Copy(empl);
//	}
//
//	~Employee()
//	{
//		if (_name != NULL) delete [] _name;
//	}
//
//	void SetData(const char* data)
//	{
//		if (_name != NULL) delete [] _name; // если объект уже был заполнен
//
//		// выполняем операцию Trim(), т.е. обрезаем пробелы в конце строки:
//
//		int lengthName = _lName;
//		while (lengthName > 0 && data[lengthName - 1] == ' ') lengthName--;
//
//		_name = new char[lengthName + 1];
//		strncpy(_name, data, lengthName);
//		_name[lengthName] = 0;
//
//		_birthYear = atoi(data += _lName);
//		_pay = atof(data += _lYear);
//	}
//
//	void Print() 
//	{
//		cout << _name << " " << _birthYear << " г.р, " << _pay << " руб.\n";
//	}
//
//	int GetBirthYear() const { return _birthYear; } // обратите внимание на 'const'
//
//	float GetPay() const { return _pay; }
//
//	void Copy(const Employee &empl) // копирование объекта
//	{
//		_lName = empl._lName;
//		_lYear = empl._lYear;
//
//		_birthYear = empl._birthYear;
//		_pay = empl._pay;
//
//		int lengthName = strlen(empl._name);
//		_name = new char[lengthName + 1];
//		strcpy(_name, empl._name);
//	}
//};
//
//
//// конструктор копирования срабатывает 2 раза
//Employee PrintLine(Employee empl) { cout << "\n"; empl.Print(); return empl; }
//
//// конструктор копирования срабатывает 1 раз
//Employee PrintLineRef(Employee &empl) { cout << "\n"; empl.Print(); return empl; }
//
//// конструктор копирования не срабатывает
//Employee& PrintLineRef2(Employee &empl) { cout << "\n"; empl.Print(); return empl; }
//
//
//void main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	// открытия файла с данными о сотрудниках
//
//	ifstream f(FILE_NAME);
//	if (!f) { cout << "Файл не найден"; return; }
//
//	Employee employees[100]; // массив сотрудников, сработал default конструктор
//
//	int i = 0;
//
//	// считывание сотрудников из файла
//
//	char buf[255];
//	while(f.getline(buf, 254))
//	{
//		employees[i++].SetData(buf);
//	}
//	
//	int emplCount = i;
//	if (!emplCount) return;
//	
//	// демонстрация статического создания объектов и работы конструктора копирования
//
//	Employee empl = employees[0];
//	empl.Print();
//
//	// примеры создания объектов
//
//	Employee empl1;
//	Employee empl2(32, 5);
//	Employee empl3 = Employee(32, 5);
//	
//	// вызов функции и передача в нее объекта
//
//	Employee e1 = PrintLine(empl);
//	Employee e2 = PrintLineRef(empl);
//	Employee e3 = PrintLineRef2(empl); // e3 - это ссылка на empl
//
//	// ВНИМАНИЕ, конструктор копирования не помогает в таком случае:
//	// empl1 = empl; !!!
//	// в этом случае необходимо перегружать операцию '='
//	// выход:
//
//	empl1.Copy(empl);
//
//	// динамический массив объектов
//
//	Employee* employees2 = new Employee[emplCount];
//	
//	cout << "\n\n";
//	for (int i = 0; i < emplCount; i++) 
//	{
//		employees2[i].Copy(employees[i]);
//		employees2[i].Print();
//	}
//	
//	_getch();
//}