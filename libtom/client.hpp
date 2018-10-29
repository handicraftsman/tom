#pragma once

#include <map>
#include <memory>
#include <vector>

extern "C" {
  #include <unistd.h>
}

namespace PTK::TOM {
  class Client {
  public:
    using LibsMap = std::vector<std::pair<std::string, std::shared_ptr<PTK::TOM::Context>>>;
    LibsMap libs_map;
    
    Client();
    ~Client();
    
    void load_lib(const std::string& file);
    void load_libsfile();
  };
  extern Client client;
}
