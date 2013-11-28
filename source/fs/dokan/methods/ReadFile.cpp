#include "methods_utils.h"

int dokan_proxy::ReadFile(std::wstring filename, ub *buf, int to_read, int &readed, __int64 offset, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"ReadFile", filename);
  STANDART_FILE_CHECKS();
  DBG_ASSERT_RETURN(!offset, ERROR_INVALID_FUNCTION, (L"TODO: Write with not zero offset"));

  auto h = DeserializeContext<file_handler>(dokan_info);
  std::vector<ub> res = h->Read(to_read);
  std::copy(res.begin(), res.end(), buf);
  readed = res.size();

  return ERROR_SUCCESS;
}