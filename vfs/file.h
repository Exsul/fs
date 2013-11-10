#include <vector>

#include "header.h"
#include "file_handler.h"

using namespace std;

class file
{
  file(file_handler);
  ~file();
  void Close();
  vector<byte> Read(word amount, dword offset = 0);
  word Write(vector<byte> data, dword offset = 0);
  void Flush();

/*/
  int GetFileInformation(std::wstring filename, LPBY_HANDLE_FILE_INFORMATION buffer, DOKAN_FILE_INFO &dokan_info);
//*/
};