cmake_minimum_required(VERSION 3.3)
project(broker_protocol_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp client/Client.cpp client/Client.h flowroute/FlowRoute.cpp flowroute/FlowRoute.h flowroute/fields/Name.cpp flowroute/fields/Name.h flowroute/fields/AbstractAddress.cpp flowroute/fields/AbstractAddress.h flowroute/fields/SourceAddress.cpp flowroute/fields/SourceAddress.h flowroute/fields/DestinationAddress.cpp flowroute/fields/DestinationAddress.h flowroute/fields/types/AbstractFlowRouteField.cpp flowroute/fields/types/AbstractFlowRouteField.h flowroute/fields/Protocol.cpp flowroute/fields/Protocol.h flowroute/fields/types/AbstractFlowRouteAction.cpp flowroute/fields/types/AbstractFlowRouteAction.h protocol/Request.cpp protocol/Request.h protocol/Reply.cpp protocol/Reply.h flowroute/fields/DISCARD.cpp flowroute/fields/DISCARD.h flowroute/exceptions/FlowRouteException.cpp flowroute/exceptions/FlowRouteException.h flowroute/fields/RATELIMIT.cpp flowroute/fields/RATELIMIT.h)
add_executable(broker_protocol_client ${SOURCE_FILES})