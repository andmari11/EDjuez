#include <string>
#include <map>
#include <set>
#include <list>
#include <iostream>

using namespace std;

struct Fecha
{
    int mes, dia, anyo;

    bool operator<(const Fecha &fecha2) const
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
using producto = string;
using cliente = string;
using sucesos = int;

class Tienda
{

    // codigoProducto, fecha y cantidad
    map<producto, set<pair<Fecha, int>>> listaProductos;
    // codigoProducto, suceso y cliente
    map<producto, set<pair<sucesos, cliente>>> listaClientes;

    map<cliente, map<producto, sucesos>> listaPedidosCliente;

    int pedidos;

public:
    Tienda()
    {
        pedidos = 0;
    }

    list<string> adquirir(string codigo, Fecha fecha, int cantidad)
    {

        listaProductos[codigo].insert({fecha, cantidad});
        
        list<string> ret;
        if (listaClientes.count(codigo))
            for (auto it : listaClientes.at(codigo))
            {

                ret.push_front(it.second);
            }

        return ret;
    }

    bool vender(string cod, string clientes)
    {   

        if (!listaProductos.count(cod))
        {

            listaPedidosCliente[clientes][cod] = pedidos;
            listaClientes[cod].insert({pedidos, clientes});
            pedidos++;

            return false;
        }



        // if(listaClientes.at(cod).)
        if (listaClientes.at(cod).count({listaPedidosCliente[clientes][cod], clientes}))
        {

            auto eliminar = listaClientes.at(cod).find({listaPedidosCliente[clientes][cod], clientes});

            listaClientes.at(cod).erase(eliminar);
        }
        else{
            return false;
        }

        if(listaPedidosCliente.count(clientes)){
            listaPedidosCliente[clientes].erase(cod);
        }
        else{
            return false;
        }
        

        return true;
    }

    int cuantos(string cod)
    {
        int ret = 0;
        for (auto it : listaProductos.at(cod))
        {

            ret += it.second;
        }

        return ret;
    }

    bool hay_esperando(string cod)
    {

        return listaClientes.count(cod) and !listaClientes.at(cod).empty();
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
    Fecha fecha;
    int cantidad;

    while (instruccion != "FIN")
    {

        if (instruccion == "vender")
        {

            cin >> cod;
            cin >> cliente;

            if (t.vender(cod, cliente))
            {

                cout << "VENDIDO";
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
            cin >> fecha.dia >> aux >> fecha.mes >> aux >> fecha.anyo;
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