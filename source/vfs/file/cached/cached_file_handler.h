#include "../file_handler.h"

struct cached_file_handler_impl;
struct cached_file_handler : public file_handler
{
  std::wstring cache_filename_location;

  cached_file_handler(const file_handler &);
  cached_file_handler(const cached_file_handler &);

  ~cached_file_handler();

  virtual dword Offset() const;
  virtual dword Offset(dword offset);
  virtual dword Length() const;
  virtual std::vector<ub> Read(word amount);
  virtual word Write(std::vector<ub> data);
private:
  cached_file_handler_impl &Impl() const;
  mutable cached_file_handler_impl *impl;
};