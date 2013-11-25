#include "methods_utils.h"


int dokan_proxy::CloseFile(std::wstring name, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"CloseFile", name);
  return 0;
}