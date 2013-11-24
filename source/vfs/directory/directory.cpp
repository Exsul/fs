#include "directory.h"
#include "../internal.h"
#include <windows.h>

directory::directory(directory_handler &_dh)
: dh(_dh)
{
}

template<>
file_find_data convert(const WIN32_FIND_DATAW &data)
{
  decltype(file_find_data::size) size = data.nFileSizeLow;
  throw_sassert(!data.nFileSizeHigh, "We didnt expect file with that size. Please bug report!");
  //size += data.nFileSizeHigh << (sizeof(data.nFileSizeLow) * BITSINBYTE);
  return file_find_data{data.cFileName, size, convert<attributes, word>(data.dwFileAttributes)};
}

void directory::FindFiles(MAYBEWRONG wstring filename, file_found_callback callback)
{
  auto search = ConCat(dh.name, filename);
  WIN32_FIND_DATAW data;
  auto h = FindFirstFileW(search.c_str(), &data);

  if (h == INVALID_HANDLE_VALUE)
    return;

  do
    callback(convert<file_find_data>(data));
  while (FindNextFileW(h, &data));

  auto error = GetLastError();
  throw_sassert(error == ERROR_NO_MORE_FILES, "Unexpected FindFile result");//, std::to_string(error)));
  FindClose(h);
}