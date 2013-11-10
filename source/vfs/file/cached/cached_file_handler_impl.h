#include "../../stdafx.h"
#include "../access_rights.h"
#include <stdio.h>

struct cached_file_handler_impl
{
private:
  FILE *F;
  dword offset;
  mutable dword length;

public:
  cached_file_handler_impl(const wstring name, const access_rights);
  ~cached_file_handler_impl();

  dword Length() const;
  dword Offset() const;
  dword Offset(const dword);

  std::vector<ub> Read(const word amount);
  word Write(const std::vector<ub> &data);
};