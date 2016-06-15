//
// Created by Markus Jungbluth on 15.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACE_H
#define BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACE_H


#include "../flowroute/FlowRoute.h"
#include "argvparser.h"

using namespace std;
using namespace CommandLineProcessing;

class BrokerCmdInterface {
public:
    BrokerCmdInterface(int argc, char* argv[]);
    FlowRoute* getFlowRoute();

    string getBrokerServer() {
        return broker_server;
    }

    int getBrokerServerPort() {
        return stoi(broker_port);
    }

protected:
    void generateFlowRoute();

private:
    ArgvParser cmd;

    FlowRoute* flowRoute;


    string broker_server;
    string broker_port;

    string action;
    string ratelimit;
    string source;
    string destination;
    string port;
    string destination_port;
    string source_port;
    string protocol;


};


#endif //BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACE_H
