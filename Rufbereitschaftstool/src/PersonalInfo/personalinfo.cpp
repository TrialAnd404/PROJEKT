#include <PersonalInfo/personalinfo.h>

PersonalInfo::PersonalInfo(std::string _userName, std::string _weekSetup)
{
    this.userName = _userName;
    for (std::size_t w=0; w<_weekSetup.size(); i++)
    {
        this.weekSetup.push_back(_weekSetup[w]);
    }
    MonthInfo monthInfo;
    this.personalMonth=monthInfo.getMonth();
    int shift = monthInfo.getShift();

    for (std::size_t i=0; i< personalMonth.size(); i++)
    {
        if (weekSetup[(i+shift)%7]==1)
            personalMonth[i]=1;
    }
}

std::string PersonalInfo::getName()
{
    return userName;
}

std::vector<int> PersonalInfo::getWeekSetup()
{
    return weekSetup;
}

std::vector<int> PersonalInfo::getPersonalMonth()
{
    return this.personalMonth;
}
