#include "resekostnad.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_KOMPISAR = 10;
const int MAX_PERSONER = 15;
const int MAX_TRANSAKTIONER = 50;
typedef Person *Person_ptr;
typedef Transaktion *Transaktion_ptr;

int main()
{
    TransaktionsLista tl;
    //PersonLista pl;
    int countTrans = 0;
    string filnamn = "resa.txt";
    ifstream IN;
    ofstream UT;
    IN.open(filnamn);
    // Felkontroll
    if (!IN)
    {
        cout << "Filen " << filnamn << " kunde inte �ppnas!!"
             << endl;
        exit(EXIT_FAILURE);
    }
  
    string slaskStr = "";
    while (getline(IN, slaskStr))
    {
        countTrans++;
    }
    IN.close();
    IN.open(filnamn);
     if (!IN)
    {
        cout << "Filen " << filnamn << " kunde inte �ppnas!!"
             << endl;
        exit(EXIT_FAILURE);
    }
    cout << countTrans << endl;
    tl.laesin(IN);
    tl.skrivut(cout);

    return 0;
}

