#include <vector>
#include <math.h>

using namespace std;


#ifndef POLINOMIO
#define POLINOMIO



class polinomio{
private:

	//exp, coef
	vector <pair<int, int>> v;

	//no usar pow
	long long int calcularMonomio(int valorX, int exp, int coef) {

		//return pow(valorX, mon.exponente) * mon.coeficiente;

		long long int ret=1;
		int i=1;
		
		while(i<=exp){
			

				ret*=valorX;

			
			i++;
		}	
		
		
		return ret*coef;
	}


public:
	polinomio(){

	}

	void addMonomio(int coef, int exp) {
		int pos=0, aux=0;
		while(aux<v.size() and v[aux].first<=exp){
			
			pos=aux;
			aux++;
		}

		if(pos==v.size()){

			v.push_back({exp, coef});
		}
		else if(v[pos].first==exp){

			v[pos].second+=coef;
		}
		else{

			v.push_back({exp, coef});
			for(int i=v.size()-1; i>pos;i--){

				swap(v[i], v[i-1]);
			}
		}
	}


	long long int calcularPol(int valorX){
		int ret = 0;
		
		for (int i = 0; i < v.size(); i++) {

			ret += calcularMonomio(valorX, v[i].first, v[i].second);
		}
		return ret;
	}
	
};

#endif
