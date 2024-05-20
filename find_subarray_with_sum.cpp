#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <tuple>


std::tuple<bool,size_t,size_t>
find_subarray_with_sum(std::vector<int> const& a, int sum)
{
    if (a.empty()) std::make_tuple(false, 0, 0);

    bool found = false;
    size_t start = 0, end = 0;
    int accum = a[0];

    while (!found && end < a.size()) {
        printf("sum[%lu:%lu]=%d\n", start, end, accum);
        if (accum == sum) {
            found = true;
        }
        else if (accum > sum) {
            accum -= a[start];
            ++start;
        }
        else {
            ++end;
            accum += a[end];
        }
    }

    return std::make_tuple(found, start, end);
}

int main()
{
    std::vector<int> a {1,2,3,4,5,6,7,8,9,10};

    std::tuple<bool,size_t,size_t> res = find_subarray_with_sum(a, 30);

    printf("found:%u start:%lu end:%lu\n",
        std::get<0>(res), std::get<1>(res), std::get<2>(res));

    return 0;
}
