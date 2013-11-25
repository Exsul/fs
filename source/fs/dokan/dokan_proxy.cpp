#include "methods\methods_utils.h"

vfs &dokan_proxy::Get()
{
  if (!worker)
    worker = new vfs();
  return *worker;
}

int dokan_proxy::CloseFile(std::wstring name, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"CloseFile", name);
  return 0;
}

int dokan_proxy::GetFileInformation(std::wstring name, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetFileInformation", name);
  return 0;
}