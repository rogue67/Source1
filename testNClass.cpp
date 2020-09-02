#include <iostream>
#include <string>

using namespace std;

const int MAX_PERSONER = 15;

class Person
{
private:
    string namn;
    double betalat_andras; // ligger ute med totalt
    double skyldig;        // skyldig totalt

public:
    Person();
    Person(string n, double b, double s);
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
    ~PersonLista();
    void laggTillEn(Person pny);
    void skrivUtOchFixa();
    double summaSkyldig();
    double summaBetalat();
    bool finnsPerson(const string &namn);
};

 */
int main()
{
    Person ppl[MAX_PERSONER];
    Person *p;
    p = new Person("Roger", 200, 100);
    cout << p->haemta_namn() << '\n';
    delete p;
    p = NULL;
    if (p == NULL)
        cout << "Borttagen" << endl;
    else 
        cout << "Ej NULL!" << '\n';

    return 0;
}

Person::Person(){};
Person::Person(string n, double b, double s)
    : namn(n), betalat_andras(b), skyldig(s){};

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
    for (int i = 0; i < MAX_PERSONER; i++)
        pers[i] = 0;
}
PersonLista::~PersonLista(){};

void PersonLista::laggTillEn(Person pny)
{
    pers[antal_pers] = &pny;
    antal_pers++;
}

void PersonLista::skrivUtOchFixa()
{
    int i = 0;
    while (pers[i] != 0)
    {
        *pers[i]->skrivUt();
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
} */