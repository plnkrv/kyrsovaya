#include "course.h"
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

const int N = 100;

//1 (создание рандомного массива от -99 до 99)
void main1(int arr[], int sort_arr[])
{
	setlocale(0, "");
	for (int i = 0; i < N; i++)
	{
		int start = -99;
		int end = 99;
		arr[i] = rand() % (end - start + 1) + start;
		sort_arr[i] = arr[i];
	}
}

//1.1 (сортировка bubble sort)
void bubble_sort(int bub[]) {

	auto start_time = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N - (i + 1); j++) {
			if (bub[j] > bub[j + 1]) {
				flag = false;
				swap(bub[j], bub[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	auto end_time = chrono::high_resolution_clock::now();

	auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	cout << "Отсортированный массив в порядке возрастания: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "[" << bub[i] << "]" << " ";
	}
	cout << endl;
	cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}

//1.2 (сортировка shaker sort)
void shaker_sort(int sh[])
{
	bool sort_or_not = true;
	int right = N - 1;
	int left = 1;
	auto start_time = chrono::high_resolution_clock::now();
	do {
		bool sort_or_not = true;
		for (int i = left; i <= right; i++)
		{
			if (sh[i - 1] > sh[i])
			{
				swap(sh[i - 1], sh[i]);
				sort_or_not = false;
			}
		}
		right--;
		for (int i = right; i >= left; i--)
		{
			if (sh[i] < sh[i - 1])
			{
				swap(sh[i], sh[i - 1]);
				sort_or_not = false;
			}
		}
		left++;
	} while (sort_or_not == false);
	auto end_time = chrono::high_resolution_clock::now();


	auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	cout << "Отсортированный массив в порядке возрастания: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "[" << sh[i] << "]" << " ";
	}
	cout << endl;
	cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}

//1.3 (Сортировка comb sort)
int getNextGap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap < 1)
		return 1;
	return gap;
}
void comb_sort(int cm[])
{

	int gap = N;
	bool swapped = true;
	auto start_time = chrono::high_resolution_clock::now();
	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;
		for (int i = 0; i < N - gap; i++)
		{
			if (cm[i] > cm[i + gap])
			{
				swap(cm[i], cm[i + gap]);
				swapped = true;
			}
		}
	}
	auto end_time = chrono::high_resolution_clock::now();

	auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	cout << "Отсортированный массив в порядке возрастания: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "[" << cm[i] << "]" << " ";
	}
	cout << endl;
	cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}

//1.4 (Сортирповка insert sort)
void insert_sort(int is[])
{

	int i, key, j;
	auto start_time = chrono::high_resolution_clock::now();
	for (i = 1; i < N; i++)
	{
		key = is[i];
		j = i - 1;

		while (j >= 0 && is[j] > key)
		{
			is[j + 1] = is[j];
			j = j - 1;
		}
		is[j + 1] = key;
	}
	auto end_time = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	cout << "Отсортированный массив в порядке возрастания: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "[" << is[i] << "]" << " ";
	}
	cout << endl;
	cout << "Время сортировки: " << result.count() << " микросекунд" << endl;
}


//2. Отсортировать заданный в пункте 1 массив […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку.
void sort_m()
{
	cout << "Варианты сортировок: " << endl;
	cout << "1.Bubble sort" << endl;
	cout << "2.Shaker sort" << endl;
	cout << "3.Comb sort" << endl;
	cout << "4.Insert sort" << endl;
}
void sort(int a[])
{
	sort_m();
	int b;
	cout << endl;
	cout << "Выберите номер сортировки: ";
	cin >> b;
	switch (b)
	{
	case 1:
		bubble_sort(a);
		break;
	case 2:
		shaker_sort(a);
		break;
	case 3:
		comb_sort(a);
		break;
	case 4:
		insert_sort(a);
		break;
	}
	cout << endl;
}

