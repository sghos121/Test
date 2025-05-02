/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include <vector>
    #include <map>
    #include <cmath>
    #include <cstdlib>
    #include <sstream>
    #include "matrix.h"
    #include "utils.h"

    using namespace std;

    // External declarations
    void yyerror(const char* s);
    int yylex();
    extern FILE *yyin;

    // Symbol table
    struct Value {
        enum { NUMBER, BOOLEAN, STRING, MATRIX } type;
        union {
            double numVal;
            bool boolVal;
            string* strVal;
            Matrix* matrixVal;
        };
        Value() : type(NUMBER), numVal(0.0) {}
        Value(double n) : type(NUMBER), numVal(n) {}
        Value(bool b) : type(BOOLEAN), boolVal(b) {}
        Value(string* s) : type(STRING), strVal(s) {}
        Value(Matrix* m) : type(MATRIX), matrixVal(m) {}
        ~Value() {
            if (type == STRING) delete strVal;
            if (type == MATRIX) delete matrixVal;
        }
    };

    map<string, Value> symbolTable;

    bool isVariableDefined(const string& name) {
        return symbolTable.count(name);
    }

    string getVariableType(const string& name) {
        if (!isVariableDefined(name)) return "Undefined";
        switch (symbolTable[name].type) {
            case Value::NUMBER: return "Number";
            case Value::BOOLEAN: return "Boolean";
            case Value::STRING: return "String";
            case Value::MATRIX: return "Matrix";
            default: return "Unknown";
        }
    }

    string valueToString(const Value& val) {
        ostringstream ss;
        switch (val.type) {
            case Value::NUMBER: ss << val.numVal; break;
            case Value::BOOLEAN: ss << (val.boolVal ? "true" : "false"); break;
            case Value::STRING: ss << *val.strVal; break;
            case Value::MATRIX: ss << *val.matrixVal; break;
            default: ss << "Undefined"; break;
        }
        return ss.str();
    }

