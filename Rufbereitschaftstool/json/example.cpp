////////////////////////////////////////////////////////////////////////
// json/example.cpp
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

log_define("component.json.example")

// <%pre>
#line 4 "json/example.ecpp"

#include <cxxtools/json.h>
#include <cxxtools/datetime.h>
#include <vector>

namespace
{

struct Result
{
    std::vector<int> values;
    cxxtools::DateTime dt;
};

void operator<<= (cxxtools::SerializationInfo& si, const Result& result)
{
    si.addMember("values") <<= result.values;
    si.addMember("dt") <<= result.dt;
}

}


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

static tnt::EcppComponentFactoryImpl<_component_> Factory("json/example");

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
  log_trace("json/example " << qparam.getUrl());


  // <%args>
bool beautify = qparam.argt< bool >("beautify", "bool");
  // </%args>

  // <%cpp>
#line 27 "json/example.ecpp"


Result result;
result.values.push_back(17);
result.values.push_back(42);
result.dt = cxxtools::DateTime::localtime();

reply.setContentType("application/json");
reply.out() << cxxtools::Json(result).beautify(beautify);


  // <%/cpp>
  return DEFAULT;
}

} // namespace
