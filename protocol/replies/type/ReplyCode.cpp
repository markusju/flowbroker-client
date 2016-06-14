//
// Created by Markus Jungbluth on 14.06.16.
//

#include "ReplyCode.h"

int ReplyCode::getCode() {
   return this->replyCode;
}

int ReplyCode::getFirstDigit() {
 return this->getCode() / 100;
}
