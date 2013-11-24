#include "dokan.h"
#include "dokan_proxy.h"

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

  memset(oper, 0, sizeof(DOKAN_OPERATIONS));
  memset(opt, 0, sizeof(DOKAN_OPTIONS));

  opt->GlobalContext = reinterpret_cast<ULONG64>(NEW dokan_proxy());
  opt->ThreadCount = 1;
  opt->Version = DOKAN_VERSION;
  opt->ThreadCount = 0; // use default
  opt->Options |= DOKAN_OPTION_DEBUG | DOKAN_OPTION_KEEP_ALIVE;


  auto CopyMountPoint = [&]( const std::wstring &source)
  {
    wchar_t *dest = nullptr;
    ax::StrFastCopy(dest, source.c_str());
    opt->MountPoint = dest;
  };

  CopyMountPoint(mount_point);
  InitMethods(oper);
}

dokan::DOKAN_STATUS dokan::StartDokan()
{
  int status = DokanMain(opt, oper);
  return convert<DOKAN_STATUS>(status);
}