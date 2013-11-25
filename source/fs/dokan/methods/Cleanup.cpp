#include "methods_utils.h"

int dokan_proxy::Cleanup(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"Cleanup", filename);
  DBG_ASSERT_RETURN(dokan_info.Context, ERROR_INVALID_HANDLE, (L"[ERROR] zero context!"));

  if (dokan_info.IsDirectory)
  {
    directory_handler *dh = reinterpret_cast<directory_handler *>(dokan_info.Context);
    DbgPrint(L"is directory");
    delete dh;
  }
  else
  {
    file_handler *fh = reinterpret_cast<file_handler *>(dokan_info.Context);
    DbgPrint(L"is file");
    delete fh;
  }
  DbgPrint(L"cleaned 0x%.08X", dokan_info.Context);
  dokan_info.Context = 0;
  return 0;
}