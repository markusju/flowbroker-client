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

    /**
     * Returns the name of a FlowSpec
     */
    Name *getName() const {
        return name;
    }
    /**
     * Sets the name of a FlowSpec
     * @param name
     */
    void setName(Name *name) {
        FlowRoute::name = name;
    }

    /**
     * Returns the Source Address of a FlowSpec
     */
    SourceAddress *getSource_address() const {
        return source_address;
    }

    /**
     * Sets the Source Address of FlowSpec
     * @param source_address
     */
    void setSource_address(SourceAddress *source_address) {
        FlowRoute::source_address = source_address;
    }

    /**
     * Returns the Destination Address of a FlowSpec
     * @return
     */
    DestinationAddress *getDestination_address() const {
        return destination_address;
    }

    /**
     * Sets the Destination Address of a FlowSpec
     * @param destination_address
     */
    void setDestination_address(DestinationAddress *destination_address) {
        FlowRoute::destination_address = destination_address;
    }

    /**
     * Returns the Protocol of a FlowSpec
     */
    Protocol *getProtocol() const {
        return protocol;
    }

    /**
     * Sets the Protocol of a FlowSpec
     * @param protocol
     */
    void setProtocol(Protocol *protocol) {
        FlowRoute::protocol = protocol;
    }

    /**
     * Returns the FilterAction of a FlowSpec
     */
    AbstractFlowRouteAction *getFilter_action() const {
        return filter_action;
    }

    /**
     * Sets the filter action for a FlowSpec
     * @param filter_action
     */
    void setFilter_action(AbstractFlowRouteAction *filter_action) {
        this->filter_action = filter_action;
    }

    /**
     * Returns the Expiration setting of a FlowSpec
     */
    Expires *getExpires() const {
        return expires;
    }

    /**
     * Sets the Expiration setting of a FlowSpec
     * @param expires
     */
    void setExpires(Expires *expires) {
        FlowRoute::expires = expires;
    }

    /**
     * Returns the Port of a FlowSpec
     */
    Port *getPort() const {
        return port;
    }

    /**
     * Sets the port of a FlowSpec
     * @param port
     */
    void setPort(Port *port) {
        FlowRoute::port = port;
    }

    /**
     * Returns the DestinationPort of a FlowSpec
     */
    DestinationPort *getDestination_port() const {
        return destination_port;
    }

    /**
     * Sets the DestionatPort of a FlowSpec
     * @param destination_port
     */
    void setDestination_port(DestinationPort *destination_port) {
        FlowRoute::destination_port = destination_port;
    }

    /**
     * Returns the SourcePort of a FlowSpec
     */
    SourcePort *getSource_port() const {
        return source_port;
    }

    /**
     * Sets the SourcePort of a FlowSpec
     * @param source_port
     */
    void setSource_port(SourcePort *source_port) {
        FlowRoute::source_port = source_port;
    }

    /**
     * Returns the PacketLength of a FlowSpec
     */
    PacketLength *getPacket_length() const {
        return packet_length;
    }

    /**
     * Sets the PacketLength of a FlowSpec
     * @param packet_length
     */
    void setPacket_length(PacketLength *packet_length) {
        FlowRoute::packet_length = packet_length;
    }

    /**
     * Returns the DSCP of a FlowSpec
     * @return
     */
    DSCP *getDscp() const {
        return dscp;
    }

    /**
     * Sets the DSCP of a FlowSpec
     * @param dscp
     */
    void setDscp(DSCP *dscp) {
        FlowRoute::dscp = dscp;
    }

    /**
     * Returns the Fragment of a FlowSpec
     * @return
     */
    Fragment *getFragment() const {
        return fragment;
    }

    /**
     * Sets the Fragment of a FlowSpec
     * @param fragment
     */
    void setFragment(Fragment *fragment) {
        FlowRoute::fragment = fragment;
    }

    /**
     * Returns the TCPFlags of a FlowSpec
     * @return
     */
    TCPFlags *getTcp_flags() const {
        return tcp_flags;
    }

    /**
     * Sets the TCPFlags of a FlowSpec
     * @param tcp_flags
     */
    void setTcp_flags(TCPFlags *tcp_flags) {
        FlowRoute::tcp_flags = tcp_flags;
    }

    /**
     * Returns the ICMPCode of a FlowSpec
     * @return
     */
    ICMPCode *getIcmp_code() const {
        return icmp_code;
    }

    /**
     * Sets the ICMP Code of a FlowSpec
     * @param icmp_code
     */
    void setIcmp_code(ICMPCode *icmp_code) {
        FlowRoute::icmp_code = icmp_code;
    }

    /**
     * Returns the ICMPType of a FlowSpec
     */
    ICMPType *getIcmp_type() const {
        return icmp_type;
    }

    /**
     * Sets the ICMPType of a FLowSpec
     * @param icmp_type
     */
    void setIcmp_type(ICMPType *icmp_type) {
        FlowRoute::icmp_type = icmp_type;
    }

    FlowRoute();
    /**
     * Parses the defined FlowSpec to a Broker Protocol Request message
     * @return A BrokerRequest object
     */
    BrokerRequest parseToRequest() const;


protected:
    void parsePreChecks() const;
    void parsePostChecks(BrokerRequest& request) const;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTE_H
