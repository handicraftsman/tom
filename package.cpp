#include <particlepm.hpp>

using namespace PPM::Utils;

PPM_PACKAGE(p) {
  p->name("tom");
  p->version(PPM::Version("v0.1.0"));
  p->description("A COM-inspired component object model for C++");
  p->github(PPM::GitHub("particletk", "tom"));
  p->license(PPM::License("MIT", "https://github.com/particletk/tom/blob/master/LICENSE.txt"));
  
  PPM::TargetPtr libtom = p->library("libtom");
  libtom->name("tom");
  libtom->cpp("c++17");
  libtom->cpp_files({
    "libtom/server.cpp",
    "libtom/client.cpp"
  });
  libtom->cpp_flags(flagcat({
    ("-I" + p->pkg_dir()),
  }));
  
  if (PPM::dev) {
    PPM::TargetPtr libgreeter = p->library("tom-demo-greeter");
    libgreeter->cpp("c++17");
    libgreeter->cpp_files({
      "greeter/greeter.cpp"
    });
    libgreeter->cpp_flags(flagcat({
      ("-I" + p->pkg_dir()),
      ("-L" + PPM::dist_dir),
      "-ltom"
    }));
    libgreeter->depends(libtom);
    
    PPM::TargetPtr demo = p->executable("tom-demo");
    demo->cpp("c++17");
    demo->cpp_files({
      "demo/main.cpp"
    });
    demo->cpp_flags(flagcat({
      ("-I" + p->pkg_dir()),
      ("-L" + PPM::dist_dir),
      "-ltom"
    }));
    demo->depends(libtom);
  }
}
