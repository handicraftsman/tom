#pragma once

#include <map>
#include <memory>
#include <vector>

extern "C" {
  #include <unistd.h>
}

#include "context.hpp"

namespace TOM {
  class Client {
  public:
    using LibsMap = std::vector<std::pair<std::string, std::shared_ptr<TOM::Context>>>;
    LibsMap libs_map;
    
    Client();
    ~Client();
    
    void load_lib(const std::string& file);
    void load_libsfile();
  };
  extern Client client;
}
