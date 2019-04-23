#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "headers.h"

int main() {
	int sock, bytes_recieved, fromlen;
	char buffer[65535];
	struct sockaddr_in from;
	struct ip  *ip;
	struct tcp *tcp;

	sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

while(1)	 {
	fromlen = sizeof from;
	bytes_recieved = recvfrom(sock, buffer, sizeof buffer, 0,
				(struct sockaddr *)&from, &fromlen);
	printf("\nBytes recebidos : %5d\n",bytes_recieved);
	printf("IP Origem : %s\n",inet_ntoa(from.sin_addr));
	ip = (struct ip *)buffer;
	printf("Tamanho do cabeçalho IP : %d\n",ip->ip_length);
	printf("Protocolo : %d\n",ip->ip_protocol);
	tcp = (struct tcp *)(buffer + (4*ip->ip_length));
	printf("Porta origem : %d\n", ntohs(tcp->tcp_source_port));

	if ((ntohs(tcp->tcp_source_port)) == 22) {
		printf("Backdoor encontrado!!!");
	}

	printf("Porta destino : %d\n", ntohs(tcp->tcp_dest_port));
       	 }
}
