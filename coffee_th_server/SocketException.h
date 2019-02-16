#ifndef SocketException_class
#define SocketException_class

#include <string>

/*
 *	The header SocketException includes all functions and param for the .cpp files which has some Exceptions
*/

class SocketException
{
 public:
  SocketException ( std::string s ) : m_s ( s ) {};
  ~SocketException (){};

  std::string description() { return m_s; }

 private:

  std::string m_s;

};

#endif
