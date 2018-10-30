#include "context.hpp"

#include <stdexcept>

extern "C" {
  #include <dlfcn.h>
}

typedef void (*ServerFunc)(TOM::Context& ctx);

namespace TOM {
  
  Context::Context(const std::string& name, const std::string& path) {
    char* error;
    
    void* h = dlopen(path.c_str(), RTLD_LAZY);
    
    if ((error = dlerror()) != nullptr) {
      throw std::runtime_error(std::string(error));
    }
    
    handle = std::shared_ptr<void>(h, dlclose);
    
    ServerFunc r = (ServerFunc) dlsym(handle.get(), "tom_reg");
    if (r != nullptr) {
      r(*this);
    }
    dlerror();
  }
  
  Context::~Context() {}
  
}
