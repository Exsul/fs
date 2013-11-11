#include "../stdafx.h"
#include "file_find_data.h"

#include <functional>
class directory
{
  typedef std::function<void(const file_find_data &)> file_found_callback;
  void FindFiles(MAYBEWRONG wstring filename, file_found_callback);
  void FindFiles(MAYBEWRONG wstring filename, wstring pattern, file_found_callback);
  void Delete();
};