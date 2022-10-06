#include "Header.h"
#include <vector>
#include <iostream>

bool compareMatrices(int* A, const std::vector<std::vector<int> >& B, int n) {
	if (B.size() != n || B[0].size() != n) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i * n + j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

namespace TEST_CANON {
	bool test1x1() {
		int* A = new int[1];
		A[0] = 2;

		int* B = new int[1];
		B[0] = 3;

		int* C = canon(A, B, 1);
		return compareMatrices(C, { {6} }, 1);
	}

	bool testZero() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 0;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon(A, B, n);

		return compareMatrices(C, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, n);
	}

	bool testIdentity() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 1;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon(A, B, n);

		return compareMatrices(C, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, n);
	}
	
	bool testSome() {

		int n = 5;

		std::vector<std::vector<int> > vecA = {
			{1, 2, 3, 4, 5},
			{0, 1, 3, 2, 1},
			{1, 2, 1, 2, 1},
			{3, 0, 11, 1, 1},
			{1, 1, 1, 1, 1}
		};
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i * n + j] = vecA[i][j];
			}
		}

		std::vector<std::vector<int> > vecB = {
			{5, 0, 3, 1, 1},
			{2, 1, 1, 2, 1},
			{2, 1, 1, 1, 0},
			{0, 1, 0, 0, 1},
			{2, 2, 1, 1, 2}
		};
		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i * n + j] = vecB[i][j];
			}
		}

		int* C = canon(A, B, n);

		return compareMatrices(C, { 
			{25, 19, 13, 13, 17}, 
			{10, 8, 5, 6, 5},
			{13, 7, 7, 7, 7},
			{39, 14, 21, 15, 6},
			{11, 5, 6, 5, 5},
		}
		, n);
	}
}

namespace TEST_CANON_EXTERNAL {
	bool test1x1() {
		int* A = new int[1];
		A[0] = 2;

		int* B = new int[1];
		B[0] = 3;

		int* C = canon_external(A, B, 1);
		return compareMatrices(C, { {6} }, 1);
	}

	bool testZero() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 0;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon_external(A, B, n);

		return compareMatrices(C, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, n);
	}

	bool testIdentity() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 1;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon_external(A, B, n);

		return compareMatrices(C, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, n);
	}

	bool testSome() {

		int n = 5;

		std::vector<std::vector<int> > vecA = {
			{1, 2, 3, 4, 5},
			{0, 1, 3, 2, 1},
			{1, 2, 1, 2, 1},
			{3, 0, 11, 1, 1},
			{1, 1, 1, 1, 1}
		};
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i * n + j] = vecA[i][j];
			}
		}

		std::vector<std::vector<int> > vecB = {
			{5, 0, 3, 1, 1},
			{2, 1, 1, 2, 1},
			{2, 1, 1, 1, 0},
			{0, 1, 0, 0, 1},
			{2, 2, 1, 1, 2}
		};
		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i * n + j] = vecB[i][j];
			}
		}

		int* C = canon_external(A, B, n);

		return compareMatrices(C, {
			{25, 19, 13, 13, 17},
			{10, 8, 5, 6, 5},
			{13, 7, 7, 7, 7},
			{39, 14, 21, 15, 6},
			{11, 5, 6, 5, 5},
			}
		, n);
	}
}

namespace TEST_CANON_INTERNAL {
	bool test1x1() {
		int* A = new int[1];
		A[0] = 2;

		int* B = new int[1];
		B[0] = 3;

		int* C = canon_internal(A, B, 1);
		return compareMatrices(C, { {6} }, 1);
	}

	bool testZero() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 0;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon_internal(A, B, n);

		return compareMatrices(C, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, n);
	}

	bool testIdentity() {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 1;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = canon_internal(A, B, n);

		return compareMatrices(C, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, n);
	}

	bool testSome() {

		int n = 5;

		std::vector<std::vector<int> > vecA = {
			{1, 2, 3, 4, 5},
			{0, 1, 3, 2, 1},
			{1, 2, 1, 2, 1},
			{3, 0, 11, 1, 1},
			{1, 1, 1, 1, 1}
		};
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i * n + j] = vecA[i][j];
			}
		}

		std::vector<std::vector<int> > vecB = {
			{5, 0, 3, 1, 1},
			{2, 1, 1, 2, 1},
			{2, 1, 1, 1, 0},
			{0, 1, 0, 0, 1},
			{2, 2, 1, 1, 2}
		};
		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i * n + j] = vecB[i][j];
			}
		}

		int* C = canon_internal(A, B, n);

		return compareMatrices(C, {
			{25, 19, 13, 13, 17},
			{10, 8, 5, 6, 5},
			{13, 7, 7, 7, 7},
			{39, 14, 21, 15, 6},
			{11, 5, 6, 5, 5},
			}
		, n);
	}
}

namespace TEST_BLOCK_EXTERNAL {
	bool test1x1(int r) {
		int* A = new int[1];
		A[0] = 2;

		int* B = new int[1];
		B[0] = 3;

		int* C = blocked_external(A, B, 1, r);
		return compareMatrices(C, { {6} }, 1);
	}

	bool testZero(int r) {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 0;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = blocked_external(A, B, n, r);

		return compareMatrices(C, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, n);
	}

	bool testIdentity(int r) {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 1;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = blocked_external(A, B, n, r);

		return compareMatrices(C, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, n);
	}