#line 139 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_TRUE = 4,                       /* TRUE  */
  YYSYMBOL_FALSE = 5,                      /* FALSE  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_THEN = 9,                       /* THEN  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_MATRIX_KEYWORD = 14,            /* MATRIX_KEYWORD  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 21,                    /* DIVIDE  */
  YYSYMBOL_ELEMENT_TIMES = 22,             /* ELEMENT_TIMES  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NEQ = 25,                       /* NEQ  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LTE = 28,                       /* LTE  */
  YYSYMBOL_GTE = 29,                       /* GTE  */
  YYSYMBOL_TERNARY_IF = 30,                /* TERNARY_IF  */
  YYSYMBOL_TERNARY_ELSE = 31,              /* TERNARY_ELSE  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 34,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 35,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 36,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 37,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_LOWEST = 40,                    /* LOWEST  */
  YYSYMBOL_TERNARY_PREC = 41,              /* TERNARY_PREC  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_UNOT = 43,                      /* UNOT  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_statementList = 46,             /* statementList  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_assignmentStmt = 49,            /* assignmentStmt  */
  YYSYMBOL_ifStmt = 50,                    /* ifStmt  */
  YYSYMBOL_forStmt = 51,                   /* forStmt  */
  YYSYMBOL_whileStmt = 52,                 /* whileStmt  */
  YYSYMBOL_printStmt = 53,                 /* printStmt  */
  YYSYMBOL_expressionList = 54,            /* expressionList  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_ternaryExpr = 56,               /* ternaryExpr  */
  YYSYMBOL_logicalOrExpr = 57,             /* logicalOrExpr  */
  YYSYMBOL_logicalAndExpr = 58,            /* logicalAndExpr  */
  YYSYMBOL_equalityExpr = 59,              /* equalityExpr  */
  YYSYMBOL_relationalExpr = 60,            /* relationalExpr  */
  YYSYMBOL_additiveExpr = 61,              /* additiveExpr  */
  YYSYMBOL_multiplicativeExpr = 62,        /* multiplicativeExpr  */
  YYSYMBOL_unaryExpr = 63,                 /* unaryExpr  */
  YYSYMBOL_primaryExpr = 64                /* primaryExpr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   114,   115,   118,   119,   120,   121,   122,
     123,   126,   129,   137,   143,   153,   163,   173,   183,   187,
     193,   196,   197,   211,   212,   224,   225,   237,   238,   262,
     288,   289,   299,   309,   319,   331,   332,   349,   368,   369,
     386,   401,   418,   419,   430,   441,   442,   443,   444,   445,
     462,   463
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "TRUE",
  "FALSE", "IDENTIFIER", "STRING", "IF", "THEN", "ELSE", "FOR", "WHILE",
  "PRINT", "MATRIX_KEYWORD", "OR", "AND", "NOT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "ELEMENT_TIMES", "ASSIGN", "EQ", "NEQ", "LT", "GT", "LTE",
  "GTE", "TERNARY_IF", "TERNARY_ELSE", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "LOWEST",
  "TERNARY_PREC", "UMINUS", "UNOT", "$accept", "program", "statementList",
  "statement", "block", "assignmentStmt", "ifStmt", "forStmt", "whileStmt",
  "printStmt", "expressionList", "expression", "ternaryExpr",
  "logicalOrExpr", "logicalAndExpr", "equalityExpr", "relationalExpr",
  "additiveExpr", "multiplicativeExpr", "unaryExpr", "primaryExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      53,   -16,   -23,     1,     7,    15,    53,    36,    53,   -62,
     -62,    14,   -62,   -62,   -62,    16,    15,    15,    37,    15,
     -62,   -62,   -62,   -62,   -62,     6,    15,    15,    15,    21,
     -62,   -62,    -7,    54,   -13,   -12,    12,    28,   -62,   -62,
      45,   -62,   -62,   -62,   -62,   -62,    38,    31,    39,    70,
     -62,   -62,    41,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,   -62,    66,
      15,    42,    43,   -62,   -62,    54,    47,   -13,   -12,   -12,
      12,    12,    12,    12,    28,    28,   -62,   -62,   -62,    42,
      46,   -62,    78,    15,    73,    37,    48,   -62,    42,    55,
     -62,   -62,    42,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
      10,     0,     6,     7,     8,     0,     0,     0,     0,     0,
      45,    46,    47,    49,    48,     0,     0,     0,     0,    17,
      18,    20,    21,    23,    25,    27,    30,    35,    38,    42,
       0,     1,     3,     5,     9,    12,     0,     0,     0,     0,
      44,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    50,    19,    24,     0,    26,    28,    29,
      31,    32,    33,    34,    36,    37,    39,    40,    41,     0,
       0,    16,     0,     0,    13,     0,     0,    22,     0,     0,
      51,    14,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,    80,    -5,   -61,   -18,   -62,   -62,   -62,   -62,
     -62,   -15,    -4,   -62,    40,    34,     5,   -35,     4,   -21,
     -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      47,    45,    46,    42,    48,    50,    51,    16,    54,    17,
      91,    57,    58,    52,    59,    60,    61,    62,    20,    21,
      22,    23,    24,    55,    80,    81,    82,    83,    94,    25,
      63,    64,    26,    18,    27,    42,    41,   101,    74,    19,
      76,   103,    49,     1,    86,    87,    88,    28,    65,    66,
      67,     1,    43,     2,    44,    90,     3,     4,     5,     1,
      53,     2,    78,    79,     3,     4,     5,    84,    85,    70,
      56,    69,    71,    72,    73,    89,     6,    99,    93,     6,
      68,    96,    92,    98,    95,   100,    40,     6,   102,    97,
      77,     0,     0,     0,    75
};

static const yytype_int8 yycheck[] =
{
      18,    16,    17,     8,    19,    26,    27,    23,    15,    32,
      71,    24,    25,    28,    26,    27,    28,    29,     3,     4,
       5,     6,     7,    30,    59,    60,    61,    62,    89,    14,
      18,    19,    17,    32,    19,    40,     0,    98,    53,    32,
      55,   102,    36,     6,    65,    66,    67,    32,    20,    21,
      22,     6,    38,     8,    38,    70,    11,    12,    13,     6,
      39,     8,    57,    58,    11,    12,    13,    63,    64,    38,
      16,    33,    33,     3,    33,     9,    34,    95,    31,    34,
      35,     3,    39,    10,    38,    37,     6,    34,    33,    93,
      56,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     8,    11,    12,    13,    34,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    23,    32,    32,    32,
       3,     4,     5,     6,     7,    14,    17,    19,    32,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      46,     0,    47,    38,    38,    55,    55,    49,    55,    36,
      63,    63,    55,    39,    15,    30,    16,    24,    25,    26,
      27,    28,    29,    18,    19,    20,    21,    22,    35,    33,
      38,    33,     3,    33,    55,    58,    55,    59,    60,    60,
      61,    61,    61,    61,    62,    62,    63,    63,    63,     9,
      55,    48,    39,    31,    48,    38,     3,    56,    10,    49,
      37,    48,    33,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    49,    50,    50,    51,    52,    53,    54,    54,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     2,
       1,     3,     3,     6,     8,     9,     5,     2,     1,     3,
       1,     1,     5,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     1,     1,     1,     1,     1,
       3,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statementList  */
