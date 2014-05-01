// proyectoFinalTC1018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <set>
#include "Timer.h"

using namespace std;

char randomLetra();
bool checkLetra(char, string);
int sumarPuntos(string s);

int _tmain(int argc, _TCHAR* argv[])
{
	std::unordered_map<std::string, int> diccionario;
	string str;
	ifstream file("diccionario.txt");

	srand(time(NULL));

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

	Timer t;
	set<string> palabras;

	t.start();
	char temp;
	char temp2;
	bool correcto = true;
	while(t.elapsedTime() < 5)
	{
		if(correcto)
		{
			temp = randomLetra();
			temp2 = randomLetra();
			while(temp==temp2)
				temp2 = randomLetra();
			cout << "Ingrese una palabra que contenga la letra " << temp  << " y " << temp2 << endl;
		}
		cin >> str;
		if(checkLetra(temp,str) && checkLetra(temp2,str))
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

	cout << "Palabra\tPuntos" << endl;
	for(set<string>::iterator set_it = palabras.begin(); set_it != palabras.end(); set_it++)
	{
		cout << *set_it << "\t" << sumarPuntos(*set_it) <<endl;
	}


	return 0;
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
	else 
		return '!';
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

