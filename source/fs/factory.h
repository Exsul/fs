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
  };

public:
  factory()
  {
    sqlite3_open("handles.dblite", &db);
    char *err = 0;
const char* SQL = "CREATE TABLE \"main\".\"NewTable\" (   \
\"handle\"  INTEGER,                                      \
\"memory\"  INTEGER,                                      \
\"file\"  TEXT,                                           \
\"lock\"  INTEGER DEFAULT false,                          \
CONSTRAINT \"memory_unique\" UNIQUE (\"memory\"),         \
CONSTRAINT \"file_unique\" UNIQUE (\"file\")              \
);                                                        \
                                                          \
CREATE UNIQUE INDEX \"main\".\"handle_index\"             \
ON \"NewTable\" (\"handle\" ASC);                         \
                                                          \
                                                          \
;";
    sqlite3_exec(db, SQL, 0, 0, &err);
  }


  fs &ClassByName( std::wstring name, int &handle )
  {
    LOCK_STATUS locked;
    while (true)
    {
      sqlite3_exec(db, "BEGIN EXCLUSIVE TRANSACTION;", 0, 0, 0);
      locked = Locked(name);
      if (locked != LOCKED)
        break;
      sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
      Sleep(5);
    }
    sqlite3_stmt *stmt = NULL;
    if (locked == UNUSED)
    {
      sqlite3_prepare16(db, L"insert into handles(memory,file) values(?1,?2)", -1, &stmt, NULL );
      sqlite3_bind_int(stmt, 1, reinterpret_cast<int>(new fs));
      sqlite3_bind_text16(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT);
      sqlite3_step(stmt);
      sqlite3_finalize(stmt);
      locked = Locked(name);
    }
    sqlite3_prepare16(db, L"update handles set lock=true where file=?", -1, &stmt, NULL );
    sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    sqlite3_prepare16(db, L"select memory,handle from handles where file=?", -1, &stmt, NULL );
    sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);

    int mem = sqlite3_column_int(stmt, 0);
    handle = sqlite3_column_int(stmt, 1);
    sqlite3_finalize(stmt);
    sqlite3_exec(db, "COMMIT;", 0, 0, 0);
    return *reinterpret_cast<fs *>(mem);
  }

  fs *ClassByHandle( int handle )
  {
    LOCK_STATUS locked;
    while (true)
    {
      sqlite3_exec(db, "BEGIN EXCLUSIVE TRANSACTION;", 0, 0, 0);
      locked = Locked(handle);
      if (locked != LOCKED)
        break;
      sqlite3_exec(db, "ROLLBACK;", 0, 0, 0);
      Sleep(5);
    }

    sqlite3_stmt *stmt = NULL;

    sqlite3_prepare16(db, L"update handles set lock=true where handle=?", -1, &stmt, NULL );
    sqlite3_bind_int(stmt, 1, handle);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    sqlite3_prepare16(db, L"select memory,handle from handles where handle=?", -1, &stmt, NULL );
    sqlite3_bind_int(stmt, 1, handle);
    int mem = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
      mem = sqlite3_column_int(stmt, 0);
      handle = sqlite3_column_int(stmt, 1);
    }
    sqlite3_finalize(stmt);
    sqlite3_exec(db, "COMMIT;", 0, 0, 0);
    return reinterpret_cast<fs *>(mem);
  }


  ~factory()
  {
    sqlite3_close(db);
  }

private:
  LOCK_STATUS Locked( std::wstring name )
  {
    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare16(db, L"select lock from handles where file=?1", -1, &stmt, NULL );
    sqlite3_bind_text16(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    return LockedInternal(*stmt);
  }

  LOCK_STATUS Locked( int handle )
  {
    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare16(db, L"select lock from handles where handle=?1", -1, &stmt, NULL );
    sqlite3_bind_int(stmt, 1, handle);
    return LockedInternal(*stmt);
  }


  LOCK_STATUS LockedInternal( sqlite3_stmt &stmt )
  {
    int locked = UNUSED;
    if (sqlite3_step(&stmt) == SQLITE_ROW)
      locked = sqlite3_column_int(&stmt, 0);
    sqlite3_finalize(&stmt);
    return static_cast<LOCK_STATUS>(locked);
  }
};