#include "stdafx.h"
#include <string>
#include "file/file_handler.h"
#include "file/access_rights.h"
#include "file/create_disposition.h"
#include "file/attributes.h"

#include "directory\directory_handler.h"

using namespace std;

class vfs
{
public:
  file_handler CreateFile(wstring filename, access_rights, create_disposition, attributes);
  file_handler CreateFile(wstring filename);
  file_handler OpenFile(wstring filename);

  directory_handler OpenDirectory(wstring dirname);
  directory_handler CreateDirectory(wstring dirname);

  void GetDiscSpace(dword &avaible, dword &total, dword &free);
/*/
  int Cleanup(std::wstring filename, DOKAN_FILE_INFO &dokan_info);

  int GetDiskFreeSpace(__int64 &avaib, __int64 &total, __int64 &free, DOKAN_FILE_INFO &dokan_info);
  int GetVolumeInformation(std::wstring name, DWORD &serial, DWORD &maximum_length, DWORD &flags, std::wstring file_system, DOKAN_FILE_INFO &dokan_info);
  int Unmount(DOKAN_FILE_INFO &dokan_info);
//*/
};