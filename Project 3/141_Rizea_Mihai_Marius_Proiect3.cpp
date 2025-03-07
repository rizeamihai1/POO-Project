#include <iostream>
#include <string.h>
#include <stdexcept>
#include <vector>
#include <set>
#include <map>
#include <stdexcept>
#include <limits>
using namespace std;
// pentru a evita cazul in care cand citesc un int pun un string:
template <class T>
void read(T &value, istream &in = cin)
{
    in >> value;

    if (in.fail()) // daca citirea a esuat
    {
        in.clear(); // sterg bufferul
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Eroare! Datele introduse nu corespund cu tipul de date cerut.");
    }

    char c;
    if (in.get(c) && c != '\n')
    {
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Eroare! Datele introduse nu corespund cu tipul de date cerut.");
    }
}

template <class T>
class Informatii
{
private:
    T obiect;

public:
    Informatii() = default;
    Informatii(T ob) : obiect(ob) {}
    Informatii(const Informatii<T> &ob) : obiect(ob.obiect) {}

    Informatii &operator=(const Informatii<T> &ob)
    {
        if (this != &ob)
        {
            this->obiect = ob.obiect;
        }
        return *this;
    }

    friend istream &operator>>(istream &in, Informatii<T> &ob)
    {
        in >> ob.obiect;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Informatii<T> &ob)
    {
        out << ob.obiect;
        return out;
    }

    ~Informatii() = default;
};

// clasa 1 - compunere pt clasa parinte
class valoriNutritionale
{
private:
    string nume;
    int kcalorii;

public:
    valoriNutritionale();                            // constructor fara parametrii
    valoriNutritionale(string nume, int kcalorii);   // constructor cu toti parametrii
    valoriNutritionale(const valoriNutritionale &v); // copy-constructor
    valoriNutritionale &operator=(const valoriNutritionale &v)
    {
        // op =
        if (this != &v)
        {
            this->nume = v.nume;
            this->kcalorii = v.kcalorii;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const valoriNutritionale &v)
    {
        out << "Nume nutrient: " << v.nume << " "
            << "Caloriile acestuia: " << v.kcalorii;
        return out;
    }
    friend istream &operator>>(istream &in, valoriNutritionale &v)
    {
        cout << "Nume: ";
        in >> v.nume;
        cout << "Numar kcalorii: ";
        in >> v.kcalorii;
        return in;
    }
    // getteri:
    string getNume() const { return this->nume; }
    int getNrKcalorii() const { return this->kcalorii; }
    ~valoriNutritionale() = default;
};
valoriNutritionale::valoriNutritionale()
{
    nume = "nimic";
    kcalorii = 0;
}
valoriNutritionale::valoriNutritionale(string nume, int kcalorii)
{
    this->nume = nume;
    this->kcalorii = kcalorii;
}
valoriNutritionale::valoriNutritionale(const valoriNutritionale &v)
{
    this->nume = v.nume;
    this->kcalorii = v.kcalorii;
}
// clasa 2 - parinte
class Produse
{
protected:
    const int id_Produs;
    static int idContor_Produse;
    string numeProdus;
    float gramaj;
    double pret;
    vector<valoriNutritionale> nutrienti;

public:
    // Constructorul fara parametrii:
    Produse();
    // Constructorul cu parametrii:
    Produse(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti);
    // Copy constructor:
    Produse(const Produse &obiect);
    // Operatorul =:
    Produse &operator=(const Produse &obiect)
    {
        // copy-constructor:
        if (this != &obiect)
        {
            this->numeProdus = obiect.numeProdus;
            this->gramaj = obiect.gramaj;
            this->pret = obiect.pret;
            this->nutrienti = obiect.nutrienti;
        }
        // prin *this - returnez valoarea
        return *this;
    }
    // Operatorul >> (citirea):
    friend istream &operator>>(istream &in, Produse &p);
    // Operatorul << (afisare) :
    friend ostream &operator<<(ostream &out, const Produse &p);
    // citirea:
    virtual istream &citire(istream &in)
    {
        cout << "Numele produsului este: ";
        int ceva = 1;
        while (ceva)
        {
            try
            {
                getline(in, this->numeProdus);
                if (this->numeProdus == "")
                {
                    throw runtime_error("Numele nu poate fii vid");
                }
                ceva = 0;
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
                cout << "Introduceti alt nume: ";
            }
        }
        cout << "Gramajul produsului: ";
        ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->gramaj, in);
                ceva = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
        }

