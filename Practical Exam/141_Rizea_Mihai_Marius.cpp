// Nume Prenume Grupa: Rizea Mihai Marius 141
// Compilator: (IDE) Codeblocks
// Tutore de laborator: Szmeteanca Eduard

#include <iostream>
#include <vector>
using namespace std;

class Obiecte {// creez aceasta clasa pentru a aputea avea un id diferit pt fiecare obiect - o sa fac abstracta nu instantiez obiecte de aici
protected:
    static int idContor;
    const int id;
public:
    Obiecte():id(idContor++) {};
    ~Obiecte() = default;
    virtual istream &citire(istream &in) = 0;
    virtual ostream &afisare(ostream &out) const = 0;
    int getId() {return this -> id;}
};
int Obiecte::idContor = 1;
// In clasele de mai jos, am facut constructorul fara param, cc destructor si op= default, deoarece nu avem atribute alocate dinamic
// iar pentru copy constructor, am folosit lista de initilaizare
class Zid: public Obiecte {
private:
    float inaltime;
    float lungime;
    float grosime;
public:
    Zid() = default;
    Zid(float inaltime, float lungime, float grosime):inaltime(inaltime),lungime(lungime),grosime(grosime) {};
    Zid(const Zid&z) = default;
    Zid &operator=(const Zid&z) = default;
    ~Zid() = default;
    // getteri si setteri pentru subpunctul 2!
    float getInaltime() {return this -> inaltime;}
    float getLungime() {return this -> lungime;}
    float getGrosime() {return this -> grosime;}
    void setInaltime(float inaltime) {this -> inaltime=inaltime;}
    void setLungime(float lungime) { this -> lungime=lungime;}
    void setGrosime(float grosime) { this -> grosime=grosime;}

    // redefinesc in clasa citirea si afisarea - daca nu devine clasa abstracta
    virtual istream &citire(istream &in) {
        cout << "Inaltimea zidului este: "; in >> this -> inaltime;
        cout << "Lungime zidului este: "; in >> this -> lungime;
        cout << "Grosime zidului este: "; in >> this -> grosime;
        return in;
    }
    virtual ostream &afisare(ostream &out) const {
        out << "ID ul zidului este: " << this -> id << endl;
        out << "Inaltimea zidului este: " << this -> inaltime << endl;
        out << "Lungime zidului este: " << this -> lungime << endl;
        out << "Grosime zidului este: " << this -> grosime << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Zid &p);
    friend ostream &operator<<(ostream &out, const Zid &p);

};
istream &operator>>(istream &in, Zid &p) {
    return p.citire(in);
}
ostream &operator<<(ostream &out, Zid &p) {
    return p.afisare(out);
}
// In clasele de mai jos, am facut constructorul fara param, cc destructor si op= default, deoarece nu avem atribute alocate dinamic
// iar pentru copy constructor, am folosit lista de initilaizare
class Turn: public Obiecte {
private:
    float putereLaser;
public:
    Turn() = default;
    Turn(float putereLaser):putereLaser(putereLaser){};
    Turn(const Turn&z) = default;
    Turn &operator=(const Turn&z) = default;
    ~Turn() = default;
    virtual istream &citire(istream &in) {
        cout << "Puterea laser este: "; in >> this -> putereLaser;
        return in;
    }
     // getteri si setteri pentru subpunctul 2!
    float getPutereLaser() {return this -> putereLaser;}
    void setPutereLaser(float putereLaser) {this -> putereLaser = putereLaser;}
    virtual ostream &afisare(ostream &out) const {
        out << "ID ul turnului este: " << this -> id << endl;
        out << "Puterea laser este: " << this -> putereLaser << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Turn &p);
    friend ostream &operator<<(ostream &out, const Turn &p);

};
istream &operator>>(istream &in, Turn &p) {
    return p.citire(in);
}
ostream &operator<<(ostream &out, Turn &p) {
    return p.afisare(out);
}

