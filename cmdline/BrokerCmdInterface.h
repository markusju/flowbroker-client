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

    /**
     * Returns a string containing the host name of the broker server
     * @return
     */
    string getBrokerServer() {
        return broker_server;
    }

    /**
     * Returns the defined Port
     * @return An integer containing the port number
     */
    int getBrokerServerPort() {
        return stoi(broker_port);
    }

    /**
     * Returns the defined secret
     * @return The secret defined by the user
     */
    string getSecret() {
        return secret;
    }

    /**
     * Returns the defined tolerance for replay protection
     * @return A long containing the tolerance value in milliseconds
     */
    long getTolerance() {
        return tolerance;
    }

protected:
    void generateFlowRoute();

private:
    ArgvParser cmd;

    FlowRoute* flowRoute;


    long tolerance = 10000;

    string broker_server;
    string broker_port;

    string expires;
    string secret;

    string action;
    string ratelimit;
    string source;
    string destination;
    string port;
    string destination_port;
    string source_port;
    string protocol;
    string packet_length;
    string fragment;
    string dscp;
    string tcp_flags;
    string icmp_type;
    string icmp_code;


};


#endif //BROKER_PROTOCOL_CLIENT_BROKERCMDINTERFACE_H
