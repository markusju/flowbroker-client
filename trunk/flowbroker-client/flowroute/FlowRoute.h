//
// Created by Markus Jungbluth on 10.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_FLOWROUTE_H
#define BROKER_PROTOCOL_CLIENT_FLOWROUTE_H

#include <string>
#include "fields/Name.h"
#include "fields/SourceAddress.h"
#include "fields/DestinationAddress.h"
#include "fields/Protocol.h"
#include "fields/types/AbstractFlowRouteAction.h"
#include "../protocol/BrokerRequest.h"
#include "fields/Expires.h"
#include "fields/Port.h"
#include "fields/DestinationPort.h"
#include "fields/SourcePort.h"
#include "fields/PacketLength.h"
#include "fields/Fragment.h"
#include "fields/DSCP.h"
#include "fields/TCPFlags.h"
#include "fields/ICMPCode.h"
#include "fields/ICMPType.h"

using namespace std;

class FlowRoute {

private:
    /**
     * All Pointers need to be explicitly null!
     * Otherwise this may behave non-deterministic!
     */
    Name* name = NULL;
    Expires* expires = NULL;


    SourceAddress* source_address = NULL;
    DestinationAddress* destination_address = NULL;
    Protocol* protocol = NULL;

    Port* port = NULL; //TODO
    SourcePort* source_port = NULL; //TODO
    DestinationPort* destination_port = NULL; //TODO
    ICMPType* icmp_type = NULL; //TODO
    ICMPCode* icmp_code = NULL; //TODO
    TCPFlags* tcp_flags = NULL; //TODO
    PacketLength* packet_length = NULL;
    Fragment* fragment = NULL; //TODO
    DSCP* dscp = NULL; //TODO

    AbstractFlowRouteAction* filter_action = NULL;




public:

    string toString() const;

    Name *getName() const {
        return name;
    }

    void setName(Name *name) {
        FlowRoute::name = name;
    }

    SourceAddress *getSource_address() const {
        return source_address;
    }

    void setSource_address(SourceAddress *source_address) {
        FlowRoute::source_address = source_address;
    }


    DestinationAddress *getDestination_address() const {
        return destination_address;
    }

    void setDestination_address(DestinationAddress *destination_address) {
        FlowRoute::destination_address = destination_address;
    }


    Protocol *getProtocol() const {
        return protocol;
    }

    void setProtocol(Protocol *protocol) {
        FlowRoute::protocol = protocol;
    }

    AbstractFlowRouteAction *getFilter_action() const {
        return filter_action;
    }

    void setFilter_action(AbstractFlowRouteAction *filter_action) {
        this->filter_action = filter_action;
    }

    Expires *getExpires() const {
        return expires;
    }

    void setExpires(Expires *expires) {
        FlowRoute::expires = expires;
    }


    Port *getPort() const {
        return port;
    }

    void setPort(Port *port) {
        FlowRoute::port = port;
    }


    DestinationPort *getDestination_port() const {
        return destination_port;
    }

    void setDestination_port(DestinationPort *destination_port) {
        FlowRoute::destination_port = destination_port;
    }


    SourcePort *getSource_port() const {
        return source_port;
    }

    void setSource_port(SourcePort *source_port) {
        FlowRoute::source_port = source_port;
    }


    PacketLength *getPacket_length() const {
        return packet_length;
    }

    void setPacket_length(PacketLength *packet_length) {
        FlowRoute::packet_length = packet_length;
    }

    DSCP *getDscp() const {
        return dscp;
    }

    void setDscp(DSCP *dscp) {
        FlowRoute::dscp = dscp;
    }

    Fragment *getFragment() const {
        return fragment;
    }

    void setFragment(Fragment *fragment) {
        FlowRoute::fragment = fragment;
    }

    TCPFlags *getTcp_flags() const {
        return tcp_flags;
    }

    void setTcp_flags(TCPFlags *tcp_flags) {
        FlowRoute::tcp_flags = tcp_flags;
    }

    ICMPCode *getIcmp_code() const {
        return icmp_code;
    }

    void setIcmp_code(ICMPCode *icmp_code) {
        FlowRoute::icmp_code = icmp_code;
    }

    ICMPType *getIcmp_type() const {
        return icmp_type;
    }

    void setIcmp_type(ICMPType *icmp_type) {
        FlowRoute::icmp_type = icmp_type;
    }

    FlowRoute();
    BrokerRequest parseToRequest() const;


protected:

    void parsePreChecks() const;
    void parsePostChecks(BrokerRequest& request) const;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTE_H
