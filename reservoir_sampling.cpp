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

void
random_sample(std::span<const uint64_t> stream, size_t size,
    std::span<uint64_t> sample, size_t sample_size)
{
    for (size_t i = 0; i < sample_size; ++i) {
        sample[i] = stream[i];
    }

    for (size_t i = sample_size; i < size; ++i) {
        size_t j = rand() % (i + 1);
        if (j < sample_size) {
            sample[j] = stream[i];
            //printf("sample[%lu]=%lu\n", j, stream[i]);
        }
    }
}

void init(std::span<uint64_t> as, size_t size)
{
    size_t i = 0;
    for (auto& a : as) {
        a = i++;//rand() % size;
    }
}


int main()
{
    const size_t SIZE = 100;
    std::array<uint64_t,SIZE> stream;

    init(stream, SIZE);
    /*for (auto& a : as) {
        printf("%lu,", a);
    }
    puts("");*/

    const size_t SAMPLE_SIZE = 10;
    std::array<uint64_t,SAMPLE_SIZE> samples;

    std::map<uint64_t, uint32_t> stat;

    const size_t TIMES = 10000;
    for (size_t i = 0; i < TIMES; ++i)
    {
        random_sample(stream, SIZE, samples, SAMPLE_SIZE);
        for (auto sample : samples) {
            if (stat.count(sample) == 0) {
                stat[sample] = 0;
            }
            else {
                stat[sample] += 1;
            }
        }
    }

    double expected_ratio = double(SAMPLE_SIZE)/SIZE;

    for (auto const& st : stat) {
        double stat_ratio = double(st.second)/TIMES;
        double diff = ((expected_ratio - stat_ratio)/expected_ratio)*100;
        printf("%lu: %u, %f %%\n", st.first, st.second, diff);
    }

    return 0;
}
