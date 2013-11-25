#include "methods_utils.h"

int dokan_proxy::SetFileTime(std::wstring filename, const FILETIME &create, const FILETIME &la, const FILETIME &lw, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"SetFileTime", filename);
  return ERROR_NOT_READY;
}
