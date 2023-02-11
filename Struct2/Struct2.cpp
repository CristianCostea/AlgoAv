
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

int  ixNumBubbleSort(float ix[][2], int lung) {
	for (int i = 0; i < lung; i++) {
		for (int j = 0; j < i; j++) {
			if (ix[j][1] > ix[i][1]) {
				swap(ix[i], ix[j]);
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
	std::cout << "i j k\n";
	std::cout << i << " " << j << " " << k << '\n';

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

int ixNumBinarySearch(float ix[][2], int n, float num)
// returneaza -1 daca nu gaseste rez sau ID-ul elementului gasit
{
	int i = 0;
	int j = n - 1;
	int k = (i + j) / 2;
	cout << "i j k\n";
	cout << i << " " << j << " " << k << '\n';

	while (i <= j)
	{
		if (ix[k][1] == num)
		{
			return k;
		}
		if (ix[k][1] < num)
		{
			i = k + 1;
			k = (i + j) / 2;
			cout << i << " " << j << " " << k << '\n';
		}
		if (ix[k][1] > num)
		{
			j = k - 1;
			k = (i + j) / 2;
			cout << i << " " << j << " " << k << '\n';
		}

	}
	return -1;
}

int ixNumInsert(float ix[][2], int n, int id, float v)
// returneaza -1 daca nu gaseste rez sau ID-ul elementului gasit
{
	int i = 0;
	int j = n - 1;
	int k = (i + j) / 2;
	//cout << "i j k\n";
	//cout << i << " " << j << " " << k << '\n';

	while (i <= j)
	{
		if (ix[k][1] == v)
		{
			for (int l = n ; l >= k + 1; l--) {
				ix[l][0] = ix[l - 1][0];
				ix[l][1] = ix[l - 1][1];
			}
			ix[k][0] = id;
			ix[k][1] = v;
			return n + 1;
		}
		if (ix[k][1] < v)
		{
			i = k + 1;
			k = (i + j) / 2;
//			cout << i << " " << j << " " << k << '\n';
		}
		if (ix[k][1] > v)
		{
			j = k - 1;
			k = (i + j) / 2;
//			cout << i << " " << j << " " << k << '\n';
		}

	}
	for (int l = n ; l >= j + 1; l--) {
		ix[l][0] = ix[l - 1][0];
		ix[l][1] = ix[l - 1][1];
	}
	ix[j+1][0] = id;
	ix[j+1][1] = v;
	return n + 1;

}

int main()
{
	laptop al[100];
	float ixFrecv[100][2];
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

	for (int i = 0; i < n; i++) {
		ixFrecv[i][0] = al[i].id;
		ixFrecv[i][1] = al[i].frecventa;
	}
	ixNumBubbleSort(ixFrecv, n);
	n = ixNumInsert(ixFrecv, n, n, 1.7);
	std::cout << "Ai introdus, sortat dupa frecventa crescator\n";
	for (int i=0; i < n; i++) {
		std::cout <<al[int(ixFrecv[i][0])].id << " " << al[int(ixFrecv[i][0])].tipcpu << " " << al[int(ixFrecv[i][0])].frecventa << " "
			<< al[int(ixFrecv[i][0])].memorie << " " << al[int(ixFrecv[i][0])].tipdisk << " " << al[int(ixFrecv[i][0])].capacitatedisk << "\n";
	}
	cout << n << '\n';
	std::cout << "Ce frecventa cautati?";
	float f;
	std::cin >> f;
	int pozf = ixNumBinarySearch(ixFrecv, n, f);
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

