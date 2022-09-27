#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

int main()
{
	int server_socket, client_socket;
	struct sockaddr_in server_addr, client_addr;

    int client_size;
    char client_message[30];
    memset(client_message, '\0', sizeof(client_message));
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1303);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_socket, 1);

    for (;;) {
        client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);

        time_t timer;
        struct tm* time_info;
        timer = time(NULL);
        time_info = localtime(&timer);

        strftime(client_message, 30, "%Y.%m.%d %H:%M", time_info);

        send(client_socket, client_message, sizeof(client_message), 0);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}
