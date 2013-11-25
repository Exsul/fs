#include "methods\methods_utils.h"

vfs &dokan_proxy::Get()
{
  if (!worker)
    worker = new vfs();
  return *worker;
}

dokan_proxy::~dokan_proxy()
{
  if (worker)
    delete worker;
}


