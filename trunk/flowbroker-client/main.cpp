#include <iostream>
#include "client/Client.h"
#include "flowroute/FlowRoute.h"
#include "flowroute/fields/SourceAddress.h"
#include "flowroute/fields/Protocol.h"
#include "flowroute/fields/DISCARD.h"


using namespace std;

int main() {


    try {

        FlowRoute route;


        set<string> seta = {"tcp"};
        Protocol prot(seta);

        DestinationAddress dest("134.96.43.11/24");

        SourceAddress src("8.8.8.8/32");
        DISCARD discard(&src);


        route.setDestination_address(&dest);
        route.setProtocol(&prot);
        route.setFilter_action(&discard);

        cout << route.toString() << "\n";




    } catch(exception& exc) {
        cerr << "An Error occured: " << exc.what() << "\n";
    }




    /**
    Client client;
    string host;

    client.conn("127.0.0.1", 5653);

    client.send_data("DISCARD 8.8.8.8/32\nPort: =80;>70&<100\n\n");

    cout << client.receive(1024);
    */
    return 0;
}