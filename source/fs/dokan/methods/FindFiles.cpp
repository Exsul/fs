#include "methods_utils.h"
#include "../../../vfs/directory/directory.h"

int dokan_proxy::FindFiles(std::wstring filename, PFillFindData func, DOKAN_FILE_INFO &dokan_info)
{
  directory_handler dh = Get().OpenDirectory(filename);
  directory d(dh);

  auto Callback = [func, &dokan_info](const file_find_data &fd)
  {
    PDOKAN_FILE_INFO pdk = &dokan_info;
    WIN32_FIND_DATAW data;
    memset(&data, 0, sizeof(WIN32_FIND_DATAW));
    auto CopyFileName = [&data, fd]()
    {
      const int max_strlen = sizeof(data.cFileName) / sizeof(data.cFileName[0]) - 1;
      ax::StrCopy(data.cFileName, fd.filename.c_str(), max_strlen);
    };
    CopyFileName();

    auto SetSize = [&data, fd]()
    {
      if (sizeof(data.nFileSizeLow) < sizeof(fd.size))
      {
        auto bits = sizeof(data.nFileSizeLow) * BITSINBYTE;
        decltype(fd.size) max = GETMAXVALUE(bits);
        data.nFileSizeLow = convert<DWORD>(fd.size & max);
        data.nFileSizeHigh = convert<DWORD>(fd.size >> bits);
      } else
      {
        data.nFileSizeHigh = 0;
        data.nFileSizeLow = convert<DWORD>(fd.size);
      }
    };
    SetSize();

    data.dwFileAttributes = convert<word>(fd.attr);
  };
  d.FindFiles(L"*", Callback);
  /*
  DbgPrint(L"FindFiles %s\n", filename.c_str());
  WIN32_FIND_DATAW data;
  wcscpy(data.cFileName, L"README.txt");
  func(&data, &dokan_info);
  */
  return 0;
}