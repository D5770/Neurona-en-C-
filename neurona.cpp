#include <iostream>
#include <string>
#include <vector>

using namespace std;

class neurona {
private:
	int entradas;
	double sesgo;
	string funcion;
	vector<double> pesos;
public:
	neurona(int num_entradas, double sesgo_valor, string func,vector<double> pesos_v){
	entradas = num_entradas; 
	sesgo = sesgo_valor;
	pesos = pesos_v;
	funcion = func;
	}
	double procesar(vector<double> entradas_value){
		double result = 0.0;
		if(funcion == "relu"){
			for(int i = 0;i < entradas; i++){
				double valor = entradas_value[i] * pesos[i];
				result += valor;
			}
		}
		return relu(result + sesgo);
	}
	double relu(double value){
		if(value > 0.0){
			return value;
			}
		cout<<value<<"\n";
		return 0.0;
	}

	double entrenar(double o, double e){
		double w = 0.0;
		double error = e - o;
		w = (error / 2.0) / 100.0;
	sesgo += w;
	return w;
	}
};
int main(){
	neurona neu(1, 2.0, "relu", {0.4});

	vector<double> entrada_mi = {0.2};

	double resultado_final = neu.procesar(entrada_mi);
	cout<<"[C++] Neurona sin entrenar resultado "<<resultado_final<<"\n";
	// double peso_entrenado = neu.entrenar(resultado_final, 3);

	int epocas = 3000;
	double esperado;
	cout<<"Introduce el resultado esperado de la neurona: \n";cin>>esperado;
	for(int epoca = 1; epoca <= epocas; epoca++){
		double resultado_actual = neu.procesar(entrada_mi);
		neu.entrenar(resultado_actual, esperado);

		double nuevo_intento = neu.procesar(entrada_mi);
		double fin = nuevo_intento;
		if(epoca == epocas){
			cout<<"[C++] Entrenado con "<<epocas<<" epocas "<<"resultado: "<<fin<<"\n";
		}
	}
	return 0;
}
// Aún me falta corregir ciertas cosas y aparte me falta entrenar el peso