// In clasele de mai jos, am facut constructorul fara param, cc destructor si op= default, deoarece nu avem atribute alocate dinamic
// iar pentru copy constructor, am folosit lista de initilaizare
class Robot: public Obiecte {
protected:
    float damage;
    int nivel;
    float viata;
public:
    Robot() = default;
    Robot(float damage, int nivel, float viata):damage(damage),nivel(nivel),viata(viata){};
    Robot(const Robot&z) = default;
    Robot &operator=(const Robot&z) = default;
    ~Robot() = default;
    // getteri si setteri pentru subpunctul 2!
    float getDamage() {return this -> damage;}
    int getNivel() {return this -> nivel;}
    float getViata() {return this -> viata;}
    void setDamage(float damage) {this ->damage = damage;}
    void setNivel(float nivel) {this->nivel = nivel;}
    virtual istream &citire(istream &in) {
        cout << "Damageul este: "; in >> this -> damage;
        cout << "Nivelul este: "; in >> this -> nivel;
        cout << "Viata este: "; in >> this -> viata;
        return in;
    }
    virtual ostream &afisare(ostream &out) const {
        out << "ID ul robotului este: " << this -> id << endl;
        out << "Damageul este: " << this -> damage << endl;
        out << "Nivelul este: " << this -> nivel << endl;
        out << "Viata este: " << this -> viata << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Robot &p);
    friend ostream &operator<<(ostream &out, const Robot &p);

};
istream &operator>>(istream &in, Robot &p) {
    return p.citire(in);
}
ostream &operator<<(ostream &out, Robot &p) {
    return p.afisare(out);
}

// In clasele de mai jos, am facut constructorul fara param, cc destructor si op= default, deoarece nu avem atribute alocate dinamic
// iar pentru copy constructor, am folosit lista de initilaizare

class RobotAerian: virtual public Robot {
private:
    float autonomiaDeZbor;
public:
    RobotAerian() = default;
    RobotAerian(float nivel, float damage, float viata, float autonomiaDeZbor):autonomiaDeZbor(autonomiaDeZbor),Robot(damage,nivel,viata){}; // reutilizare cod din parinte prin cc cu toti param
    RobotAerian(const RobotAerian&z) = default;
    RobotAerian &operator=(const RobotAerian&z) = default;
    ~RobotAerian() = default;
     // getteri si setteri pentru subpunctul 2!
    float getAutonomiaDeZbor() {return this -> autonomiaDeZbor;}
    void setAutonomiaDeZbor(float autonomiaDeZbor) {this -> autonomiaDeZbor = autonomiaDeZbor;}
    virtual istream &citire(istream &in);
    virtual ostream &afisare(ostream &out) const;

};

ostream &RobotAerian::afisare(ostream &out) const {
    this -> Robot::afisare(out); // reutilizare cod din parinte
    out << "Autonomia De Zbor este: " << this -> autonomiaDeZbor << endl;
    return out;
}
istream &RobotAerian::citire(istream &in) {
    this -> Robot::citire(in);
    cout << "Autonomia de zbor este: "; in >> this -> autonomiaDeZbor;
    return in;
}
// In clasele de mai jos, am facut constructorul fara param, cc destructor si op= default, deoarece nu avem atribute alocate dinamic
// iar pentru copy constructor, am folosit lista de initilaizare
class RobotTerestru: public Robot {
private:
    int nrGloante;
    bool areScut;
public:
    RobotTerestru() = default;
    RobotTerestru(bool areScut, float damage, float nivel, float viata,int nrGloante):nrGloante(nrGloante),areScut(areScut),Robot(damage,nivel,viata){}; // reutilizare cod din parinte prin cc cu toti param
    RobotTerestru(const RobotTerestru&z) = default;
    RobotTerestru &operator=(const RobotTerestru&z) = default;
    ~RobotTerestru() = default;
    // getteri si setteri pentru subpunctul 2!
    int getNrGloante() {return this -> nrGloante;}
    bool getAreScut() {return this -> areScut;}
    void setNrGloante(int nrGloante) {this -> nrGloante = nrGloante;}
     void setAreScut() {this -> areScut = true;}
    virtual istream &citire(istream &in);
    virtual ostream &afisare(ostream &out) const;

};

ostream &RobotTerestru::afisare(ostream &out) const {
    this -> Robot::afisare(out); // reutilizare cod din parinte
    out << "Numar gloante " << this -> nrGloante << endl;
    out << "Are scut: " << this -> areScut << endl;
    return out;
}
istream &RobotTerestru::citire(istream &in) {
    this -> Robot::citire(in); // reutilizare cod din parinte
    cout << "Numar gloante "; in >> this -> nrGloante;
    cout << "Are scut: "; in >> this -> areScut;
    return in;
}


