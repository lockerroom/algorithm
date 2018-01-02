#include "../common.h"
#include "test_1.h"
#include <time.h>
#include <vector>

float devide_half(unsigned long long);

void test_1_1()
{
    std::vector<unsigned long long> src_data{0};

    std::cout << "Number" << "\t" << "Time" << std::endl;
    for (auto i : src_data)
    {
        float tmp_time = devide_half(i);
        std::cout << i << "\t" << tmp_time << std::endl;
    }
}


float devide_half(unsigned long long N)
{
    clock_t t;
    float exec_time = 0.0f;

    t = clock();
    unsigned long long res = N / 2;
    t = clock() - t;

    exec_time = ((float)t)/CLOCKS_PER_SEC;
    return exec_time;
}