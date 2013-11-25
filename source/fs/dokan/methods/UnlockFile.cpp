#include "methods_utils.h"


int dokan_proxy::UnlockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"UnlockFile", filename);
  file_handler *h = DeserializeContext<file_handler>(dokan_info);
  DBG_ASSERT_RETURN(h->Unlock(), ERROR_INVALID_FUNCTION, (L"failed"));
  DBG_RETURN(ERROR_SUCCESS, (L"success"));
}
