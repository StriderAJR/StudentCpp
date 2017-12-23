// Задание

// В зоопарке живут бегемоты и крокодилы.
// Бегемоты отличаются друг от друга кличкой, весом и полом.
// Крокодилы - кличкой, полом, длиной и цветом. Причем крокодилы бывают зеленые, белые, синие и черные.

// По прибытию в зоопарк бегемотов и крокодилов измеряют, взвешивают и, если у них нет клички, выбирают им имя.
// Животных могут перевозить из зоопарка в зоопарк. Также в зоопарке могут рождаться собственные детеныши со случайным полом.
// Если самоцов в стаде становится больше, чем самок, то самцы начинают драться. В результате всегда погибает половина самцов.

// Смоделируйте жизнь зоопарка. Попробуйте добиться такой организации работы зоопарка, чтобы животные не убивали друг друга.

#pragma once

#include <iostream>
#include <ctime>
#include <wincon.h>
using namespace std;

namespace TaskExampleClasses
{
	// Цвет
	enum CrocodileColour
	{
		green,	// зеленый
		white,	// белый
		blue,	// синий
		black	// черный
	};

	// Пол
	enum Sex
	{
		male,	// самец
		female	// самка
	};

	// Бегемот
	class Hypopotamus
	{
		char* name;		// кличка
		double weight;	// вес
		Sex sex;		// пол

	public:
		Hypopotamus()
		{
			name = nullptr;
			weight = 10; // 10 кг, думаю, нормальный вес для бегемотика
			sex = Sex(rand() % 2);
		}
	};
	// Крокодил
	class Crocodile
	{
		char* name;				// кличка
		double length;	// длина
		Sex sex;				// пол
		CrocodileColour colour;	// цвет

	public:
		Crocodile()
		{
			name = nullptr;
			length = 0.2; // 20 см, крокодильчики достаточно маленькие при рождении
			sex = Sex(rand() % 2);
			colour = CrocodileColour(0 + (rand() % (int)(4 - 0 + 1)));
		}
	};
	// Зоопарк
	class Zoo
	{
		Hypopotamus** hypos;		// бегемоты
		Crocodile** crocs;			// крокодилы

		unsigned int hypoIndex;	// кол-во бегемотов в зоопарке
		unsigned int crocIndex;	// кол-во крокодилов в зоопарке

		unsigned int hypoCageSize;	// Максимальное кол-во мест в клетках зоопарка для бегемотов
		unsigned int crocCageSize;	// Максимальное кол-во мест в клетках зоопарка для крокодилов

		unsigned int hypoMaleCount;		// Кол-во самцов бегемотов
		unsigned int hypoFemaleCount;	// Кол-во самок бегемотов
		unsigned int crocMaleCount;		// Кол-во самцов крокодилов
		unsigned int crocFemaleCount;	// Кол-во самок крокодилов
	
		// Когда место в клетках у бегемотов заканчивается, закупаются новые клетки
		void extendHypoCages()
		{
			// Кол-во будущих клеток в 2 раза больше, чем было
			unsigned int newCageSize = hypoCageSize * 2;
			// Выделяем место под новых бегемотов
			Hypopotamus** newCages = new Hypopotamus*[newCageSize];
			// Копируем напрямую память из старого место в новое
			// memcpy - memory copy
			// newCages - куда будем копировать
			// hypos - откуда копируем
			// последний параметр - сколько байт нужно скопировать
			// hypoCageSize * sizeof(Hypopotamus*) - вычисление кол-ва байт в старом массиве
			memcpy(newCages, hypos, hypoCageSize * sizeof(Hypopotamus*));
			// Удаляем память старого массива, мы ее уже скопировали
			delete[] hypos;
			// Сохраняем адрес нового массива в поле класса
			hypos = newCages;
			// Сохраняем новый размер клеток в поле класса
			hypoCageSize = newCageSize;
		}

		// Когда место в клетках у бегемотов заканчивается, закупаются новые клетки
		void extendCrocCages()
		{
			unsigned int newCageSize = crocCageSize * 2;
			Crocodile** newCages = new Crocodile*[newCageSize];
			memcpy(newCages, crocs, crocCageSize * sizeof(Crocodile*));

			delete[] crocs;
			crocs = newCages;
			crocCageSize = newCageSize;
		}
		// Проверяем не стало ли самцов бегемотов больше, чем самок
		void checkHypoMaleToFemaleCount()
		{
			
		}
		// Проверяем не стало ли самцов крокодилов больше, чем самок
		void checkCrocMaleToFemaleCount()
		{

		}
		// Самцы бегемотов начали драться и убивать друг друга
		void hypoGenoside()
		{
			
		}
		// Самцы крокодилов начали драться и убивать друг друга
		void crocGenoside()
		{

		}
	public:
		Zoo()
		{
			// При открытии нового зоопарка его вместимость будет маленькой:
			// По 10 бегемотов и крокодилов
			hypoCageSize = 10;
			crocCageSize = 10;

			hypoIndex = -1; // Это будет использоваться как индекс, поэтому -1, 
			crocIndex = -1; // т.к. 0 - это уже наличие 1 животного

			hypos = new Hypopotamus*[hypoCageSize];
			crocs = new Crocodile*[crocCageSize];
		}

		// Рождение бегемотика
		// Имени у него не будет, пол генерируется случайно
		void addHypo()
		{
			// Если из-за нового бегемотика будет перенаселение в клетке, то...
			if (hypoIndex + 1 == hypoCageSize)
				// расширяем клетки
				extendHypoCages();

			Hypopotamus* newHypo = new Hypopotamus;
			hypos[++hypoIndex] = newHypo;
		}
		// Рождение крокодильчика
		// Имени у него не будет, пол и цвет генерируется случайно
		void addCroc()
		{
			// Если из-за нового бегемотика будет перенаселение в клетке, то...
			if (hypoIndex + 1 == hypoCageSize)
				// расширяем клетки
				extendHypoCages();

			Crocodile* newCroc = new Crocodile;
			crocs[++crocIndex] = newCroc;
		}
		// В зоопарк приехал новый бегемот
		void addHypo(Hypopotamus* hypo)
		{

		}
		// В зоопарк приехал новый крокодил
		void addCroc(Crocodile* croc)
		{

		}
		// Отправить бегемота в другой зоопарк
		void sendHypoToZoo(Zoo* zoo, Hypopotamus* hypo)
		{
			
		}
		// Отправить крокодила в другой зоопарк
		void sendCrocToZoo(Zoo* zoo, Crocodile* croc)
		{

		}
	};

	void main()
	{
		srand(time(nullptr));
	}
}