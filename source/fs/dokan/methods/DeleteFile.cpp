#include "methods_utils.h"

int dokan_proxy::DeleteFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"DeleteFile", filename);
  return ERROR_NOT_READY;
}
