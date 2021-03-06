//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include<iostream>
using namespace std;

int* initMemory(const int);
void initArray(int *, const int);
void printArray(int *, const int);
void sortArray(int *, const int);

int main() {
	setlocale(LC_ALL, "ru");
	int N = 0;
	cout << "Введите размер массива: ";
	cin >> N;
	int* Array = initMemory(N);
	initArray(Array, N);
	printArray(Array, N);
	sortArray(Array, N);
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
		*p = rand() % 101 - 50;
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

void sortArray(int *A, const int N) {
	for (int *p = (A + N - 1); p >= A; p--) {
		for (int *k = p; k >= A; k--) {
			if (*p < 0) {
				swap(*p, *k);
			}
		}
	}
	for (int *p = A; p < A + N, *p<0; p++) {
		for (int *k = p; k < A + N; k++) {
			if (*p > *k) {
				swap(*k, *p);
			}
		}
	}

}

