#ifndef COMMANDLINE_VIDEOSTORE_CPP_SPLITSTRING_H
#define COMMANDLINE_VIDEOSTORE_CPP_SPLITSTRING_H

#include <vector>
#include <string>

inline std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> strings;
  for (size_t first=0, last=0; last < str.length(); first=last+1) {
    last = str.find(delimiter, first);
    strings.push_back(str.substr(first, last-first));
  }
  return strings;
}
#endif //COMMANDLINE_VIDEOSTORE_CPP_SPLITSTRING_H
