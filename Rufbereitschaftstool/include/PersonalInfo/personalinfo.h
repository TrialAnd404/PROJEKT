#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <vector>

#include "MonthInfo/monthinfo.h"

class PersonalInfo
{
    public:
        PersonalInfo(std::string _userName, std::string _weekSetup);
        std::string getName();
        std::vector<int> getWeekSetup();
        std::vector<int> getPersonalMonth();
    private:
        std::string userName;
        std::vector<int> personalMonth;
};

#endif
