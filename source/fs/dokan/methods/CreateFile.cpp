#include "methods_utils.h"

int dokan_proxy::CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"CreateFile", filename);

  DBG_ASSERT_RETURN(!dokan_info.Context, ERROR_BAD_COMMAND, (L"[ERROR] Context is not null"));
  
  try
  {
    attributes attr = Get().GetAttributes(filename);
    if (attr.Enabled(attributes::DIRECTORY))
      return CreateDirectory(filename, dokan_info);
  }
  catch (file_handler::file_not_found)
  {
  }

  DBG_ASSERT_RETURN(!dokan_info.IsDirectory, ERROR_BAD_COMMAND, (L"[ERROR] IsDirectory Flag set"));

  try
  {
    file_handler *fh = Get().CreateFile(filename, convert<access_rights>(access), convert<create_disposition>(share), convert<attributes>(flags));
    dokan_info.Context = reinterpret_cast<ULONG64>(fh);
    DbgPrint(L"creating context: 0x%.08X", dokan_info.Context);
  }
  catch (file_handler::access_denied)
  {
    DBG_RETURN(ERROR_ACCESS_DENIED, (L"[ERROR] AccessDenied"));
  }
  return 0;
}