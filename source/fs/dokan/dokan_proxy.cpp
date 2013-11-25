#include "methods\methods_utils.h"

vfs &dokan_proxy::Get()
{
  if (!worker)
    worker = new vfs();
  return *worker;
}

int dokan_proxy::Cleanup(std::wstring name, DOKAN_FILE_INFO &dokan_info)
{
  DbgPrint(L">Cleanup: %s", name.c_str());
  dokan_info.Context = 0;
  return 0;
}

int dokan_proxy::CloseFile(std::wstring name, DOKAN_FILE_INFO &dokan_info)
{
  DbgPrint(L">CloseFile: %s", name.c_str());
  dokan_info.Context = 0;
  return 0;
}

int dokan_proxy::GetFileInformation(std::wstring name, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info)
{
  DbgPrint(L">GetFileInformation: %s", name.c_str());
  return 0;
}