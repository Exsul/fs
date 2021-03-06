#include "methods_utils.h"

int dokan_proxy::OpenDirectory(wstring dirname, DOKAN_FILE_INFO &dokan_info)
{
  if (dokan_info.Context)
    return ERROR_BAD_COMMAND;

  HANDLER_BEGIN(L"OpenDirectory", dirname);

  try
  {
    directory_handler *dh = Get().OpenDirectory(dirname);
    dokan_info.Context = reinterpret_cast<ULONG64>(dh);
    DbgPrint(L"Creating context: 0x%.08X", dokan_info.Context);
  } catch (directory_handler::directory_not_found &)
  {
    DBG_RETURN(ERROR_FILE_NOT_FOUND, (L"NotFound"));
  }
  throw_assert(dokan_info.Context);
  if (!dokan_info.IsDirectory)
    dokan_info.IsDirectory = true;
  return 0;
}