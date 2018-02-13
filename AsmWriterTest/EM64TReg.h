#pragma once

#include <stdint.h>
#include <iostream>

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
    uint8_t m_code;
    const char *m_name;
public:
    constexpr EM64TReg(EM64TRegId id, uint8_t code, const char *name)
        : m_id(id), m_code(code), m_name(name) {}
};
using EM64TXmmWord = uint8_t[16];
class EM64TXmmReg : private EM64TReg<EM64TXmmWord>
{
public:
    constexpr EM64TXmmReg(EM64TRegId id, uint8_t code, const char *name)
        : EM64TReg<EM64TXmmWord>(id, code, name) {}
};
using EM64TYmmWord = uint8_t[32];
class EM64TYmmReg : private EM64TReg<EM64TYmmWord>
{
public:
    constexpr EM64TYmmReg(EM64TRegId id, uint8_t code, const char *name)
        : EM64TReg<EM64TYmmWord>(id, code, name) {}
};
using EM64TZmmWord = uint8_t[64];
class EM64TZmmReg : private EM64TReg<EM64TZmmWord>
{
public:
    constexpr EM64TZmmReg(EM64TRegId id, uint8_t code, const char *name)
        : EM64TReg<EM64TZmmWord>(id, code, name) {}
};
template<typename T>
class EM64TAReg : public EM64TReg<T>
{
public:
    constexpr EM64TAReg(EM64TRegId id, uint8_t code, const char *name)
        : EM64TReg<T>(id, code, name) {}
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
    return os << reg.m_name;
}
}