#pragma once

#include <string>
#include <set>
#include <vector>

#include <Poco/DateTime.h>

namespace foo
{

Poco::DateTime now();
std::vector<std::string> getNames(const std::set<int> ids);

}