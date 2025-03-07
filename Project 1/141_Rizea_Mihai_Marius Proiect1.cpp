#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Aparate {
    private:
        const int id_Aparate;
        static int idContor_Aparate;
        char *numeAparat;
        float masaMaxima;
        bool disponibil; // true - nu lucreaza nimeni || false - e ocupat
        char *grupaMusculara; // grupa musculara pe care o lucreaza;
        int luniRevizie; // cate luni mai sunt pana la urmatoarea revizie;
    public:
        //constructor (fara parametrii):
        Aparate():id_Aparate(idContor_Aparate++){
            numeAparat = new char[strlen("default")+1];
            strcpy(numeAparat, "default");
            masaMaxima = 0;
            disponibil = true;
            grupaMusculara = new char[strlen("none")+1];
            strcpy(grupaMusculara,"none");
            luniRevizie = 0;
        }
        //constructor (cu toti parametrii):
        Aparate(char * numeAparat, float masaMaxima, bool disponibil, char* grupaMusculara, int luniRevizie):id_Aparate(idContor_Aparate++) {
            this -> numeAparat = new char[strlen(numeAparat)+1];
            strcpy(this -> numeAparat, numeAparat);
            this -> masaMaxima = masaMaxima;
            this -> disponibil = disponibil;
            this -> grupaMusculara = new char[strlen(grupaMusculara)+1];
            strcpy(this -> grupaMusculara, grupaMusculara);
            this -> luniRevizie = luniRevizie;
        }
        // 2 constructori cu parametrii:
        // primul contine numele aparatului si masa:
        Aparate(char *numeAparat, float masaMaxima):id_Aparate(idContor_Aparate) {
            this -> numeAparat = new char[strlen(numeAparat)+1];
            strcpy(this -> numeAparat, numeAparat);
            this -> masaMaxima = masaMaxima;
            disponibil = true;
            grupaMusculara = new char[strlen("none")+1];
            strcpy(grupaMusculara,"none");
            luniRevizie = 0;
        }
        // al doilea contine daca este disponibil si grupaMusculara
        Aparate(bool disponibil, char* grupaMusculara):id_Aparate(idContor_Aparate) {
            numeAparat = new char[strlen("default")+1];
            strcpy(numeAparat, "default");
            masaMaxima = 0;
            this -> disponibil = disponibil;
            this -> grupaMusculara = new char[strlen(grupaMusculara)+1];
            strcpy(this -> grupaMusculara, grupaMusculara);
            luniRevizie = 0;
        }
        // getteri:
        const char* getNumeAparat() {
            return this -> numeAparat;
        }
        float getMasaMaxima() {
            return this -> masaMaxima;
        }
        bool getDisponibil() {
            return this->disponibil;
        }
        const char* getGrupaMusculara() {
            return this->grupaMusculara;
        }
        int getLuniRevizie() {
            return this->luniRevizie;
        }

        // setteri:
        void setNumeAparat(char *numeAparat) {
            if(this -> numeAparat != NULL)
                delete []this->numeAparat;
            this -> numeAparat = new char[strlen(numeAparat)+1];
            strcpy(this -> numeAparat, numeAparat);
        }
        void setMasaMaxima(float masaMaxima) {
            this -> masaMaxima = masaMaxima;
        }
        void setDisponibil(bool disponibil) {
            this -> disponibil = disponibil;
        }
        void setGrupaMusculara(char *grupaMusculara) {
            if(this -> grupaMusculara != NULL)
                delete []this -> grupaMusculara;
            this -> grupaMusculara = new char[strlen(grupaMusculara)+1];
            strcpy(this->grupaMusculara, grupaMusculara);
        }
        void setLuniRevizie(int luniRevizie) {
            this -> luniRevizie = luniRevizie;
        }

        // operatorul >>
        friend istream &operator>>(istream &in, Aparate &a);

        // operatorul <<
        friend ostream &operator<<(ostream &out, const Aparate &a);

        //copy-constrcutor:
        Aparate(const Aparate &a):id_Aparate(idContor_Aparate++) {
            this -> numeAparat = new char[strlen(a.numeAparat)+1];
            strcpy(this -> numeAparat, a.numeAparat);
            this -> masaMaxima = a.masaMaxima;
            this -> disponibil = a.disponibil;
            this -> grupaMusculara = new char[strlen(a.grupaMusculara)+1];
            strcpy(this->grupaMusculara, a.grupaMusculara);
            this -> luniRevizie = a.luniRevizie;
        }
        // operatorul =
        Aparate &operator= (const Aparate &a) {
            if(this != &a) {
                if( this -> numeAparat != NULL) {
                    delete [] this -> numeAparat;
                }
                if( this -> grupaMusculara != NULL) {
                    delete []this->grupaMusculara;
                }
                strcpy(this -> numeAparat, a.numeAparat);
                this -> masaMaxima = a.masaMaxima;
                this -> disponibil = a.disponibil;
                this -> grupaMusculara = new char[strlen(a.grupaMusculara)+1];
                strcpy(this->grupaMusculara,a.grupaMusculara);
                this -> luniRevizie = a.luniRevizie;
            }
            return *this;
        }
        // operatorul ==
        bool operator==(const Aparate &a) {
            // consider ca 2 aparate sunt egale daca:
            // au ac masa
            // sunt de aceeasi grupa musculara
            // ac timp pana la revizie
            if(this -> masaMaxima != a.masaMaxima)
                return 0;
            if(strcmp(this -> grupaMusculara, a.grupaMusculara)!=0)
                return 0;
            if(this -> luniRevizie != a.luniRevizie)
                return 0;
            return 1;
        }
        // operatorul <=
        bool operator<=(const Aparate &a) {
            // consider ca this <= aparatul a daca:
            // masa maxima este mai mica
            // lexicografic this < a (la grupaMusculara)
            // lunile pana la revizie de la this sunt mai putine decat la a
            if(this -> masaMaxima > a.masaMaxima)
                return 0;
            if(strcmp(this -> grupaMusculara,a.grupaMusculara) > 0)
                return 0;
            if(this -> luniRevizie > a.luniRevizie)
                return 0;
            return 1;
        }
        // operatorul ++ (pre)
        Aparate &operator++() {
            // consider ++a in urm fel:
            // cresc masaMaxima cu 10kg
            // il fac disponibil
            // pun inca 12 luni pana la revizie
            // pun la numele aparatului (la final) 'PLUS'
            char aux[100];
            strcpy(aux, this -> numeAparat);
            if(this -> numeAparat != NULL)
                delete []this -> numeAparat;
            strcat(aux, "PLUS");
            this -> numeAparat = new char[strlen(aux)+1];
            strcpy(this -> numeAparat, aux);
            this -> disponibil = true;
            this -> luniRevizie += 12;
            this -> masaMaxima += 10;
            return *this;
        }
        // operatorul ++ (post)
        Aparate operator++(int) {
            Aparate aux = *this;
            ++(*this);
            return aux;
        }
        // operatorul +
        Aparate operator+(Aparate a) {
            // adunarea in urm fel:
            // this -> nume + " " + a.nume
            // daca unul din ele nu e disponibil - niciunul nu va fii disponibil
            // adun greutate maxima si lunile
            if (this -> disponibil == 0 or a.disponibil == 0)
                a.disponibil = 0;
            a.masaMaxima += this -> masaMaxima;
            a.luniRevizie += this -> luniRevizie;
            char aux[200];
            strcpy(aux, this -> numeAparat);
            strcat(aux, " ");
            strcat(aux, a.numeAparat);
            if(a.numeAparat != NULL)
                delete []a.numeAparat;
            a.numeAparat = new char[strlen(aux)+1];
            strcpy(a.numeAparat, aux);
            return a;
        }
        // operatorul -
        Aparate operator-(Aparate a) {
            // scaderea in urm fel:
            // this -> nume + "FARA" + a.nume
            // daca unul din ele e disponibil - rezultatul va fii disponibil
            // scad greutate maxima si lunile
            if (this -> disponibil == 1 or a.disponibil == 1)
                a.disponibil = 1;
            a.masaMaxima -= this -> masaMaxima;
            a.luniRevizie -= this -> luniRevizie;
            char aux[200];
            strcpy(aux, this -> numeAparat);
            strcat(aux, " FARA ");
            strcat(aux, a.numeAparat);
            if(a.numeAparat != NULL)
                delete []a.numeAparat;
            a.numeAparat = new char[strlen(aux)+1];
            strcpy(a.numeAparat, aux);
            return a;
        }
        // operatorul []:
        char operator[](int index) {
            if(index >= 0 && index < strlen(this -> numeAparat))
                return this -> numeAparat[index]; // a index-a litere din numeAparat
            throw runtime_error("Index invalid in Aparate.");
        }
        // operatorul cast:
        operator bool() {
            return this -> disponibil;
        }
        /*
        // operatorul + (pentru 2 clase - scris de 2 ori pt comutativitate):
        friend Clienti operator+(Clienti client, Aparate aparat);
        friend Clienti operator+(Aparate aparat, Clienti client);
        */
        // destructor:
        ~Aparate() {
            if( this -> numeAparat != NULL)
                delete [] this -> numeAparat;
            if(this -> grupaMusculara != NULL)
                delete []this -> grupaMusculara;
        }
};
// Citirea (pentru clasa Aparate):
int Aparate::idContor_Aparate= 1;
istream &operator>>(istream &in, Aparate &a) {
    cout << endl;
    cout << "Nume Aparat: ";
    char aux[100]; // ne folosim de variabila aux pt a obtine continutul, lungimea si pt a nu avea acces direct
    in.get();
    in.getline(aux,100);
    a.numeAparat = new char[strlen(aux)+1]; // aici ne folosim de lungime, declarand un *char de lungimea lui aux
    strcpy(a.numeAparat, aux); // aici ne folosim de continutul din aux;

    cout << "Masa maxima: "; in >> a.masaMaxima;
    cout << "Este aparatul disponibil? (1/0): "; in >> a.disponibil; // 1 - da; 0 - nu
    cout << "Grupa musculara: ";
    in.get();
    in.getline(aux,100);
    a.grupaMusculara = new char[strlen(aux)+1];
    strcpy(a.grupaMusculara,aux);
    cout << "Cate luni mai sunt pana la urmatoarea revizie?: ";
    in >> a.luniRevizie;
    cout << endl;
    return in;
}
// Afisarea (pentru clasa Aparate):
ostream &operator<<(ostream &out, const Aparate &a) {
    out << endl;
    out << "Aparatul are ID-ul: " << a.id_Aparate << endl;
    out << "Nume aparat: " << a.numeAparat << endl;
    out << "Masa maxima: " << a.masaMaxima << endl;
    if(a.disponibil == true)
        out << "Aparatul este disponibil" << endl;
    else
        out << "Aparatul nu este disponibil" << endl;
    out << "Grupa musculara lucrata: " << a.grupaMusculara << endl;
    out << "Numarul de luni pana la urm revizie: " << a.luniRevizie << endl;
    out<<endl;
    return out;
}


