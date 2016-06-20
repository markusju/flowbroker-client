//
// Created by Markus Jungbluth on 15.06.16.
//

#include <stdlib.h>
#include <iostream>
#include "BrokerCmdInterface.h"
#include "../flowroute/fields/DISCARD.h"
#include "../flowroute/fields/RATELIMIT.h"
#include "exceptions/BrokerCmdInterfaceValueErrorException.h"


BrokerCmdInterface::BrokerCmdInterface(int argc, char **argv) {

    //Defaults

    broker_port = "5653";
    ratelimit = "9600";


    // init
    cmd.setIntroductoryDescription("BrokerProtocol Denial of Service mitigation client.\nUsage:");

    //define error codes
    cmd.addErrorCode(0, "Success");
    cmd.addErrorCode(1, "Error");

    cmd.setHelpOption("h", "help", "Print this help page");

    cmd.defineOption("secret", "HMAC secret used to secure the communication with the Broker Server", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("broker-server", "BrokerServer address", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("broker_port", "BrokerServer port\nDefault: 5653", ArgvParser::OptionRequiresValue);
    cmd.defineOption("action", "Defines a traffic action.\nValid actions are: DISCARD, RATELIMIT", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("rate-limit", "Defines the rate at which a traffic aggregate is to be limited\nDefault: 9600", ArgvParser::OptionRequiresValue);
    cmd.defineOption("source", "Defines the source IPv4 prefix for a traffic action:\nExample: 8.8.8.8/32", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("destination", "Specifies a destination address for the traffic action.\nExample: 8.8.8.8/32.\nIf not set, this will default to the host's IP-Address.", ArgvParser::OptionRequiresValue);
    cmd.defineOption("expires", "Defines a duration in seconds, after which the FlowSpec is revoked on the broker", ArgvParser::OptionRequiresValue);
    cmd.defineOption("port", "", ArgvParser::OptionRequiresValue);
    cmd.defineOption("destination-port", "", ArgvParser::OptionRequiresValue);
    cmd.defineOption("source-port", "", ArgvParser::OptionRequiresValue);
    cmd.defineOption("protocol", "", ArgvParser::OptionRequiresValue);


    // finally parse and handle return codes (display help etc...)
    int result = cmd.parse(argc, argv);

    if (result != ArgvParser::NoParserError)
    {
        cout << cmd.parseErrorDescription(result);
        exit(1);
    }

    if (cmd.foundOption("secret")) secret = cmd.optionValue("secret");
    if (cmd.foundOption("broker-server")) broker_server = cmd.optionValue("broker-server");
    if (cmd.foundOption("broker-port")) broker_port = cmd.optionValue("broker-port");


    if (cmd.foundOption("action")) action = cmd.optionValue("action");
    if (cmd.foundOption("expires")) expires = cmd.optionValue("expires");
    if (cmd.foundOption("ratelimit")) ratelimit = cmd.optionValue("ratelimit");
    if (cmd.foundOption("source")) source = cmd.optionValue("source");
    if (cmd.foundOption("destination")) destination = cmd.optionValue("destination");
    if (cmd.foundOption("port")) port = cmd.optionValue("port");
    if (cmd.foundOption("destination-port")) destination_port = cmd.optionValue("destination-port");
    if (cmd.foundOption("source-port")) source_port = cmd.optionValue("source-port");
    if (cmd.foundOption("protocol")) protocol = cmd.optionValue("protocol");

    this->generateFlowRoute();

}

FlowRoute *BrokerCmdInterface::getFlowRoute() {
    return flowRoute;
}

void BrokerCmdInterface::generateFlowRoute() {
    flowRoute = new FlowRoute();


    if (!action.empty()) {

        if (!source.empty()) {

            if (action == "DISCARD") {
                flowRoute->setFilter_action(
                        new DISCARD(
                                new SourceAddress(source)
                        )
                );

            } else if (action == "RATELIMIT") {
                flowRoute->setFilter_action(
                        new RATELIMIT(
                                new SourceAddress(source),
                                stoi(ratelimit)
                        )
                );

            } else {
                throw BrokerCmdInterfaceValueErrorException("Invalid traffic action!");
            }

        } else {
            //Illegal State
            throw BrokerCmdInterfaceValueErrorException("No source address defined!");
        }

    } else {
        //Illegal State
        throw BrokerCmdInterfaceValueErrorException("No traffic action defined!");
    }


    if (!destination.empty()) {
        flowRoute->setDestination_address(new DestinationAddress(destination));
    }

    if (!expires.empty()) {
        flowRoute->setExpires(new Expires(stoi(expires)));
    }

    if (!port.empty()) {
        //TODO
    }

    if (!destination_port.empty()) {
        //TODO
    }

    if (!source_port.empty()) {
        //TODO
    }

    if (!protocol.empty()) {
        flowRoute->setProtocol(new Protocol(protocol));
    }

}
