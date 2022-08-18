#include <iostream>
#include <string>
#include <fstream>

using namespace std;

float menorProb,segundoMenor;

struct Arvore
{
	string simbolos;
	float probabilidade;
	Arvore *esq, *dir, *prox;
};

Arvore *Raiz = new Arvore;
Arvore *ListaPri = new Arvore;
string codigo, entrada,tabela;
ofstream outfile;

void procuraMenor(Arvore **ListaPri, float tam)
{
	Arvore *temp = new Arvore;
	temp = *ListaPri;
	string naoRepete;
	menorProb = 1;
	segundoMenor = 1;
	
	for(int i=0;i<tam;i++)
	{
		if(temp->probabilidade <= menorProb)
		{
			menorProb = temp -> probabilidade;
			naoRepete = temp -> simbolos;
			
		}
		temp = temp -> prox;
	}	
	temp = *ListaPri;

	for(int i=0;i<tam;i++)
	{	
		if(temp->probabilidade <= segundoMenor && temp -> simbolos != naoRepete)
		{
			segundoMenor = temp -> probabilidade;
		}
		temp = temp -> prox;
	}
}

void ordem(Arvore *raiz)
{
	if(raiz==NULL)
		return;
	cout << raiz->simbolos<< endl;
	ordem(raiz->esq);
	ordem(raiz->dir);
}

void geraCodigo(Arvore *raiz)
{
	if(raiz->esq == NULL && raiz->dir == NULL)
	{
		string old = raiz->simbolos;
		string rep = codigo;
		for (int pos=0;(pos = entrada.find(old, pos)) != string::npos; pos+=rep.length())
			entrada.replace(pos, old.length(), rep);
		codigo.erase(codigo.size()-1);
	}else
	{
		if(raiz->esq != NULL)
		{
			codigo.push_back('1');
			geraCodigo(raiz->esq);
		}
		if(raiz->dir != NULL)
		{
			codigo.push_back('0');
			geraCodigo(raiz->dir);
		}
		if(codigo.size() > 0)
			codigo.erase(codigo.size()-1);
	}
}

void geraTabela(Arvore *raiz)
{
	if(raiz->esq == NULL && raiz->dir == NULL)
	{
		string old = raiz->simbolos;
		string rep = codigo;
		for (int pos=0;(pos = entrada.find(old, pos)) != string::npos; pos+=rep.length())
			tabela.replace(pos, old.length(), rep);
		outfile << raiz->simbolos << " " << codigo << endl;
		codigo.erase(codigo.size()-1);
	}else
	{
		if(raiz->esq != NULL)
		{
			codigo.push_back('1');
			geraTabela(raiz->esq);
		}
		if(raiz->dir != NULL)
		{
			codigo.push_back('0');
			geraTabela(raiz->dir);
		}
		if(codigo.size() > 0)
			codigo.erase(codigo.size()-1);
	}
}

