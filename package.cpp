#include <particlepm.hpp>

using namespace PPM::Utils;

PPM_PACKAGE(p) {
  p->name("tom");
  p->version(PPM::Version("v0.1.1"));
  p->description("A COM-inspired component object model for C++");
  p->github(PPM::GitHub("handicraftsman", "tom"));
  p->license(PPM::License("MIT", "https://github.com/handicraftsman/tom/blob/master/LICENSE.txt"));
  
  PPM::TargetPtr libtom = p->library("libtom");
  libtom->name("tom");
  libtom->cpp("c++17");
  libtom->cpp_files({
    "libtom/context.cpp",
    "libtom/manager.cpp"
  });
  libtom->cpp_flags(flagcat({
    ("-I" + p->pkg_dir()),
  })); 
}
