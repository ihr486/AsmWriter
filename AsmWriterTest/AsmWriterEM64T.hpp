#pragma once

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <string>
#include <vector>

#include "EM64TReg.h"

namespace AsmWriter
{
class EM64TLabel
{
    std::string m_name;
public:
    EM64TLabel()
    {
    }
    EM64TLabel(const std::string& name)
        : m_name(name)
    {
    }
};
enum class EM64TScale
{
    X1, X2, X4, X8
};
template<typename T>
class EM64TMem
{
    EM64TRegQ m_base, m_index;
    uint32_t m_disp;
    EM64TScale m_scale;
public:
    EM64TMem(const EM64TRegQ& base, uint32_t disp = 0)
        : m_base(base), m_disp(disp)
    {
    }
};
using EM64TMem8 = EM64TMem<uint8_t>;
template<typename T>
class EM64TImm
{
    friend std::ostream& operator<<(std::ostream&, const EM64TImm<T>&);
    T m_value;
public:
    EM64TImm(T imm)
        : m_value(imm)
    {
    }
};
using EM64TImm8 = EM64TImm<uint8_t>;
template<typename T>
std::ostream& operator<<(std::ostream& os, const EM64TImm<T>& imm)
{
    return os << std::hex <<  << "0x" << imm.m_value;
}
class EM64TNode
{
public:
    virtual ~EM64TNode()
    {
    }
};
class EM64TInst : public EM64TNode
{
    std::string m_mnemonic;
public:
    EM64TInst(const std::string& mnemonic)
        : m_mnemonic(mnemonic)
    {
    }
    virtual ~EM64TInst()
    {
    }
};
enum class AsmError
{
    OK
};
class EM64T
{
public:
    static constexpr EM64TARegQ RAX{ EM64TRegId::RAX, 0, "rax" };
    static constexpr EM64TRegQ RBX{ EM64TRegId::RBX, 1, "rbx" };
    static constexpr EM64TRegQ RCX{ EM64TRegId::RCX, 2, "rcx" };
    static constexpr EM64TRegQ RDX{ EM64TRegId::RDX, 3, "rdx" };
    static constexpr EM64TRegQ RDI{ EM64TRegId::RDI, 7, "rdi" };
    static constexpr EM64TRegQ RSI{ EM64TRegId::RSI, 6, "rsi" };
    static constexpr EM64TRegQ RBP{ EM64TRegId::RBP, 5, "rbp" };
    static constexpr EM64TRegQ RSP{ EM64TRegId::RSP, 4, "rsp" };

    static constexpr EM64TRegQ R8{ EM64TRegId::R8, 8, "r8" };
    static constexpr EM64TRegQ R9{ EM64TRegId::R9, 9, "r9" };
    static constexpr EM64TRegQ R10{ EM64TRegId::R10, 10, "r10" };
    static constexpr EM64TRegQ R11{ EM64TRegId::R11, 11, "r11" };
    static constexpr EM64TRegQ R12{ EM64TRegId::R12, 12, "r12" };
    static constexpr EM64TRegQ R13{ EM64TRegId::R13, 13, "r13" };
    static constexpr EM64TRegQ R14{ EM64TRegId::R14, 14, "r14" };
    static constexpr EM64TRegQ R15{ EM64TRegId::R15, 15, "r15" };

    static constexpr EM64TARegD EAX{ EM64TRegId::EAX, 0, "eax" };
    static constexpr EM64TRegD EBX{ EM64TRegId::EBX, 1, "ebx" };
    static constexpr EM64TRegD ECX{ EM64TRegId::ECX, 2, "ecx" };
    static constexpr EM64TRegD EDX{ EM64TRegId::EDX, 3, "edx" };
    static constexpr EM64TRegD EDI{ EM64TRegId::EDI, 7, "edi" };
    static constexpr EM64TRegD ESI{ EM64TRegId::ESI, 6, "esi" };
    static constexpr EM64TRegD EBP{ EM64TRegId::EBP, 5, "ebp" };
    static constexpr EM64TRegD ESP{ EM64TRegId::ESP, 4, "esp" };

    static constexpr EM64TARegW AX{ EM64TRegId::AX, 0, "ax" };
    static constexpr EM64TRegW BX{ EM64TRegId::BX, 1, "bx" };
    static constexpr EM64TRegW CX{ EM64TRegId::CX, 2, "cx" };
    static constexpr EM64TRegW DX{ EM64TRegId::DX, 3, "dx" };
    static constexpr EM64TRegW DI{ EM64TRegId::DI, 7, "di" };
    static constexpr EM64TRegW SI{ EM64TRegId::SI, 6, "si" };
    static constexpr EM64TRegW BP{ EM64TRegId::BP, 5, "bp" };
    static constexpr EM64TRegW SP{ EM64TRegId::SP, 4, "sp" };

