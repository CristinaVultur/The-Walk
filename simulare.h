#ifndef SIMULARE_H_INCLUDED
#define SIMULARE_H_INCLUDED
#include "robot.h"
#include "map.h"
#include "items.h"
#include <iostream>

class Simulare{
    Map Harta;
    Robot *R;
    bool gasit;
public:
    Simulare();
    bool get_stare(){ return this->gasit;};
    void operator++(int);//inaintarea rundelor
    friend std::ostream &operator<<(std::ostream &,const Simulare &);
    friend void plasare_itemi_speciali(char, Map &);
    friend class Robot;

};
#endif // SIMULARE_H_INCLUDED
