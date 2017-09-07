#include <iostream>
#include <iomanip>//solo es estetico - no afecta a las operacion
using namespace std;//Es necesario para hacer un programa interactivo pero las operaciones son basicas (no str)

float promedio(int numeros[],int x){//funcion con dos parametros: array y la longitud del mismo
	float suma=0; // Para almacenar la suma que se realiza en el bucle
	for (int i=0;i<x;i++)//Bucle de tamano "x"
		suma+=numeros[i];//suma cada uno de los elementos del array
	return (suma/x);//regresa un resultado flotante entre la suma total y el numero de elementos
}

float mediana(int numeros[],int x){
	if (x%2==0)//Si el numero de elementos del array es par se tiene que hacer un promedio entre los 2 elementos centrales
		return float(numeros[(x/2)-1]+numeros[x/2])/2;
	else
		return numeros[(x/2)];//si es impar el numero de elementos del array regresa el valor del elemento central
}

int maximo(int numeros[],int x){
	int max=numeros[0];//le doy el valor maximo de forma arbitraria al indice cero para tener una referencia y comparar
	for (int i=1;i<x;i++){//Bucle de tamano "x-1" porque se comienza desde el indice 1
		if (max<numeros[i])//recorre todo el array comparando uno a uno de forma consecutiva
			max=numeros[i];//si pasa el condicional ese valor se almacena en "max"
	}return max;
}
//minimo y maximo son iguales a excepcion del "<" y ">"
int minimo(int numeros[],int x){
	int min=numeros[0];//le doy el valor minimo de forma arbitraria al indice cero para tener una referencia y comparar
	for (int i=1;i<x;i++){//Bucle de tamano "x-1" porque se comienza desde el indice 1
		if (min>numeros[i])//si el indice cero en mayor al indice siguiente el valor de "min" cambiara
			min=numeros[i];
	}return min;
}

int factorial(int x){//Uso recursividad porque creo que es mejor que un bucle
	if (x<2)//factorial de uno y cero es uno
		return 1;//es un dato ya conocido
	else//el factorial de n tambien se puede expresar como n*(n-1)!
		return x*factorial(x-1);//Y es (n-1)! lo que lo hace recursivo al llamar denuevo a la funcion
}

int main(){
	int y,x,numero;
	cout << setw(9) <<"Promedio"<<"  (1)\n"<<setw(9)<<"Media"<<"  (2)\n"<<setw(9)<<"Maximo"<<"  (3)\n"<<setw(9)<<"Minimo"<<"  (4)\n"<<setw(9)<<"Factorial"<<"  (5)\n\n";
	cout <<"Ingrese el numero de operacion que desea realizar: ";cin >> y;
	if (y<5){//Use un condicional ya que las 4 primeras operaciones necesitan un conjunto de numeros
		cout << "Cuantos numeros va a ingresar? "; cin >> x;//Para darle una longitud al array
		int numeros [x];
		cout << "Ingrese los numeros:\n";
		for (int i=0;i<x;i++)//Use un bucle para ingresar de forma secuencial los numeros dentro del array
		cin>>numeros[i];
		switch (y){//Una forma mas corta (codigo) de llamar las funciones segun el numero de operacion que eligio
			case 1:	cout << "El promedio de los numeros es: " << promedio(numeros,x); break;
			case 2: cout << "La mediana de los numeros es: " << mediana(numeros,x); break;
			case 3:	cout << "El maximo de los numeros es: " << maximo(numeros,x); break;
			default: cout << "El minimo de los numeros es: " << minimo(numeros,x); break;
		}//segun sea el caso la funcion elegida sera llamada
	}
	else if (y==5){//No necesita un conjunto de numeros 
		cout << "Ingrese un numero para obtener su factorial: "; cin >> numero;
		cout << "El factorial de " << numero << " es: " << factorial(numero);
	}
	else//Por si ingresa cualquier numero que no este dentro de 1-5
		cout << "Numero invalido";//TODO EL CONDICIONAL SE PODIA SEPARAR EN UNA SOLA FUNCION Y DEJAR MAS ORDENADO LA FUNCION MAIN
	return 0; 
}

