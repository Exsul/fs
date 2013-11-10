struct share_mode
{
  enum SHARE_MODE
  { // http://msdn.microsoft.com/en-us/library/windows/desktop/aa363858(v=vs.85).aspx
    PRIVATE = 0,
    DELETE = 4,
    READ = 1,
    WRITE = 2
  };
};