#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>


using namespace std;

#ifndef HORA
#define HORA

class tHora{

     int h,m,s;

public:

    int getH () const{

        return h;
    }

    int getM() const{

        return m;
    }

    int getS() const {


        return s;
    }

        tHora(int h=0, int m=0, int s=0){

            this->h=h;
            this->m=m;
            this->s=s;

            if(!valido(h, m, s)){

                throw invalid_argument("ERROR\n");
            }
        }

        bool operator<(tHora const& other) const {

            bool ret=true;
            
            if(this->getH()>other.getH()){
                ret=false;
            }
            else if(this->getH()==other.getH()){

                if(this->getM()>other.getM()){
                    ret=false;
                }
                else if(m==other.getM() and s>other.getS()){

                    ret=false;
                }
            }

            return ret;
        }

        bool operator==(tHora const& h) const {
            return this->h * 3600 + this->m * 60 + this->s == h.h * 3600 + h.m* 60 + h.s;
        }

        tHora operator+ ( tHora hora2){

        
            s+=hora2.s;
            m += hora2.m +s/60;
            s %=60;    


            h+=hora2.h + m/60;
            m %=60;    

            if(!valido(h, m, s)){

                throw invalid_argument("ERROR\n");
            }

            return tHora(h, m, s);
        }

        bool valido(int h , int m , int s) const {

            return 0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59;
        }

        void read(istream & in){

            char aux;

            in>>h>>aux>>m>>aux>>s;

            if(!valido(h, m, s)){

                throw invalid_argument("ERROR\n");
            }

        }

        void print(std::ostream& o = std::cout) const {
      o << setfill('0') << setw(2) << getH() << ':'
        << std::setfill('0') << std::setw(2) << getM() << ':'
        << std::setfill('0') << std::setw(2) << getS();
    }

};

inline std::ostream & operator<<(std::ostream & salida, tHora const& h) {
   h.print(salida);
   return salida;
}
#endif