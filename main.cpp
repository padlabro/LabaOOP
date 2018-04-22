#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[]) 
{

	if (argc != 3) 
	{
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;

	container c;

	c.In(ifst);
	
	int k1 = 10;
	int menu = 10;
	while (menu != 0) {

		cout << "Input number:" << endl;
		cout << "1 - Sort container" << endl;
		cout << "2 - Out container" << endl;
		cout << "3 - Multimethod" << endl;
		cout << "4 - Clear container" << endl;
		cout << "0 - exit" << endl;
		cin >> menu;
		if (cout.fail())
		{
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (menu < 0 || menu > 4) {
			cout << "Incorrect choice! Try again!" << endl;
			continue;
		}
		else {
			switch (menu)
			{
			case 1:
				cout << "Input number:" << endl;
				cout << "0 - from small to big" << endl;
				cout << "1 - from big to small" << endl;
				while (k1 != 0 || k1 != 1)
				{
					cin >> k1;
					if (cout.fail())
					{
						cout << "Wrong input!" << endl;
						exit(1);
					}
					if (k1 != 0 || k1 != 1)
					{
						cout << "Incorrect choice! Try again!" << endl;
						continue;
					}
				}
				c.Sort(k1);
				break;
			case 2:
				c.OutCont(ofst);
				break;
			case 3:
				c.MultiMethod(ofst);
				break;
			case 4:
				c.Clear();
				break;
			default:
				break;
			}
		}
	}

	cout << "Stop" << endl;
	ifst.close();
	ofst.close();
	return 0;

	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}
