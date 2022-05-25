
#include <iostream>
#include <thread>
#include <chrono>

#include "openhd-profile.hpp"
#include "openhd-platform.hpp"

#include "OHDVideo.h"

int main(int argc, char *argv[]) {
  const auto profile = profile_from_manifest();
  const auto platform = platform_from_manifest();

  if (profile.is_air) {
	OHDVideo ohdVideo(platform, profile);
	std::cout << "OHDVideo started\n";
	while (true) {
	  std::this_thread::sleep_for(std::chrono::seconds(5));
	  std::cout<<"XOHDVid\n";
	  std::cout<<ohdVideo.createDebug();
	}
  } else {
	std::cout << "OHDVideo not started - not on air pi\n";
  }

  std::cerr << "OHDVideo stopped\n";

  return 0;
}