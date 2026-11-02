#include "BST.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

BST::BST() : korzen(nullptr) {}

BST::~BST() {
    czysc();
}

void BST::dodaj(int wartosc) {
    korzen = dodajRekurencyjnie(korzen, wartosc);
}

Wezel* BST::dodajRekurencyjnie(Wezel* wezel, int wartosc) {
    if (wezel == nullptr) return new Wezel(wartosc);
    if (wartosc < wezel->wartosc) wezel->lewy = dodajRekurencyjnie(wezel->lewy, wartosc);
    else if (wartosc > wezel->wartosc) wezel->prawy = dodajRekurencyjnie(wezel->prawy, wartosc);
    return wezel;
}

void BST::usun(int wartosc) {
    korzen = usunRekurencyjnie(korzen, wartosc);
}

Wezel* BST::znajdzMinimum(Wezel* wezel) {
    Wezel* akt = wezel;
    while (akt && akt->lewy != nullptr) akt = akt->lewy;
    return akt;
}

Wezel* BST::usunRekurencyjnie(Wezel* wezel, int wartosc) {
    if (wezel == nullptr) return wezel;
    if (wartosc < wezel->wartosc) {
        wezel->lewy = usunRekurencyjnie(wezel->lewy, wartosc);
    } else if (wartosc > wezel->wartosc) {
        wezel->prawy = usunRekurencyjnie(wezel->prawy, wartosc);
    } else {
        if (wezel->lewy == nullptr) {
            Wezel* temp = wezel->prawy;
            delete wezel;
            return temp;
        } else if (wezel->prawy == nullptr) {
            Wezel* temp = wezel->lewy;
            delete wezel;
            return temp;
        }
        Wezel* temp = znajdzMinimum(wezel->prawy);
        wezel->wartosc = temp->wartosc;
        wezel->prawy = usunRekurencyjnie(wezel->prawy, temp->wartosc);
    }
    return wezel;
}

void BST::czysc() {
    czyscRekurencyjnie(korzen);
    korzen = nullptr;
}

void BST::czyscRekurencyjnie(Wezel* wezel) {
    if (wezel != nullptr) {
        czyscRekurencyjnie(wezel->lewy);
        czyscRekurencyjnie(wezel->prawy);
        delete wezel;
    }
}

vector<int> BST::szukajDrogi(int wartosc) {
    vector<int> droga;
    Wezel* akt = korzen;
    while (akt != nullptr) {
        droga.push_back(akt->wartosc);
        if (wartosc == akt->wartosc) return droga;
        if (wartosc < akt->wartosc) akt = akt->lewy;
        else akt = akt->prawy;
    }
    return {}; 
}

void BST::wyswietlGraficznie() {
    cout << "\nStruktura drzewa (obrocona o 90 stopni):\n";
    wyswietlGraficznieRekurencyjnie(korzen, 0);
    cout << "\n";
}

void BST::wyswietlGraficznieRekurencyjnie(Wezel* wezel, int odstep) {
    if (wezel == nullptr) return;
    odstep += 5;
    wyswietlGraficznieRekurencyjnie(wezel->prawy, odstep);
    cout << endl;
    for (int i = 5; i < odstep; i++) cout << " ";
    cout << wezel->wartosc << "\n";
    wyswietlGraficznieRekurencyjnie(wezel->lewy, odstep);
}

void BST::wyswietl(int tryb) {
    vector<int> wynik;
    if (tryb == 1) {
        preorder(korzen, wynik);
        cout << "Preorder: ";
    } else if (tryb == 2) {
        inorder(korzen, wynik);
        cout << "Inorder: ";
    } else if (tryb == 3) {
        postorder(korzen, wynik);
        cout << "Postorder: ";
    }
    for (int v : wynik) cout << v << " ";
    cout << "\n";
}

void BST::preorder(Wezel* wezel, vector<int>& wynik) {
    if (wezel) {
        wynik.push_back(wezel->wartosc);
        preorder(wezel->lewy, wynik);
        preorder(wezel->prawy, wynik);
    }
}

void BST::inorder(Wezel* wezel, vector<int>& wynik) {
    if (wezel) {
        inorder(wezel->lewy, wynik);
        wynik.push_back(wezel->wartosc);
        inorder(wezel->prawy, wynik);
    }
}

void BST::postorder(Wezel* wezel, vector<int>& wynik) {
    if (wezel) {
        postorder(wezel->lewy, wynik);
        postorder(wezel->prawy, wynik);
        wynik.push_back(wezel->wartosc);
    }
}

void BST::zapiszDoTekstowego(const string& nazwaPliku) {
    ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        vector<int> wynik;
        preorder(korzen, wynik); 
        for (int v : wynik) plik << v << " ";
        plik.close();
        cout << "Zapisano drzewo do pliku tekstowego.\n";
    } else {
        cerr << "Blad otwarcia pliku tekstowego do zapisu.\n";
    }
}

vector<int> BST::pobierzWszystkieElementyPreorder() {
    vector<int> wynik;
    preorder(korzen, wynik);
    return wynik;
}