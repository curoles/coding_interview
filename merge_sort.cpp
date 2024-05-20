//https://en.wikipedia.org/wiki/Merge_sort

#include <cstddef>
//#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <map>
#include <span>
//#include <algorithm>

template<typename T>
void merge(std::span<T> dst, std::span<const T> src, size_t begin, size_t mid, size_t end)
{
    size_t left = begin, right = mid;

    for (size_t i = begin; i < end; ++i) {
        bool use_left = left < mid && (right >= end || src[left] < src[right]);
        dst[i] = src[use_left? left : right];
        if (use_left) { left++; }
        else { right++; }
    }
}

template<typename T>
void copy_span(std::span<T> dst, std::span<const T> src, size_t begin, size_t end)
{
    for (size_t i = begin; i < end; ++i) {
        dst[i] = src[i];
    }
}

template<typename T>
void top_down_merge_split_sort(std::span<T> a, std::span<T> tmp, size_t begin, size_t end)
{
    if (end - begin <= 1)
        return;

    size_t mid = (end + begin) / 2;

    top_down_merge_split_sort(tmp, a, begin, mid);
    top_down_merge_split_sort(tmp, a, mid, end);

    merge<T>(a, tmp, begin, mid, end);
}

template<typename T>
void top_down_merge_sort(std::span<T> a, size_t size)
{
    T* tmp = new T[size];
    copy_span<T>(std::span<T>(tmp,size), a, 0, size);
    top_down_merge_split_sort(a, std::span<T>(tmp,size), 0, size);
    delete[] tmp;
}

template<typename T>
void bottom_up_merge_sort(std::span<T> a, size_t size)
{
    T* tmp = new T[size];
    std::span<T> b(tmp,size);

    for (size_t width = 1; width < size; width *= 2)
    {
        // Array A is full of runs of length width.
        for (size_t i = 0; i < size; i += 2 * width)
        {
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if (i+width >= n) )
            merge<T>(b, a, i, std::min(i+width, size), std::min(i+2*width, size));
        }
        copy_span<T>(a, b, 0, size);
    }

    delete[] tmp;
}

void init(std::span<uint64_t> as, size_t size)
{
    //size_t i = 0;
    for (auto& a : as) {
        a = rand() % size;
    }
}


int main()
{
    const size_t SIZE = 100;
    std::array<uint64_t,SIZE> as;

    printf("TOP DOWN\n");

    init(as, SIZE);
    /*for (auto& a : as) {
        printf("%lu,", a);
    }
    puts("");*/

    top_down_merge_sort<uint64_t>(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    //printf("\nops=%lu  %f[1/n^2]\n", num_ops, double(num_ops)/(SIZE*SIZE));
    printf("\n\n");

    for (size_t i = 0; i < SIZE; ++i) {
        as[i] = SIZE - i;
    }

    top_down_merge_sort<uint64_t>(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    //printf("\nops=%lu  %f[1/n^2]\n", num_ops, double(num_ops)/(SIZE*SIZE));
    printf("\n");

    printf("BOTTOM UP\n");

    init(as, SIZE);

    bottom_up_merge_sort<uint64_t>(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    //printf("\nops=%lu  %f[1/n^2]\n", num_ops, double(num_ops)/(SIZE*SIZE));
    printf("\n\n");

    return 0;
}
