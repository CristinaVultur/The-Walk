#include <iostream>
#include "map.h"

using namespace std;

Map::Map()
{
    m=new char*[15];//matrice alocata dinamic ce reprezinta harta
    for(int i=0;i<15;i++)
        m[i]=new char[15];
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
         m[i][j]='0';
}

ostream & operator<<(ostream &out, const Map &m)//supraincarcam operatorul de afisare
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
            out<<m.m[i][j]<<" ";
        out<<endl;
    }
    return out;
}
