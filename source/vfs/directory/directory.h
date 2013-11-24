#include "../stdafx.h"
#include "file_find_data.h"
#include "directory_handler.h"

#include <functional>
class directory
{
  directory_handler dh;
public:
  directory(directory_handler &dh);
  typedef std::function<void(const file_find_data &)> file_found_callback;
  void FindFiles(MAYBEWRONG wstring filename, file_found_callback);
  void FindFiles(MAYBEWRONG wstring filename, wstring pattern, file_found_callback);
  void Delete();
};