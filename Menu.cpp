#include "Menu.h"

bool isNumber(const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

void copyArray(int*& a, int* b, int n) {
    if (a != nullptr) delete[] a;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void inputArrayByFile(int*& a, int& n, const char* file_name) {
    ifstream inp;
    inp.open(file_name);
    if (!inp.is_open()) {
        cout << "Cannot open file " << file_name << endl;
        exit(1);
    }
    inp >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        inp >> a[i];
    }
    inp.close();
}

void outputArrayByFile(int* a, int n, const char* file_name) {
    ofstream out(file_name);
    out << n << endl;
    for (int i = 0; i < n; i++) {
        out << a[i];
        if (i != n - 1)
            out << " ";
        else
            out << endl;
    }
    out.close();
}

void resourceUsedBySortingAlgorithm(int* a, int n, long long& count_compare, double& time_used,
                                    int which_algo, bool is_to_count_compare,
                                    bool is_to_count_time) {
    int* temp_arr = nullptr;
    switch (which_algo) {
        case 0:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) bubbleSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = bubbleSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 1:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) heapSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = heapSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 2:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) insertionSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = insertionSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 3:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) selectionSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = selectionSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 4:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) mergeSortCompare(a, 0, n - 1, count_compare);
            if (is_to_count_time) {
                time_used = mergeSortTime(temp_arr, 0, n - 1);
                delete[] temp_arr;
            }
            break;
        case 5:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) quickSortCompare(a, 0, n - 1, count_compare);
            if (is_to_count_time) {
                time_used = quickSortTime(temp_arr, 0, n - 1);
                delete[] temp_arr;
            }
            break;
        case 6:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) radixSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = radixSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 7:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) shellSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = shellSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 8:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) flashSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = flashSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 9:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) countingSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = countingSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        case 10:
            if (is_to_count_time) {
                copyArray(temp_arr, a, n);
            }
            if (is_to_count_compare) shakerSortCompare(a, n, count_compare);
            if (is_to_count_time) {
                time_used = shakerSortTime(temp_arr, n);
                delete[] temp_arr;
            }
            break;
        default:
            break;
    }
}

void printResultsAlgorithm(int* arr, int n, int algo, const char* parameters) {
    long long count_compare = 0;
    double time_used = 0;
    if (strcmp(parameters, "-time") == 0) {
        resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, algo, 0, 1);
        cout << "Running Time: " << time_used << " ms" << endl;
    } else if (strcmp(parameters, "-comp") == 0) {
        resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, algo, 1, 0);
        cout << "Comparisons: " << count_compare << endl;
    } else if (strcmp(parameters, "-both") == 0) {
        resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, algo, 1, 1);
        cout << "Running Time: " << time_used << " ms" << endl;
        cout << "Comparisons: " << count_compare << endl;
    } else {
        cout << "Error: Unknown Parameter!" << endl;
        exit(1);
    }
}

void printResultsCompare(int* arr1, int* arr2, int n, int algo1, int algo2) {
    long long count_compare1 = 0;
    long long count_compare2 = 0;
    double time_used1 = 0;
    double time_used2 = 0;
    resourceUsedBySortingAlgorithm(arr1, n, count_compare1, time_used1, algo1, 1, 1);
    resourceUsedBySortingAlgorithm(arr2, n, count_compare2, time_used2, algo2, 1, 1);
    cout << "Running Time: " << time_used1 << " ms | " << time_used2 << " ms" << endl;
    cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;
}

int algoIndex(const char* algo, const char* algos[]) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(algo, algos[i]) == 0) {
            return i;
        }
    }
    cout << "Error: Unknown Algorithm!" << endl;
    exit(1);
}

int inputOrderIndex(const char* order, const char* orders[]) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(order, orders[i]) == 0) {
            return i;
        }
    }
    cout << "Error: Unknown Input Order!" << endl;
    exit(1);
}

