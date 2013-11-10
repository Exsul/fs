#include <vector>

#include "../header.h"
#include "file_handler.h"

using namespace std;

class file : ax::object
{
public:
  virtual void Close() = 0;
  virtual vector<byte> Read(word amount, dword offset = 0) = 0;
  virtual word Write(vector<byte> data, dword offset = 0) = 0;
  virtual void Flush() = 0;
  virtual void Cleanup() = 0;

/*/
  int GetFileInformation(std::wstring filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info);
  int SetFileAttributes(std::wstring filename, int attr, DOKAN_FILE_INFO &dokan_info);
  int SetFileTime(std::wstring filename, FILETIME &create, FILETIME &la, FILETIME &lw, DOKAN_FILE_INFO &dokan_info);
  int DeleteFile(std::wstring filename, DOKAN_FILE_INFO &dokan_info);
  int MoveFile(std::wstring filename, std::wstring new_filename, bool replace, DOKAN_FILE_INFO &dokan_info);

  int SetEndOfFile(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int SetAllocationSize(std::wstring filename, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int LockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);
  int UnlockFile(std::wstring filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info);

  int GetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, int &, DOKAN_FILE_INFO &dokan_info);
  int SetFileSecurity(std::wstring name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, DOKAN_FILE_INFO &dokan_info);

//*/
};