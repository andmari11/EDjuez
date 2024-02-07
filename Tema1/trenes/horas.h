#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>


using namespace std;

#ifndef HORA
#define HORA


class Hora{

    int HH, MM, SS;


public:

    int getH () const{

        return HH;
    }

    int getM() const{

        return MM;
    }

    int getS() const {


        return SS;
    }

    Hora(int h=0, int m=0, int s=0){


        if(!valido(h, m, s)){

            throw invalid_argument("ERROR\n");
        }

        this->HH=h;
        this->MM=m;
        this->SS=s;
    
    }

    bool valido(int h , int m , int s) const {

        return 0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59;
    }

    void write (istream& in){

       int h, m, s;
       char aux;

       in >> h >> aux >> m >> aux >> s;

       if (!valido(h, m, s)) {

            throw domain_error("ERROR\n");

       }

       HH = h;
       MM = m;
       SS = s;

    }

    void read(ostream& out) const {

        out<< setfill('0') << setw(2)<<getH()<<":";
        out<< setfill('0') << setw(2)<<getM()<<":";
        out<< setfill('0') << setw(2)<<getS();
    }

    bool operator<(Hora const& h) const{

        return this->getH() * 3600 + this->getM() * 60 + this->getS() < h.getH() * 3600 + h.getM() * 60 + h.getS();
    }

};

inline istream& operator>>(istream& in, Hora & h){


    h.write(in);

    return in;
}

inline ostream& operator<< (ostream & out, Hora const& h){

    h.read(out);
    return out;
}
#endif