#include "methods_utils.h"


int dokan_proxy::GetFileInformation(std::wstring name, BY_HANDLE_FILE_INFORMATION &buffer, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetFileInformation", name);
  auto attr = Get().GetAttributes(name);
  buffer.dwFileAttributes = convert<word>(attr);
  memset(&buffer.ftCreationTime, 0, sizeof(FILETIME));
  memset(&buffer.ftLastAccessTime, 0, sizeof(FILETIME));
  memset(&buffer.ftLastWriteTime, 0, sizeof(FILETIME));
  buffer.dwVolumeSerialNumber = cached_serial;
  buffer.nNumberOfLinks = 1;

  auto XOR32 = [](const wstring &buf)
  {
    word ret = 0;
    for each (wchar_t ch in buf)
      ret ^= ch;
    return ret;
  };

  auto CRC32 = [XOR32](const wstring &buf)
  {
    DbgPrint(L"TODO: CRC32");
    return XOR32(buf);
  };

  buffer.nFileIndexLow = XOR32(name);
  buffer.nFileSizeHigh = CRC32(name);

  if (dokan_info.IsDirectory)
  {
    auto *h = DeserializeContext<directory_handler>(dokan_info);
    DbgPrint(L"TODO: Write directory length");
    buffer.nFileSizeLow = 0;
    buffer.nFileSizeHigh = 0;
  }
  else
  {
    auto *h = DeserializeContext<file_handler>(dokan_info);
    auto length = h->Length();
    DbgPrint(L"TODO: Write file length");
  }
  return ERROR_SUCCESS;
}
