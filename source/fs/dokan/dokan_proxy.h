#include "dokan_cpp_port.h"

#undef CreateFile
class vfs;
class dokan_proxy
{
  vfs *worker;

  vfs &Get();
public:
  int CreateFile(std::wstring filename, int access, int share, int pos, int flags, DOKAN_FILE_INFO &dokan_info);
  int OpenDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int CreateDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int Cleanup(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int CloseFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int ReadFile(std::wstring filename, void *buf, int to_read, int &readed, __int64 offset, DOKAN_FILE_INFO &dokan_info);
  int WriteFile(std::wstring filename, void *buf, int to_write, int &written, __int64 offset, DOKAN_FILE_INFO &dokan_info);
  int FlushFileBuffers(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int GetFileInformation(std::wstring filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info);
  int FindFiles(std::wstring filename, PFillFindData, DOKAN_FILE_INFO &dokan_info);
  int FindFilesWithPattern(std::wstring filename, std::wstring pattern, PFillFindData, DOKAN_FILE_INFO &dokan_info);
  int SetFileAttributes(std::wstring filename, int attr, DOKAN_FILE_INFO &dokan_info);
  int SetFileTime(std::wstring filename, FILETIME &create, FILETIME &la, FILETIME &lw, DOKAN_FILE_INFO &dokan_info);
  int DeleteFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int DeleteDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int MoveFile(std::wstring filename, std::wstring new_filename, bool replace, DOKAN_FILE_INFO &dokan_info);
  int SetEndOfFile(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int SetAllocationSize(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int LockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int UnlockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int GetDiskFreeSpace(__int64 &avaib, __int64 &total, __int64 &free, DOKAN_FILE_INFO &dokan_info);
  int GetVolumeInformation(std::wstring name, DWORD &serial, DWORD &maximum_length, DWORD &flags, std::wstring file_system, DOKAN_FILE_INFO &dokan_info);
  int Unmount(DOKAN_FILE_INFO &dokan_info);
  int GetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, int &, DOKAN_FILE_INFO &dokan_info);
  int SetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, DOKAN_FILE_INFO &dokan_info);
};