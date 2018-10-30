#pragma once

#include <string>

#include <libtom/libtom.hpp>

class IGreeter : public TOM::IUnknown {
public:
  virtual ~IGreeter() {}
  
  virtual void greet(const std::string& who) = 0;
};
