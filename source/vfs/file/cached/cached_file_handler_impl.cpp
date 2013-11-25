#include "cached_file_handler_impl.h"
#include "../file_handler.h"

cached_file_handler_impl::cached_file_handler_impl(const wstring name, const access_rights r)
: offset(0), F(nullptr), length(WORD_MAX)
{
  wchar_t ar[3] = {'r', 'b', 0};
  if (r.Enabled(access_rights::WRITE))
    ar[0] = 'w';
  errno_t error = _wfopen_s(&F, name.c_str(), ar);
  if (F)
    return;

  if (error == ENOENT)
    throw file_handler::file_not_found();
  if (error == EACCES)
    throw file_handler::access_denied();
  if (error == EINVAL) // trying to access directory as file (ex C:\blabla\)
    throw file_handler::file_not_found();
  throw_message("File cache not found! Cache corrupted");
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

dword cached_file_handler_impl::Offset(const dword _offset)
{
  if (offset != _offset)
    fseek(F, _offset, SEEK_SET);
  offset = _offset;
  return Offset();
}

std::vector<ub> cached_file_handler_impl::Read(const word amount)
{
  std::vector<ub> ret;
  ret.resize(amount, 0);
  usst readed = fread(&ret[0], sizeof(ub), amount, F);
  throw_assert(readed <= amount);
  if (readed != amount)
    ret.resize(readed);
  ret.shrink_to_fit();
  return ret;
}

word cached_file_handler_impl::Write(const std::vector<ub> &data)
{
  usst writed = fwrite(&data[0], sizeof(ub), data.size(), F);
  return writed;
}

void cached_file_handler_impl::Create(const wstring name)
{
  access_rights r;
  r.rights.push_back(access_rights::WRITE);
  cached_file_handler_impl(name, r);
}