void primeMenu(int argc, char** argv) {
    if (argc < 5) {
        cout << "Too few arguments." << endl;
        exit(1);
    }

    const char* orders[4]{"-rand", "-nsorted", "-sorted", "-rev"};
    const char* order_display[4]{"Randomize", "Nearly Sorted", "Sorted", "Reversed"};

    const char* algos[11]{"bubble-sort", "heap-sort",     "insertion-sort", "selection-sort",
                          "merge-sort",  "quick-sort",    "radix-sort",     "shell-sort",
                          "flash-sort",  "counting-sort", "shaker-sort"};
    const char* algos_display[11]{
        "Bubble Sort", "Heap Sort",  "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort",
        "Radix Sort",  "Shell Sort", "Flash Sort",     "Counting Sort",  "Shaker Sort"};

    if (strcmp(argv[1], "-a") == 0) {
        cout << "ALGORITHM MODE" << endl;

        if (argc == 5) {
            int n = 0;
            int* arr = nullptr;
            if (!isNumber(argv[3])) {  // Command 1
                inputArrayByFile(arr, n, argv[3]);

                int algo_idx = algoIndex(argv[2], algos);

                cout << "Algorithm: " << algos_display[algo_idx] << endl;
                cout << "Input file: " << argv[3] << endl;
                cout << "Input Size: " << n << endl;

                cout << "---------------------------------------------" << endl;
                printResultsAlgorithm(arr, n, algo_idx, argv[4]);

                outputArrayByFile(arr, n, "output.txt");

                delete[] arr;
            } else {  // Command 3
                n = atoi(argv[3]);

                int algo_idx = algoIndex(argv[2], algos);

                cout << "Algorithm: " << algos_display[algo_idx] << endl;
                cout << "Input size: " << n << endl << endl;

                for (int i = 0; i < 4; i++) {
                    cout << "Input Order: " << order_display[i] << endl;
                    createArrayByOrder(arr, n, i);

                    string out_str("input_");
                    out_str.push_back(i + 1 + '0');
                    out_str += ".txt";

                    outputArrayByFile(arr, n, out_str.c_str());

                    cout << "---------------------------------------------" << endl;
                    printResultsAlgorithm(arr, n, algo_idx, argv[4]);
                    cout << endl;

                    delete[] arr;
                }
            }

        } else if (argc == 6) {  // Command 2
            int n = 0;
            int* arr = nullptr;
            if (isNumber(argv[3])) {
                n = atoi(argv[3]);
                int order_idx = inputOrderIndex(argv[4], orders);
                int algo_idx = algoIndex(argv[2], algos);

                cout << "Algorithm: " << algos_display[algo_idx] << endl;
                cout << "Input size: " << n << endl;
                cout << "Input order: " << order_display[order_idx] << endl;

                createArrayByOrder(arr, n, order_idx);

                outputArrayByFile(arr, n, "input.txt");

                cout << "---------------------------------------------" << endl;

                printResultsAlgorithm(arr, n, algo_idx, argv[5]);

                outputArrayByFile(arr, n, "output.txt");

                delete[] arr;
            } else {
                cout << "Invalid input size" << endl;
                exit(1);
            }
        } else {
            cout << "Too many arguments." << endl;
            exit(1);
        }

    } else if (strcmp(argv[1], "-c") == 0) {
        cout << "COMPARE MODE" << endl;
        if (argc == 5) {  // Command 4
            int n = 0;
            int* arr1 = nullptr;
            int* arr2 = nullptr;
            int algo1_idx = algoIndex(argv[2], algos);
            int algo2_idx = algoIndex(argv[3], algos);

            inputArrayByFile(arr1, n, argv[4]);
            copyArray(arr2, arr1, n);

            cout << "Algorithm: " << algos_display[algo1_idx] << " | " << algos_display[algo2_idx]
                 << endl;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input Size: " << n << endl;

            cout << "---------------------------------------------" << endl;

            printResultsCompare(arr1, arr2, n, algo1_idx, algo2_idx);

            delete[] arr1;
            delete[] arr2;

        } else if (argc == 6) {  // Command 5
            int n = 0;
            int* arr1 = nullptr;
            int* arr2 = nullptr;
            if (isNumber(argv[4])) {
                n = atoi(argv[4]);

                int algo1_idx = algoIndex(argv[2], algos);
                int algo2_idx = algoIndex(argv[3], algos);

                int order_idx = inputOrderIndex(argv[5], orders);

                createArrayByOrder(arr1, n, order_idx);
                copyArray(arr2, arr1, n);

                outputArrayByFile(arr1, n, "input.txt");

                cout << "Algorithm: " << algos_display[algo1_idx] << " | "
                     << algos_display[algo2_idx] << endl;
                cout << "Input order: " << order_display[order_idx] << endl;
                cout << "Input Size: " << n << endl;

                cout << "---------------------------------------------" << endl;

                printResultsCompare(arr1, arr2, n, algo1_idx, algo2_idx);

                delete[] arr1;
                delete[] arr2;
            } else {
                cout << "Invalid input size" << endl;
                exit(1);
            }
        } else {
            cout << "Too many arguments." << endl;
            exit(1);
        }
    } else {
        cout << "Invalid arguments." << endl;
        exit(1);
    }
}