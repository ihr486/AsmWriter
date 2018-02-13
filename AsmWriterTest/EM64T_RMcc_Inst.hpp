/*
 * EM64T instruction table (2): Conditional move/set/branch instructions
 * CMOVcc, SETcc, Jcc, JMP, CALL
 */

#define ASMWRITER_CMOV_RR_RM_INST(mnemonic, code8) \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TReg<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(0x0F, code8), EM64TRMOperand<T>(dst, src)); \
    } \
    template<typename T> \
    std::enable_if<!std::is_same<T, uint8_t>::value>::type mnemonic(const EM64TReg<T>& dst, const EM64TMem<T>& src) \
    { \
        emit(#mnemonic, EM64TRMOpcode<T>(0x0F, code8), EM64TRMOperand<T>(dst, src)); \
    }
#define ASMWRITER_SET_RR_RM_INST(mnemonic, code8) \
    void mnemonic(const EM64TRegB& dst) \
    { \
        emit(#mnemonic, EM64TRMOpcode<uint8_t>(0x0F, code8), EM64TRMOperand<uint8_t>(0, dst)); \
    } \
    void mnemonic(const EM64TMemB& dst) \
    { \
        emit(#mnemonic, EM64TRMOpcode<uint8_t>(0x0F, code8), EM64TRMOperand<uint8_t>(0, dst)); \
    }

ASMWRITER_CMOV_RR_RM_INST(cmova, 0x47)
ASMWRITER_CMOV_RR_RM_INST(cmovae, 0x43)
ASMWRITER_CMOV_RR_RM_INST(cmovb, 0x42)
ASMWRITER_CMOV_RR_RM_INST(cmovbe, 0x46)
ASMWRITER_CMOV_RR_RM_INST(cmovc, 0x42)
ASMWRITER_CMOV_RR_RM_INST(cmove, 0x44)
ASMWRITER_CMOV_RR_RM_INST(cmovg, 0x4F)
ASMWRITER_CMOV_RR_RM_INST(cmovge, 0x4D)
ASMWRITER_CMOV_RR_RM_INST(cmovl, 0x4C)
ASMWRITER_CMOV_RR_RM_INST(cmovle, 0x4E)
ASMWRITER_CMOV_RR_RM_INST(cmovna, 0x46)
ASMWRITER_CMOV_RR_RM_INST(cmovnae, 0x42)
ASMWRITER_CMOV_RR_RM_INST(cmovnb, 0x43)
ASMWRITER_CMOV_RR_RM_INST(cmovnbe, 0x47)
ASMWRITER_CMOV_RR_RM_INST(cmovnc, 0x43)
ASMWRITER_CMOV_RR_RM_INST(cmovne, 0x45)
ASMWRITER_CMOV_RR_RM_INST(cmovng, 0x4E)
ASMWRITER_CMOV_RR_RM_INST(cmovnge, 0x4C)
ASMWRITER_CMOV_RR_RM_INST(cmovnl, 0x4D)
ASMWRITER_CMOV_RR_RM_INST(cmovnle, 0x4F)
ASMWRITER_CMOV_RR_RM_INST(cmovno, 0x41)
ASMWRITER_CMOV_RR_RM_INST(cmovnp, 0x4B)
ASMWRITER_CMOV_RR_RM_INST(cmovns, 0x49)
ASMWRITER_CMOV_RR_RM_INST(cmovnz, 0x45)
ASMWRITER_CMOV_RR_RM_INST(cmovo, 0x40)
ASMWRITER_CMOV_RR_RM_INST(cmovp, 0x4A)
ASMWRITER_CMOV_RR_RM_INST(cmovpe, 0x4A)
ASMWRITER_CMOV_RR_RM_INST(cmovpo, 0x4B)
ASMWRITER_CMOV_RR_RM_INST(cmovs, 0x48)
ASMWRITER_CMOV_RR_RM_INST(cmovz, 0x44)

ASMWRITER_SET_RR_RM_INST(seta, 0x97)
ASMWRITER_SET_RR_RM_INST(setae, 0x93)
ASMWRITER_SET_RR_RM_INST(setb, 0x92)
ASMWRITER_SET_RR_RM_INST(setbe, 0x96)
ASMWRITER_SET_RR_RM_INST(setc, 0x92)
ASMWRITER_SET_RR_RM_INST(sete, 0x94)
ASMWRITER_SET_RR_RM_INST(setg, 0x9F)
ASMWRITER_SET_RR_RM_INST(setge, 0x9D)
ASMWRITER_SET_RR_RM_INST(setl, 0x9C)
ASMWRITER_SET_RR_RM_INST(setle, 0x9E)
ASMWRITER_SET_RR_RM_INST(setna, 0x96)
ASMWRITER_SET_RR_RM_INST(setnae, 0x92)
ASMWRITER_SET_RR_RM_INST(setnb, 0x93)
ASMWRITER_SET_RR_RM_INST(setnbe, 0x97)
ASMWRITER_SET_RR_RM_INST(setnc, 0x93)
ASMWRITER_SET_RR_RM_INST(setne, 0x95)
ASMWRITER_SET_RR_RM_INST(setng, 0x9E)
ASMWRITER_SET_RR_RM_INST(setnge, 0x9C)
ASMWRITER_SET_RR_RM_INST(setnl, 0x9D)
ASMWRITER_SET_RR_RM_INST(setnle, 0x9F)
ASMWRITER_SET_RR_RM_INST(setno, 0x91)
ASMWRITER_SET_RR_RM_INST(setnp, 0x9B)
ASMWRITER_SET_RR_RM_INST(setns, 0x99)
ASMWRITER_SET_RR_RM_INST(setnz, 0x95)
ASMWRITER_SET_RR_RM_INST(seto, 0x90)
ASMWRITER_SET_RR_RM_INST(setp, 0x9A)
ASMWRITER_SET_RR_RM_INST(setpe, 0x9A)
ASMWRITER_SET_RR_RM_INST(setpo, 0x9B)
ASMWRITER_SET_RR_RM_INST(sets, 0x98)
ASMWRITER_SET_RR_RM_INST(setz, 0x94)
