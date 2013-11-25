#include "cached_file.h"

cached_file::cached_file(const cached_file_handler &_fh)
: handler(_fh)
{

}

cached_file::~cached_file()
{
}

void cached_file::Close()
{
}

vector<byte> cached_file::Read(word amount, dword offset)
{
  handler.Offset(offset);
  return handler.Read(amount);
}

word cached_file::Write(vector<byte> data, dword offset)
{
  handler.Offset(offset);
  return handler.Write(data);
}

void cached_file::Flush()
{
}

bool cached_file::Lock(const bword offset, const bword length)
{
  return handler.Lock();
}

bool cached_file::Unlock(const bword offset, const bword length)
{
  return handler.Unlock();
}
