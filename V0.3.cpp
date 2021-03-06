#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "studentas.h"
#include "medianoskaiciavimas.h"
#include "vidurkis.h"

void vardPavgz_ivedimas(studentas Eil[], int i) //Funkcija, duodanti suvesti vardus ir pavares bei egzamino rezultata.
{
    std::cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
    std::cin >> Eil[i].Vard;
    std::cout << "Iveskite studento nr. " << i + 1 << " Pav:\n";
    std::cin >> Eil[i].Pav;
    std::cout << "Iveskite studento nr. " << i + 1 << " egzamino ivertinima:\n";

    for (;;) {
        if (std::cin >> Eil[i].egz && Eil[i].egz > 0 && Eil[i].egz <= 10) {
            break;
        }
        else {
            if (std::cin.eof()) break;
            std::cout << "Ivedete negalima egzamino ivertinima, bandykite vesti dar karta:\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
        }
    }
}

void mok_paz(studentas Eil[], int i) //Funkcija, duodanti ivesti vartotojui mokiniu pazymius.
{
    double laikinas;
    std::cout << "Veskite studento pazymius, kaip manysite, kad pazymiu uztenka parasykite -1\n";

    for (;;)
    {
        std::cout << "Iveskite pazymi:\n";
        if (std::cin >> laikinas && laikinas <= 10 && laikinas != 0 && laikinas >= -1)
        {
            if (laikinas != -1)
            {
                Eil[i].paz.push_back(laikinas);
            }
            else
            {
                break;
            }
        }
        else {
            std::cout << "Ivedete visiskai ne toki simboli, kuri reikia ivesti. Iveskite pazymi nuo 1 iki 10 imtinai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

}

int random_paz_generatorius() //Generuojame random skaiciu intervale nuo 1 iki 10.
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void random_paz_ivedimas(studentas Eil[], int i, int kiek_paz) //Ivedame automatiskai sugeneruotus pazymius.
{

    for (int x = 0; x < kiek_paz; x++)
    {
        Eil[i].paz.push_back(random_paz_generatorius());
    }
}

void gal_paz_su_vidurkiu(studentas Eil[], int studentu_kiekis) //Galutinio pazymio skaiciavimas su vidurkiu.
{
    float Vidurkis;
    float Suma;
    int Dydis;
    for (int i = 0; i < studentu_kiekis; i++) {
        Suma = std::accumulate(Eil[i].paz.begin(), Eil[i].paz.end(), 0);
        Dydis = (Eil[i].paz.size());
        Vidurkis = Suma / (Eil[i].paz.size());
        Eil[i].GALPAZ = Vidurkis * 0.4 + Eil[i].egz * 0.6;
    }
}

void rez_vid_print(studentas Eil[], int studentu_kiekis) //Atspausdina galutinius rezultatus su vidurkiu.
{
    std::cout << "\n\n";
    std::cout << std::setw(20) << std::left << "Vard"
        << std::setw(20) << std::left << "Pav"
        << std::setw(16) << std::left << "GALPAZ(vid.)\n";
    std::cout << std::left << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_kiekis; i++)
    {
        std::cout << std::setw(20) << std::left << Eil[i].Vard
            << std::setw(20) << std::left << Eil[i].Pav
            << std::setw(16) << std::left << Eil[i].GALPAZ << std::endl;
    }
    std::cout << "\n\n";
}


void gal_paz_su_mediana(studentas Eil[], int studentu_kiekis) //Galutinio pazymio skaiciavimas su mediana.
{

    for (int i = 0; i < studentu_kiekis; i++) {

        Eil[i].GALPAZ = (medianos_skaiciavimas(Eil[i].paz) * 0.4 + Eil[i].egz * 0.6);
    }
}

void rez_med_print(studentas Eil[], int studentu_kiekis) //Atspausdina galutinius rezultatus su mediana.
{
    std::cout << "\n\n";

    std::cout << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde" <<
        std::setw(18) << std::left << "Galutinis(med.)\n"
        << std::left << "---------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_kiekis; i++)
    {
        std::cout << std::setw(20) << std::left << Eil[i].Vard
            << std::setw(20) << std::left << Eil[i].Pav
            << std::setw(18) << std::left << Eil[i].GALPAZ << std::endl;
    }
    std::cout << "\n\n";
}

bool palyginimas(studentas& studentasPirmas, studentas& studentasAntras)
{
    return studentasPirmas.Vard < studentasAntras.Vard;
}


double mediana(vector<double> namuDarbuPazymiai) {
    double mediana;
    int ilgis = namuDarbuPazymiai.size();
    sort(namuDarbuPazymiai.begin(), namuDarbuPazymiai.end());

    if (ilgis % 2 == 0) {
        return (namuDarbuPazymiai[ilgis / 2] + namuDarbuPazymiai[(ilgis / 2) - 1]) / 2.;
    }
    else {
        return namuDarbuPazymiai[ilgis / 2];
    }
}

bool palyginimas(studentas pirmas, studentas antras)
{
    return pirmas.Vard < antras.Vard;
}

void spaudinkStudenta(vector<studentas> grupe)
{
    ofstream output;
    output.open("rezultatai.txt");
    output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << endl;
    output << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size() - 1; i++) {
        output << fixed << left << setw(20) << grupe[i].Vard << setw(20) << grupe[i].Pav << setw(20) << setprecision(2) << grupe[i].GALPAZ << endl;
    }
}

