#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

class animal {
public:
	char name[256];
	// идентификаци€, порождение и ввод фигуры из потока
	static  animal* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0;    // вывод 
	virtual void OutFish(ofstream &ofst);
	virtual void OutBird(ofstream &ofst);
};

class fish : public animal {
public:
	enum habitat { RIVER, SEA, LAKE };; // место проживани€
	habitat h;
	// переопредел€ем интерфейс класса
	void InData(ifstream &ifst);  // ввод 
	void Out(ofstream &ofst);     // вывод 
	void OutFish(ofstream &ofst);
	fish() {} // создание без инициализации.
};

class bird : public animal {
public:
	bool migratory; // перелетные или нет
	// переопредел€ем интерфейс класса
	void InData(ifstream &ifst);  // ввод 
	void Out(ofstream &ofst);     // вывод
	void OutBird(ofstream &ofst);
	bird() {} // создание без инициализации.
};

// ѕростейший контейнер на основе одномерного массива
class container {
	enum { max_len = 100 }; // максимальна€ длина
	int len; // текуща€ длина
	animal *cont[max_len];
public:
	container();   // инициализаци€ контейнера
	~container() { Clear(); }   // утилизаци€ контейнера

	void In(ifstream &ifst);  // ввод фигур
	void Out(ofstream &ofst);  // вывод фигур
	void OutFish(ofstream &ofst);
	void OutBird(ofstream &ofst);
	void Clear();  // очистка контейнера от фигур
};
