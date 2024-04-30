#pragma once

#include <cmath>
#include <vector>
#include "Contaners.hpp"

template <class T> size_t SelectSort(T &arr) {
    size_t m = 0, c = 0;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        int snp = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[snp])
                snp = j;
            c++;
        }
        std::swap(arr[i], arr[snp]);
        m += 3;
    }
    return m + c;
}

template <class T> size_t BubbleSort(T &arr) {
    size_t m = 0, c = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 1; j < arr.size() - i; j++) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
            }
            c++;
        }
    }
    return m + c;
}

template <class T> size_t ShakerSort(T &arr) {
    size_t L = 0, R = arr.size() - 1, k = arr.size() - 1;
    size_t m = 0, c = 0;
    do {
        for (size_t j = R; j > L; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        L = k;
        for (size_t j = L; j < R; j++) {
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

template <class T> size_t InsertSort(T &arr) {
    size_t m = 0, c = 0;
    for (size_t i = 1; i < arr.size(); i++) {
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

template <class T> size_t ShellSort(T &arr) {
    size_t m = 0, c = 0;
    size_t M = (int)std::log2(arr.size()) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (size_t i = h[a]; i < arr.size(); i++) {
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

template <class T, class C> size_t ShellSort(T &arr, C commpare) {
    size_t m = 0, c = 0;
    size_t M = (int)std::log2(arr.size()) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (size_t i = h[a]; i < arr.size(); i++) {
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

template <class T> void build_heap(T &arr, size_t l, size_t r, size_t &m, size_t &c) {
    auto x = arr[l];
    size_t i = l;
    while (true) {
        size_t j = 2 * i;
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

template <class T> size_t HeapSort(T &arr) {
    size_t m = 0, c = 0;
    for (long long l = arr.size() / 2; l >= 0; l--)
        build_heap(arr, l, arr.size() - 1, m, c);
    size_t r = arr.size() - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        m += 3;
        build_heap(arr, 0, r, m, c);
    }
    return m + c;
}

template <class T> int64_t HoaraSort(T &arr, int64_t left, int64_t right, size_t &m, size_t &c) {
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

template <class T> void QuickSort(T &arr, int64_t start, int64_t end, size_t &m, size_t &c) {
    if (start >= end)
        return;
    int64_t rightStart = HoaraSort(arr, start, end, m, c);
    QuickSort(arr, start, rightStart - 1, m, c);
    QuickSort(arr, rightStart, end, m, c);
}

template <class T> size_t QuickSort(T &arr) {
    size_t m = 0, c = 0;
    QuickSort(arr, 0, arr.size() - 1, m, c);
    return m + c;
}
