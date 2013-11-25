#include "methods_utils.h"


int dokan_proxy::LockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"LockFile", filename);
  file_handler *h = DeserializeContext<file_handler>(dokan_info);
  DBG_ASSERT_RETURN(h->Lock(), ERROR_INVALID_FUNCTION, (L"failed"));
  DBG_RETURN(ERROR_SUCCESS, (L"success"));
}
