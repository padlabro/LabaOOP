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
	// �������������, ���������� � ���� ������ �� ������
	static  animal* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ostream &ofst) = 0;    // ����� 
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
	enum habitat { RIVER, SEA, LAKE };; // ����� ����������
	habitat h;
	// �������������� ��������� ������
	void InData(ifstream &ifst);  // ���� 
	void Out(ostream &ofst);     // ����� 
	void OutFish(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	fish() {} // �������� ��� �������������.
};

class bird : public animal
{
public:
	bool migratory; // ���������� ��� ���
	// �������������� ��������� ������
	void InData(ifstream &ifst);  // ���� 
	void Out(ostream &ofst);     // �����
	void OutBird(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	bird() {} // �������� ��� �������������.
};

class beast : public animal 
{
public:
	enum type { PREDATOR, HERBIVORE, INSECTIVORE };; // ����� ����������
	type t;
	// �������������� ��������� ������
	void InData(ifstream &ifst);  // ���� 
	void Out(ostream &ofst);     // ����� 
	void OutBeast(ostream &ofst);
	void MultiMethod(animal *other, ostream &ofst);
	void MMFish(ostream &ofst);
	void MMBird(ostream &ofst);
	void MMBeast(ostream &ofst);
	beast() {} // �������� ��� �������������.
};

// ���������� ��������� �� ������ ����������� �������
class container 
{
public:
	enum { max_len = 100 }; // ������������ �����
	int len; // ������� �����
	animal *cont[max_len];
public:
	container();   // ������������� ����������
	~container() { Clear(); }   // ���������� ����������

	void In(ifstream &ifst);  // ���� �����
	void Out(ostream &ofst);  // ����� �����
	void OutFish(ostream &ofst);
	void OutBird(ostream &ofst);
	void OutBeast(ostream &ofst);
	void Clear();  // ������� ���������� �� �����
	void Sort(int d); // ���������� ����������
	void MultiMethod(ostream &ofst);
};
