#include "Sort.h"

void heapifyTime(int start, int a[], int n) {
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
        heapifyTime(larger, a, n);
    }
}

double heapSortTime(int a[], int n) {
    auto beginTime = clock();
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapifyTime(i, a, n);
    }
    swap(a[0], a[n - 1]);
    int sz = n - 1;
    while (sz > 1) {
        heapifyTime(0, a, sz);
        sz--;
        HoanVi(a[0], a[sz]);
    }
    double timeUsed = ((double)clock() - beginTime) / CLOCKS_PER_SEC;
    return timeUsed;
}

void heapifyCompare(int start, int a[], int n, int &count_compare) {
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
        heapifyTime(larger, a, n);
    }
}

void heapSortCompare(int a[], int n, int &count_compare) {
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
    auto beginTime = clock();
    int minValue, maxValue;
    minValue = maxValue = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minValue)
            minValue = a[i];
        else if (a[i] > maxValue)
            maxValue = a[i];
    }

    int m = int(0.43 * n);
    int *cnt = new int[m]{0};

    for (int i = 0; i < n; i++)
        cnt[int(m * (a[i] - minValue) / (maxValue - minValue + 1))]++;

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
    double timeUsed = ((double)clock() - beginTime) / CLOCKS_PER_SEC;
    return timeUsed;
}

void flashSortCompare(int a[], int n, int &count_compare) {
    int minValue, maxValue;
    minValue = maxValue = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] < minValue)
            minValue = a[i];
        else if (++count_compare && a[i] > maxValue)
            maxValue = a[i];
    }

    int m = int(0.43 * n);
    int *cnt = new int[m]{0};

    for (int i = 0; ++count_compare && i < n; i++)
        cnt[int(m * (a[i] - minValue) / (maxValue - minValue + 1))]++;

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
        while ((++count_compare && j > 0) &&
               (++count_compare && temp < a[j - 1])) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }

    delete[] cnt;
}