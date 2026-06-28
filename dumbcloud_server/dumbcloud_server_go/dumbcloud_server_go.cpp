#include <iostream>
#include <string>
#include <dumbcloud_server/dumbcloud_server.h>


void InitialSetup() {
	std::string name;
	std::cin >> name;
	dc::internal::Server::Instance().SetServerHandle(name);
}

int main(int argc, char* argv[]) {
	std::cout << "dumbcloud_server_go init" << std::endl;
	std::cout << "%%% this is initial setup. please enter this device handle for other servers to see: ";
	InitialSetup();
	std::cout << std::endl;

	try {
		dc::internal::Server::Instance();
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return -1;
	}

	std::string path;
	std::string name;
	std::cout << "enter name of your entry";
	std::cin >> name;
	std::cout << "enter path to your directory";
	std::cin >> path;


	dc::utils::TrackedEntry entry = dc::utils::GenerateEntry(name, path);
	dc::internal::Server::Instance().AddEntry(entry);

	int a;
	std::cout << "waiting for input ";
	std::cin >> a;

	return 0;
}