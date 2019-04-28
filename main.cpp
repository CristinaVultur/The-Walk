#include <iostream>
#include "map.h"
#include "robot.h"
#include "simulare.h"
#include "items.h"

using namespace std;

int main()
{
    Simulare Game;
    //cout<<Game;
    int Stop=0;
    while(Stop==0&&(Game.get_stare())==false)//cat timp continuam jocul si nu am gasit comoara
    {
        int Answer;
        cout<<"\nContinue Game?";
        cout<<endl;
        cin>>Answer;//cat timp vrem sa continuam jocul se simuleaza rundele
        switch(Answer)
        {
            case 1:{Game++;break;}
            case 0:{Stop=1; cout<<Game; break;}//cand vrem sa oprim afisam ce s-a schimbar pe harta
        }
    }
    if(Game.get_stare()==true) cout<<"Comoara Gasita!";

    return 0;
}