        cout << "Pretul produsului: ";
        ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->pret, in);
                ceva = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
        }
        cout << "Valorile nutritionale: " << endl;
        int comanda;
        int k = 1;
        /*while (k == 1)
        {
            cout << "Apasa 1 daca vrei sa adaugi o valoare nutritionala pentru "
                    "produs\n";
            cout << "Apasa 2 daca nu vrei sa adaugi o valoare nutritionala pentru "
                    "produs\n";
            cout << "Input: ";
            in >> comanda;
            if (comanda == 1)
            {
                valoriNutritionale nutrient;
                in >> nutrient;
                this->nutrienti.push_back(nutrient);
            }
            else
            {
                k = 0;
            }
        }*/
        while (k == 1)
        {
            cout << "Apasa 1 daca vrei sa adaugi o valoare nutritionala pentru "
                    "produs\n";
            cout << "Apasa 2 daca nu vrei sa adaugi o valoare nutritionala pentru "
                    "produs\n";
            ceva = 1;
            while (ceva)
            {
                try
                {
                    read(comanda, in);
                    if (comanda == 1)
                    {
                        valoriNutritionale nutrient;
                        in >> nutrient;
                        this->nutrienti.push_back(nutrient);
                        ceva = 0;
                    }
                    else
                    {
                        if (comanda == 2)
                        {
                            k = 0;
                            ceva = 0;
                        }
                        else
                            throw invalid_argument("Input invalid! Te rog sa introduci 1 sau 2.");
                    }
                }
                catch (const runtime_error &e)
                {
                    cout << e.what() << endl;
                }

                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
        }
        return in;
    }
    ostream &afisare(ostream &out) const
    {
        // const este pun ca sa nu-l pot modifica pe this
        out << "----ID-ul produsului este: " << this->id_Produs << endl;
        out << "----Numele produsului este: " << this->numeProdus << endl;
        out << "----Gramajul produsului: " << this->gramaj << endl;
        out << "----Pretul produsului: " << this->pret << endl;
        out << "----Valorile nutritionale: " << endl;
        for (int i = 0; i < this->nutrienti.size(); i++)
        {
            out << this->nutrienti[i] << endl;
        }
        return out;
    }
    // Operatorul ==:
    bool operator==(const Produse &p);
    // Operatorul <=
    bool operator<=(const Produse &p);
    // Getteri:
    string getNumeProdus() { return numeProdus; }
    float getGramaj() { return gramaj; }
    double getPret() { return pret; }
    const int getID() { return this->id_Produs; }
    // Setteri:
    void setNumeProdus(string numeProdus) { this->numeProdus = numeProdus; }
    void setGramaj(float gramaj) { this->gramaj = gramaj; }
    void setPret(double pret) { this->pret = pret; }

    // Destructor:
    ~Produse() = default;
};
int Produse::idContor_Produse = 1;

Produse::Produse() : id_Produs(idContor_Produse++)
{
    numeProdus = "Anonim";
    gramaj = 0;
    pret = 0;
    nutrienti = {};
}
Produse::Produse(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti) : id_Produs(idContor_Produse++)
{ // argumentele pentru constructor;
    this->numeProdus = numeProdus;
    this->gramaj = gramaj;
    this->pret = pret;
    this->nutrienti = nutrienti;
}
Produse::Produse(const Produse &obiect) : id_Produs(idContor_Produse++)
{
    // const ca sa nu pot edita prin this(obiectul returnat de functie) obiectul
    // primit ca parametru; aproape ca si constructorul cu parametrii, dar pun
    // obiect.(parametri)
    this->numeProdus = obiect.numeProdus;
    this->gramaj = obiect.gramaj;
    this->pret = obiect.pret;
    this->nutrienti = obiect.nutrienti;
}
bool Produse::operator==(const Produse &p)
{
    // Consideram ca 2 produse sunt egale daca au acelasi nume, gramaj, si pret:
    if (this->numeProdus != p.numeProdus)
        return 0;
    if (this->gramaj != p.gramaj)
        return 0;
    if (this->pret != p.pret)
        return 0;
    return 1;
}
bool Produse::operator<=(const Produse &p)
{
    // consideram ca this < p daca:
    // lexicografic numele lui this < p
    // (in caz de egalitate): raportul dintre pret/gramaj este <= decat cel de
    // la p:
    if (this->numeProdus > p.numeProdus)
        return 0;
    if ((this->pret / this->gramaj) > (p.pret / p.gramaj))
        return 0;
    return 1;
}
// Citirea (pentru clasa Produse):
istream &operator>>(istream &in, Produse &p)
{
    return p.citire(in);
}
// Afisarea (pentru clasa Produse):
ostream &operator<<(ostream &out, const Produse &p) { return p.afisare(out); }

