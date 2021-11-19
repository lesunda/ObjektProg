#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <list>
#include "studentas.h"
#include "pagrindinio_failo_nuskaitymas.h"
#include "random_pazymiu_sudarymas.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------------------

vector<int> automatinis_pazymiu_generavimas_kiekv_stud(int pazymiu_skaicius) {
	vector<int> kiekvieno_mok_pazymiai;
	for (int i = 0; i < pazymiu_skaicius; i++) {
		kiekvieno_mok_pazymiai.push_back(random_pazymiu_sudarymas());
	}
	return kiekvieno_mok_pazymiai;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

double galutinio_pazymio_skaiciavimas_su_vidurkiu(vector<int> kiekvieno_mok_pazymiai) {
	studentas Eil;
	Eil.GALPAZ = 0.4 * accumulate(kiekvieno_mok_pazymiai.begin(), kiekvieno_mok_pazymiai.end(), 0) / kiekvieno_mok_pazymiai.size() + 0.6 * random_pazymiu_sudarymas();
	return Eil.GALPAZ;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

double medianos_skaiciavimas(vector<int> kiekvieno_mok_pazymiai) {
	studentas Eil;
	int Dydis;
	Dydis = kiekvieno_mok_pazymiai.size();
	if (Dydis == 0)
	{
		return 0;
	}
	else
	{
		sort(kiekvieno_mok_pazymiai.begin(), kiekvieno_mok_pazymiai.end());
		//for (int i = 0; i < Dydis; i++) {
		//}
		if (Dydis % 2 == 0)
		{
			//return (kiekvieno_mok_pazymiai[Dydis / 2 - 1] + kiekvieno_mok_pazymiai[Dydis / 2.0]) / 2.0;
			return Eil.GALPAZ = 0.4 * ((kiekvieno_mok_pazymiai[Dydis / 2 - 1] + kiekvieno_mok_pazymiai[Dydis / 2.0]) / 2.0) + 0.6 * random_pazymiu_sudarymas();
		}
		else
		{
			//return  kiekvieno_mok_pazymiai[Dydis / 2.0];
			return Eil.GALPAZ = 0.4 * (kiekvieno_mok_pazymiai[Dydis / 2.0]) + 0.6 * random_pazymiu_sudarymas();
		}
	}

}


//--------------------------------------------------------------------------------------------------------------------------------------------------

int pagrindinio_failo_kurimas(vector<int> studentu_skaicius) {
	int studentu_kiekis;
	string pasirinkimas;


	cout << "Iveskite skaiciu keliu studentu rezultatus noresite matyti:  " << endl;
	cin >> studentu_kiekis;
	cout << "Iveskite kaip noresite skaiciuoti galutini pazymi. Jeigu su mediana rasykite M. Su vidurkiu rasykite V." << endl;
	cin >> pasirinkimas;


	while (pasirinkimas != "m" && pasirinkimas != "M" && pasirinkimas != "v" && pasirinkimas != "V") {
		std::cout << "Iveskite tai, ko prasoma.\n";
		std::cin >> pasirinkimas;
	}

	if (pasirinkimas == "v" || pasirinkimas == "V") {

		cout << "------------------------------------------------------------------------------------------------" << endl;


		string pagr_failo_pav = "Visi_Studentai" + to_string(studentu_kiekis) + ".txt";


		auto startas1 = chrono::high_resolution_clock::now(); //STARTAS//


		ofstream pagr_failo_spausd(pagr_failo_pav);
		vector<int> mokinio_pazymiai;

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


		cout << to_string(studentu_kiekis) + " studentu pagrindinis failo kurimas uztruko " << skirtumas1.count() << " sekundziu." << endl;

		return studentu_kiekis;
	}

	if (pasirinkimas == "m" || pasirinkimas == "M") {
		cout << "------------------------------------------------------------------------------------------------" << endl;


		string pagr_failo_pav = "Visi_Studentai" + to_string(studentu_kiekis) + ".txt";


		auto startas1 = chrono::high_resolution_clock::now(); //STARTAS//


		ofstream pagr_failo_spausd(pagr_failo_pav);
		vector<int> mokinio_pazymiai;

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
	}




}

//--------------------------------------------------------------------------------------------------------------------------------------------------

studentas get(std::list<studentas> _list, int _i) {
	std::list<studentas>::iterator it = _list.begin();
	//?????
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/*void nuskriaustukai_ir_galvotukai(vector<studentas>& Eil, vector<studentas>& nuskriaustukai)
{
	double atskaitos_pazymio_taskas = 5.00;
	for (int m = 0; m < Eil.size(); m++) {
		if (get(Eil, m).GALPAZ.GALPAZ < atskaitos_pazymio_taskas) {
			nuskriaustukai.push_back(get(Eil, m));
			Eil.erase(Eil.begin() + m);
			m--;
		}
	}
}*/

//--------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	vector<int> studentu_skaicius;

	double atskaitos_pazymio_taskas = 5.00;

	list<studentas> visi_studentai;
	int studentu_kiekis = pagrindinio_failo_kurimas(studentu_skaicius);

	pagrindinio_failo_nuskaitymas(visi_studentai, studentu_kiekis);

	list<studentas> nuskriaustukai;

	auto startas3 = chrono::high_resolution_clock::now(); //STARTAS//

	for (int m = 0; m < visi_studentai.size(); m++) {
		if (get(visi_studentai, m).GALPAZ < atskaitos_pazymio_taskas) {
			nuskriaustukai.push_back(get(visi_studentai, m));
			visi_studentai.erase(visi_studentai.begin() + m);
			m--;
		}
	}

	auto endas3 = chrono::high_resolution_clock::now(); //PABAIGA//


	chrono::duration<double> skirtumas3 = endas3 - startas3;

	cout << to_string(studentu_kiekis) + " studentu rusiavimas i dvi skirtingas grupes uztruko " << skirtumas3.count() << " sekundziu." << endl;


	string failo_pavadinimas;
	failo_pavadinimas = "Mokiniai_Nuskriaustukai " + to_string(studentu_kiekis - visi_studentai.size()) + ".txt";
	ofstream nuskriaustuku_failas(failo_pavadinimas);


	auto startas4 = chrono::high_resolution_clock::now(); //STARTAS//


	for (int i = 0; i < nuskriaustukai.size(); i++) {
		nuskriaustuku_failas << get(nuskriaustukai, i).Vard << setw(20) << get(nuskriaustukai, i).Pav << setw(20) << get(nuskriaustukai, i).GALPAZ << endl;
	}

	auto endas4 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas4 = endas4 - startas4;
	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu nuskriaustuku irasymo i faila laikas yra lygus " << skirtumas4.count() << " sekundziu." << endl;



	failo_pavadinimas = "Mokiniai_Galvotukai " + to_string(visi_studentai.size()) + ".txt";
	ofstream galvotuku_failas(failo_pavadinimas);


	auto startas5 = chrono::high_resolution_clock::now(); //STARTAS//


	for (int j = 0; j < visi_studentai.size(); j++) {
		galvotuku_failas << get(visi_studentai, j).Vard << setw(20) << get(visi_studentai, j).Pav << setw(20) << get(visi_studentai, j).GALPAZ << endl;
	}

	auto endas5 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas5 = endas5 - startas5;


	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu galvotuku irasymo i faila laikas yra lygus " << skirtumas5.count() << " sekundziu." << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	return 0;
}
