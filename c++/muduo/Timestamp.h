#pragma once

#include <iostream>
#include <string>

class Timestamp
{
public:
    using int64 = long;
    Timestamp();
    explicit Timestamp(int64 microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString() const;

private:
    int64 microSecondsSinceEpoch_;
};