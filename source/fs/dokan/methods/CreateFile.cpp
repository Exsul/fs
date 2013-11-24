#include "methods_utils.h"

int dokan_proxy::CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info)
{
  REFACTOR // GetFileAttributes to check is it directory
  try
  {
    file_handler &fh = Get().CreateFile(filename, convert<access_rights>(access), convert<create_disposition>(share), convert<attributes>(flags));
    delete &fh;
  } catch (file_handler::file_not_found)
  {
    if (!OpenDirectory(filename, dokan_info))
    {
      DbgPrint(L"CreateFile: IsDirectory %s", filename.c_str());
      return 0;
    }
    DbgPrint(L"CreateFile: NotFound %s", filename.c_str());
    return ERROR_FILE_NOT_FOUND;
  } catch (file_handler::access_denied)
  {
    DbgPrint(L"CreateFile: AccessDenied %s", filename.c_str());
    return ERROR_ACCESS_DENIED;
  }
  dokan_info.Context = 30;
  return 0;
}