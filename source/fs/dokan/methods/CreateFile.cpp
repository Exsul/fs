#include "methods_utils.h"

int dokan_proxy::CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"CreateFile", filename);

  DBG_ASSERT_RETURN(!dokan_info.IsDirectory, ERROR_BAD_COMMAND, (L"[ERROR] IsDirectory Flag set"));
  DBG_ASSERT_RETURN(!dokan_info.Context, ERROR_BAD_COMMAND, (L"[ERROR] Context is not null"));

  REFACTOR // GetFileAttributes to check is it directory
  try
  {
    file_handler &fh = Get().CreateFile(filename, convert<access_rights>(access), convert<create_disposition>(share), convert<attributes>(flags));
    dokan_info.Context = reinterpret_cast<ULONG64>(&fh);
    DbgPrint(L"Creating context: %li", dokan_info.Context);
  } catch (file_handler::file_not_found)
  {
    DbgPrint(L"NotFound, trying as directory");
    DBG_ASSERT_RETURN(!OpenDirectory(filename, dokan_info), ERROR_FILE_NOT_FOUND, (L"NotFound"));
    DBG_RETURN(0, (L"IsDirectory"));
  } catch (file_handler::access_denied)
  {
    DBG_RETURN(ERROR_ACCESS_DENIED, (L"AccessDenied"));
  }
  return 0;
}