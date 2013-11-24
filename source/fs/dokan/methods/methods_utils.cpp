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

#include <iostream>
void DbgPrint(LPCWSTR format, ...)
{
  WCHAR buffer[512];
  va_list argp;
  va_start(argp, format);
  vswprintf_s(buffer, sizeof(buffer) / sizeof(WCHAR), format, argp);
  va_end(argp);
  OutputDebugStringW(buffer);
  std::wstring t = buffer;
  std::wcout << t << std::endl;
}