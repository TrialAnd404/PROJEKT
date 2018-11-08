#ifndef MONTHINFO_H
#define MONTHINFO_H

#include <vector>
#include <time.h>

class MonthInfo
{
    public:
        MonthInfo();
        std::vector<int> getMonth();
        int getCurrentMonthDays();
        std::vector<int> getMonthHolidays();
        int getShift();
    private:
        std::vector<int> month;
        int monthDays[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int currentMonth;
        int dayOfMonth;
        int dayOfWeek;
        int weekShift;
        std::vector<int> monthHolidays;     
};

#endif

