#include "methods_utils.h"
#include <algorithm>

int dokan_proxy::WriteFile(std::wstring filename, const ub *buf, int to_write, int &written, __int64 offset, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"WriteFile", filename);
  STANDART_FILE_CHECKS();
  DBG_ASSERT_RETURN(!offset, ERROR_INVALID_FUNCTION, (L"TODO: Write with not zero offset"));

  auto h = DeserializeContext<file_handler>(dokan_info);
  std::vector<ub> data(buf, buf + to_write);
  written = h->Write(data);
  return ERROR_SUCCESS;
}