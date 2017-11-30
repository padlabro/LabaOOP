#include "Header.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Protect.h"

using namespace std;

container::container() : len(0) { }

void container::In(ifstream &ifst) 
{
	CheckInputFile(ifst);
	while (!ifst.eof() && max_len != len) 
	{
		if ((cont[len] = animal::In(ifst)) != 0) 
		{
			len++;
		}
	}
}

void container::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
	if (len)
		ofst << "Container contains " << len << " elements." << endl;
	else
		ofst << "Container is empty:\n";

	for (int i = 0; i < len; i++) 
	{
		ofst << i + 1<< ": ";
		cont[i]->Out(ofst);
		ofst << "length of name = " << cont[i]->LengthOfName() << "." << endl;
	}
}

void container::Clear() 
{
	for (int i = 0; i < len; i++) 
	{
		delete cont[i];
	}
	len = 0;
}

//-----------------------------------------------------
// Сортировка содержимого контейнера
void container::Sort(int d) 
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++) 
		{
			switch (d)
			{
			case 0:
				if (cont[i]->Compare(*cont[j]))
				{
					animal *tmp = cont[i];
					cont[i] = cont[j];
					cont[j] = tmp;
				}
				break;
			case 1:
				if (!cont[i]->Compare(*cont[j]))
				{
					animal *tmp = cont[i];
					cont[i] = cont[j];
					cont[j] = tmp;
				}
				break;
			default:
				cerr << "Inknown d in sort function!" << endl;
				exit(1);
			}
		}
	}
}

void container::OutFish(ostream &ofst) 
{
	CheckOutputFile(ofst);
	if (len) 
	{
		ofst << "Container contains " << len << " elements." << endl;
		ofst << "Only fishes." << endl;
	}
	else
		ofst << "Container is empty:\n";

	for (int i = 0; i < len; i++) 
	{
		ofst << i+1 << ": ";
		cont[i]->OutFish(ofst);
	}
}

void container::OutBird(ostream &ofst) 
{
	CheckOutputFile(ofst);
	if (len) 
	{
		ofst << "Container contains " << len << " elements." << endl;
		ofst << "Only birds." << endl;
	}
	else
		ofst << "Container is empty:\n";
	
	for (int i = 0; i < len; i++)
	{
		ofst << i+1 << ": ";
		cont[i]->OutBird(ofst);
	}
}

void container::OutBeast(ostream &ofst) 
{
	CheckOutputFile(ofst);
	if (len) 
	{
		ofst << "Container contains " << len << " elements." << endl;
		ofst << "Only beasts." << endl;
	}
	else
		ofst << "Container is empty:\n";
	
	for (int i = 0; i < len; i++) 
	{
		ofst << i+1 << ": ";
		cont[i]->OutBeast(ofst);
	}
}

void fish::InData(ifstream &ifst)
{
	CheckInputFile(ifst);
	animal::InData(ifst);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	switch (k)
	{
	case 1:
		h = fish::habitat::RIVER;
		break;
	case 2:
		h = fish::habitat::SEA;
		break;
	case 3:
		h = fish::habitat::LAKE;
		break;
	default:
		cout << "Error! Unknown habitat!" << endl;
		break;
	}
}

void fish::Out(ostream &ofst) 
{
	CheckOutputFile(ofst);
	animal::Out(ofst);
	ofst << "It is fish. It lives in ";
	switch (h) 
	{
	case fish::habitat::RIVER:
		ofst << "river." << endl;
		break;
	case fish::habitat::SEA:
		ofst << "sea." << endl;
		break;
	case fish::habitat::LAKE:
		ofst << "lake." << endl;
		break;
	default:
		cout << "Error! Unknown habitat!" << endl;
		break;
	}
}

void fish::OutFish(ostream &ofst) 
{
	CheckOutputFile(ofst);
	Out(ofst);
}

void bird::InData(ifstream &ifst) 
{
	CheckInputFile(ifst);
	animal::InData(ifst);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(0 <= k && k <= 1))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	switch (k)
	{
	case 0:
		migratory = false;
		break;
	case 1:
		migratory = true;
		break;
	default:
		cout << "Error! Unknown migratory!" << endl;
		break;
	}
}

void bird::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
	animal::Out(ofst);
	ofst << "It is bird. It is ";
	switch (migratory)
	{
	case false:
		ofst << "not ";
		break;
	case true:
		break;
	}
	ofst << "migratory." << endl;
}

