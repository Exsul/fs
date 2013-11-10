#include "../../stdafx.h"
#include "../access_rights.h"
#include <stdio.h>

struct cached_file_handler_impl
{
private:
  FILE *F;
  word offset;
  mutable word length;

public:
  cached_file_handler_impl(const wstring name, const access_rights);
  ~cached_file_handler_impl();

  dword Length() const;
  dword Offset() const;
  dword Offset(const dword);
};