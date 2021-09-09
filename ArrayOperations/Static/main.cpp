#include <iostream>
#include "StatArray.h"
#include <ctime>
#include <random>
using namespace std;

bool flag(int n)
{
	if ((n < 100) && (n > 0))
		return true;
	return false;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int x[100];
	int n, z, a, k;
	cout << "Введите размер массива" << endl;
	cin >> n;
	if (flag(n)) {
		cout << "Выберите вариант заполнение массива (Введите число с клавиатуры: 1 - запись вручную, 0 - заполнить массив случайными числами)" << endl;
		cin >> z;
		if (z == 1) input(x, n);
		else random(x, n);
		output(x, n);
		cout << "Список команд\n1 - Вставка числа \n2 - Линейный поиск числа \n3 - Номер первого вхождения\n4 - Количество заданных элементов\n5 - Удалить элемент, сохранив порядок\n6 - Удалить элемент без сохранения порядка\n7 - Удалить все элементы, равные заданному\n8 - Переместить все элементы меньше первого в начало\n";
		cin >> z;
		switch (z) {
		case 1:
			cout << "Введите число, которое нужно вставить: ";
			cin >> a;
			cout << "Введите индекс, куда его нужно вставить: ";
			cin >> k;
			if ((k >= 0) & (k < n)) {
				insert(x, k, a, n);
				output(x, n);
			}
			else cout << "Некорректный ввод!";
			break;
		case 2:
			cout << "Введите искомое число: ";
			cin >> a;
			linpoisk(x, a, n);
			break;
		case 3:
			cout << "Введите искомое число: ";
			cin >> a;
			if (pervhod(x, a, n) >= 0)
				cout << "Индекс вашего числа: " << pervhod(x, a, n);
			else cout << "Элемент не найден!";
			break;
		case 4:
			cout << "Введите искомое число: ";
			cin >> a;
			if (kolvovhod(x, a, n) >= 0)
				cout << "Количество найденных элементов: " << kolvovhod(x, a, n);
			else cout << "Элементы не найдены!";
			break;
		case 5:
			cout << "Введите индекс элемента, который нужно удалить: ";
			cin >> k;
			if ((k >= 0) & (k < n)) {
				delsave(x, k, n);
				output(x, n);
			}
			else cout << "Некорректные данные!";
			break;
		case 6:
			cout << "Введите индекс элемента, который нужно удалить: ";
			cin >> k;
			if ((k >= 0) & (k < n)) {
				del(x, k, n);
				output(x, n);
			}
			else cout << "Некорректные данные!";
			break;
		case 7:
			cout << "Введите значение, которое нужно удалить: ";
			cin >> a;
			delall(x, a, n);
			output(x, n);
			break;
		case 8:
			weirdsort(x, n);
			output(x, n);
			break;
		}
	}
	else cout << "Некорректный размер массива!";
}