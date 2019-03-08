#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

void printLine(string st)
{
	multimap<string, int>FW;

	string Word;
	string Line;
	stringstream ss(st);
	int line = 0;

	map<string, int>::iterator m;

	while (getline(ss, Line, '\n'))
	{
		stringstream sss(Line);
		while (sss >> Word)
			FW.insert(make_pair(Word, line));
		line++;
	}

	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << "->" << m->second << endl;//(*m)first = m->first
}

string read_from_file(const char *file_name)
{
	ifstream inFile(file_name);
	stringstream strStream;
	strStream << inFile.rdbuf();//´Ù ÀÐ¾î¿È
	return strStream.str();
}

int main()
{
	const char *file_name = "C:\\Users\\user\\Desktop\\20151466\\Project1\\news.txt";
	string str = read_from_file(file_name);
	printLine(str);
	return 0;
}