#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

class animal {
public:
	char name[256];
	// �������������, ���������� � ���� ������ �� ������
	static  animal* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ofstream &ofst) = 0;    // ����� 
};

class fish : public animal {
public:
	enum habitat { RIVER, SEA, LAKE };; // ����� ����������
	habitat h;
	// �������������� ��������� ������
	void InData(ifstream &ifst);  // ���� 
	void Out(ofstream &ofst);     // ����� 
	fish() {} // �������� ��� �������������.
};

class bird : public animal {
public:
	bool migratory; // ���������� ��� ���
	// �������������� ��������� ������
	void InData(ifstream &ifst);  // ���� 
	void Out(ofstream &ofst);     // ����� 
	bird() {} // �������� ��� �������������.
};

// ���������� ��������� �� ������ ����������� �������
class container {
	enum { max_len = 100 }; // ������������ �����
	int len; // ������� �����
	animal *cont[max_len];
public:
	container();   // ������������� ����������
	~container() { Clear(); }   // ���������� ����������

	void In(ifstream &ifst);  // ���� �����
	void Out(ofstream &ofst);  // ����� �����
	void Clear();  // ������� ���������� �� �����
};