	bool testSome(int r) {

		int n = 5;

		std::vector<std::vector<int> > vecA = {
			{1, 2, 3, 4, 5},
			{0, 1, 3, 2, 1},
			{1, 2, 1, 2, 1},
			{3, 0, 11, 1, 1},
			{1, 1, 1, 1, 1}
		};
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i * n + j] = vecA[i][j];
			}
		}

		std::vector<std::vector<int> > vecB = {
			{5, 0, 3, 1, 1},
			{2, 1, 1, 2, 1},
			{2, 1, 1, 1, 0},
			{0, 1, 0, 0, 1},
			{2, 2, 1, 1, 2}
		};
		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i * n + j] = vecB[i][j];
			}
		}

		int* C = blocked_external(A, B, n, r);

		return compareMatrices(C, {
			{25, 19, 13, 13, 17},
			{10, 8, 5, 6, 5},
			{13, 7, 7, 7, 7},
			{39, 14, 21, 15, 6},
			{11, 5, 6, 5, 5},
			}
		, n);
	}
}


namespace TEST_BLOCK_INTERNAL {
	bool test1x1(int r) {
		int* A = new int[1];
		A[0] = 2;

		int* B = new int[1];
		B[0] = 3;

		int* C = blocked_internal(A, B, 1, r);
		return compareMatrices(C, { {6} }, 1);
	}

	bool testZero(int r) {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 0;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = blocked_internal(A, B, n, r);

		return compareMatrices(C, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, n);
	}

	bool testIdentity(int r) {
		int n = 3;
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					A[i * n + j] = 1;
				}
				else {
					A[i * n + j] = 0;
				}
			}
		}

		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					B[i * n + j] = 1;
				}
				else {
					B[i * n + j] = 0;
				}
			}
		}

		int* C = blocked_internal(A, B, n, r);

		return compareMatrices(C, { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, n);
	}

	bool testSome(int r) {

		int n = 5;

		std::vector<std::vector<int> > vecA = {
			{1, 2, 3, 4, 5},
			{0, 1, 3, 2, 1},
			{1, 2, 1, 2, 1},
			{3, 0, 11, 1, 1},
			{1, 1, 1, 1, 1}
		};
		int* A = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i * n + j] = vecA[i][j];
			}
		}

		std::vector<std::vector<int> > vecB = {
			{5, 0, 3, 1, 1},
			{2, 1, 1, 2, 1},
			{2, 1, 1, 1, 0},
			{0, 1, 0, 0, 1},
			{2, 2, 1, 1, 2}
		};
		int* B = new int[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i * n + j] = vecB[i][j];
			}
		}

		int* C = blocked_internal(A, B, n, r);

		return compareMatrices(C, {
			{25, 19, 13, 13, 17},
			{10, 8, 5, 6, 5},
			{13, 7, 7, 7, 7},
			{39, 14, 21, 15, 6},
			{11, 5, 6, 5, 5},
			}
		, n);
	}
}

void runAllTests() {
	bool passed = true;
	passed &= TEST_CANON::test1x1();
	passed &= TEST_CANON::testIdentity();
	passed &= TEST_CANON::testSome();
	passed &= TEST_CANON::testZero();

	if (passed) {
		std::cout << "canon passed;" << "\n";
	}
	else {
		std::cout << "canon not passed;" << "\n";
	}

	passed = true;
	passed &= TEST_CANON_EXTERNAL::test1x1();
	passed &= TEST_CANON_EXTERNAL::testIdentity();
	passed &= TEST_CANON_EXTERNAL::testSome();
	passed &= TEST_CANON_EXTERNAL::testZero();

	if (passed) {
		std::cout << "canon_external passed;" << "\n";
	}
	else {
		std::cout << "canon_external not passed;" << "\n";
	}

	passed = true;
	passed &= TEST_CANON_INTERNAL::test1x1();
	passed &= TEST_CANON_INTERNAL::testIdentity();
	passed &= TEST_CANON_INTERNAL::testSome();
	passed &= TEST_CANON_INTERNAL::testZero();

	if (passed) {
		std::cout << "canon_internal passed;" << "\n";
	}
	else {
		std::cout << "canon_internal not passed;" << "\n";
	}

	passed = true;
	passed &= TEST_BLOCK_EXTERNAL::test1x1(1);
	passed &= TEST_BLOCK_EXTERNAL::testIdentity(1);
	passed &= TEST_BLOCK_EXTERNAL::testSome(1);
	passed &= TEST_BLOCK_EXTERNAL::testZero(1);

	if (passed) {
		std::cout << "block_external passed; blocks: " << 1 << "\n";
	}
	else {
		std::cout << "block_external not passed; blocks: " << 1 << "\n";
	}

	passed = true;
	passed &= TEST_BLOCK_EXTERNAL::test1x1(1);
	passed &= TEST_BLOCK_EXTERNAL::testIdentity(1);
	passed &= TEST_BLOCK_EXTERNAL::testSome(1);
	passed &= TEST_BLOCK_EXTERNAL::testZero(1);

	if (passed) {
		std::cout << "block_external passed; blocks: " << 1 << "\n";
	}
	else {
		std::cout << "block_external not passed; blocks: " << 1 << "\n";
	}

	passed = true;
	passed &= TEST_BLOCK_EXTERNAL::test1x1(1);
	passed &= TEST_BLOCK_EXTERNAL::testIdentity(3);
	passed &= TEST_BLOCK_EXTERNAL::testZero(3);
	passed &= TEST_BLOCK_EXTERNAL::testSome(5);

	if (passed) {
		std::cout << "block_external passed; blocks: " << "n" << "\n";
	}
	else {
		std::cout << "block_external not passed; blocks: " << "n" << "\n";
	}
}