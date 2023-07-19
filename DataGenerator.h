#pragma once
#include <time.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
void HoanVi(T&, T&);
void GenerateRandomData(int[], int);
void GenerateSortedData(int[], int);
void GenerateReverseData(int[], int);
void GenerateNearlySortedData(int[], int);
void GenerateData(int[], int, int);