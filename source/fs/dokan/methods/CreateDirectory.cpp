#include "methods_utils.h"

int dokan_proxy::CreateDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  todo(Create directory);
  HANDLER_BEGIN(L"CreateDirectory", filename);
  Get().CreateDirectory(filename);
}