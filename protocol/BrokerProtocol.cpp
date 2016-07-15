//
// Created by Markus Jungbluth on 14.06.16.
//

#include <iostream>
#include "BrokerProtocol.h"
#include "exceptions/BrokerRequestFailedException.h"

BrokerProtocol::BrokerProtocol(BrokerClient *brokerClient, BrokerReplyParser* brokerReplyParser, BrokerReplyEvaluator* brokerReplyEvaluator, BrokerSecurityModule* brokerSecurityModule) {
    this->brokerClient = brokerClient;
    this->brokerReplyParser = brokerReplyParser;
    this->brokerReplyEvaluator = brokerReplyEvaluator;
    this->brokerSecurityModule = brokerSecurityModule;
}

void BrokerProtocol::send(BrokerRequest *request) {

    //Applying the HMAC
    brokerSecurityModule->setDate(request);
    brokerSecurityModule->signRequest(request);

    //Synthesizing the request
    string requestString = request->toString();

    //Sending the request and receiving the reply
    string receivedString = this->brokerClient->sendRequest(requestString);

    //Parsing the Reply
    BrokerReply brokerReply = this->brokerReplyParser->evaluate(receivedString);

    //Checking the HMAC
    brokerSecurityModule->validateDate(&brokerReply);
    brokerSecurityModule->validateSignature(&brokerReply);

    //Evaluating the Reply
    ReplyCode* code = this->brokerReplyEvaluator->evaluate(&brokerReply);

    if (code->isFailed()) {
        cerr << "Request failed. FlowSpec could not be installed. " << "[" << code->getCode() << "]" << " [" << code->getStandardMessage() << "]" << "\n";
        cerr << code->getDetailedExplanation() << "\n\n";

        throw BrokerRequestFailedException("Request failed.");
    } else {
        cout << "FlowSpec successfully installed. [" << code->getCode() << "]" << " [" << code->getStandardMessage() << "]" << "\n";
    }


}
