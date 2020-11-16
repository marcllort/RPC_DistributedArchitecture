/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "xat.h"
#include <string.h>


int *
writemsg_1_svc(Message *argp, struct svc_req *rqstp)
{
	static int  result;

	FILE * f = fopen("xat.txt", "a");

	fprintf(f, "%s : %s\n", argp->user, argp->data);
			printf("MESSAGE RECEIVED --- %s : %s\n", argp->user, argp->data);

	fclose(f);

	return &result;
}

int CHAIN_add(Xat *h, Message msg) {

	h->Xat_val = realloc(h->Xat_val, (h->Xat_len + 1) * sizeof(Message));

	h->Xat_val[h->Xat_len].data = malloc(strlen(msg.data) + 1);
	h->Xat_val[h->Xat_len].user = malloc(strlen(msg.user) + 1);

	strcpy(h->Xat_val[h->Xat_len].data, msg.data);
	strcpy(h->Xat_val[h->Xat_len].user, msg.user);


	return ++h->Xat_len;
}

void CHAIN_toString(Xat h) {
	char aux[200 + 1];

	sprintf(aux, "CHAIN string: %d\n", h.Xat_len);

	for (u_int i = 0; i < h.Xat_len; i++) {
		sprintf(aux, "%s: ", h.Xat_val[i].user);
		sprintf(aux, "%s\n", h.Xat_val[i].data);
	}

}

Xat *
getchat_1_svc(int *argp, struct svc_req *rqstp)
{
	static Xat result;
	printf("peta1\n");
	//u_int index;
	Xat h;

	h.Xat_len = 0;
	h.Xat_val = NULL;
	Xat messages = h;
	
	printf("peta2\n");
	FILE * f = fopen("xat.txt", "r");
	if (f != NULL) {
		while (!feof(f))
		{
			Message m;
			char *line = (char *) malloc (sizeof(char) * 200);
			fgets(line, 200, f);
			char *p;
			if (strlen(line) > 0)
			{
				p = strtok(line, ":");
				if(p)
				{
					printf("NAME: %s\n", p);
				}
				m.user = p;
				p = strtok(NULL, ":");

				if(p){
					printf("MESSAGE: %s\n", p);
				}
				
				m.data = p;
				
			
			CHAIN_add(&messages, m);
			}
			
		}
		
		

	}
	/*for (index = 0; index < h.Xat_len; index++)
		CHAIN_add(&messages, h.Xat_val[index]);
	*/
	Message m;
	m.data="test";
	m.user="marc";
	CHAIN_add(&messages, m);
	result = messages;
	CHAIN_toString(result);
	printf("peta3\n");

	return &result;
}
