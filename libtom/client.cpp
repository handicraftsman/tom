#include <map>
#include <memory>
#include <pair>
#include <vector>

#include "decls.hpp"
#include "context.hpp"

using LibsMap = std::vector<std::pair<std::string, std::shared_ptr<PTK::TOM::Context>>>;

static LibsMap libs_map;