class Clienti {
    private:
        const int id_Clienti;
        static int idContor_Clienti;
        string categorie; // daca sunt de tip premium sau normali;
        char *nume;
        float kg;
        bool banat; // unui client i se poate restituii accesul la sala.
    public:
        //constructor fara parametrii:
        Clienti():id_Clienti(idContor_Clienti++) {
            categorie = "N";
            nume = new char[strlen("anonim")+1];
            strcpy(nume,"anonim");
            kg = 0;
            banat = false;
        }
        //constructorul cu parametrii:
        Clienti(string categorie, char* nume, float kg, bool banat):id_Clienti(idContor_Clienti++) {
            this -> categorie = categorie;
            this -> nume = new char[strlen(nume)+1];
            strcpy(this -> nume, nume);
            this -> kg = kg;
            this -> banat = banat;
        }
        // cei 2 constructori cu parametrii:
        // primul va avea categoria si numele
        Clienti(string categorie, char* nume):id_Clienti(idContor_Clienti) {
            this -> categorie = categorie;
            this -> nume = new char[strlen(nume)+1];
            strcpy(this -> nume,nume);
            kg = 0;
            banat = false;
        }
        // al doilea va avea kg si banat
        Clienti(float kg, bool banat):id_Clienti(idContor_Clienti) {
            categorie = "N";
            nume = new char[strlen("anonim")+1];
            strcpy(nume,"anonim");
            this -> kg = kg;
            this -> banat = banat;
        }
        // getteri:
        string getCategorie() {
            return this-> categorie;
        }
        const char* getNume() {
            return this->nume;
        }
        float getKg() {
            return this->kg;
        }
        bool getBanat() {
            return this->banat;
        }
        const int getId() {
            return this -> id_Clienti;
        }
        // setteri:
        void setCategorie(string categorie) {
            this -> categorie = categorie;
        }
        void setNume(char *nume) {
            if(this -> nume != NULL)
                delete []this->nume;
            this -> nume = new char[strlen(nume)+1];
            strcpy(this -> nume, nume);
        }
        void setKg(float kg) {
            this -> kg = kg;
        }
        void setBanat(bool banat) {
            this -> banat = banat;
        }

