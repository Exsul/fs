#include "../file.h"
#include "cached_file_handler.h"

class cached_file : public file
{
protected:
  cached_file_handler handler;
public:
  cached_file(const cached_file_handler &B);
  ~cached_file();
  virtual void Close();
  virtual vector<byte> Read(word amount, dword offset = 0);
  virtual word Write(vector<byte> data, dword offset = 0);
  virtual void Flush();
};