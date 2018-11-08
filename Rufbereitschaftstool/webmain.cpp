////////////////////////////////////////////////////////////////////////
// webmain.cpp
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

log_define("component.webmain")

// <%pre>
#line 1 "webmain.ecpp"

// put your includes here
// #include "foo.h"

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

static tnt::EcppComponentFactoryImpl<_component_> Factory("webmain");

static const char* rawData = "\010\000\000\000\374\003\000\000<!DOCTYPE html>\n<html>\n    <head>\n        <title>tntne"
  "t application Rufbereitschaftstool</title>\n        <meta charset=\"UTF-8\">\n        <meta name=\"description\" cont"
  "ent=\"Rufbereitschaftstool application\">\n        <link rel=\"stylesheet\" href=\"css/Rufbereitschaftstool.css\" typ"
  "e=\"text/css\">\n        <link rel=\"stylesheet\" href=\"css/dropdown.css\" type=\"text/css\">\n        <link rel=\"s"
  "tylesheet\" href=\"css/datatables.css\" type=\"text/css\">\n        <link rel=\"stylesheet\" href=\"css/statusbar.css"
  "\" type=\"text/css\">\n        <link rel=\"stylesheet\" href=\"css/noty.css\" type=\"text/css\">\n        <link rel="
  "\"stylesheet\" href=\"css/noty/themes/mint.css\" type=\"text/css\">\n        <script data-main=\"js/main\" src=\"js/r"
  "equire.js\"></script>\n    </head>\n    <body>\n        <ul id=\"mainmenu\" class=\"dropdown\">\n            <li><a h"
  "ref=\"rufbereitschaftstool\">Rufbereitschaftsplan</a></li>\n        </ul>\n\n        <div id=\"content\"></div>\n\n  "
  "      <div class=\"statusbar\">\n            <div>status</div>\n        </div>\n    </body>\n</html>\n";

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
  log_trace("webmain " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
#line 5 "webmain.ecpp"

// put your C++ code here

  reply.out() << data[0]; // <!DOCTYPE html>\n<html>\n    <head>\n        <title>tntnet application Rufbereitschaftstool</title>\n        <meta charset="UTF-8">\n        <meta name="description" content="Rufbereitschaftstool application">\n        <link rel="stylesheet" href="css/Rufbereitschaftstool.css" type="text/css">\n        <link rel="stylesheet" href="css/dropdown.css" type="text/css">\n        <link rel="stylesheet" href="css/datatables.css" type="text/css">\n        <link rel="stylesheet" href="css/statusbar.css" type="text/css">\n        <link rel="stylesheet" href="css/noty.css" type="text/css">\n        <link rel="stylesheet" href="css/noty/themes/mint.css" type="text/css">\n        <script data-main="js/main" src="js/require.js"></script>\n    </head>\n    <body>\n        <ul id="mainmenu" class="dropdown">\n            <li><a href="rufbereitschaftstool">Rufbereitschaftsplan</a></li>\n        </ul>\n\n        <div id="content"></div>\n\n        <div class="statusbar">\n            <div>status</div>\n        </div>\n    </body>\n</html>\n
  // <%/cpp>
  return DEFAULT;
}

} // namespace
