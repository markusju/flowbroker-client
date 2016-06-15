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

using namespace std;

class FlowRoute {

private:
    Name* name;
    SourceAddress* source_address;
    DestinationAddress* destination_address;
    Protocol* protocol;

    AbstractFlowRouteField* port; //TODO
    AbstractFlowRouteField* source_port; //TODO
    AbstractFlowRouteField* destination_port; //TODO
    AbstractFlowRouteField* icmp_type; //TODO
    AbstractFlowRouteField* icmp_code; //TODO
    AbstractFlowRouteField* tcp_flags; //TODO
    AbstractFlowRouteField* packet_length; //TODO
    AbstractFlowRouteField* fragment; //TODO
    AbstractFlowRouteField* dscp; //TODO

    AbstractFlowRouteAction* filter_action;




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

    FlowRoute();
    BrokerRequest* parseToRequest() const;


protected:

    void parsePreChecks() const;
    void parsePostChecks(BrokerRequest* request) const;
};


#endif //BROKER_PROTOCOL_CLIENT_FLOWROUTE_H
