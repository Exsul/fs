#include "../../header.h"
#include "../dokan_proxy.h"
#undef DELETE
#undef CREATE_ALWAYS
#undef CREATE_NEW
#undef OPEN_ALWAYS
#undef OPEN_EXISTING
#undef TRUNCATE_EXISTING
#include "../../win_undef_names.h"
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

template<typename t, bool notnull = true>
t *DeserializeContext(const DOKAN_FILE_INFO &info)
{
  if (notnull)
    throw_assert(info.Context);
  return reinterpret_cast<t *>(info.Context);
}

#define STANDART_FILE_CHECKS() \
  DBG_ASSERT_RETURN(dokan_info.Context, ERROR_INVALID_FUNCTION, (L"[ERROR] Delete file zero context")); \
  DBG_ASSERT_RETURN(!dokan_info.IsDirectory, ERROR_INVALID_FUNCTION, (L"[ERROR] Write file on directory called"))
