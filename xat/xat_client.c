/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "xat.h"
#include <string.h>
#include <unistd.h>

char * IO_readKeyboard () {

	char * frase;
	char c;
	int i = 0;

	frase = (char *) malloc(sizeof(char));
	read(0, &c, 1);
	while (c == ' '){
		read (0, &c,1);
	}
	while (c != '\n') {
		frase[i] = c;
		i++;
		frase = (char*)realloc(frase, sizeof(char)*(i + 1));
		read(0, &c, 1);
	}
	frase[i] = '\0';
	printf("FRASE");
	return frase;
}

void
program_xat_1(char *host, char* user)
{
	CLIENT *clnt;
	int  *result_1;
	Message  writemsg_1_arg;
	Xat  *result_2;
	int  getchat_1_arg;
	char * keyboard;

#ifndef	DEBUG
	clnt = clnt_create (host, PROGRAM_XAT, VERSION_XAT, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	writemsg_1_arg.user = user;
	writemsg_1_arg.data = host;


	result_1 = writemsg_1(&writemsg_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed f1");
	}
	result_2 = getchat_1(&getchat_1_arg, clnt);
	if (result_2 == (Xat *) NULL) {
		clnt_perror (clnt, "call failed f2");
	}else{
		printf("HHHH");
		printf("message : %s\n", result_2->Xat_val[result_2->Xat_len-1].data);
	}
	keyboard = IO_readKeyboard();
	writemsg_1_arg.user = user;
	while (strcmp(keyboard, "EXIT")) {

		writemsg_1_arg.data = keyboard;
		result_1 = writemsg_1(&writemsg_1_arg, clnt);
		if (result_1 == (void *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		keyboard = IO_readKeyboard();
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char *user;

	if (argc < 3) {
		printf ("usage: %s server_host client_username\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	user = argv[2];
	program_xat_1 (host, user);
exit (0);
}
