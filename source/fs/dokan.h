#ifndef _FS_DOKAN_H_
#define _FS_DOKAN_H_

#include "header.h"
#include "dokan_cpp_port.h"

class dokan
{
  static PDOKAN_OPERATIONS oper;
  static PDOKAN_OPTIONS opt;
  static bool inited;
public:
  enum DOKAN_STATUS;
  static void InitDokan(std::wstring mount_point);
  static DOKAN_STATUS StartDokan();

  enum DOKAN_STATUS
  {
    SUCCESS = 0,
    GENERAL_ERROR = -1, /* General Error */
    DRIVE_LETTER_ERROR = -2, /* Bad Drive letter */
    DRIVER_INSTALL_ERROR= -3, /* Can't install driver */
    START_ERROR = -4, /* Driver something wrong */
    MOUNT_ERROR = -5, /* Can't assign a drive letter or mount point */
    MOUNT_POINT_ERROR = -6, /* Mount point is invalid */
  };
};

#endif