void bird::OutBird(ostream &ofst) 
{
	CheckOutputFile(ofst);
	Out(ofst);
}

void beast::InData(ifstream &ifst) 
{
	CheckInputFile(ifst);
	animal::InData(ifst);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	switch (k) 
	{
	case 1:
		t = beast::type::PREDATOR;
		break;
	case 2:
		t = beast::type::HERBIVORE;
		break;
	case 3:
		t = beast::type::INSECTIVORE;
		break;
	default:
		cout << "Error! Unknown type!" << endl;
		break;
	}
}

void beast::Out(ostream &ofst) 
{
	CheckOutputFile(ofst);
	animal::Out(ofst);
	ofst << "It is beast. It is ";
	switch (t)
	{
	case beast::type::PREDATOR:
		ofst << "predator." << endl;
		break;
	case beast::type::HERBIVORE:
		ofst << "herbivore." << endl;
		break;
	case beast::type::INSECTIVORE:
		ofst << "insectivore." << endl;
		break;
	default:
		cout << "Error! Unknown type!" << endl;
		break;
	}
}

void beast::OutBeast(ostream &ofst)
{
	CheckOutputFile(ofst);
	Out(ofst);
}

animal* animal::In(ifstream &ifst)
{
	CheckInputFile(ifst);
	animal *a;
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	char t[256];
	ifst.getline(t, 256);
	CheckWrongInput(ifst);
	switch (k)
	{
	case 1:
		a = new fish;
		break;
	case 2:
		a = new bird;
		break;
	case 3:
		a = new beast;
		break;
	default:
		return 0;
	}
	a->InData(ifst);
	return a;
}

void animal::InData(ifstream &ifst) 
{
	CheckInputFile(ifst);
	ifst.getline(name,256);
	CheckWrongInput(ifst);
	ifst >> age;
	CheckWrongInput(ifst);
	CheckAge(age);
}

void animal::Out(ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << "It is " << name << ". " << endl;
	ofst << "It is " << age << " years old." << endl;
}

int animal::LengthOfName() 
{
	return strlen(name);
}

bool animal::Compare(animal &other) 
{
	return LengthOfName() < other.LengthOfName();
}

void animal::OutFish(ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << endl; // пустая строка
}

void animal::OutBird(ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << endl; // пустая строка
}

void animal::OutBeast(ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << endl; // пустая строка
}

void fish::MultiMethod(animal *other, ostream &ofst)
{
	other->MMFish(ofst);
}

void fish::MMFish(ostream &ofst) 
{
	ofst << endl << "Fish and Fish" << endl << endl;
}

void fish::MMBird(ostream &ofst) 
{
	ofst << endl << "Bird and Fish" << endl << endl;
}

void fish::MMBeast(ostream &ofst) 
{
	ofst << endl << "Beast and Fish" << endl << endl;
}

void bird::MultiMethod(animal *other, ostream &ofst) 
{
	other->MMBird(ofst);
}

void bird::MMFish(ostream &ofst) 
{
	ofst << endl << "Fish and Bird" << endl << endl;
}

void bird::MMBird(ostream &ofst) 
{
	ofst << endl << "Bird and Bird" << endl << endl;
}

void bird::MMBeast(ostream &ofst)
{
	ofst << endl << "Beast and Bird" << endl << endl;
}

void beast::MultiMethod(animal *other, ostream &ofst) 
{
	other->MMBeast(ofst);
}

void beast::MMFish(ostream &ofst) 
{
	ofst << endl << "Fish and Beast" << endl << endl;
}

void beast::MMBird(ostream &ofst) 
{
	ofst << endl << "Bird and Beast" << endl << endl;
}

void beast::MMBeast(ostream &ofst) 
{
	ofst << endl << "Beast and Beast" << endl << endl;
}

void container::MultiMethod(ostream &ofst) 
{
	ofst << "Multimethod." << endl;
	animal *a1;
	animal *a2;
	for (int i = 0; i < len; i++) 
	{
		a1 = cont[i];
		for (int j = 0; j < len; j++) 
		{
			a2 = cont[j];
			a1->MultiMethod(a2, ofst);
			a1->Out(ofst);
			a2->Out(ofst);
		}
	}
}