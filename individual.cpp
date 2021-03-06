//В массиве А(N,M) переставить строки в порядке возрастания элементов последнего столбца.
#include <iostream>
#include<iomanip>
using namespace std;

typedef void menu(int**, int, int);

void  giveMemory(int ** &, const int , const int );
void initArray(int **, int , int );
void printArray(int **, int , int );
void freeMemory(int **, const int );
void lastcolumn(int **, int , int );
void help(int **, int, int);
void exit(int **, int, int);

int main() {
	setlocale(LC_ALL, "Ru");
	int n, N, M;
	int**A = nullptr;
	cout << "Введите размер:";
	cin >> N >> M;
	menu *Fmenu[4] = { exit, help, printArray, lastcolumn };
	giveMemory(A, N, M);
	initArray(A, N, M);
	while (true) {
		cout << "введите номер операции\n 0 - exit \n 1 - help \n 2 - исходный массив \n 3 - результат \n";
		cin >> n;
		if (n > 4 || n < 0) n = 0;
		(*Fmenu[n])(A, N, M);
	}
	printArray(A, N, M);
	lastcolumn(A, N, M);
	freeMemory(A, N);
	system("pause");
	return 0;
}

void  giveMemory(int** &A, const int N, const int M) {
	try { A = new int*[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}

	for (int i = 0; i<M; i++) {
		try { A[i] = new int[M]; }
		catch (...) {
			cout << "Ошибка: невозможно создать очередную строку.";
			exit(0);
		}
	}
}

void exit(int**, int, int) {
	exit(0);
}

void help(int**, int, int) {
	cout << "В массиве А(N,M) переставляет строки в порядке возрастания элементов последнего столбца.";
}

void initArray(int **A, int N, int M) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			A[i][j] = rand() % 30;
		}
	}
}
void printArray(int **A, int N, int M) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
}
void freeMemory(int **A, const int N) {
	for (int i = 0; i<N; i++) {
		delete[]A[i];
	}
}

void lastcolumn(int **A, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j<N; j++) {
			if (A[j][M - 1] < A[i][M - 1]) {
				swap(A[j], A[i]);
			}
		}
	}
	printArray(A, N, M);
}