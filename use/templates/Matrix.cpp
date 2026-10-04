#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T, int N, int M>
class Matrix {
	T* matrix;

public:
	Matrix() {
		matrix = new T[N * M];
	}

	void set(int row, int col, T value) {
		*(matrix + row * M + col) = value;
	}

	T get(int row, int col) const {
		return *(matrix + row * M + col);
	}

	Matrix operator+(const Matrix& other) {
		Matrix result;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				result.set(i, j, get(i, j) + other.get(i, j));
			}
		}

		return result;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << *(matrix + i * M + j) << " ";
			}
			std::cout << "\n";
		}
	}

	~Matrix() {
		delete[] matrix;
	}
};

int main() {
	Matrix<int, 2, 3> a;
	Matrix<int, 2, 3> b;

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(0, 2, 3);
	a.set(1, 0, 4);
	a.set(1, 1, 5);
	a.set(1, 2, 6);

	b.set(0, 0, 10);
	b.set(0, 1, 20);
	b.set(0, 2, 30);
	b.set(1, 0, 40);
	b.set(1, 1, 50);
	b.set(1, 2, 60);

	Matrix<int, 2, 3> c = a + b;

	c.print();

	assert(a.get(0, 0) == 1);
	assert(a.get(1, 2) == 6);

	assert(c.get(0, 0) == 11);
	assert(c.get(0, 1) == 22);
	assert(c.get(0, 2) == 33);
	assert(c.get(1, 0) == 44);
	assert(c.get(1, 1) == 55);
	assert(c.get(1, 2) == 66);


	Matrix<double, 2, 3> d;
	Matrix<double, 2, 3> e;

	d.set(0, 0, 1.5);
	d.set(0, 1, 2.7);
	d.set(0, 2, 3.14);
	d.set(1, 0, 4.8);
	d.set(1, 1, 5.25);
	d.set(1, 2, 6.9);

	e.set(0, 0, 10.2);
	e.set(0, 1, 20.3);
	e.set(0, 2, 30.4);
	e.set(1, 0, 40.5);
	e.set(1, 1, 50.6);
	e.set(1, 2, 60.7);

	Matrix<double, 2, 3> f = d + e;

	f.print();

	assert(std::abs(f.get(0, 0) - 11.7) < 0.000001);
	assert(std::abs(f.get(0, 1) - 23.0) < 0.000001);
	assert(std::abs(f.get(0, 2) - 33.54) < 0.000001);
	assert(std::abs(f.get(1, 0) - 45.3) < 0.000001);
	assert(std::abs(f.get(1, 1) - 55.85) < 0.000001);
	assert(std::abs(f.get(1, 2) - 67.6) < 0.000001);


	Matrix<std::string, 2, 3> x;
	Matrix<std::string, 2, 3> y;

	x.set(0, 0, "abhdabfuha ");
	x.set(0, 1, "hsbfbdh ");
	x.set(0, 2, "jshhs ");
	x.set(1, 0, "qweqwe ");
	x.set(1, 1, "zxczxc ");
	x.set(1, 2, "mnvbnv ");

	y.set(0, 0, "hello ");
	y.set(0, 1, "world ");
	y.set(0, 2, "cpp ");
	y.set(1, 0, "matrix ");
	y.set(1, 1, "test ");
	y.set(1, 2, "abc ");

	Matrix<std::string, 2, 3> z = x + y;

	z.print();

	assert(z.get(0, 0) == "abhdabfuha hello ");
	assert(z.get(0, 1) == "hsbfbdh world ");
	assert(z.get(0, 2) == "jshhs cpp ");
	assert(z.get(1, 0) == "qweqwe matrix ");
	assert(z.get(1, 1) == "zxczxc test ");
	assert(z.get(1, 2) == "mnvbnv abc ");


	Matrix<int, 1, 1> one;
	one.set(0, 0, 5);

	assert(one.get(0, 0) == 5);

	Matrix<int, 1, 1> two;
	two.set(0, 0, 10);

	Matrix<int, 1, 1> three = one + two;

	assert(three.get(0, 0) == 15);

	return 0;
}