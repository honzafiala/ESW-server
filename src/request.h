#ifndef SERVER_REQUEST_H
#define SERVER_REQUEST_H

#include "proto/messages.pb.h"


class ServerRequest {
public:
    ServerRequest();
    Response getResponse(Request requestMessage);
    void addWalk(Walk walk);

};

#endif // SERVER_REQUEST_H