        // operatorul <=:
        // vom compara prima data in functie de categorie, daca un client are P (premium) iar celalat N(normal), primul va fii "mai bun"
        // in caz de egalitate: lexicografic (pt nume)
        bool operator<=(const Clienti &c) {
            // Prima data scriu cazurile in care this ar fii strict mai mare decat c, pt contradictie
            if(this -> categorie > c.categorie) // N > P
                return 0;
            if(strcmp(this -> nume, c.nume) < 0) // Numele lui this > numele c
                return 0;
            if(this -> kg > c.kg) //this are mai multe kg decat c
                return 0;
            if(this -> banat == 1 and c.banat == 0) // this e banat c nu e
                return 0;
            return 1;

        }

        // operatorul ==:
        // vom compara dupa categorie(la fel ca la <=) si apoi in functie de kg si starea de banat; (fara nume)
        bool operator==(const Clienti &c) {
            if(this -> categorie != c.categorie)
                return 0;
            if(this -> kg != c.kg)
                return 0;
            if(this -> banat != c.banat)
                return 0;
            return 1;
        }

        // operatorul ++ (pre):
        Clienti &operator++() {
            // consider incrementare daca:
            // in momentul de fata are abonament normal -> il fac premium
            // daca este banat -> il debanez
            this -> categorie = 'P';
            this -> banat = 0;
            return *this;
        }

        // operatorul ++ (post):
        Clienti operator++(int) {
            //! fara referinta, pt ca returnez aux, o variabila locala
            // variabila locala va fii stearsa dupa terminarea functiei
            Clienti aux = *this; // folosesc o variabila auxiliara pentru a salva continutul din this inainte de incrementare
            ++(*this); // modific this
            return aux; // returnez valorea initiala (dinainte de ++) a lui this;

        }

        // operatorul +:
        Clienti operator+(Clienti client) {
            // Consider ca 'adun' doi clienti si obtin un 'nou client' care are datele urmatoare:
            // din doua abonamente fac unul
            // daca unul din ei are premium -> clientul rezultat va avea tot premium
            // numele clientului rezultat va fii din concatenarea numelelor celor doi
            // kg - suma kg celor 2
            // daca unul este banat - clientul rezultat va fii si el banat
            // Clienti client - este o copie a 'client'
            // se va sterge cand se termina apelul functiei
            if(this -> categorie == "P" or client.categorie == "N") // in celelate cazuri client.categorie ramane cum a fost initial
                client.categorie = "P";
            int lungime;
            char aux[100]; // copie pentru a pastra continutul din cliet.nume
            strcpy(aux, this -> nume);
            strcat(aux," ");
            strcat(aux, client.nume);
            lungime = strlen(aux);
            if(client.nume != NULL)
                delete []client.nume; // pt a aloca din nou dinamic un char de lungimea client.nume + spatiu(1) + this -> nume
            client.nume = new char[lungime + 1];
            strcpy(client.nume,aux);
            // acum client.nume contine numele amanudora
            client.kg += this -> kg;
            if(this -> banat == 1 or client.banat == 1) // daca doar unul e banat si rezultatul va fii banat
                client.banat = 1;
            return client;
        }
        // operatorul -:
        Clienti operator-(Clienti client) {
            // consider ca 'scad' doi clienti si obtin un 'nou client' care are datele urmatoare:
            // daca unul are abonament normal, si celalate are fie premium sau normal
            // abonamentul rezultat va fii normal
            // numele va fii de forma: "this -> nume fara client.nume"
            // voi face diferenta dintre kg
            // daca unul nu este banat si celalat fie ca este sau nu
            // clientul rezultat NU va fii banat
            // prin valoare - se face o copie care va fii returnata - rezultatul scaderii
            if (this -> categorie == "N" or client.categorie == "N")
                client.categorie = "N";
            int lungime = strlen(client.nume) + 6 + strlen(this -> nume); // 6 = " fara "
            char aux[200]; // pt a copia numele din client
            strcpy(aux, client.nume);
            if(client.nume != NULL)
                delete []client.nume; // realocare de memorie dinamica
            client.nume = new char[lungime + 1];
            strcpy(client.nume, this-> nume);
            strcat(client.nume, " fara ");
            strcat(client.nume, aux);
            client.kg = this -> kg - client.kg;
            if (this -> banat == 0 or client.banat == 0)
                client.banat = 0;
            return client;
        }

        // operatorul =:
        Clienti &operator=(const Clienti &c) {
            //prima data destructor:
            if(this -> nume != NULL)
                delete []this->nume;
            //copy-constructor:
            this -> categorie = c.categorie;
            this -> nume = new char[strlen(c.nume)+1];
            strcpy(this -> nume, c.nume);
            this -> kg = c.kg;
            this -> banat = c.kg;
            return *this; //pentru dereferentiere
        }

        // operatorul >>
        friend istream &operator>>(istream &in, Clienti &c);
        // operatorul <<
        friend ostream &operator<<(ostream &out, const Clienti &c);
        //copy-constructor:
        Clienti(const Clienti &c):id_Clienti(idContor_Clienti++){
            this -> categorie = c.categorie;
            this -> nume = new char[strlen(c.nume)+1];
            strcpy(this -> nume, c.nume);
            this -> kg = c.kg;
            this -> banat = c.kg;
        }
        // Operatorul []:
        int operator[](int index) {
            if(index >= 0 && index < strlen(this -> nume))
                return this -> nume[index]; // a index-a litera din nume
            throw runtime_error("Index invalid in Clienti.");
        }
        // operatorul cast:
        operator string() {
            return this -> categorie;
        }
        /*// operatorul + (pentru 2 clase - scris de 2 ori pt comutativitate):
        friend Clienti operator+(Clienti client, Aparate aparat);
        friend Clienti operator+(Aparate aparat, Clienti client);
        */
        //destructor:
        ~Clienti() {
            if(this -> nume != NULL)
                delete []this->nume;
        }
};
int Clienti::idContor_Clienti = 1;
//Citirea (pentru clasa Clienti):
istream &operator>>(istream &in, Clienti &c) {
    if(c.nume != NULL)
           delete []c.nume;
    cout << "    Categoria abonamentului (al clientului): "; in>>c.categorie;
    cout<< "    Numele clientului: ";
    char aux[100];
    in.get();
    in.getline(aux,99);
    c.nume = new char[strlen(aux)+1];
    strcpy(c.nume, aux);
    cout << "    Kg: "; in>>c.kg;
    cout <<"    Este banat?(true(1)/false(0)): "; in>>c.banat;
    return in;
}
// Afisarea (pentru clasa Clienti):
ostream &operator<<(ostream &out, const Clienti &c){
    out << "    ID ul clientului: " << c.id_Clienti << endl;
    out << "    Categoria abonamentului: ";
    if(c.categorie == "N")
        out << "Normal"<< endl;
    else
        out << "Premium" << endl;
    out << "    Numele clientului: " << c.nume << endl;
    out << "    Masa corporala: " << c.kg <<" kg" << endl;
    out << "    Este banat?: ";
    if (c.banat == 1)
        out << "Da" << endl;
    else
        out<< "Nu" << endl;
    return out;
}