// clasa 3 - copil
class ProduseDeSlabit : public Produse
{
protected:
    float nivelArdereGrasimi;
    int nrFibre;

public:
    ProduseDeSlabit();
    ProduseDeSlabit(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float nivelArdereGrasimi, int nrFibre);
    ProduseDeSlabit(const ProduseDeSlabit &p);
    bool operator<=(const ProduseDeSlabit &p);
    bool operator==(const ProduseDeSlabit &p);
    ProduseDeSlabit &operator=(const ProduseDeSlabit &p)
    {
        if (this != &p)
        {
            Produse::operator=(p);
            this->nivelArdereGrasimi = p.nivelArdereGrasimi;
            this->nrFibre = p.nrFibre;
        }
        return *this;
    }
    istream &citire(istream &in)
    {
        this->Produse::citire(in);
        cout << "Nivelul de ardere al grasimilor (numar intre 0-1) este: ";
        /*int sem = 0;
        int ceva = 1;
        while (sem == 0)
        {

            in >> this->nivelArdereGrasimi;
            if (0 <= this->nivelArdereGrasimi && this->nivelArdereGrasimi < 1)
            {
                sem = 1;
                break;
            }
            else
                cout << "Numarul nu este subunitar pozitiv, dati alt input: ";
        }*/
        int ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->nivelArdereGrasimi, in);
                if (0 <= this->nivelArdereGrasimi && this->nivelArdereGrasimi < 1)
                    ceva = 0;
                else
                    throw invalid_argument("Numarul furnizat nu este subunitar!");
            }
            catch (runtime_error &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
            catch (invalid_argument &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
        }

        cout << "Numarul de fibre este: ";
        ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->nrFibre, in);
                ceva = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
        }
        return in;
    }
    ostream &afisare(ostream &out) const
    {
        this->Produse::afisare(out);
        out << "Nivelul de ardere al grasimilor este: " << this->nivelArdereGrasimi << endl;
        out << "Numarul de fibre este: " << this->nrFibre << endl;
        return out;
    }

    float getNivelArdereGrasimi() const { return this->nivelArdereGrasimi; }
    int getNrFibre() const { return this->nrFibre; }
    const int getID()
    {
        const int id = this->Produse::getID();
        return id;
    }
    // metoda constanta - calculeaza un raport dintre nivelArdereGrasimi*100 +
    // nrFibre impartit la pretul produsului;
    // metoda constanta:
    float indiceProdus() const;
    ~ProduseDeSlabit() = default;
};

ProduseDeSlabit::ProduseDeSlabit() : Produse()
{
    nivelArdereGrasimi = 0;
    nrFibre = 0;
}
ProduseDeSlabit::ProduseDeSlabit(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float nivelArdereGrasimi, int nrFibre) : Produse(numeProdus, gramaj, pret, nutrienti)
{
    this->nivelArdereGrasimi = nivelArdereGrasimi;
    this->nrFibre = nrFibre;
}
ProduseDeSlabit::ProduseDeSlabit(const ProduseDeSlabit &p) : Produse(p)
{
    this->nivelArdereGrasimi = p.nivelArdereGrasimi;
    this->nrFibre = p.nrFibre;
}
float ProduseDeSlabit::indiceProdus() const
{
    int s = this->nivelArdereGrasimi * 100 + this->nrFibre;
    int pret = this->pret;
    return s / pret;
}
bool ProduseDeSlabit::operator<=(const ProduseDeSlabit &p)
{
    bool rezultat = Produse::operator<=(p);
    if (rezultat == 0)
        return 0;
    if (this->nivelArdereGrasimi > p.nivelArdereGrasimi)
        return 0;
    if (this->nrFibre > p.nrFibre)
        return 0;
    return 1;
}
bool ProduseDeSlabit::operator==(const ProduseDeSlabit &p)
{
    bool egalitate = Produse::operator==(p);
    if (egalitate == 0)
        return 0;
    if (this->nivelArdereGrasimi != p.nivelArdereGrasimi)
        return 0;
    if (this->nrFibre != p.nrFibre)
        return 0;
    return 1;
}
istream &operator>>(istream &in, ProduseDeSlabit &p)
{
    return p.citire(in);
}
ostream &operator<<(ostream &out, const ProduseDeSlabit &p) { return p.afisare(out); }

