/*
 * EM64T instruction table (4) : ZO instructions without implicit operands
 * CLC, CLD, CMC, LFENCE, MFENCE, NOP, PAUSE, RET, SFENCE, STC, STD
 */
#define ASMWRITER_ZO_INST(mnemonic, code8) \
    void mnemonic() \
    { \
        emit(#mnemonic, EM64TOpcode(code8)); \
    }
#define ASMWRITER_ZO_INST2(mnemonic, code8a, code8b) \
    void mnemonic() \
    { \
        emit(#mnemonic, EM64TOpcode(code8a, code8b)); \
    }
#define ASMWRITER_ZO_INST3(mnemonic, code8a, code8b) \
    void mnemonic() \
    { \
        emit(#mnemonic, EM64TOpcode(0x0F, code8a, code8b)); \
    }

ASMWRITER_ZO_INST(clc, 0xF8)
ASMWRITER_ZO_INST(cld, 0xFC)
ASMWRITER_ZO_INST(cmc, 0xF5)
ASMWRITER_ZO_INST(nop, 0x90)
ASMWRITER_ZO_INST2(pause, 0xF3, 0x90)
ASMWRITER_ZO_INST(ret, 0xC3)
ASMWRITER_ZO_INST3(sfence, 0xAE, 0xF8)
ASMWRITER_ZO_INST(stc, 0xF9)
ASMWRITER_ZO_INST(std, 0xFD)
ASMWRITER_ZO_INST3(mfence, 0xAE, 0xF0)
ASMWRITER_ZO_INST3(lfence, 0xAE, 0xE8)