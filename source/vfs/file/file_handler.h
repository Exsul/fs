#pragma once
#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include "../stdafx.h"
#include <string>

class file_handler : public ax::shared_self_controlled
{
protected:
  std::wstring filename;
public:
  virtual dword Offset() const = 0;
  virtual dword Offset(dword offset) = 0;
  virtual dword Length() const = 0;
  virtual std::vector<ub> Read(word amount) = 0;
  virtual word Write(std::vector<ub> data) = 0;

  const std::wstring &Name() const;
};

#endif