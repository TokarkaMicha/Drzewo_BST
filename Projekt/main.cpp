#include <iostream>
#include "BST.h"
#include "MenedzerPlikow.h"

using namespace std;

void wyswietlMenu() {
    cout << "\n--- Menu Drzewa BST ---\n";
    cout << "1. Dodajesz element\n";
    cout << "2. Usuniesz element\n";
    cout << "3. Usun cale drzewo\n";
    cout << "4. Szukaj drogi do elementu\n";
    cout << "5. Wyswietl drzewo graficznie\n";
    cout << "6. Wyswietl drzewo (1-Preorder, 2-Inorder, 3-Postorder)\n";
    cout << "7. Zapisz drzewo do pliku tekstowego\n";
    cout << "8. Wczytaj liczby z pliku tekstowego\n";
    cout << "9. Zapisz drzewo binarnie\n";
    cout << "10. Wczytaj drzewo binarnie\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    BST drzewo;
    int opcja;

    do {
        wyswietlMenu();
        cin >> opcja;

        switch (opcja) {
            case 1: {
                int wartosc;
                cout << "Podaj wartosc do dodania: ";
                cin >> wartosc;
                drzewo.dodaj(wartosc);
                break;
            }
            case 2: {
                int wartosc;
                cout << "Podaj wartosc do usuniecia: ";
                cin >> wartosc;
                drzewo.usun(wartosc);
                break;
            }
            case 3:
                drzewo.czysc();
                cout << "Drzewo wyczyszczone.\n";
                break;
            case 4: {
                int wartosc;
                cout << "Podaj wartosc do znalezienia: ";
                cin >> wartosc;
                vector<int> droga = drzewo.szukajDrogi(wartosc);
                if (droga.empty() || droga.back() != wartosc) {
                    cout << "Elementu nie znaleziono.\n";
                } else {
                    cout << "Droga: ";
                    for (int w : droga) cout << w << " ";
                    cout << "\n";
                }
                break;
            }
            case 5:
                drzewo.wyswietlGraficznie();
                break;
            case 6: {
                int tryb;
                cout << "Podaj tryb (1-Preorder, 2-Inorder, 3-Postorder): ";
                cin >> tryb;
                if(tryb >= 1 && tryb <= 3) drzewo.wyswietl(tryb);
                else cout << "Nieznany tryb.\n";
                break;
            }
            case 7:
                drzewo.zapiszDoTekstowego("drzewo.txt");
                break;
            case 8:
                MenedzerPlikow::wczytajZTekstowego(drzewo, "dane.txt");
                break;
            case 9:
                MenedzerPlikow::zapiszBinarne(drzewo, "drzewo.bin");
                break;
            case 10:
                MenedzerPlikow::odczytajBinarne(drzewo, "drzewo.bin");
                break;
            case 0:
                cout << "Zamykanie programu...\n";
                break;
            default:
                cout << "Nieprawidlowa opcja!\n";
        }
    } while (opcja != 0);

    return 0;
}