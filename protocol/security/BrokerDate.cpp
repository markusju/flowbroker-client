//
// Created by Markus Jungbluth on 20.06.16.
//


#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>
#include <cmath>
#include <chrono>
#include "BrokerDate.h"
#include "exceptions/DateValidationFailedErrorException.h"

void BrokerDate::checkTimeStamp(string date) {
    long start_millis = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();


    long stamp = gettime(date);

    long diff = start_millis - stamp;

    if (diff > toleranceMillis || diff < -toleranceMillis) throw DateValidationFailedErrorException(("Possible Replay Attack. Timestamps do not match! Offset." + to_string(diff)).c_str());
    return;

}

string BrokerDate::getCurrentTimeStamp() {
    long now_micros = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return puttime(now_micros);
}

long BrokerDate::gettime(string input){
    tm t = {};
    regex reg("([0-9]{4})-([0-9]{2})-([0-9]{2})T([0-9]{2})\\:([0-9]{2})\\:([0-9]{2})\\.([0-9]{3,6})Z");
    smatch m;
    if (!regex_match(input, m, reg)) throw DateValidationFailedErrorException("Invalid Date!");

    int year = stoi(m[1].str());
    int month = stoi(m[2].str());
    int day = stoi(m[3].str());
    int hour = stoi(m[4].str());
    int minute = stoi(m[5].str());
    int second = stoi(m[6].str());
    int millis = stoi(m[7].str());

    if (year < 1900) throw DateValidationFailedErrorException("Invalid Date!");
    if (month < 1 || month > 12) throw DateValidationFailedErrorException("Invalid Date!");
    if (day < 1 || day > 31) throw DateValidationFailedErrorException("Invalid Date!");
    if (hour < 0 || hour > 23) throw DateValidationFailedErrorException("Invalid Date!");


    t.tm_year = year-1900;
    t.tm_mon = month-1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;


    long stamp_millis = millis / 1000;
    time_t tt1 = mktime(&t) - timezone;
    long stamp = tt1*1000+stamp_millis;

    return stamp;
}


string BrokerDate::puttime(long stamp) {
    time_t now_secs = stamp / 1000000;
    char buffer[64];
    strftime(buffer, 64, "%Y-%m-%dT%H:%M:%S", gmtime(&now_secs));

    stringstream ss;
    stringstream ss2;
    ss2 << fixed << (stamp % 1000000) / 1000000.0;
    ss << buffer << ss2.str().erase(0,1)  << "Z";

    return ss.str();
}

BrokerDate::BrokerDate(long toleranceMillis) {
    this->toleranceMillis = toleranceMillis;
}

