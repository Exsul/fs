#include "methods_utils.h"

int dokan_proxy::GetVolumeInformation(std::wstring &name, word &serial, word &max_filename_length, word &flags, std::wstring &file_system, DOKAN_FILE_INFO &dokan_info)
{
  HANDLER_BEGIN(L"GetVolumeInformation", name);

  name = L"PROTOTYPE";
  file_system = L"PROTOTYPE";
  serial = cached_serial = 30;
  max_filename_length = GETMAXVALUE(BITSINBYTE * 1);
  const int read_only = 0x00080000;
  flags = REFACTOR read_only;
  return 0;
}