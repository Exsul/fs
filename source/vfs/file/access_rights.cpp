#include "access_rights.h"

bool access_rights::Enabled(ACCESS_RIGHTS flag) const
{
  for each (ACCESS_RIGHTS var in rights)
    if (var == flag)
      return true;
  return false;
}