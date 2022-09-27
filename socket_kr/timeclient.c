#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_addr;

	char server_message[100];
	memset(server_message, '\0', sizeof(server_message));

	char ip_address[15];
	scanf("%s", &ip_address);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1303);
	server_addr.sin_addr.s_addr = inet_addr(ip_address);

	connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

	recv(server_socket, server_message, sizeof(server_message), 0);
	printf("%s\n", server_message);

	close(server_socket);

	return 0;
}
