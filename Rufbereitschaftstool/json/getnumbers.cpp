////////////////////////////////////////////////////////////////////////
// json/getnumbers.cpp
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

log_define("component.json.getnumbers")

// <%pre>
#line 4 "json/getnumbers.ecpp"

#include <Rufbereitschaftstool/config.h>

#include <cxxtools/json.h>
#include <tntdb/connect.h>
#include <tntdb/statement.h>
#include <tntdb/value.h>

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

static tnt::EcppComponentFactoryImpl<_component_> Factory("json/getnumbers");

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
  log_trace("json/getnumbers " << qparam.getUrl());


  // <%args>
bool beautify = qparam.argt< bool >("beautify", "bool");
  // </%args>

  // <%cpp>
#line 15 "json/getnumbers.ecpp"


tntdb::Connection conn = tntdb::connectCached(Rufbereitschaftstool::Config::it().dburl());

tntdb::Statement sel = conn.prepare(R"SQL(
    select number
      from test
)SQL");

std::vector<int> result;
for (auto row: sel)
{
    int value;
    row.get(value);
    result.push_back(value);
}

reply.setContentType("application/json");
reply.out() << cxxtools::Json(result).beautify(beautify);


  // <%/cpp>
  return DEFAULT;
}

} // namespace