class Produse {
    private:
        const int id_Produs;
        static int idContor_Produse;
        string numeProdus;
        float gramaj;
        double pret;
        int nrValoriNutritionale;
        int *valoriNutritionale; // fiecare produs are in campul 0 caloriile, 1 carbohidrati, si tot asa..
    public:
        //Constructorul fara parametrii:
        Produse():id_Produs(idContor_Produse++) {
            numeProdus = "Anonim";
            gramaj = 0;
            pret = 0;
            nrValoriNutritionale = 0;
            valoriNutritionale = NULL;
        }
        // Constructorul cu parametrii:
        Produse(string numeProdus, float gramaj, double pret, int nrValoriNutritionale, int *valoriNutritionale):id_Produs(idContor_Produse++) { // argumentele pentru constructor;
            this -> numeProdus = numeProdus;
            this -> gramaj = gramaj;
            this -> pret = pret;
            this -> nrValoriNutritionale = nrValoriNutritionale;
            this -> valoriNutritionale = new int[nrValoriNutritionale + 1]; // alocare dinamica
            for(int i = 0; i < this -> nrValoriNutritionale; i++)
                this -> valoriNutritionale[i] = valoriNutritionale[i];
        }
        // 2 constructori cu parametrii:
        // Primul va avea doar numeleProdus si gramaj:
        Produse(string numeProdus, float gramaj):id_Produs(idContor_Produse++) {
            this -> numeProdus = numeProdus;
            this -> gramaj = gramaj;
            pret = 0;
            nrValoriNutritionale = 0;
            valoriNutritionale = NULL;
        }
        // Al doilea va avea nrValoriNutritionale si valoriNutritionale:
        Produse(int nrValoriNutritionale, int* valoriNutritionale):id_Produs(idContor_Produse++) {
            numeProdus = "Anonim";
            gramaj = 0;
            pret = 0;
            this -> nrValoriNutritionale = nrValoriNutritionale;
            this -> valoriNutritionale = new int[this -> nrValoriNutritionale + 1];
            for(int i = 0; i < this ->nrValoriNutritionale; i++)
                this -> valoriNutritionale[i] = valoriNutritionale[i];
        }
        // Getteri:
        string getNumeProdus() {
            return numeProdus;
        }
        float getGramaj() {
            return gramaj;
        }
        double getPret() {
            return pret;
        }
        int getNrValoriNutritionale() {
            return nrValoriNutritionale;
        }
        const int* getValoriNutritionale () {

            return valoriNutritionale;
        }
        const int getID() {
            return this -> id_Produs;
        }
        // Setteri:
        void setNumeProdus(string numeProdus) {
            this -> numeProdus = numeProdus;
        }
        void setGramaj(float gramaj) {
            this -> gramaj = gramaj;
        }
        void setPret(double pret) {
            this -> pret = pret;
        }
        void setNrValoriNutritionale(int nrValoriNutritionale) {
            this -> nrValoriNutritionale = nrValoriNutritionale;
        }
        void setValoriNutritionale(int *valoriNutritionale) {
            if(this -> valoriNutritionale != NULL)
                delete []this -> valoriNutritionale; // pt a putea aloca un nou spatiu in mem
            this -> valoriNutritionale = new int[this ->nrValoriNutritionale + 1];
            for(int i = 0; i < this -> nrValoriNutritionale; i++)
                this -> valoriNutritionale[i] = valoriNutritionale[i];
        }
        // Operatorul >> (citirea):
        friend istream &operator>>(istream &in, Produse &p);
        // Operatorul << (afisare) :
        friend ostream &operator<<(ostream &out, const Produse &p);
        // Copy constructor:
        Produse(const Produse &obiect):id_Produs(idContor_Produse++) {
            // const ca sa nu pot edita prin this(obiectul returnat de functie) obiectul primit ca parametru;
            // aproape ca si constructorul cu parametrii, dar pun obiect.(parametri)
            this -> numeProdus = obiect.numeProdus;
            this -> gramaj = obiect.gramaj;
            this -> pret = obiect.pret;
            this -> nrValoriNutritionale = obiect.nrValoriNutritionale;
            this -> valoriNutritionale = new int[obiect.nrValoriNutritionale + 1];
            for(int i = 0; i < this -> nrValoriNutritionale; i++)
                this -> valoriNutritionale[i] = obiect.valoriNutritionale[i];
        }
        // Operatorul =:
        Produse &operator=(Produse &obiect) {
            // destructor:
            if(this -> valoriNutritionale != NULL)
                delete []this -> valoriNutritionale;
            // copy-constructor:
            if (this != &obiect) {
                this -> numeProdus = obiect.numeProdus;
                this -> gramaj = obiect.gramaj;
                this -> pret = obiect.pret;
                this -> nrValoriNutritionale = obiect.nrValoriNutritionale;
                this -> valoriNutritionale = new int[obiect.nrValoriNutritionale + 1];
                for(int i = 0; i < this -> nrValoriNutritionale; i++)
                    this -> valoriNutritionale[i] = obiect.valoriNutritionale[i];
            }
            //prin *this - returnez valoarea
            return *this;
        }
        // Operatorul ==:
        bool operator==(const Produse &p) {
            // Consideram ca 2 produse sunt egale daca au acelasi nume, gramaj, si pret:
            if(this -> numeProdus != p.numeProdus)
                return 0;
            if(this -> gramaj != p.gramaj)
                return 0;
            if(this -> pret != p.pret)
                return 0;
            return 1;
        }
        // Operatorul <=
        bool operator<=(const Produse&p) {
            // consideram ca this < p daca:
            // lexicografic numele lui this < p
            // (in caz de egalitate): raportul dintre pret/gramaj este <= decat cel de la p:
            if(this -> numeProdus > p.numeProdus)
                return 0;
            if((this -> pret / this -> gramaj) > (p.pret / p.gramaj))
                return 0;
            return 1;
        }
        // Operatorul ++ (pre):
        Produse &operator++() {
            // consideram ++ daca ii crestem gramajul si gramajul cu o unitate
            this -> gramaj +=1;
            this -> pret +=1;
            return *this; // dereferentiere
        }
        // Operatorul ++(post)
        Produse operator++(int) {
            //! fara referinta, pt ca returnez aux, o variabila locala
            // variabila locala va fii stearsa dupa terminarea functiei
            Produse aux = *this; // folosesc o variabila auxiliara pentru a salva continutul din this inainte de incrementare
            ++(*this); // modific this
            return aux; // returnez valorea initiala (dinainte de ++) a lui this;
        }
        // Operatorul +:
        Produse operator+(Produse p) {
            // Consider ca adun doua produse in urmatorul fel:
            // combin numele celor 2, adun pretul si gramaj
            // gasesc maximul pentru nrValoriNutritionale (dintre this si p)
            // pentru fiecare pozitie din vector, fac p.valoriNutritionale[i] += this->valoriNutritionale[i]
            p.numeProdus = this -> numeProdus + " " + p.numeProdus;
            p.gramaj += this -> gramaj;
            p.pret += this -> pret;
            int maxim = max(p.nrValoriNutritionale,this -> nrValoriNutritionale);
            int aux[5] = {0}; // fac o copie a vectorului p;
            for(int i = 0; i < p.nrValoriNutritionale; i++)
                aux[i] = p.valoriNutritionale[i];
            if(p.valoriNutritionale != NULL)
                delete []p.valoriNutritionale;
            p.valoriNutritionale = new int[maxim+1];
            int pozitie = 0; // fac cu while si nu for, pt a evita situatiile in care sar din vectorul this->
            while(pozitie < this -> nrValoriNutritionale) {
                p.valoriNutritionale[pozitie] = this->valoriNutritionale[pozitie] + aux[pozitie];
                pozitie +=1;
            }
            while(pozitie < maxim) { // intra doar daca vectorul (this->...) a fost prea mic
                p.valoriNutritionale[pozitie] = aux[pozitie];
                pozitie +=1;
            }

            return p;
        }
        // Operatorul -:
        Produse operator-(Produse p) {
            // Consider ca scad doua produse in urmatorul fel:
            // combin numele celor 2, scad pretul si gramaj
            // gasesc maximul pentru nrValoriNutritionale (dintre this si p)
            // pentru fiecare pozitie din vector, fac p.valoriNutritionale[i] = this->valoriNutritionale[i] - p.valoriNutritionale[i]
            p.numeProdus = this -> numeProdus + " FARA " + p.numeProdus;
            p.gramaj = this -> gramaj - p.gramaj;
            p.pret = this -> pret - p.pret;
            int maxim = max(p.nrValoriNutritionale,this -> nrValoriNutritionale);
            int aux[5] = {0}; // fac o copie a vectorului p;
            for(int i = 0; i < p.nrValoriNutritionale; i++)
                aux[i] = p.valoriNutritionale[i];
            if(p.valoriNutritionale != NULL)
                delete []p.valoriNutritionale;
            p.valoriNutritionale = new int[maxim+1];
            int pozitie = 0; // fac cu while si nu for, pt a evita situatiile in care sar din vectorul this->
            while(pozitie < this -> nrValoriNutritionale) {
                p.valoriNutritionale[pozitie] = this->valoriNutritionale[pozitie] - aux[pozitie];
                pozitie +=1;
            }
            while(pozitie < maxim) { // intra doar daca vectorul (this->...) a fost prea mic
                p.valoriNutritionale[pozitie] = aux[pozitie];
                pozitie +=1;
            }

            return p;
        }
        // operatorul cast:
        operator int() {
            return this -> nrValoriNutritionale;
        }
        // Operatorul []:
        int operator[](int index) {
            if(index >= 0 && index < this -> nrValoriNutritionale)
                return this -> valoriNutritionale[index];
            throw runtime_error("Index invalid in Produse.");
        }
        //Destructor:
        ~Produse() {
            if(this -> valoriNutritionale != NULL)
                delete []this -> valoriNutritionale;
        }

};
int Produse::idContor_Produse = 1;
//Citirea (pentru clasa Produse):
istream &operator>>(istream &in, Produse &p) {
    // Prima data ma asigur ca spatiile alocate dinamic sunt sterse:
    if(p.valoriNutritionale != NULL) {
        delete []p.valoriNutritionale;
    }
    cout << "Numele produsului este: "; in >> p.numeProdus;
    cout << "Gramajul produsului: "; in >> p.gramaj;
    cout << "Pretul produsului: "; in >> p.pret;
    cout << "Numarul de valori nutritionale: (numar maxim 4) "; in >> p.nrValoriNutritionale;
    cout << "Valorile efective: " << endl;
    p.valoriNutritionale = new int[p.nrValoriNutritionale +1];
    for(int i = 0; i < p.nrValoriNutritionale; i++) {
        if (i == 0) {
            cout << "Numarul de calorii: "; in >> p.valoriNutritionale[0];
        }
        if (i == 1) {
            cout << "Numarul de grasimi: "; in >> p.valoriNutritionale[1];
        }
        if (i == 2) {
            cout << "Numarul de carbohidrati: "; in >> p.valoriNutritionale[2];
        }
        if (i == 3) {
            cout << "Numarul de proteine: "; in >> p.valoriNutritionale[3];
        }
    }
    cout << endl;
    return in;
}
// Afisarea (pentru clasa Produse):
ostream &operator<<(ostream &out, const Produse &p) {
    out << "----ID-ul produsului este: " << p.id_Produs << endl;
    out << "----Numele produsului este: " << p.numeProdus << endl;
    out << "----Gramajul produsului: " <<  p.gramaj << endl;
    out << "----Pretul produsului: " << p.pret << endl;
    out << "----Numarul de valori nutritionale: " << p.nrValoriNutritionale << endl;
    out << "----Valorile efective: " << endl;
    for(int i = 0; i < p.nrValoriNutritionale; i++) {
        if (i == 0) {
            out << "----Numarul de calorii: " << p.valoriNutritionale[0] << endl;
        }
        if (i == 1) {
            out << "----Numarul de grasimi: " << p.valoriNutritionale[1] << endl;
        }
        if (i == 2) {
            out << "----Numarul de carbohidrati: " << p.valoriNutritionale[2] << endl;
        }
        if (i == 3) {
            out << "----Numarul de proteine: " << p.valoriNutritionale[3] << endl;
        }
    }
    cout << endl;
    return out;
}



