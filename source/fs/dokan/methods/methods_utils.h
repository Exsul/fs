#include "../../header.h"
#include "../dokan_proxy.h"
#undef DELETE
#undef CREATE_ALWAYS
#undef CREATE_NEW
#undef OPEN_ALWAYS
#undef OPEN_EXISTING
#undef TRUNCATE_EXISTING
#include "../../../vfs/vfs.h"

template<>
access_rights convert(const int &a);
template<>
create_disposition convert(const int &a);

#include <fstream>
class dbg_print
{
  word depth = 0;
  std::wofstream file;
public:
  dbg_print();
  ~dbg_print();
  void operator()(LPCWSTR format, ...);
  struct lvl_dbg_print
  {
    ~lvl_dbg_print();
    lvl_dbg_print(const lvl_dbg_print &) = delete;
    template<typename T> void operator=(T) = delete;
    lvl_dbg_print(lvl_dbg_print &&);
  private:
    lvl_dbg_print();
    friend class dbg_print;
  };
  friend struct lvl_dbg_print;
  lvl_dbg_print Down() const;
};

extern dbg_print DbgPrint;

#define HANDLER_BEGIN(methodname, filename) DbgPrint(L">  %s %s", methodname, filename.c_str()); auto level = DbgPrint.Down()
#define DBG_RETURN(ret, dbgprint) if (true) { DbgPrint dbgprint; return ret; } else
#define DBG_ASSERT_RETURN(cond, ret, dbgprint) if (!(cond)) DBG_RETURN(ret, dbgprint); else
