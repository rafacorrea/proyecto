// proyectoFinalTC1018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include "assert.h"
#include <string>
#include <fstream>
#include <time.h>
#include <random>
#include <vector>


using namespace std;

class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = clock();
		}

		unsigned long elapsedTime() {
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds) {
			return seconds >= elapsedTime();
		}
};


unsigned long hash_string( const string & s );
char randomLetra();
bool checkLetra(char, string);
int sumarPuntos(string s);

int _tmain(int argc, _TCHAR* argv[])
{
	std::unordered_map<std::string, int> m;
	ifstream file("diccionario.txt");
	string str;
	if(file.is_open())
	{
		while(getline(file,str))
		{
			m[str] = hash_string(str);
		}
		file.close();
	}

	else 
		cout << "No se pudo abrir el archivo" << endl;

	char temp = randomLetra();
	cout << "Ingrese una palabra que contenga la letra " << temp << endl;
	cin >> str;

	// check if key is present
	if(checkLetra(temp,str))
	{
		if (m.find(str) != m.end())
			std::cout << "Se encontro la palabra \"" << str << "\"!"  << endl;
		else
			cout << str << " no es una palabra" << endl;
	}
	else
		cout << "No contiene la letra " << temp << endl;


	timer t;
	vector<string> test;
	test.reserve(30);

	int i = 0;
	t.start();
	while(t.elapsedTime() < 5)
	{
		cin >> str;
		test.push_back(str);
	}

	cout << "Palabra\tPuntos" << endl;
	for(vector<string>::iterator vectorit = test.begin(); vectorit != test.end(); vectorit++)
	{
		cout << *vectorit << "\t" << sumarPuntos(*vectorit) <<endl;
	}
	// retrieve
	//std::cout << m["hola"] << '\n';
	//std::map<std::string, int>::iterator i = m.find("hola");
	//assert(i != m.end());
	//std::cout << "Key: " << i->first << " Value: " << i->second << '\n';

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

unsigned long hash_string( const string & s )
{
  unsigned long h = 0; 
  for ( int i=0 ; i < s.length(); i++)  
    h = 5*h + s[i];   
  
  return h;
}
