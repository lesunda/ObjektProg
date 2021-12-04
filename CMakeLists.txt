cmake_minimum_required(VERSION "3.12.1")

project(TESTINIS2)

add_executable(TESTINIS2 TESTINIS2.cpp pagrindinio_failo_nuskaitymas.cpp random_pazymiu_sudarymas.cpp studentas.cpp pagrindinio_failo_nuskaitymas.h random_pazymiu_sudarymas.h studentas.h)

install(TARGETS TESTINIS2 DESTINATION bin)