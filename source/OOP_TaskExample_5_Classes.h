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
	};
	// Крокодил
	class Crocodile
	{
		char* name;				// кличка
		unsigned short length;	// длина
		Sex sex;				// пол
		CrocodileColour colour;	// цвет

	public:
	};
	// Зоопарк
	class Zoo
	{
		Hypopotamus** hypos;		// бегемоты
		Crocodile** crocs;			// крокодилы

		unsigned int hyposCount;	// кол-во бегемотов в зоопарке
		unsigned int crocsCount;	// кол-во крокодилов в зоопарке

		unsigned int hypoCageSize;	// Максимальное кол-во мест в клетках зоопарка для бегемотов
		unsigned int crocCageSize;	// Максимальное кол-во мест в клетках зоопарка для крокодилов

		unsigned int hypoMaleCount;		// Кол-во самцов бегемотов
		unsigned int hypoFemaleCount;	// Кол-во самок бегемотов
		unsigned int crocMaleCount;		// Кол-во самцов крокодилов
		unsigned int crocFemaleCount;	// Кол-во самок крокодилов
	public:
		void addHypo()
		{
			
		}

		void addCroc()
		{
			
		}

		void addHypo(Hypopotamus* hypo)
		{

		}

		void addCroc(Crocodile* croc)
		{

		}

		void sendHypoToZoo(Zoo* zoo, Hypopotamus* hypo)
		{
			
		}

		void sendCrocToZoo(Zoo* zoo, Crocodile* croc)
		{

		}
	};
}