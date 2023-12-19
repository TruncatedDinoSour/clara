#ifndef _CLARA_HTTP_H
#define _CLARA_HTTP_H
#include <stddef.h>

#include "map.h"

typedef enum {
    GET = 0,
    POST,
    PUT,
    DELETE,
    HEAD,
    OPTIONS,
    PATCH,
    CONNECT,
    TRACE
} ClaraMethod;

typedef struct {
    unsigned short code;
    ClaraMap *headers;
    size_t content_size;
    char *content;
} ClaraResponse;

typedef struct _ClaraRequest ClaraRequest;

typedef ClaraResponse (*ClaraRequestHandler)(ClaraRequest *);

typedef struct {
    ClaraMethod method;
    ClaraRequestHandler handler;
    const char *route;
} ClaraRoute;

struct _ClaraRequest {
    ClaraMethod method;
    ClaraMap *headers;
    size_t content_size;
    char *content;
    ClaraRoute route;
};
#endif /* _CLARA_HTTP_H */
