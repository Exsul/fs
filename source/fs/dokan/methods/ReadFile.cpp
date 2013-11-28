#include "methods_utils.h"

int dokan_proxy::ReadFile(std::wstring filename, ub *buf, int to_read, int &readed, __int64 offset, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"ReadFile", filename);
  return ERROR_NOT_READY;
}