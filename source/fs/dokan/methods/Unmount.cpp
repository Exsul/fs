#include "methods_utils.h"


int dokan_proxy::Unmount(DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"Unmount", wstring(L""));
  return ERROR_NOT_READY;
}
