#include <fstream>

using namespace std;

bool FilesCmp(ifstream &expected, ifstream &actual) 
{
	bool flag = true;
	char acttest;
	char exptest;
	while (!expected.eof()) 
	{
		expected >> exptest;
		actual >> acttest;
		if (exptest != acttest) 
		{
			flag = false;
			break;
		}
	}
	return flag;
}