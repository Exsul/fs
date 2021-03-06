#include "stdafx.h"
#include "vfs.h"
#include "file\cached\cached_file_handler.h"

#include <sstream>
DEPRECATED // by born

wstring ConCat(const wstring &a, const wstring &b)
{
  std::wstringstream stream;
  stream << a << b;
  return stream.str();
}
wstring Cache(const wstring &filename)
{
  wstring tmp_dir = L"C:\\mapped";
  return ConCat(tmp_dir, filename);
}

file_handler *vfs::CreateFile(wstring filename, access_rights ar, create_disposition cd, attributes at)
{
  wstring actual_mapped_file = Cache(filename);
  return NEW MEMLEAK cached_file_handler(cached_file_handler::Create(actual_mapped_file));
}

file_handler *vfs::CreateFile(wstring filename)
{
  todo(Looks like simple creation is deprecated);
}

file_handler *vfs::OpenFile(wstring filename)
{
  wstring actual_mapped_file = Cache(filename);
  return NEW MEMLEAK cached_file_handler(actual_mapped_file);
}

directory_handler *vfs::OpenDirectory(wstring dirname)
{ REFACTOR
  return CreateDirectory(dirname);
}

directory_handler *vfs::CreateDirectory(wstring dirname)
{
  return NEW MEMLEAK directory_handler(dirname);
}

void vfs::GetDiscSpace(dword &avaible, dword &total, dword &free)
{
  const dword drive_size = 2 REQUIRE_CPP11 REFACTOR GB;
  total = drive_size;
  avaible = drive_size;
  free = drive_size;
}