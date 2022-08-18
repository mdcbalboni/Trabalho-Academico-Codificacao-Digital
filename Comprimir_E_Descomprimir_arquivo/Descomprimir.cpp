#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Arvore
{
	string simbolos;
	string codigo;
	Arvore *esq, *dir, *prox;
};

Arvore *Raiz = new Arvore;
Arvore *ListaPri = new Arvore;

int main () 
{
	ifstream infile;
	ofstream outfile;
	infile.open("Probabilidades.txt"); 
	string entrada,simbolo;
	getline (infile,entrada);
	int i,j,tamSimbolos=0,iteradorLista;
	Arvore *temp = new Arvore;
	Arvore *temp2 = new Arvore;
	temp=ListaPri;
	
	
	while(!infile.eof())
	{	
		temp->simbolos = entrada[0];
		
		entrada.erase(0,2);
		
		temp->codigo = entrada;

		temp->prox = new Arvore;
		
		temp = temp->prox;
		
		getline (infile,entrada);
		tamSimbolos++;
	}
	temp=ListaPri;
	
	
	for(i=0;i<tamSimbolos;i++)
	{
		temp2=Raiz;
		iteradorLista=temp->codigo.size();
		for(j=0;j<iteradorLista;j++)
		{
			if(temp->codigo[j]=='0')
			{
				if(temp2->dir == NULL)
					temp2->dir = new Arvore;
				temp2=temp2->dir;
			}else
			{
				if(temp2->esq == NULL)
					temp2->esq = new Arvore;
				temp2=temp2->esq;
			}
		}
		temp2->simbolos=temp->simbolos	;	
		temp=temp->prox;
	}
	
	infile.close();
	infile.open("TextoCodificado.dat"); 
	getline (infile,entrada);
	outfile.open("TextoDescodificado.txt");
	
	while(!entrada.empty())
	{
		temp = Raiz;
		while(temp->esq != NULL && temp->dir != NULL)
		{
			if(entrada[0] == '0')
			{
				temp = temp->dir;
			}else{
				temp = temp->esq;
			}
			entrada.erase(0,1);
		}
		
		outfile << temp->simbolos;
		
	}
	
	outfile.close();
	
	return 0;
}
