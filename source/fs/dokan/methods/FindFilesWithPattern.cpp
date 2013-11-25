#include "methods_utils.h"

int dokan_proxy::FindFilesWithPattern(std::wstring filename, std::wstring pattern, PFillFindData, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"FindFilesWithPattern", filename);
  return ERROR_NOT_READY;
}
