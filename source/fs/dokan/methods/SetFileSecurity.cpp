#include "methods_utils.h"


int dokan_proxy::SetFileSecurity(std::wstring filename, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"SetFileSecurity", filename);
  return ERROR_NOT_READY;
}
