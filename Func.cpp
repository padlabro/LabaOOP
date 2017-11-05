#include "Header.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

container::container() : len(0) { }

void container::In(ifstream &ifst) {
	while (!ifst.eof() && max_len != len) {
		if ((cont[len] = animal::In(ifst)) != 0) {
			len++;
		}
	}
}

void container::Out(ofstream &ofst)
{
	ofst << "Container contents " << len << " elements." << endl;
	for (int i = 0; i < len; i++) {
		ofst << i + 1<< ": ";
		cont[i]->Out(ofst);
		ofst << "length of name = " << cont[i]->LengthOfName() << "." << endl;
	}
}

void container::Clear() {
	for (int i = 0; i < len; i++) {
		delete cont[i];
	}
	len = 0;
}

//-----------------------------------------------------
// Сортировка содержимого контейнера
void container::Sort() {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (cont[i]->Compare(*cont[j])) {
				animal *tmp = cont[i];
				cont[i] = cont[j];
				cont[j] = tmp;
			}
		}
	}
}

void fish::InData(ifstream &ifst) {
	animal::InData(ifst);
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		h = fish::habitat::RIVER;
		break;
	case 2:
		h = fish::habitat::SEA;
		break;
	case 3:
		h = fish::habitat::LAKE;
		break;
	}
}

void fish::Out(ofstream &ofst) {
	animal::Out(ofst);
	ofst << "It is fish. It lives in ";
	switch (h) {
	case fish::habitat::RIVER:
		ofst << "river." << endl;
		break;
	case fish::habitat::SEA:
		ofst << "sea." << endl;
		break;
	case fish::habitat::LAKE:
		ofst << "lake." << endl;
		break;
	}
}

void bird::InData(ifstream &ifst) {
	animal::InData(ifst);
	int k;
	ifst >> k;
	switch (k) {
	case 0:
		migratory = false;
		break;
	case 1:
		migratory = true;
		break;
	}
}

void bird::Out(ofstream &ofst) {
	animal::Out(ofst);
	ofst << "It is bird. It is ";
	switch (migratory) {
	case false:
		ofst << "not ";
		break;
	case true:
		break;
	}
	ofst << "migratory." << endl;
}

void beast::InData(ifstream &ifst) {
	animal::InData(ifst);
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		t = beast::type::PREDATOR;
		break;
	case 2:
		t = beast::type::HERBIVORE;
		break;
	case 3:
		t = beast::type::INSECTIVORE;
		break;
	}
}

void beast::Out(ofstream &ofst) {
	animal::Out(ofst);
	ofst << "It is beast. It is ";
	switch (t) {
	case beast::type::PREDATOR:
		ofst << "predator." << endl;
		break;
	case beast::type::HERBIVORE:
		ofst << "herbivore." << endl;
		break;
	case beast::type::INSECTIVORE:
		ofst << "insectivore." << endl;
		break;
	}
}

animal* animal::In(ifstream &ifst) {
	animal *a;
	int k;
	ifst >> k;
	char t[256];
	ifst.getline(t, 256);
	switch (k) {
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

void animal::InData(ifstream &ifst) {
	ifst.getline(name,256);
	ifst >> age;
}

void animal::Out(ofstream &ofst) {
	ofst << "It is " << name << ". " << endl;
	ofst << "It is " << age << " years old." << endl;
}

int animal::LengthOfName() {
	return strlen(name);
}

bool animal::Compare(animal &other) {
	return LengthOfName() < other.LengthOfName();
}