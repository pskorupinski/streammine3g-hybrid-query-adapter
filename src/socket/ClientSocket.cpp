// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"
#include <stdexcept>


ClientSocket::ClientSocket ( std::string host, int port )
{
	char* strHost = new char[host.length() + 1];
	strcpy(strHost, host.c_str());

	char* strPort = new char[6];
	snprintf(strPort, 6, "%d", port);

    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);

    tcp::resolver::query query(tcp::v4(), strHost, strPort);
    tcp::resolver::iterator iterator = resolver.resolve(query);

    s = new tcp::socket(io_service);

	try {
	    s->connect(*iterator);
	} catch(boost::system::system_error& e) {
		s = 0;
		throw std::runtime_error ( "Could not connect." );
	}

	delete [] strPort;
	delete [] strHost;

}


ClientSocket::~ClientSocket()
{
	boost::system::error_code error;
	s->shutdown(boost::asio::ip::tcp::socket::shutdown_both, error);
//	std::cout << "1";
	if (error == boost::asio::error::eof) {
//		std::cout << "2a";
		return; 									// Connection closed cleanly by peer.
	}
	else if (error) {
//		std::cout << "2b";
		throw boost::system::system_error(error); 	// Some other error.
	}
//	std::cout << "2c";
//
//	s->close(error);
//
//	std::cout << "3";
//	if (error == boost::asio::error::eof) {
//		std::cout << "4a";
//		return; 									// Connection closed cleanly by peer.
//	}
//	else if (error) {
//		std::cout << "4b";
//		throw boost::system::system_error(error); 	// Some other error.
//	}
//	std::cout << "4c";
//
//	delete s;
//
//	std::cout << "5";
}

void ClientSocket::setMaxLength(int lMaxLength)
{
	this->m_lMaxLenght = lMaxLength;
}

int ClientSocket::getData(char* chBuff, int lArraySize)
{
//	std::string str;
//	int lLastLength;

//	if(m_strUnread.empty())
//	{
	size_t reply_length;
	if(s != 0) {
		try {
			reply_length = boost::asio::read(*s, boost::asio::buffer(chBuff, lArraySize));
		} catch(boost::system::system_error& e) {
		  throw std::runtime_error ( "Could not read from socket." );
		}
	}

//	}
//	else
//	{
//		str = m_strUnread;
//	}
//
//	/*
//	 * if not enough place in a return buffer
//	 *  - store current string in an object field
//	 *  - set last length to -1 what means that read was unsuccessful
//	 */
//	if(str.length() > lArraySize)
//	{
//		m_strUnread = str;
//		lLastLength = -1;
//	}
//	else
//	{
//		m_strUnread = "";
//
//		strncpy(const_cast<char*>(chBuff), str.c_str(), str.length());
//		lLastLength = str.length();
//	}
//
	return reply_length;
}
