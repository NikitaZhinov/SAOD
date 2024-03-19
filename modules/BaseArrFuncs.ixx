#include <iostream>
#include <random>

export module BaseArrFuncs;

export template <typename T> void FillInc(T &A, size_t len) {
    for (size_t i = 0; i < len; i++)
        A[i] = i;
}

export template <typename T> void FillDec(T &A, size_t len) {
    for (size_t i = 1; i <= len; i++)
        A[i - 1] = len - i;
}

export template <typename T> void FillRand(T &A, size_t len) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for (size_t i = 0; i < len; i++)
        A[i] = dist(gen);
}

export template <typename T> int CheckSum(T &A, size_t len) {
    int sum = 0;
    for (size_t i = 0; i < len; i++)
        sum += A[i];
    return sum;
}

export template <typename T> size_t RunNumber(T &A, size_t len) {
    int n = 1;
    int pred = A[0];
    for (size_t i = 1; i < len; i++) {
        if (A[i] < pred)
            n++;
        pred = A[i];
    }
    return n;
}

export template <typename T> void PrintMas(T &A, size_t len) {
    for (size_t i = 0; i < len; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
