#include <iostream>
#include <omp.h> 

const int n = 1000;
const int r = 1000;

int* canon(int* A, int* B, int n) {
	int i = 0, j = 0, k = 0;
	double t1, t2;

	int* C = new int[n * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i * n + j] = 0;
		}
	}

	t1 = omp_get_wtime();

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				C[i * n + j] += A[i * n + k] * B[k * n + j];
			}
		}
	}


	t2 = omp_get_wtime();
	std::cout << "Multiplication time: " << t2 - t1 << '\n';


	return C;
}

int* canon_external(int* A, int* B, int n) {
	int i = 0, j = 0, k = 0;
	double t1, t2;

	int* C = new int[n * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i * n + j] = 0;
		}
	}

	t1 = omp_get_wtime();

#pragma omp parallel for shared(A, B, C) private(i, j, k)
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				C[i * n + j] += A[i * n + k] * B[k * n + j];
			}
		}
	}


	t2 = omp_get_wtime();
	std::cout << "Multiplication time: " << t2 - t1 << '\n';


	return C;
}

int* canon_internal(int* A, int* B, int n) {
	int i = 0, j = 0, k = 0;
	double t1, t2;

	int* C = new int[n * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i * n + j] = 0;
		}
	}

	t1 = omp_get_wtime();

	for (i = 0; i < n; i++) {
#pragma omp parallel for shared(A, B, C, i) private(j, k)
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				C[i * n + j] += A[i * n + k] * B[k * n + j];
			}
		}
	}


	t2 = omp_get_wtime();
	std::cout << "Multiplication time: " << t2 - t1 << '\n';


	return C;
}

int* blocked_external(int* A, int* B, int n, int r) {
	int i = 0, j = 0, k = 0, i_gl = 0, j_gl = 0, k_gl = 0;
	const int q = n / r;
	double t1, t2;

	int* C = new int[n * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i * n + j] = 0;
		}
	}

	t1 = omp_get_wtime();

#pragma omp parallel for shared(A, B, C) private(i, j, k, i_gl, j_gl, k_gl)
	for (i_gl = 0; i_gl < q; i_gl++) {
		for (j_gl = 0; j_gl < q; j_gl++) {
			for (k_gl = 0; k_gl < q; k_gl++) {
				//============================================

				for (i = i_gl * r; i < (i_gl + 1) * r; i++) {
					for (j = j_gl * r; j < (j_gl + 1) * r; j++) {
						for (k = k_gl * r; k < (k_gl + 1) * r; k++) {
							C[i * n + j] += A[i * n + k] * B[k * n + j];
						}
					}
				}

				//============================================
			}
		}
	}


	t2 = omp_get_wtime();
	std::cout << "Multiplication time: " << t2 - t1 << '\n';


	return C;
}

int* blocked_internal(int* A, int* B, int n, int r) {
	int i = 0, j = 0, k = 0, i_gl = 0, j_gl = 0, k_gl = 0;
	const int q = n / r;
	double t1, t2;

	int* C = new int[n * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i * n + j] = 0;
		}
	}

	t1 = omp_get_wtime();

	for (i_gl = 0; i_gl < q; i_gl++) {
#pragma omp parallel for shared(A, B, C, i_gl) private(i, j, k, j_gl, k_gl)
		for (j_gl = 0; j_gl < q; j_gl++) {
			for (k_gl = 0; k_gl < q; k_gl++) {
				//============================================

				for (i = i_gl * r; i < (i_gl + 1) * r; i++) {
					for (j = j_gl * r; j < (j_gl + 1) * r; j++) {
						for (k = k_gl * r; k < (k_gl + 1) * r; k++) {
							C[i * n + j] += A[i * n + k] * B[k * n + j];
						}
					}
				}

				//============================================
			}
		}
	}


	t2 = omp_get_wtime();
	std::cout << "Multiplication time: " << t2 - t1 << '\n';


	return C;
}


int main() {
	int* A = new int[n * n];
	int* B = new int[n * n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i * n + j] = 1;
			B[i * n + j] = 1;
		}
	}

	int* C1 = canon(A, B, n);
	int* C2 = canon_external(A, B, n);
	int* C3 = canon_internal(A, B, n);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		std::cout << C[i * n + j] << " ";
	//	}
	//	std::cout << '\n';
	//}//;'';';';';/////////


	return 0;
}
