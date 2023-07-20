#include "Menu.h"

bool isNumber(const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

void resourceUsedBySortingAlgorithm(int* a, int n, int& count_compare, double& time_used,
                                    int which_algo, bool is_to_count_compare,
                                    bool is_to_count_time) {
    switch (which_algo) {
        case 0:
            if (is_to_count_compare) bubbleSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = bubbleSortTime(a, n);
            break;
        case 1:
            if (is_to_count_compare) heapSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = heapSortTime(a, n);
            break;
        case 2:
            if (is_to_count_compare) insertionSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = insertionSortTime(a, n);
            break;
        case 3:
            if (is_to_count_compare) selectionSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = selectionSortTime(a, n);
            break;
        case 4:
            if (is_to_count_compare) mergeSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = mergeSortTime(a, n);
            break;
        case 5:
            if (is_to_count_compare) quickSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = quickSortTime(a, n);
            break;
        case 6:
            if (is_to_count_compare) radixSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = radixSortTime(a, n);
            break;
        case 7:
            if (is_to_count_compare) shellSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = shellSortTime(a, n);
            break;
        case 8:
            if (is_to_count_compare) flashSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = flashSortTime(a, n);
            break;
        case 9:
            if (is_to_count_compare) countingSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = countingSortTime(a, n);
            break;
        case 10:
            if (is_to_count_compare) shakerSortCompare(a, n, count_compare);
            if (is_to_count_time) time_used = shakerSortTime(a, n);
            break;
        default:
            break;
    }
}

void printResultsOnConditions(int* arr, int n, const char* algo, const char* parameters) {
    string algos[11]{"-bubble-sort", "-heap-sort",     "-insertion-sort", "-selection-sort",
                     "-merge-sort",  "-quick-sort",    "-radix-sort",     "-shell-sort",
                     "-flash-sort",  "-counting-sort", "-shaker-sort"};
    int count_compare = 0;
    double time_used = 0;
    for (int i = 0; i < 11; i++) {
        if (strcmp(algo, algos[i].c_str()) == 0) {
            if (strcmp(parameters, "-time") == 0) {
                resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, i, 1, 0);
                cout << "Running Time: " << time_used << " ms" << endl;
            } else if (strcmp(parameters, "-comp") == 0) {
                resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, i, 0, 1);
                cout << "Comparisons: " << count_compare << endl;
            } else if (strcmp(parameters, "-both") == 0) {
                resourceUsedBySortingAlgorithm(arr, n, count_compare, time_used, i, 1, 1);
                cout << "Running Time: " << time_used << " ms" << endl;
                cout << "Comparisons: " << count_compare << endl;
            } else {
                cout << "Error: Unknown Parameter!" << endl;
            }
            return;
        }
    }
    cout << "Error: Unknown Sorting Algorithm!" << endl;
}

int primeMenu(int argc, char** argv) {
    if (argc < 5) {
        cout << "Too few arguments." << endl;
        return 1;
    }

    if (strcmp(argv[1], "-a") == 0) {
        cout << "Algorithm Mode" << endl;
        cout << "---------------------------------------------" << endl;
        if (argc == 5) {
            int n = 0;
            int* arr = nullptr;
            if (!isNumber(argv[3])) {  // Command 1
                ifstream inp;
                inp.open(argv[3]);
                if (!inp.is_open()) {
                    cout << "Cannot open file " << argv[3] << endl;
                    return 1;
                }
                inp >> n;
                arr = new int[n];
                for (int i = 0; i < n; i++) {
                    inp >> arr[i];
                }
                printResultsOnConditions(arr, n, argv[2], argv[4]);
                delete[] arr;
                inp.close();
            } else {  // Command 3
                n = atoll(argv[3]);
                const char* order[4]{"-rand", "-sorted", "-rev", "-nsorted"};
                for (int i = 0; i < 4; i++) {
                    arr = createArrayBasedOnString(n, order[i]);
                    printResultsOnConditions(arr, n, argv[2], argv[4]);
                    delete[] arr;
                }
            }

        } else if (argc == 6) {  // Command 2
            int n = 0;
            int* arr = nullptr;
            if (isNumber(argv[3])) {
                arr = createArrayBasedOnString(n, argv[4]);
                printResultsOnConditions(arr, n, argv[2], argv[5]);
                delete[] arr;
            } else {
                cout << "Invalid input size" << endl;
            }
        } else {
            cout << "Too many arguments." << endl;
            return 1;
        }

    } else if (strcmp(argv[1], "-c") == 0) {
        cout << "Compare Mode" << endl;
        cout << "---------------------------------------------" << endl;
        if (argc == 5) {  // Command 4
            int n = 0;
            int* arr = nullptr;
            ifstream inp;
            inp.open(argv[4]);
            if (!inp.is_open()) {
                cout << "Cannot open file " << argv[4] << endl;
                return 1;
            }
            inp >> n;
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                inp >> arr[i];
            }
            printResultsOnConditions(arr, n, argv[2], "-both");
            printResultsOnConditions(arr, n, argv[3], "-both");
            delete[] arr;
            inp.close();
        } else if (argc == 6) {  // Command 5
            int n = 0;
            int* arr = nullptr;
            if (isNumber(argv[4])) {
                arr = createArrayBasedOnString(n, argv[4]);
                printResultsOnConditions(arr, n, argv[2], argv[5]);
                delete[] arr;
                arr = createArrayBasedOnString(n, argv[4]);
                printResultsOnConditions(arr, n, argv[3], argv[5]);
                delete[] arr;
            } else {
                cout << "Invalid input size" << endl;
            }
        } else {
            cout << "Too many arguments." << endl;
            return 1;
        }
    } else {
        cout << "Invalid arguments." << endl;
        return 1;
    }
    return 0;
}