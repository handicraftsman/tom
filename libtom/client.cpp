#include "client.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "decls.hpp"
#include "context.hpp"

using namespace std::placeholders;

namespace TOM {
  Client::Client() {}
  
  Client::~Client() {}
  
  void Client::load_lib(const std::string& file) {
    std::filesystem::path p(file);
    std::string fname = p.filename();
    libs_map.push_back(std::make_pair(fname, std::make_shared(new Context(fname, file))));
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
  
  Client client;
}
