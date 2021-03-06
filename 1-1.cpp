//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента
#include<iostream>
using namespace std;

int* initMemory(const int);
void initArray(int *, const int);
void printArray(int *, const int);
void swap(int *, int *);
void sortArray(int*, const int, int);

int main() {
	setlocale(LC_ALL, "ru");
	int N = 0;
	int k = 0;
	cout << "Введите размер массива: ";
	cin >> N;
	int* Array = initMemory(N);
	initArray(Array, N);
	printArray(Array, N);
	cout << "Введите номер элемента массива: ";
	cin >> k;
	sortArray(Array, N, k);
	printArray(Array, N);
	system("pause");
	delete[] Array;
	return 0;
}

int* initMemory(const int N) {
	try {
		int* temp = new int[N];
		for (int *p = temp; p < temp + N; p++) {
			*p = 0;
		}
		return temp;
	}
	catch (...) {
		cout << "Ошибка!";
		system("pause");
		main();
	}
}

void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand();
	}
}

void printArray(int* A, const int N) {
	cout << "Элементы массива:\n";
	for (int* p = A; p < A + N; p++) {
		cout << *p << " ";
	}
}

void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}

void sortArray(int *A, const int N, int k) {
	for (int *p = (A + k - 1); p < A + N; p++) {
		for (int *k = p; k < A + N; k++) {
			if (*p > *k) {
				swap(*k, *p);
			}
		}
	}
}
