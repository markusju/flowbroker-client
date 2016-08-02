//
// Created by Markus Jungbluth on 14.06.16.
//

#ifndef BROKER_PROTOCOL_CLIENT_REPLYCODE_H
#define BROKER_PROTOCOL_CLIENT_REPLYCODE_H


#include <string>

using namespace std;

class ReplyCode {
public:
    /**
     * Returns whether the ReplyCode indicates that a request succeeded.
     * @return true if the servers confirms that a request succeeded
     */
    virtual bool isSuccessful() = 0;
    /**
     * Returns whether the ReplyCode indicates that a reply is informational purposes only.
     * @return true if the server neither acknowledges success nor failure of the request
     */
    virtual bool isInformational() = 0;
    /**
     * Returns whether the ReplyCode indicates that a request was not executed successfully
     * @return true if a command could not be executed
     */
    virtual bool isFailed() = 0;
    /**
     * Returns whether the ReplyCode indicates that an error was caused by the client.
     * @return true if the error was caused by the client
     */
    virtual bool isMyFault() = 0;
    /**
     * Returns an integer representation of the three digit reply code
     * @return Three-digit reply code
     */
    virtual int getCode();
    /**
     * Returns the first digit of the reply code
     * @return One digit
     */
    virtual int getFirstDigit();

    /**
     * Returns the (short) protocol message for the corresponding reply code
     * @return A string containing the message
     */
    virtual string getStandardMessage() = 0;
    /**
     * Returns a long textual explanation of the ReplyCode
     * @return A string explaining the ReplyCode
     */
    virtual string getDetailedExplanation() = 0;

protected:
    int replyCode;
};


#endif //BROKER_PROTOCOL_CLIENT_REPLYCODE_H
