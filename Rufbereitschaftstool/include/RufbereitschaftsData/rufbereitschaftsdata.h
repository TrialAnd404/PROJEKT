#ifndef RUFBEREITSCHAFTSDATA_H
#define RUFBEREITSCHAFTSDATA_H

#include <fstream>

#include "PersonalInfo/personalinfo.h"
#include "MonthInfo/monthinfo.h"


class RufbereitschaftsData
{
    public:
        RufbereitschaftsData();
        void updateData();
        MonthInfo getMonthInfo();
        std::vector<PersonalInfo> getAllPersonalInfo();
        PersonalInfo getSpecificPersonalInfo(int index);
        int getUserAmount();

        
    private:
        std::vector<PersonalInfo> personalInfo;
        MonthInfo monthInfo;
};

#endif
