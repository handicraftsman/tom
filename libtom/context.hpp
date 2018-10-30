#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace TOM {
  class Context;
  class Manager;
}

#include "decls.hpp"

extern "C" {
  extern "C" void tom_reg(TOM::Context& ctx);
}

namespace TOM {
  class Context {
  public:
    friend class Manager;
    friend void ::tom_reg(TOM::Context& ctx);
    
    Context(const std::string& name, const std::string& path);
    ~Context();
    
  protected:
    std::shared_ptr<void> handle;
    std::unordered_map<std::string, Constructor> classes;
    
  public:
    template<typename T>
    void register_class(const std::string& name) {
      classes[name] = [] (IUnknownPtr p) {
        return IUnknownPtr(static_cast<IUnknown*>(new T(p)));
      };
    }
  };
}
