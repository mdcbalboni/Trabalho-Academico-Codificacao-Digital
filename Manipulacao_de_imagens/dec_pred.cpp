#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include "jo_jpeg.cpp"
using namespace std;
int main()
{
	ifstream infile;
	infile.open("Residuo.raw");
	unsigned int i=0, tamImagem=0;
	char c;
	while (infile.get(c))
		tamImagem++;
	infile.clear();
	infile.seekg(0, ios::beg);
	unsigned char imagem[tamImagem];
	while (infile.get(c))
	{
		imagem[i] = (unsigned char) c;
		i++;
	}
	infile.close();
	ofstream outfile;
	outfile.open("Despredita.raw");
	outfile.put(imagem[0]);
	for (i = 1; i < tamImagem; i++)
	{
		imagem[i] = imagem[i]+imagem[i-1];
		outfile.put(imagem[i]);
	}
	outfile.close();	
	return 0;
}
