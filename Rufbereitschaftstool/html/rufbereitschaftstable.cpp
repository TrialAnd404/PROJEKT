////////////////////////////////////////////////////////////////////////
// html/rufbereitschaftstable.cpp
// generated with ecppc
//

#include <tnt/ecpp.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>
#include <tnt/httpheader.h>
#include <tnt/http.h>
#include <tnt/data.h>
#include <tnt/componentfactory.h>
#include <cxxtools/log.h>
#include <stdexcept>

log_define("component.html.rufbereitschaftstable")

// <%pre>
#line 1 "html/rufbereitschaftstable.ecpp"


#include <include/RufbereitschaftsData/rufbereitschaftsdata.h>
#include <vector>


// </%pre>

namespace
{
class _component_ : public tnt::EcppComponent
{
    _component_& main()  { return *this; }

  protected:
    ~_component_();

  public:
    _component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl);

    unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
};

static tnt::EcppComponentFactoryImpl<_component_> Factory("html/rufbereitschaftstable");

static const char* rawData = "@\000\000\000m\000\000\000}\000\000\000~\000\000\000\204\000\000\000\265\000\000\000\266"
  "\000\000\000\274\000\000\000\304\000\000\000\305\000\000\000\340\000\000\000\346\000\000\000\000\001\000\000J\001\000"
  "\000M\001\000\000^\001\000\000\n<html>\n<table>\n <th>\n  <td>Username</td>\n  \n            <td>.</td>\n            "
  "<td style=\"background-color:#FF0000\">.</td>\n </th>\n \n        <tr>\n          <td></td>\n                <td></td"
  ">\n                <td style=\"background-color:#FF0000\"></td>\n        </tr>\n   \n</table>\n</html>\n";

// <%shared>
// </%shared>

// <%config>
// </%config>

#define SET_LANG(lang) \
     do \
     { \
       request.setLang(lang); \
       reply.setLocale(request.getLocale()); \
     } while (false)

_component_::_component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl)
  : EcppComponent(ci, um, cl)
{
  // <%init>
  // </%init>
}

_component_::~_component_()
{
  // <%cleanup>
  // </%cleanup>
}

template <typename T>
inline void _tnt_ignore_unused(const T&) { }

unsigned _component_::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
{
  log_trace("html/rufbereitschaftstable " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
#line 9 "html/rufbereitschaftstable.ecpp"
  // <= this starts a c++-processing-block

RufbereitschaftsData myRufbereitschaftsData;

std::vector<int> monthData	= myRufbereitschaftsData.getMonthInfo().getMonth();
int currentMonth		= myRufbereitschaftsData.getMonthInfo().getCurrentMonth();

std::vector<PersonalInfo> personalInfo = myRufbereitschaftsData.getAllPersonalInfo();


  reply.out() << data[0]; // \n<html>\n<table>\n <th>\n  <td>Username</td>\n  \n
#line 25 "html/rufbereitschaftstable.ecpp"
   for (std::size_t i = 0; i < monthData.size(); i++){

#line 26 "html/rufbereitschaftstable.ecpp"
       if (monthData[i] ==0)

  reply.out() << data[1]; //             <td>
#line 27 "html/rufbereitschaftstable.ecpp"
  reply.sout() << ( i+1 );
  reply.out() << data[2]; // .
#line 27 "html/rufbereitschaftstable.ecpp"
  reply.sout() << ( myRufbereitschaftsData.getMonthInfo().getCurrentMonth() );
  reply.out() << data[3]; // </td>\n
#line 28 "html/rufbereitschaftstable.ecpp"
       else

  reply.out() << data[4]; //             <td style="background-color:#FF0000">
#line 29 "html/rufbereitschaftstable.ecpp"
  reply.sout() << ( i+1 );
  reply.out() << data[5]; // .
#line 29 "html/rufbereitschaftstable.ecpp"
  reply.sout() << ( currentMonth );
  reply.out() << data[6]; // </td>\n
#line 30 "html/rufbereitschaftstable.ecpp"
   }       

  reply.out() << data[7]; //  </th>\n 
  reply.out() << data[8]; // \n
#line 33 "html/rufbereitschaftstable.ecpp"
   for(std::size_t i = 0; i<personalInfo.size(); i++)

#line 34 "html/rufbereitschaftstable.ecpp"
   {

#line 35 "html/rufbereitschaftstable.ecpp"
       std::vector<int> personalMonth = personalInfo[i].getPersonalMonth();

  reply.out() << data[9]; //         <tr>\n          <td>
#line 37 "html/rufbereitschaftstable.ecpp"
  reply.sout() << ( personalInfo[i].getName() );
  reply.out() << data[10]; // </td>\n
#line 38 "html/rufbereitschaftstable.ecpp"
         for (std::size_t j = 0; j < personalMonth.size(); i++){

#line 39 "html/rufbereitschaftstable.ecpp"
             if (personalMonth[j] ==0)

  reply.out() << data[11]; //                 <td></td>\n
#line 41 "html/rufbereitschaftstable.ecpp"
         else

  reply.out() << data[12]; //                 <td style="background-color:#FF0000"></td>\n        </tr>\n 
  reply.out() << data[13]; //   \n
#line 45 "html/rufbereitschaftstable.ecpp"
   }

  reply.out() << data[14]; // </table>\n</html>\n
  // <%/cpp>
  return DEFAULT;
}

} // namespace
