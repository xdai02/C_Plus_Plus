#ifndef _OUT_OF_STOCK_EXCEPTION_H_
#define _OUT_OF_STOCK_EXCEPTION_H_

#include <string>
#include <exception>

class OutOfStockException : public std::exception {
    private:
    std::string msg;

    public:
    OutOfStockException(std::string msg);
    virtual const char *what() const noexcept override;
};

#endif