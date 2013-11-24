#include "../../header.h"
#include "../dokan_proxy.h"
#undef DELETE
#undef CREATE_ALWAYS
#undef CREATE_NEW
#undef OPEN_ALWAYS
#undef OPEN_EXISTING
#undef TRUNCATE_EXISTING
#include "../../../vfs/vfs.h"

template<>
access_rights convert(const int &a);
template<>
create_disposition convert(const int &a);