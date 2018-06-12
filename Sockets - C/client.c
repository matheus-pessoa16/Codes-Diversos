/*
* connect.c: conecta no loopback utilizando TCP/80
*
* Para compilar:
* cc -Wall connect.c -o connect
* Matheus Pessoa
* Alexandre Fiori
*/
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
/* define o destino da conexão, porta 80 em localhost */
#define DESTINO_ADDR "127.0.0.1"
#define DESTINO_PORT 3000


int send_msg(int socket, char *s){
	int result = send(socket, s, strlen(s), 0);
	if (result == -1){
		fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
	}
	return result;
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
	//memset(s, 0, slen);
  }
  if (c < 0)
    return c;
  else if (c == 0)
    buf[0] = '\0';
  else
    s[c-1]='\0';
  return len - slen; // caso não sejam enviados todos os dados, mostro quanto falta para enviar
}



int main(){
    int fd;
    struct in_addr addr;
    struct sockaddr_in sock;
    //struct protoent *proto = getprotobyname("tcp");
    /* cria o socket */
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) {
        perror("socket");
        return 1;
    }
    /* limpa as estruturas que serão utilizadas */
    memset(&addr, 0, sizeof(addr));
    memset(&sock, 0, sizeof(sock));
    /* converte determinado endereço para network byte order */
    if(!inet_aton(DESTINO_ADDR, &addr)) {
        fprintf(stderr, "Endereço inválido!\n");
        //prinf();
        close(fd); /* é importante fechar o socket! */
        return 1;
    }
    /* preenche a estrutura sockaddr_in: onde vamos conectar */
    sock.sin_family = AF_INET;
    sock.sin_addr = addr;
    sock.sin_port = htons(DESTINO_PORT);

    /* conecta */
    if(connect(fd, (struct sockaddr *) &sock, sizeof(sock)) == -1){
        perror("connect");
        close(fd);
        return 1;
    }

    // int reuse = 1;
    // if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1){
	// 	error("Can't set the reuse option on the socket");
	// }
    char buf[255];
    int len = sizeof(buf);

    /* agora estamos conectados em DESTINO_ADDR, DESTINO_PORT utilizando
    * o protocolo TCP */
    fprintf(stdout, "Conectado a %s, %d...\n", DESTINO_ADDR, DESTINO_PORT);
    //send_msg(fd, "Teste");
    //sleep(1);
    /* desconecta */
    //shutdown(fd, 2);

    send(fd, "Teste", 6, 0);
    read_in(fd, buf, len);
    printf("%s\n", buf);
    send(fd, "Teste", 6, 0);
    while(read_in(fd, buf, len)){

    }
    // if( != -1){
    //     read_in(fd, buf, len);
    //     printf("%s\n", buf);
    // }


    // while(1){
    //     read_in(fd, buf, len);
    //     if(strncasecmp("Teste de mensagem", buf,len)){
    //         send_msg(fd, "Teste");
    //     }
    // }

    close(fd);
    return 0;
}
