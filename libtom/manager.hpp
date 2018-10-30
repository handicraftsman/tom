#pragma once

#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

extern "C" {
  #include <unistd.h>
}

#include "context.hpp"

namespace TOM {
  class Manager {
  protected:
    std::unordered_map<std::string, std::shared_ptr<Context>> libs_map;
    std::vector<std::string> lib_order;
    
  public:
    Manager();
    ~Manager();
    
    void load_lib(const std::string& file);
    void load_libsfile();
    
    IUnknownPtr construct(const std::string& name, IUnknownPtr arg);
    IUnknownPtr construct(const std::string& lib, const std::string& name, IUnknownPtr arg);    
  };
  extern Manager manager;
}
