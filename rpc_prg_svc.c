/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc_prg.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
rpc_prg_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		int time_func_1_arg;
		echo echo_message_1_arg;
		int listfiles_1_arg;
		sort_arr sorting_1_arg;
		multiply multiplier_1_arg;
	} argument;
	union {
		time_char time_func_1_res;
		echo echo_message_1_res;
		char *listfiles_1_res;
		sort_arr sorting_1_res;
		result_mat multiplier_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case time_func:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_time_char;
		local = (bool_t (*) (char *, void *,  struct svc_req *))time_func_1_svc;
		break;

	case echo_message:
		_xdr_argument = (xdrproc_t) xdr_echo;
		_xdr_result = (xdrproc_t) xdr_echo;
		local = (bool_t (*) (char *, void *,  struct svc_req *))echo_message_1_svc;
		break;

	case listFiles:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (bool_t (*) (char *, void *,  struct svc_req *))listfiles_1_svc;
		break;

	case sorting:
		_xdr_argument = (xdrproc_t) xdr_sort_arr;
		_xdr_result = (xdrproc_t) xdr_sort_arr;
		local = (bool_t (*) (char *, void *,  struct svc_req *))sorting_1_svc;
		break;

	case multiplier:
		_xdr_argument = (xdrproc_t) xdr_multiply;
		_xdr_result = (xdrproc_t) xdr_result_mat;
		local = (bool_t (*) (char *, void *,  struct svc_req *))multiplier_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!rpc_prg_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (RPC_PRG, RPC_PRG_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, RPC_PRG, RPC_PRG_VERS, rpc_prg_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (RPC_PRG, RPC_PRG_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, RPC_PRG, RPC_PRG_VERS, rpc_prg_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (RPC_PRG, RPC_PRG_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}