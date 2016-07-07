#undef TRACE_SYSTEM
#define TRACE_SYSTEM pxd

#if !defined(_LTTNG_PXD_H) || defined(TRACE_HEADER_MULTI_READ)
#define _LTTNG_PXD_H

#include "../../../probes/lttng-tracepoint-event.h"
#include <linux/tracepoint.h>

LTTNG_TRACEPOINT_EVENT(
	pxd_open,
	TP_PROTO(uint64_t dev_id, int major, int minor, fmode_t mode, int err),
	TP_ARGS(dev_id, major, minor, mode, err),
	TP_FIELDS(
		ctf_integer(uint64_t, dev_id_field, dev_id)
		ctf_integer(int, minor_field, minor)
		ctf_integer(fmode_t, mode_field, mode)
		ctf_integer(int, err_field, err)))

LTTNG_TRACEPOINT_EVENT(
	pxd_release,
	TP_PROTO(uint64_t dev_id, int major, int minor, fmode_t mode),
	TP_ARGS(dev_id, major, minor, mode),
	TP_FIELDS(
		ctf_integer(uint64_t, dev_id_field, dev_id)
		ctf_integer(int, major_field, major)
		ctf_integer(int, minor_field, minor)
		ctf_integer(fmode_t, mode_field, mode)))

LTTNG_TRACEPOINT_EVENT(
	pxd_ioctl,
	TP_PROTO(uint64_t dev_id, int major, int minor, fmode_t mode,
			 unsigned int cmd, unsigned long arg, int err),
	TP_ARGS(dev_id, major, minor, mode, cmd, arg, err),
	TP_FIELDS(
		ctf_integer(uint64_t, dev_id_field, dev_id)
		ctf_integer(int, major_field, major)
		ctf_integer(int, minor_field, minor)
		ctf_integer(fmode_t, mode_field, mode)
		ctf_integer(unsigned, cmd_field, cmd)
		ctf_integer(unsigned long, arg_field, arg)
		ctf_integer(int, err_field, err)))

LTTNG_TRACEPOINT_EVENT(
	pxd_request,
	TP_PROTO(
		uint64_t reqctr, uint64_t unique, uint32_t size, uint64_t off,
		uint32_t minor, uint32_t flags, bool qfn),
	TP_ARGS(reqctr, unique, size, off, minor, flags, qfn),
	TP_FIELDS(
		ctf_integer(uint64_t, reqctr_field, reqctr)
		ctf_integer(uint64_t, unique_field, unique)
		ctf_integer(uint32_t, size_field, size)
		ctf_integer(uint64_t, off_field, off)
		ctf_integer(uint32_t, minor_field, minor)
		ctf_integer_hex(uint32_t, flags_field, flags)
		ctf_integer(uint32_t, qfn_field, qfn)))

LTTNG_TRACEPOINT_EVENT(
	pxd_reply,
	TP_PROTO(uint64_t reqctr, uint64_t unique, uint32_t flags),
	TP_ARGS(reqctr, unique, flags),
	TP_FIELDS(
		ctf_integer(uint64_t, reqctr_field, reqctr)
		ctf_integer(uintptr_t, unique_field, unique)
		ctf_integer_hex(uint32_t, flags_field, flags)))

LTTNG_TRACEPOINT_EVENT(
	pxd_get_fuse_req,
	TP_PROTO(uint64_t reqctr, int nr_pages),
	TP_ARGS(reqctr, nr_pages),
	TP_FIELDS(
		ctf_integer(uint64_t, reqctr_field, reqctr)
		ctf_integer(int, nr_pages_field, nr_pages)))

LTTNG_TRACEPOINT_EVENT(
	pxd_get_fuse_req_result,
	TP_PROTO(uint64_t reqctr, int status, int eintr),
	TP_ARGS(reqctr, status, eintr),
	TP_FIELDS(
		ctf_integer(uint64_t, reqctr_field, reqctr)
		ctf_integer(int, status_field, status)
		ctf_integer(int, eintr_field, eintr)))
#endif /* !defined(_LTTNG_PXD_H) || defined(TRACE_HEADER_MULTI_READ) */

#include "../../../probes/define_trace.h"
