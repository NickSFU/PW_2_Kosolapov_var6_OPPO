// PW_2_Kosolapov_var6_OPPO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct temp_measurement
{
	int year, month, day;
	string location;
	float temperature;

};

vector <temp_measurement> data1;

void print_temp()
{
	temp_measurement a;
	for (int i = 0; i < data1.size(); i++)
	{
		a = data1[i];
		cout << a.year << "." << a.month << "." << a.day << " " << a.location << " " << a.temperature << endl;
	}
}
int main()
{
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "File is not opened";
		return 1;
	}
	temp_measurement a;
	string line;
	int n;
	getline(in, line, '\n');
	n = stoi(line);
	for (int i = 0; i < n; i++)
	{
		getline(in, line, '.');
		a.year = stoi(line);
		getline(in, line, '.');
		a.month = stoi(line);
		getline(in, line, ' ');
		a.day = stoi(line);
		getline(in, line, ' ');
		a.location = line;
		getline(in, line);
		a.temperature = stof(line);
		data1.push_back(a);
	}
	print_temp();
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
