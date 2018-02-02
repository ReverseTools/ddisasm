/*
 * Dl_operator.h
 *
 *  Created on: Feb 1, 2018
 *      Author: afloresmontoya
 */

#ifndef SRC_DL_OPERATOR_H_
#define SRC_DL_OPERATOR_H_

#include <string>
#include <cstdint>

enum operator_type{NONE, REG,IMMEDIATE,INDIRECT};


class Dl_operator
{
private:


public:
    operator_type type;
    std::string reg1;
    std::string reg2;
    std::string reg3;
    int64_t offset;
    int64_t multiplier;
    int64_t disp;

    Dl_operator(operator_type type=operator_type::NONE,
                std::string reg1="none",
                std::string reg2="none",
                std::string reg3="none",
                int64_t offset=0,
                int64_t multiplier=1,
                int64_t dist=0):
        type(type),
        reg1(reg1),
        reg2(reg2),
        reg3(reg3),
        offset(offset),
        multiplier(multiplier),
        disp(dist){}

    operator_type get_type() const;
    // for debugging purposes
    std::string print() const;

    std::string print_tabs(int64_t id) const;
};

struct compare_operators{
bool operator() (const Dl_operator&  op1,const Dl_operator&  op2);
};


#endif /* SRC_DL_OPERATOR_H_ */
