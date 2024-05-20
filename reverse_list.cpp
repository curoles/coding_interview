#include <list>
#include <iostream>

int main()
{
    std::list<int> l{1,2,3,4,5};

    if (l.size() == 0 || l.size() == 1) return 0;

    auto it1 = l.begin();
    auto it2 = l.end();
    it2--;

    while (it1 != it2) {
        std::cout << *it1 << "," << *it2 << std::endl;
        std::iter_swap(it1, it2);
        it1++;
        it2--;
    }

    for (auto el : l) {
        std::cout << el << ",";
    }
    std::cout << "\n";

    return 0;
}
