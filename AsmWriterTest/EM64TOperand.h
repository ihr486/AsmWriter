#pragma once

#include <iostream>
#include <stdint.h>
#include <stdio.h>

namespace AsmWriter
{
class EM64TOperand
{
    friend std::ostream& operator<<(std::ostream& os, const EM64TOperand& operand);
public:
    EM64TOperand() {}
    virtual ~EM64TOperand() {}

    virtual void print(char *buf, size_t max_len) const
    {
        snprintf(buf, max_len, "");
    }
};
class EM64TRMOperand : public EM64TOperand
{
    uint8_t m_rex, m_modrm, m_sib;
public:
    template<typename T>
    EM64TRMOperand(const EM64TReg<T>& r, const EM64TReg<T>& rm)
    {
    }
    template<typename T>
    EM64TRMOperand(const EM64TReg<T>& r, const EM64TMem<T>& rm)
    {
    }
    template<typename T>
    EM64TRMOperand(const EM64TMem<T>& rm, const EM64TReg<T>& r)
    {
    }
    template<typename T>
    EM64TRMOperand(uint8_t r, const EM64TReg<T>& rm)
    {
    }
    template<typename T>
    EM64TRMOperand(uint8_t r, const EM64TMem<T>& rm)
    {
    }
};
static std::ostream& operator<<(std::ostream& os, const EM64TOperand& operand)
{
    return os;
}
class EM64TRMIOperand
{
public:
    template<typename T>
    EM64TRMIOperand(const EM64TReg<T>& op1, const EM64TReg<T>& op2)
    {
    }
    template<typename T>
    EM64TRMIOperand(const EM64TReg<T>& op1, const EM64TMem<T>& op2)
    {
    }
    template<typename T>
    EM64TRMIOperand(const EM64TMem<T>& op1, const EM64TReg<T>& op2)
    {
    }
    template<typename T>
    EM64TRMIOperand(const EM64TReg<T>& op1, const EM64TImm<T>& op2)
    {
    }
    template<typename T>
    EM64TRMIOperand(const EM64TMem<T>& op1, const EM64TImm<T>& op2)
    {
    }
};

}