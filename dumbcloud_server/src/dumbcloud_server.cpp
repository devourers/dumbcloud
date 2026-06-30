#include <dumbcloud_server/dumbcloud_server.h>
#include <dumbcloud_utils/json.hpp>

#include <stdexcept>
#include <iostream> //todo: include utils/journal may be?


#ifdef _WIN32
#include <windows.h>
#elif __linux__
#endif

namespace dc { namespace internal {

ServerJournal::ServerJournal() {
  journal_stream.open("dcserver.journal", std::ios::out | std::ios::trunc); //reseting it
  journal_stream.close();
}

void ServerJournal::OnMessageAdded() {
  journal_stream.open("dcserver.journal", std::fstream::in | std::fstream::out | std::fstream::app);
  journal_stream << journal_.front() << "\n\r";
  journal_.pop();
  journal_stream.close();
}

Server::Server() {
#ifdef _WIN32
  HANDLE server_mutex = CreateMutexA(NULL, true, DUMBCLOUD_SERVER_MUTEX_NAME);
  if (server_mutex == NULL) {
    throw std::runtime_error("Failure to initiate unique mutex");
  }

  if (GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(server_mutex);
    throw std::runtime_error("Instance of dumbcloud-server already running somewhere.");
  }

#elif __linux__
  //TODO: create similar unique process running stuff for linux
#endif

}

Server& Server::Instance() {
  static Server instance;
  instance.journal_.AddMessage("Succecfully created dumbcloud_server");

  //TODO: ALL INIT INFO GOES HERE (like creating folders and whatnot)

  if (!std::filesystem::is_directory("backups")) {
    std::filesystem::create_directory("backups");
    instance.journal_.AddMessage("backups/ directory missing, created a new one");
  }
  else {
    //parse backups that are present
  }
    
  if (!std::filesystem::is_directory("named_backups")) {
    std::filesystem::create_directory("named_backups");
    instance.journal_.AddMessage("named_backups/ directory missing, created a new one");
  }
  else {
    //parse named backups
  }

  if (!std::filesystem::is_directory("incoming")) {
    std::filesystem::create_directory("incoming");
    instance.journal_.AddMessage("incoming/ directory missing, created a new one");
  }
  else {
    //incoming should be clear on start?
  }

  instance.journal_.AddMessage("Succesfully initiated dumbcloud_server");

  return instance;
}

void Server::SetServerHandle(const std::string& handle) {
  server_handle_ = handle; 
  journal_.AddMessage("Server handle set to " + server_handle_);
}

void Server::AddEntry(const dc::utils::TrackedEntry& entry) {
  tracked_entries_[entry.entry_name_] = entry;
  journal_.AddMessage("Adding entry " + entry.entry_name_ + "; " + "Location: " + entry.entry_path_.string());
  journal_.AddMessage("Total " + std::to_string(entry.saves_.size()) + " files added to entry " + entry.entry_name_);
}

void Server::LoadServerConfiguration() {
  std::fstream cfg(DUMBCLOUD_SERVER_CONFIGURATION_FILENAME, std::ios::out);
  nlohmann::json cfg_data = nlohmann::json::parse(cfg);
  SetServerHandle(cfg_data["handle"].get<std::string>());
  for (auto& cfg_entry : cfg_data["tracked_entries"].items()) {
    //TODO: we need to parse files ourselves, also consider that some files can be excluded (only local saves)
    dc::utils::TrackedEntry entry;
    entry.entry_name_ = cfg_entry.key();
    entry.entry_path_ = cfg_entry.value()["path"].get<std::string>();
    this->AddEntry(entry);
    //TODO: for file get file 
  }
}

void Server::DumpServerConfiguration() {
  //TODO
}

Server::~Server() {
  journal_.AddMessage("Server shut down");
  DumpServerConfiguration();
  //log to journal ur fucking dead
  //and other stuff like saving/writing
}


}}


