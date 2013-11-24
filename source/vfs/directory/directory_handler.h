#ifndef _VFS_DIRECTORY_HANDLER_H_
#define _VFS_DIRECTORY_HANDLER_H_

#include "../stdafx.h"
struct directory_handler : object
{
  wstring name;

  directory_handler(wstring name);
};

#endif