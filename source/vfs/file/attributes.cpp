#include "attributes.h"

template<>
word convert(const attributes &a)
{
  word ret = 0;
  for each (attributes::ATTRIBUTES var in a.attr)
    ret |= var;
  return ret;
}

template<>
attributes convert(const word &a)
{
  attributes ret;
  auto Check = [&ret, a](attributes::ATTRIBUTES flag)
  {
    if (a & flag)
      ret.attr.push_back(flag);
  };

  Check(attributes::READONLY);
  Check(attributes::HIDDEN);
  Check(attributes::SYSTEM);
  Check(attributes::DIRECTORY);
  Check(attributes::ARCHIVE);
  Check(attributes::DEVICE);
  Check(attributes::NORMAL);
  Check(attributes::TEMPORARY);
  Check(attributes::SPARSE_FILE);
  Check(attributes::REPARSE_POINT);
  Check(attributes::COMPRESSED);
  Check(attributes::OFFLINE);
  Check(attributes::NOT_CONTENT_INDEXED);
  Check(attributes::ENCRYPTED);
  Check(attributes::INTEGRITY_STREAM);
  Check(attributes::VIRTUAL);
  Check(attributes::NO_SCRUB_DATA);

  return ret;
}