//3. Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном.
void maxmin(int arr[], int sort_arr[])
{

	int max = arr[0];
	int min = arr[0];
	auto start_time1 = chrono::high_resolution_clock::now();
	for (int i = 1; i < N; i++)
	{
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	auto end_time1 = chrono::high_resolution_clock::now();

	auto start_time = chrono::high_resolution_clock::now();
	bubble_sort(sort_arr);
	int minik, maxik;
	minik = sort_arr[0],
		maxik = sort_arr[99];
	cout << "Минимальный элемент массива: " << minik << endl;
	cout << "Максимальный элемент массива: " << maxik << endl;
	auto end_time = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

	cout << "Поиск в неотсортированном массиве: " << result.count() << " микросекунд" << endl;
	auto result1 = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	cout << "Поиск в отсортированном массиве: " << result1.count() << " микросекунд" << endl;
	cout << endl;
}

//4. Выводит среднее значение максимального и минимального значения в отсортированном и неотсортированном.Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска.
void srznach(int arr[])
{

	for (int i = 0; i < N; i++)
	{
		int start = -99;
		int end = 99;
		arr[i] = rand() % (end - start + 1) + start;

	}
	for (int i = 0; i < N; i++)
	{
		cout << "[" << arr[i] << "]" << " ";

	}
	cout << endl;
	int b = (arr[0] + arr[N - 1]) / 2;
	cout << "Среднее значение максимального и минимального значения в неотсортированном массиве:" << endl;
	cout << b << endl;

	bubble_sort(arr);

	int a = (arr[0] + arr[N - 1]) / 2;
	cout << "Среднее значение максимального и минимального значения в отсортированном массиве:" << endl;
	cout << a << endl;

	int i = N - 1;
	while (arr[i] > a)
	{
		i /= 2;
	}
	int k = 0;
	cout << "Индексы всех элементов, которые равны этому значению: " << endl;
	auto start_time = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == a)
		{
			cout << i << " ";
			k++;
		}
	}

	auto end_time = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	if (k == 0) cout << "Значения не найдены" << endl;
	cout << "Количество элементов: " << k << endl;
	cout << "Время поиска: " << result.count() << " микросекунд" << endl;
	cout << endl;
}
//5. Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.
void kol_mense(int arr[])
{
	bubble_sort(arr);
	int a;
	cout << "Введите число а:" << endl;
	cin >> a;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < a)
		{
			count++;
		}
	}
	cout << "Количество элементов меньше " << a << ": " << count << endl;
	cout << endl;
}
//6. Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.
void kol_bolse(int arr[])
{
	bubble_sort(arr);
	int b;
	cout << "Введите число b:" << endl;
	cin >> b;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] > b)
		{
			++count;
		}
	}
	cout << "Количество элементов больше " << b << ": " << count << endl;
	cout << endl;
}

//8.  Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.
void mesta(int arr[])
{

	bubble_sort(arr);
	cout << "Введите индексы элементов для обмена: " << endl;
	int i1, i2;
	cin >> i1 >> i2;
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		temp = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = temp;
	}
	auto end = chrono::high_resolution_clock::now();
	auto result = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Скорость обмена: " << 100000.0 / result.count() << " обменов в секунду" << endl;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "[" << arr[i] << "]" << " ";
	}
	cout << endl;
	cout << endl;
}
//идз. 
void idz(int arr[]) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum = sum + arr[i];
	}

	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] + arr[(i + 1) % N];
	}

	int count[10] = { 0 };

	for (int i = 0; i < N; i++) {
		count[abs(arr[i] % 10)]++;
	}

	cout << "Количество элементов, которые делятся на 1, 2, 3, 4, 5, 6, 7, 8, 9:" << endl;
	cout << endl;
	for (int i = 1; i < 10; i++) {
		cout << "Элементов, делящихся на " << i << ": " << count[i] << endl;
	}
	cout << endl;
}


void course2()
{
	setlocale(0, "");
	int choice;
	bool p = true;
	int arr[N], sort_arr[N];
	main1(arr, sort_arr);
	while (p)
	{
		cout << "Выберите номер задания:" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 0:
			cout << "Конец";
			break;
		case 1:
			main1(arr, sort_arr);
			for (int i = 0; i < N; i++)
			{
				cout << "[" << arr[i] << "]" << " ";
			}
			cout << endl;
			cout << endl;
			break;
		case 2:
			sort(sort_arr);
			break;
		case 3:
			maxmin(arr, sort_arr);
			break;
		case 4:
			srznach(arr);
			break;
		case 5:
			kol_mense(arr);
			break;
		case 6:
			kol_bolse(arr);
			break;
		case 8:
			mesta(arr);
			break;
		case 9:
			idz(arr);
			break;
		}
	}
}
