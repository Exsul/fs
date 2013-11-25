#include "vfs.h"
#include "internal.h"
#include <windows.h>

attributes vfs::GetAttributes(wstring path)
{
  DWORD attr = GetFileAttributesW(Cache(path).c_str());
  if (attr == INVALID_FILE_ATTRIBUTES)
    throw file_handler::file_not_found();
  return convert<attributes, word>(attr);
}