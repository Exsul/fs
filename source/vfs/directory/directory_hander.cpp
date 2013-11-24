#include "directory_handler.h"
#include "../internal.h"
#include "directory.h"
#include <Windows.h>

directory_handler::directory_handler(wstring name)
: name(Cache(name))
{
  REFACTOR
  // http://stackoverflow.com/questions/8233842/how-to-check-if-directory-exist-using-c-and-winapi
  DWORD ftyp = GetFileAttributesW(name.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    throw directory_not_found();
  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return;
  throw directory_not_found();
}