class Sala {
    private:
        const int id_Sala;
        static int idContor_Sala;
        bool deschisa; //in functie de orar
        int nrClienti;
        Clienti *clienti;
        char* manager;
        char categorie; // N - normala / P - premium
        double venituri;
        int nrProduse;
        Produse *produse;
    public:
        //constructorii:
        //constructorul fara parametrii:
        Sala():id_Sala(idContor_Sala++) {
            deschisa = true;
            nrClienti = 0;
            clienti = NULL;
            manager = new char[strlen("anonim")+1];
            strcpy(manager, "anonim");
            categorie = 'N';
            venituri = 0;
            nrProduse = 0;
            produse = NULL;
        }

        //construtorul cu toti parametrii:
        Sala(bool deschisa, int nrClienti, Clienti *clienti, char* manager, char categorie, double venituri, int nrProduse, Produse *produse):id_Sala(idContor_Sala++) {
            this -> deschisa = deschisa;
            this -> nrClienti = nrClienti;
            this -> clienti = new Clienti[this->nrClienti+1]; // alocare dinamica
            for(int i=0;i<=nrClienti;i++)
                this -> clienti[i] = clienti[i];
            this -> manager = new char[strlen(manager)+1];
            strcpy(this -> manager, manager);
            this -> categorie = categorie;
            this -> venituri = venituri;
            this -> nrProduse = nrProduse;
            this -> produse = new Produse[this -> nrProduse + 1];
            for(int i = 0; i < this -> nrProduse; i++) {
                this -> produse[i] = produse[i];
            }
        }
        // 2 constructori cu parametrii:
        // primul va avea daca sala e deschisa, numarul de clienti si vectorul de clienti:
        Sala(bool deschisa, int nrClienti, Clienti* clienti):id_Sala(idContor_Sala++) {
            this -> deschisa = deschisa;
            this -> nrClienti = nrClienti;
            for(int i = 0; i < this -> nrClienti; i++)
                this -> clienti[i] = clienti[i];
            this -> manager = new char[strlen("anonim")+1];
            strcpy(this -> manager, "anonim");
            categorie = 'N';
            venituri = 0;
            nrProduse = 0;
            produse = NULL;
        }
        // al doilea va avea manager, nrProduse si *produse:
        Sala(char* manager, int nrProduse, Produse *produse):id_Sala(idContor_Sala++) {
            deschisa = true;
            nrClienti = 0;
            clienti = NULL;
            this -> manager = new char[strlen(manager)+1];
            strcpy(this -> manager, manager);
            categorie = 'N';
            venituri = 0;
            this -> nrProduse = nrProduse;
            this -> produse = new Produse[this -> nrProduse + 1];
            for(int i = 0; i < this -> nrProduse; i++) {
                this -> produse[i] = produse[i];
            }

        }
        //Getteri
        bool getDeschisa() {
            return deschisa; // alocarea statica
        }
        int getNrClienti() {
            return nrClienti;
        }
        const Clienti* getClienti() { //alocare dinamica, folosim const pt a nu putea modifica vectorul;
            return clienti;
        }
        const char* getManager() {
            return manager;
        }
        char getCategorie() {
            return categorie;
        }
        double getVenituri() {
            return venituri;
        }
        int getNrProduse() {
            return nrProduse;
        }
        const Produse* getProduse() {
            return produse;
        }
        const int getID() {
            return id_Sala;
        }