#line 111 "parser.y"
                       { cout << "Parsing complete." << endl; }
#line 1256 "parser.tab.c"
    break;

  case 12: /* assignmentStmt: IDENTIFIER ASSIGN expression  */
#line 129 "parser.y"
                                             {
                string varName = *(yyvsp[-2].strVal);
                symbolTable[varName] = *(yyvsp[0].val);
                delete (yyvsp[-2].strVal);
                delete (yyvsp[0].val);
              }
#line 1267 "parser.tab.c"
    break;

  case 13: /* ifStmt: IF LPAREN expression RPAREN THEN block  */
#line 137 "parser.y"
                                               {
        if ((yyvsp[-3].val)->type == Value::BOOLEAN && (yyvsp[-3].val)->boolVal) {
            // Execute block
        }
        delete (yyvsp[-3].val);
      }
#line 1278 "parser.tab.c"
    break;

  case 14: /* ifStmt: IF LPAREN expression RPAREN THEN block ELSE block  */
#line 143 "parser.y"
                                                          {
        if ((yyvsp[-5].val)->type == Value::BOOLEAN && (yyvsp[-5].val)->boolVal) {
            // Execute then-block
        } else {
            // Execute else-block
        }
        delete (yyvsp[-5].val);
      }
#line 1291 "parser.tab.c"
    break;

  case 15: /* forStmt: FOR LPAREN assignmentStmt SEMICOLON expression SEMICOLON assignmentStmt RPAREN block  */
#line 153 "parser.y"
                                                                                              {
        if ((yyvsp[-4].val)->type == Value::BOOLEAN) {
            cout << "For loop condition evaluated to " << ((yyvsp[-4].val)->boolVal ? "true" : "false") << endl;
        } else {
            yyerror("For loop condition must be boolean");
        }
        delete (yyvsp[-4].val);
      }
#line 1304 "parser.tab.c"
    break;

  case 16: /* whileStmt: WHILE LPAREN expression RPAREN block  */
#line 163 "parser.y"
                                                {
          if ((yyvsp[-2].val)->type == Value::BOOLEAN) {
              cout << "While loop condition evaluated to " << ((yyvsp[-2].val)->boolVal ? "true" : "false") << endl;
          } else {
              yyerror("While loop condition must be boolean");
          }
          delete (yyvsp[-2].val);
        }
#line 1317 "parser.tab.c"
    break;

  case 17: /* printStmt: PRINT expressionList  */
#line 173 "parser.y"
                                {
          for (const auto& val : *(yyvsp[0].valList)) {
              cout << valueToString(*val) << " ";
              delete val;
          }
          cout << endl;
          delete (yyvsp[0].valList);
        }
#line 1330 "parser.tab.c"
    break;

  case 18: /* expressionList: expression  */
#line 183 "parser.y"
                           {
                (yyval.valList) = new vector<struct Value*>();
                (yyval.valList)->push_back((yyvsp[0].val));
              }
#line 1339 "parser.tab.c"
    break;

  case 19: /* expressionList: expressionList COMMA expression  */
#line 187 "parser.y"
                                                {
                (yyval.valList) = (yyvsp[-2].valList);
                (yyval.valList)->push_back((yyvsp[0].val));
              }
