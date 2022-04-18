// sewerat v0.1.0
// find it at: https://github.com/sewerat.git

// I believe these are required.
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0501

#define PROG_NAME "sewerat"
#define PROG_VERSION "0.1.0"

#include "TcpClient.h"
#include <iostream>

// Links the needed WINSOCK library.
#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char **argv) {
  std::cout << PROG_NAME << " " << PROG_VERSION << '\n';
  // Automatically calls connect_to_host, someone can change
  // this to be less confusing if you'd like
  // Defaults to 127.0.0.1:80
  TcpClient client = TcpClient("127.0.0.1", 80, true);
}
