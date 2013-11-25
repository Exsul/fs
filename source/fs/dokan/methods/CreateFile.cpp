#include "methods_utils.h"

int dokan_proxy::CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info)
{
  DbgPrint(L">CreateFile %s", filename.c_str());
  auto level = DbgPrint.Down();
  REFACTOR // GetFileAttributes to check is it directory
  try
  {
    file_handler &fh = Get().CreateFile(filename, convert<access_rights>(access), convert<create_disposition>(share), convert<attributes>(flags));
    delete &fh;
  } catch (file_handler::file_not_found)
  {
    DbgPrint(L"NotFound, trying as directory");
    if (!OpenDirectory(filename, dokan_info))
    {
      DbgPrint(L"IsDirectory");
      return 0;
    }
    DbgPrint(L"NotFound");
    return ERROR_FILE_NOT_FOUND;
  } catch (file_handler::access_denied)
  {
    DbgPrint(L"AccessDenied");
    return ERROR_ACCESS_DENIED;
  }
  dokan_info.Context = 30;
  return 0;
}