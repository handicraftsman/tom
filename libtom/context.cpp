#include "context.hpp"

#include <stdexcept>

extern "C" {
  #include <dlfcn.h>
}

namespace TOM {
  
  Client::Client(const std::string& name, const std::string& path) {
    char* error;
    
    void* h = dlopen(path, RTLD_LAZY);
    
    if ((error = dlerror()) != nullptr) {
      throw std::runtime_error(std::string(error));
    }
    
    handle = std::shared_ptr<void>(h, dlclose);
  }
  
  Client::~Client() {}
  
}
