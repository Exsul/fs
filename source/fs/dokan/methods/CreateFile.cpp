#include "methods_utils.h"

int dokan_proxy::CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info)
{
  if (filename == L"\\")
    return 0;
  Get().CreateFile(filename, convert<access_rights>(access), convert<create_disposition>(share), convert<attributes>(flags));
//  DbgPrint(L"CreateFile %s\n", filename.c_str());
  dokan_info.Context = 30;
  return 0;
}