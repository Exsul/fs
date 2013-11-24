#include "directory_handler.h"
#include "../internal.h"

directory_handler::directory_handler(wstring name)
: name(Cache(name))
{
}