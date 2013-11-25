#include "methods_utils.h"

int dokan_proxy::CreateDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"CreateDirectory", filename);
  dokan_info.IsDirectory = true;
  dokan_info.Context = reinterpret_cast<ULONG64>(Get().CreateDirectory(filename));
  return 0;
}