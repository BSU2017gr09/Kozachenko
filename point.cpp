//класс координат точки
#include<iostream>
#include<cmath>
using namespace std;

class Point{
public: double x;
		double y;
		Point() : x(0), y(0) {  }
		Point(Point &other) {
			x = other.x;
			y = other.y;
		}
		Point(double a, double b = 0) : x(a), y(b) { }
		~Point() {  }
		Point& operator= (const Point &other) { x = other.x; y = other.y; return *this; }
		
		//координаты суммы 2-х точек - сумма их координат
		Point operator+(const Point &other) { Point tmp; tmp.x = x + other.x; tmp.y = y + other.y;  return tmp; }
		
		//разность точек- разность площадей окружностей
		Point operator-(const Point &other) {
			double tmp; Point r;
			r.x = sqrt(this->x * this->x + this->y * this->y);
			r.y = sqrt(other.x * other.x + other.y * other.y);
			tmp = 3.14 * (r.x * r.x - r.y * r.y);
			cout << "\nразность точек = ";
			cout << tmp << endl;
			return tmp;
		}
		//произведение 2-х точек - скалярное произведение векторов
		Point operator*(const Point &other) {
			double tmp;
			Point r;
			tmp = this->x * other.x + this->y * other.y;
			cout << "произведение точек = " << tmp << endl;
			return tmp;
		}

		//частное 2-х точек - отношение радиус-векторов 
		Point operator/(const Point &other) {
			double tmp;
			tmp = sqrt(this->x * this->x + this->y * this->y) / sqrt(other.x * other.x + other.y * other.y);
			cout << "частное 2-х точек = " << tmp << endl;
			return tmp;
		}
		
		friend ostream& operator<<(ostream &mystream, Point &tmp) { 
			int n;
			cout << "какие координаты вы желаете вывести?" << endl << "1 - декартовы\n2 - полярные\n";
			cin >> n;
			switch (n) {
			case 1:
				mystream << "( " << tmp.x << ", " << tmp.y << " )\n"; break;
			case 2:
				mystream << "радиус = " << tmp.x * tmp.x + tmp.y * tmp.y << "\nугол = " << atan(tmp.y / tmp.x); break;
			default:
				cout << "неверный номер операции\n"; mystream << "( " << tmp.x << ", " << tmp.y << " )\n"; break;
			}
			return mystream;
		}
		friend istream& operator>>(istream &mystream, Point &tmp) { 
			cout << "введите x: \n";
			mystream >> tmp.x;
			cout << "введите y: \n";
			mystream >> tmp.y;
			return mystream; 
		}

};

int main() {
	setlocale(LC_ALL, "ru");
	Point a;
	Point b;
	Point c;
	Point d;
	Point w;
	Point r;
	cout << "введите координаты точек: \n";
	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	c = a - b;
	d = a + b;
	cout << "сумма точек = " << d << endl;
	w = a * b;
	r = a / b;
	system("pause");
	return 0;
}