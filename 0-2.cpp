//� ������� ������� N, ������������ ����.������� �� 0 �� 10, 
//���������� ������������ ����� ������������������ ������ ���������.
#include <iostream>
using namespace std;
void initArray(int *, const int);
void printArray(int *, const int );
void MaxLen(int *, const int );
int main() {
	setlocale(LC_ALL, "ru");
	int *A;
	int N;
	cout << "������� ������ �������: ";
	cin >> N;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "������: ���������� ������� ����� ������.";
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
	cout << "�������� �������:\n";
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
	cout << "������������ ����� ������������������ ������ ���������: " << lenMax << endl;
}
