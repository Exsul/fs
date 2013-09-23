#include "sqlite3.h"
#include "class.h"

class factory
{
  sqlite3 *db;

  enum LOCK_STATUS
  {
    LOCKED = 1,
    UNLOCKED = 0,
    UNUSED = 5
  }
public:
  factory()
  {
    sqlite3_open("handles.dblite", &db);
    char *err = 0;
const char* SQL = "CREATE TABLE IF NOT EXSISTS \"main\".\"handles\" ( \
\"handle\"  INTEGER,                                    \
\"memory\"  INTEGER,                                    \
\"file\"  TEXT,                                         \
\"lock\"  INTEGER DEFAULT false                         \
)                                                       \
;";
    sqlite3_exec(db, SQL, 0, 0, &err);
  }

  fs &ClassByName( std::wstring name, int &handle )
  {
    LOCK_STATUS locked;
    while (true)
    {
      sqlite3_exec(db, "BEGIN EXCLUSIVE TRANSACTION;");
      locked = Locked(name);
      if (locked != LOCKED)
        break;
      sqlite3_exec(db, "ROLLBACK;");
      Sleep(5);
    }
    sqlite3_stmt *stmt = NULL;
    void *mem;
    
    if (locked == UNLOCKED)
    {
      sqlite3_prepare16(db, L"update handles set lock=true where file=?", -1, &stmt, NULL );
      sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
      sqlite3_step(stmt);
      sqlite3_finalize(stmt);

      sqlite3_prepare16(db, L"select memory,handle from handles where file=?", -1, &stmt, NULL );
      sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
      sqlite3_step(stmt);
      mem = (void *)sqlite3_column_int(stmt, 0);
      handle = (void *)sqlite3_column_int(stmt, 1);
      sqlite3_finalize(stmt);
    }

    const char* SQL = "BEGIN EXCLUSIVE TRANSACTION; \
SELECT memory FROM handlers WHERE file=?;

    sqlite3_exec(db, "COMMIT;");
  }


  ~factory()
  {
    sqlite3_close(db);
  }

private:
  LOCK_STATUS Locked( std::wstring name )
  {
    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare16(db, L"select lock from handles where file=$1", -1, &stmt, NULL );
    sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    int locked = UNUSED;
    if (sqlite3_step( stmt ) == SQLITE_ROW)
      locked = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return locked;
  }
};