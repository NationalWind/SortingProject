#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
#include <fstream>
using namespace std;

template <class T>
void HoanVi(T&, T&);
void GenerateRandomData(int[], int);
void GenerateSortedData(int[], int);
void GenerateReverseData(int[], int);
void GenerateNearlySortedData(int[], int);
void GenerateData(int[], int, int);