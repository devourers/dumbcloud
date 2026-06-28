#ifndef JOURNAL_H_INCLUDED
#define JOURNAL_H_INCLUDED

#include <queue>
#include <string>
#include <iostream>
#include <mutex>

namespace dc { namespace utils {

class Journal {

public:
	Journal() = default;

	void AddMessage(const std::string& message); //adds timestamps on it's own

	virtual void OnMessageAdded() = 0;

	virtual ~Journal() = default;

protected:
	std::mutex write_mutex_;
	std::queue<std::string> journal_;
};

} }


#endif