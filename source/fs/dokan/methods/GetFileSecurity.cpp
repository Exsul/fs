#include "methods_utils.h"


int dokan_proxy::GetFileSecurity(std::wstring filename, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, unsigned long &, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetFileSecurity", filename);
  return ERROR_NOT_READY;
}
