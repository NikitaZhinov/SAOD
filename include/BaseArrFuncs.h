#pragma once

#include <iostream>
#include <random>

template <typename T> void FillInc(T &arr, std::size_t len);
template <typename T> void FillDec(T &arr, std::size_t len);
template <typename T> void FillRand(T &arr, std::size_t len);
template <typename T> int CheckSum(T &arr, std::size_t len);
template <typename T> std::size_t RunNumber(T &arr, std::size_t len);
template <typename T> void PrintMas(T &arr, std::size_t len);
