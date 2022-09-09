/**
* tiny6502
*
* Copyright (c) 2022 informedcitizenry <informedcitizenry@gmail.com>
*
* Licensed under the MIT license. See LICENSE for full license information.
*
*/

#ifndef token_h
#define token_h

#include "string_view.h"
#include <ctype.h>

typedef enum token_type {
    TOKEN_EOF,
    TOKEN_DOT,
    TOKEN_DOUBLECARET,
    TOKEN_ASTERISK,
    TOKEN_SOLIDUS,
    TOKEN_PERCENT,
    TOKEN_PLUS,
    TOKEN_HYPHEN,
    TOKEN_LSHIFT,
    TOKEN_RSHIFT,
    TOKEN_ARSHIFT,
    TOKEN_LANGLE,
    TOKEN_LTE,
    TOKEN_GTE,
    TOKEN_RANGLE,
    TOKEN_SPACESHIP,
    TOKEN_DOUBLEEQUAL,
    TOKEN_BANGEQUAL,
    TOKEN_AMPERSAND,
    TOKEN_CARET,
    TOKEN_PIPE,
    TOKEN_DOUBLEAMPERSAND,
    TOKEN_DOUBLEPIPE,
    TOKEN_QUERY,
    TOKEN_EQUAL,
    TOKEN_COLON,
    TOKEN_LPAREN,
    TOKEN_LSQUARE,
    TOKEN_LCURLY,
    TOKEN_COMMA,
    TOKEN_RPAREN,
    TOKEN_RSQUARE,
    TOKEN_RCURLY,
    TOKEN_BANG,
    TOKEN_TILDE,
    TOKEN_MULTIPLUS,
    TOKEN_MULTIHYPHEN,
    TOKEN_HASH,
    TOKEN_OPTIONINPUT,
    TOKEN_OPTIONCASESENSITIVE,
    TOKEN_OPTIONFORMAT,
    TOKEN_OPTIONHELP,
    TOKEN_OPTIONLABELS,
    TOKEN_OPTIONLIST,
    TOKEN_OPTIONQUIET,
    TOKEN_OPTIONVERSION,
    TOKEN_OPTIONARG,
    TOKEN_OPTIONOUTPUT,
    TOKEN_MACROSUBSTITUTION,
    TOKEN_NUMBEREDSUBSTITUTION,
    TOKEN_NEWLINE,
    TOKEN_UNRECOGNIZED,
    TOKEN_HEXLITERAL,
    TOKEN_DECLITERAL,
    TOKEN_BINLITERAL,
    TOKEN_STRINGLITERAL,
    TOKEN_CHARLITERAL,
    TOKEN_IDENT,
    TOKEN_ANC,
    TOKEN_ANE,
    TOKEN_ARR,
    TOKEN_ASR,
    TOKEN_DCP,
    TOKEN_DOP,
    TOKEN_ISB,
    TOKEN_JAM,
    TOKEN_LAS,
    TOKEN_LAX,
    TOKEN_RLA,
    TOKEN_RRA,
    TOKEN_SAX,
    TOKEN_SHA,
    TOKEN_SHX,
    TOKEN_SHY,
    TOKEN_SLO,
    TOKEN_SRE,
    TOKEN_STP_I,
    TOKEN_TAS,
    TOKEN_TOP,
    TOKEN_S,
    TOKEN_BBR,
    TOKEN_BBS,
    TOKEN_BRA,
    TOKEN_BRL,
    TOKEN_COP,
    TOKEN_JML,
    TOKEN_JSL,
    TOKEN_MVN,
    TOKEN_MVP,
    TOKEN_PEA,
    TOKEN_PEI,
    TOKEN_PER,
    TOKEN_PHB,
    TOKEN_PHD,
    TOKEN_PHK,
    TOKEN_PHX,
    TOKEN_PHY,
    TOKEN_PLB,
    TOKEN_PLD,
    TOKEN_PLX,
    TOKEN_PLY,
    TOKEN_REP,
    TOKEN_RMB,
    TOKEN_RTL,
    TOKEN_SEP,
    TOKEN_SMB,
    TOKEN_STP,
    TOKEN_STZ,
    TOKEN_TCD,
    TOKEN_TCS,
    TOKEN_TDC,
    TOKEN_TRB,
    TOKEN_TSB,
    TOKEN_TSC,
    TOKEN_TXY,
    TOKEN_TYX,
    TOKEN_WAI,
    TOKEN_WDM,
    TOKEN_XBA,
    TOKEN_XCE,
    TOKEN_NON_RESERVED_NUM,
    TOKEN_A,
    TOKEN_X,
    TOKEN_Y,
    TOKEN_ADC,
    TOKEN_AND,
    TOKEN_ASL,
    TOKEN_BCC,
    TOKEN_BCS,
    TOKEN_BEQ,
    TOKEN_BIT,
    TOKEN_BMI,
    TOKEN_BNE,
    TOKEN_BPL,
    TOKEN_BRK,
    TOKEN_BVC,
    TOKEN_BVS,
    TOKEN_CLC,
    TOKEN_CLD,
    TOKEN_CLI,
    TOKEN_CLV,
    TOKEN_CMP,
    TOKEN_CPX,
    TOKEN_CPY,
    TOKEN_DEC,
    TOKEN_DEX,
    TOKEN_DEY,
    TOKEN_EOR,
    TOKEN_INC,
    TOKEN_INX,
    TOKEN_INY,
    TOKEN_JMP,
    TOKEN_JSR,
    TOKEN_LDA,
    TOKEN_LDX,
    TOKEN_LDY,
    TOKEN_LSR,
    TOKEN_NOP,
    TOKEN_ORA,
    TOKEN_PHA,
    TOKEN_PHP,
    TOKEN_PLA,
    TOKEN_PLP,
    TOKEN_ROL,
    TOKEN_ROR,
    TOKEN_RTI,
    TOKEN_RTS,
    TOKEN_SBC,
    TOKEN_SEC,
    TOKEN_SED,
    TOKEN_SEI,
    TOKEN_STA,
    TOKEN_STX,
    TOKEN_STY,
    TOKEN_TAX,
    TOKEN_TAY,
    TOKEN_TSX,
    TOKEN_TXA,
    TOKEN_TXS,
    TOKEN_TYA,
    TOKEN_INCLUDE,
    TOKEN_MACRO,
    TOKEN_M8,
    TOKEN_M16,
    TOKEN_MX8,
    TOKEN_MX16,
    TOKEN_X8,
    TOKEN_X16,
    TOKEN_ALIGN,
    TOKEN_BINARY,
    TOKEN_BYTE,
    TOKEN_WORD,
    TOKEN_DWORD,
    TOKEN_FILL,
    TOKEN_LONG,
    TOKEN_STRINGIFY,
    TOKEN_RELOCATE,
    TOKEN_ENDRELOCATE,
    TOKEN_DP,
    TOKEN_PRON,
    TOKEN_PROFF,
    TOKEN_STRING,
    TOKEN_CSTRING,
    TOKEN_LSTRING,
    TOKEN_NSTRING,
    TOKEN_PSTRING,
    TOKEN_MACRO_NAME,
    TOKEN_END,
    TOKEN_ENDMACRO,
    TOKEN_TYPE_NUM
} token_type;

#define TOKEN_TEXT_MAX_LEN    200

typedef struct token
{
    
    token_type type;
    string_view src;
    int src_line;
    int src_line_pos;
    const char *src_filename;
    const struct token *expanded_macro;
    const char *include_filename;
    int include_line;
    
} token;

int token_is_of_type(const token *token, const token_type *types, size_t lut_size);
size_t token_copy_text_to_buffer(const token *token, char *buffer, size_t buffer_len);

#define TOKEN_GET_TEXT(token, buffer) \
char buffer[TOKEN_TEXT_MAX_LEN]={}; token_copy_text_to_buffer(token, buffer, TOKEN_TEXT_MAX_LEN)

#endif /* token_h */