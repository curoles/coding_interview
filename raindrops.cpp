#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

static std::set<size_t> sidewalk;

void init(size_t size)
{
    for (size_t i = 0; i < size; ++i)
        sidewalk.insert(i);
}

bool is_all_wet(size_t pos)
{
    if (sidewalk.count(pos)) {
        sidewalk.erase(pos);
    }
    return sidewalk.empty();
}

int main()
{
    const size_t size = 10000;
    init(size);

    size_t iterations = 0;
    while (!is_all_wet(rand()%size)) {
        ++iterations;
    }

    printf("size:%lu iterations:%lu\n", size, iterations);

    return 0;
}
