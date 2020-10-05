#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 10
#define PORT 43454
#define SA struct sockaddr
int main()
{
char buff[MAX];
const char *buf[2];
int sockfd,len,n,m;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(len));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(PORT);
len=sizeof(servaddr);
for(;;)
{
printf("\nEnter message: ");
n=0,m=0;
while((buff[n++]=getchar())!='\n');
sendto(sockfd,buff,sizeof(buff),0,(SA *)&servaddr,len);

if(strncmp("bye",buff,3)==0)
{
printf("Client Exit...\n");
break;
}
else{
printf("Enter shift: ");
while((buf[m++]=getchar())!='\n')
sendto(sockfd,buf,sizeof(buf),0,(SA *)&servaddr,len);

bzero(buff,sizeof(buff));
recvfrom(sockfd,buff,sizeof(buff),0,(SA *)&servaddr,&len);
printf("From Server : %s\n",buff);
if(strncmp("bye",buff,3)==0)
{
printf("Client Exit...\n");
break;
}}
}
close(sockfd);
}
