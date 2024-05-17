#pragma once

#include "Lists.hpp"

#include <cmath>
#include <cstddef>
#include <vector>

template <typename T> std::size_t selectSort(T &arr, std::size_t len) {
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

template <typename T> std::size_t bubbleSort(T &arr, std::size_t len) {
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

template <typename T> std::size_t shakerSort(T &arr, std::size_t len) {
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

template <typename T> std::size_t insertSort(T &arr, std::size_t len) {
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

template <typename T> std::size_t shellSort(T &arr, std::size_t len) {
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

template <class T, class C> std::size_t shellSort(T &arr, std::size_t len, C commpare) {
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

template <typename T> void buildHeap(T &arr, std::size_t l, std::size_t r, std::size_t &m, std::size_t &c) {
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

template <typename T> std::size_t heapSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    for (long long l = len / 2; l >= 0; l--)
        buildHeap(arr, l, len - 1, m, c);
    std::size_t r = len - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        m += 3;
        buildHeap(arr, 0, r, m, c);
    }
    return m + c;
}

template <typename T> int hoaraSort(T &arr, int left, int right, std::size_t &m, std::size_t &c) {
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

template <typename T> void quickSort(T &arr, int start, int end, std::size_t &m, std::size_t &c) {
    if (start >= end)
        return;
    int rightStart = hoaraSort(arr, start, end, m, c);
    quickSort(arr, start, rightStart - 1, m, c);
    quickSort(arr, rightStart, end, m, c);
}

template <typename T> std::size_t quickSort(T &arr, std::size_t len) {
    std::size_t m = 0, c = 0;
    quickSort(arr, 0, len - 1, m, c);
    return m + c;
}

template <typename T> std::size_t digitalSort(list<T> &list_) {
    std::size_t t = 0;
    int count_of_queue = 256;

    for (std::size_t i = 0; i < std::pow(2, sizeof(T) * 8) / count_of_queue; i++) {
        std::vector<queue<T>> Q(count_of_queue);

        std::size_t len_list = list_.get_size();
        for (std::size_t j = 0; j < len_list; j++)
            Q[list_(j) / (int)std::pow(count_of_queue, i) % count_of_queue].push(list_(j));

        list_.clear();
        for (int j = 0; j < 256; i++)
            list_ += Q[j];
    }

    return t;
}
