#include "MenedzerPlikow.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void MenedzerPlikow::zapiszBinarne(BST& drzewo, const string& nazwaPliku) {
    vector<int> dane = drzewo.pobierzWszystkieElementyPreorder();
    ofstream plik(nazwaPliku, ios::binary);
    if (plik.is_open()) {
        size_t rozmiar = dane.size();
        plik.write(reinterpret_cast<const char*>(&rozmiar), sizeof(rozmiar));
        plik.write(reinterpret_cast<const char*>(dane.data()), rozmiar * sizeof(int));
        plik.close();
        cout << "Zapisano binarne pomyslnie.\n";
    } else {
        cerr << "Blad zapisu binarnego.\n";
    }
}

void MenedzerPlikow::odczytajBinarne(BST& drzewo, const string& nazwaPliku) {
    ifstream plik(nazwaPliku, ios::binary);
    if (plik.is_open()) {
        drzewo.czysc();
        size_t rozmiar;
        plik.read(reinterpret_cast<char*>(&rozmiar), sizeof(rozmiar));
        vector<int> dane(rozmiar);
        plik.read(reinterpret_cast<char*>(dane.data()), rozmiar * sizeof(int));
        for (int wartosc : dane) {
            drzewo.dodaj(wartosc);
        }
        plik.close();
        cout << "Wczytano binarne pomyslnie.\n";
    } else {
        cerr << "Blad odczytu binarnego.\n";
    }
}

void MenedzerPlikow::wczytajZTekstowego(BST& drzewo, const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        int wartosc;
        while (plik >> wartosc) {
            drzewo.dodaj(wartosc);
        }
        plik.close();
        cout << "Wczytano z pliku tekstowego pomyslnie.\n";
    } else {
        cerr << "Blad odczytu pliku tekstowego.\n";
    }
}