#include "out_of_stock_exception.h"

OutOfStockException::OutOfStockException(std::string msg) {
    this->msg = msg;
}

const char *OutOfStockException::what() const noexcept {
    return msg.c_str();
}