#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

class animal 
{
public:
	char name[256];
	int age;
	// идентификаци€, порождение и ввод фигуры из потока
	static  animal* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ostream &ofst) = 0;    // вывод 
	int LengthOfName();
	bool Compare(animal &other);
	virtual void OutFish(ostream &ofst);
	virtual void OutBird(ostream &ofst);
	virtual void OutBeast(ostream &ofst);
	virtual void MultiMethod(animal *other, ostream &ofst) = 0;
	virtual void MMFish(ostream &ofst) = 0;
	virtual void MMBird(ostream &ofst) = 0;
	virtual void MMBeast(ostream &ofst) = 0;
};

class fish : public animal 
{
public:
	enum habitat { RIVER, SEA, LAKE };; // место проживани€
	habitat h;
	// переопредел€ем интерфейс класса
	void InData(ifstream &ifst);  // ввод 
	void Out(ostream &ofst);     // вывод 
	void OutFish(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	fish() {} // создание без инициализации.
};

class bird : public animal
{
public:
	bool migratory; // перелетные или нет
	// переопредел€ем интерфейс класса
	void InData(ifstream &ifst);  // ввод 
	void Out(ostream &ofst);     // вывод
	void OutBird(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	bird() {} // создание без инициализации.
};

class beast : public animal 
{
public:
	enum type { PREDATOR, HERBIVORE, INSECTIVORE };; // место проживани€
	type t;
	// переопредел€ем интерфейс класса
	void InData(ifstream &ifst);  // ввод 
	void Out(ostream &ofst);     // вывод 
	void OutBeast(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	beast() {} // создание без инициализации.
};

// ѕростейший контейнер на основе одномерного массива
class container 
{
public:
	enum { max_len = 100 }; // максимальна€ длина
	int len; // текуща€ длина
	animal *cont[max_len];
public:
	container();   // инициализаци€ контейнера
	~container() { Clear(); }   // утилизаци€ контейнера

	void In(ifstream &ifst);  // ввод фигур
	void Out(ostream &ofst);  // вывод фигур
	void OutCont(ostream &ofst);
	void OutFish(ostream &ofst);
	void OutBird(ostream &ofst);
	void OutBeast(ostream &ofst);
	void Clear();  // очистка контейнера от фигур
	void Sort(int d); // сортировка контейнера
	void MultiMethod(ostream &ofst);
};
