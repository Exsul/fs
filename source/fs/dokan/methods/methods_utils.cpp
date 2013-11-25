#include "methods_utils.h"

template<>
access_rights convert(const int &a)
{
  access_rights ret;
  auto Check = [&ret, a](access_rights::ACCESS_RIGHTS right)
  {
    if (a & right)
      ret.rights.push_back(right);
  };

  Check(access_rights::READ);
  Check(access_rights::WRITE);
  Check(access_rights::DELETE);
  return ret;
}

template<>
create_disposition convert(const int &a)
{
  return create_disposition{convert<create_disposition::CREATE_DISPOSITION>(a)};
}

dbg_print DbgPrint;

#include "../../../vfs/internal.h" // only for concat
#include <iostream>
void dbg_print::operator()(LPCWSTR format, ...)
{
  WCHAR buffer[512];
  va_list argp;
  va_start(argp, format);
  vswprintf_s(buffer, sizeof(buffer) / sizeof(WCHAR), format, argp);
  va_end(argp);

  auto ShowDepth = []( word depth )
  {
    wstring ret;
    for (word i = 0; i < depth; ++i)
      ret = ConCat(ret, L"  ");
    return ret;
  };

  std::wstring t = ConCat(ShowDepth(depth), buffer);
  OutputDebugStringW(t.c_str());
  OutputDebugStringW(L"\n");
  std::wcout << t << std::endl;
  file << t << std::endl;
}

dbg_print::lvl_dbg_print::~lvl_dbg_print()
{
  DbgPrint.depth--;
}

dbg_print::lvl_dbg_print::lvl_dbg_print()
{
  DbgPrint.depth++;
}

dbg_print::lvl_dbg_print dbg_print::Down() const
{
  return lvl_dbg_print();
}

dbg_print::dbg_print()
{
  file.open(L"C:\\mapped\\Log.txt", ios::out || ios::trunc);
}
dbg_print::~dbg_print()
{
  file.close();
}
