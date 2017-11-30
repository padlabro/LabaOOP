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
	}
}

void container::Clear() {
	for (int i = 0; i < len; i++) {
		delete cont[i];
	}
	len = 0;
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
	default:
		return 0;
	}
	a->InData(ifst);
	return a;
}

void animal::InData(ifstream &ifst) {
	ifst.getline(name,256);
}

void animal::Out(ofstream &ofst) {
	ofst << "It is " << name << ". ";
}

void fish::MultiMethod(animal *other, ofstream &ofst)
{
	other->MMFish(ofst);
}

void fish::MMFish(ofstream &ofst)
{
	ofst << endl << "Fish and Fish" << endl << endl;
}

void fish::MMBird(ofstream &ofst)
{
	ofst << endl << "Bird and Fish" << endl << endl;
}

void bird::MultiMethod(animal *other, ofstream &ofst)
{
	other->MMBird(ofst);
}

void bird::MMFish(ofstream &ofst)
{
	ofst << endl << "Fish and Bird" << endl << endl;
}

void bird::MMBird(ofstream &ofst)
{
	ofst << endl << "Bird and Bird" << endl << endl;
}

void container::MultiMethod(ofstream &ofst)
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