#line 1348 "parser.tab.c"
    break;

  case 20: /* expression: ternaryExpr  */
#line 193 "parser.y"
                        { (yyval.val) = (yyvsp[0].val); }
#line 1354 "parser.tab.c"
    break;

  case 21: /* ternaryExpr: logicalOrExpr  */
#line 196 "parser.y"
                           { (yyval.val) = (yyvsp[0].val); }
#line 1360 "parser.tab.c"
    break;

  case 22: /* ternaryExpr: logicalOrExpr TERNARY_IF expression TERNARY_ELSE ternaryExpr  */
#line 197 "parser.y"
                                                                          {
             if ((yyvsp[-4].val)->type == Value::BOOLEAN && (yyvsp[-4].val)->boolVal) {
                 (yyval.val) = (yyvsp[-2].val);
                 delete (yyvsp[-4].val);
                 delete (yyvsp[0].val);
             } else {
                 (yyval.val) = (yyvsp[0].val);
                 delete (yyvsp[-4].val);
                 delete (yyvsp[-2].val);
             }
           }
#line 1376 "parser.tab.c"
    break;

  case 23: /* logicalOrExpr: logicalAndExpr  */
#line 211 "parser.y"
                              { (yyval.val) = (yyvsp[0].val); }
#line 1382 "parser.tab.c"
    break;

  case 24: /* logicalOrExpr: logicalOrExpr OR logicalAndExpr  */
#line 212 "parser.y"
                                               {
               if ((yyvsp[-2].val)->type == Value::BOOLEAN && (yyvsp[0].val)->type == Value::BOOLEAN) {
                   (yyval.val) = new Value((yyvsp[-2].val)->boolVal || (yyvsp[0].val)->boolVal);
               } else {
                   yyerror("Operands of OR must be boolean");
                   (yyval.val) = new Value(false);
               }
               delete (yyvsp[-2].val);
               delete (yyvsp[0].val);
             }
#line 1397 "parser.tab.c"
    break;

  case 25: /* logicalAndExpr: equalityExpr  */
#line 224 "parser.y"
                             { (yyval.val) = (yyvsp[0].val); }
#line 1403 "parser.tab.c"
    break;

  case 26: /* logicalAndExpr: logicalAndExpr AND equalityExpr  */
#line 225 "parser.y"
                                                {
                if ((yyvsp[-2].val)->type == Value::BOOLEAN && (yyvsp[0].val)->type == Value::BOOLEAN) {
                    (yyval.val) = new Value((yyvsp[-2].val)->boolVal && (yyvsp[0].val)->boolVal);
                } else {
                    yyerror("Operands of AND must be boolean");
                    (yyval.val) = new Value(false);
                }
                delete (yyvsp[-2].val);
                delete (yyvsp[0].val);
              }
#line 1418 "parser.tab.c"
    break;

  case 27: /* equalityExpr: relationalExpr  */
#line 237 "parser.y"
                             { (yyval.val) = (yyvsp[0].val); }
#line 1424 "parser.tab.c"
    break;

  case 28: /* equalityExpr: equalityExpr EQ relationalExpr  */
#line 238 "parser.y"
                                             {
              if ((yyvsp[-2].val)->type == (yyvsp[0].val)->type) {
                  switch ((yyvsp[-2].val)->type) {
                      case Value::NUMBER:
                          (yyval.val) = new Value((yyvsp[-2].val)->numVal == (yyvsp[0].val)->numVal);
                          break;
                      case Value::BOOLEAN:
                          (yyval.val) = new Value((yyvsp[-2].val)->boolVal == (yyvsp[0].val)->boolVal);
                          break;
                      case Value::STRING:
                          (yyval.val) = new Value(*(yyvsp[-2].val)->strVal == *(yyvsp[0].val)->strVal);
                          break;
                      default:
                          yyerror("Equality not supported for this type");
                          (yyval.val) = new Value(false);
                          break;
                  }
              } else {
                  yyerror("Type mismatch in equality comparison");
                  (yyval.val) = new Value(false);
              }
              delete (yyvsp[-2].val);
              delete (yyvsp[0].val);
            }
