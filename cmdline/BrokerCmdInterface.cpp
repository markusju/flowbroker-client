//
// Created by Markus Jungbluth on 15.06.16.
//

#include <stdlib.h>
#include <iostream>
#include "BrokerCmdInterface.h"
#include "../flowroute/fields/DISCARD.h"
#include "../flowroute/fields/RATELIMIT.h"
#include "exceptions/BrokerCmdInterfaceValueErrorException.h"
#include "../flowroute/fields/SourcePort.h"
#include "../flowroute/fields/WITHDRAW.h"
#include "../flowroute/fields/ICMPCode.h"
#include "../flowroute/fields/ICMPType.h"
#include "../version.h"


BrokerCmdInterface::BrokerCmdInterface(int argc, char **argv) {

    //Defaults

    broker_port = "5653";
    ratelimit = "9600";



    // init
    string descr = "broker_client ("+ string(VERSION)+ "):\nUsage:";
    cmd.setIntroductoryDescription(descr);

    //define error codes
    cmd.addErrorCode(0, "Success");
    cmd.addErrorCode(1, "Error");

    cmd.setHelpOption("h", "help", "Print this help page");


    cmd.defineOption("broker-server", "BrokerServer address", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("broker_port", "BrokerServer port\nDefault: 5653", ArgvParser::OptionRequiresValue);
    cmd.defineOption("secret", "HMAC secret used to secure the communication with the Broker Server", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("action", "Defines a traffic action.\nValid actions are: DISCARD, RATELIMIT and WITHDRAW", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("ratelimit", "Defines the rate at which a traffic aggregate is to be limited\nDefault: 9600", ArgvParser::OptionRequiresValue);
    cmd.defineOption("source", "Defines the source IPv4 prefix for a traffic action:\nExample: 8.8.8.8/32", ArgvParser::OptionRequired | ArgvParser::OptionRequiresValue);
    cmd.defineOption("destination", "Specifies a destination address for the traffic action.\nExample: 8.8.8.8/32.\nIf not set, this will default to the host's IP-Address.", ArgvParser::OptionRequiresValue);
    cmd.defineOption("expires", "Defines a duration in seconds, after which the FlowSpec is revoked on the broker", ArgvParser::OptionRequiresValue);
    cmd.defineOption("port", "Defines a source AND destination port. \n Example: =80&=90 or >80&<120", ArgvParser::OptionRequiresValue);
    cmd.defineOption("destination-port", "Defines a destination port. \n Example: =80&=90 or >80&<120", ArgvParser::OptionRequiresValue);
    cmd.defineOption("source-port", "Defines a source port. \n Example: =80&=90 or >80&<120", ArgvParser::OptionRequiresValue);
    cmd.defineOption("protocol", "Defines one or many Layer 4 protocols as match criteria. \n Valid protocols are: tcp, udp", ArgvParser::OptionRequiresValue);
    cmd.defineOption("packet-length", "Defines a oacket length or packet length range as match criteria. \n Example: 5000;>50&<2000", ArgvParser::OptionRequiresValue);
    cmd.defineOption("fragment", "Defines one or many properties to select fragmented packets. \n Valid properties are: \n not-a-fragment, dont-fragment, is-fragment, first-fragment, last-fragment", ArgvParser::OptionRequiresValue);
    cmd.defineOption("dscp", "DEfines one or many DSCP or DSCP ranges. \n Example: 10;>13&<24", ArgvParser::OptionRequiresValue);
    cmd.defineOption("tcp-flags", "Defines one or many TCP-Flags as match criteria. \n Valid Flags are: \n fin, syn, rst, push, ack, urgent", ArgvParser::OptionRequiresValue);
    cmd.defineOption("icmp-type", "Defines one or many ICMP-Types as match criteria. \n Valid Types are: \n echo-reply, echo-request, info-reply, info-request, mask-reply, mask-request, parameter-problem, redirect, router-advertisement, router-solicit, source-quench, time-exceeded, timestamp, timestamp-reply, unreachable\n ", ArgvParser::OptionRequiresValue);
    cmd.defineOption("icmp-code", "Defines one or many ICMP-Codes as match criteria. \n Valid Codes are: \n communication-prohibited-by-filtering, destination-host-prohibited, destination-host-unknown, destination-network-unknown, fragmentation-needed, host-precedence-violation, ip-header-bad, network-unreachable, network-unreachable-for-tos, port-unreachable, redirect- for-host,redirect-for-network, redirect-for-tos-and-host, redirect-for-tos-and-net, required- option-missing, source-host-isolated, source-route-failed, ttl-eq-zero-during-reassembly, ttl-eq-zero-during-transit", ArgvParser::OptionRequiresValue);
    cmd.defineOption("tolerance", "Defines the tolerance for the replay attack protection in milliseconds. \nThe tolerance is both applied to future and past dates. \nDefault: +/-10000", ArgvParser::OptionRequiresValue);


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
    if (cmd.foundOption("packet-length")) packet_length = cmd.optionValue("packet-length");
    if (cmd.foundOption("fragment")) fragment = cmd.optionValue("fragment");
    if (cmd.foundOption("dscp")) dscp = cmd.optionValue("dscp");
    if (cmd.foundOption("tcp-flags")) tcp_flags = cmd.optionValue("tcp-flags");
    if (cmd.foundOption("icmp-type")) icmp_type = cmd.optionValue("icmp-type");
    if (cmd.foundOption("icmp-code")) icmp_code = cmd.optionValue("icmp-code");
    if (cmd.foundOption("tolerance")) tolerance = stol(cmd.optionValue("tolerance"));


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

            } else if (action == "WITHDRAW") {
                flowRoute->setFilter_action(
                        new WITHDRAW(
                                new SourceAddress(source)
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
        flowRoute->setPort(new Port(port));
    }

    if (!destination_port.empty()) {
        flowRoute->setDestination_port(new DestinationPort(destination_port));
    }

    if (!source_port.empty()) {
        flowRoute->setSource_port(new SourcePort(source_port));
    }

    if (!protocol.empty()) {
        flowRoute->setProtocol(new Protocol(protocol));
    }

    if (!packet_length.empty()) {
        flowRoute->setPacket_length(new PacketLength(packet_length));
    }

    if (!fragment.empty()) {
        flowRoute->setFragment(new Fragment(fragment));
    }

    if (!dscp.empty()) {
        flowRoute->setDscp(new DSCP(dscp));
    }

    if (!tcp_flags.empty()) {
        flowRoute->setTcp_flags(new TCPFlags(tcp_flags));
    }

    if (!icmp_type.empty()) {
        flowRoute->setIcmp_type(new ICMPType(icmp_type));
    }

    if (!icmp_code.empty()) {
        flowRoute->setIcmp_code(new ICMPCode(icmp_code));
    }

}
