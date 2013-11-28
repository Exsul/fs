#include "access_rights.h"

/*
#define SPECIFY_TYPE(method,type,end) template<> method<type>(type)end;
#define SPECIFY(method, end) \
  SPECIFY_TYPE(method, access_rights::DIRECTORY); \
  SPECIFY_TYPE(method, access_rights::FILE); \
  SPECIFY_TYPE(method, access_rights::BOTH)
  */

template<typename ONE_OF_THESE_ENUM_TYPES>
void access_rights::Enabled(std::function<void(const ONE_OF_THESE_ENUM_TYPES &)> callback) const
{
  for each (ONE_OF_THESE_ENUM_TYPES a in Container<ONE_OF_THESE_ENUM_TYPES>())
    callback(a);
}

template<typename ONE_OF_THESE_ENUM_TYPES>
bool access_rights::Enabled(ONE_OF_THESE_ENUM_TYPES flag) const
{
  for each (ONE_OF_THESE_ENUM_TYPES a in Container<ONE_OF_THESE_ENUM_TYPES>())
    if (a == flag)
      return true;
  return false;
}

template<typename ONE_OF_THESE_ENUM_TYPES>
void access_rights::Add(ONE_OF_THESE_ENUM_TYPES flag)
{
  if (Enabled(flag))
    return;
  Container<ONE_OF_THESE_ENUM_TYPES>().push_back(flag);
}

template<typename ONE_OF_THESE_ENUM_TYPES>
void access_rights::Remove(ONE_OF_THESE_ENUM_TYPES flag)
{
  if (!Enabled(flag))
    return;
  todo(Remove access right flag);
}

template<typename ONE_OF_THESE_ENUM_TYPES>
void access_rights::operator+=(ONE_OF_THESE_ENUM_TYPES flag)
{
  Add(flag);
}

template<typename ONE_OF_THESE_ENUM_TYPES>
void access_rights::operator-=(ONE_OF_THESE_ENUM_TYPES flag)
{
  Remove(flag);
}

#define CONTAINER(type, source, mod) template<> mod std::vector<type> &access_rights::Container<type>() mod { return source; }
CONTAINER(access_rights::FILE, f, )
CONTAINER(access_rights::DIRECTORY, d, )
CONTAINER(access_rights::BOTH, b, )

CONTAINER(access_rights::FILE, f, const)
CONTAINER(access_rights::DIRECTORY, d, const)
CONTAINER(access_rights::BOTH, b, const)

namespace
{
  void ForceSpecification()
  { // because bug http://stackoverflow.com/questions/6083948/explicit-specialization-of-c-struct-member-template-functions-is-this-a-visu
    access_rights ar;
    access_rights::DIRECTORY d = access_rights::ADD_FILE;
    access_rights::FILE f = access_rights::APPEND;
    access_rights::BOTH b = access_rights::READ_ATTRIBUTE;

#define SPECIFY(method) \
    ar method(d); \
    ar method(f); \
    ar method(b)

    SPECIFY(.Add);
    SPECIFY(.Remove);
    SPECIFY(+= );
    SPECIFY(-= );
#undef SPECIFY
  }
}

namespace
{
  struct CheckLambda REQUIRE_CPP14 // generic lambda
  {
    access_rights &ret;
    word a;
    CheckLambda(access_rights &_ret, word _a) : ret(_ret), a(_a) {}
    template<typename T>
    void operator()(T right) const
    {
      if (a & right)
        ret += right;
    }
  };

  void ParseFile(access_rights &ret, const word &a)
  {
    auto Check = CheckLambda(ret, a);
    Check(access_rights::APPEND);
    Check(access_rights::EXECUTE);
    Check(access_rights::READ);
    Check(access_rights::WRITE);
  }

  void ParseDir(access_rights &ret, const word &a)
  {
    auto Check = CheckLambda(ret, a);
    Check(access_rights::ADD_FILE);
    Check(access_rights::ADD_SUBDIRECTORY);
    Check(access_rights::DELETE_CHILD);
    Check(access_rights::LIST);
    Check(access_rights::TRAVERSE);
  }

  void ParseBoth(access_rights &ret, const word &a)
  {
    auto Check = CheckLambda(ret, a);
    Check(access_rights::WRITE_ATTRIBUTE);
    Check(access_rights::READ_ATTRIBUTE);
    Check(access_rights::READ_EATTRIBUTE);
    Check(access_rights::WRITE_EATTRIBUTE);
  }
};

access_rights::access_rights()
{

}

access_rights::access_rights(const word &a, type_index ti)
{
  if (ti == typeid(access_rights::DIRECTORY))
    ParseDir(*this, a);
  else if (ti == typeid(access_rights::FILE))
    ParseFile(*this, a);
  else
    throw_message("Wrong type used to init access rights. Could be only file or directory");
  ParseBoth(*this, a);
}

access_rights::operator word() const
{
  word ret;
  auto Add = [&ret](const int &a)
  {
    ret |= a;
  };
  std::function<void(const int &)> func = Add;
  Enabled(convert<std::function<void(const access_rights::FILE &)>>(func));
  Enabled(convert<std::function<void(const access_rights::DIRECTORY &)>>(func));
  Enabled(convert<std::function<void(const access_rights::BOTH &)>>(func));
  return ret;
}