#line 1453 "parser.tab.c"
    break;

  case 29: /* equalityExpr: equalityExpr NEQ relationalExpr  */
#line 262 "parser.y"
                                              {
              if ((yyvsp[-2].val)->type == (yyvsp[0].val)->type) {
                  switch ((yyvsp[-2].val)->type) {
                      case Value::NUMBER:
                          (yyval.val) = new Value((yyvsp[-2].val)->numVal != (yyvsp[0].val)->numVal);
                          break;
                      case Value::BOOLEAN:
                          (yyval.val) = new Value((yyvsp[-2].val)->boolVal != (yyvsp[0].val)->boolVal);
                          break;
                      case Value::STRING:
                          (yyval.val) = new Value(*(yyvsp[-2].val)->strVal != *(yyvsp[0].val)->strVal);
                          break;
                      default:
                          yyerror("Inequality not supported for this type");
                          (yyval.val) = new Value(false);
                          break;
                  }
              } else {
                  yyerror("Type mismatch in inequality comparison");
                  (yyval.val) = new Value(false);
              }
              delete (yyvsp[-2].val);
              delete (yyvsp[0].val);
            }
#line 1482 "parser.tab.c"
    break;

  case 30: /* relationalExpr: additiveExpr  */
#line 288 "parser.y"
                             { (yyval.val) = (yyvsp[0].val); }
#line 1488 "parser.tab.c"
    break;

  case 31: /* relationalExpr: relationalExpr LT additiveExpr  */
#line 289 "parser.y"
                                               {
                if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                    (yyval.val) = new Value((yyvsp[-2].val)->numVal < (yyvsp[0].val)->numVal);
                } else {
                    yyerror("Operands of < must be numbers");
                    (yyval.val) = new Value(false);
                }
                delete (yyvsp[-2].val);
                delete (yyvsp[0].val);
              }
#line 1503 "parser.tab.c"
    break;

  case 32: /* relationalExpr: relationalExpr GT additiveExpr  */
#line 299 "parser.y"
                                               {
                if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                    (yyval.val) = new Value((yyvsp[-2].val)->numVal > (yyvsp[0].val)->numVal);
                } else {
                    yyerror("Operands of > must be numbers");
                    (yyval.val) = new Value(false);
                }
                delete (yyvsp[-2].val);
                delete (yyvsp[0].val);
              }
#line 1518 "parser.tab.c"
    break;

  case 33: /* relationalExpr: relationalExpr LTE additiveExpr  */
#line 309 "parser.y"
                                                {
                if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                    (yyval.val) = new Value((yyvsp[-2].val)->numVal <= (yyvsp[0].val)->numVal);
                } else {
                    yyerror("Operands of <= must be numbers");
                    (yyval.val) = new Value(false);
                }
                delete (yyvsp[-2].val);
                delete (yyvsp[0].val);
              }
#line 1533 "parser.tab.c"
    break;

  case 34: /* relationalExpr: relationalExpr GTE additiveExpr  */
#line 319 "parser.y"
                                                {
                if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                    (yyval.val) = new Value((yyvsp[-2].val)->numVal >= (yyvsp[0].val)->numVal);
                } else {
                    yyerror("Operands of >= must be numbers");
                    (yyval.val) = new Value(false);
                }
                delete (yyvsp[-2].val);
                delete (yyvsp[0].val);
              }
#line 1548 "parser.tab.c"
    break;

  case 35: /* additiveExpr: multiplicativeExpr  */
#line 331 "parser.y"
                                 { (yyval.val) = (yyvsp[0].val); }
#line 1554 "parser.tab.c"
    break;

  case 36: /* additiveExpr: additiveExpr PLUS multiplicativeExpr  */
#line 332 "parser.y"
                                                   {
              if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                  (yyval.val) = new Value((yyvsp[-2].val)->numVal + (yyvsp[0].val)->numVal);
              } else if ((yyvsp[-2].val)->type == Value::MATRIX && (yyvsp[0].val)->type == Value::MATRIX) {
                  try {
                      (yyval.val) = new Value(new Matrix(*(yyvsp[-2].val)->matrixVal + *(yyvsp[0].val)->matrixVal));
                  } catch (const exception& e) {
                      yyerror(("Matrix addition error: " + string(e.what())).c_str());
                      (yyval.val) = new Value(0.0);
                  }
              } else {
                  yyerror("Operands of + must be numbers or matrices");
                  (yyval.val) = new Value(0.0);
              }
              delete (yyvsp[-2].val);
              delete (yyvsp[0].val);
            }
