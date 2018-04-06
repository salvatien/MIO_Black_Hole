#include "stdafx.h"
#include <WINDOWS.H>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "Gwiazda.h"
extern double SumaFitnesow;

void cec17_test_func(double *, double *, int, int, int);

double *OShift, *M, *y, *z, *x_bound;
int ini_flag = 0, n_flag, func_flag, *SS;

void Gwiazda::ObliczWartoscFunkcji()
{
	double f[1];
	cec17_test_func(x, f, 10, 1, 1);
	wartoscFunkcji = f[0];
	fitness = 1.0 / wartoscFunkcji;
}

Gwiazda::Gwiazda(Gwiazda* CzarnaDziura)
{
	for (int i = 0; i < 10; i++)
	{
		x[i] = (double)((rand() % 10001) / 50.0 - 100);
		v[i] = 0.;
	}
	ObliczWartoscFunkcji();
	if (SprawdzCzyNowaCzarnaDziura(CzarnaDziura))
	{
		promienSchwarzschilda = fitness / SumaFitnesow/ 1000;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			v[i] = ((double)rand() / (RAND_MAX)) * (CzarnaDziura->x[i] - x[i]);
			x[i] += v[i];
		}
	}
}

Gwiazda::Gwiazda()
{
	for (int i = 0; i < 10; i++)
	{
		x[i] = (double)((rand() % 10001) / 50.0 - 1000);
		v[i] = 0.;
	}
		ObliczWartoscFunkcji();
		SumaFitnesow = wartoscFunkcji * 30;
		promienSchwarzschilda = fitness / SumaFitnesow / 1000;
}

bool Gwiazda::SprawdzCzyNowaCzarnaDziura(Gwiazda* CzarnaDziura)
{
	if (wartoscFunkcji <= CzarnaDziura->wartoscFunkcji)
	{
		promienSchwarzschilda = fitness / SumaFitnesow/ 1000;
		return true;
	}
	else
		return false;
}

double Gwiazda::OdlegloscOdCzarnejDziury(Gwiazda* CzarnaDziura)
{
	double temp = 0;
	for (int i = 0; i < 10; i++)
		temp += (x[i] - CzarnaDziura->x[i])*(x[i] - CzarnaDziura->x[i]);
	return sqrt(temp);
}

void Gwiazda::AktualizujPolozenie(Gwiazda* CzarnaDziura)
{
	for (int i = 0; i < 10; i++)
	{
		v[i] = ((double)rand() / (RAND_MAX)) * (CzarnaDziura->x[i] - x[i]);
		x[i] += v[i];
	}
	if (OdlegloscOdCzarnejDziury(CzarnaDziura) < CzarnaDziura->promienSchwarzschilda)
	{
		for (int i = 0; i < 10; i++)
			x[i] = (double)((rand() % 10001) / 50.0 - 100);
	}
}
