#include "methods_utils.h"

int dokan_proxy::SetFileAttributes(std::wstring filename, int attr, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"SetFileAttributes", filename);
  return ERROR_NOT_READY;
}



