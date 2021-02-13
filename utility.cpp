#pragma once

#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

bool contain(string str, string substr) {
    return ( str.find(substr) != string::npos );
}

string tolower(string str) {
    return boost::algorithm::to_lower_copy(str);
}
