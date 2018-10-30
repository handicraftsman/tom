#pragma once

#include <memory>
#include <string>

namespace TOM {
  class Context;
}

#include "server.hpp"

namespace TOM {
  class Context {
  public:
    friend void TOM::Server::reg(Context& ctx);
    friend void TOM::Server::unreg(Context& ctx);
    
    Context(const std::string& name, const std::string& path);
    ~Context();
    
    std::shared_ptr<void> handle;
  };
}
