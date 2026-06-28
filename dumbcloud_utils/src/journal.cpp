#include <dumbcloud_utils/journal.h>

#include <dumbcloud_utils/dumbcloud_utils.h>

#include <iostream>

namespace dc { namespace utils {




void Journal::AddMessage(const std::string& message) {
	std::unique_lock<std::mutex> lock(write_mutex_);
	//adds timestamp
	std::time_t result = std::time(nullptr);
	auto tm = *std::localtime(&result);
	std::string timed_msg = GenerateTimeStamp() + "%%%" + message;

	journal_.push(timed_msg);
	OnMessageAdded();
}

} }