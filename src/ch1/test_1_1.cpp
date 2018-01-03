#include "../common.h"
#include "test_1.h"
#include <time.h>
#include <vector>

void select_k_max_val(std::vector<int>& src, int* dst, int k)
{
    /*
    if (!dst || k < 1) return;
    for (auto i : src)
    {
        insert_to_array(dst, k, i);
    }
    */

    for (unsigned long long ull = 0 ; ull < 1000000 ; ++ull)
    {
        std::cout << std::ends;
    }
}

void test_1_1()
{
    std::vector<int> src_data{0, 9, 73, 2, 57, 3, 20, 4, 1, 10, 100, 9637, 28451, 1211, 2341, 7465, 8843, 6653, 2246};
    std::vector<int> k_array{1, 2, 3, 4, 5};

    for (auto ssz : k_array)
    {
        int* tmp = new int[ssz];
        for (int i = 0 ; i < ssz ; ++i)
        {
            *(tmp + i) = 0;
        }

        time_t start_time;
        time_t stop_time;

        start_time = time(NULL);
        select_k_max_val(src_data, tmp, ssz);
        stop_time = time(NULL);

        double exec_time = difftime(start_time, stop_time);
        
        printf("Select %d numbers, and execute time is %f.", ssz, exec_time);
        std::cout << "Select result is : ";
        for (int i = 0 ; i < ssz ; ++i)
        {
            std::cout << *(tmp + i) << " " << std::ends;
        }
        std::cout << std::endl;
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
