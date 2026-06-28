#include <iostream>
#include <string>
#include <dumbcloud_server/dumbcloud_server.h>


void InitialSetup() {
	std::string name;
	std::cin >> name;
}

int main(int argc, char* argv[]) {
	std::cout << "dumbcloud_server_go init" << std::endl;
	std::cout << "%%% this is initial setup. please enter this device handle for other servers to see.";
	InitialSetup();
	std::cout << std::endl;
	return 0;
}