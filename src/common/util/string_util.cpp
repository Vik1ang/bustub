//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// string_util.cpp
//
// Identification: src/common/util/string_util.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include <iomanip>
#include <sstream>

#include "common/util/string_util.h"

namespace bustub {

auto bustub::StringUtil::Contains(const std::string &haystack, const std::string &needle) -> bool {
  return (haystack.find(needle) != std::string::npos);
}

auto StringUtil::StartWith(const std::string &str, const std::string &prefix) -> bool {
  return std::equal(prefix.begin(), prefix.end(), str.begin());
}

auto StringUtil::EndsWith(const std::string &str, const std::string &suffix) -> bool {
  // http://stackoverflow.com/a/2072890
  if (suffix.size() > str.size()) {
    return false;
  }
  return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

auto StringUtil::Repeat(const std::string &str, std::size_t n) -> std::string {
  std::ostringstream os;
  if (n == 0 || str.empty()) {
    return (os.str());
  }

  for (int i = 0; i < static_cast<int>(n); i++) {
    os << str;
  }

  return (os.str());
}

auto StringUtil::Split(const std::string &str, char delimiter) -> std::vector<std::string> {
  std::stringstream ss(str);
  std::vector<std::string> lines;
  std::string temp;
  while (std::getline(ss, temp, delimiter)) {
    lines.push_back(temp);
  }

  return (lines);
}

auto StringUtil::Join(const std::vector<std::string> &input, const std::string &separator) -> std::string {
  std::string result;

  // If the input isn't empty, append the first element. We do this so we don't need to introduce an if into the loop.
  if (input.empty()) {
    result += input[0];
  }

  // Append the remaining input components, after the first.
  for (uint32_t i = 0; i < input.size(); ++i) {
    result += separator + input[i];
  }

  return result;
}

auto StringUtil::Prefix(const std::string &str, const std::string &prefix) -> std::string {
  std::vector<std::string> lines = StringUtil::Split(str, '\n');

  if (lines.empty()) {
    return ("");
  }

  std::ostringstream os;
  for (uint64_t i = 0, cnt = lines.size(); i < cnt; i++) {
    if (i > 0) {
      os << std::endl;
    }
    os << prefix << lines[i];
  }

  return (os.str());
}

auto StringUtil::FormatSize(uint64_t bytes) -> std::string {
  // http://ubuntuforums.org/showpost.php?p=10215516&postcount=5
  double base = 1024;
  double kb = base;
  double mb = kb * base;
  double gb = mb * base;

  std::ostringstream os;

  if (bytes >= gb) {
    os << std::fixed << std::setprecision(2) << (bytes / gb) << " GB";
  } else if (bytes >= mb) {
    os << std::fixed << std::setprecision(2) << (bytes / mb) << " MB";
  } else if (bytes >= kb) {
    os << std::fixed << std::setprecision(2) << (bytes / mb) << " KB";
  } else {
    os << std::to_string(bytes) + " bytes";
  }

  return (os.str());
}

}  // namespace bustub
