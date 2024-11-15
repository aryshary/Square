#include <iostream>
#include <windows.h>
#include <exception>
#include <cmath>

using namespace std;

class figures {
protected:
	float a;
public:
	figures(float i_a) {
		if (i_a <= 0) {
			throw - 1;
		}
		a = i_a ;
	}

	virtual float S() {
		return a*a;
	}
};

class rectangle : public figures {
	float b;
public:
	rectangle(float i_a, float i_b) : figures(i_a) {
		if (i_b <= 0) {
			throw - 1;
		}
		b = i_b;
	}

	virtual float S() override {
		return a * b;
	}
};

class circle : public figures {
public:
	circle(float i_r) : figures(i_r) {}
	virtual float S() override {
		return 3.14 * a * a;
	}
};

class triangle : public figures {
	float b;
	float c;
public:
	triangle(float i_a, float i_b, float i_c) : figures(i_a) {
		if (i_b <= 0) {
			throw - 1;
		}
		b = i_b;
		c = i_c;
	}

	virtual float S() override {
		if (a + b <= c || a + c <= b || b + c <= a) {
			throw 'a';
		}
		return 0.5 * a * b;
	}
};

class trapeze : public figures {
	float b;
	float h;
public:
	trapeze(float i_a, float i_b, float i_h) : figures(i_a) {
		if (i_b <= 0 || i_h <= 0) {
			throw - 1;
		}
		b = i_b;
		h = i_h;
	}

	virtual float S() override {
		return 0.5 * (a + b) * h;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		rectangle rectangle(4.5, 2.5);
		circle circle(3.5);
		triangle triangle(1.5, 20.5, 2.7);
		trapeze trapeze(5.5, 2.5, 1.5);

		figures* figure[] = { &rectangle, &circle, &triangle, &trapeze };
		for (int i = 0; i < 4; i++) {
			cout << figure[i]->S() << endl;
		}
	}
	catch (int) {
		cerr << "Значення повинне бути додатнім!\n";
	}
	catch (char) {
		cerr << "Трикутник не може існувати!\n";
	}
	
}