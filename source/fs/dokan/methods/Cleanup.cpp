#include "methods_utils.h"

int dokan_proxy::Cleanup(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"Cleanup", filename);
  DBG_ASSERT_RETURN(dokan_info.Context, ERROR_INVALID_HANDLE, (L"[ERROR] Zero context!"));
  if (dokan_info.IsDirectory)
  {
    directory_handler *dh = reinterpret_cast<directory_handler *>(dokan_info.Context);
    DbgPrint(L"Directory");
    delete dh;
  }
  else
  {
    file_handler *fh = reinterpret_cast<file_handler *>(dokan_info.Context);
    DbgPrint(L"File");
    delete fh;
  }
  dokan_info.Context = 0;
  DbgPrint(L"Cleaned");
  return 0;
}