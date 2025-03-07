#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
// clasa 1 - interfata
class IOinterface
{
public:
  virtual istream &citire(istream &in) = 0;
  virtual ostream &afisare(ostream &out) const = 0;
};
// clasa 2 - compunere pt clasa parinte
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
// clasa 3 - parinte
class Produse : public IOinterface
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
    in >> this->numeProdus;
    cout << "Gramajul produsului: ";
    in >> this->gramaj;
    cout << "Pretul produsului: ";
    in >> this->pret;
    cout << "Valorile nutritionale: " << endl;
    int comanda;
    int k = 1;
    while (k == 1)
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
    }
    return in;
  }
  virtual ostream &afisare(ostream &out) const
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

  // Indice calitate produs - metoda constanta
  virtual float indiceProdus() const = 0;
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
// clasa 4 - copil 1
class ProduseDeSlabit : virtual public Produse
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
    int sem = 0;
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
    }

    cout << "Numarul de fibre este: ";
    in >> this->nrFibre;
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

// clasa 5 - copil 2
class ProduseMasaMusculara : virtual public Produse
{
protected:
  int cantitateAminoAcizi;
  string sursaProteine;

public:
  ProduseMasaMusculara();
  ProduseMasaMusculara(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float cantitateAminoAcizi, int sursaProteine);
  ProduseMasaMusculara(const ProduseMasaMusculara &p);
  bool operator<=(const ProduseMasaMusculara &p);
  bool operator==(const ProduseMasaMusculara &p);
  const int getID()
  {
    const int id = this->Produse::getID();
    return id;
  }
  ProduseMasaMusculara &operator=(const ProduseMasaMusculara &p)
  {
    if (this != &p)
    {
      Produse::operator=(p);
      this->cantitateAminoAcizi = p.cantitateAminoAcizi;
      this->sursaProteine = p.sursaProteine;
    }
    return *this;
  }
  istream &citire(istream &in)
  {
    this->Produse::citire(in);
    cout << "Cantitate de amino acizi este: ";
    in >> this->cantitateAminoAcizi;
    cout << "Sursa proteinei este: ";
    in >> this->sursaProteine;
    return in;
  }
  ostream &afisare(ostream &out) const
  {
    this->Produse ::afisare(out);
    out << "Cantitate de amino acizi este: " << this->cantitateAminoAcizi
        << endl;
    out << "Sursa proteinei este: " << this->sursaProteine << endl;
    return out;
  }
  float indiceProdus() const;
  ~ProduseMasaMusculara() = default;
};

ProduseMasaMusculara::ProduseMasaMusculara() : Produse()
{
  cantitateAminoAcizi = 0;
  sursaProteine = "niciuna";
}
ProduseMasaMusculara::ProduseMasaMusculara(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float cantitateAminoAcizi, int sursaProteine) : Produse(numeProdus, gramaj, pret, nutrienti)
{
  this->cantitateAminoAcizi = cantitateAminoAcizi;
  this->sursaProteine = sursaProteine;
}
ProduseMasaMusculara::ProduseMasaMusculara(const ProduseMasaMusculara &p) : Produse(p)
{
  this->cantitateAminoAcizi = p.cantitateAminoAcizi;
  this->sursaProteine = p.sursaProteine;
}
float ProduseMasaMusculara::indiceProdus() const
{
  float s = this->cantitateAminoAcizi * 2;
  float pret = this->pret;
  return s / pret;
}
bool ProduseMasaMusculara::operator<=(const ProduseMasaMusculara &p)
{
  bool rezultat = Produse::operator<=(p);
  if (rezultat == 0)
    return 0;
  if (this->cantitateAminoAcizi > p.cantitateAminoAcizi)
    return 0;
  return 1;
}
bool ProduseMasaMusculara::operator==(const ProduseMasaMusculara &p)
{
  bool egalitate = Produse::operator==(p);
  if (egalitate == 0)
    return 0;
  if (this->cantitateAminoAcizi != p.cantitateAminoAcizi)
    return 0;
  if (this->sursaProteine != p.sursaProteine)
    return 0;
  return 1;
}

