
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include <list>
#include "pagrindinio_failo_nuskaitymas.h"

int pagrindinio_failo_nuskaitymas(list<studentas>& Eil, int stud_skaicius) {
	int studento_numeris = 0;
	ifstream failo_nuskaitymas;
	string pavadinimas = "Visi_Studentai" + to_string(stud_skaicius) + ".txt";
	string n;
	float skirtumas2 = 0;
	studentas dellisto;


	failo_nuskaitymas.open(pavadinimas);
	if (failo_nuskaitymas.is_open()) {

		auto startas2 = chrono::high_resolution_clock::now(); //STARTAS//

		getline(failo_nuskaitymas >> ws, n);


		while (studento_numeris < stud_skaicius) {


			failo_nuskaitymas >> dellisto.Vard;
			failo_nuskaitymas >> dellisto.Pav;
			failo_nuskaitymas >> dellisto.GALPAZ;



			Eil.push_back(dellisto);
			studento_numeris++;
		}
		auto endas2 = chrono::high_resolution_clock::now(); //PABAIGA//
		chrono::duration<double> skirtumas2 = endas2 - startas2;
		cout << to_string(stud_skaicius) + " studentu duomenu nuskaitymas is pagrindinio failo uztruko " << skirtumas2.count() << " sekundziu." << endl;

	}
	return skirtumas2;
}
