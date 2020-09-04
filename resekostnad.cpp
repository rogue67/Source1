#include "resekostnad.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Person::Person()
{
    namn = "";
    betalat_andras = 0.0;
    skyldig = 0.0;
}

Person::Person(string n, double b, double s)
    : namn(n), betalat_andras(b), skyldig(s){};

Person::~Person() {}

Person &Person::operator=(const Person &p)
{
    if (this != &p)
    {
        namn = p.namn;
        betalat_andras = p.betalat_andras;
        skyldig = p.skyldig;
    }
    return *this;
}

string Person::haemta_namn()
{
    return namn;
}

double Person::haemta_betalat()
{

    return betalat_andras;
}

double Person::haemta_skyldig()
{
    return skyldig;
}

void Person::skrivUt()
{
    cout << endl
         << namn << " Ligger ute med : " << betalat_andras << " och är skyldig: " << skyldig;
    double diff = betalat_andras - skyldig;
    if (diff > 0)
        cout << " Skall ha " << diff << " från potten!" << endl;
    else
        cout << " Skall betala " << -diff << " till potten!" << endl;
}

/* PersonLista::PersonLista()
{
    antal_pers = 0;
    pers = nullptr;
}

PersonLista::PersonLista(const int &n)
{
    antal_pers = n;
    pers = new Person[n];
}
PersonLista::~PersonLista()
{
    delete[] pers;
}

PersonLista  &PersonLista::operator=(const PersonLista &pl)
{
    if (this != &pl)
    {
        delete[] pers;
        antal_pers = pl.antal_pers;
        pers = new Person[antal_pers];
        for (int j = 0; j < antal_pers; j++)
            pers[j] = pl.pers[j];
    }
    return *this;
}

void PersonLista::laggTillEn(Person pny)
{
   
    antal_pers++;
}

void PersonLista::skrivUtOchFixa()
{
    int i = 0;
    while (pers[i] != 0)
    {
        pers[i]->skrivUt();
        i++;
    }

    cout << endl
         << "Totalt: utlägg - skulder "
         << " = " << summaBetalat() - summaSkyldig() << endl
         << endl;
}

double PersonLista::summaSkyldig()
{
    double skyldig = 0.0;
    for (int i = 0; i < antal_pers; i++)
        skyldig += pers[i]->haemta_skyldig();
    return skyldig;
}

double PersonLista::summaBetalat()
{
    double betalat = 0.0;
    for (int i = 0; i < antal_pers; i++)
        betalat += pers[i]->haemta_betalat();
    return betalat;
}

bool PersonLista::finnsPerson(const string &namn)
{
    bool hittad = false;
    for (int i = 0; i < antal_pers; i++)
    {
        if (pers[i]->haemta_namn() == namn)
            hittad = true;
    }
    return hittad;
}*/

Transaktion::Transaktion()
{
    datum = "";
    typ = "";
    namn = "";
    belopp = 0.0;
    ant_kompisar = 0;
    kompisar = 0;
} 

Transaktion::~Transaktion()
{
    delete[] kompisar;
}

Transaktion &Transaktion::operator=(const Transaktion &t)
{
    if (this != &t)
    {
        delete[] kompisar;
        datum = t.datum;
        typ = t.typ;
        namn = t.namn;
        belopp = t.belopp;
        ant_kompisar = t.ant_kompisar;
        kompisar = new string[ant_kompisar];
        for (int i = 0; i < ant_kompisar; i++)
            kompisar[i] = t.kompisar[i];
    }
    return *this;
}

string Transaktion::haemta_namn()
{
    return namn;
}

double Transaktion::haemta_belopp()
{
    return belopp;
}

int Transaktion::haemta_ant_kompisar()
{
    return ant_kompisar;
}

bool Transaktion::finnsKompis(const string &namnet)
{
    bool hittat = false;
    for (int k = 0; k < ant_kompisar; k++)
    {
        if (namnet == kompisar[k])
            hittat = true;
    }
    return hittat;
}

void Transaktion::haemta_kompisar(string _kompisar[])
{
    for (int j = 0; j < ant_kompisar; j++)
        _kompisar[j] = kompisar[j];
}

bool Transaktion::laesEnTrans(istream &fin)
{
    bool filslut = fin.eof();
    fin >> datum >> typ >> namn >> belopp >> ant_kompisar;
    kompisar = new string[ant_kompisar];
    for (int k = 0; k < ant_kompisar; k++)
        fin >> kompisar[k];
    return !filslut;
}

void Transaktion::skrivEnTrans(ostream &fout)
{
    fout << datum << '\t' << typ << '\t' << namn << '\t' << belopp << '\t' << ant_kompisar;
    for (int k = 0; k < ant_kompisar; k++)
    {
        fout << '\t' << kompisar[k];
    }
}

TransaktionsLista::TransaktionsLista()
{
    antal_trans = 0;
    trans = nullptr;
}

TransaktionsLista::~TransaktionsLista()
{
    delete[] trans;
}

int TransaktionsLista::antalTrans()
{
    return antal_trans;
}

void TransaktionsLista::laesin(istream &is)
{
    Transaktion t;
    while (t.laesEnTrans(is))
    {
        laggTill(t);
    }
}

void TransaktionsLista::skrivut(ostream &os)
{
    for (int k = 0; k < antal_trans; k++)
    {
        if (k > 0)
            os << endl;
        trans[k].skrivEnTrans(os);
    }
}

void TransaktionsLista::laggTill(Transaktion &t)
{
    trans[antal_trans] = t;
    antal_trans++;
}

double TransaktionsLista::totalkostnad()
{
    double kostnad = 0;
    for (int k = 0; k < antal_trans; k++)
        kostnad += trans[k].haemta_belopp();
    return kostnad;
}

double TransaktionsLista::liggerUteMed(const string &namnet)
{
    double fodran = 0;
    for (int k = 0; k < antal_trans; k++)
    {
        if (trans[k].haemta_namn() == namnet)
        {
            double b = trans[k].haemta_belopp();
            int p = trans[k].haemta_ant_kompisar();
            fodran += b * double(p) / double(p + 1);
        }
    }
    return fodran;
}

double TransaktionsLista::aerSkyldig(const string &namnet)
{
    double skuld = 0;
    for (int i = 0; i < antal_trans; i++)
        if (trans[i].finnsKompis(namnet))
        {
            double b = trans[i].haemta_belopp();
            int k = trans[i].haemta_ant_kompisar();
            skuld += b / double(k + 1);
        }
    return skuld;
}

/* PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista pLista;
    string k[MAX_KOMPISAR];
    for (int i = 0; i < antal_trans; i++)
    {
        bool finns_namn = false;
        string namn = trans[i].haemta_namn();
        finns_namn = pLista.finnsPerson(namn);
        // Kontrollerar om personen som betalade finns registrerad.
        if (!finns_namn)
        {
            double fodran = liggerUteMed(namn);
            double skuld = aerSkyldig(namn);
            Person p(namn, fodran, skuld);
            pLista.laggTillEn(p);
        }
        // Kontrollerar om kompisar finns registrerade.
        int n = trans[i].haemta_ant_kompisar();
        trans[i].haemta_kompisar(k);
        for (int j = 0; j < n; j++)
        {
            finns_namn = pLista.finnsPerson(k[j]);
            if (!finns_namn)
            {
                double fodran = liggerUteMed(k[j]);
                double skuld = aerSkyldig(k[j]);
                Person p(k[j], fodran, skuld);
                pLista.laggTillEn(p);
            }
        }
    }

    return pLista;
} */