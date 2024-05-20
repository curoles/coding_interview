#include <cstddef>
#include <cstring>
#include <cstdio>
#include <vector>

void array_merge_into(std::vector<int>& a, std::vector<int> const& b)
{
    size_t a_sz = a.size();

    // create extra space in a to accomodate items from b
    for (size_t i = 0; i < b.size(); ++i) a.push_back(-1);

    size_t a_i = a_sz - 1;
    size_t a_j = a.size() - 1;
    size_t b_i = b.size();
    while (b_i) {
        int bi = b[b_i-1];
        printf("check a[%lu]=%d vs b[%lu]=%d\n", a_i, a[a_i], b_i-1, bi);
        if (a[a_i] > bi) {
            a[a_j] = a[a_i];
            //a[a_i] = bi;
            --a_i;
        }
        else {
            a[a_j] = bi;
            --b_i;
        }
        --a_j;
        for (auto const& ai : a) {printf("%d,", ai);} puts("");
    }
}

int main()
{
    std::vector<int>a {1,3,5,7};
    std::vector<int>b {2,4,6,8,9,10,11};

    array_merge_into(a, b);

    for (auto const& ai : a)
        printf("%d,", ai);
    puts("");

    return 0;
}
