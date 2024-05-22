#include <cstddef>
#include <cstring>
#include <cstdio>
#include <vector>

template<typename T=size_t>
struct LcsLenMatrix
{
    std::vector<T> data;
    size_t rows, cols;

    LcsLenMatrix(size_t size1, size_t size2):
        rows(size1), cols(size2)
    {
        data.resize(rows * cols, (T)0);
    }

    T& operator()(size_t row, size_t col) {
        return data[col*rows + row];
    }
};

size_t longest_common_substring(const char* s1, const char* s2)
{
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    LcsLenMatrix len(s1_len, s2_len);
    unsigned int longest_len = 0;
    const char* longest_str = nullptr;
    size_t total = 0;

    for (size_t i = 0; i < s1_len; ++i) {
        for (size_t j = 0; j < s2_len; ++j) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) {len(i, j) = 1;}
                else {len(i,j) = len(i-1,j-1) + 1;}
                total++;
                unsigned int l=len(i,j);
                printf("%lu:%lu len=%u str=%.*s\n", i, j, l, l, &s1[i+1-l]);

                if (l > longest_len) {
                    longest_len = l;
                    longest_str = &s1[i+1-l];
                }
            }
        }
    }

    if (longest_len) {
        printf("longest substring:%.*s\n", (int)longest_len, longest_str);
    }

    return total;
}

int main(void)
{
    const char* s1 = "badanat";
    const char* s2 = "canadas";

    size_t total = longest_common_substring(s1, s2);
    printf("total: %lu\n", total);

    return 0;
}
