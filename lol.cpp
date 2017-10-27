#include <chrono>
#include <iostream>
#include <signal.h>
#include <thread>

#include "gen/right.ascii.h"
#include "gen/left.ascii.h"
#include "gen/middle.ascii.h"

void my_handler(int s) {
	exit(1);
}

unsigned char* frames[] = {
	&gen_left_ascii[0],
	&gen_middle_ascii[0],
	&gen_right_ascii[0],
	&gen_middle_ascii[0],
};

int main (int argc, char** argv)
{
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, nullptr);

	for (int i = 0 ;; i++)
	{
		std::cout << "\033[2J";
		std::cout << frames[i % 4] << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	}

	return 0;
}
