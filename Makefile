CFLAGS := -Wall -Werror -O2 -std=c++20

PROGS := reverse_list longest_substring sorted_merge_one_array raindrops
PROGS += find_subarray_with_sum stock_buy_sell reservoir_sampling
PROGS += insertion_sort merge_sort
PROGS += longest_common_substring

all: $(PROGS)

%: %.cpp
	$(CXX) $(CFLAGS) -o ../build/$@ $<

