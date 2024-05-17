#pragma once

#include <cmath>
#include <vector>
#include <utility>

template <typename T> std::size_t SelectSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 0; i < len - 1; i++) {
        int snp = i;
        for (std::size_t j = i + 1; j < len; j++) {
            if (arr[j] < arr[snp])
                snp = j;
            c++;
        }
        std::swap(arr[i], arr[snp]);
        m += 3;
    }
    return m + c;
}

template <typename T> std::size_t BubbleSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 0; i < len; i++) {
        for (std::size_t j = 1; j < len - i; j++) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
            }
            c++;
        }
    }
    return m + c;
}

template <typename T> std::size_t ShakerSort(T &arr, std::size_t len) {
    std::size_t L = 0, R = len - 1, k = len - 1;
    std::size_t m = 0, c = 0;
    do {
        for (std::size_t j = R; j > L; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        L = k;
        for (std::size_t j = L; j < R; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        R = k;
    } while (L < R);
    return m + c;
}

template <typename T> std::size_t InsertSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (std::size_t i = 1; i < len; i++) {
        bool f = true;
        auto t = arr[i];
        long long j = i - 1;
        while (j > -1 and t < arr[j]) {
            f = false;
            arr[j + 1] = arr[j];
            j--;
            c++;
            m++;
        }
        if (f)
            c++;
        arr[j + 1] = t;
        m += 2;
    }
    return m + c;
}

template <typename T> std::size_t ShellSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    std::size_t M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (std::size_t i = h[a]; i < len; i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and arr[j] > arr[j + h[a]]; j -= h[a]) {
                std::swap(arr[j], arr[j + h[a]]);
                m += 3;
                f = false;
                c++;
            }
            if (f)
                c++;
        }
    }
    return m + c;
}

template <class T, class C> std::size_t ShellSort(T &arr, std::size_t len, C commpare) {
    std::size_t m = 0, c = 0;
    std::size_t M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (std::size_t i = h[a]; i < len; i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and commpare(arr[j], arr[j + h[a]]); j -= h[a]) {
                std::swap(arr[j], arr[j + h[a]]);
                m += 3;
                f = false;
                c++;
            }
            if (f)
                c++;
        }
    }
    return m + c;
}

template <typename T> void build_heap(T &arr, std::size_t l, std::size_t r, std::size_t &m, std::size_t &c) {
    auto x = arr[l];
    std::size_t i = l;
    while (true) {
        std::size_t j = 2 * i;
        if (j > r)
            break;
        if (j < r and arr[j + 1] <= arr[j])
            j++;
        c++;
        if (x <= arr[j]) {
            c++;
            break;
        }
        c++;
        arr[i] = arr[j];
        m++;
        i = j;
    }
    arr[i] = x;
    m += 2;
}

template <typename T> std::size_t HeapSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (long long l = len / 2; l >= 0; l--)
        build_heap(arr, l, len - 1, m, c);
    std::size_t r = len - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        m += 3;
        build_heap(arr, 0, r, m, c);
    }
    return m + c;
}

template <typename T> int HoaraSort(T &arr, int left, int right, std::size_t &m, std::size_t &c) {
    auto pivo = arr[(left + right) / 2];
    m++;
    while (left <= right) {
        c += 2;
        while (arr[left] < pivo) {
            left++;
            c++;
        }
        while (arr[right] > pivo) {
            right--;
            c++;
        }
        if (left <= right) {
            std::swap(arr[left++], arr[right--]);
            m += 3;
        }
    }
    return left;
}

template <typename T> void QuickSort(T &arr, int start, int end, std::size_t &m, std::size_t &c) {
    if (start >= end)
        return;
    int rightStart = HoaraSort(arr, start, end, m, c);
    QuickSort(arr, start, rightStart - 1, m, c);
    QuickSort(arr, rightStart, end, m, c);
}

template <typename T> std::size_t QuickSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    QuickSort(arr, 0, len - 1, m, c);
    return m + c;
}