int main()
{
    vector<Obiecte*> inventar;
    int k = 1;
    int scor = 50000;
    while(k) {
        int comanda;
        cout << "Apasati 1 pentru a adauga un zid (DEFAULT): 300p" << endl;
        cout << "Apasati 2 pentru a adauga un turn (DEFAULT): 500p" << endl;
        cout << "Apasati 3 pentru a adauga un robot aerian (DEFAULT):100p" << endl;
        cout << "Apasati 4 pentru a adauga un robot terestru (DEFAULT):50p" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Apasati 5 pentru a afisa toate obiectele din inventar:"<< endl;
        cout << "Apasati 6 pentru a afisa toate obiectele de tip robot:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Apasati 7 pentru a sterge un obiect din inventar:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Apasati 8 pentru a face upgrade la zid" << endl;
        cout << "Apasati 9 pentru a face upgrade la turn" << endl;
        cout << "Apasati 10 pentru a face upgrade la robot aerian" << endl;
        cout << "Apasati 11 pentru a face upgrade la robot terestru" << endl;
        cout << "Apasati 12 pentru a iesii" << endl;
        cout << "Mai aveti: "<<scor << endl;
        cin >> comanda;
        switch(comanda) {
        case(1): {
            if(scor < 300) {
                cout << "Nu se mai poate adauga";
                break;
            }
            Zid *p = new Zid(2,1,0.5);
            inventar.push_back(p);
            scor -=300;
            break;
        }
        case(2): {
            if(scor < 500) {
                cout << "Nu se mai poate adauga";
                break;
            }
            Turn *p = new Turn(1000);
            inventar.push_back(p);
            scor -=500;
        }
        case(3): {
            if(scor < 100) {
                cout << "Nu se mai poate adauga";
                break;
            }
            RobotAerian *p = new RobotAerian(1,100,100,10);
            inventar.push_back(p);
            scor -=100;
            break;
        }
        case(4): {
            if(scor < 50) {
                cout << "Nu se mai poate adauga";
                break;
            }
            RobotTerestru *p = new RobotTerestru(0,100,1,100,500); // 0 - pe prima pozitie, consideram ca nu are scut
            inventar.push_back(p);
            scor -=50;
            break;
        }
        case(5): {
            for(int i = 0; i < inventar.size(); i++) {
                if(dynamic_cast<Zid*>(inventar[i])) {
                    cout << *dynamic_cast<Zid*>(inventar[i]) << endl;
                 } else {
                     if(dynamic_cast<Turn*>(inventar[i])) {
                        cout << *dynamic_cast<Turn*>(inventar[i]) << endl;
                     } else {
                         if(dynamic_cast<RobotAerian*>(inventar[i])) {
                            cout << *dynamic_cast<RobotAerian*>(inventar[i]) << endl;
                        } else {
                            if(dynamic_cast<RobotTerestru*>(inventar[i])) {
                                cout << *dynamic_cast<RobotTerestru*>(inventar[i]) << endl;
                            }
                        }
                     }
                 }
            }
            break;
        }
        case(6): {
            for(int i = 0; i < inventar.size(); i++) {
                if(dynamic_cast<Robot*>(inventar[i])) {
                    cout << *dynamic_cast<Robot*>(inventar[i]) << endl;
                }
            }
            break;
        }
        case(7): {
            int id;
            cout << "Dati id ul elementului pe care doriti sa-l stergeti:" << endl;
            cin >> id;
            int sem = 0;
            int pozitie = 0;
            for(int i = 0; i < inventar.size(); i++) {
                if(inventar[i]->getId() == id) {
                    pozitie = i;
                    sem = 1;
                }
            }
            if(sem) {
                inventar.erase(inventar.begin() + pozitie);
                cout << "Stergerea s-a produs cu succes!" << endl;
                scor +=500;
            } else {
                cout <<"ID invalid!" << endl;
            }
        }
        case(8): {
            int id;
            cout << "Dati id ul zidului pe care doriti sa-l upgradati:" << endl;
            cin >> id;
            int sem = 0;
            int pozitie = 0;
            for(int i = 0; i < inventar.size(); i++) {
                if(inventar[i]->getId() == id) {
                    pozitie = i;
                    sem = 1;
                }
            }
            if(sem) {
                // retin atributele vechiului zid in cazul in care nu mai am scor
                Zid *p = new Zid(*dynamic_cast<Zid*>(inventar[pozitie]));
                int scor_nou = 100*(p->getGrosime()+1)*(p->getLungime()+1)*(p->getInaltime()+1);
                if(scor_nou > scor) {
                    cout << "Nu se poate face upgrade!" << endl;
                } else {
                    dynamic_cast<Zid*>(inventar[pozitie])->setInaltime(p->getInaltime()+1);
                    dynamic_cast<Zid*>(inventar[pozitie])->setGrosime(p->getGrosime()+1);
                    dynamic_cast<Zid*>(inventar[pozitie])->setLungime(p->getLungime()+1);
                    scor -= scor_nou;
                }
            }
            break;
        }
        case(9): {
            int id;
            cout << "Dati id ul turnului pe care doriti sa-l upgradati:" << endl;
            cin >> id;
            int sem = 0;
            int pozitie = 0;
            for(int i = 0; i < inventar.size(); i++) {
                if(inventar[i]->getId() == id) {
                    pozitie = i;
                    sem = 1;
                }
            }
            if(sem) {
                // retin atributele vechiului zid in cazul in care nu mai am scor
                Turn *p = new Turn(*dynamic_cast<Turn*>(inventar[pozitie]));
                int scor_nou = 500*(p->getPutereLaser()+500);
                if(scor_nou > scor) {
                    cout << "Nu se poate face upgrade!"<< endl;
                } else {
                    dynamic_cast<Turn*>(inventar[pozitie])->setPutereLaser(p->getPutereLaser()+500);
                    scor -= scor_nou;
                }
            }
            break;
        }
        case(10): {
            int id;
            cout << "Dati id ul robotului aerian pe care doriti sa-l upgradati:" << endl;
            cin >> id;
            int sem = 0;
            int pozitie = 0;
            for(int i = 0; i < inventar.size(); i++) {
                if(inventar[i]->getId() == id) {
                    pozitie = i;
                    sem = 1;
                }
            }
            if(sem) {
                // retin atributele vechiului robot in cazul in care nu mai am scor
                RobotAerian *p = new RobotAerian(*dynamic_cast<RobotAerian*>(inventar[pozitie]));
                int scor_nou = 50*(p->getAutonomiaDeZbor()+1)*(p->getDamage() + 25)*(p->getNivel()+1);
                if(scor_nou > scor) {
                    cout << "Nu se poate face upgrade!" << endl;
                } else {
                    dynamic_cast<RobotAerian*>(inventar[pozitie])->setAutonomiaDeZbor(p->getAutonomiaDeZbor()+1);
                    dynamic_cast<RobotAerian*>(inventar[pozitie])->setDamage(p->getDamage()+1);
                    dynamic_cast<RobotAerian*>(inventar[pozitie])->setNivel(p->getNivel()+1);
                    scor -= scor_nou;
                }
            }
            break;
        }
        case(11): {
            int id;
            cout << "Dati id ul robotului terestru pe care doriti sa-l upgradati:" << endl;
            cin >> id;
            int sem = 0;
            int pozitie = 0;
            for(int i = 0; i < inventar.size(); i++) {
                if(inventar[i]->getId() == id) {
                    pozitie = i;
                    sem = 1;
                }
            }
            if(sem) {
                // retin atributele vechiului robot in cazul in care nu mai am scor
                RobotTerestru *p = new RobotTerestru(*dynamic_cast<RobotTerestru*>(inventar[pozitie]));
                int scor_nou = 10*(p->getNrGloante()+100)*(p->getDamage() + 50)*(p->getNivel()+1);
                if(scor_nou > scor) {
                    cout << "Nu se poate face upgrade!" << endl;
                } else {
                    dynamic_cast<RobotTerestru*>(inventar[pozitie])->setNrGloante(p->getNrGloante()+100);
                    dynamic_cast<RobotTerestru*>(inventar[pozitie])->setDamage(p->getDamage() + 50);
                    dynamic_cast<RobotTerestru*>(inventar[pozitie])->setNivel(p->getNivel()+1);
                    if(p->getNivel() >=5) {
                        dynamic_cast<RobotTerestru*>(inventar[pozitie])->setAreScut();
                    }
                     scor -= scor_nou;
                }
            }
            break;
        }
        case(12): {
            k = 0;
            break;
        }
        }

    }

}
