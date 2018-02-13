#pragma once

#include <stdint.h>
#include <initializer_list>

namespace AsmWriter
{
class EM64TOpcode
{
    static constexpr int MAX_OPCODE_LEN = 4;
protected:
    int m_length;
    uint8_t m_code[MAX_OPCODE_LEN];
    void push_byte(uint8_t b)
    {
        if (m_length < MAX_OPCODE_LEN)
            m_code[m_length++] = b;
    }
public:
    EM64TOpcode(const std::initializer_list<uint8_t> list)
    {
        for (uint8_t b : list)
        {
            if (m_length == MAX_OPCODE_LEN) break;
            m_code[m_length++] = b;
        }
    }
    EM64TOpcode(uint8_t code0) : m_length(1), m_code{code0} {}
    EM64TOpcode(uint8_t code0, uint8_t code1) : m_length(2), m_code{code0, code1} {}
    EM64TOpcode(uint8_t code0, uint8_t code1, uint8_t code2) : m_length(3), m_code{code0, code1, code2} {}
    EM64TOpcode(uint8_t code0, uint8_t code1, uint8_t code2, uint8_t code3) : m_length(4), m_code{code0, code1, code2, code3} {}
};
class EM64TRMOpcode : public EM64TOpcode
{
public:
    template<typename T>
    EM64TRMOpcode(uint8_t code8)
    {
    }
};
}