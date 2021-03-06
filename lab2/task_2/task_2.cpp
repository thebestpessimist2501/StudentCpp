
#include "stdafx.h"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void PrintResult(list <double> arr, char arr1[], int k) {
	list <double> :: iterator f = arr.begin();
	double result = *f;
	for (int i = 0; i <= (k - 2); i++)
	{
		char sign = arr1[i];
		f++;
		switch (sign) {
		case '+':
			result += (*f);
			break;
		case '-':
			result -= (*f);
			break;
		case '*':
			result *= (*f);
			break;
		case '/':
			result /= (*f);
			break;
		}
	}
	cout << result;
}

int ZeroCheck(char s[255]) {
	int j = 0;
	for (int m = 0; m < strlen(s); m++)
	{
		if ((s[m] != '0') && (s[m] != ',')) 
		return 0;
		else if (s[m] == '0') j++;
	}
	if (j != 0)
	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите числа (end - окончание ввода) : " << endl;

	bool flag = true;
	char str[255];
	int i = 0;
	double num;
	list <double> arr_num;

	do {
		cin.getline(str, 255);
		num = atof(str);
		if ((num / 1 != NULL) || (ZeroCheck(str) == 1)) {
			arr_num.push_back(num);
			i++;
		}
		else {
			if ((str[0] == 'e') && (str[1] == 'n') && (str[2] == 'd') == true)
				flag = false;
			else cout << "Некорректный ввод. Введите число заново " << endl;
		}
	} while (flag == true);

	if (i == 0) return 0;
	if (i != 1) cout << "\nВведите действия над числами : ";
	char *arr_signs = new char[i - 1];
	bool error;

	do {
		error = false;
		for (int k = 0; k <= (i - 2); k++) {
			cin >> arr_signs[k];
			if (((arr_signs[k] == '+') || (arr_signs[k] == '-') ||
				(arr_signs[k] == '*') || (arr_signs[k] == '/')) == 0)
				error = true;
		}
		if (error == true)
			cout << "Некорректный ввод. Попробуйте заново" << endl;
	} while (error == true);

	cout << "Результат: ";
	PrintResult(arr_num, arr_signs, i);
	delete[] arr_signs;
	cout << "\nНажмите любую клавишу для завершения программы\n";
	system("pause");
	return 0;
}

