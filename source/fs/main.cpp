#include "dokan.h"


//static WCHAR RootDirectory[MAX_PATH] = L"C:";
static WCHAR MountPoint[MAX_PATH] = L"M:";

//void InitMethods( PDOKAN_OPERATIONS );

//static factory *handlers;

void main()
{
  dokan t;
  t.InitDokan(MountPoint);
  dokan::DOKAN_STATUS status = t.StartDokan();
  /*
  handlers = new factory();
  PDOKAN_OPERATIONS oper = new DOKAN_OPERATIONS;
  PDOKAN_OPTIONS opt = new DOKAN_OPTIONS;

  memset(opt, 0, sizeof(DOKAN_OPTIONS));
  opt->Version = DOKAN_VERSION;
  opt->ThreadCount = 0; // use default
  opt->Options |= DOKAN_OPTION_DEBUG | DOKAN_OPTION_KEEP_ALIVE;
  //opt->Options |= DOKAN_OPTION_STDERR;
  opt->MountPoint = MountPoint;

  memset(oper, 0, sizeof(DOKAN_OPERATIONS));
  InitMethods(oper);

  int status = DokanMain(opt, oper);
  */
  switch (status) {
  case dokan::SUCCESS:
	  fprintf(stderr, "Success\n");
	  break;
  case dokan::GENERAL_ERROR:
	  fprintf(stderr, "Error\n");
	  break;
  case dokan::DRIVE_LETTER_ERROR:
	  fprintf(stderr, "Bad Drive letter\n");
	  break;
  case dokan::DRIVER_INSTALL_ERROR:
	  fprintf(stderr, "Can't install driver\n");
	  break;
  case dokan::START_ERROR:
	  fprintf(stderr, "Driver something wrong\n");
	  break;
  case dokan::MOUNT_ERROR:
	  fprintf(stderr, "Can't assign a drive letter\n");
	  break;
  case dokan::MOUNT_POINT_ERROR:
	  fprintf(stderr, "Mount point error\n");
	  break;
  default:
	  fprintf(stderr, "Unknown error: %d\n", status);
	  break;
  }
  fflush(stderr);
}