#include "methods_utils.h"

int dokan_proxy::FlushFileBuffers(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"FlushFileBuffers", filename);
  return ERROR_NOT_READY;
}