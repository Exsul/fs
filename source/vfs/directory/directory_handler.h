#include "../stdafx.h"
struct directory_handler : object
{
  wstring name;

  directory_handler(wstring name) : name(name)
  {
  }
};