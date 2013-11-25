#include "methods_utils.h"

int dokan_proxy::WriteFile(std::wstring filename, const void *buf, int to_write, int &written, __int64 offset, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"WriteFile", filename);
  return ERROR_NOT_READY;
}