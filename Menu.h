#pragma once
#include <string.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "DataGenerator.h"
#include "Sort.h"

using namespace std;

void resourceUsedBySortingAlgorithm(int*, int, long long&, double&, int, bool, bool);
void printResultsAlgorithmMode(int*, int, int, const char*);
void printResultsCompareMode(int*, int*, int, int, int);
void primeMenu(int, char**);