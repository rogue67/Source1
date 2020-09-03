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
    TransaktionsLista *tl;
    //PersonLista *pl;

    string filnamn = "resa.txt";
    ifstream fin(filnamn.c_str());
    // Felkontroll
    if (!fin)
    {
        cout << "Filen " << filnamn << " kunde inte �ppnas!!"
             << endl;
        exit(EXIT_FAILURE);
    }
    int count = 0;
    string slaskStr = "";
    while(getline(cin,slaskStr))
    {
        count++;
    }
    /* getline(fin, slaskStr);
    do
    {
        count++;
    } while (getline(fin, slaskStr)); */
    cout << count << endl;
    tl = new TransaktionsLista(count);
    return 0;
}