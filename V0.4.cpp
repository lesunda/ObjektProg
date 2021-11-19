#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include <list>
#include <algorithm>

using namespace std;

struct studentas {
	std::string Vard, Pav;
	float GALPAZ = 0;
};

//--------------------------------------------------------------------------------------------------------------------------------------------------

int random_pazymiu_sudarymas() {
	return rand() % 10 + 1;
}

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

//---------------------------------------------------------------------------------------------------------------------------------------------------

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
	cout << "------------------------------------------------------------------------------------------------" << endl;
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

int pagrindinio_failo_nuskaitymas(vector<studentas>& Eil, int stud_skaicius) {
	int studento_numeris = 0;
	ifstream failo_nuskaitymas;
	string pavadinimas = "Visi_Studentai" + to_string(stud_skaicius) + ".txt";
	string n;
	float skirtumas2 = 0;


	failo_nuskaitymas.open(pavadinimas);
	if (failo_nuskaitymas.is_open()) {

		auto startas2 = chrono::high_resolution_clock::now(); //STARTAS//
	
		getline(failo_nuskaitymas >> ws, n);


		while (studento_numeris < stud_skaicius) {

			Eil.resize(Eil.size() + 1);
			failo_nuskaitymas >> Eil.at(studento_numeris).Vard;
			failo_nuskaitymas >> Eil.at(studento_numeris).Pav;
			failo_nuskaitymas >> Eil.at(studento_numeris).GALPAZ;
			studento_numeris++;
		}
		auto endas2 = chrono::high_resolution_clock::now(); //PABAIGA//
		chrono::duration<double> skirtumas2 = endas2 - startas2;
		cout << to_string(stud_skaicius) + " studentu duomenu nuskaitymas is pagrindinio failo uztruko " << skirtumas2.count() << " sekundziu." << endl;

	}
	return skirtumas2;
}

void nuskriaustukai_ir_galvotukai(vector<studentas>& Eil, vector<studentas>& galvociai, vector<studentas>& nuskriaustukai) {

	double atskaitos_pazymio_taskas = 5.00;

	for (int m = 0; m < Eil.size(); m++) {
		if (Eil.at(m).GALPAZ < atskaitos_pazymio_taskas) {
			nuskriaustukai.push_back(Eil.at(m));
		}
		else {
			galvociai.push_back(Eil.at(m));
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	vector<int> studentu_skaicius;
	int studentu_kiekis = pagrindinio_failo_kurimas(studentu_skaicius);

	vector<studentas> visi_studentai;
	pagrindinio_failo_nuskaitymas(visi_studentai, studentu_kiekis);

	vector<studentas> galvociai;
	vector<studentas> nuskriaustukai;


	auto startas3 = chrono::high_resolution_clock::now(); //STARTAS//
	nuskriaustukai_ir_galvotukai(visi_studentai, galvociai, nuskriaustukai);
	auto endas3 = chrono::high_resolution_clock::now(); //PABAIGA//

	chrono::duration<double> skirtumas3 = endas3 - startas3;


	cout << to_string(studentu_kiekis) + " studentu rusiavimas i dvi skirtingas grupes uztruko " << skirtumas3.count() << " sekundziu." << endl;


	string failo_pavadinimas;
	failo_pavadinimas = "Mokiniai_Nuskriaustukai " + to_string(studentu_kiekis - galvociai.size()) + ".txt";
	ofstream nuskriaustuku_failas(failo_pavadinimas);


	auto startas4 = chrono::high_resolution_clock::now(); //STARTAS//

	//nuskriaustuku_failas << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis" << endl;
	nuskriaustuku_failas << "--------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < studentu_kiekis; i++) {
		if (visi_studentai.at(i).GALPAZ < 5.00) {
			nuskriaustuku_failas << visi_studentai.at(i).Vard << setw(20) << visi_studentai.at(i).Pav << setw(20) << visi_studentai.at(i).GALPAZ << endl;
		}

	}

	auto endas4 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas4 = endas4 - startas4;
	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu nuskriaustuku irasymo i faila laikas yra lygus " << skirtumas4.count() << " sekundziu." << endl;



	failo_pavadinimas = "Mokiniai_Galvotukai " + to_string(studentu_kiekis - nuskriaustukai.size()) + ".txt";
	ofstream galvotuku_failas(failo_pavadinimas);


	auto startas5 = chrono::high_resolution_clock::now(); //STARTAS//

	//galvotuku_failas << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis" << endl;
	galvotuku_failas << "--------------------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < studentu_kiekis; j++) {
		if (visi_studentai.at(j).GALPAZ >= 5.00) {
			galvotuku_failas << visi_studentai.at(j).Vard << setw(20) << visi_studentai.at(j).Pav << setw(20) << visi_studentai.at(j).GALPAZ << endl;
		}
	}
	auto endas5 = chrono::high_resolution_clock::now(); //PABAIGA//
	chrono::duration<double> skirtumas5 = endas5 - startas5;
	cout << "Is " + to_string(studentu_kiekis) + " studentu atrinktu galvotuku irasymo i faila laikas yra lygus " << skirtumas5.count() << " sekundziu." << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;



	return 0;
}




