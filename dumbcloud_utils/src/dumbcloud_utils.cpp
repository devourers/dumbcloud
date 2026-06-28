#include <dumbcloud_utils/dumbcloud_utils.h>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace dc { namespace utils {

std::string GenerateTimeStamp() {
  auto t = std::time(nullptr);
  auto tm = *std::localtime(&t);

  std::ostringstream oss;
  oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
  auto str = oss.str();
  return str;
}

TrackedEntry GenerateEntry(const std::string& name, const std::string& path) {
	TrackedEntry res;
	res.entry_path_ = std::filesystem::path(path);
	if (!std::filesystem::is_directory(res.entry_path_))
		throw std::runtime_error("Trying to create entry from a file path");
	res.entry_name_ = name;
	for (const auto& entry : std::filesystem::directory_iterator(res.entry_path_)) {
		if (std::filesystem::is_directory(entry.path()))
			continue; //we are not tracking folders inside folders
		res.saves_.push_back(entry.path());
	}
	return res;
}

} }
