/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "xat.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
writemsg_1(argp, clnt)
	Message *argp;
	CLIENT *clnt;
{
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, writeMsg, xdr_Message, argp, xdr_int, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}

Xat *
getchat_1(argp, clnt)
	int *argp;
	CLIENT *clnt;
{
	static Xat clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, getChat, xdr_int, argp, xdr_Xat, &clnt_res, TIMEOUT) != RPC_SUCCESS)
		return (NULL);
	return (&clnt_res);
}
