#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>


// Selects the k-th smallest element of an unsorted array.
//
// Complexity:
//   Time: O(N)
//   Space: O(logN) ~ O(N)
//
template <class T, class Comparator = std::less<T>>
struct QuickSelect {
    Comparator less = Comparator();
    // Selects the k-th smallest element of the given unsorted array.
    // Returns the value of the k-th smallest element.
    // k = [0,N)
    // Time: O(N)
    // Space: O(N)
    T operator()(std::vector<T> const& array, size_t k) const {
        if (k < 0 || k >= array.size()) throw std::out_of_range("k");
        std::vector<T> buffer(array.begin(), array.end());
        auto index = index_of(buffer, k);
        return buffer[index];
    }
    // Selects the k-th smallest element of the given unsorted array.
    // Returns the index of the k-th smallest element.
    // k = [0,N)
    // Time: O(N)
    // Space: O(logN)
    size_t index_of(std::vector<T>& array, size_t k) const {
        if (k < 0 || k >= array.size()) throw std::out_of_range("k");
        return select(array, 0, array.size(), k);
    }
private:
    size_t select(std::vector<T>& array, size_t begin, size_t end, size_t k) const {
        while (true) {
            if (end - begin == 1) {
                return begin;
            }
            auto pivot_index = pivot_of(array, begin, end);
            pivot_index = partition(array, begin, end, k, array[pivot_index]);
            std::cout << pivot_index << " " << k << std::endl;
            if (pivot_index == k) {
                return k;
            } else if (pivot_index < k) {
                begin = pivot_index + 1;
            } else {
                end = pivot_index;
            }
        }
    }
    size_t pivot_of(std::vector<T>& array, size_t begin, size_t end) const {
        if (end - begin <= 5) {
            return partition5(array, begin, end);
        }
        size_t n = 0;
        for (size_t i = begin; i < end; i += 5) {
            auto median = partition5(array, i, std::min(i+5,end));
            std::swap(array[median], array[begin + (i-begin)/5]);
            ++n;
        }
        auto k = begin + (n-1)/2;
        return select(array, begin, begin + n, k);
    }
    inline size_t partition(std::vector<T>& array, size_t begin, size_t end, size_t k, T pivot_value) const {
        auto begin_equal = std::partition(array.begin() + begin, array.begin() + end, [&](auto value) {
            return less(value, pivot_value);
        });
        auto end_equal = std::partition(begin_equal, array.begin() + end, [&](auto value) {
            return !less(value, pivot_value) && !less(pivot_value, value);
        });
        size_t begin_equal_range = distance(array.begin(), begin_equal);
        size_t end_equal_range = distance(array.begin(), end_equal);
        if (k < begin_equal_range) {
            return begin_equal_range;
        } else if (k >= end_equal_range) {
            return end_equal_range-1;
        } else {
            return k;
        }
    }
    inline size_t partition5(std::vector<T>& array, size_t begin, size_t end) const {
        for (size_t i = begin + 1; i < end; ++i) {
            for (size_t j = i; j > begin && less(array[j], array[j-1]); --j) {
                std::swap(array[j-1], array[j]);
            }
        }
        return begin + (end - begin - 1) / 2;
    }
};
