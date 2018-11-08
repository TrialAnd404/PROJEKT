////////////////////////////////////////////////////////////////////////
// action/insertdata.cpp
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

log_define("component.action.insertdata")

// <%pre>
#include <actionreply.h>
#line 6 "action/insertdata.ecpp"

#include <Rufbereitschaftstool/config.h>

#include <tntdb/connect.h>
#include <tntdb/statement.h>


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

static tnt::EcppComponentFactoryImpl<_component_> Factory("action/insertdata");

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
  log_trace("action/insertdata " << qparam.getUrl());


  // <%args>
int number = qparam.argt< int >("number", "int");
std::string name = qparam.param("name");
  // </%args>

#line 6 "action.ecpp"
  typedef ActionReply actionReply_type;
  TNT_REQUEST_FILE_VAR(ActionReply, actionReply, action.ecpp, ());   // <%request> ActionReply actionReply
  _tnt_ignore_unused<actionReply_type>(actionReply);
  // <%cpp>
  // <%include> action.ecpp
  // </%include>
#line 13 "action/insertdata.ecpp"


tntdb::Connection conn = tntdb::connectCached(Rufbereitschaftstool::Config::it().dburl());

tntdb::Statement ins = conn.prepare(R"SQL(
    insert into test(name, number)
     values (:name, :number)
)SQL");

ins.set("number", number)
   .set("name", name)
   .execute();

actionReply.information("one row inserted");


  // <%/cpp>
  return DEFAULT;
}

} // namespace
