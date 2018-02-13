/*
 * EM64T instruction table (3) : Advanced RMI (2 operand) instructions
 * XADD, CMPXCHG
 * IMUL(partial)
 * BSF/TZCNT, BSR/LZCNT, BT, BTC, BTS, BTR, POPCNT
 */
#define ASMWRITER_RMI_MR_RR_INST2(mnemonic, code8) \
    template<typename T> \
    void mnemonic(const EM64TReg<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TEMOpcode<T>(0x0F, code8), EM64TRMOperand<T>(src, dst)); \
    } \
    template<typename T> \
    void mnemonic(const EM64TMem<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(0x0F, code8), EM64TRMOperand<T>(src, dst)); \
    }
#define ASMWRITER_RMI_RR_RM_INSTN8(mnemonic, code8) \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(0x0F, code8), EM64TRMOpcode<T>(dst, src)); \
    } \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TMem<T>& src) \
    { \
        emit(#mnemonic, EM64TOpcode<T>(0x0F, code8), EM64TRMOpcode<T>(dst, src)); \
    }
#define ASMWRITER_RMI_MR_INSTN8(mnemonic, code8) \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TMem<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(0x0F, code8), EM64TRMOperand<T>(src, dst)); \
    }
#define ASMWRITER_RMI_RI_MI_INSTN8(mnemonic, code8, coder) \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TImm8& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(0x0F, code8), EM64TRMIOperand<T>(coder, dst, src)); \
    } \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TImm8& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(0x0F, code8), EM64TRMIOperand<T>(coder, dst, src)); \
    }

ASMWRITER_RMI_MR_RR_INST2(xadd, 0xC0)

ASMWRITER_RMI_MR_RR_INST2(cmpxchg, 0xB0)

ASMWRITER_RMI_RR_RM_INSTN8(bsf, 0xBC)
ASMWRITER_RMI_RR_RM_INSTN8(tzcnt, 0xBC)

ASMWRITER_RMI_RR_RM_INSTN8(bsr, 0xBD)
ASMWRITER_RMI_RR_RM_INSTN8(lzcnt, 0xBD)

ASMWRITER_RMI_RR_RM_INSTN8(imul, 0xAF)

ASMWRITER_RMI_RR_RM_INSTN8(popcnt, 0xB8)

ASMWRITER_RMI_MR_INSTN8(bt, 0xA3)
ASMWRITER_RMI_RI_MI_INSTN8(bt, 0xBA, 4)

ASMWRITER_RMI_MR_INSTN8(btc, 0xBB)
ASMWRITER_RMI_RI_MI_INSTN8(btc, 0xBA, 7)

ASMWRITER_RMI_MR_INSTN8(btr, 0xB3)
ASMWRITER_RMI_RI_MI_INSTN8(btr, 0xBA, 6)

ASMWRITER_RMI_MR_INSTN8(bts, 0xAB)
ASMWRITER_RMI_RI_MI_INSTN8(bts, 0xBA, 5)
