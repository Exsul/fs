#include "methods_utils.h"


int dokan_proxy::LockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"LockFile", filename);
  return ERROR_NOT_READY;
}
