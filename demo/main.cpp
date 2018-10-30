#include <libtom/client.hpp>

int main(int argc, char** argv) {
  TOM::client.load_lib("./libtom-demo-greeter.so");
}
