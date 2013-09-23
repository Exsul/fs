#include <string>
#include "header.h"

class fs
{
  int CreateFile(std::string filename, int access, int share, int pos, int flags, DOKAN_FILE_INFO &dokan_info );
  int OpenDirectory( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int CreateDirectory( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int Cleanup( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int CloseFile( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int ReadFile( std::string filename, void *buf, int to_read, int &readed, __int64 offset, DOKAN_FILE_INFO &dokan_info );
  int WriteFile( std::string filename, void *buf, int to_write, int &written, __int64 offset, DOKAN_FILE_INFO &dokan_info );
  int FlushFileBuffers( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int GetFileInformation( std::string filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info );
  int FindFiles( std::string filename, PFillFindData, DOKAN_FILE_INFO &dokan_info );
  int FindFilesWithPattern( std::string filename, std::string pattern, PFillFindData, DOKAN_FILE_INFO &dokan_info );
  int SetFileAttributes( std::string filename, int attr, DOKAN_FILE_INFO &dokan_info );
  int SetFileTime( std::string filename, FILETIME &create, FILETIME &la, FILETIME &lw, DOKAN_FILE_INFO &dokan_info );
  int DeleteFile( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int DeleteDirectory( std::string filename, DOKAN_FILE_INFO &dokan_info );
  int MoveFile( std::string filename, std::string new_filename, bool replace, DOKAN_FILE_INFO &dokan_info );
  int SetEndOfFile( std::string filename, __int64 length, DOKAN_FILE_INFO &dokan_info );
  int SetAllocationSize( std::string filename, __int64 length, DOKAN_FILE_INFO &dokan_info );
  int LockFile( std::string filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info );
  int UnlockFile( std::string filename, __int64 offset, __int64 length, DOKAN_FILE_INFO &dokan_info );
  int GetDiskFreeSpace( __int64 &avaib, __int64 &total, __int64 &free, DOKAN_FILE_INFO &dokan_info );
  int GetVolumeInformation( std::string name, int &serial, int &maximum_length, int &flags, std::string file_system, DOKAN_FILE_INFO &dokan_info );
  int Unmount ( DOKAN_FILE_INFO &dokan_info );
  int GetFileSecurity( std::string name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, int &, DOKAN_FILE_INFO &dokan_info );
  int SetFileSecurity( std::string name, PSECURITY_INFORMATION, PSECURITY_DESCRIPTOR, int, DOKAN_FILE_INFO &dokan_info );
};