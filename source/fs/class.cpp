#include "class.h"
#include <iostream>

static void DbgPrint(LPCWSTR format, ...)
{
  WCHAR buffer[512];
  va_list argp;
  va_start(argp, format);
  vswprintf_s(buffer, sizeof(buffer)/sizeof(WCHAR), format, argp);
  va_end(argp);
  OutputDebugStringW(buffer);
  std::wstring t = buffer;
  std::wcout << t << std::endl;
}

int fs::CreateFile( std::wstring filename, int access, int share, int pos, int flags, DOKAN_FILE_INFO &dokan_info )
{
  DbgPrint(L"CreateFile %s\n", filename.c_str());
  dokan_info.Context = 30;
  return 0;
}

int fs::OpenDirectory( std::wstring filename, DOKAN_FILE_INFO &dokan_info )
{
  DbgPrint(L"OpenDirectory %s\n", filename.c_str());
  dokan_info.Context = 30;
  return 0;
}

int fs::FindFiles( std::wstring filename, PFillFindData func, DOKAN_FILE_INFO &dokan_info )
{
  DbgPrint(L"FindFiles %s\n", filename.c_str());
  WIN32_FIND_DATAW data;
  wcscpy(data.cFileName, L"README.txt");
  func(&data, &dokan_info);
  return 0;
}

int fs::GetVolumeInformation( std::wstring name, DWORD &serial, DWORD &maximum_length, DWORD &flags, std::wstring file_system, DOKAN_FILE_INFO &dokan_info )
{
  return ERROR_NOT_READY * -1;
}

int fs::Cleanup( std::wstring name, DOKAN_FILE_INFO &dokan_info )
{
  dokan_info.Context = 0;
  return 0;
}

int fs::CloseFile( std::wstring name, DOKAN_FILE_INFO &dokan_info )
{
  dokan_info.Context = 0;
  return 0;
}

int fs::GetFileInformation( std::wstring filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info )
{
  return 0;
}