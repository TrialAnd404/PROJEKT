#include <MonthInfo/monthinfo.h>

MonthInfo::MonthInfo()
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    currentMonth = aTime->tm_mon;
    dayOfMonth = aTime->tm_mday;
    dayOfWeek = aTime->tm_wday;
    weekShift = 7-(dayOfWeek-dayOfMonth%7)+1;
    
    monthHolidays=getMonthHolidays();

    for (int i =0; i<monthDays[currentMonth]; i++)
    {
        if ((i+weekShift)%7 == 6 || (i+weekShift)%7 == 0 || monthHolidays[i] == 1)
        {
            month.push_back(1);
        }
        else
        {
            month.push_back(0);
        }
        month.push_back((i+weekShift)%7);
    };
}

int MonthInfo::getCurrentMonthDays()
{
    return monthDays[currentMonth];
}
std::vector<int> MonthInfo::getMonth()
{
    return month;
}

/*std::vector<int> MonthInfo::getMonthHolidays()
{
//Einlesen von Vektor der Länge des Monats, Feiertage 1 Keine Feiertage 0
}*/
