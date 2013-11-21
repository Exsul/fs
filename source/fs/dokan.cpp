#include "dokan.h"

PDOKAN_OPERATIONS dokan::oper = nullptr;
PDOKAN_OPTIONS dokan::opt = nullptr;
bool dokan::inited = false;

void InitMethods(PDOKAN_OPERATIONS);

void dokan::InitDokan( std::wstring mount_point )
{
  throw_assert(!inited);
  inited = true;

  oper = NEW DOKAN_OPERATIONS;
  opt = NEW DOKAN_OPTIONS;
  memset(opt, 0, sizeof(DOKAN_OPTIONS));
  opt->Version = DOKAN_VERSION;
  opt->ThreadCount = 0; // use default
  opt->Options |= DOKAN_OPTION_DEBUG | DOKAN_OPTION_KEEP_ALIVE;

  //ax::StrFastCopy<wchar_t>(opt->MountPoint, mount_point.c_str());
  memset(oper, 0, sizeof(DOKAN_OPERATIONS));
  InitMethods(oper);
}

dokan::DOKAN_STATUS dokan::StartDokan()
{
}