        //Setteri
        void setDeschisa(bool deschisa) { // alocarea statica
            this -> deschisa = deschisa;
        }
        void setNrClienti(int nrClienti) {
            this -> nrClienti = nrClienti;
        }
        void setClienti(Clienti *clienti) {
            if (this->clienti != NULL) { //sterg continutul
                delete[] this->clienti;
            this->clienti = new Clienti[this->nrClienti+1]; //aloc o noua zona, de dimensiunea parametrului curent
            for(int i=0; i<this->nrClienti;i++)
                this -> clienti[i] = clienti[i];
            }
        }
        void setManager(char* manager) {
            if(this -> manager != NULL) // sterg stringul vechi
                delete[] this -> manager;
            this -> manager = new char[strlen(manager)+1]; // aloc un nou spatiu de lungimea param
            strcpy(this -> manager, manager);
        }
        void setCategorie(char categorie) {
            this -> categorie = categorie;
        }
        void setVenituri(double venituri) {
            this -> venituri = venituri;
        }
        void setNrProduse(int nrProduse) {
            this -> nrProduse = nrProduse;
        }
        void setProduse(Produse *produse) {
            if(this -> produse != NULL) // sterg vectorul curent cu produse
                delete []this -> produse;
            this -> produse = new Produse[this -> nrProduse + 1]; // creez un vector nou cu dimeniunea (noua)
            for(int i = 0; i < this -> nrProduse; i++)
                this -> produse[i] = produse[i]; // pun in vectorul creat pe fiecare pozitie, valorile din vect nou
        }

        //operatorul >> citire:
        friend istream& operator>>(istream& in, Sala &s);

        //operatoul << afisare:
        friend ostream& operator<<(ostream& out, const Sala &s);

