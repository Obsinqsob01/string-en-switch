//Incluimos las librerias que usaremos en el programa
#include <iostream> //Uso basico de i/o de C++
#include <string.h> //Uso de las funciones strupr() y tolower()

//Usamos en nombre de espacio estandard de C++
using namespace std;

//Funcion que nos ayuda a pasar strings en switch, *ignorar y no modificar*
constexpr unsigned int str2int(const char * str, int h = 0){
	return !str[h] ? 5381 : (str2int(str,h + 1) * 33) ^ str[h]; 
}

//Funcion principal main
int main(){
	/*Declaramos 2 variables, una alberga el tipo logico y la otra la expresion ingresada,
	exp la declaramos como cadena de caracteres basada en arreglos, usando el dato string no funciona
	*tambien ignorar*
	*/
	char exp[2],tipo;
	
	//Se le pide al usuario que ingrese el caracter correspondiente al operador logico
	cout<<"Ingrese el tipo logico con el que va a resolver el problema ('a' and y 'o' or): ";
	cin>>tipo; //Guardamos la entrada en la variable tipo
	
	//Se le pide al usuario que ingrese la expresion
	cout<<"Ingrese una expresion: ";
	cin>>exp; //Guardamos la entrada en la varable exp
	
	/*Esta funcion lo que hace es pasar la variable expresion a mayusculas, en caso de que se ingrese minusculas
	solo para cuestiones de que nuestro programa funcione correctamente en ambos casos*/
	strupr(exp);
	
	/*Hacemos el switch primero hacia nuestra variable tipo, la funcion tolower() convierte la variable pasada por parametro 
	a minusculas*/
	switch(tolower(tipo)){
		case 'a': //En caso de que la variable tipo sea 'a'
			//Hacemos un switch usando la funcion str2int(exp) que hace que podamos comparar cadenas
			switch(str2int(exp)){
				/*Aqui nos saltamos 3 casos en los que todos da falso, por lo que no era necesario poner
				una instruccion para cada uno, si no soo acomodarlos de manera que al entrar en uno de los
				casos llevara a una instruccion final donde serviria para todos*/
				case str2int("FF"):
				case str2int("VF"):
				case str2int("FV"):
					//Si se ingreso cualquiera de las 3 expresiones anteriores al final solo llega a esta instruccion
					cout<<endl<<"La expresion es falsa";
					break;
				//Este seria el caso en el que la instruccion es verdadera
				case str2int("VV"):
					cout<<endl<<"La expresion es verdadera";
					break;
				//Este seria el caso por defecto/contrario de la expresion
				default:
					cout<<endl<<"La expresion ingresada no es correcta!";
			}
			break;
		case 'o': //En caso de que la variable tipo sea 'o'
			//Hacemos un switch usando la funcion str2int(exp) que hace que podamos comparar cadenas
			switch(str2int(exp)){
				/*Aqui nos saltamos 3 casos en los que todos da verdadero, por lo que no era necesario poner
				una instruccion para cada uno, si no soo acomodarlos de manera que al entrar en uno de los
				casos llevara a una instruccion final donde serviria para todos*/
				case str2int("VF"):
				case str2int("FV"):
				case str2int("VV"):
					//Si se ingreso cualquiera de las 3 expresiones anteriores al final solo llega a esta instruccion
					cout<<endl<<"La expresion es verdadera";
					break;
				//Este seria el caso en el que la instruccion es falsa
				case str2int("FF"):
					cout<<endl<<"La expresion es falsa";
					break;
				//Este seria el caso por defecto/contrario de la expresion
				default:
					cout<<endl<<"La expresion ingresada no es correcta!";
			}
			break;
		////Este seria el caso por defecto/contrario del tipo logico ingresado
		default:
			cout<<endl<<"El tipo logico ingresado no es correcto!";
	}
	
	//Usamos la funcion system("pause>null") para que el programa no se cierre
	system("pause>null");
	//Devolvemos la funcion
	return 0;
}