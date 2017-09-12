#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>


//GLOBAL
int listener_d;

int error(char *msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int open_listener_socket(){
	int s = socket(PF_INET, SOCK_STREAM, 0); // cria um socket do tipo tcp aceitando qualquer configuração de IP
	if(s == -1){
		error("Can't open socket");
	}
	return s;
}

void bind_to_port(int socket, int port){
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(port); // seta a porta 3000 para se conectar
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1){
		error("Can't set the reuse option on the socket");
	}
	int c = bind(socket, (struct sockaddr*)&name, sizeof(name)); // tenta conectar o socket criado na porta 3000
	if(c == -1){
		error("Can't bind the socket");
	}
}

int send_msg(int socket, char *s){
	int result = send(socket, s, strlen(s), 0);
	if (result == -1){
		fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
	}
	return result;
}

void shutdown_connection(int sig){
	if(listener_d){
		close(listener_d);
	}
	fprintf(stderr, "Connection close!\n");
	exit(0);
}

void print_msg(char *msg){
	printf("Mensagem recebida: %s\n", msg);
}


int read_in(int socket, char *buf, int len){
  char *s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);
  while ((c > 0) && (s[c-1] != '\n')) {
	s += c;
	slen -= c;
	c = recv(socket, s, slen, 0);
	print_msg(s);
	memset(s, 0, slen);
  }
  if (c < 0)
    return c;
  else if (c == 0)
    buf[0] = '\0';
  else
    s[c-1]='\0';
  return len - slen; // caso não sejam enviados todos os dados, mostro quanto falta para enviar
}

int main(int argc, char *argv[]){
	// if(catch_signal(SIGINT, shutdown_connection) == -1){
	// 	error("Can't set the interrupt handler");
	// }

	char *cliente_ip;
	int cliente_port;
	struct sockaddr_in cliente; // socket do cliente

	listener_d = open_listener_socket(); //inicio uma conexão
	bind_to_port(listener_d, 3000); // tento fixar uma porta ao socket criado

	if(listen(listener_d, 5) == -1){ // posso enfileirar até 5 tentativas de conexão que irão esperar até poder conectar
		error("Can't listen");
	}

	unsigned int address_size = sizeof(cliente);

	puts("Waiting for connections");
	char buff[255]; // buffer que recebe e envia as mensagens
	int len_buff;
	memset(buff, 0, sizeof(buff)); // zero o buffer

	while(1){


		int connect_d = accept(listener_d, (struct sockaddr *)&cliente, &address_size); //tento conectar ao servidor
																					//passando o socket cliente que irá se
																						//conectar

		if(connect_d == -1){
			error("Can't open secondary socket");
		}

		cliente_ip = inet_ntoa(cliente.sin_addr); // pego o ip e a porta do cliente que se conectou
		cliente_port = ntohs(cliente.sin_port);

		printf("cliente conectou: %s : [ %d ]\n", cliente_ip, cliente_port);

		len_buff = sizeof(buff);
		//read_in(connect_d, buff, len_buff);
		if(send_msg(connect_d, "Teste de mensagem\n") != -1){ // envio a mensagem para o cliente
			read_in(connect_d, buff, len_buff); // recebo uma mensagem de volta - preciso pressionar ctrl + c para ver no server
			//read_in(listener_d, buff, len_buff);

			if(strncasecmp("Teste", buff, 5)){	// caso a mensagem recebida seja "Teste", envio uma resposta
				send_msg(connect_d, "Bem sucedido\n");
			}else{
				if(send_msg(connect_d, "Testando") != -1){ // envio testando para o cliente
					read_in(connect_d, buff, len_buff);
					//read_in(listener_d, buff, len_buff);
				}else{
					if( strncasecmp("close", buff, 5) ){
						close(connect_d);
					}
				}
			}

		}

	}

	return 0;
}
