#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

int main (int argc, int argv [])
{
try
{
ServerSocket server(7850);
while(true)
{
ServerSocket new_sock;
server.accept(new_sock);
try
{ while(true)
{
std::string data;
new_sock >> data;
std::cout << data << std::endl;

new_sock << data;
}
}
catch (SocketException&) {}

}
}
catch (SocketException & e)
{
std::cout << "Error" << e.description () << "\nExiting. \n";
}
return 0;
}
