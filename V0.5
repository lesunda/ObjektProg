#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <list>
#include "studentas.h"
#include "pagrindinio_failo_nuskaitymas.h"
#include "random_pazymiu_sudarymas.h"
//--------------------------------------------------------------------------------------------------------------------------------------------------

list<int> automatinis_pazymiu_generavimas_kiekv_stud(int pazymiu_skaicius) {
	list<int> kiekvieno_mok_pazymiai;
	for (int i = 0; i < pazymiu_skaicius; i++) {
		kiekvieno_mok_pazymiai.push_back(random_pazymiu_sudarymas());
	}
	return kiekvieno_mok_pazymiai;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

double galutinio_pazymio_skaiciavimas_su_vidurkiu(list<int> kiekvieno_mok_pazymiai) {
	studentas Eil;
	Eil.GALPAZ = 0.4 * accumulate(kiekvieno_mok_pazymiai.begin(), kiekvieno_mok_pazymiai.end(), 0) / kiekvieno_mok_pazymiai.size() + 0.6 * random_pazymiu_sudarymas();
	return Eil.GALPAZ;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
double medianos_skaiciavimas(list<int> kiekvieno_mok_pazymiai) {
	double median;
    auto itr = kiekvieno_mok_pazymiai.begin();

    // n is even
    if(kiekvieno_mok_pazymiai.size() % 2 == 0 ) {
        for( int i = 0 ; i < kiekvieno_mok_pazymiai.size() / 2 ; i ++ ) {
            itr++;
        }

        median = ( (double)*itr + *--itr ) / 2;
    }
    // n is odd
    else {
        for( int i = 0 ; i < kiekvieno_mok_pazymiai.size() / 2 ; i ++ ) {
            itr++;
        }

        median = *itr;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------------------
int pagrindinio_failo_kurimas(list<int> studentu_skaicius) {
	int studentu_kiekis;
	string pasirinkimas;


	cout << "Iveskite skaiciu keliu studentu rezultatus noresite matyti:  " << endl;
	cin >> studentu_kiekis;
	/*cout << "Iveskite kaip noresite skaiciuoti galutini pazymi. Jeigu su mediana rasykite M. Su vidurkiu rasykite V." << endl;
	cin >> pasirinkimas;*/


		cout << "------------------------------------------------------------------------------------------------" << endl;

		string pagr_failo_pav = "Visi_Studentai" + to_string(studentu_kiekis) + ".txt";


		auto startas1 = chrono::high_resolution_clock::now(); //STARTAS//


		ofstream pagr_failo_spausd(pagr_failo_pav);
		list<int> mokinio_pazymiai;

		pagr_failo_spausd << setw(20) << left << "Vardenis"
			<< setw(20) << left << "Pavardenis"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;



		for (int s = 1; s <= studentu_kiekis; s = s + 1) {
			mokinio_pazymiai = automatinis_pazymiu_generavimas_kiekv_stud(5);
			pagr_failo_spausd << setw(20) << "Vardenis" + to_string(s) << setw(20) << "Pavardenis" + to_string(s) << setw(20) << galutinio_pazymio_skaiciavimas_su_vidurkiu(mokinio_pazymiai) << endl;
			mokinio_pazymiai.clear();

		}

		auto endas1 = chrono::high_resolution_clock::now();  //PABAIGA//
		chrono::duration<double> skirtumas1 = endas1 - startas1;


		//cout << to_string(studentu_kiekis) + " studentu pagrindinis failo kurimas uztruko " << skirtumas1.count() << " sekundziu." << endl;

		return studentu_kiekis;

		/*if (pasirinkimas == "m" || pasirinkimas == "M") {
			cout << "------------------------------------------------------------------------------------------------" << endl;


			string pagr_failo_pav = "Visi_Studentai" + to_string(studentu_kiekis) + ".txt";


			auto startas1 = chrono::high_resolution_clock::now(); //STARTAS//


			ofstream pagr_failo_spausd(pagr_failo_pav);
			list<int> mokinio_pazymiai;

			pagr_failo_spausd << setw(20) << left << "Vardenis"
				<< setw(20) << left << "Pavardenis"
				<< setw(20) << left << "Galutinis(Med.)" << endl;



			for (int s = 1; s <= studentu_kiekis; s = s + 1) {
				mokinio_pazymiai = automatinis_pazymiu_generavimas_kiekv_stud(5);
				pagr_failo_spausd << setw(20) << "Vardenis" + to_string(s) << setw(20) << "Pavardenis" + to_string(s) << setw(20) << medianos_skaiciavimas(mokinio_pazymiai) << endl;
				mokinio_pazymiai.clear();

			}

			auto endas1 = chrono::high_resolution_clock::now();  //PABAIGA//
			chrono::duration<double> skirtumas1 = endas1 - startas1;


			cout << to_string(studentu_kiekis) + " studentu pagrindinis failo kurimas uztruko " << skirtumas1.count() << " sekundziu." << endl;

			return studentu_kiekis;
		}*/



	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------


/*studentas get(std::list<studentas> _list, int _i) {
	std::list<studentas>::iterator it = _list.begin();
	//?????
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}*/


//--------------------------------------------------------------------------------------------------------------------------------------------------

int main() {


	list<int> studentu_skaicius;
	int studentu_kiekis = pagrindinio_failo_kurimas(studentu_skaicius);

	list<studentas> visi_studentai;
	pagrindinio_failo_nuskaitymas(visi_studentai, studentu_kiekis);


	list<studentas> galvociai;
	list<studentas> nuskriaustukai;

	float atskaitos_pazymio_taskas = 5;


	auto startas3 = chrono::high_resolution_clock::now(); //STARTAS//

	
	for (auto i : visi_studentai)
	{
		if (i.GALPAZ >= atskaitos_pazymio_taskas)
		{
			galvociai.push_back(i);
		}
		else
		{
			nuskriaustukai.push_back(i);
		}
	}


	auto endas3 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas3 = endas3 - startas3;

	cout << to_string(studentu_kiekis) + " studentu rusiavimas i dvi skirtingas grupes uztruko " << skirtumas3.count() << " sekundziu." << endl;


	string failo_pavadinimas;
	failo_pavadinimas = "Mokiniai_Nuskriaustukai " + to_string(studentu_kiekis - galvociai.size()) + ".txt";
	ofstream nuskriaustuku_failas(failo_pavadinimas);


	auto startas4 = chrono::high_resolution_clock::now(); //STARTAS//


	for (auto const& i : nuskriaustukai) {
		nuskriaustuku_failas << i.Vard << setw(20) << i.Pav << setw(20) << i.GALPAZ << endl;
	}

	auto endas4 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas4 = endas4 - startas4;
	//cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu nuskriaustuku irasymo i faila laikas yra lygus " << skirtumas4.count() << " sekundziu." << endl;



	failo_pavadinimas = "Mokiniai_Galvotukai " + to_string(studentu_kiekis - nuskriaustukai.size()) + ".txt";
	ofstream galvotuku_failas(failo_pavadinimas);


	auto startas5 = chrono::high_resolution_clock::now(); //STARTAS//


	for (auto const& i : galvociai) {
		galvotuku_failas << i.Vard << setw(20) << i.Pav << setw(20) << i.GALPAZ << endl;
	}


	auto endas5 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas5 = endas5 - startas5;
	//cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu galvotuku irasymo i faila laikas yra lygus " << skirtumas5.count() << " sekundziu." << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;


	return 0;
}





