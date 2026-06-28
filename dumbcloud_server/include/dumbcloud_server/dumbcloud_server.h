#ifndef DUMBCLOUD_SERVER_H_INCLUDED
#define DUMBCLOUD_SERVER_H_INCLUDED

#include <dumbcloud_utils/dumbcloud_utils.h>
#include <dumbcloud_utils/journal.h>
#include <fstream>
#include <map>

namespace dc { namespace internal {

#ifdef _WIN32
#define DUMBCLOUD_SERVER_MUTEX_NAME "Global\\dumbcloud_server-1337"
#elif __linux__
#endif

#define DUMBCLOUD_SERVER_CONFIGURATION_FILENAME "dc_server_cfg.json"
#define DUMBCLOUD_SERVER_CONFIGURATION_BACKUPS_PATH "backups"
#define DUMBCLOUD_SERVER_CONFIGURATION_INCOMING_PATH "incoming"


class ServerJournal : public dc::utils::Journal {

public:

	ServerJournal();

	virtual void OnMessageAdded() override;

	virtual ~ServerJournal() override {
		journal_stream.close();
	}

private:
	std::fstream journal_stream;
};


class Server {

private:
	Server();

public:

static Server& Instance();

~Server();

public: /// setters and getters

void SetServerHandle(const std::string& handle);
const std::string& GetServerHandle() { return server_handle_; }

void LoadServerConfiguration();

public: /// methods for handling server itself
	void AddEntry(const dc::utils::TrackedEntry& entry);

	void DumpServerConfiguration();

private:

	/// what other servers will see in list
	std::string server_handle_; 

	/// server journal
	ServerJournal journal_;

	/// entries, which server tracks
	std::map<std::string, dc::utils::TrackedEntry> tracked_entries_;

};


}}

#endif