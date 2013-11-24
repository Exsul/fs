#include "dokan\dokan.h"


//static WCHAR RootDirectory[MAX_PATH] = L"C:";
static WCHAR MountPoint[MAX_PATH] = L"M:";

//void InitMethods( PDOKAN_OPERATIONS );

//static factory *handlers;

struct t
{
  t()
  {
    throw_message("Hello");
  }
};

void main()
{
  dokan t;
  t.InitDokan(MountPoint);
  dokan::DOKAN_STATUS status = t.StartDokan();

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