#include "fcgi_config.h"
#include "fcgiapp.h"

#define SOCKET_PATH "/tmp/fastcgi/ip.socket"

int main(void)
{
	FCGX_Init();
	int socket = FCGX_OpenSocket(SOCKET_PATH, 0);
	char* remote_addr;

	FCGX_Request request;
	if (FCGX_InitRequest(&request, socket, 0) != 0)
		return 1;

	while (1) {
		FCGX_Accept_r(&request);
		remote_addr = FCGX_GetParam("REMOTE_ADDR", request.envp);

		FCGX_PutS("Content-type: text/plain\n\n", request.out);
		FCGX_PutS(remote_addr, request.out);
		FCGX_PutS("\n", request.out);

		FCGX_Finish_r(&request);
	}
}
