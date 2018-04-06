#pragma once

class Gwiazda
{
public:
	double x[10], v[10], wartoscFunkcji, promienSchwarzschilda, fitness;
	Gwiazda(Gwiazda* CzarnaDziura);
	Gwiazda();
	void ObliczWartoscFunkcji();
	bool SprawdzCzyNowaCzarnaDziura(Gwiazda* CzarnaDziura);
	void AktualizujPolozenie(Gwiazda* CzarnaDziura); 
	double OdlegloscOdCzarnejDziury(Gwiazda* CzarnaDziura);

private:
};
