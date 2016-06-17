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

    AbstractFlowRouteField* port = NULL; //TODO
    AbstractFlowRouteField* source_port = NULL; //TODO
    AbstractFlowRouteField* destination_port = NULL; //TODO
    AbstractFlowRouteField* icmp_type = NULL; //TODO
    AbstractFlowRouteField* icmp_code = NULL; //TODO
    AbstractFlowRouteField* tcp_flags = NULL; //TODO
    AbstractFlowRouteField* packet_length = NULL; //TODO
    AbstractFlowRouteField* fragment = NULL; //TODO
    AbstractFlowRouteField* dscp = NULL; //TODO

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

    FlowRoute();
    BrokerRequest parseToRequest() const;


protected:

    void parsePreChecks() const;
    void parsePostChecks(BrokerRequest& request) const;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTE_H
