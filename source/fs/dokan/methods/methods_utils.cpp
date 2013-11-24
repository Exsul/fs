#include "methods_utils.h"

template<>
access_rights convert(const int &a)
{
  access_rights ret;
  auto Check = [&ret, a](access_rights::ACCESS_RIGHTS right)
  {
    if (a & right)
      ret.rights.push_back(right);
  };

  Check(access_rights::READ);
  Check(access_rights::WRITE);
  Check(access_rights::DELETE);
  return ret;
}

template<>
create_disposition convert(const int &a)
{
  return create_disposition{convert<create_disposition::CREATE_DISPOSITION>(a)};
}

template<>
attributes convert(const int &a)
{
  attributes ret;
  auto Check = [&ret, a](attributes::ATTRIBUTES flag)
  {
    if (a & flag)
      ret.attr.push_back(flag);
  };
  Check(attributes::ARCHIVE);
  Check(attributes::ENCRYPTED);
  Check(attributes::HIDDEN);
  Check(attributes::NORMAL);
  Check(attributes::OFFLINE);
  Check(attributes::READONLY);
  Check(attributes::SYSTEM);
  Check(attributes::TEMPORARY);

  return ret;
}