int main () 
{
	//Ler arquivo e colocar em uma string.
	string armazenaSimbolos,simboloEntrada,simboloCompara;
	ifstream infile;
	infile.open("Arquivo.txt"); 
	getline (infile,entrada);	
	
	//string entrada = "BAAANH HCGGTE  DFJJEUE  SSNEYUFWDKKRGP  SNFHEFWQUEF NDFYQWGI ASDBTYW JASDGFWEB NSDFUYWEF HSWBEFWI";
	int j, i, tamSimbolos,iteradorLista;
	float tamEntrada = entrada.length(), cont;

	//Armazena somente uma aparição do simbolo da entrada principal.
	for(i=0; i< tamEntrada; i++)
	{
		cont=0;
		simboloEntrada=entrada[i];
		tamSimbolos=armazenaSimbolos.length();
		for(j=0;j<tamSimbolos;j++)
		{
			simboloCompara=armazenaSimbolos[j];
			if(simboloEntrada == simboloCompara)
				cont++;
		}
		if(cont==0)
			armazenaSimbolos.append(simboloEntrada);
	}
	
	//Estava dando segmentation fault se as três variaveis do tipo arvore fossem declaradas antes do for de cima
	Arvore *temp2 = new Arvore;
	Arvore *juncao = new Arvore;
	Arvore *temp = new Arvore;
	tamSimbolos=armazenaSimbolos.length();
    iteradorLista=tamSimbolos;	
	
	
	temp = ListaPri;
	
	// Calcular propabilidades
	for(i=0; i< tamSimbolos; i++)
	{
		
		cont=0;
		simboloEntrada=armazenaSimbolos[i];
		for(j=0; j< tamEntrada; j++)
		{
			simboloCompara=entrada[j];
			if (simboloEntrada == simboloCompara)
				cont++;
		}
		temp->prox = new Arvore;
		temp->probabilidade = (cont/tamEntrada);
		temp->simbolos = armazenaSimbolos[i];
		temp = temp->prox;

	}

	//Cria Arvore
	for(i=0;i<iteradorLista-1;i++)
	{
		temp = ListaPri;
		procuraMenor(&ListaPri,tamSimbolos);
		juncao = new Arvore();
		
		temp = ListaPri;
		
		//Coloca as informaçoes do primeiro simbolo com menor incidencia
		for(j=0;j<tamSimbolos;j++)
		{
			if(temp->probabilidade==menorProb)
			{
				juncao->simbolos = temp->simbolos;
				juncao->probabilidade = temp->probabilidade;			
				break;
			}
			temp=temp->prox;
		}
		temp = ListaPri;
		
		//Unimos o primeiro simbolo com o segundo simbolo com menor incidencia em juncao 
		for(j=0;j<tamSimbolos;j++)
		{
			if(temp->probabilidade==segundoMenor && juncao->simbolos != temp->simbolos)
			{
				juncao->simbolos = temp->simbolos+"+"+juncao->simbolos;
				juncao->probabilidade = juncao->probabilidade+temp->probabilidade;	
				break;
			}
			temp=temp->prox;
		}	
		temp = ListaPri;
		
		//Ir pro final da lista
		for(j=0;j<tamSimbolos-1;j++){
			temp=temp->prox;
		}
		
		//Coloca juncao no final da Lista de prioridade
		temp->prox = new Arvore;
		temp=temp->prox;
		temp->simbolos=juncao->simbolos;
		temp->probabilidade=juncao->probabilidade;
		
		
		//Aponta a uniao dos simbolos para seus devidos filhos e retira os mesmos da lista de prioridade
		//Aponta e retira o da direita
		temp2=ListaPri;
		if(temp2->probabilidade==menorProb)
		{
			temp->dir=temp2;
			ListaPri=ListaPri->prox;
		}else
		{
			while(temp2->prox != NULL)
			{
				if(temp2->prox->probabilidade==menorProb)
				{
					temp->dir=temp2->prox;
					temp2->prox=temp2->prox->prox;
					break;
				}
				temp2=temp2->prox;
					
			} 
		}
		temp2=ListaPri;
		
		//Aponta e retira o da esquerda
		if(temp2->probabilidade==segundoMenor)
		{
			temp->esq=temp2;
			ListaPri=ListaPri->prox;
		}else
		{
			while(temp2->prox != NULL)
			{
				if(temp2->prox->probabilidade==segundoMenor)
				{
					temp->esq=temp2->prox;
					temp2->prox=temp2->prox->prox;
					break;
				}
				temp2=temp2->prox;
				
			} 
		}
		tamSimbolos--;
	}
	
	temp = ListaPri;
	
	//Imprimir na tela a arvore em ordem de vizitazção	
	//ordem(ListaPri);
	
	outfile.open("TextoCodificado.dat");
	geraCodigo(ListaPri);
	outfile << entrada;
	outfile.close();
	
	
	outfile.open("Probabilidades.txt");
	geraTabela(ListaPri);
	outfile.close();
	
	return 0;
}
