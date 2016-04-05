// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class ClientSocket
{
	int m_lLastLength;
	int m_lMaxLenght;

	tcp::socket * s;

public:

	ClientSocket ( std::string host, int port );
	~ClientSocket();

	void setMaxLength(int nMaxLength);
	int getLastLength() { return m_lLastLength; }

	int getData( char*, int );

};


#endif
