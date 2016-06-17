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



/**
 * Reference Implementation for the Broker Protocol
 */

using namespace std;

int main(int argc, char** argv) {

    MessageAuthenticationCode code("secret");
    string hmac = code.getMacForMessage("test");
    cout << hmac << "\n";

    try {
        BrokerCmdInterface cmd(argc, argv);
        BrokerClient client(cmd.getBrokerServer(), cmd.getBrokerServerPort());

        BrokerReplyParser parser;
        BrokerReplyEvaluator evaluator;
        BrokerProtocol protocol(&client, &parser, &evaluator);

        FlowRoute* route = cmd.getFlowRoute();

        /*
        FlowRoute route;

        set<string> seta = {"tcp"};
        Protocol prot(seta);

        DestinationAddress dest("134.96.43.11/24");

        SourceAddress src("8.8.8.8/32");
        DISCARD discard(&src);
        RATELIMIT ratelimit(&src, 10000);


        route.setDestination_address(&dest);
        route.setProtocol(&prot);
        route.setFilter_action(&discard);
        */


        BrokerRequest req = route->parseToRequest();

        protocol.send(&req);


    } catch(exception& exc) {
        cerr << "An Error occured: " << exc.what() << "\n";
    }


    /*
    Client client;
    string host;

    client.conn("127.0.0.1", 5653);

    client.send_data("DISCARD 8.8.8.8/32\nPort: =80;>70&<100\n\n");

    cout << client.receive(1024);
     */

    return 0;
}