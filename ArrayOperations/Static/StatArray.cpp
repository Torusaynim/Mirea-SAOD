#include <iostream>
#include "StatArray.h"
#include <ctime>
using namespace std;

void input(int* x, int n)
{
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < n; i++)
		cin >> x[i];
}

void random(int* x, int n)
{
	for (int i = 0; i < n; i++)
		x[i] = rand();
}

void output(int* x, int n)
{
	cout << "Массив: ";
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void insert(int* x, int k, int a, int& (n))
{
	n++;
	for (int i = n - 1; i > k; i--)
		x[i] = x[i - 1];
	x[k] = a;
}



void linpoisk(int* x, int k, int n)
{
	int j = 0;
	cout << "Номер(а) вашего элемента: ";
	for (int i = 0; i < n; i++)
		if (x[i] == k) {
			cout << i << " ";
			j++;
		}
	if (j == 0) cout << "Элемент не найден!";
}

int pervhod(int* x, int k, int n)
{
	for (int i = 0; i < n; i++)
		if (x[i] == k)
			return i;
	return -1;
}

int kolvovhod(int* x, int k, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
		if (x[i] == k)
			j++;
	return j;
}

void delsave(int* x, int k, int& (n))
{
	for (int i = k; i < n - 1; i++)
		x[i] = x[i + 1];
	x[n] = 0;
	n--;
}

void del(int* x, int k, int& (n))
{
	x[k] = x[n - 1];
	n--;
}

void delall(int* x, int a, int& (n))
{
	for (int i = 0; i < n - 1; i++) {
		if (x[i] == a) {
			for (int j = i; j < n - 1; j++)
				x[j] = x[j + 1];
			n--;
			i--;
		}
	}
}

void weirdsort(int* x, int n)
{
	int k = 0, s = x[0], c;
	for (int i = 1; i < n; i++) {
		if (x[i] < s) {
			c = x[i];
			for (int j = i; j > k; j--)
				x[j] = x[j - 1];
			x[k] = c;
			k++;
		}
	}
}