#line 1576 "parser.tab.c"
    break;

  case 37: /* additiveExpr: additiveExpr MINUS multiplicativeExpr  */
#line 349 "parser.y"
                                                    {
              if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                  (yyval.val) = new Value((yyvsp[-2].val)->numVal - (yyvsp[0].val)->numVal);
              } else if ((yyvsp[-2].val)->type == Value::MATRIX && (yyvsp[0].val)->type == Value::MATRIX) {
                  try {
                      (yyval.val) = new Value(new Matrix(*(yyvsp[-2].val)->matrixVal - *(yyvsp[0].val)->matrixVal));
                  } catch (const exception& e) {
                      yyerror(("Matrix subtraction error: " + string(e.what())).c_str());
                      (yyval.val) = new Value(0.0);
                  }
              } else {
                  yyerror("Operands of - must be numbers or matrices");
                  (yyval.val) = new Value(0.0);
              }
              delete (yyvsp[-2].val);
              delete (yyvsp[0].val);
            }
#line 1598 "parser.tab.c"
    break;

  case 38: /* multiplicativeExpr: unaryExpr  */
#line 368 "parser.y"
                              { (yyval.val) = (yyvsp[0].val); }
#line 1604 "parser.tab.c"
    break;

  case 39: /* multiplicativeExpr: multiplicativeExpr TIMES unaryExpr  */
#line 369 "parser.y"
                                                       {
                    if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                        (yyval.val) = new Value((yyvsp[-2].val)->numVal * (yyvsp[0].val)->numVal);
                    } else if ((yyvsp[-2].val)->type == Value::MATRIX && (yyvsp[0].val)->type == Value::MATRIX) {
                        try {
                            (yyval.val) = new Value(new Matrix(*(yyvsp[-2].val)->matrixVal * *(yyvsp[0].val)->matrixVal));
                        } catch (const exception& e) {
                            yyerror(("Matrix multiplication error: " + string(e.what())).c_str());
                            (yyval.val) = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of * must be numbers or matrices");
                        (yyval.val) = new Value(0.0);
                    }
                    delete (yyvsp[-2].val);
                    delete (yyvsp[0].val);
                  }
#line 1626 "parser.tab.c"
    break;

  case 40: /* multiplicativeExpr: multiplicativeExpr DIVIDE unaryExpr  */
