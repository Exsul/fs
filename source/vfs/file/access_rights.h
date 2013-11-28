#include "../stdafx.h"
#include <functional>
#include <vector>
#include <typeindex>

struct access_rights
{
  // http://msdn.microsoft.com/en-us/library/windows/desktop/gg258116(v=vs.85).aspx
  enum DIRECTORY
  {
    ADD_FILE = 2, // For a directory, the right to create a file in the directory.
    ADD_SUBDIRECTORY = 4, // For a directory, the right to create a subdirectory.
    DELETE_CHILD = 64, // For a directory, the right to delete a directory and all the files it contains, including read - only files.
    LIST = 1, // For a directory, the right to list the contents of the directory.
    TRAVERSE = 32, // For a directory, the right to traverse the directory.By default, users are assigned the BYPASS_TRAVERSE_CHECKING privilege, which ignores the FILE_TRAVERSE access right.See the remarks in File Security and Access Rights for more information.
  };

  enum FILE
  {
    APPEND = 4, // For a file object, the right to append data to the file. (For local files, write operations will not overwrite existing data if this flag is specified without FILE_WRITE_DATA.) For a directory object, the right to create a subdirectory(FILE_ADD_SUBDIRECTORY).
    EXECUTE = 32, // For a native code file, the right to execute the file.This access right given to scripts may cause the script to be executable, depending on the script interpreter.
    READ = 1, // For a file object, the right to read the corresponding file data.For a directory object, the right to read the corresponding directory data.
    WRITE = 2, //For a file object, the right to write data to the file.For a directory object, the right to create a file in the directory(FILE_ADD_FILE).
  };

  enum BOTH
  {
    WRITE_ATTRIBUTE = 256, // The right to write file attributes.
    READ_ATTRIBUTE = 128, // The right to read file attributes.
    READ_EATTRIBUTE = 8, // The right to read extended file attributes.
    WRITE_EATTRIBUTE = 16, //The right to write extended file attributes.
  };

  //FILE_CREATE_PIPE_INSTANCE = 4, // For a named pipe, the right to create a pipe.

  // FILE_ALL_ACCESS All possible access rights for a file.
  //STANDARD_RIGHTS_READ // Includes READ_CONTROL, which is the right to read the information in the file or directory object's security descriptor. This does not include the information in the SACL.
  //STANDARD_RIGHTS_WRITE // Same as STANDARD_RIGHTS_READ.

  std::vector<DIRECTORY> d;
  std::vector<FILE> f;
  std::vector<BOTH> b;

  /*/
#pragma region manipulate_methods
#define METHOD( begin, type, end ) template<> begin<type>(type)end
#define MULTI_METHOD( begin, end ) \
  template<typename T> begin(T)end; \
  METHOD(begin, DIRECTORY, end);   \
  METHOD(begin, FILE, end);   \
  METHOD(begin, BOTH, end)
  //*/

  template<typename ONE_OF_THESE_ENUM_TYPES>
  void Enabled(std::function<void(const ONE_OF_THESE_ENUM_TYPES &)>) const;

  template<typename ONE_OF_THESE_ENUM_TYPES>
  bool Enabled(ONE_OF_THESE_ENUM_TYPES) const;

  template<typename ONE_OF_THESE_ENUM_TYPES>
  void Add(ONE_OF_THESE_ENUM_TYPES);

  template<typename ONE_OF_THESE_ENUM_TYPES>
  void Remove(ONE_OF_THESE_ENUM_TYPES);

  template<typename ONE_OF_THESE_ENUM_TYPES>
  void operator+=(ONE_OF_THESE_ENUM_TYPES);

  template<typename ONE_OF_THESE_ENUM_TYPES>
  void operator-=(ONE_OF_THESE_ENUM_TYPES);

  /*/
  MULTI_METHOD(bool Enabled, const);
  MULTI_METHOD(void Add, );
  MULTI_METHOD(void Remove, );

  MULTI_METHOD(void operator+=, );
  MULTI_METHOD(void operator-=, );

#undef METHOD
#undef MULTI_METHOD
#pragma endregion
  //*/

  explicit operator word() const;

  access_rights(const word &, std::type_index);
  access_rights();
private:
  template<typename ONE_OF_THESE_ENUM_TYPES>
  std::vector<ONE_OF_THESE_ENUM_TYPES> &Container();
public:
  template<typename ONE_OF_THESE_ENUM_TYPES>
  const std::vector<ONE_OF_THESE_ENUM_TYPES> &Container() const;
};

