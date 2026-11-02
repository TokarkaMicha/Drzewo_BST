#ifndef WEZEL_H
#define WEZEL_H

class Wezel {
public:
    int wartosc;
    Wezel* lewy;
    Wezel* prawy;

    Wezel(int w) : wartosc(w), lewy(nullptr), prawy(nullptr) {}
};

#endif