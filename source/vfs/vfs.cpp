#include "stdafx.h"
#include "vfs.h"
#include "file\cached\cached_file_handler.h"

#include <sstream>
DEPRECATED // by born
namespace
{
  wstring ConCat(const wstring &a, const wstring &b)
  {
    std::wstringstream stream;
    stream << a << b;
    return stream.str();
  }
  wstring Cache(const wstring &filename)
  {
    wstring tmp_dir = L"C:\\Users\\Enelar\\AppData\\Local\\Temp\\fs_debug\\";
    return ConCat(tmp_dir, filename);
  }
}

file_handler &vfs::CreateFile(wstring filename, access_rights, create_disposition, attributes)
{
  wstring actual_mapped_file = Cache(filename);
  cached_file_handler *ret = MEMLEAK NEW cached_file_handler(actual_mapped_file);
  return *ret;
}

file_handler &vfs::CreateFile(wstring filename)
{
  todo(Looks like simple creation is deprecated);
}

file_handler &vfs::OpenFile(wstring filename)
{
  wstring actual_mapped_file = Cache(filename);
  cached_file_handler *ret = MEMLEAK NEW cached_file_handler(actual_mapped_file);
  return *ret;
}