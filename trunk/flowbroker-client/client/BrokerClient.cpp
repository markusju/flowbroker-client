//
// Created by Markus Jungbluth on 14.06.16.
//

#include "BrokerClient.h"

BrokerClient::BrokerClient(string host, int port) {

}

BrokerReply BrokerClient::sendRequest(BrokerRequest *request) {
    this->connect();

    this->client.send_data(request->toString());
    string output = this->client.receive(2048);



    this->disconnect();

}

void BrokerClient::connect() {
    this->client.conn(this->host, this->port);
}

void BrokerClient::disconnect() {
    this->client.disconn();

}
