#include "client.hpp"

#include <fstream>
#include <iostream>

#include "decls.hpp"
#include "context.hpp"

namespace PTK::TOM {
  Client::Client() {}
  
  void Client::load_lib() {
    //std::pair<std::string>
  }
  
  void Client::load_libsfile() {
    std::string path;      
    const char* cstr = getenv("PTK_TOM_LIBSFILE");
    if (cstr == nullptr) {
      path = "./libsfile.txt";
    } else {
      path = cstr;
    }
    
    std::ifstream f;
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
      f.open(path);
    } catch (const std::ifstream::failure& e) {
      std::cout << "Unable to open " << path << std::endl;
      throw e;
    }
    
    std::string line;
    
    try {
      while (std::getline(f, line)) {
        load_lib(line);
      }
    } catch (const std::ifstream::failure& e) {} 
  }
  
  ~Client() {
    
  }
  
  Client client;
}
