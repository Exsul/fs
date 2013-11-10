#include "cached_file_handler_impl.h"

cached_file_handler_impl::cached_file_handler_impl(const wstring name, const access_rights r)
: offset(0), F(nullptr), length(WORD_MAX)
{
  wchar_t ar[3] = {'r', 'b', 0};
  if (r.Enabled(access_rights::WRITE))
    ar[0] = 'w';
  errno_t error = _wfopen_s(&F, name.c_str(), ar);
  throw_sassert(F, "File cache not found! Cache corrupted");
}

cached_file_handler_impl::~cached_file_handler_impl()
{
  if (F)
    fclose(F);
}

#include <cerrno>

dword cached_file_handler_impl::Length() const
{
  if (length == WORD_MAX)
  {
    throw_assert(!errno);
    fseek(F, 0, SEEK_END);
    int _length = ftell(F);
    fseek(F, offset, SEEK_SET);
    throw_assert(!errno);
    throw_assert(_length != -1);
    throw_assert(_length >= 0);
    length = convert<word>(_length);
  }
  return length;
}

dword cached_file_handler_impl::Offset() const
{
  return offset;
}
