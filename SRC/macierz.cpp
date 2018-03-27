#include "macierz.h"

#include<iostream>

using std::cout;
using std::endl;

Wektor :: Wektor()
{
	for(int i=0; i<4; i++)
	{
		dane[i] = 0;
	}
}

Wektor :: Wektor(double x, double y, double z, double f)
{
	dane[0] = x;
	dane[1] = y;
	dane[2] = z;
	dane[3] = f;
}


void Wektor :: wypisz() const
{
	for(int i=0; i<4; i++)
	{
		cout<<dane[i]<<" ";
	}
	cout<<endl;
}

void  Wektor :: ustaw(double x, double y, double z, double f)
{
	dane[0] = x;
	dane[1] = y;
	dane[2] = z;
	dane[3] = f;
}

double Wektor :: X()
{
	return dane[0];
}

double Wektor :: Y()
{
	return dane[1];
}

double Wektor :: Z()
{
	return dane[2];
}

double Wektor :: F()
{
	return dane[3];
}

Macierz :: Macierz(Wektor w1, Wektor w2, Wektor w3)
{
	dane[0] = w1;
	dane[1] = w2;
	dane[2] = w3;
}


void Macierz :: wypisz() const
{
	for(int i=0; i<3; i++)
	{
		dane[i].wypisz();
	}
}

int next(int indeks)
{
	if(indeks < 2)
		return indeks +1;
	else
		return 0;

}