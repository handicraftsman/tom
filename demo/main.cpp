#include <libtom/libtom.hpp>

#include "../greeter/greeter.hpp"

int main(int argc, char** argv) {
  TOM::manager.load_libsfile();
  
  auto greeter = std::dynamic_pointer_cast<IGreeter>(TOM::manager.construct("Greeter", nullptr));
  greeter->greet("World");
}
