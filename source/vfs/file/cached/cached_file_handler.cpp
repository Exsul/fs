#include "cached_file_handler.h"
#include "cached_file_handler_impl.h"

cached_file_handler_impl &cached_file_handler::Impl() const
{
  DEPRECATED
    access_rights ar;
    ar.rights.push_back(access_rights::WRITE);

  if (!impl)
    impl = NEW cached_file_handler_impl(filename, ar);
  return *impl;
}

cached_file_handler::cached_file_handler(const file_handler &)
: impl(nullptr)
{
}

cached_file_handler::cached_file_handler(const cached_file_handler &)
{
  todo(What i should do on cached_file_handler_copy);
}

cached_file_handler::~cached_file_handler()
{
  if (impl)
    delete impl;
}

dword cached_file_handler::Offset() const
{
  return Impl().Offset();
}

dword cached_file_handler::Offset(dword offset)
{
  return Impl().Offset(offset);
}

dword cached_file_handler::Length() const
{
  return Impl().Length();
}

std::vector<ub> cached_file_handler::Read(word amount)
{
  return vector<ub>();
}

word cached_file_handler::Write(std::vector<ub> data)
{
  return 0;
}
