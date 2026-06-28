#ifndef DUMBCLOUD_UTILS_H_INCLUDED
#define DUMBCLOUD_UTILS_H_INCLUDED

#include <string>
#include <filesystem>
#include <iostream>

namespace dc {namespace utils {

	std::string GenerateTimeStamp();

struct TrackedEntry {
	std::string entry_name_; //game name
	std::filesystem::path entry_path_; //path to dir where all the files are stored (this is a dir)
	std::vector<std::filesystem::path> saves_; //the files themselves

};

TrackedEntry GenerateEntry(const std::string& name, const std::string& path);

}}


#endif