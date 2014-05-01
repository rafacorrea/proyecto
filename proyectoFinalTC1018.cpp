// proyectoFinalTC1018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map> //hash table /map
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "Timer.h"
#include <map>


using namespace std;

char randomLetra(); //Letra al "azar" ;vocales mayor %
bool checkLetra(char, string); //revisar si *char* esta en *string*
int sumarPuntos(string s); 
void buscarNombre(string str, multimap<string,int> map); //busca e imprime todas las entradas con llave str
multimap<string,int> crearMapa(); //crea un multimapa desde scores.txt

int _tmain(int argc, _TCHAR* argv[])
{
	std::unordered_map<std::string, int> diccionario; // hash table donde se guardaran las palabras
	string str; //dicionario.txt >> str
	ifstream file("diccionario.txt");
	string decision = "r";

	srand(time(NULL));

	/* Popular HASH */
	if(file.is_open())
	{
		while(file>>str)
		{
			++diccionario[str]; 
		
		}
		file.close();
		
	}

	else 
	{
		cout << "No se pudo abrir el archivo diccionario.txt, no se creo la tabla hash" << endl;
		return false;
	}

	/* Ingresar palabras */
	Timer t;
	;

	
	char letra1; 
	char letra2; 
	bool correcto;

	/* JUGAR */
	while(decision == "r") // decision al final
	{
		t.start();
		set<string> palabras;
		correcto = true;
		while(t.elapsedTime() < 5) //tiempo para contestar
		{
			if(correcto) //nuevas letras...
			{
				letra1 = randomLetra();
				letra2 = randomLetra();
				while(letra1==letra2)
					letra2 = randomLetra();
				cout << "Ingrese una palabra que contenga la letra " << letra1 << " y " << letra2 << endl;
			}

			cin >> str;

			if(checkLetra(letra1,str) && checkLetra(letra2,str)) 
			{
				if (diccionario.find(str) != diccionario.end())
				{
					palabras.insert(str);
					correcto = true;
				}
				else
					correcto = false;
			}
			else
				correcto = false;
		}

		/* Generar tabla de puntos */

		int acumulador = 0;
		int temp;

		cout << "Palabra\t\tPuntos" << endl;
		for(set<string>::iterator set_it = palabras.begin(); set_it != palabras.end(); set_it++)
		{
			temp = sumarPuntos(*set_it);
			cout << *set_it << "\t\t" << temp <<endl;
			acumulador += temp;
		}

		cout << endl << "TOTAL\t" << acumulador << endl;

		/* Scores */
		cout << endl << "Ingrese su nombre para guardar el score" << endl;
		string nombre;
		cin.ignore();
		getline(cin, nombre);
	

		ofstream scores ("scores.txt", ios::app);
		if (scores.is_open())
		{
			scores << acumulador << ";" << nombre << "\n";
			scores.close();
		}
	
		else 
			cout << "No se pudo guardar el score" << endl;

		cout << endl << "Escriba un comando (r, -buscar *, -high)" << endl;
		getline(cin, decision);
	}	

	/*Genera y popula el multimapa desde "scores.txt", despues busca el nombre en "decision" en ese mapa*/
	if (decision.substr(0,7) == "-buscar")
	{
		buscarNombre(decision.substr(8), crearMapa()); 
	}

	
	return 0;
}


multimap<string,int> crearMapa()
{
	multimap<string,int> scores;
	string str;
	ifstream scoreREAD("scores.txt");

	if(scoreREAD.is_open())
	{
		while(getline(scoreREAD, str))
		{
			scores.insert(pair<string,int>(str.substr(str.find(";") + 1), atoi(str.substr(0, str.find(";")).c_str())));

		}
		scoreREAD.close();
	}
	else
		cout << "Error al generar mapa" << endl;

	return scores;
}


void buscarNombre(string str, multimap<string,int> map)
{
	pair<multimap<string,int>::iterator,multimap<string,int>::iterator> range;
	range = map.equal_range(str);
	cout << "Nombre\t\tScore\n" ;
	for(multimap<string,int>::iterator range_it = range.first; range_it != range.second; range_it++)
	{
		cout << str << "\t\t" <<  range_it->second << endl;
	}

}


int sumarPuntos(string s)
{
	int puntos = 0;
	for(int i = 0; i < s.length(); i++)
	{
		switch(s[i])
		{
		case 'a': 
		case 'e':
		case 'i':
		case 'o':
		case 'u': 
			{ 
				puntos += 10;
				break;
			}

		case 'z': 
		case 'x': 
		case 'f': 
			{ 
				puntos += 50;
				break;
			}

		default: 
			{
				puntos += 25;
				break;
			}
		}
	}

	return puntos;
}


char randomLetra()
{
	int temp = rand()%100;

	if (temp < 12)
		return 'a';
	else if (temp < 14)
		return 'b';
	else if (temp < 18)
		return 'c';
	else if (temp < 24)
		return 'd';
	else if (temp < 37)
		return 'e';
	else if (temp < 38)
		return 'f';
	else if (temp < 39)
		return 'g';
	else if (temp < 40)
		return 'h';
	else if (temp < 46)
		return 'i';
	else if (temp < 47)
		return 'j';
	else if (temp < 52)
		return 'l';
	else if (temp < 55)
		return 'm';
	else if (temp < 62)
		return 'n';
	else if (temp < 70)
		return 'o';
	else if (temp < 72)
		return 'p';
	else if (temp < 73)
		return 'q';
	else if (temp < 80)
		return 'r';
	else if (temp < 88)
		return 's';
	else if (temp < 92)
		return 't';
	else if (temp < 96)
		return 'u';
	else if (temp < 97)
		return 'v';
	else if (temp < 98)
		return 'x';
	else if (temp < 99)
		return 'y';
	else if (temp < 100)
		return 'z';
}


bool checkLetra(char letra, string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == letra)
			return true;
	}
	return false;
}

