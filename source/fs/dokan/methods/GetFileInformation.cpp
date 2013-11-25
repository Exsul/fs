#include "methods_utils.h"


int dokan_proxy::GetFileInformation(std::wstring name, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetFileInformation", name);
  return 0;
}
