#include "Sort.h"

void heapify(int start, int a[], int n) {
    int left = start * 2 + 1;
    if (left >= n) return;
    int larger = left;
    int right = start * 2 + 2;
    if (right < n) {
        if (a[right] > a[larger]) {
            larger = right;
        }
    }
    if (a[start] < a[larger]) {
        HoanVi(a[start], a[larger]);
        heapify(larger, a, n);
    }
}

void heapSort(int a[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(i, a, n);
    }
    swap(a[0], a[n - 1]);
    int sz = n - 1;
    while (sz > 1) {
        heapify(0, a, sz);
        sz--;
        HoanVi(a[0], a[sz]);
    }
}

double heapSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();
    heapSort(a, n);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void heapifyCompare(int start, int a[], int n, long long& count_compare) {
    int left = start * 2 + 1;
    if (++count_compare && left >= n) return;
    int larger = left;
    int right = start * 2 + 2;
    if (++count_compare && right < n) {
        if (++count_compare && a[right] > a[larger]) {
            larger = right;
        }
    }
    if (++count_compare && a[start] < a[larger]) {
        HoanVi(a[start], a[larger]);
        heapify(larger, a, n);
    }
}

void heapSortCompare(int a[], int n, long long& count_compare) {
    count_compare = 0;
    for (int i = (n - 1) / 2; ++count_compare && i >= 0; i--) {
        heapifyCompare(i, a, n, count_compare);
    }
    HoanVi(a[0], a[n - 1]);
    int sz = n - 1;
    while (sz > 1) {
        heapifyCompare(0, a, sz, count_compare);
        sz--;
        swap(a[0], a[sz]);
    }
}

double flashSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int minValue, maxValue;
    minValue = maxValue = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minValue)
            minValue = a[i];
        else if (a[i] > maxValue)
            maxValue = a[i];
    }

    int m = int(0.43 * n);
    int* cnt = new int[m]{0};
    double c1 = (double)(m - 1) / (maxValue - minValue);
    for (int i = 0; i < n; i++) {
        int k = int(c1 * (a[i] - minValue));
        ++cnt[k];
    }
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];

    int numMoves = 0;
    int i = 0;
    int k = m - 1;
    while (numMoves < n - 1) {
        while (i > cnt[k] - 1) {
            i++;
            k = int(m * (a[i] - minValue) / (maxValue - minValue + 1));
        }
        int flash = a[i];
        if (k < 0) break;
        while (i != cnt[k]) {
            k = int(m * (flash - minValue) / (maxValue - minValue + 1));
            int swap = a[cnt[k] - 1];
            a[cnt[k] - 1] = flash;
            cnt[k]--;
            flash = swap;
            numMoves++;
        }
    }
    for (int i = 1; i < n; i++) {
        int j = i;
        int temp = a[i];
        while (j > 0 && temp < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }

    delete[] cnt;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void flashSortCompare(int a[], int n, long long& count_compare) {
    int minValue, maxValue;
    minValue = maxValue = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] < minValue)
            minValue = a[i];
        else if (++count_compare && a[i] > maxValue)
            maxValue = a[i];
    }

    int m = int(0.43 * n);
    int* cnt = new int[m]{0};

    double c1 = (double)(m - 1) / (maxValue - minValue);
    for (int i = 0; ++count_compare && i < n; i++) {
        int k = int(c1 * (a[i] - minValue));
        ++cnt[k];
    }

    for (int i = 1; ++count_compare && i < m; i++) cnt[i] += cnt[i - 1];

    int numMoves = 0;
    int i = 0;
    int k = m - 1;
    while (++count_compare && numMoves < n - 1) {
        while (++count_compare && i > cnt[k] - 1) {
            i++;
            k = int(m * (a[i] - minValue) / (maxValue - minValue + 1));
        }
        int flash = a[i];
        if (++count_compare && k < 0) break;
        while (++count_compare && i != cnt[k]) {
            k = int(m * (flash - minValue) / (maxValue - minValue + 1));
            int swap = a[cnt[k] - 1];
            a[cnt[k] - 1] = flash;
            cnt[k]--;
            flash = swap;
            numMoves++;
        }
    }
    for (int i = 1; ++count_compare && i < n; i++) {
        int j = i;
        int temp = a[i];
        while ((++count_compare && j > 0) && (++count_compare && temp < a[j - 1])) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }

    delete[] cnt;
}

double bubbleSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void bubbleSortCompare(int a[], int n, long long& count_compare) {
    for (int i = 0; ++count_compare && i < n - 1; i++) {
        for (int j = 0; ++count_compare && j < n - i - 1; j++) {
            if (++count_compare && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

double shakerSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n / 2; i++) {
        bool swapped = false;
        for (int j = i; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }
        for (int j = n - 2 - i; j > i; j--) {
            if (a[j] > a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void shakerSortCompare(int a[], int n, long long& count_compare) {
    for (int i = 0; ++count_compare && i < n / 2; i++) {
        bool swapped = false;
        for (int j = i; ++count_compare && j < n - i - 1; j++) {
            if (++count_compare && a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }
        for (int j = n - 2 - i; ++count_compare && j > i; j--) {
            if (++count_compare && a[j] > a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

double countingSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();

    if (n <= 1) {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_used =
            std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        return time_used;
    }
    int max_value = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_value) max_value = a[i];
    }

    int* counting_array = new int[max_value + 1];
    for (int i = 0; i <= max_value; i++) {
        counting_array[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        counting_array[a[i]]++;
    }

    for (int i = 1; i <= max_value; i++) {
        counting_array[i] += counting_array[i - 1];
    }

    int* temp = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        temp[counting_array[a[i]] - 1] = a[i];
        counting_array[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
    delete[] counting_array;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void countingSortCompare(int a[], int n, long long& count_compare) {
    if (++count_compare && n <= 1) return;

    int max_value = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] > max_value) max_value = a[i];
    }

    int* counting_array = new int[max_value + 1];
    for (int i = 0; ++count_compare && i <= max_value; i++) {
        counting_array[i] = 0;
    }

    for (int i = 0; ++count_compare && i < n; i++) {
        counting_array[a[i]]++;
    }

    for (int i = 1; ++count_compare && i <= max_value; i++) {
        counting_array[i] += counting_array[i - 1];
    }

    int* temp = new int[n];

    for (int i = n - 1; ++count_compare && i >= 0; i--) {
        temp[counting_array[a[i]] - 1] = a[i];
        counting_array[a[i]]--;
    }

    for (int i = 0; ++count_compare && i < n; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
    delete[] counting_array;
}

double selectionSortTime(int a[], int size) {
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < size; j++) {
            if (a[minIdx] > a[j]) {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void selectionSortCompare(int a[], int size, long long& count_compare) {
    for (int i = 0; ++count_compare && i < size - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; ++count_compare && j < size; j++) {
            if (++count_compare && a[minIdx] > a[j]) {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
    }
}

double insertionSortTime(int a[], int size) {
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void insertionSortCompare(int a[], int size, long long& count_compare) {
    for (int i = 1; ++count_compare && i < size; i++) {
        int key = a[i];
        int j = i - 1;

        while (++count_compare && j >= 0 && ++count_compare && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

double shellSortTime(int a[], int size) {
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int key = a[i];
            int j = i - interval;

            while (j >= 0 && a[j] > key) {
                a[j + interval] = a[j];
                j -= interval;
            }

            a[j + interval] = key;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void shellSortCompare(int a[], int size, long long& count_compare) {
    for (int interval = size / 2; ++count_compare && interval > 0; interval /= 2) {
        for (int i = interval; ++count_compare && i < size; i++) {
            int key = a[i];
            int j = i - interval;

            while (++count_compare && j >= 0 && ++count_compare && a[j] > key) {
                a[j + interval] = a[j];
                j -= interval;
            }

            a[j + interval] = key;
        }
    }
}

void merge(int a[], int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = a[first + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + j + 1];
    int i = 0;
    int j = 0;
    int k = first;
    while (i < n1 && j < n2) a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

    while (j < n2) a[k++] = R[j++];
    while (i < n1) a[k++] = L[i++];
    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortTime(a, first, mid);
        mergeSortTime(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

double mergeSortTime(int a[], int first, int last) {
    auto start_time = std::chrono::high_resolution_clock::now();
    mergeSort(a, first, last);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void mergeCompare(int a[], int first, int mid, int last, long long& count_compare) {
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; ++count_compare && i < n1; i++) L[i] = a[first + i];
    for (int j = 0; ++count_compare && j < n2; j++) R[j] = a[mid + j + 1];
    int i = 0;
    int j = 0;
    int k = first;
    while (++count_compare && i < n1 && ++count_compare && j < n2)
        a[k++] = (++count_compare && L[i] < R[j]) ? L[i++] : R[j++];

    while (++count_compare && j < n2) a[k++] = R[j++];
    while (++count_compare && i < n1) a[k++] = L[i++];
    delete[] L;
    delete[] R;
}
void mergeSortCompare(int a[], int first, int last, long long& count_compare) {
    if (++count_compare && first < last) {
        int mid = first + (last - first) / 2;
        mergeSortCompare(a, first, mid, count_compare);
        mergeSortCompare(a, mid + 1, last, count_compare);
        mergeCompare(a, first, mid, last, count_compare);
    }
}

double radixSortTime(int a[], int n) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int* b = new int[n];
    int m = a[0], exp = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > m) m = a[i];

    while (m / exp > 0) {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--) b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++) a[i] = b[i];
        exp *= 10;
    }
    delete[] b;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}

void radixSortCompare(int a[], int n, long long& count_compare) {
    int* b = new int[n];
    int m = a[0], exp = 1;

    for (int i = 0; ++count_compare && i < n; i++)
        if (++count_compare && a[i] > m) m = a[i];

    while (++count_compare && m / exp > 0) {
        int bucket[10] = {0};
        for (int i = 0; ++count_compare && i < n; i++) bucket[a[i] / exp % 10]++;
        for (int i = 1; ++count_compare && i < 10; i++) bucket[i] += bucket[i - 1];
        for (int i = n - 1; ++count_compare && i >= 0; i--) b[--bucket[a[i] / exp % 10]] = a[i];
        for (int i = 0; ++count_compare && i < n; i++) a[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}

int partitionCompare(int a[], int first, int last, long long& count_compare) {
    int pivot = a[(first + last) / 2];
    int i = first;
    int j = last;
    int tmp;
    while (++count_compare && i <= j) {
        while (++count_compare && a[i] < pivot) i++;
        while (++count_compare && a[j] > pivot) j--;
        if (++count_compare && i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}
void quickSortCompare(int a[], int first, int last, long long& count_compare) {
    int index = partitionCompare(a, first, last, count_compare);
    if (++count_compare && first < index - 1) quickSortCompare(a, first, index - 1, count_compare);
    if (++count_compare && index < last) quickSortCompare(a, index, last, count_compare);
}

int partition(int a[], int first, int last) {
    int pivot = a[(first + last) / 2];
    int i = first;
    int j = last;
    int tmp;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int a[], int first, int last) {
    int index = partition(a, first, last);
    if (first < index - 1) quickSortTime(a, first, index - 1);
    if (index < last) quickSortTime(a, index, last);
}

double quickSortTime(int a[], int first, int last) {
    auto start_time = std::chrono::high_resolution_clock::now();
    quickSort(a, first, last);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return time_used;
}