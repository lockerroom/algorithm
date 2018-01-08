#include "time_counter.h"

void CTimeCounter::begin_time()
{
    gettimeofday(&m_beg_time, NULL);
}

void CTimeCounter::end_time()
{
    gettimeofday(&m_end_time, NULL);
}

unsigned long CTimeCounter::get_counter() const
{
    return (1000000 * (m_end_time.tv_sec - m_beg_time.tv_sec) + m_end_time.tv_usec - m_beg_time.tv_usec);
}
