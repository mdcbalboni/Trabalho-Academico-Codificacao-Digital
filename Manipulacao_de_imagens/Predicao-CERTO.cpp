#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

int main()
{
	ifstream infile;
	infile.open("lena.raw");
	int i,j;
	string bag;
	unsigned char c;


	while (infile >> c)
	{
		bag.push_back(int(c));
	}

	infile.close();

	vector<int> array(bag.size());

	cout << bag.size() << endl;

	for (i = 0; i < bag.size(); i++)
	{
		array[i] = int(bag[i]);
	}


	for (i = 1; i < bag.size(); i++)
	{
		array[i] -= int(bag[i-1]);
	}

	ofstream outfile;
	outfile.open("teste.raw");
	for (i = 0; i < bag.size(); i++)
	{
		outfile << array[i];
	}
	outfile.close();

	return 0;
}