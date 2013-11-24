struct attributes
{
  enum ATTRIBUTES
  { // http://msdn.microsoft.com/en-us/library/windows/desktop/aa363858(v=vs.85).aspx
    ARCHIVE = 0x20,
    ENCRYPTED = 0x4000,
    HIDDEN = 0x2,
    NORMAL = 0x80,
    OFFLINE = 0x1000,
    READONLY = 0x1,
    SYSTEM = 0x4,
    TEMPORARY = 0x100
  };

  vector<ATTRIBUTES> attr;

  bool Enabled(ATTRIBUTES) const;
};