#line 386 "parser.y"
                                                        {
                    if ((yyvsp[-2].val)->type == Value::NUMBER && (yyvsp[0].val)->type == Value::NUMBER) {
                        if ((yyvsp[0].val)->numVal != 0) {
                            (yyval.val) = new Value((yyvsp[-2].val)->numVal / (yyvsp[0].val)->numVal);
                        } else {
                            yyerror("Division by zero");
                            (yyval.val) = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of / must be numbers");
                        (yyval.val) = new Value(0.0);
                    }
                    delete (yyvsp[-2].val);
                    delete (yyvsp[0].val);
                  }
#line 1646 "parser.tab.c"
    break;

  case 41: /* multiplicativeExpr: multiplicativeExpr ELEMENT_TIMES unaryExpr  */
#line 401 "parser.y"
                                                               {
                    if ((yyvsp[-2].val)->type == Value::MATRIX && (yyvsp[0].val)->type == Value::MATRIX) {
                        try {
                            (yyval.val) = new Value(new Matrix((yyvsp[-2].val)->matrixVal->elementWiseMultiply(*(yyvsp[0].val)->matrixVal)));
                        } catch (const exception& e) {
                            yyerror(("Element-wise multiplication error: " + string(e.what())).c_str());
                            (yyval.val) = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of .* must be matrices");
                        (yyval.val) = new Value(0.0);
                    }
                    delete (yyvsp[-2].val);
                    delete (yyvsp[0].val);
                  }
#line 1666 "parser.tab.c"
    break;

  case 42: /* unaryExpr: primaryExpr  */
#line 418 "parser.y"
                       { (yyval.val) = (yyvsp[0].val); }
#line 1672 "parser.tab.c"
    break;

  case 43: /* unaryExpr: MINUS unaryExpr  */
#line 419 "parser.y"
                                        {
           if ((yyvsp[0].val)->type == Value::NUMBER) {
               (yyval.val) = new Value(-(yyvsp[0].val)->numVal);
           } else if ((yyvsp[0].val)->type == Value::MATRIX) {
               (yyval.val) = new Value(new Matrix(-*(yyvsp[0].val)->matrixVal));
           } else {
               yyerror("Unary minus not supported for this type");
               (yyval.val) = new Value(0.0);
           }
           delete (yyvsp[0].val);
         }
#line 1688 "parser.tab.c"
    break;

  case 44: /* unaryExpr: NOT unaryExpr  */
#line 430 "parser.y"
                                    {
           if ((yyvsp[0].val)->type == Value::BOOLEAN) {
               (yyval.val) = new Value(!(yyvsp[0].val)->boolVal);
           } else {
               yyerror("NOT operator requires boolean operand");
               (yyval.val) = new Value(false);
           }
           delete (yyvsp[0].val);
         }
#line 1702 "parser.tab.c"
    break;

  case 45: /* primaryExpr: NUMBER  */
#line 441 "parser.y"
                    { (yyval.val) = new Value((yyvsp[0].numVal)); }
#line 1708 "parser.tab.c"
    break;

  case 46: /* primaryExpr: TRUE  */
#line 442 "parser.y"
                  { (yyval.val) = new Value(true); }
#line 1714 "parser.tab.c"
    break;

  case 47: /* primaryExpr: FALSE  */
#line 443 "parser.y"
                   { (yyval.val) = new Value(false); }
#line 1720 "parser.tab.c"
    break;

  case 48: /* primaryExpr: STRING  */
#line 444 "parser.y"
                    { (yyval.val) = new Value(new string(*(yyvsp[0].strVal))); delete (yyvsp[0].strVal); }
#line 1726 "parser.tab.c"
    break;

  case 49: /* primaryExpr: IDENTIFIER  */
#line 445 "parser.y"
                        {
             string varName = *(yyvsp[0].strVal);
             if (isVariableDefined(varName)) {
                 const Value& val = symbolTable[varName];
                 switch (val.type) {
                     case Value::NUMBER: (yyval.val) = new Value(val.numVal); break;
                     case Value::BOOLEAN: (yyval.val) = new Value(val.boolVal); break;
                     case Value::STRING: (yyval.val) = new Value(new string(*val.strVal)); break;
                     case Value::MATRIX: (yyval.val) = new Value(new Matrix(*val.matrixVal)); break;
                     default: (yyval.val) = new Value(0.0); break;
                 }
             } else {
                 yyerror(("Undefined variable: " + varName).c_str());
                 (yyval.val) = new Value(0.0);
             }
             delete (yyvsp[0].strVal);
           }
#line 1748 "parser.tab.c"
    break;

  case 50: /* primaryExpr: LPAREN expression RPAREN  */
#line 462 "parser.y"
                                      { (yyval.val) = (yyvsp[-1].val); }
#line 1754 "parser.tab.c"
    break;

  case 51: /* primaryExpr: MATRIX_KEYWORD LBRACKET NUMBER COMMA NUMBER RBRACKET  */
#line 463 "parser.y"
                                                                  {
             int rows = static_cast<int>((yyvsp[-3].numVal));
             int cols = static_cast<int>((yyvsp[-1].numVal));
             if (rows > 0 && cols > 0) {
                 (yyval.val) = new Value(new Matrix(rows, cols));
             } else {
                 yyerror("Matrix dimensions must be positive");
                 (yyval.val) = new Value(0.0);
             }
           }
#line 1769 "parser.tab.c"
    break;


#line 1773 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 475 "parser.y"


void yyerror(const char* s) {
    cerr << "Error: " << s << endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            cerr << "Cannot open file: " << argv[1] << endl;
            return 1;
        }
    }
    yyparse();
    if (yyin) fclose(yyin);
    return 0;
}
