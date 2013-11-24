/* minwinbase.h
typedef struct _WIN32_FIND_DATAW
{
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  _Field_z_ WCHAR  cFileName[ MAX_PATH ];
  _Field_z_ WCHAR  cAlternateFileName[ 14 ];
  #ifdef _MAC
  DWORD dwFileType;
  DWORD dwCreatorType;
  WORD  wFinderFlags;
  #endif
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
*/

#include "../stdafx.h"
#include "../file/attributes.h"

// struct _WIN32_FIND_DATAW
struct file_find_data
{
  wstring filename;
  dword size;
  attributes attr;
};