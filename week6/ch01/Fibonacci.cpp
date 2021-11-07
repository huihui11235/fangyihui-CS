#include <iostream>
using namespace std;

class Matrix {
	public:
		int n;
		int **m;
		Matrix(int num) {
			m = new int *[num];
			for (int i = 0; i < num; i++) {
				m[i] = new int[num];
			}
			n = num;
			clear();
		}
		void clear() {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					m[i][j] = 0;
				}
			}
		}
		void unit() {
			clear();
			for (int i = 0; i < n; ++i) {
				m[i][i] = 1;
			}
		}
		Matrix operator=(const Matrix mtx) {
			Matrix(mtx.n);
			for (int i = 0; i < mtx.n; ++i) {
				for (int j = 0; j < mtx.n; ++j) {
					m[i][j] = mtx.m[i][j];
				}
			}
			return *this;
		}
		Matrix operator*(const Matrix &mtx) {
			Matrix result(mtx.n);
			result.clear();
			for (int i = 0; i < mtx.n; ++i) {
				for (int j = 0; j < mtx.n; ++j) {
					for (int k = 0; k < mtx.n; ++k) {
						result.m[i][j] += m[i][k] * mtx.m[k][j];
					}
				}
			}
			return result;
		}
};

int main(int argc, const char *argv[]) {
	unsigned int num = 2;
	Matrix first(num);
	first.m[0][0] = 1;
	first.m[0][1] = 1;
	first.m[1][0] = 1;
	first.m[1][1] = 0;
	int t;
	cin >> t;
	Matrix result(num);
	result.unit();
	int n = t - 2;
	while (n) {
		if (n % 2) {
			result = result * first;
		}
		first = first * first;
		n = n / 2;
	}
	cout << (result.m[0][0] + result.m[0][1]) << endl;
	return 0;
}

