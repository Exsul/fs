#include "methods_utils.h"

int dokan_proxy::OpenDirectory(wstring dirname, DOKAN_FILE_INFO &dokan_info)
{
  try
  {
    directory_handler &dh = Get().OpenDirectory(dirname);
    delete &dh;
  } catch (directory_handler::directory_not_found &)
  {
    return ERROR_FILE_NOT_FOUND;
  }
  if (!dokan_info.IsDirectory)
    dokan_info.IsDirectory = true;
  return 0;
}