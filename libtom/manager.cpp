#include "manager.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "decls.hpp"
#include "context.hpp"

using namespace std::placeholders;

namespace TOM {
  Manager::Manager() {}
  
  Manager::~Manager() {}
  
  void Manager::load_lib(const std::string& file) {
    std::filesystem::path p(file);
    std::string fname = p.filename();
    libs_map[fname] = std::shared_ptr<Context>(new Context(fname, file));
    lib_order.push_back(fname);
  }
  
  void Manager::load_libsfile() {
    std::string path;      
    const char* cstr = getenv("TOM_LIBSFILE");
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
  
  IUnknownPtr Manager::construct(const std::string& name, IUnknownPtr arg) {
    for (std::pair<std::string, std::shared_ptr<Context>> p : libs_map) {
      if (p.second->classes.find(name) != p.second->classes.end()) {
        return (p.second->classes[name])(arg);
      }
    }
    return nullptr;
  }
  
  IUnknownPtr Manager::construct(const std::string& lib, const std::string& name, IUnknownPtr arg) {
    if (libs_map.find(lib) != libs_map.end()) {
      std::shared_ptr<Context> ctx = libs_map[lib];
      if (ctx->classes.find(name) != ctx->classes.end()) {
        return (ctx->classes[name])(arg);
      }
    }
    return nullptr;
  }
  
  Manager manager;
}
