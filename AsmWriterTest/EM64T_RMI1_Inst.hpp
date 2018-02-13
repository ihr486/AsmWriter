/*
 * EM64T instruction table (2) : Basic/Advanced RMI (1 operand) instructions
 * DEC, DIV, IDIV, IMUL(partial), INC, MUL, NEG, NOT
 * PUSH, POP
 * PREFETCHT0, PREFETCHT1, PREFETCHT2, PREFETCHNTA, PREFETCHNTA
 */
#define ASMWRITER_RMI_RM1_INST(mnemonic, code8, coder) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(code8), EM64TRMOpcode<T>(coder, dst)); \
    } \
    template<typename T> \
    void mnemonic(const EM64TMem<T>& dst) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(code8), EM64TRMOpcode<T>(coder, dst)); \
    }
#define ASMWRITER_RMI_RM1_INSTN8(mnemonic, code8, coder) \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(code8), EM64TRMOpcode<T>(coder, dst)); \
    } \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TMem<T>& dst) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(code8), EM64TRMOpcode<T>(coder, dst)); \
    }
#define ASMWRITER_RMI_I1_INST(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TImm<T>& imm) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(code8), EM64TIOperand<T>(imm)); \
    }
#define ASMWRITER_RMI_M1_INST(mnemonic, code8, coder) \
    void mnemonic(const EM64TMem8& mem) \
    { \
        emit(#mnemonic, EM64TOpcode<uint8_t>(0x0F, code8), EM64TRMOperand<uint8_t>(coder, mem)); \
    }

ASMWRITER_RMI_RM1_INST(dec, 0xFE, 1)
ASMWRITER_RMI_RM1_INST(div, 0xF6, 6)
ASMWRITER_RMI_RM1_INST(idiv, 0xF6, 7)
ASMWRITER_RMI_RM1_INST(imul, 0xF6, 5)
ASMWRITER_RMI_RM1_INST(inc, 0xFE, 0)
ASMWRITER_RMI_RM1_INST(mul, 0xF6, 4)
ASMWRITER_RMI_RM1_INST(neg, 0xF6, 3)
ASMWRITER_RMI_RM1_INST(not, 0xF6, 2)

ASMWRITER_RMI_RM1_INSTN8(push, 0xFF, 6)
ASMWRITER_RMI_I1_INST(push, 0x6A)

ASMWRITER_RMI_RM1_INSTN8(pop, 0x8F, 0)

ASMWRITER_RMI_M1_INST(prefetcht0, 0x18, 1)
ASMWRITER_RMI_M1_INST(prefetcht1, 0x18, 2)
ASMWRITER_RMI_M1_INST(prefetcht2, 0x18, 3)
ASMWRITER_RMI_M1_INST(prefetchnta, 0x18, 0)
ASMWRITER_RMI_M1_INST(prefetchw, 0x0D, 1)
