struct create_disposition
{
  enum CREATE_DISPOSITION
  { // http://msdn.microsoft.com/en-us/library/windows/desktop/aa363858(v=vs.85).aspx
    AAA = 1,
    CREATE_ALWAYS = 2,
    CREATE_NEW = 1,
    OPEN_ALWAYS = 4,
    OPEN_EXISTING = 3,
    TRUNCATE_EXISTING = 5
  } value;
};