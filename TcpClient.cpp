// TcpClient - a class for interacting with the c2 server.
#include "TcpClient.h"

#include "include/spdlog/sinks/stdout_color_sinks.h"
#include "include/spdlog/spdlog.h"
#include <windows.h>

TcpClient::TcpClient(std::string host, int port, bool log)
    : host(host), port(port), do_logging(log) {
  if (do_logging) {
    spdlog::set_level(spdlog::level::debug);
    logger = spdlog::stdout_color_mt("TcpClient");
    logger->info("Creating socket for {}:{}", host, port);
  }
  // Fetch the socket object from WinSock.
  get_socket();

  // Check for errors.
  if (sock == INVALID_SOCKET) {
    if (do_logging)
      logger->error("Error with socket: {}", WSAGetLastError());
    sock_erred = true;
    freeaddrinfo(result);
    WSACleanup();
    return;
  }

  if (do_logging)
    logger->info("Socket created successfully!");

  connect_to_host();
}

void TcpClient::get_socket() {
  // Needed by WinSock.
  WSADATA wsa_data;
  int init_result;
  init_result = WSAStartup(MAKEWORD(2, 2), &wsa_data);

  if (init_result != 0) {
    if (do_logging)
      logger->error("{}", WSAGetLastError());
    sock_erred = true;
    WSACleanup();
    return;
  }

  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  // Convert the port to a c string.
  std::string string_port = std::to_string(port);
  const char *cstr_port = string_port.c_str();

  // Check the server address and port.
  int getaddr_res = getaddrinfo(host.c_str(), cstr_port, &hints, &result);
  if (getaddr_res != 0) {
    if (do_logging)
      logger->error("Could get addrinfo : {}", getaddr_res);
    sock_erred = true;
    WSACleanup();
    return;
  }

  // Create the socket object (this is class-wide)
  sock = INVALID_SOCKET;

  // This is equal to the first address returned by getaddrinfo.
  ptr = result;

  // Create a SOCKET for connecting to server
  sock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
}

void TcpClient::connect_to_host() {
  if (do_logging) {
    logger->info("Connecting to {}:{}!", host, port);
  }
}