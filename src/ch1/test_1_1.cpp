#include "../common.h"
#include "test_1.h"
#include "../time_counter/time_counter.h"
#include <vector>

void select_k_max_val(std::vector<int>& src, int* dst, int k)
{
    if (!dst || k < 1) return;
    for (auto i : src)
    {
        insert_to_array(dst, k, i);
    }
}

void test_1_1()
{
    // std::vector<int> src_data{0, 9, 73, 2, 57, 3, 20, 4, 1, 10, 100, 9637, 28451, 1211, 2341, 7465, 8843, 6653, 2246};
    std::vector<int> src_data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
                              12, 13, 14, 15, 16, 17, 18, 19, 20,
                              21, 22, 23, 24, 25, 26, 27, 28, 29,
                              30, 31, 32, 33, 34, 35, 36, 37, 38,
                              39, 40, 41, 42, 43, 44, 45, 46, 47,
                              48, 49, 50, 51, 52, 53, 54, 55, 56,
                              57, 58, 59, 60, 61, 62, 63, 64, 65, 
                              66, 67, 68, 69, 70, 71, 72, 73, 74,
                              75, 76, 77, 78, 79, 80, 81, 82, 83,
                              84, 85, 86, 87, 88, 89, 90, 91, 92,
                              93, 94, 95, 96, 97, 98, 99, 100
                              };
    std::vector<int> k_array{1, 5, 10, 50, 100};

    printf("numbers\ttime\n");
    for (auto ssz : k_array)
    {
        int* tmp = new int[ssz];
        for (int i = 0 ; i < ssz ; ++i)
        {
            *(tmp + i) = 0;
        }

        CTimeCounter counter;
        unsigned long timer;

        counter.begin_time();
        select_k_max_val(src_data, tmp, ssz);
        counter.end_time();

        timer = counter.get_counter();
        printf("%d\t%ldus\n", ssz, timer);
        // printf("Select %d numbers, and execute time is %ld us.", ssz, timer);
        /*
        std::cout << " Select result is : ";
        for (int i = 0 ; i < ssz ; ++i)
        {
            std::cout << *(tmp + i) << " " << std::ends;
        }
        std::cout << std::endl;
        */
        delete [] tmp;
    }
}

void insert_to_array(int* dst, int len, int in_val)
{
    if (!dst || len < 1) return;
    int end_pos = len - 1;
    if (*(dst + end_pos) < in_val)
    {
        *(dst + end_pos) = in_val;
        for (int i = end_pos - 1 ; i  >= 0 ; --i)
        {
            if (*(dst + i) < *(dst + i + 1))
            {
                int tmp = *(dst + i);
                *(dst + i) = *(dst + i + 1);
                *(dst + i + 1) = tmp;
            }
            else
            {
                break;
            }
        }
    }
}
