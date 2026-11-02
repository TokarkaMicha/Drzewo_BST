#ifndef BST_H
#define BST_H

#include "Wezel.h"
#include <vector>
#include <string>

using namespace std;

class BST {
private:
    Wezel* korzen;

    Wezel* dodajRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* usunRekurencyjnie(Wezel* wezel, int wartosc);
    Wezel* znajdzMinimum(Wezel* wezel);
    void czyscRekurencyjnie(Wezel* wezel);
    void wyswietlGraficznieRekurencyjnie(Wezel* wezel, int odstep);
    
    void preorder(Wezel* wezel, vector<int>& wynik);
    void inorder(Wezel* wezel, vector<int>& wynik);
    void postorder(Wezel* wezel, vector<int>& wynik);

public:
    BST();
    ~BST();

    void dodaj(int wartosc);
    void usun(int wartosc);
    void czysc();
    
    vector<int> szukajDrogi(int wartosc);
    void wyswietlGraficznie();
    void wyswietl(int tryb); 
    void zapiszDoTekstowego(const string& nazwaPliku);

    vector<int> pobierzWszystkieElementyPreorder();
};

#endif