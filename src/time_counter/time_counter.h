#ifndef TIME_COUNTER_H_
#define TIME_COUNTER_H_

#include "../common.h"
#include <sys/time.h>

class CTimeCounter
{
public:
    // 开始计时
    void begin_time();
    // 停止计时
    void end_time();
    // 获取时间差 us
    unsigned long get_counter() const;

private:
    struct timeval m_beg_time;
    struct timeval m_end_time;
};

#endif
