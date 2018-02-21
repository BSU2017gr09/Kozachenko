//В массиве размера N, заполненного случ.числами от 0 до 10, 
//определить максимальную длину последовательности равных элементов.
#include <iostream>
using namespace std;
void initArray(int *, const int);
void printArray(int *, const int );
void MaxLen(int *, const int );
int main() {
	setlocale(LC_ALL, "ru");
	int *A;
	int N;
	cout << "Введите размер массива: ";
	cin >> N;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Ошибка: невозможно создать такой массив.";
		return 1;
	}
	initArray(A, N);
	printArray(A, N);
	MaxLen(A, N);
	system("pause");
	delete[] A;
	return 0;
}
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}
void printArray(int *A, const int N) {
	cout << "Элементы массива:\n";
	for (int *p = A; p < A + N; p++) {
		cout << *p << endl;
	}
}
void MaxLen(int *A,  const int N) {
	int lenNow = 0, lenMax = 0;
	for (int *p = A; p < A + N-1; p++) {
		if (*p == *(p + 1)) lenNow++;
		else {
			if (lenNow > lenMax) lenMax = lenNow;
			else lenNow = 1;
		}
	}
	cout << "Максимальная длина последовательности равных элементов: " << lenMax << endl;
}