    static constexpr EM64TARegB AL{ EM64TRegId::AL, 0, "al" };
    static constexpr EM64TRegB BL{ EM64TRegId::BL, 1, "bl" };
    static constexpr EM64TRegB CL{ EM64TRegId::CL, 2, "cl" };
    static constexpr EM64TRegB DL{ EM64TRegId::DL, 3, "dl" };
    static constexpr EM64TRegB AH{ EM64TRegId::AH, 4, "ah" };
    static constexpr EM64TRegB BH{ EM64TRegId::BH, 5, "bh" };
    static constexpr EM64TRegB CH{ EM64TRegId::CH, 6, "ch" };
    static constexpr EM64TRegB DH{ EM64TRegId::DH, 7, "dh" };

    static constexpr EM64TXmmReg XMM0{ EM64TRegId::XMM0, 0, "xmm0" };
    static constexpr EM64TXmmReg XMM1{ EM64TRegId::XMM1, 1, "xmm1" };
    static constexpr EM64TXmmReg XMM2{ EM64TRegId::XMM2, 2, "xmm2" };
    static constexpr EM64TXmmReg XMM3{ EM64TRegId::XMM3, 3, "xmm3" };
    static constexpr EM64TXmmReg XMM4{ EM64TRegId::XMM4, 4, "xmm4" };
    static constexpr EM64TXmmReg XMM5{ EM64TRegId::XMM5, 5, "xmm5" };
    static constexpr EM64TXmmReg XMM6{ EM64TRegId::XMM6, 6, "xmm6" };
    static constexpr EM64TXmmReg XMM7{ EM64TRegId::XMM7, 7, "xmm7" };
    static constexpr EM64TXmmReg XMM8{ EM64TRegId::XMM8, 8, "xmm8" };
    static constexpr EM64TXmmReg XMM9{ EM64TRegId::XMM9, 9, "xmm9" };
    static constexpr EM64TXmmReg XMM10{ EM64TRegId::XMM10, 10, "xmm10" };
    static constexpr EM64TXmmReg XMM11{ EM64TRegId::XMM11, 11, "xmm11" };
    static constexpr EM64TXmmReg XMM12{ EM64TRegId::XMM12, 12, "xmm12" };
    static constexpr EM64TXmmReg XMM13{ EM64TRegId::XMM13, 13, "xmm13" };
    static constexpr EM64TXmmReg XMM14{ EM64TRegId::XMM14, 14, "xmm14" };
    static constexpr EM64TXmmReg XMM15{ EM64TRegId::XMM15, 15, "xmm15" };

    static constexpr EM64TYmmReg YMM0{ EM64TRegId::YMM0, 0, "ymm0" };
    static constexpr EM64TYmmReg YMM1{ EM64TRegId::YMM1, 1, "ymm1" };
    static constexpr EM64TYmmReg YMM2{ EM64TRegId::YMM2, 2, "ymm2" };
    static constexpr EM64TYmmReg YMM3{ EM64TRegId::YMM3, 3, "ymm3" };
    static constexpr EM64TYmmReg YMM4{ EM64TRegId::YMM4, 4, "ymm4" };
    static constexpr EM64TYmmReg YMM5{ EM64TRegId::YMM5, 5, "ymm5" };
    static constexpr EM64TYmmReg YMM6{ EM64TRegId::YMM6, 6, "ymm6" };
    static constexpr EM64TYmmReg YMM7{ EM64TRegId::YMM7, 7, "ymm7" };
    static constexpr EM64TYmmReg YMM8{ EM64TRegId::YMM8, 8, "ymm8" };
    static constexpr EM64TYmmReg YMM9{ EM64TRegId::YMM9, 9, "ymm9" };
    static constexpr EM64TYmmReg YMM10{ EM64TRegId::YMM10, 10, "ymm10" };
    static constexpr EM64TYmmReg YMM11{ EM64TRegId::YMM11, 11, "ymm11" };
    static constexpr EM64TYmmReg YMM12{ EM64TRegId::YMM12, 12, "ymm12" };
    static constexpr EM64TYmmReg YMM13{ EM64TRegId::YMM13, 13, "ymm13" };
    static constexpr EM64TYmmReg YMM14{ EM64TRegId::YMM14, 14, "ymm14" };
    static constexpr EM64TYmmReg YMM15{ EM64TRegId::YMM15, 15, "ymm15" };

