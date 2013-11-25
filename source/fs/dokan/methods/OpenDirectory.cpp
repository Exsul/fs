#include "methods_utils.h"

int dokan_proxy::OpenDirectory(wstring dirname, DOKAN_FILE_INFO &dokan_info)
{
  DbgPrint(L">OpenDirectory: %s", dirname.c_str());
  auto level = DbgPrint.Down();
  try
  {
    directory_handler &dh = Get().OpenDirectory(dirname);
    delete &dh;
  } catch (directory_handler::directory_not_found &)
  {
    DbgPrint(L"NotFound");
    return ERROR_FILE_NOT_FOUND;
  }
  if (!dokan_info.IsDirectory)
    dokan_info.IsDirectory = true;
  return 0;
}