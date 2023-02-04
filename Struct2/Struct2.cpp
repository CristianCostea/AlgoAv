
#include <iostream>
#include <fstream>
#include <stdio.h>

typedef struct laptop
{
	char tipcpu[6];
	float frecventa; //in GHZ
	float memorie; //in GB
	char tipdisk[3]; // Poate fi HDD sau SDD
	float capacitatedisk; //in GB 
	int id; //ID unic

};

using namespace std;
int  bubbleSort(laptop a[10], int lung) {
	for (int i = 0; i < lung; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j].frecventa > a[i].frecventa) {
				laptop x;
				x = a[j];
				a[j] = a[i];
				a[i] = x;
			}
		}
	}
	return 0;
}

int BinarySearch(laptop a[],int n, float frecventa)
// returneaza -1 daca nu gaseste rez sau ID-ul elementului gasit
{
	int i = 0;
	int j = n - 1;
	int k = (i+j) / 2;
	cout << "i j k\n";
	cout << i << " " << j << " " << k << '\n';

	while (i<=j)
	{
		if (a[k].frecventa == frecventa)
		{
			return k;
		}
		if (a[k].frecventa < frecventa) 
		{
			i = k+1;
			k = (i + j) / 2;
			cout << i << " " << j << " " << k << '\n';
		}
		if (a[k].frecventa > frecventa)
		{
			j = k-1;
			k = (i + j) / 2;
			cout << i << " " << j << " " << k << '\n';
		}
		
	}
	return -1;
}
int main()
{
	laptop al[10];
	int n;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	std::cout << "Cate laptopuri sunt? (max 10)\n";
	//std::cin >> n;
	fin >> n;
	std::cout << n << '\n';
	std::cout << "Introduceti caracteristicile laptopurilor (tip cpu, frecventa, memorie, tip disc, capacitate disc)" << "\n";
	std::cout << "Cate o linie pentru fiecare laptop, separate prin spatiu\n";
	for (int i=0; i < n; i++) {
		//std::cin >> al[i].tipcpu >> al[i].frecventa >> al[i].memorie >> al[i].tipdisk >> al[i].capacitatedisk;
		fin >> al[i].tipcpu >> al[i].frecventa >> al[i].memorie >> al[i].tipdisk >> al[i].capacitatedisk;
		std:cout << al[i].tipcpu << " " << al[i].frecventa << " " << al[i].memorie << " " << al[i].tipdisk << " " << al[i].capacitatedisk <<'\n';

		al[i].id = i;
	}

	bubbleSort(al, n);


	std::cout << "Ai introdus, sortat dupa frecventa crescator\n";
	for (int i=0; i < n; i++) {
		std::cout <<al[i].id << " " << al[i].tipcpu << " " << al[i].frecventa << " "
			<< al[i].memorie << " " << al[i].tipdisk << " " << al[i].capacitatedisk << "\n";
	}
	cout << n << '\n';
	std::cout << "Ce frecventa cautati?";
	float f;
	std::cin >> f;
	int pozf = BinarySearch(al, n, f);
	if (pozf > -1)
	{
		fout << "Am gasit frecventa " << f << " in pozitia " << pozf << '\n';
		cout << "Am gasit frecventa " << f << " in pozitia " << pozf << '\n';
	}
	else
	{
		fout << "Nu am gasit frecventa " << f << "\n";
		cout << "Nu am gasit frecventa " << f << "\n";
	}
}

