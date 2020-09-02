#include "resekostnad.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_KOMPISAR = 10;
const int MAX_PERSONER = 15;
const int MAX_TRANSAKTIONER = 50;

int main()
{
    string namnIn;
 /*    Person ppl[MAX_PERSONER];
    Person *p; */
    Transaktion t;
    TransaktionsLista *tl;
    ifstream fin("resa.txt");
    t.laesEnTrans(fin);
    cout << t.haemta_namn() << endl;
    cout << t.haemta_ant_kompisar() << endl;
    t.skrivEnTrans(cout);
    cout << endl;
    cout << "Finns kompis? ";
    cin >>  namnIn;
    cout << t.finnsKompis(namnIn) << endl;
    int n = t.haemta_ant_kompisar();
    string *kp = new string[n];
    t.haemta_kompisar(kp);
    for (int j = 0; j < n; j++)
    cout << kp[j] << '\n';
    delete[] kp;
    
    return 0;
}