/*
        AtlasSocket.cpp
        ----------------
        begin           : 1999.11.29
        copyright       : (C) 1999 by John Barrett (ZW)
        email           : jbarrett@box100.com
*/

#include "AtlasTCPSocket.h"

int ATCPSocket::didWSAInit = 0;

ATCPSocket::ATCPSocket()
{

#ifdef _WIN32
	if (!didWSAInit) {
		WSAStartup(0x0101, &wsadata);
		didWSAInit = 1;
		printf("Did WSAStartup\n\n");
	}
#endif

	sock = socket(AF_INET, SOCK_STREAM, 0);
}

ATCPSocket::ATCPSocket(int asock): ASocket(asock)
{
}

int	ATCPSocket::connect(string& addr, int port)
{
	struct hostent		*host;
	u_long			hostaddr;
	struct sockaddr_in	sin;
	int			res;

	host = gethostbyname(addr.c_str());
	if (host == NULL)
	{
		// try it as an IP address
		printf("converting IP Address\n");
		hostaddr = inet_addr(addr.c_str());
		printf("converting IP Address = %li \n", hostaddr);
		if (hostaddr == -1) return -1;
	} else {
		// name lookup worked, get address
		printf("reading host entry\n");
		hostaddr = *((u_long *)host->h_addr);
	}

	printf("opening connection to %li:%i on socket = %i\n", hostaddr,port,sock);

	memset(&sin, 0, sizeof(sin)); // make sure everything zero
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = hostaddr;

	return ::connect(sock, (struct sockaddr*)&sin, sizeof(sin));
}

int	ATCPSocket::listen(string& addr, int port, int backlog)
{
	u_long			myaddr;
	struct sockaddr_in	sin;
	int			res;

	myaddr = inet_addr(addr.c_str());
	if (myaddr == -1) return -1;

	memset(&sin, 0, sizeof(sin)); // make sure everything zero
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = myaddr;

	res = bind(sock, (struct sockaddr*)&sin, sizeof(sin));
	if (res == -1) return -1;

	return ::listen(sock, backlog);
}

ATCPSocket*	ATCPSocket::accept()
{
	int			newsock;
	struct sockaddr_in	sin;
	int			sinlen;

	sinlen = sizeof(sin);
	newsock = ::accept(sock, (struct sockaddr*)&sin, &sinlen);
	return new ATCPSocket(newsock);
}

int	ATCPSocket::send(string& data)
{
	return ::send(sock, data.c_str(), data.length(), 0);
}

int		ATCPSocket::recv(string& data)
{
	char	buf[2048];

	int res = ::recv(sock,buf,2047,0);

	data.erase();
	data.assign(buf,res);
	return res;
}

