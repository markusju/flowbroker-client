//
// Created by Markus Jungbluth on 10.06.16.
//

#include <iostream>
#include "FlowRoute.h"
#include "exceptions/FlowRouteException.h"

FlowRoute::FlowRoute() {

}

string FlowRoute::toString() const {
    return this->parseToRequest().toString();
}




void FlowRoute::parsePreChecks() const {
    if (this->filter_action == NULL) throw FlowRouteException("Pre Check failed: No Filter Action specified.");
}


void FlowRoute::parsePostChecks(BrokerRequest& request) const {
    //FUTURE USE...
    //TODO
}

BrokerRequest FlowRoute::parseToRequest() const {
    this->parsePreChecks();

    BrokerRequest request(this->filter_action->getMethod());

    for (auto el : this->filter_action->getMethodArguments()) {
        request.addRequestArgument(el);
    }


    if (this->expires != NULL) {
        request.addParameter(
                this->expires->getKey(),
                this->expires->getValue()
        );
    }



    if (this->destination_address != NULL) {
        request.addParameter(
                this->destination_address->getKey(),
                this->destination_address->getValue()
        );
    }

    if (this->protocol != NULL) {
        request.addParameter(
                this->protocol->getKey(),
                this->protocol->getValue()
        );
    }

    if (this->port != NULL) {
        request.addParameter(
                this->port->getKey(),
                this->port->getValue()
        );
    }

    if (this->destination_port != NULL) {
        request.addParameter(
                this->destination_port->getKey(),
                this->destination_port->getValue()
        );
    }

    if (this->source_port != NULL) {
        request.addParameter(
                this->source_port->getKey(),
                this->source_port->getValue()
        );
    }

    if (this->icmp_type != NULL) {
        request.addParameter(
                this->icmp_type->getKey(),
                this->icmp_type->getValue()
        );
    }

    if (this->icmp_code != NULL) {
        request.addParameter(
                this->icmp_code->getKey(),
                this->icmp_code->getValue()
        );
    }

    if (this->tcp_flags != NULL) {
        request.addParameter(
                this->tcp_flags->getKey(),
                this->tcp_flags->getValue()
        );
    }

    if (this->packet_length != NULL) {
        request.addParameter(
                this->packet_length->getKey(),
                this->packet_length->getValue()
        );
    }

    if (this->dscp != NULL) {
        request.addParameter(
                this->dscp->getKey(),
                this->dscp->getValue()
        );
    }

    if (this->fragment != NULL) {
        request.addParameter(
                this->fragment->getKey(),
                this->fragment->getValue()
        );
    }

    this->parsePostChecks(request);
    return request;
}

