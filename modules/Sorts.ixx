#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

export module Sorts;

export template <class T> size_t SelectSort(T &A) {
    size_t m = 0, c = 0;
    for (size_t i = 0; i < A.size() - 1; i++) {
        int snp = i;
        for (size_t j = i + 1; j < A.size(); j++) {
            if (A[j] < A[snp])
                snp = j;
            c++;
        }
        std::swap(A[i], A[snp]);
        m += 3;
    }
    return m + c;
}

export template <class T> size_t BubbleSort(T &A) {
    size_t m = 0, c = 0;
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 1; j < A.size() - i; j++) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
                m += 3;
            }
            c++;
        }
    }
    return m + c;
}

export template <class T> size_t ShakerSort(T &A) {
    size_t L = 0, R = A.size() - 1, k = A.size() - 1;
    size_t m = 0, c = 0;
    do {
        for (size_t j = R; j > L; j--) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        L = k;
        for (size_t j = L; j < R; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        R = k;
    } while (L < R);
    return m + c;
}

export template <class T> size_t InsertSort(T &A) {
    size_t m = 0, c = 0;
    for (size_t i = 1; i < A.size(); i++) {
        bool f = true;
        auto t = A[i];
        long long j = i - 1;
        while (j > -1 and t < A[j]) {
            f = false;
            A[j + 1] = A[j];
            j--;
            c++;
            m++;
        }
        if (f)
            c++;
        A[j + 1] = t;
        m += 2;
    }
    return m + c;
}

export template <class T> size_t ShellSort(T &A) {
    size_t m = 0, c = 0;
    size_t M = (int)std::log2(A.size()) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (size_t i = h[a]; i < A.size(); i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and A[j] > A[j + h[a]]; j -= h[a]) {
                std::swap(A[j], A[j + h[a]]);
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

export template <class T, class C> size_t ShellSort(T &A, C commpare) {
    size_t m = 0, c = 0;
    size_t M = (int)std::log2(A.size()) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (size_t i = h[a]; i < A.size(); i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 and commpare(A[j], A[j + h[a]]); j -= h[a]) {
                std::swap(A[j], A[j + h[a]]);
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
