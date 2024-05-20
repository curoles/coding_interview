//https://www.geeksforgeeks.org/reservoir-sampling/
//https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/

#include <cstddef>
//#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <array>
#include <map>
#include <span>
//#include <algorithm>

uint64_t
sort(std::span<uint64_t> as, size_t size)
{
    uint64_t num_ops {0};

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j > 0; --j) {
            if (as[j-1] > as[j]) {
                auto tmp = as[j-1];
                as[j-1] = as[j];
                as[j] = tmp;
                num_ops++;
            }
            else {
                break;
            }
        }
    }

    return num_ops;
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

    init(as, SIZE);
    /*for (auto& a : as) {
        printf("%lu,", a);
    }
    puts("");*/

    uint64_t num_ops = sort(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    printf("\nops=%lu  %f[1/n^2]\n", num_ops, double(num_ops)/(SIZE*SIZE));

    for (size_t i = 0; i < SIZE; ++i) {
        as[i] = SIZE - i;
    }


    num_ops = sort(as, SIZE);
    for (auto& a : as) {
        printf("%lu,", a);
    }
    printf("\nops=%lu  %f[1/n^2]\n", num_ops, double(num_ops)/(SIZE*SIZE));

    return 0;
}
