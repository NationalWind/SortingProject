#pragma once
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

#include "DataGenerator.h"
#include "Sort.h"

using namespace std;

void resourceUsedBySortingAlgorithm(int*, int, int&, double&, int, bool, bool);
void printResultsOnConditions(int*, int, const char*, const char*);
int primeMenu(int, char**);