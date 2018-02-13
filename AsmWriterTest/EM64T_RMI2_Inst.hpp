/*
 * EM64T instruction table (1) : Basic RMI instructions
 * MOV(partial)
 * ADC, ADD, AND, CMP, OR, SBB, SUB, XOR, TEST, XCHG
 */
#define ASMWRITER_RMI_AI_INST(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TAreg<T>& dst, const EM64TImm<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TAIOperand<T>(src)); \
    }
#define ASMWRITER_RMI_RR_RM_INST(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMOperand<T>(dst, src)); \
    } \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TMem<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMOperand<T>(dst, src)); \
    }
#define ASMWRITER_RMI_RR2_INST(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMOperand<T>(src, dst)); \
    }
#define ASMWRITER_RMI_MR_INST(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TMem<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMOperand<T>(src, dst)); \
    }
#define ASMWRITER_RMI_RI_MI_INST(mnemonic, code8, coder) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TImm<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMIOperand<T>(coder, dst, src)); \
    } \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TImm<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMIOperand<T>(coder, dst, src)); \
    }
#define ASMWRITER_RMI_RI_MI_SXINST(mnemonic, code8, coder) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TImm8& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMIOperand<T>(coder, dst, src)); \
    } \
    template<typename T> \
    void mnemonic(const EM64TMem<T>& dst, const EM64TImm8& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(code8), EM64TRMIOperand<T>(coder, dst, src)); \
    }

ASMWRITER_RMI_AI_INST(adc, 0x14)
ASMWRITER_RMI_RR_RM_INST(adc, 0x12)
ASMWRITER_RMI_MR_INST(adc, 0x10)
ASMWRITER_RMI_RI_MI_INST(adc, 0x80, 2)
ASMWRITER_RMI_RI_MI_SXINST(adc, 0x82, 2)

ASMWRITER_RMI_AI_INST(add, 0x04)
ASMWRITER_RMI_RR_RM_INST(add, 0x02)
ASMWRITER_RMI_MR_INST(add, 0x00)
ASMWRITER_RMI_RI_MI_INST(add, 0x80, 0)
ASMWRITER_RMI_RI_MI_SXINST(add, 0x82, 0)

ASMWRITER_RMI_AI_INST(and, 0x24)
ASMWRITER_RMI_RR_RM_INST(and, 0x22)
ASMWRITER_RMI_MR_INST(and, 0x20)
ASMWRITER_RMI_RI_MI_INST(and, 0x80, 4)
ASMWRITER_RMI_RI_MI_SXINST(and, 0x82, 4)

ASMWRITER_RMI_AI_INST(cmp, 0x3C)
ASMWRITER_RMI_RR_RM_INST(cmp, 0x3A)
ASMWRITER_RMI_MR_INST(cmp, 0x38)
ASMWRITER_RMI_RI_MI_INST(cmp, 0x80, 7)
ASMWRITER_RMI_RI_MI_SXINST(cmp, 0x82, 7)

ASMWRITER_RMI_RR_RM_INST(mov, 0x8A)
ASMWRITER_RMI_MR_INST(mov, 0x88)
ASMWRITER_RMI_RI_MI_INST(mov, 0xC6, 0)

ASMWRITER_RMI_AI_INST(or, 0x0C)
ASMWRITER_RMI_RR_RM_INST(or, 0x0A)
ASMWRITER_RMI_MR_INST(or, 0x08)
ASMWRITER_RMI_RI_MI_INST(or, 0x80, 1)
ASMWRITER_RMI_RI_MI_SXINST(or, 0x82, 1)

ASMWRITER_RMI_AI_INST(sbb, 0x1C)
ASMWRITER_RMI_RR_RM_INST(sbb, 0x1A)
ASMWRITER_RMI_MR_INST(sbb, 0x18)
ASMWRITER_RMI_RI_MI_INST(sbb, 0x80, 3)
ASMWRITER_RMI_RI_MI_SXINST(sbb, 0x82, 3)

ASMWRITER_RMI_AI_INST(sub, 0x2C)
ASMWRITER_RMI_RR_RM_INST(sub, 0x2A)
ASMWRITER_RMI_MR_INST(sub, 0x28)
ASMWRITER_RMI_RI_MI_INST(sub, 0x80, 5)
ASMWRITER_RMI_RI_MI_SXINST(sub, 0x82, 5)

ASMWRITER_RMI_AI_INST(xor, 0x34)
ASMWRITER_RMI_RR_RM_INST(xor, 0x32)
ASMWRITER_RMI_MR_INST(xor, 0x30)
ASMWRITER_RMI_RI_MI_INST(xor, 0x80, 6)
ASMWRITER_RMI_RI_MI_SXINST(xor, 0x82, 6)

ASMWRITER_RMI_AI_INST(test, 0xA8)
ASMWRITER_RMI_MR_INST(test, 0x84)
ASMWRITER_RMI_RI_MI_INST(test, 0xF6, 0)
ASMWRITER_RMI_RR2_INST(test, 0x84)

ASMWRITER_RMI_RR_RM_INST(xchg, 0x86)
