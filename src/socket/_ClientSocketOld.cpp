// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"


ClientSocket::ClientSocket ( std::string host, int port )
{
	if ( ! Socket::create() )
	{
		throw SocketException ( "Could not create client socket." );
	}

	if ( ! Socket::connect ( host, port ) )
	{
		throw SocketException ( "Could not bind to port." );
	}

	m_strUnread = "";

}

void ClientSocket::setMaxLength(int lMaxLength)
{
	this->m_lMaxLenght = lMaxLength;
}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


const ClientSocket& ClientSocket::operator >> ( const char * s )
{
	std::string str;

	if(m_strUnread.empty())
	{
		if ( ! Socket::recv ( str ) )
		{
		  throw SocketException ( "Could not read from socket." );
		}
	}
	else
	{
		str = m_strUnread;
		std::cout << m_strUnread[0] << "-" << str.length() << "-";

	}

	/*
	 * if not enough place in a return buffer
	 *  - store current string in an object field
	 *  - set last length to -1 what means that read was unsuccessful
	 */
	if(str.length() > sizeof(s))
	{
		m_strUnread = str;
		m_lLastLength = -1;
	}
	else
	{
		m_strUnread = "";

		strncpy(const_cast<char*>(s), str.c_str(), str.length());
		m_lLastLength = str.length();
		std::cout << "4-";
	}

	return *this;
}

int ClientSocket::getData(const char* chBuff, int lArraySize)
{
	std::string str;
	int lLastLength;

	if(m_strUnread.empty())
	{
		if ( ! Socket::recv ( str ) )
		{
		  throw SocketException ( "Could not read from socket." );
		}
	}
	else
	{
		str = m_strUnread;
	}

	/*
	 * if not enough place in a return buffer
	 *  - store current string in an object field
	 *  - set last length to -1 what means that read was unsuccessful
	 */
	if(str.length() > lArraySize)
	{
		m_strUnread = str;
		lLastLength = -1;
	}
	else
	{
		m_strUnread = "";

		strncpy(const_cast<char*>(chBuff), str.c_str(), str.length());
		lLastLength = str.length();
	}

	return lLastLength;
}
