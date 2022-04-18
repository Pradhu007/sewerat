#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "../include/spdlog/sinks/stdout_color_sinks.h"
#include "../include/spdlog/spdlog.h"

#include <winsock2.h>
#include <ws2tcpip.h>

class TcpClient {
private:
  std::shared_ptr<spdlog::logger> logger;
  bool sock_erred = false;
  struct addrinfo *result = NULL, *ptr = NULL, hints;
  SOCKET sock;

public:
  std::string host;
  int port;
  bool do_logging;

  TcpClient(std::string host = "", int port = 80, bool log = false);
  void get_socket();
  void connect_to_host();
};

#endif