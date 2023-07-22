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
void printResultsAlgorithm(int*, int, int, const char*);
void printResultsCompare(int*, int*, int, int, int);
void primeMenu(int, char**);