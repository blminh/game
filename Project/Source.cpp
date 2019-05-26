#include <iostream>
#include <fstream>
using namespace std;

void open_file(fstream file)
{
	file.open("cauhoi.txt", ios::out | ios::in | ios::app);
}