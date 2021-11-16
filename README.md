***DĖMESIO***
***!!!***
Kiekviename faile, kurio pavadinime slepiasi žodis PAPILDYMAS reiškia, kad aš klausydamasis savo grupiokų atsiskaitymų ir tai, kad prašėte jų ištaisyti savo klaidas, patobulinau savo programą, kadangi pas mane buvo panašios klaidos. Įdėta mediana į skaičiavimus, bei dalis programos išskirstyta i header tipo failus. Pagrindinis darbas buvo įkeltas laiku.
Atnaujinta 2021-11-16.
***!!!***

***V0.5***

Tai yra visiškai identiškai ta pati programa, kuri buvo ir V0.4 užduotyje. Tik vietoj std::vector<studentas> pakeista į std::list<studentas>. Ši programa išveda tik laiką, per kurį yra nuskaitomi pagrindiniai duomenys ir surūšiuojami studentai į dvi grupes.
  
  **Taigi sugaištas laikas nuskaitant duomenis iš failų:**
  a) 1000 studentų -  0.0013919 sekundžių.
  b) 10000 studentų -  0.011648 sekundžių.
  c) 100000 studentų - 0.118677 sekundžių.
  d) 1000000 studentų -  1.57832 sekundžių.
  e) 10000000 studentų - 19.9111 sekundziu.
  
  
  
  **Sugaištas laikas surūšiuojant į dvi grupes:**
  a) 1000 studentų - 0.378938 sekundžių.
  b) 10000 studentų - 29.0099 sekundžių.
  c) 100000 studentų - 1126.7371 sekundžių.
  d) 1000000 studentų - neskaičiavau kadangi tai truktų nemažą laiko tarpą, tačiau atsižvelgiant i praeitų studentų didėjimą galima būtų daryti prielaidą, kad 1000000 studentų bus sūrušiuota į dvi grupes per ~30000 sekundžių.
  e) 10000000 studentų - neskaičiavau kadangi tai truktų nemažą laiko tarpą, tačiau atsižvelgiant i praeitų studentų didėjimą galima būtų daryti prielaidą, kad 10000000 studentų bus sūrušiuota į dvi grupes per +-100000 sekundžių.

***Testavimo parametrai:***
  Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz   1.99 GHz;
  8,00 GB (naudotina: 7,88 GB);
  SSD 240GB.
  
  
