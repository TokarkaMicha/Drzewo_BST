#ifndef MENEDZERPLIKOW_H
#define MENEDZERPLIKOW_H
//hej
#include "BST.h"
#include <string>

using namespace std;

class MenedzerPlikow {
public:
    static void zapiszBinarne(BST& drzewo, const string& nazwaPliku);
    static void odczytajBinarne(BST& drzewo, const string& nazwaPliku);
    static void wczytajZTekstowego(BST& drzewo, const string& nazwaPliku);
};

#endif