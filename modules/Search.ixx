export module Search;

#define ELEMENT_IS_NOT_FOUND -1;

export size_t COMPARE_BINARY_SEARCH_1 = 0;
export size_t COMPARE_BINARY_SEARCH_2 = 0;

export template <typename TArr, typename TElem> long long BinarySearch1(const TArr &arr, size_t len, TElem x) {
    COMPARE_BINARY_SEARCH_1 = 0;
    size_t left = 0, right = len - 1;

    while (left <= right) {
        size_t middle = (left + right) / 2;
        COMPARE_BINARY_SEARCH_1++;
        if (arr[middle] == x)
            return (long long)middle;

        if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
        COMPARE_BINARY_SEARCH_1++;
    }

    return ELEMENT_IS_NOT_FOUND;
}

export template <typename TArr, typename TElem> long long BinarySearch2(const TArr &arr, size_t len, TElem x) {
    COMPARE_BINARY_SEARCH_2 = 0;
    size_t left = 0, right = len - 1;

    while (left < right) {
        size_t middle = (left + right) / 2;
        if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle;
        COMPARE_BINARY_SEARCH_2++;
    }

    COMPARE_BINARY_SEARCH_2++;
    if (arr[right] == x)
        return (long long)right;
    return ELEMENT_IS_NOT_FOUND;
}
