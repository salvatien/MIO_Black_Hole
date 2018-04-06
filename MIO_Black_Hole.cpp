// MIO_Black_Hole.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Gwiazda.h"


double SumaFitnesow=0;

double AktualizujSumeFitnesow(int populacja, Gwiazda** Tab)
{
	double temp = 0;
	for (int i = 0; i < populacja; i++)
	{
		temp += Tab[i]->fitness;
	}
	return temp;
}

int main()
{
	double Wyniki[30];
	for (int z = 0; z < 30; z++)
	{
		Gwiazda* CzarnaDziura = new Gwiazda();
		SumaFitnesow = 0;
		int populacja = 25; 
		srand(time(NULL));
		Gwiazda* Gwiazdozbior[25]; 
		double Najlepsza[4000]; 
		for (int i = 0; i < 25; i++) 
		{
			Gwiazdozbior[i] = new Gwiazda(CzarnaDziura);
		}
		SumaFitnesow = AktualizujSumeFitnesow(populacja, Gwiazdozbior);
		for (int iteracja = 0; iteracja <4000; iteracja++) 
		{
			for (int i = 0; i < populacja; i++)
			{
				Gwiazdozbior[i]->ObliczWartoscFunkcji();
				if (Gwiazdozbior[i]->SprawdzCzyNowaCzarnaDziura(CzarnaDziura))
				{
					CzarnaDziura = Gwiazdozbior[i];
				}
				else
				{
					Gwiazdozbior[i]->AktualizujPolozenie(CzarnaDziura);
					Gwiazdozbior[i]->ObliczWartoscFunkcji();
					if (Gwiazdozbior[i]->SprawdzCzyNowaCzarnaDziura(CzarnaDziura))
					{
						CzarnaDziura = Gwiazdozbior[i];
					}
				}
			}
			SumaFitnesow = AktualizujSumeFitnesow(populacja, Gwiazdozbior);

			Najlepsza[iteracja] = CzarnaDziura->wartoscFunkcji;
		}
		std::cout << "Wartosc funkcji wynosi: " << CzarnaDziura->wartoscFunkcji << std::endl;
		Wyniki[z] = CzarnaDziura->wartoscFunkcji;
		std::cout << std::endl;

	}
	double suma = 0;
	double najmniejszy = 1e+11;
	for(int z=0; z<30; z++)
	{
		suma += Wyniki[z];
		if (Wyniki[z] < najmniejszy) najmniejszy = Wyniki[z];
	}
	std::cout << "Srednio: " << suma / 30 << std::endl;
	std::cout << "Najmniejsza: " << najmniejszy << std::endl;
	getchar();
	return 0;
}