// clasa 6 - nepot
class Shake : public ProduseDeSlabit, public ProduseMasaMusculara
{
private:
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
      ProduseMasaMusculara::operator=(p);
      this->nivelArdereGrasimi = p.getNivelArdereGrasimi();
      this->nrFibre = p.getNrFibre();
      this->concentratie = p.concentratie;
    }
    return *this;
  }
  istream &citire(istream &in)
  {
    this->ProduseDeSlabit::citire(in);
    cout << "Cantitate de amino acizi este: ";
    in >> this->cantitateAminoAcizi;
    cout << "Sursa proteinei este: ";
    in >> this->sursaProteine;
    cout << "Concentratia este: ";
    in >> this->concentratie;
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

Shake::Shake() : Produse(), ProduseDeSlabit(), ProduseMasaMusculara()
{
  concentratie = 0;
};
Shake::Shake(string numeProdus, float gramaj, double pret, vector<valoriNutritionale> nutrienti, float nivelArdereGrasimi, int nrFibre, float cantitateAminoAcizi, int sursaProteine, float concentratie) : Produse(numeProdus, gramaj, pret, nutrienti),
                                                                                                                                                                                                            ProduseDeSlabit(numeProdus, gramaj, pret, nutrienti, nivelArdereGrasimi, nrFibre),
                                                                                                                                                                                                            ProduseMasaMusculara(numeProdus, gramaj, pret, nutrienti, cantitateAminoAcizi, sursaProteine)
{
  this->concentratie = concentratie;
};
Shake::Shake(const Shake &p) : Produse(p), ProduseDeSlabit(p), ProduseMasaMusculara(p)
{
  this->concentratie = p.concentratie;
}
float Shake::indiceProdus() const
{
  float suma = this->cantitateAminoAcizi * 2 + this->nrFibre + this->nivelArdereGrasimi * 100;
  float pret = this->pret;
  return suma / pret;
}
bool Shake::operator<=(const Shake &p)
{
  bool rezultat = ProduseMasaMusculara::operator<=(p);
  if (rezultat == 0)
    return 0;
  if (this->nrFibre > p.getNrFibre())
    return 0;
  if (this->nivelArdereGrasimi > p.getNivelArdereGrasimi())
    return 0;
  return 1;
}
bool Shake::operator==(const Shake &p)
{
  bool egalitate = ProduseMasaMusculara::operator==(p);
  if (egalitate == 0)
    return 0;
  if (this->nrFibre != p.getNrFibre())
    return 0;
  if (this->nivelArdereGrasimi != p.getNivelArdereGrasimi())
    return 0;
  if (this->concentratie != p.concentratie)
    return 0;
  return 1;
}

int main()
{
  vector<Produse *> produse;
  int comanda;
  int k = 1;
  while (k == 1)
  {
    cout << "-------------------------------------------------------------------------------------------------------\n";
    cout << "| Apasa 1 pentru a adauga un produs de slabit                                                         |\n";
    cout << "| Apasa 2 pentru a adauga un produs de masa musculara                                                 |\n";
    cout << "| Apasa 3 pentru a citii un produs de tip Shake (combinatie dintre produs de slabit si masa musculara)|\n";
    cout << "| Apasa 4 pentru a afisa produsele                                                                    |\n";
    cout << "| Apasa 5 pentru a sterge un produs                                                                   |\n";
    cout << "| Apasa 6 pentru a afisa lista indicilor produselor                                                   |\n";
    cout << "| Apasa 7 pentru a afisa cel mai bun produs                                                           |\n";
    cout << "| Apasa 8 pentru a inchide                                                                            |\n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    cin >> comanda;

    switch (comanda)
    {
    case 1:
    {
      ProduseDeSlabit *p = new ProduseDeSlabit;
      cin >> *p;
      produse.push_back(p);
      break;
    }
    case 2:
    {
      ProduseMasaMusculara *p = new ProduseMasaMusculara;
      cin >> *p;
      produse.push_back(p);
      break;
    }
    case 3:
    {
      Shake *p = new Shake;
      cin >> *p;
      produse.push_back(p);
      break;
    }
    case 4:
    {
      for (int i = 0; i < produse.size(); i++)
        cout << *produse[i] << endl;

      break;
    }
    case 5:
    {
      cout << "Dati pozitia produsului pe care doriti sa-l stergeti: ";
      int pozitie;
      cin >> pozitie;
      pozitie -= 1;
      if (0 <= pozitie && pozitie < produse.size())
        produse.erase(produse.begin() + pozitie);
      else
        cout << "Pozitie gresita\n";
      break;
    }
    case 6:
    {
      for (int i = 0; i < produse.size(); i++)
      {
        cout << "Produsul " << i+1 << " cu numele " << produse[i]->getNumeProdus() << " are indicele " << produse[i]->indiceProdus() << endl;
      }
      break;
    }
    case 7:
    {
      string numeProdus;
      float maxim = 0;
      int indice = 0;
      for (int i = 0; i < produse.size(); i++)
      {
        float curent = produse[i]->indiceProdus();
        if (curent > maxim)
        {
          maxim = curent;
          numeProdus = produse[i]->getNumeProdus();
          indice = i;
        }
      }
      cout << "Cel mai bun produs este: " << numeProdus << " care are pozitia " << indice + 1 << " cu un indice de: " << maxim << endl;
      break;
    }
    case 8:
    {
      k = 0;
      break;
    }
    }
  }
  return 0;
}
