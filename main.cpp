/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <jsoncpp/json/json.h>
#include <iostream>
using namespace std;


    void error(const char *msg){
        perror(msg);
        exit(0);
    }

    int main(int argc, char *argv[]){

        int sockfd, portno, n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        //creacion del json, al leerlo se ordena de forma abc... asi que lee primero el ID

        Json::Reader reader;
        Json::Value root;
        std::string text = "{ \"Solicitud\": \"hello\", \"ID\": 147852}";

        if (!reader.parse(text, root)) {
            std::cout << reader.getFormattedErrorMessages() << std::endl;
        }
        cout << root;


        //este codigo es el mismo en server que en client
        char buffer[256];
        if (argc < 3) {
            fprintf(stderr,"usage %s hostname port\n", argv[0]);
            exit(0);
        }
        portno = atoi(argv[2]);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            error("ERROR opening socket");

        server = gethostbyname(argv[1]);

        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }
        //


        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
              (char *)&serv_addr.sin_addr.s_addr,
              server->h_length);
        serv_addr.sin_port = htons(portno);
        //

        if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
            error("ERROR connecting");
        printf("Please enter the message: ");
        bzero(buffer,256);
        fgets(buffer,255,stdin);

        n = write(sockfd,buffer,strlen(buffer));

        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0)
            error("ERROR reading from socket");
        printf("%s\n",buffer);
        close(sockfd);
        return 0;
    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <jsoncpp/json/json.h>
#include <iostream>
using namespace std;


void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    Json::Reader reader;
    Json::Value root = "{ \"Solicitud\": \"hello\", \"ID\": 147852}";
    std::string text = "{ \"Solicitud\": \"hello\", \"ID\": 147852}";


    const char* start;
    const char* end;
    static bool collectComments = true;

    reader.parse(start, end, root, collectComments);


    //char buffer[256];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    printf("Please enter the message: ");
   //bzero(buffer,256);
   //fgets(buffer,255,stdin);
   void* a;
   a=&root;

    n = write(sockfd,end,strlen(end));
    if (n < 0)
        error("ERROR writing to socket");
    //bzero(buffer,256);


    n = read(sockfd,a, size_t(a));
    if (n < 0)
        error("ERROR reading from socket");
    //printf("%s\n",buffer);
    close(sockfd);
    return 0;
}