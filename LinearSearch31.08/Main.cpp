#include <iostream>
using namespace std;

template <typename T>
void show_arr(T arr[], const int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)		
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

	// Поиск первого вхождения
template <typename T>
int search_index(T arr[], const int lenght, T value, int begin = 0) {	// begin для указа позиции в массиве. i = begin (с позиции цикл начинаем)
	for (int i = begin; i < lenght; i++)
		if (arr[i] == value)
			return i;
	return -1;															// если элемента нет в массиве, то добавляем -1
}

	// Поиск последнего вхождения
template <typename T>
int search_last_index(T arr[], const int size, T value) {
	for (int i = size - 1; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}
template <typename T>
int search_last_index(T arr[], const int size, T value, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

	// Задание
void subWord(char arr[], const int lenght, char sym) {
	int index = search_index(arr, lenght, sym);
	if (index == -1)		// если символа нет в массиве
		cout << "ERROR";
	else {
		for (int i = index; i < lenght; i++)
			cout << arr[i];
		cout << endl;
	}
	
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Линейный поиск
	const int size = 6;
	int arr[size] = { 4, 7, -1, 8, 7, 0 };
	cout << "Массив:\n";
	show_arr(arr, size);
	
	cout << "Введите число: ";
	cin >> n;

	// Поиск первого вхождения
	if (search_index(arr, size, n, 2) == -1)
		cout << "Такого числа нет в массиве.\n\n";
	else
		cout << "Позиция числа в массиве: " <<	search_index(arr,size,n,2) << ".\n\n";

	// Поиск последнего вхождения
	if (search_last_index(arr, size, n, 3) == -1)
		cout << "Такого числа нет в массиве.\n\n";
	else
		cout << "Позиция последнего вхождения числа в массив: " << search_last_index(arr, size, n, 3) << ".\n\n"; 

	// Задание "Подслово"
	const int word_size = 8;
	char word_arr[word_size] = { 'f', 'u', 'n', 'c', 't', 'i','o', 'n'};
	cout << "Введите символ: ";
	char sym;
	cin >> sym;
	cout << "Подслово:\n";
	subWord(word_arr, word_size, sym);
	cout << endl;

	return 0;
}