#include "vfs.h"
#include <windows.h>

attributes vfs::GetAttributes(wstring path)
{
  DWORD attr = GetFileAttributesW(path.c_str());
  if (attr == INVALID_FILE_ATTRIBUTES)
    throw file_handler::file_not_found();
  return convert<attributes, word>(attr);
}