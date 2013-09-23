#include "header.h"
#include "sqlite3.h"

//static WCHAR RootDirectory[MAX_PATH] = L"C:";
static WCHAR MountPoint[MAX_PATH] = L"M:";

void InitMethods( PDOKAN_OPERATIONS );
const char* SQL = "CREATE TABLE IF NOT EXISTS foo(handle,addr);";

void main()
{
  sqlite3 *db = 0; // хэндл объекта соединение к БД
  char *err = 0;
  if(sqlite3_open("handles.dblite", &db))
    ;
    //fprintf(stderr, "Ошибка открытия/создания БД: %s\n", sqlite3_errmsg(db));
  // выполняем SQL
  else if (sqlite3_exec(db, SQL, 0, 0, &err))
  {
    fprintf(stderr, "Ошибка SQL: %sn", err);
    sqlite3_free(err);
  }
  // закрываем соединение
  sqlite3_close(db);

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

  switch (status) {
  case DOKAN_SUCCESS:
	  fprintf(stderr, "Success\n");
	  break;
  case DOKAN_ERROR:
	  fprintf(stderr, "Error\n");
	  break;
  case DOKAN_DRIVE_LETTER_ERROR:
	  fprintf(stderr, "Bad Drive letter\n");
	  break;
  case DOKAN_DRIVER_INSTALL_ERROR:
	  fprintf(stderr, "Can't install driver\n");
	  break;
  case DOKAN_START_ERROR:
	  fprintf(stderr, "Driver something wrong\n");
	  break;
  case DOKAN_MOUNT_ERROR:
	  fprintf(stderr, "Can't assign a drive letter\n");
	  break;
  case DOKAN_MOUNT_POINT_ERROR:
	  fprintf(stderr, "Mount point error\n");
	  break;
  default:
	  fprintf(stderr, "Unknown error: %d\n", status);
	  break;
  }
  fflush(stderr);
}