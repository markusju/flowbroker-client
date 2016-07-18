#include <iostream>
#include "client/Client.h"
#include "flowroute/FlowRoute.h"
#include "flowroute/fields/SourceAddress.h"
#include "flowroute/fields/Protocol.h"
#include "flowroute/fields/DISCARD.h"
#include "flowroute/fields/RATELIMIT.h"
#include "protocol/parser/BrokerReplyParser.h"
#include "client/BrokerClient.h"
#include "protocol/BrokerProtocol.h"
#include "cmdline/BrokerCmdInterface.h"
#include "protocol/security/MessageAuthenticationCode.h"
#include "flowroute/fields/Fragment.h"
#include "flowroute/fields/TCPFlags.h"
#include <stdlib.h>

#define PROGNAME "broker_client"
/**
 * Reference Implementation for the Broker Protocol
 */

using namespace std;


int main(int argc, char** argv) {
    try {

        //Command Line Interface
        BrokerCmdInterface cmd(argc, argv);

        //Setting up the client with options obtained from CMD
        BrokerClient client(cmd.getBrokerServer(), cmd.getBrokerServerPort());

        BrokerReplyParser parser;
        BrokerReplyEvaluator evaluator;
        BrokerSecurityModule secModule(cmd.getSecret(), cmd.getTolerance());
        BrokerProtocol protocol(&client, &parser, &evaluator, &secModule);

        //Obtaining FlowRoute from CMD
        FlowRoute* route = cmd.getFlowRoute();

        BrokerRequest req = route->parseToRequest();

        protocol.send(&req);

    } catch(exception& exc) {
        cerr << PROGNAME << ": " << exc.what() << "\n";
        return 1;
    }

    return 0;
}