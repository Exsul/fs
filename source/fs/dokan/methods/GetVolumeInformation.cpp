#include "methods_utils.h"

int dokan_proxy::GetVolumeInformation(std::wstring &name, word &serial, word &max_filename_length, word &flags, std::wstring &file_system, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetVolumeInformation", name);

  name = L"PROTOTYPE";
  file_system = L"PROTOTYPE";
  serial = cached_serial = 30;
  max_filename_length = GETMAXVALUE(BITSINBYTE * 1);

  flags =
    FILE_CASE_SENSITIVE_SEARCH |
    FILE_CASE_PRESERVED_NAMES |
    FILE_SUPPORTS_REMOTE_STORAGE |
    FILE_UNICODE_ON_DISK |
    FILE_PERSISTENT_ACLS;
  return 0;
}