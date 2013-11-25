#include "methods_utils.h"

int dokan_proxy::DeleteDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"DeleteDirectory", filename);
  return ERROR_NOT_READY;
}
