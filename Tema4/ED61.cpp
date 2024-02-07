#include <iostream>
#include <iomanip>

#include <string>
#include <list>
#include <set>

#include <unordered_map>


using namespace std;


using clientes=string;
using codigos=string;

struct tFecha
{
    int mes, dia, anyo;

    bool operator<(const tFecha &fecha2) const
    {
        if (anyo < fecha2.anyo)
        {
            return true;
        }
        else if (anyo == fecha2.anyo)
        {
            if (mes < fecha2.mes)
            {
                return true;
            }
            else if (mes == fecha2.mes)
            {
                if (dia < fecha2.dia)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


class Tienda{

    struct infoProducto{

        int cantidad=0;
        multiset<tFecha> listaFechas;
        list<clientes> listaEspera;
    };
    unordered_map <codigos, infoProducto> registroProductos;
public:

    list<clientes> adquirir(const codigos& c, const tFecha& f, const int& cantidad){

        list<clientes> ret;

        if(registroProductos.count(c)){

            auto &it=registroProductos.at(c);
            int i=cantidad;

            if(!it.listaEspera.empty()){


                while(!it.listaEspera.empty() and i>0){

                    ret.push_back(it.listaEspera.front());
                    it.listaEspera.pop_front();
                    i--;
                }

            }

            it.cantidad+=i;

            for(;i>0;i--){

                it.listaFechas.insert(tFecha(f));
            }

        }
        else{


            auto &it=registroProductos[c];
            it.cantidad+=cantidad;

            for(int i=cantidad;i>0;i--){

                it.listaFechas.insert(tFecha(f));
            }
        }

        return ret;
    }

    pair<bool, tFecha> vender(const codigos& prod, const clientes& c){

        tFecha f;
        pair<bool, tFecha> ret={false,f};

        if(registroProductos.count(prod)){

            auto &it=registroProductos.at(prod);

            if(it.cantidad>0){
                f=tFecha(*it.listaFechas.begin());

                ret={true, f};
                it.listaFechas.erase(it.listaFechas.begin());
                it.cantidad--;
            }
            else{

                it.listaEspera.push_back(c);
            }
        }
        else{
            
            registroProductos[prod].listaEspera.push_back(c);
        }

        return ret;
    }

    int cuantos(const codigos& prod) const {

        if(registroProductos.count(prod)){

            return registroProductos.at(prod).cantidad;
        }
        
        return 0;
    }

    bool hay_esperando(const codigos& prod){

        if(registroProductos.count(prod)){

            return !registroProductos.at(prod).listaEspera.empty();
        }
        
        return false;
    }

};

bool resuelveCaso()
{

    string instruccion;

    cin >> instruccion;

    if (!cin)
        return false;

    Tienda t;
    string cod, cliente;
    tFecha fecha;
    int cantidad;

    while (instruccion != "FIN")
    {

        if (instruccion == "vender")
        {

            cin >> cod;
            cin >> cliente;
            auto ret=t.vender(cod, cliente);
            if (ret.first)
            {

                cout << "VENDIDO "<<ret.second.dia<<"/"<<setw(2)<<setfill('0')<<ret.second.mes<<"/"<<ret.second.anyo;
            }
            else
            {

                cout << "EN ESPERA";
            }
        }
        else if (instruccion == "adquirir")
        {
            char aux;
            cin >> cod;
            cin >> fecha.dia>>aux>>fecha.mes>>aux>>fecha.anyo;
            cin >> cantidad;

            list<string> l = t.adquirir(cod, fecha, cantidad);
            cout << "PRODUCTO ADQUIRIDO ";

            for (string aux : l)
            {

                cout << aux << " ";
            }
        }
        else if (instruccion == "cuantos")
        {
            cin >> cod;

            cout << t.cuantos(cod);
        }
        else
        {
            cin >> cod;

            if (t.hay_esperando(cod))
            {

                cout << "SI";
            }
            else
            {
                cout << "NO";
            }
        }

        cout << endl;
        cin >> instruccion;
    }

    cout <<"---"<<endl;

    return true;
}

int main()
{
    while (resuelveCaso());

}