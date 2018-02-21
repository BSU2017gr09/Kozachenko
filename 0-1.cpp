//� ������� ������� N, ������������ ����.������� �� 0 �� 10, ���������� ���������� ���������, ������������� ����� ������ ����.
#include <iostream>
using namespace std;

int* initMemory(const int);
void initArray(int*, const int);
void printArray(int*, const int);
bool containNumber(int*, int, const int);
int quantityRepeat(int*, const int);

const int TEMP = 11;

int main() {
	setlocale(LC_ALL, "ru");
	int N = 0;
	cout << "������� ������ �������: ";
	cin >> N;
	int* Array = initMemory(N);
	initArray(Array, N);
	printArray(Array, N);
	cout << endl << "���������� ���������, ������������� ����� ������ ����:" << quantityRepeat(Array, N);
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
		cout << "������!";
		system("pause");
		main();
	}
}

void initArray(int* A, const int N) {
	for (int* p = A; p < A + N; p++) {
		*p = rand() % TEMP;
	}
}

void printArray(int* A, const int N) {
	cout << "�������� �������:\n";
	for (int* p = A; p < A + N; p++) {
		cout << *p << " ";
	}
}

bool containNumber(int* A, int length, const int number) {
	for (int* p = A; p < A + length; p++) {
		if (*p == number) return true;
	}
	return false;
}

int quantityRepeat(int *A, const int N) {
	int count = 0;
	int* temp = initMemory(N / 2);
	for (int* p = A; p < A + N; p++) {
		for (int* q = p + 1; q < A + N; q++) {
			if ((*p == *q) && !containNumber(temp, count, *p)) {
				*temp = *p;
				temp++;
				count++;
			}
		}
	}
	return count;
}

