#include "methods_utils.h"

int dokan_proxy::MoveFile(std::wstring filename, std::wstring new_filename, bool replace, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"MoveFile", filename);
  return ERROR_NOT_READY;
}