        //copy-constructor:
        Sala(const Sala &s):id_Sala(idContor_Sala++) {
            // aproape ca si constructorul cu parametrii, dar pun s.(parametri)
            this -> deschisa = s.deschisa;
            this -> nrClienti = s.nrClienti;
            this -> clienti = new Clienti[s.nrClienti+1]; // aloc o zona noua pt vectorul de clienti
            for(int i=0;i<=s.nrClienti-1;i++)
                this -> clienti[i] = s.clienti[i];
            this -> manager = new char[strlen(s.manager)+1]; // aloc o zona noua pt numele managerului
            strcpy(this -> manager, s.manager); // pun la adresa(zona noua de mem) continutul din string ul s.manager
            this -> categorie = s.categorie;
            this -> venituri = s.venituri;
            this -> nrProduse = s.nrProduse;
            this -> produse = new Produse[this -> nrProduse +1]; // aloc o zona noua pt vectorul de produse
            for(int i = 0; i < this -> nrProduse; i++)
                this -> produse[i] = s.produse[i];
        }
        //operatorul =:
        Sala& operator=(const Sala &s) {
            if (this != &s) { // daca adresa ob curent este diferita de aceea a obiectului s
                //destructor:
                if(this -> clienti != NULL) // sterg campurile dinamice, vor fii realocate folosind dimensiunile din s
                    delete[] this -> clienti;
                if(this -> manager != NULL)
                    delete []this -> manager;
                if(this -> produse != NULL)
                    delete []this -> produse;
                //copy-constructor:
                this -> deschisa = s.deschisa;
                this -> nrClienti = s.nrClienti;
                this -> clienti = new Clienti[s.nrClienti+1];
                for(int i=0;i<=s.nrClienti-1;i++)
                    this -> clienti[i] = s.clienti[i];
                this -> manager = new char[strlen(s.manager)+1];
                strcpy(this -> manager, s.manager);
                this -> categorie = s.categorie;
                this -> venituri = s.venituri;
                this -> nrProduse = s.nrProduse;
                this -> produse = new Produse[this -> nrProduse +1];
                for(int i = 0; i < this -> nrProduse; i++)
                    this -> produse[i] = s.produse[i];


            }
            return *this;
        }
        // operatorul ==:
        bool operator==(const Sala &s) {
            // consider ca 2 sali sunt egale daca:
            // au acelasi numar de clienti au acelasi manager si sunt de aceeasi categorie
            if (this -> nrClienti != s.nrClienti)
                return 0;
            if (strcmp(this -> manager,s.manager)!=0)
                return 0;
            if (this -> categorie != s.categorie)
                return 0;
            return 1;
        }
        // operatorul <=:
        bool operator<=(const Sala &s) {
            // consider ca sala this este <= decat sala s daca:
            // numarul de clienti este mai mic
            // lexicografic, managerul din this este <= decat din s
            // this este de categorie Normala iar s este Premium
            if(this -> nrClienti > s.nrClienti)
                return 0;
            if(this -> manager > s.manager)
                return 0;
            if(this -> categorie == 'P' and s.categorie == 'N')
                return 0;
            return 1;
        }
        // operatorul ++ (pre):
        Sala &operator++() {
            // face sala deschisa - chiar daca e inchisa;
            // creste cu unu numarul de clienti;
            // creste veniturile cu 100
            // face sala de categoria premium ('P')
            this -> deschisa = true;
            this -> categorie = 'P';
            this -> venituri += 100;
            this -> nrClienti +=1;
            return *this;
        }
        // operatorul ++ (post)
        Sala operator++(int) {
            Sala aux = *this;
            ++(*this);
            return aux;
        }
        // operatorul +:
        Sala operator+(Sala s) {
            // consider ca adun 2 sali in urmatorul fel:
            // daca una e deschisa - rezultatul va fii o sala deschisa
            // adun nr de clienti
            // realoc vectorul de clienti
            // venituri adun
            if (this -> deschisa == true || s.deschisa == true)
                s.deschisa = true;
            Clienti *aux = new Clienti[s.nrClienti +1];
            for(int i = 0; i < s.nrClienti; i++)
                aux [i] = s.clienti[i];
            if(s.clienti != NULL)
                delete []s.clienti;
            s.nrClienti += this -> nrClienti;
            s.clienti = new Clienti[s.nrClienti +1];
            for(int i = 0; i < this -> nrClienti; i++)
                s.clienti[i] = this -> clienti[i];
            for(int i = this -> nrClienti; i < s.nrClienti; i++)
                s.clienti[i] = aux[i - this->nrClienti];
            s.venituri += this -> venituri;
            return s;
        }
        // operatorul -:
        Sala operator-(Sala s) {
            // consider ca scad 2 sali in urmatorul fel:
            // daca una e inchisa - rezultatul va fii o sala inchisa
            // scad nr de clienti
            // scad nr de produse
            // veniturile le scad
            if(this -> deschisa == 0 or s.deschisa == 0)
                s.deschisa = 0;
            s.nrClienti = this -> nrClienti - s.nrClienti;
            s.nrProduse = this -> nrProduse - s.nrProduse;
            s.venituri = this -> venituri - s.venituri;
            return s;
        }
        // operatorul []:
        Clienti operator[](int index) {
            if(index >= 0 && index < this -> nrClienti)
                return this -> clienti[index];
            throw runtime_error("Index invalid in Sala.");
        }
        // operatorul cast:
        operator int() {
            return this -> nrClienti;
        }
        //destructor
        ~Sala() {
            if(this -> clienti != NULL)
                delete[] this -> clienti;
            if(this -> manager != NULL)
                delete []this -> manager;
            if(this -> produse != NULL)
                delete[] this -> produse;
        }
};
int Sala::idContor_Sala = 1;
//Citirea (pentru clasa Sala):
istream& operator>>(istream& in, Sala &s) {
    // &operator in, in - obiect al clasei ostream
    // returneaza adresa obiectului in
    //golim spatiile care vor fii alocate dinamic:
    if(s.clienti != NULL)
        delete[] s.clienti;
    if(s.manager != NULL)
        delete[] s.manager;
    if(s.produse != NULL)
        delete[] s.produse;
    cout << endl;
    cout << "Este deschisa sala?(true/false): "; in >> s.deschisa;
    cout << "Numarul de clienti: "; in >> s.nrClienti;
    s.clienti = new Clienti[s.nrClienti+1];
    cout << "Clienti: " << endl;
    for(int i = 0; i<=s.nrClienti-1; i++) {
        cout << "Al " << i+1 <<"-lea client: " << endl;
        in >> s.clienti[i];
    }
    cout << "Nume Manager: ";
    char aux[100]; //citim prin o alta variabila pt a nu avea acces direct la variabila s.manager;
    in.get();
    in.getline(aux,99);
    s.manager = new char[strlen(aux)+1];
    strcpy(s.manager, aux);
    // cum initial nu stim ce lungime are cuvantul pe care-l vom avea
    // folosim aux, prin care tinem minte si lungimea cuvantului (pt alocarea dinamica) si pt a tine minte continutul cuvantului
    cout << "Categoria salii (N/P): ";
    in >> s.categorie; ;
    cout << "Venituri: "; in>>s.venituri;
    cout << "Numarul de produse din sala: "; in >> s.nrProduse;
    s.produse = new Produse[s.nrProduse + 1]; // aloc dinamic inainte sa incarc pe fiecare pozitie cu valori
    cout << "Produsele respective: " << endl;
    for(int i = 0; i < s.nrProduse; i++)
        in >> s.produse[i];
    cout << endl;
    return in;
}
//Afisare (pentru clasa Sala):
ostream &operator<<(ostream& out, const Sala &s) {
    // const Sala &s - referinta catre obiectul s, pt ca nu vrem sa modificam obiectul
    // &operator out, out - obiect al clasei ostream
    // returneaza adresa obiectului out
    out << "-----------------------------------" << endl;
    out << "ID ul salii este: " << s.id_Sala << endl;
    out << "Sala este: ";
    if(s.deschisa == true)
        out << "deschisa" << endl;
    else
        out << "inchisa" << endl;
    out << "Sala are un numar de " << s.nrClienti << " clienti" << endl;
    out << "Clientii sunt urmatorii: " << endl;
    for(int i = 0;i<=s.nrClienti-1;i++)
        out << s.clienti[i] << endl;
    out << "Numele managerului este: " << s.manager << endl;
    out << "Categoria salii este: ";
    if(s.categorie == 'N')
        cout << "Normala" << endl;
    else
        if(s.categorie == 'P')
            cout << "Premium" << endl;
    out << "Veniturile sunt: " << s.venituri << endl;
    out << "Numarul de produse din sala: " << s.nrProduse << endl;
    out << "Produsele respective: " <<endl;
    for(int i = 0; i < s.nrProduse; i++)
        out << s.produse[i] << endl;
    out << endl;
    out << "-----------------------------------";
    return out;
}

