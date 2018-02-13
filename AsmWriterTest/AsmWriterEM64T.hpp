#pragma once

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <string>
#include <vector>

namespace AsmWriter
{
enum class EM64TRegId
{
    None = 0,
    RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP,
    R8, R9, R10, R11, R12, R13, R14, R15,
    EAX, EBX, ECX, EDX, EDI, ESI, EBP, ESP,
    AX, BX, CX, DX, DI, SI, BP, SP,
    AL, BL, CL, DL, AH, BH, CH, DH,
    XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7,
    XMM8, XMM9, XMM10, XMM11, XMM12, XMM13, XMM14, XMM15,
    YMM0, YMM1, YMM2, YMM3, YMM4, YMM5, YMM6, YMM7,
    YMM8, YMM9, YMM10, YMM11, YMM12, YMM13, YMM14, YMM15,
    ZMM0, ZMM1, ZMM2, ZMM3, ZMM4, ZMM5, ZMM6, ZMM7,
    ZMM8, ZMM9, ZMM10, ZMM11, ZMM12, ZMM13, ZMM14, ZMM15,
    ZMM16, ZMM17, ZMM18, ZMM19, ZMM20, ZMM21, ZMM22, ZMM23,
    ZMM24, ZMM25, ZMM26, ZMM27, ZMM28, ZMM29, ZMM30, ZMM31,
    CS, DS, ES, FS, GS
};
template<typename T>
class EM64TReg
{
    friend std::ostream& operator<<(std::ostream&, const EM64TReg<T>&);

    EM64TRegId m_id;
    std::string m_name;
public:
    EM64TReg(EM64TRegId id, const std::string& name)
        : m_id(id), m_name(name)
    {
    }
    EM64TReg()
        : m_id(EM64TRegId::None), m_name()
    {
    }
};
class EM64TXmmReg
{
    friend std::ostream& operator<<(std::ostream&, const EM64TXmmReg&);

    EM64TRegId m_id;
    std::string m_name;
public:
    EM64TXmmReg(EM64TRegId id, const std::string& name)
        : m_id(id), m_name(name)
    {
    }
};
class EM64TYmmReg
{
    friend std::ostream& operator<<(std::ostream&, const EM64TYmmReg&);

    EM64TRegId m_id;
    std::string m_name;
public:
    EM64TYmmReg(EM64TRegId id, const std::string& name)
        : m_id(id), m_name(name)
    {
    }
};
class EM64TZmmReg
{
    friend std::ostream& operator<<(std::ostream&, const EM64TZmmReg&);

    EM64TRegId m_id;
    std::string m_name;
public:
    EM64TZmmReg(EM64TRegId id, const std::string& name)
        : m_id(id), m_name(name)
    {
    }
};
template<typename T>
class EM64TAReg : public EM64TReg<T>
{
public:
    EM64TAReg(EM64TRegId id, const std::string& name)
        : EM64TReg<T>(id, name)
    {
    }
};
using EM64TRegQ = EM64TReg<uint64_t>;
using EM64TRegD = EM64TReg<uint32_t>;
using EM64TRegW = EM64TReg<uint16_t>;
using EM64TRegB = EM64TReg<uint8_t>;
using EM64TARegQ = EM64TAReg<uint64_t>;
using EM64TARegD = EM64TAReg<uint32_t>;
using EM64TARegW = EM64TAReg<uint16_t>;
using EM64TARegB = EM64TAReg<uint8_t>;
template<typename T>
std::ostream& operator<<(std::ostream& os, const EM64TReg<T>& reg)
{
    os << reg.m_name;
    return os;
}
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
class EM64TRMOperand
{
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
    EM64TRMOperand(uint8_t r, const EM64TReg<T>& rm)
    {
    }
    template<typename T>
    EM64TRMOperand(uint8_t r, const EM64TMem<T>& rm)
    {
    }
};
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
    EM64TOperand m_operand;
public:
    EM64TInst(const std::string& mnemonic, const EM64TRMI_MRIOperand& operand)
        : m_mnemonic(mnemonic), m_operand(operand)
    {
    }
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
    static constexpr EM64TARegQ RAX(EM64TRegId::RAX, "rax");
    static EM64TRegQ RBX, RCX, RDX, RDI, RSI, RBP, RSP;
    static EM64TRegQ R8, R9, R10, R11, R12, R13, R14, R15;

    static EM64TARegD EAX;
    static EM64TRegD EBX, ECX, EDX, EDI, ESI, EBP, ESP;

    static EM64TARegW AX;
    static EM64TRegW BX, CX, DX, DI, SI, BP, SP;

    static EM64TARegB AL;
    static EM64TRegB BL, CL, DL, AH, BH, CH, DH;

    static EM64TXmmReg XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7;
    static EM64TXmmReg XMM8, XMM9, XMM10, XMM11, XMM12, XMM13, XMM14, XMM15;

    static EM64TYmmReg YMM0, YMM1, YMM2, YMM3, YMM4, YMM5, YMM6, YMM7;
    static EM64TYmmReg YMM8, YMM9, YMM10, YMM11, YMM12, YMM13, YMM14, YMM15;

    static EM64TZmmReg ZMM0, ZMM1, ZMM2, ZMM3, ZMM4, ZMM5, ZMM6, ZMM7;
    static EM64TZmmReg ZMM8, ZMM9, ZMM10, ZMM11, ZMM12, ZMM13, ZMM14, ZMM15;
    static EM64TZmmReg ZMM16, ZMM17, ZMM18, ZMM19, ZMM20, ZMM21, ZMM22, ZMM23;
    static EM64TZmmReg ZMM24, ZMM25, ZMM26, ZMM27, ZMM28, ZMM29, ZMM30, ZMM31;
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
