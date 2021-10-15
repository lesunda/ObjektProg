#include "medianoskaiciavimas.h"
#include<iostream>    
#include<algorithm>
using namespace std;

double medianos_skaiciavimas(std::vector<double> MokinioPazymiai) //Skaiciuojame mediana.
{
    int Dydis;
    Dydis = MokinioPazymiai.size();
    if (Dydis == 0)
    {
        return 0;
    }
    else
    {
        sort(MokinioPazymiai.begin(), MokinioPazymiai.end());
        for (int i = 0; i < Dydis; i++) {
        }
        if (Dydis % 2 == 0)
        {
            return (MokinioPazymiai[Dydis / 2 - 1] + MokinioPazymiai[Dydis / 2.0]) / 2.0;
        }
        else
        {
            return  MokinioPazymiai[Dydis / 2.0];
        }
    }

}
