#include "methods_utils.h"

int dokan_proxy::SetAllocationSize(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"SetAllocationSize", filename);
  return ERROR_NOT_READY;
}
