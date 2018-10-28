#pragma once

namespace PTK::TOM {
  class Context;
}

#include "server.hpp"

namespace PTK::TOM {
  class Context {
  public:
    friend void PTK::TOM::Server::reg(Context& ctx);
    friend void PTK::TOM::Server::unreg(Context& ctx);
  };
}
