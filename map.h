#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <iostream>
using namespace std;
class Robot;
class Robot_noob;
class Robot_mediu;
class Robot_high;
class Simulare;

class Map{
    char **m;
public:
    Map();
    friend ostream& operator<<(ostream &, const Map &);
    friend class Robot;
    friend class Robot1;
    friend class Robot2;
    friend class Robot3;
    friend class Simulare;
    friend class Items;
    friend class Item_break;
    friend void plasare_itemi_speciali(char c,Map &Harta);

};

#endif // MAP_H_INCLUDED