/*Clienti operator+(Clienti client, Aparate aparat) {
    // adun un client si un aparat in felul urmator:
    // iau numele clientului si scriu
    // NUME CLIENT + " LUCREAA LA " + NUME APARAT
    // consider masa ca fiind suma clientului + aparat (sa fie mai multe argumente :) )
    char aux[200];
    strcpy(aux, client.getNume());
    cout << aux;
    strcat(aux, " LUCREAZA LA ");
    strcpy(aux, aparat.getNumeAparat());
    if(client.nume != NULL)
        delete []client.nume;
    client.nume = new char[strlen(aux)+1];
    strcpy(client.nume, aux);
    client.kg += aparat.masaMaxima;
    return client;

}

Clienti operator+(Aparate aparat, Clienti client) {
    // adun un client si un aparat in felul urmator:
    // iau numele clientului si scriu
    // NUME CLIENT + " LUCREAA LA " + NUME APARAT
    // consider masa ca fiind suma clientului + aparat (sa fie mai multe argumente :) )
    char aux[200];
    strcpy(aux, client.getNume());
    cout << aux;
    /*strcat(aux, " LUCREAZA LA ");
    strcpy(aux, aparat.getNumeAparat());
    if(client.getNume() != NULL)
        delete []client.nume;
    client.nume = new char[strlen(aux)+1];
    strcpy(client.nume, aux);
    client.kg += aparat.masaMaxima;
    return client;
}
*/
int main() {
    vector <Sala> listaSali;
    int k = 1;
    while(k==1) {
        cout << "Apasa 1 pentru a citi o sala.\n";
        cout << "Apasa 2 pentru a afisa lista de sali.\n";
        cout << "Apasa 3 pentru a sterge a k-a clasa.\n";
        cout << "Apasa 4 pentru a vedea salile de un anumit tip (citeste-l).\n";
        cout << "Apasa 5 pentru a vedea salile deschise. \n";
        cout << "Apasa 6 pentru vedea daca un produs este disponibil intr-o sala.\n";
        cout << "Apasa 7 pentru a iesii din program.\n";
        int comanda;
        cin >> comanda;
        switch(comanda) {
            case 1:
                {
                    Sala s;
                    cin >> s;
                    listaSali.push_back(s); // pun in vector sala citita
                    break;
                }
            case 2:
                {
                    if(listaSali.size() == 0)
                        cout << "Momentan nu exista sali" << endl;
                    for(int i = 0; i<listaSali.size(); i++) {
                        cout<<endl<<listaSali[i]<<endl; // afisez salile din vector
                    }
                    break;
                }
            case 3:
                {
                    int pozitie;
                    cout << "Citeste indexul salii care trebuie stearsa: ";
                    cin >> pozitie;

                    if(listaSali.begin() != listaSali.end()) { // verific daca lista nu este vida
                        listaSali.erase(listaSali.begin()+pozitie); // sterg elementul de pe pozitia citita
                    } else {
                        cout << "In lista nu sunt destule sali" << endl; // tratez cazul de lista vida
                    }
                    break;
                }
            case 4:
                {
                    char categorie;
                    int numar = 0; // daca nu am cel putin o sala de o anumita categorie, afisez un mesaj specific
                    cout << "Tipul salii N/P - normal sau premium: ";
                    cin >> categorie; // citesc N sau P
                    if (categorie == 'N') {
                        for(int i = 0; i<listaSali.size(); i++) {
                            if (listaSali[i].getCategorie() == 'N') { // Verific daca exista sali de tip N (normale)
                                numar = 1;
                            }
                        }
                        if(numar == 1) { // daca am gasit cel putin o sala de acel tip, o afisez
                            cout << "Salile de categorie normala sunt: ";
                            for(int i = 0; i<listaSali.size(); i++) {
                                if (listaSali[i].getCategorie() == 'N') {
                                    cout<<endl<<listaSali[i]<<endl;
                                }
                            }
                        } else { // nu am gasit o sala, deci dau mesajul urmator
                            cout << "Nu exista sali de tip normal" << endl;
                        }
                    }
                    if (categorie == 'P') {
                        for(int i = 0; i<listaSali.size(); i++) {
                            if (listaSali[i].getCategorie() == 'P') { // Verific daca exista sali de tip P (premium)
                                numar = 1;
                            }
                        }
                        if(numar == 1) { // daca am gasit cel putin o sala de acel tip, o afisez
                            cout << "Salile de categorie normala sunt: ";
                            for(int i = 0; i<listaSali.size(); i++) {
                                if (listaSali[i].getCategorie() == 'P') {
                                    cout<<endl<<listaSali[i]<<endl;
                                }
                            }
                        } else { // nu am gasit o sala, deci dau mesajul urmator
                            cout << "Nu exista sali de tip premium" << endl;
                        }
                    }
                    break;
                }
            case 5:
                {   int sem = 0; // tratez cazul in care nu sunt sali deschise
                    for(int i = 0; i < listaSali.size(); i++) {
                        if(listaSali[i].getDeschisa() == 1) {  // ma folosesc de getter pt a lua valoarea din campul deschisa
                            sem = 1; // daca sem este 1, exista cel putin o sala deschisa
                        }
                    }
                    if(sem == 1) {
                        cout << "Salile deschise sunt urmatoarele: " << endl;
                        for(int i = 0; i < listaSali.size(); i++) {
                            if(listaSali[i].getDeschisa() == true) { // afisez salile deschise
                                cout << listaSali[i] << endl;
                            }
                        }
                    } else {
                        cout << "Momentan nu sunt sali deschise" << endl; // tratez cazul in care nu sunt sali deschise";
                    }
                    break;
                }
            case 6:
                {
                // acest caz va fii tratat in felul urmator:
                // citesc un cuvant - numeProdus
                // caut prin toate salile daca acel produs exista
                // in caz afirmativ, afisez salile respective
                // altfe, afisez "nu este pe stoc"
                cout << "Dati numele produsului: ";
                char cuvant[100];
                cin.get();
                cin.getline(cuvant, 100);
                int semafor = 0;
                for(int i = 0; i < listaSali.size(); i++) {
                    for(int j = 0; j < listaSali[i].getNrProduse(); j++) {
                        Produse aux = listaSali[i].getProduse()[j];
                        if(cuvant == aux.getNumeProdus())
                            semafor = 1;
                    }
                }
                if (semafor == 1) {
                    cout << "Produsul se gaseste in Sala: ";
                    for(int i = 0; i < listaSali.size(); i++) {
                        for(int j = 0; j < listaSali[i].getNrProduse(); j++) {
                            Produse aux = listaSali[i].getProduse()[j];
                            if(cuvant == aux.getNumeProdus())
                                cout << i+1 << " ";
                        }
                    cout << endl;
                }
                } else {
                    cout << "Produsul nu se gaseste in nicio sala. " << endl;
                }

                break;
                }
            case 7:
                {
                    k=0;
                    break;
            }
        }
    }
    return 0;
}

