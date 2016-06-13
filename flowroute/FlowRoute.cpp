//
// Created by Markus Jungbluth on 10.06.16.
//

#include "FlowRoute.h"
#include "exceptions/FlowRouteException.h"

FlowRoute::FlowRoute() {

}

string FlowRoute::toString() const {
    return this->parse();
}

string FlowRoute::parse() const {
    this->checkAction();
    this->checkMatchCriteria();

    string output;
    output.reserve(8192);

    output.append(this->filter_action->toString());
    output.append("\n");


    if (this->destination_address != NULL) {
        output.append(this->destination_address->toString());
        output.append("\n");
    }

    if (this->protocol != NULL) {
        output.append(this->protocol->toString());
        output.append("\n");
    }

    if (this->port != NULL) {
        output.append(this->protocol->toString());
        output.append("\n");
    }

    if (this->destination_port != NULL) {
        output.append(this->destination_port->toString());
        output.append("\n");
    }

    if (this->source_port != NULL) {
        output.append(this->source_port->toString());
        output.append("\n");
    }

    if (this->icmp_type != NULL) {
        output.append(this->icmp_type->toString());
        output.append("\n");
    }

    if (this->icmp_code != NULL) {
        output.append(this->icmp_code->toString());
        output.append("\n");
    }

    if (this->tcp_flags != NULL) {
        output.append(this->tcp_flags->toString());
        output.append("\n");
    }

    if (this->packet_length != NULL) {
        output.append(this->packet_length->toString());
        output.append("\n");
    }

    if (this->dscp != NULL) {
        output.append(this->dscp->toString());
        output.append("\n");
    }

    if (this->fragment != NULL) {
        output.append(this->fragment->toString());
        output.append("\n");
    }

    return output;
}

void FlowRoute::checkAction() const {
    if (this->filter_action == NULL) {
        throw FlowRouteException("Invalid or no action for FlowSpec defined!");
    }
}

void FlowRoute::checkMatchCriteria() const {

}
