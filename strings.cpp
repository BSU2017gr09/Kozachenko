//В строке удалить все слова, содержащие заданную букву ровно два раза.
#include<iostream>
#include<cstring>
#pragma warning(disable : 4996)
using namespace std;

typedef char menu(char*, char);

char* initMemory(const int );
char exit(char* , char);
char input(char* , char);
char *wordCut(char* , unsigned int);
char output(char* , char);
char help(char* , char );
void clearMemory(char*, int);

const int MAX = 255;

int main() {
	setlocale(LC_ALL, "Ru");
	char str[MAX];
	char k;
	menu *q = nullptr;
	int n;
	cout << "Введите символ: ";
	cin >> k;
	menu *Fmenu[4] = { exit, help, input, output };
	while (true) {
		cout << "введите номер операции\n 0 - exit \n 1 - help \n 2 - ввести строку \n 3 - вывести результат \n";
		cin >> n;
		if (n > 4 || n < 0) n= 0;
		(*Fmenu[n])(str, k);
	}
	clearMemory(str, MAX);
	system("pause");
	return 0;
}

char* initMemory(const int MAX) {
	char* str;
	try {
		str = new char[MAX];
	}
	catch (...) {
		cout << "Ошибка! Невозможно создать такой массив.";
		exit(0);
	}
	return str;
}

char exit(char* , char) {
	exit(0);
}

char input(char* str, char) {
	fflush(stdin);
	cout << "Вводите строку:";
	while (true) {
		cin.getline(str, MAX);
		if (strlen(str)) break;
	}
	return 0;
}

char *wordCut(char *S1, unsigned int b) {
	char S3[MAX];
	strncpy(S3, S1, b);
	*(S3 + b) = ' ';
	*(S3 + b + 1) = '\0';
	return S3;
}

char output(char* str, char k) {
	char pat[6] = "., !?";
	char* result = new char[MAX] { '\0' };
	char* p = str;
	int count = 0;
	while (*p) {
		if (*p == k) count++;
		else {
			if ((*p == ' ') && count == 2)
			{
				count = 0;
				str += strcspn(str, pat) + 1;
			}
			else {
				if (*p == ' ')
				{
					count = 0;
					result = strcat(result, wordCut(str, strcspn(str + 1, pat) + 1));
					str += strcspn(str, pat) + 1;
				}
			}
		}
		p++;
	}
	if (count != 2) {
		result = strcat(result, wordCut(str, strcspn(str + 1, pat) + 1));
	}
	cout << "Ваша строка:" << result << endl;
	return 0;
}

char help(char* , char ) {
	cout << "В строке удаляет все слова, содержащие заданную букву ровно два раза."; 
	return 0;
}

void clearMemory(char *str, int MAX) {
	delete[MAX] str;
}