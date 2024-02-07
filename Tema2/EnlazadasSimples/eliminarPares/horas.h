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

        this->HH=h;
        this->MM=m;
        this->SS=s;
    
    }

    void write (istream& in){

       int h, m, s;
       char aux;

       in >> h >> aux >> m >> aux >> s;

       HH = h;
       MM = m;
       SS = s;

    }

    void read(ostream& out) const {

        out<< setfill('0') << setw(2)<<getH()<<":";
        out<< setfill('0') << setw(2)<<getM()<<":";
        out<< setfill('0') << setw(2)<<getS();
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