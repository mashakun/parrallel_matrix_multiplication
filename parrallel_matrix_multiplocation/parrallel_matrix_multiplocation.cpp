#include "Header.h"
#include "tests.h"

#include <vector>;
#include <cstdlib>;
#include <iostream>
//const int n = 1000;
//const int r = 1000;

int* fillMatrix(const int n) {
	int* M = new int[n * n];
	const int min = -100;
	const int max = 100;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i * n + j] = min + std::rand() % (max + 1 - min);
		}
	}

	return M;
}

int main() {
	//runAllTests();
	const int n[10] = { 100, 250, 500, 1000, 1024, 1500, 1750, 2000, 2048, 2250};
	//const int r[10] = {2, 5, 10, 16, 20, 32, 50, 100, 200, 500};

	std::vector<std::vector<int>> r(10);
	r[0] = { 2, 5, 10, 20, 50 };
	r[1] = { 2, 5, 10, 50 };
	r[2] = { 2, 5, 10, 20, 50, 100, 250 };
	r[3] = { 2, 5, 10, 20, 50, 100, 250 };
	r[4] = { 2, 32, 64, 128 };
	r[5] = { 2, 5, 10, 20, 50, 100, 250, 500 };
	r[6] = { 2, 5, 10, 50, 250 };
	r[7] = { 2, 5, 10, 20, 50, 100, 250, 500 };
	r[8] = { 2, 32, 64, 128, 512 };
	r[9] = { 2, 5, 10, 50, 250 };


	for (int i = 0; i < 10; i++) {
		int* A = fillMatrix(n[i]);
		int* B = fillMatrix(n[i]);

		std::cout << "=============== n = " << n[i] << " =================\n";
		std::cout << "--------------- canon ---------------\n";
		int* C1 = canon(A, B, n[i]);
		delete[] C1;
		std::cout << "--------------- canon_internal ---------------\n";
		int* C2 = canon_internal(A, B, n[i]);
		delete[] C2;
		std::cout << "--------------- canon_external ---------------\n";
		int* C3 = canon_external(A, B, n[i]);
		delete[] C3;
		std::cout << '\n\n';


		delete[] A;
		delete[] B;
	}


	return 0;
}