// clasa 4 - nepot
class Shake : public ProduseDeSlabit
{
private:
    int cantitateAminoAcizi;
    string sursaProteine;
    float concentratie;

public:
    Shake();
    Shake(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float nivelArdereGrasimi, int nrFibre, float cantitateAminoAcizi, int sursaProteine, float concentratie);
    Shake(const Shake &p);
    bool operator<=(const Shake &p);
    bool operator==(const Shake &p);
    const int getID()
    {
        const int id = this->Produse::getID();
        return id;
    }
    Shake &operator=(const Shake &p)
    {
        if (this != &p)
        {
            ProduseDeSlabit::operator=(p);
            this->cantitateAminoAcizi = p.cantitateAminoAcizi;
            this->sursaProteine = p.sursaProteine;
            this->concentratie = p.concentratie;
        }
        return *this;
    }
    istream &citire(istream &in)
    {
        this->ProduseDeSlabit::citire(in);
        cout << "Cantitate de amino acizi este: ";
        int ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->cantitateAminoAcizi, in);
                ceva = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
                cout << "Reintroduceti datele: ";
            }
        }
        cout << "Sursa proteinei este: ";
        getline(in, this->sursaProteine);
        cout << "Concentratia este: ";
        ceva = 1;
        while (ceva)
        {
            try
            {
                read(this->concentratie, in);
                ceva = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
                cout << "Reintroduceti datele: ";
            }
        }
        return in;
    }
    ostream &afisare(ostream &out) const
    {
        this->ProduseDeSlabit::afisare(out);
        out << "Cantitate de amino acizi este: " << this->cantitateAminoAcizi << endl;
        out << "Sursa proteinei este: " << this->sursaProteine << endl;
        out << "Concentratia este: " << this->concentratie << endl;
        return out;
    }
    float indiceProdus() const;
    ~Shake() = default;
};

Shake::Shake() : ProduseDeSlabit()
{
    concentratie = 0;
};
Shake::Shake(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float nivelArdereGrasimi, int nrFibre, float cantitateAminoAcizi, int sursaProteine, float concentratie) : ProduseDeSlabit(numeProdus, gramaj, pret, nutrienti, nivelArdereGrasimi, nrFibre)
{
    this->concentratie = concentratie;
};
Shake::Shake(const Shake &p) : ProduseDeSlabit(p)
{
    this->concentratie = p.concentratie;
}
float Shake::indiceProdus() const
{
    float suma = this->cantitateAminoAcizi * 2 + this->nrFibre + this->nivelArdereGrasimi * 100;
    float pret = this->pret;
    return suma / pret;
}

bool Shake::operator==(const Shake &p)
{
    bool egalitate = ProduseDeSlabit::operator==(p);
    if (egalitate == 0)
        return 0;
    if (this->sursaProteine != p.sursaProteine)
        return 0;
    if (this->cantitateAminoAcizi != p.cantitateAminoAcizi)
        return 0;
    if (this->concentratie != p.concentratie)
        return 0;
    return 1;
}
istream &operator>>(istream &in, Shake &p)
{
    return p.citire(in);
}
ostream &operator<<(ostream &out, const Shake &p) { return p.afisare(out); }

class meniu // clasa singleton
{
private:
    static meniu *m;

    meniu() {}                                 // constructor privat
    meniu(const meniu &m) = delete;            // stergem constructorul de copiere
    meniu &operator=(const meniu &m) = delete; // stergem operatorul =
public:
    static meniu *getMeniu(); // returneaza meniul
    void runMeniu();          // ruleaza meniul
    void deleteMeniu();       // dezaloca memoria atribuita meniului
};

meniu *meniu::getMeniu()
{
    if (m != NULL)
        return m;
    else
        m = new meniu(); // daca nu exista deja un obiect, il creeaza
    return m;
}

