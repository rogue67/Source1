#pragma ones
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person
{
private:
    string namn;
    double betalat_andras; // ligger ute med totalt
    double skyldig;        // skyldig totalt

public:
    Person();
    Person(string n, double b, double s);
    ~Person();
    Person& operator=( const Person& p);
    string haemta_namn();
    double haemta_betalat();
    double haemta_skyldig();
    void skrivUt();
};

/* class PersonLista
{
private:
    int antal_pers;
    Person *pers;

public:
    PersonLista();
    PersonLista(const int &n);
    ~PersonLista();
    PersonLista& operator=( const PersonLista& pl);
    void laggTillEn(Person pny);
    void skrivUtOchFixa();
    double summaSkyldig();
    double summaBetalat();
    bool finnsPerson(const string &namn);
}; */

class Transaktion
{
private:
    string datum;
    string typ;
    string namn;
    double belopp;
    int ant_kompisar;
    string *kompisar;

public:
    Transaktion();
    ~Transaktion();
    Transaktion& operator=( const Transaktion& t);
    string haemta_namn();
    double haemta_belopp();
    int haemta_ant_kompisar();
    bool finnsKompis(const string &namnet);
    void haemta_kompisar(string _kompisar[]);
    bool laesEnTrans(istream &is);
    void skrivEnTrans(ostream &os);
};

class TransaktionsLista
{
private:
    Transaktion *trans;
    int antal_trans;

public:
    TransaktionsLista(const int &n);
    ~TransaktionsLista();
    Transaktion& operator=( const Transaktion& t);
    int antalTrans();
    void laesin(istream &is);
    void skrivut(ostream &os);
    void laggTill(Transaktion &t);
    double totalkostnad();
    double liggerUteMed(const string &namnet);
    double aerSkyldig(const string &namnet);
    //PersonLista FixaPersoner();
};