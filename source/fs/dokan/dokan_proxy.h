#include "dokan_cpp_port.h"

#include "../win_undef_names.h"
class vfs;
class dokan_proxy
{
  vfs *worker = nullptr;

  vfs &Get();
public:
  int CreateFile(std::wstring filename, int access, int share, int pos, word flags, DOKAN_FILE_INFO &dokan_info);
  int OpenDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int CreateDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int Cleanup(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int CloseFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int ReadFile(std::wstring filename, void *buf, int to_read, int &readed, __int64 offset, DOKAN_FILE_INFO &dokan_info);
  int WriteFile(std::wstring filename, const void *buf, int to_write, int &written, __int64 offset, DOKAN_FILE_INFO &dokan_info);
  int FlushFileBuffers(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int GetFileInformation(std::wstring filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info);
  int FindFiles(std::wstring filename, PFillFindData, DOKAN_FILE_INFO &dokan_info);
  int FindFilesWithPattern(std::wstring filename, std::wstring pattern, PFillFindData, DOKAN_FILE_INFO &dokan_info);
  int SetFileAttributes(std::wstring filename, int attr, DOKAN_FILE_INFO &dokan_info);
  int SetFileTime(std::wstring filename, const FILETIME &create, const FILETIME &la, const FILETIME &lw, DOKAN_FILE_INFO &dokan_info);
  int DeleteFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int DeleteDirectory(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int MoveFile(std::wstring filename, std::wstring new_filename, bool replace, DOKAN_FILE_INFO &dokan_info);
  int SetEndOfFile(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int SetAllocationSize(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int LockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int UnlockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int GetDiskFreeSpace(dword &avaib, dword &total, dword &free, DOKAN_FILE_INFO &dokan_info);
  int GetVolumeInformation(std::wstring &name, word &serial, word &max_filename_length, word &flags, std::wstring &file_system, DOKAN_FILE_INFO &dokan_info);
  int Unmount(DOKAN_FILE_INFO &dokan_info);
  int GetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, unsigned long &, DOKAN_FILE_INFO &dokan_info);
  int SetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, DOKAN_FILE_INFO &dokan_info);

  ~dokan_proxy();
};