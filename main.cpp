#include <iostream>
#include "client/Client.h"
#include "flowroute/FlowRoute.h"
#include "flowroute/fields/SourceAddress.h"
#include "flowroute/fields/Protocol.h"
#include "flowroute/fields/DISCARD.h"
#include "flowroute/fields/RATELIMIT.h"
#include "protocol/parser/BrokerReplyParser.h"
#include "client/BrokerClient.h"
#include "protocol/BrokerProtocol.h"
#include "cmdline/BrokerCmdInterface.h"
#include "protocol/security/MessageAuthenticationCode.h"
#include "flowroute/fields/Fragment.h"
#include "flowroute/fields/TCPFlags.h"
#include <stdlib.h>

#define PROGNAME "broker_client"
/**
 * broker_client 0.1
 *
 *
 * A reference implementation of a Flow Specification Broker Client
 *
 *
 *   broker_client is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   broker_client is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   broker_client ist Freie Software: Sie können es unter den Bedingungen
 *   der GNU General Public License, wie von der Free Software Foundation,
 *   Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
 *   veröffentlichten Version, weiterverbreiten und/oder modifizieren.
 *
 *   borker_client wird in der Hoffnung, dass es nützlich sein wird, aber
 *   OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
 *   Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
 *   Siehe die GNU General Public License für weitere Details.
 *
 *   Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
 *   Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 */

using namespace std;


int main(int argc, char** argv) {
    try {

        //Command Line Interface
        BrokerCmdInterface cmd(argc, argv);

        //Setting up the client with options obtained from CMD
        BrokerClient client(cmd.getBrokerServer(), cmd.getBrokerServerPort());

        BrokerReplyParser parser;
        BrokerReplyEvaluator evaluator;
        BrokerSecurityModule secModule(cmd.getSecret(), cmd.getTolerance());
        BrokerProtocol protocol(&client, &parser, &evaluator, &secModule);

        //Obtaining FlowRoute from CMD
        FlowRoute* route = cmd.getFlowRoute();

        BrokerRequest req = route->parseToRequest();

        protocol.send(&req);

    } catch(exception& exc) {
        cerr << PROGNAME << ": " << exc.what() << "\n";
        return 1;
    }

    return 0;
}