// For a given string, write a function to compute the length of the longest substring
// that has only distinct characters.
#include <cstddef>
#include <cstring>
#include <cstdio>

#pragma GCC diagnostic ignored "-Wchar-subscripts"

size_t longest_substring(const char* s)
{
    if (s == nullptr) return 0;

    size_t begin = 0, pos = 0, longest = 0;
    size_t const slen = strlen(s);
    struct Letter {bool exists; size_t pos;} letters[256];
    memset(&letters, 0, sizeof(letters));

    while (pos < slen) {
        char letter = s[pos];
        size_t len = pos - begin + 1;
        if (letters[letter].exists) {
            size_t new_begin = letters[letter].pos + 1;
            letters[letter].pos = pos;
            printf("pos:%lu new begin:%lu longest=%lu\n", pos, new_begin, longest);
            for (size_t i = begin; i < new_begin; i++) {letters[s[i]].exists = false;}
            begin = new_begin;
        }
        else {
            if (len > longest) longest = len;
            printf("%lu-%lu, len=%lu longest=%lu\n", begin, pos, len, longest);
        }
        letters[letter].exists = true;
        letters[letter].pos = pos;
        pos++;
    }

    return longest;
}

int main()
{
    longest_substring("Meta, metamates, me");
    return 0;
}
