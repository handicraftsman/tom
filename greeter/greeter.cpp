#include <iostream>
#include <libtom/libtom.hpp>

#include "greeter.hpp"

class Greeter : public IGreeter {
public:
  Greeter(TOM::IUnknownPtr arg) {
    (void) arg;
  }
  
  virtual ~Greeter() {}
  
  virtual void greet(const std::string& who) override {
    std::cout << "Hello, " << who << "!" << std::endl;
  }
};

extern "C" {
  void tom_reg(TOM::Context& ctx) {
    ctx.register_class<Greeter>("Greeter");
  }

}
