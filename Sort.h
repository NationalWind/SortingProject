#pragma once

#include <algorithm>
#include <cmath>

#include "DataGenerator.h"

using namespace std;

double heapSortTime(int[], int);
void heapSortCompare(int[], int, long long&);
double flashSortTime(int[], int);
void flashSortCompare(int[], int, long long&);
double bubbleSortTime(int[], int);
void bubbleSortCompare(int[], int, long long&);
double shakerSortTime(int[], int);
void shakerSortCompare(int[], int, long long&);
double countingSortTime(int[], int);
void countingSortCompare(int[], int, long long&);
double selectionSortTime(int[], int);
void selectionSortCompare(int[], int, long long&);
double insertionSortTime(int[], int);
void insertionSortCompare(int[], int, long long&);
double shellSortTime(int[], int);
void shellSortCompare(int[], int, long long&);
double mergeSortTime(int[], int, int);
void mergeSortCompare(int[], int, int, long long&);
double radixSortTime(int[], int);
void radixSortCompare(int[], int, long long&);
double quickSortTime(int[], int, int);
void quickSortCompare(int[], int, int, long long&);
