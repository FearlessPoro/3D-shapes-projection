#ifndef macierz_h
#define macierz_h

class Wektor{
public:
    double dane[4];

    Wektor();

    Wektor(double x, double y, double z, double f);

    void wypisz() const;

    void ustaw(double x, double y, double z, double f);

    double X();

    double Y();
	
	double Z();
	
	double F();
};

class Macierz{
public:
    Wektor dane[3];

    Macierz(Wektor w1, Wektor w2, Wektor w3);

    void wypisz() const;
};

int next(int indeks);
#endif
