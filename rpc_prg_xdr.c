/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc_prg.h"

bool_t
xdr_echo (XDR *xdrs, echo *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->a, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_sort_arr (XDR *xdrs, sort_arr *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->b, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->number_sort))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->b;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->number_sort);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->b, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->number_sort))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->b;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->number_sort = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->b, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->number_sort))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_multiply (XDR *xdrs, multiply *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (4 +  100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->row1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col2))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->matrixA, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->matrixB, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->row1);
			IXDR_PUT_LONG(buf, objp->row2);
			IXDR_PUT_LONG(buf, objp->col1);
			IXDR_PUT_LONG(buf, objp->col2);
			{
				register int *genp;

				for (i = 0, genp = objp->matrixA;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->matrixB;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (4 +  100  + 100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->row1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->row2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->col2))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->matrixA, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->matrixB, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->row1 = IXDR_GET_LONG(buf);
			objp->row2 = IXDR_GET_LONG(buf);
			objp->col1 = IXDR_GET_LONG(buf);
			objp->col2 = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->matrixA;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			{
				register int *genp;

				for (i = 0, genp = objp->matrixB;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->row1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->row2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->col1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->col2))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->matrixA, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->matrixB, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_result_mat (XDR *xdrs, result_mat *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->matrixC, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->matrixC;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->matrixC, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->matrixC;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->matrixC, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_time_char (XDR *xdrs, time_char *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->T, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}
