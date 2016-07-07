#include <linux/module.h>
#include "../lttng-tracer.h"

#include <pxd_trace.h>

#define LTTNG_PACKAGE_BUILD
#define CREATE_TRACE_POINTS
#undef TRACE_INCLUDE_PATH
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_PATH ../instrumentation/events/lttng-module
#define TRACE_INCLUDE_FILE pxd

#include "../instrumentation/events/lttng-module/pxd.h"

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Blake Lewis <blake@portworx.com>");
MODULE_DESCRIPTION("PX driver probes");
MODULE_VERSION(__stringify(LTTNG_MODULES_MAJOR_VERSION) "."
    __stringify(LTTNG_MODULES_MINOR_VERSION) "."
    __stringify(LTTNG_MODULES_PATCHLEVEL_VERSION)
    LTTNG_MODULES_EXTRAVERSION);
