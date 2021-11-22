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

list<int> automatinis_pazymiu_generavimas_kiekv_stud(int pazymiu_skaicius) {
	list<int> kiekvieno_mok_pazymiai;
	for (int i = 0; i < pazymiu_skaicius; i++) {
		kiekvieno_mok_pazymiai.push_back(random_pazymiu_sudarymas());
	}
	return kiekvieno_mok_pazymiai;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

double galutinio_pazymio_skaiciavimas(list<int> kiekvieno_mok_pazymiai) {
	studentas Eil;
	Eil.GALPAZ = 0.4 * accumulate(kiekvieno_mok_pazymiai.begin(), kiekvieno_mok_pazymiai.end(), 0) / kiekvieno_mok_pazymiai.size() + 0.6 * random_pazymiu_sudarymas();
	return Eil.GALPAZ;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

int pagrindinio_failo_kurimas(list<int> studentu_skaicius) {
	int studentu_kiekis;
	cout << "Iveskite skaiciu keliu studentu rezultatus noresite matyti:  " << endl;
	cin >> studentu_kiekis;
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
		pagr_failo_spausd << setw(20) << "Vardenis" + to_string(s) << setw(20) << "Pavardenis" + to_string(s) << setw(20) << galutinio_pazymio_skaiciavimas(mokinio_pazymiai) << endl;
		mokinio_pazymiai.clear();

	}

	auto endas1 = chrono::high_resolution_clock::now();  //PABAIGA//
	chrono::duration<double> skirtumas1 = endas1 - startas1;


	cout << to_string(studentu_kiekis) + " studentu pagrindinis failo kurimas uztruko " << skirtumas1.count() << " sekundziu." << endl;

	return studentu_kiekis;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------


void nuskriaustukai_ir_galvotukai(list<studentas>& Eil, list<studentas>& nuskriaustukai)
{
	copy_if(Eil.begin(), Eil.end(), back_inserter(nuskriaustukai), [](studentas x) {return x.GALPAZ < 5; });
	Eil.erase(remove_if(Eil.begin(), Eil.end(), [](studentas x) {return x.GALPAZ < 5; }), Eil.end());

}

//-------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	list<int> studentu_skaicius;
	list<studentas> nuskriaustukai;
	int studentu_kiekis = pagrindinio_failo_kurimas(studentu_skaicius);

	list<studentas> visi_studentai;
	pagrindinio_failo_nuskaitymas(visi_studentai, studentu_kiekis);


	auto startas3 = chrono::high_resolution_clock::now(); //STARTAS//
	nuskriaustukai_ir_galvotukai(visi_studentai, nuskriaustukai);
	auto endas3 = chrono::high_resolution_clock::now(); //PABAIGA//


	chrono::duration<double> skirtumas3 = endas3 - startas3;

	cout << to_string(studentu_kiekis) + " studentu rusiavimas i dvi skirtingas grupes uztruko " << skirtumas3.count() << " sekundziu." << endl;


	string failo_pavadinimas;
	failo_pavadinimas = "Mokiniai_Nuskriaustukai " + to_string(studentu_kiekis - visi_studentai.size()) + ".txt";
	ofstream nuskriaustuku_failas(failo_pavadinimas);


	auto startas4 = chrono::high_resolution_clock::now(); //STARTAS//


	for (auto const& i : nuskriaustukai) {
		nuskriaustuku_failas << i.Vard << setw(20) << i.Pav << setw(20) << i.GALPAZ << endl;
	}

	auto endas4 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas4 = endas4 - startas4;
	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu nuskriaustuku irasymo i faila laikas yra lygus " << skirtumas4.count() << " sekundziu." << endl;



	failo_pavadinimas = "Mokiniai_Galvotukai " + to_string(studentu_kiekis - nuskriaustukai.size()) + ".txt";
	ofstream galvotuku_failas(failo_pavadinimas);


	auto startas5 = chrono::high_resolution_clock::now(); //STARTAS//


	for (auto const& i : visi_studentai) {
		galvotuku_failas << i.Vard << setw(20) << i.Pav << setw(20) << i.GALPAZ << endl;
	}
	auto endas5 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas5 = endas5 - startas5;
	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu galvotuku irasymo i faila laikas yra lygus " << skirtumas5.count() << " sekundziu." << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	return 0;
}