    static constexpr EM64TZmmReg ZMM0{ EM64TRegId::ZMM0, 0, "zmm0" };
    static constexpr EM64TZmmReg ZMM1{ EM64TRegId::ZMM1, 1, "zmm1" };
    static constexpr EM64TZmmReg ZMM2{ EM64TRegId::ZMM2, 2, "zmm2" };
    static constexpr EM64TZmmReg ZMM3{ EM64TRegId::ZMM3, 3, "zmm3" };
    static constexpr EM64TZmmReg ZMM4{ EM64TRegId::ZMM4, 4, "zmm4" };
    static constexpr EM64TZmmReg ZMM5{ EM64TRegId::ZMM5, 5, "zmm5" };
    static constexpr EM64TZmmReg ZMM6{ EM64TRegId::ZMM6, 6, "zmm6" };
    static constexpr EM64TZmmReg ZMM7{ EM64TRegId::ZMM7, 7, "zmm7" };
    static constexpr EM64TZmmReg ZMM8{ EM64TRegId::ZMM8, 8, "zmm8" };
    static constexpr EM64TZmmReg ZMM9{ EM64TRegId::ZMM9, 9, "zmm9" };
    static constexpr EM64TZmmReg ZMM10{ EM64TRegId::ZMM10, 10, "zmm10" };
    static constexpr EM64TZmmReg ZMM11{ EM64TRegId::ZMM11, 11, "zmm11" };
    static constexpr EM64TZmmReg ZMM12{ EM64TRegId::ZMM12, 12, "zmm12" };
    static constexpr EM64TZmmReg ZMM13{ EM64TRegId::ZMM13, 13, "zmm13" };
    static constexpr EM64TZmmReg ZMM14{ EM64TRegId::ZMM14, 14, "zmm14" };
    static constexpr EM64TZmmReg ZMM15{ EM64TRegId::ZMM15, 15, "zmm15" };
    static constexpr EM64TZmmReg ZMM16{ EM64TRegId::ZMM16, 16, "zmm16" };
    static constexpr EM64TZmmReg ZMM17{ EM64TRegId::ZMM17, 17, "zmm17" };
    static constexpr EM64TZmmReg ZMM18{ EM64TRegId::ZMM18, 18, "zmm18" };
    static constexpr EM64TZmmReg ZMM19{ EM64TRegId::ZMM19, 19, "zmm19" };
    static constexpr EM64TZmmReg ZMM20{ EM64TRegId::ZMM20, 20, "zmm20" };
    static constexpr EM64TZmmReg ZMM21{ EM64TRegId::ZMM21, 21, "zmm21" };
    static constexpr EM64TZmmReg ZMM22{ EM64TRegId::ZMM22, 22, "zmm22" };
    static constexpr EM64TZmmReg ZMM23{ EM64TRegId::ZMM23, 23, "zmm23" };
    static constexpr EM64TZmmReg ZMM24{ EM64TRegId::ZMM24, 24, "zmm24" };
    static constexpr EM64TZmmReg ZMM25{ EM64TRegId::ZMM25, 25, "zmm25" };
    static constexpr EM64TZmmReg ZMM26{ EM64TRegId::ZMM26, 26, "zmm26" };
    static constexpr EM64TZmmReg ZMM27{ EM64TRegId::ZMM27, 27, "zmm27" };
    static constexpr EM64TZmmReg ZMM28{ EM64TRegId::ZMM28, 28, "zmm28" };
    static constexpr EM64TZmmReg ZMM29{ EM64TRegId::ZMM29, 29, "zmm29" };
    static constexpr EM64TZmmReg ZMM30{ EM64TRegId::ZMM30, 30, "zmm30" };
    static constexpr EM64TZmmReg ZMM31{ EM64TRegId::ZMM31, 31, "zmm31" };
};
class EM64TWriter
{
    std::vector<EM64TNode*> m_listing;
public:
    EM64TWriter()
    {
    }
#include "EM64T_RMI2_Inst.hpp"
#include "EM64T_RMI1_Inst.hpp"
#include "EM64T_RMI2_Inst2.hpp"
#include "EM64T_RMcc_Inst.hpp"
#include "EM64T_ZO_Inst.hpp"
};
}
