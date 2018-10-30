#pragma once

#include <functional>
#include <string>
#include <memory>

namespace TOM {
  class IUnknown;
  using IUnknownPtr = std::shared_ptr<IUnknown>;
  using ClsId = std::string;
  using Constructor = std::function<IUnknownPtr(IUnknownPtr)>;
}
