#include "RufbereitschaftsData/rufbereitschaftsdata.h"

RufbereitschaftsData::RufbereitschaftsData()
{
    std::string dummyname = "";
    std::string dummysetup = "";
    
    ifstream myfile("");
    if (myfile.isopen())
    {
        while(!myfile.eof())
        {
            getline(myfile,dummyname,'\t');
            getline(myfile,dummysetup,'\t');
        
            personalInfo.push_back(PersonalInfo::PersonalInfo(dummyname, dummysetup));
        }
    }
}

void RufbereitschaftsData::updateData()
{
    return true;
}

int getUserAmount::RufbereitschaftsData()
{
    return personalInfo.size();
}

Monthinfo getMonthInfo::RufbereitschaftsData()
{
    return monthInfo;
}

std::vector<PersonalInfo> getAllPersonalInfo::RufbereitschaftsData()
{
    return personalInfo;
}

PersonalInfo getSpecificPersonalInfo::RufbereitschafsData(int _index)
{
    return personalInfo[_index];
}
