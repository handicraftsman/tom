#pragma once

#include <memory>

#include "decls.hpp"

namespace PTK::TOM {
  class Context;
}

namespace PTK::TOM::Server {
  extern "C" {
    extern "C" void reg(Context& ctx);
    extern "C" void unreg(Context& ctx);
    extern "C" void has_clsid(ClsId clsid);
  }
}