int main()
{
    int stulpeliai = 0;
    int eilutes = 0;
    double laikinas;
    string elementas;
    string eil;
    studentas stud;
    vector <studentas> grupe;
    double vidurk;
    double median;
    int isvestis = 0;
    studentas Eil[25];
    std::string laikinas3;
    std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti is failo, spauskite R.Jeigu norite suvesti duomenis patys - spauskite P.\n";
    std::cin >> laikinas3;
    while (laikinas3 != "r" && laikinas3 != "R" && laikinas3 != "p" && laikinas3 != "P") {
        std::cout << "Iveskite tai, ko prasoma.\n";
        std::cin >> laikinas3;
    }

    if (laikinas3 == "r" || laikinas3 == "R")
    {
        try {
            ifstream openF;
            openF.open("kursiokai.txt");
            if (openF.is_open()) {
                openF.close();
            }
            else {
                throw 505;
            }
        }
        catch (int myNum) {
            cout << "Error: Failas pavadinimu 'kursiokai.txt' nebuvo rastas." << endl;
            exit(1);
        }

        cout << "Jei norite isvesti studento galutini pazymi su namu darbu vidurkiu iveskite 1, jei su mediana spauskite 0" << endl;
        cin >> isvestis;
        while (isvestis != 1 && isvestis != 0) {
            cout << "Ivestas netikamas simbolis. Iveskite is naujo:" << endl;
            cin >> isvestis;
        }


        ifstream openF("kursiokai.txt");

        while (true)
        {
            if (!openF.eof())
            {
                getline(openF, eil);
                eilutes++;
                if (eilutes == 1) {
                    stringstream s(eil);
                    while (s >> elementas) {
                        stulpeliai++;
                    }
                }
                openF >> stud.Vard >> stud.Pav;
                stulpeliai = stulpeliai - 2;
                stud.paz.reserve(stulpeliai - 1);
                for (int i = 0; i < stulpeliai - 1; i++) {
                    openF >> laikinas;
                    stud.paz.push_back(laikinas);
                }

                openF >> stud.egz;
                if (isvestis == 1) {
                    vidurk = vidurkis(stud.paz);
                    stud.GALPAZ = 0.4 * vidurk + 0.6 * stud.egz;
                }
                else
                {
                    median = mediana(stud.paz);
                    stud.GALPAZ = 0.4 * median + 0.6 * stud.egz;
                }
                grupe.push_back(stud);
                stud.paz.clear();
            }
            else break;
        }
        openF.close();
        //sort(grupe.begin(), grupe.end(), palyginimas);
        spaudinkStudenta(grupe);
    }

    else {
        {
            std::cout << "\n\n\n\n\n";
            std::string laikinas;
            int studentu_kiekis;
            std::string laikinas2;

            std::cout << "Iveskite skaiciu, keliu studentu pazymius reiks skaiciuoti:\n";
            for (;;) {
                if (std::cin >> studentu_kiekis) {
                    break;
                }
                else {
                    if (std::cin.eof()) break;
                    std::cout << "Ivedete neteisinga simboli, iveskite studentu kieki\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }


            std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai tuomet spauskite \"R\".\nJeigu norite suvesti duomenis patys - spauskite \"P\".\n";
            std::cin >> laikinas;
            while (laikinas != "r" && laikinas != "R" && laikinas != "p" && laikinas != "P") {
                std::cout << "Iveskite tai, ko prasoma.\n";
                std::cin >> laikinas;
            }

            if (laikinas == "p" || laikinas == "P")
            {
                for (int i = 0; i < studentu_kiekis; i++)
                {
                    vardPavgz_ivedimas(Eil, i);
                    mok_paz(Eil, i);
                }
            }
            else
            {
                for (int i = 0; i < studentu_kiekis; i++)
                {
                    vardPavgz_ivedimas(Eil, i);
                    random_paz_ivedimas(Eil, i, 5);
                }
            }
            std::cout << "Jeigu norite, kad studento galutinis pazimys pazymys butu skaiciuojamas imant vidurki, tuomet spauskite\"V\"\n Jeigu norite, kad GALPAZ pazymys butu skaiciuojamas imant mediana, spauskite\"M\"\n";
            std::cin >> laikinas2;
            while (laikinas2 != "v" && laikinas2 != "V" && laikinas2 != "m" && laikinas2 != "M") {
                std::cout << "Iveskite tai, ko prasoma.\n";
                std::cin >> laikinas2;
            }

            if (laikinas2 == "v" || laikinas2 == "V") {
                gal_paz_su_vidurkiu(Eil, studentu_kiekis);
                rez_vid_print(Eil, studentu_kiekis);
            }

            else
            {
                gal_paz_su_mediana(Eil, studentu_kiekis);
                rez_med_print(Eil, studentu_kiekis);
            }

        }
    }
    return 0;
}
