#include "methods_utils.h"


int dokan_proxy::GetDiskFreeSpace(dword &avaib, dword &total, dword &free, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetDiskFreeSpace", wstring(L""));
  return ERROR_NOT_READY;
}
