#pragma once
#include <fstream>
#include <iostream>
int* canon(int* A, int* B, int n, std::ostream& f = std::cout);
int* canon_external(int* A, int* B, int n, std::ostream& = std::cout);
int* canon_internal(int* A, int* B, int n, std::ostream& = std::cout);
int* blocked(int* A, int* B, int n, int r, std::ostream& = std::cout);
int* blocked_external(int* A, int* B, int n, int r, std::ostream& = std::cout);
int* blocked_internal(int* A, int* B, int n, int r, std::ostream& = std::cout);