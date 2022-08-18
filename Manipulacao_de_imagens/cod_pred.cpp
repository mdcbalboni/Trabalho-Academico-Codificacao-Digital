#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
using namespace std;
int main()
{
	ifstream infile;
	infile.open("lena.raw");
	unsigned int i=0, tamImagem=0;
	char c;
	while (infile.get(c))
		tamImagem++;
	unsigned char bag[tamImagem];
	infile.clear();
	infile.seekg(0, ios::beg);
	while (infile.get(c))
	{
		bag[i] = (unsigned char) c;
		i++;
	}
	infile.close();
	ofstream outfile;
	outfile.open("Residuo.raw");
	outfile.put(bag[0]);
	for (i = 1; i < tamImagem; i++)
		outfile.put(bag[i] - bag[i-1]);
	outfile.close();	
	return 0;
}
