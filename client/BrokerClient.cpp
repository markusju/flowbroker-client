//
// Created by Markus Jungbluth on 14.06.16.
//

#include "BrokerClient.h"

BrokerClient::BrokerClient(string host, int port) {
    this->host = host;
    this->port = port;

}

string BrokerClient::sendRequest(string request) {
    this->connect();
    this->client.send_data(request);
    string output = this->client.receive(2048);
    this->disconnect();

    return output;
}

void BrokerClient::connect() {
    this->client.conn(this->host, this->port);
}

void BrokerClient::disconnect() {
    this->client.disconn();

}