void meniu::runMeniu()
{
    vector<Produse *> produse;
    map<string, Produse *> mapa;
    set<int> preturi;
    int k = 1;
    int comanda;

    while (k == 1) // meniu interactiv
    {
        cout << "-------------------------------------------------------------------------------------------------------\n";
        cout << "| Apasa 1 pentru a adauga un produs                                                                   |\n";
        cout << "| Apasa 2 pentru a adauga un produs de slabit                                                         |\n";
        cout << "| Apasa 3 pentru a adauga un Shake                                                                    |\n";
        cout << "| Apasa 4 pentru a afisa produsele                                                                    |\n";
        cout << "| Apasa 5 pentru a sterge un produs                                                                   |\n";
        cout << "| Apasa 6 pentru a afisa cel mai mic si cel mai mare pret (set)                                       |\n";
        cout << "| Apasa 7 pentru a afisa daca exista un produs dupa un anumit nume (map)                              |\n";
        cout << "| Apasa 8 pentru a inchide                                                                            |\n";
        cout << "-------------------------------------------------------------------------------------------------------\n";

        int kk = 1;
        while (kk)
        {
            try
            {
                read(comanda);
                kk = 0;
            }
            catch (runtime_error &e)
            {
                cout << e.what();
                cout << "\nReintroduceti date: ";
            }
        }
        switch (comanda)
        {
        case 1:
        {
            Produse *p = new Produse;
            cin >> *p;
            // cout << typeid(*p).name() << endl;
            produse.push_back(p);
            // set:
            preturi.insert(p->getPret());
            // map:
            string nume = p->getNumeProdus();
            mapa.insert(make_pair(nume, p));
            break;
        }
        case 2:
        {
            ProduseDeSlabit *p = new ProduseDeSlabit;
            cin >> *p;
            // cout << typeid(*p).name() << endl;
            produse.push_back(p);
            // set:
            preturi.insert(p->getPret());
            // map:
            string nume = p->getNumeProdus();
            mapa.insert(make_pair(nume, p));
            break;
        }
        case 3:
        {
            Shake *p = new Shake;
            cin >> *p;
            // cout << typeid(*p).name() << endl;
            produse.push_back(p);
            // set:
            preturi.insert(p->getPret());
            // map:
            string nume = p->getNumeProdus();
            mapa.insert(make_pair(nume, p));
            break;
        }
        case 4:
        {
            for (int i = 0; i < produse.size(); i++)
            {
                if (dynamic_cast<Shake *>(produse[i]))
                {
                    cout << "prod de slabit:\n";
                    cout << *dynamic_cast<Shake *>(produse[i]);
                }
                else
                {
                    if (dynamic_cast<ProduseDeSlabit *>(produse[i]))
                    {
                        cout << "shake:\n";
                        cout << *dynamic_cast<ProduseDeSlabit *>(produse[i]);
                    }
                    else
                    {
                        cout << *produse[i];
                    }
                }
                cout << endl;
            }
            break;
        }
        case 5:
        {
            // AICI TREBUIE TRATATA EXCEPTIA OUT OF INDEX
            cout << "Dati pozitia produsului pe care doriti sa-l stergeti: ";
            int pozitie;
            int ceva = 1;
            while(ceva)
            try {
                cin >> pozitie;
                pozitie -= 1;
                if (0 <= pozitie && pozitie < produse.size()) {
                    produse.erase(produse.begin() + pozitie);
                    ceva = 0;
                    cout << "Stergerea s-a realizat corect!";
                } else
                    throw out_of_range("Eroare! Pozitie gresita");
            }
            catch(const out_of_range &e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 6:
        {
            // int primulElement = *(mySet.begin())
            int minim = *(preturi.begin());
            int maxim = *(preturi.begin());
            for (auto elem = preturi.begin(); elem != preturi.end(); ++elem)
            {
                if (*elem < minim)
                    minim = *elem;
                if (*elem > maxim)
                    maxim = *elem;
            }
            cout << "Pretul cel mai mic al unui produs este: " << minim << " si cel mai mare este: " << maxim << endl;
            break;
        }
        case 7:
        {
            string nume;
            cout << "Introduceti numele produsului cautat: ";
            cin >> nume;
            // in map, first e key ul adica numele
            // second este elementul cu totul
            int semafor = 0;
            for (auto element = mapa.begin(); element != mapa.end(); ++element)
            {
                if (nume == element->first)
                {
                    semafor = 1;
                    cout << *element->second << endl;
                }
            }
            if (semafor == 0)
            {
                cout << "Nu exista produse cu numele " << nume << endl;
            }
            break;
        }

        case 8:
        {
            k = 0;
            break;
        }
        }
    }
}
void meniu::deleteMeniu()
{
    if (m != NULL)
        delete m;
}

meniu *meniu::m = NULL;
// Metodele template:
// primeste un vector de orice tip (si cum am deja suprascris operatorul <= in fiecare clasa) se pot realiza comparatii -> sortarile
template <class T>
void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] <= a[j - 1])
                swap(a[j], a[j - 1]);
}
// functie de a gasii maximul (folosindu-ma de operatorul <=)
template <class T>
T maxim(T a[], int n)
{
    T maxim = a[0];
    for (int i = 1; i <= n; i++)
    {
        if (maxim <= a[i])
            maxim = a[i];
    }
    return maxim;
}
int main()
{
    // Pentru clasa template:
    // Informatii <Shake> a;
    // cin >> a;
    // cout << a;
    meniu *menu = menu->getMeniu();
    menu->runMeniu();
    menu->deleteMeniu();
}
