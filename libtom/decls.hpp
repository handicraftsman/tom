#pragma once

#include <string>
#include <memory>

namespace PTK::TOM {
  class IUnknown;
  using IUnknownPtr = std::shared_ptr<IUnknown>;
  using ClsId = std::string;
  using Constructor = std::function<IUnknownPtr(IUnknownPtr)>;
}