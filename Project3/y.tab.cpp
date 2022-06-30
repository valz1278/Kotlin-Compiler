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
#include <fstream>
#include <stack>
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

void yyerror(string s);
extern int linenum;

int top_index = -1;
vector<SymbolTable> tableList;
void push();
bool pop();
void dump();
void addArgument(string id, int data_type);
void create(string id, identifierData data, int id_type);
void createWithTypes(string id, int data_type, int id_type); 
void createFunction(string id, int id_type); 
void createArray(string id, int type, int size);

vector<vector<identifierData>> params;
void beginParam();
void endParam();
void addParam(identifierData data);

void checkDataType(identifierData data, int type);
void checkIdentifierType(identifierData data, int type);
void checkParameters(identifierData* data);
identifierData* fetch(string id);

string className;
ofstream out;
int checkScope(string id);

int labelCount = 0;
vector<int> ifLabelCounter;
vector<int> whileLabelCounter;
vector<int> forLabelCounter;

#line 112 "y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_LE = 4,                         /* LE  */
  YYSYMBOL_GE = 5,                         /* GE  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_NE = 7,                         /* NE  */
  YYSYMBOL_ADD = 8,                        /* ADD  */
  YYSYMBOL_SUB = 9,                        /* SUB  */
  YYSYMBOL_MUL = 10,                       /* MUL  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_CLASS = 16,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_DECLARE = 18,                   /* DECLARE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_EXIT = 21,                      /* EXIT  */
  YYSYMBOL_FALSE = 22,                     /* FALSE  */
  YYSYMBOL_FLOAT = 23,                     /* FLOAT  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_FUN = 25,                       /* FUN  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_IN = 27,                        /* IN  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_LOOP = 29,                      /* LOOP  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 31,                   /* PRINTLN  */
  YYSYMBOL_RANGE = 32,                     /* RANGE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_VAL = 35,                       /* VAL  */
  YYSYMBOL_VAR = 36,                       /* VAR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_BOOL_LITERAL = 38,              /* BOOL_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 39,              /* REAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 40,            /* STRING_LITERAL  */
  YYSYMBOL_INT_LITERAL = 41,               /* INT_LITERAL  */
  YYSYMBOL_42_ = 42,                       /* '|'  */
  YYSYMBOL_43_ = 43,                       /* '&'  */
  YYSYMBOL_44_ = 44,                       /* '!'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_UNARY_MINUS = 51,               /* UNARY_MINUS  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_class_declaration = 63,         /* class_declaration  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_class_block = 65,               /* class_block  */
  YYSYMBOL_class_contents = 66,            /* class_contents  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_formal_arguments = 69,          /* formal_arguments  */
  YYSYMBOL_arguments = 70,                 /* arguments  */
  YYSYMBOL_argument = 71,                  /* argument  */
  YYSYMBOL_return_type = 72,               /* return_type  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_statements = 74,                /* statements  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_function = 76,                  /* function  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_simple_stmt = 79,               /* simple_stmt  */
  YYSYMBOL_80_4 = 80,                      /* $@4  */
  YYSYMBOL_81_5 = 81,                      /* $@5  */
  YYSYMBOL_body = 82,                      /* body  */
  YYSYMBOL_if_statement = 83,              /* if_statement  */
  YYSYMBOL_84_6 = 84,                      /* $@6  */
  YYSYMBOL_else_statement = 85,            /* else_statement  */
  YYSYMBOL_86_7 = 86,                      /* $@7  */
  YYSYMBOL_loop_stmt = 87,                 /* loop_stmt  */
  YYSYMBOL_while_loop = 88,                /* while_loop  */
  YYSYMBOL_89_8 = 89,                      /* $@8  */
  YYSYMBOL_90_9 = 90,                      /* $@9  */
  YYSYMBOL_for_loop = 91,                  /* for_loop  */
  YYSYMBOL_assign_expr = 92,               /* assign_expr  */
  YYSYMBOL_assign_var_type = 93,           /* assign_var_type  */
  YYSYMBOL_variable = 94,                  /* variable  */
  YYSYMBOL_constant = 95,                  /* constant  */
  YYSYMBOL_array = 96,                     /* array  */
  YYSYMBOL_invocation = 97,                /* invocation  */
  YYSYMBOL_98_10 = 98,                     /* $@10  */
  YYSYMBOL_comma_separated_expressions = 99, /* comma_separated_expressions  */
  YYSYMBOL_100_11 = 100,                   /* $@11  */
  YYSYMBOL_expression = 101,               /* expression  */
  YYSYMBOL_bool_expr = 102,                /* bool_expr  */
  YYSYMBOL_arithmetic_expr = 103,          /* arithmetic_expr  */
  YYSYMBOL_literal_constant = 104,         /* literal_constant  */
  YYSYMBOL_variable_type = 105             /* variable_type  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,    44,     2,     2,     2,     2,    43,     2,
      54,    55,    49,    47,    56,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      45,    58,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    42,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   123,   126,   125,   141,   143,   143,   143,
     145,   145,   147,   147,   147,   149,   151,   151,   151,   153,
     155,   155,   157,   159,   159,   161,   161,   161,   161,   163,
     164,   163,   190,   212,   213,   213,   215,   215,   217,   218,
     221,   221,   224,   223,   234,   233,   245,   252,   252,   255,
     260,   254,   274,   277,   279,   281,   286,   297,   304,   319,
     320,   323,   325,   325,   339,   339,   340,   341,   344,   345,
     362,   363,   364,   365,   366,   369,   400,   431,   462,   493,
     524,   555,   569,   583,   597,   615,   641,   667,   693,   720,
     729,   737,   746,   757,   758,   759,   760
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "LE", "GE", "EQ",
  "NE", "ADD", "SUB", "MUL", "DIV", "BOOL", "BREAK", "CHAR", "CASE",
  "CLASS", "CONTINUE", "DECLARE", "DO", "ELSE", "EXIT", "FALSE", "FLOAT",
  "FOR", "FUN", "IF", "IN", "INT", "LOOP", "PRINT", "PRINTLN", "RANGE",
  "RETURN", "STRING", "VAL", "VAR", "WHILE", "BOOL_LITERAL",
  "REAL_LITERAL", "STRING_LITERAL", "INT_LITERAL", "'|'", "'&'", "'!'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "UNARY_MINUS", "'{'", "'}'",
  "'('", "')'", "','", "':'", "'='", "'['", "']'", "$accept", "program",
  "class_declaration", "$@1", "class_block", "class_contents",
  "declarations", "declaration", "formal_arguments", "arguments",
  "argument", "return_type", "block", "statements", "statement",
  "function", "$@2", "$@3", "simple_stmt", "$@4", "$@5", "body",
  "if_statement", "$@6", "else_statement", "$@7", "loop_stmt",
  "while_loop", "$@8", "$@9", "for_loop", "assign_expr", "assign_var_type",
  "variable", "constant", "array", "invocation", "$@10",
  "comma_separated_expressions", "$@11", "expression", "bool_expr",
  "arithmetic_expr", "literal_constant", "variable_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    34,    74,    -8,  -105,  -105,  -105,    24,    81,  -105,
      75,    78,    80,    35,    81,   -25,    81,  -105,  -105,  -105,
    -105,   -22,   -22,  -105,  -105,  -105,  -105,    42,    -3,   106,
    -105,    46,  -105,   -26,    97,    61,  -105,  -105,  -105,  -105,
    -105,   -52,  -105,  -105,  -105,  -105,   106,   106,   106,  -105,
     119,  -105,  -105,  -105,  -105,   111,  -105,    96,   104,   115,
      -3,  -105,  -105,   106,   151,  -105,    65,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   113,
      -3,  -105,    97,  -105,   123,   106,     8,  -105,   -20,   -20,
     -20,   -20,   133,   151,   -20,   -20,    45,    45,  -105,  -105,
    -105,  -105,  -105,   -25,  -105,   122,    86,  -105,    49,  -105,
     128,    84,   131,   106,  -105,  -105,   106,  -105,  -105,   134,
      49,  -105,  -105,  -105,  -105,  -105,   106,   106,   106,   183,
     119,   106,   106,   119,   106,  -105,  -105,  -105,   119,    17,
     161,   118,   119,   119,   119,   132,   148,  -105,  -105,   171,
     118,   106,   160,  -105,  -105,  -105,   119,   152,   118,   139,
    -105,   118,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     3,     4,     1,     2,     0,     0,     5,
       0,     0,     0,     0,     0,    11,     9,    12,    13,    14,
      29,     0,    55,     6,     7,    10,     8,     0,     0,     0,
      59,     0,    56,    57,    18,    21,    95,    94,    93,    96,
      54,    69,    91,    90,    92,    89,     0,     0,     0,    72,
      53,    73,    74,    70,    60,     0,    58,     0,     0,    17,
       0,    30,    62,     0,    81,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    18,    20,     0,    67,     0,    68,    76,    78,
      77,    80,    83,    82,    75,    79,    87,    88,    85,    86,
      61,    19,    16,    11,    31,     0,    64,    71,    24,    63,
       0,     0,     0,     0,    34,    36,    39,    49,    26,     0,
      24,    25,    27,    28,    47,    48,    67,     0,     0,     0,
      42,     0,     0,    38,     0,    22,    23,    65,    32,     0,
       0,     0,    35,    37,    50,     0,     0,    40,    41,    46,
       0,     0,     0,    44,    43,    51,    33,     0,     0,     0,
      45,     0,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,   192,  -105,  -105,  -105,   -11,   -14,  -105,  -105,   120,
    -105,  -105,   -23,    83,  -105,  -105,  -105,  -105,  -104,  -105,
    -105,   -31,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   141,   182,  -105,  -105,  -105,  -105,  -105,    79,  -105,
     -29,  -105,  -105,  -105,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,     9,    13,    14,    15,    35,    58,
      59,    61,   147,   119,   120,    16,    27,    84,   148,   131,
     132,   149,   122,   141,   154,   158,   123,   124,   134,   150,
     125,    30,    31,    17,    18,    19,    49,    85,   105,   110,
     106,    51,    52,    53,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    25,    62,    24,   121,    26,    83,    63,     1,    36,
      11,    12,    67,    68,    69,    70,   121,    64,    65,    66,
      37,    67,    68,    69,    70,    38,   101,    75,    76,    77,
      78,    39,    29,    55,    86,    28,    29,     4,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      71,    72,   111,    73,    74,    75,    76,    77,    78,    71,
      72,   104,    73,    74,    75,    76,    77,    78,   107,    67,
      68,    69,    70,   112,     5,   113,     8,   145,    20,   114,
     115,    21,   116,    22,   130,   118,   117,   133,    23,   108,
      67,    68,    69,    70,    77,    78,    34,   118,   138,   139,
      57,   103,   142,   143,    29,   144,    10,    71,    72,    41,
      73,    74,    75,    76,    77,    78,    11,    12,    60,   155,
      87,   111,   156,    67,    68,    69,    70,   160,    71,    72,
     162,    73,    74,    75,    76,    77,    78,    67,    68,    69,
      70,   -66,   127,   128,    42,    43,    44,    45,   114,   115,
      46,   116,    79,    80,    47,    67,    68,    69,    70,    81,
      48,    71,    72,    32,    73,    74,    75,    76,    77,    78,
     103,    82,    54,   100,    56,   103,    72,   109,    73,    74,
      75,    76,    77,    78,   126,   129,   140,   135,   146,   152,
     151,   153,   157,   159,   161,     6,    73,    74,    75,    76,
      77,    78,   102,   136,    33,   137
};

static const yytype_uint8 yycheck[] =
{
      29,    15,    54,    14,   108,    16,    60,    59,    16,    12,
      35,    36,     4,     5,     6,     7,   120,    46,    47,    48,
      23,     4,     5,     6,     7,    28,    80,    47,    48,    49,
      50,    34,    58,    59,    63,    57,    58,     3,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      42,    43,     3,    45,    46,    47,    48,    49,    50,    42,
      43,    84,    45,    46,    47,    48,    49,    50,    60,     4,
       5,     6,     7,    24,     0,    26,    52,    60,     3,    30,
      31,     3,    33,     3,   113,   108,    37,   116,    53,   103,
       4,     5,     6,     7,    49,    50,    54,   120,   127,   128,
       3,    52,   131,   132,    58,   134,    25,    42,    43,     3,
      45,    46,    47,    48,    49,    50,    35,    36,    57,   150,
      55,     3,   151,     4,     5,     6,     7,   158,    42,    43,
     161,    45,    46,    47,    48,    49,    50,     4,     5,     6,
       7,    55,    58,    59,    38,    39,    40,    41,    30,    31,
      44,    33,    41,    57,    48,     4,     5,     6,     7,    55,
      54,    42,    43,    22,    45,    46,    47,    48,    49,    50,
      52,    56,    31,    60,    33,    52,    43,    55,    45,    46,
      47,    48,    49,    50,    56,    54,     3,    53,    27,    41,
      58,    20,    32,    41,    55,     3,    45,    46,    47,    48,
      49,    50,    82,   120,    22,   126
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    62,    63,     3,     0,    62,    64,    52,    65,
      25,    35,    36,    66,    67,    68,    76,    94,    95,    96,
       3,     3,     3,    53,    66,    67,    66,    77,    57,    58,
      92,    93,    92,    93,    54,    69,    12,    23,    28,    34,
     105,     3,    38,    39,    40,    41,    44,    48,    54,    97,
     101,   102,   103,   104,    92,    59,    92,     3,    70,    71,
      57,    72,    54,    59,   101,   101,   101,     4,     5,     6,
       7,    42,    43,    45,    46,    47,    48,    49,    50,    41,
      57,    55,    56,   105,    78,    98,   101,    55,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
      60,   105,    70,    52,    73,    99,   101,    60,    67,    55,
     100,     3,    24,    26,    30,    31,    33,    37,    73,    74,
      75,    79,    83,    87,    88,    91,    56,    58,    59,    54,
     101,    80,    81,   101,    89,    53,    74,    99,   101,   101,
       3,    84,   101,   101,   101,    60,    27,    73,    79,    82,
      90,    58,    41,    20,    85,    82,   101,    32,    86,    41,
      82,    55,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    64,    63,    65,    66,    66,    66,
      67,    67,    68,    68,    68,    69,    70,    70,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    75,    75,    77,
      78,    76,    79,    79,    80,    79,    81,    79,    79,    79,
      82,    82,    84,    83,    86,    85,    85,    87,    87,    89,
      90,    88,    91,    92,    93,    94,    94,    94,    94,    95,
      95,    96,    98,    97,   100,    99,    99,    99,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     3,     2,     2,     1,
       2,     0,     1,     1,     1,     3,     3,     1,     0,     3,
       2,     0,     4,     2,     0,     1,     1,     1,     1,     0,
       0,     7,     3,     6,     0,     3,     0,     3,     2,     1,
       1,     1,     0,     5,     0,     3,     0,     1,     1,     0,
       0,     5,     9,     2,     2,     2,     3,     3,     4,     3,
       4,     6,     0,     5,     0,     4,     1,     0,     3,     1,
       1,     4,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1
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
  case 4: /* $@1: %empty  */
#line 126 "parser.y"
                  { 
                    push();
                    className = *(yyvsp[0].string_value);
                    out << "class " << className << endl << "{" << endl; 
                  }
#line 1336 "y.tab.cpp"
    break;

  case 5: /* class_declaration: CLASS ID $@1 class_block  */
#line 132 "parser.y"
                  {
                    identifierData* temp = fetch("main");
                    if(temp->id_type != 3) yyerror("main is not a function");
                    // dump();
                    pop();
                    out << "}" << endl;
                  }
#line 1348 "y.tab.cpp"
    break;

  case 19: /* argument: ID ':' variable_type  */
#line 153 "parser.y"
                               { createWithTypes(*(yyvsp[-2].string_value), (yyvsp[0].data_type), 1); addArgument(*(yyvsp[-2].string_value), (yyvsp[0].data_type)); }
#line 1354 "y.tab.cpp"
    break;

  case 20: /* return_type: ':' variable_type  */
#line 155 "parser.y"
                                { tableList[top_index - 1].setReturnType((yyvsp[0].data_type)); }
#line 1360 "y.tab.cpp"
    break;

  case 21: /* return_type: %empty  */
#line 155 "parser.y"
                                                                                  { tableList[top_index - 1].setReturnType(6); }
#line 1366 "y.tab.cpp"
    break;

  case 29: /* $@2: %empty  */
#line 163 "parser.y"
                   { createFunction(*(yyvsp[0].string_value), 3); push();}
#line 1372 "y.tab.cpp"
    break;

  case 30: /* $@3: %empty  */
#line 164 "parser.y"
          { 
            if(*(yyvsp[-3].string_value) == "main") {
              out << "\tmethod public static void main(java.lang.String[])" << endl 
              << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
            }
            else {
              out << "\tmethod public static ";
              if(fetch(*(yyvsp[-3].string_value))->data_type == 6) out << "void ";
              else out << "int ";
              out << *(yyvsp[-3].string_value) << "(";
              for(int i = 0; i < fetch(*(yyvsp[-3].string_value))->value.arguments.size(); i++){
                if(i == 0) out << stringDataType(fetch(*(yyvsp[-3].string_value))->value.arguments[i].data_type);
                else out << ", " << stringDataType(fetch(*(yyvsp[-3].string_value))->value.arguments[i].data_type);
              }
              out << ")" << endl << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
            }
          }
#line 1394 "y.tab.cpp"
    break;

  case 31: /* function: FUN ID $@2 formal_arguments return_type $@3 block  */
#line 182 "parser.y"
          { 
            if(fetch(*(yyvsp[-5].string_value))->data_type == 6) out << "\t\treturn" << endl << "\t}" << endl;
            else out << "\t}" << endl;
            // dump(); 
            pop();
          }
#line 1405 "y.tab.cpp"
    break;

  case 32: /* simple_stmt: ID '=' expression  */
#line 191 "parser.y"
            {
              identifierData* temp = fetch(*(yyvsp[-2].string_value));
              if(temp->id_type != 1){
                yyerror(*(yyvsp[-2].string_value) + " isn't a variable");
              }
              if(temp->initialized){
                if((yyvsp[0].data)->data_type == temp->data_type){
                  temp->value = (yyvsp[0].data)->value;
                }
                else{
                  yyerror("Incompatible types");
                }
                temp->value = (yyvsp[0].data)->value;
              }
              else{
                temp->value = (yyvsp[0].data)->value;
                temp->initialized = true;
              } 
              if(checkScope(*(yyvsp[-2].string_value)) == -1) out << "\t\tputstatic int " << className << "." << *(yyvsp[-2].string_value) << endl;
              else if(checkScope(*(yyvsp[-2].string_value)) > -1) out << "\t\tistore " << checkScope(*(yyvsp[-2].string_value)) << endl;
            }
#line 1431 "y.tab.cpp"
    break;

  case 33: /* simple_stmt: ID '[' expression ']' '=' expression  */
#line 212 "parser.y"
                                                   { identifierData* temp = fetch(*(yyvsp[-5].string_value)); if ((yyvsp[-3].data)->value.int_value >= temp->array_size || (yyvsp[-3].data)-> value.int_value < 0) yyerror("Given index is not within range"); if (temp->value.arguments[0].data_type != (yyvsp[0].data)->data_type) yyerror("Data type doesn't match"); }
#line 1437 "y.tab.cpp"
    break;

  case 34: /* $@4: %empty  */
#line 213 "parser.y"
                    { out << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl; }
#line 1443 "y.tab.cpp"
    break;

  case 35: /* simple_stmt: PRINT $@4 expression  */
#line 214 "parser.y"
                         { out << "\t\tinvokevirtual void java.io.PrintStream.print(" << stringDataType((yyvsp[0].data)->data_type) << ")" << endl; }
#line 1449 "y.tab.cpp"
    break;

  case 36: /* $@5: %empty  */
#line 215 "parser.y"
                      { out << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl; }
#line 1455 "y.tab.cpp"
    break;

  case 37: /* simple_stmt: PRINTLN $@5 expression  */
#line 216 "parser.y"
                         { out << "\t\tinvokevirtual void java.io.PrintStream.println(" << stringDataType((yyvsp[0].data)->data_type) << ")" << endl; }
#line 1461 "y.tab.cpp"
    break;

  case 38: /* simple_stmt: RETURN expression  */
#line 217 "parser.y"
                                { out << "\t\tireturn" << endl; }
#line 1467 "y.tab.cpp"
    break;

  case 39: /* simple_stmt: RETURN  */
#line 218 "parser.y"
                     { out << "\t\treturn" << endl; }
#line 1473 "y.tab.cpp"
    break;

  case 42: /* $@6: %empty  */
#line 224 "parser.y"
                  { 
                    checkDataType(*(yyvsp[0].data), 3);
                    out << "\t\tifeq L" << labelCount << endl;
                    ifLabelCounter.push_back(labelCount++);
                    ifLabelCounter.push_back(labelCount++);
                  }
#line 1484 "y.tab.cpp"
    break;

  case 44: /* $@7: %empty  */
#line 234 "parser.y"
                  {
                    out << "\t\tgoto L" << ifLabelCounter.back() << endl;
                    out << "\tL" << ifLabelCounter[ifLabelCounter.size() - 2] << ":" << endl;
                  }
#line 1493 "y.tab.cpp"
    break;

  case 45: /* else_statement: ELSE $@7 body  */
#line 239 "parser.y"
                  {
                    out << "\tL" << ifLabelCounter.back() << ":" << endl;
                    ifLabelCounter.pop_back();
                    ifLabelCounter.pop_back();
                  }
#line 1503 "y.tab.cpp"
    break;

  case 46: /* else_statement: %empty  */
#line 245 "parser.y"
                  {
                    out << "\tL" << ifLabelCounter[ifLabelCounter.size() - 2] << ":" << endl;
                    ifLabelCounter.pop_back();
                    ifLabelCounter.pop_back();
                  }
#line 1513 "y.tab.cpp"
    break;

  case 49: /* $@8: %empty  */
#line 255 "parser.y"
            { 
              out << "\tL" << labelCount << ":" << endl;
              whileLabelCounter.push_back(labelCount++);
            }
#line 1522 "y.tab.cpp"
    break;

  case 50: /* $@9: %empty  */
#line 260 "parser.y"
            {
              checkDataType(*(yyvsp[0].data), 3);
              out << "\t\tifeq L" << labelCount << "\n";
              whileLabelCounter.push_back(labelCount++);
            }
#line 1532 "y.tab.cpp"
    break;

  case 51: /* while_loop: WHILE $@8 expression $@9 body  */
#line 266 "parser.y"
            { 
              out << "\t\tgoto L" << whileLabelCounter[whileLabelCounter.size() - 2] << endl;
              out << "\tL" << whileLabelCounter[whileLabelCounter.size() - 1] << ":" << endl;
              whileLabelCounter.pop_back();
              whileLabelCounter.pop_back();
            }
#line 1543 "y.tab.cpp"
    break;

  case 52: /* for_loop: FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' body  */
#line 274 "parser.y"
                                                               { checkIdentifierType(*fetch(*(yyvsp[-6].string_value)), 1); }
#line 1549 "y.tab.cpp"
    break;

  case 53: /* assign_expr: '=' expression  */
#line 277 "parser.y"
                            { (yyval.data) = (yyvsp[0].data);}
#line 1555 "y.tab.cpp"
    break;

  case 54: /* assign_var_type: ':' variable_type  */
#line 279 "parser.y"
                                   { (yyval.data_type) = (yyvsp[0].data_type);}
#line 1561 "y.tab.cpp"
    break;

  case 55: /* variable: VAR ID  */
#line 282 "parser.y"
        { 
          createWithTypes(*(yyvsp[0].string_value), 1, 1);
          if(top_index == 0) out << "\tfield static int " << *(yyvsp[0].string_value) << endl;
        }
#line 1570 "y.tab.cpp"
    break;

  case 56: /* variable: VAR ID assign_expr  */
#line 287 "parser.y"
        { 
          create(*(yyvsp[-1].string_value), *(yyvsp[0].data), 1);
          if(top_index == 0) {
            out << "\tfield static " << stringDataType((yyvsp[0].data)->data_type) << " " << *(yyvsp[-1].string_value) << " = ";
            if((yyvsp[0].data)->data_type == 3) out << ((yyvsp[0].data)->value.bool_value? "true" : "false");
            else out << ((yyvsp[0].data)->value.int_value);
            out << endl;
          }
          if(checkScope(*(yyvsp[-1].string_value)) > -1) out << "\t\tistore " << checkScope(*(yyvsp[-1].string_value)) << endl;
        }
#line 1585 "y.tab.cpp"
    break;

  case 57: /* variable: VAR ID assign_var_type  */
#line 298 "parser.y"
        { 
          createWithTypes(*(yyvsp[-1].string_value), (yyvsp[0].data_type), 1);
          if((yyvsp[0].data_type) == 1 || (yyvsp[0].data_type) == 3){
            if(top_index == 0) out << "\tfield static " << stringDataType((yyvsp[0].data_type)) << " " << *(yyvsp[-1].string_value) << endl;
          }
        }
#line 1596 "y.tab.cpp"
    break;

  case 58: /* variable: VAR ID assign_var_type assign_expr  */
#line 305 "parser.y"
        { 
          checkDataType(*(yyvsp[0].data), (yyvsp[-1].data_type)); 
          create(*(yyvsp[-2].string_value), *(yyvsp[0].data), 1);
          
          if(top_index == 0) {
            out << "\tfield static " << stringDataType((yyvsp[-1].data_type)) << " " << *(yyvsp[-2].string_value) << " = ";
            if((yyvsp[0].data)->data_type == 3) out << ((yyvsp[0].data)->value.bool_value? "true" : "false");
            else out << ((yyvsp[0].data)->value.int_value);
            out << endl;
          }
          if (checkScope(*(yyvsp[-2].string_value)) > -1) out << "\t\tistore " << checkScope(*(yyvsp[-2].string_value)) << endl;
        }
#line 1613 "y.tab.cpp"
    break;

  case 59: /* constant: VAL ID assign_expr  */
#line 319 "parser.y"
                             { create(*(yyvsp[-1].string_value), *(yyvsp[0].data), 2); }
#line 1619 "y.tab.cpp"
    break;

  case 60: /* constant: VAL ID assign_var_type assign_expr  */
#line 320 "parser.y"
                                             { checkDataType(*(yyvsp[0].data), (yyvsp[-1].data_type)); create(*(yyvsp[-2].string_value), *(yyvsp[0].data), 2);}
#line 1625 "y.tab.cpp"
    break;

  case 61: /* array: VAR ID assign_var_type '[' INT_LITERAL ']'  */
#line 323 "parser.y"
                                                   { createArray(*(yyvsp[-4].string_value), (yyvsp[-3].data_type), (yyvsp[-1].integer_value));}
#line 1631 "y.tab.cpp"
    break;

  case 62: /* $@10: %empty  */
#line 325 "parser.y"
                   { checkIdentifierType(*fetch(*(yyvsp[-1].string_value)), 3); beginParam(); }
#line 1637 "y.tab.cpp"
    break;

  case 63: /* invocation: ID '(' $@10 comma_separated_expressions ')'  */
#line 326 "parser.y"
          { 
            checkParameters(fetch(*(yyvsp[-4].string_value))); 
            out << "\t\tinvokestatic " << stringDataType(fetch(*(yyvsp[-4].string_value))->data_type) << " " << className << "." << *(yyvsp[-4].string_value) << "(";
            for(int i = 0; i < fetch(*(yyvsp[-4].string_value))->value.arguments.size(); i++){
              if(i == 0) out << stringDataType(fetch(*(yyvsp[-4].string_value))->value.arguments[i].data_type);
              else out << ", " << stringDataType(fetch(*(yyvsp[-4].string_value))->value.arguments[i].data_type);
            }
            out << ")" << endl;
            (yyval.data) = fetch(*(yyvsp[-4].string_value)); 
            endParam(); 
          }
#line 1653 "y.tab.cpp"
    break;

  case 64: /* $@11: %empty  */
#line 339 "parser.y"
                                         { addParam(*(yyvsp[0].data)); }
#line 1659 "y.tab.cpp"
    break;

  case 66: /* comma_separated_expressions: expression  */
#line 340 "parser.y"
                                         { addParam(*(yyvsp[0].data)); }
#line 1665 "y.tab.cpp"
    break;

  case 68: /* expression: '(' expression ')'  */
#line 344 "parser.y"
                                { (yyval.data) = (yyvsp[-1].data); }
#line 1671 "y.tab.cpp"
    break;

  case 69: /* expression: ID  */
#line 346 "parser.y"
            { 
              identifierData* data = fetch(*(yyvsp[0].string_value));
              (yyval.data) = data; 
              if( data->id_type == 2 || data->id_type == 4 ){
                if(top_index != 0){
                  if(data->data_type == 4) out << "\t\tldc \"" << data->value.string_value << "\"" << endl;
                  else if(data->data_type == 3) out << "\t\t" << (data->value.bool_value? "iconst_1" : "iconst_0") << endl;
                  else if(data->data_type == 2) out << "\t\tsipush " << data->value.int_value << endl;
                  else if(data->data_type == 1) out << "\t\tsipush " << data->value.int_value << endl;
                }
              }
              else {
                if (checkScope(*(yyvsp[0].string_value)) == -1) out << "\t\tgetstatic int " << className << "." << *(yyvsp[0].string_value) << endl;
                else if (checkScope(*(yyvsp[0].string_value)) > -1) out << "\t\tiload " << checkScope(*(yyvsp[0].string_value)) << endl;
              }           
            }
#line 1692 "y.tab.cpp"
    break;

  case 71: /* expression: ID '[' expression ']'  */
#line 363 "parser.y"
                                    { identifierData *temp = fetch(*(yyvsp[-3].string_value)); if(temp->data_type != 5) yyerror(*(yyvsp[-3].string_value) + " is not an array"); if((yyvsp[-1].data)->value.int_value >= temp->array_size || (yyvsp[-1].data)->value.int_value < 0) yyerror("Index out of range"); (yyval.data) = new identifierData(); (yyval.data)->data_type = temp->data_type;}
#line 1698 "y.tab.cpp"
    break;

  case 75: /* bool_expr: expression '<' expression  */
#line 370 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value < (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((float)(yyvsp[-2].data)->value.int_value < (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value < (float)(yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value < (yyvsp[0].data)->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tiflt" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1733 "y.tab.cpp"
    break;

  case 76: /* bool_expr: expression LE expression  */
#line 401 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value <= (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((float)(yyvsp[-2].data)->value.int_value <= (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value <= (float)(yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value <= (yyvsp[0].data)->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifle" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1768 "y.tab.cpp"
    break;

  case 77: /* bool_expr: expression EQ expression  */
#line 432 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value == (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value == (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.bool_value == (yyvsp[0].data)->value.bool_value);
            }
            else if((yyvsp[-2].data)->data_type == 4 && (yyvsp[0].data)->data_type == 4) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.string_value == (yyvsp[0].data)->value.string_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr == expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifeq" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1803 "y.tab.cpp"
    break;

  case 78: /* bool_expr: expression GE expression  */
#line 463 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value >= (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((float)(yyvsp[-2].data)->value.int_value >= (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value >= (float)(yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value >= (yyvsp[0].data)->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr >= expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifge" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1838 "y.tab.cpp"
    break;

  case 79: /* bool_expr: expression '>' expression  */
#line 494 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value > (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((float)(yyvsp[-2].data)->value.int_value > (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value > (float)(yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value > (yyvsp[0].data)->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr > expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifgt" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1873 "y.tab.cpp"
    break;

  case 80: /* bool_expr: expression NE expression  */
#line 525 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.int_value != (yyvsp[0].data)->value.int_value);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.double_value != (yyvsp[0].data)->value.double_value);
            }
            else if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.bool_value != (yyvsp[0].data)->value.bool_value);
            }
            else if((yyvsp[-2].data)->data_type == 4 && (yyvsp[0].data)->data_type == 4) {
              temp->value.bool_value = ((yyvsp[-2].data)->value.string_value != (yyvsp[0].data)->value.string_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr != expr");
            }
            (yyval.data) = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifne" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
#line 1908 "y.tab.cpp"
    break;

  case 81: /* bool_expr: '!' expression  */
#line 556 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[0].data)->data_type == 3) {
              temp->value.bool_value = !((yyvsp[0].data)->value.bool_value);
            }
            else {
              yyerror("Incompatible type for !expr");
            }
            (yyval.data) = temp;

            out << "\t\ticonst_1" << endl << "\t\tixor" << endl;
          }
#line 1926 "y.tab.cpp"
    break;

  case 82: /* bool_expr: expression '&' expression  */
#line 570 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.bool_value = (yyvsp[-2].data)->value.bool_value && (yyvsp[0].data)->value.bool_value;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            (yyval.data) = temp;

            out << "\t\tiand" << endl;
          }
#line 1944 "y.tab.cpp"
    break;

  case 83: /* bool_expr: expression '|' expression  */
#line 584 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.bool_value = (yyvsp[-2].data)->value.bool_value || (yyvsp[0].data)->value.bool_value;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            (yyval.data) = temp;
            out << "\t\tior" << endl;
          }
#line 1961 "y.tab.cpp"
    break;

  case 84: /* arithmetic_expr: '-' expression  */
#line 598 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[0].data)->data_type == 1) {
                    *temp = *(yyvsp[0].data);
                    temp->value.int_value = -1 * temp->value.int_value;
                  }
                  else if((yyvsp[0].data)->data_type == 2) {
                    *temp = *(yyvsp[0].data);
                    temp->value.double_value = -1 * temp->value.double_value;
                  }
                  else {
                    yyerror("Incompatible type for -expr");
                  }
                  (yyval.data) = temp;

                  if((yyvsp[0].data)->data_type == 1) out << "\t\tineg" << endl;
                }
#line 1983 "y.tab.cpp"
    break;

  case 85: /* arithmetic_expr: expression '*' expression  */
#line 616 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ((yyvsp[-2].data)->value.int_value * (yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)(yyvsp[-2].data)->value.int_value * (yyvsp[0].data)->value.double_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value * (double)(yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value * (yyvsp[0].data)->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr * expr");
                  }
                  (yyval.data) = temp;

                  if(temp->data_type == 1) out << "\t\timul" << endl;
                }
#line 2013 "y.tab.cpp"
    break;

  case 86: /* arithmetic_expr: expression '/' expression  */
#line 642 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ((yyvsp[-2].data)->value.int_value / (yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)(yyvsp[-2].data)->value.int_value / (yyvsp[0].data)->value.double_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value / (double)(yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value / (yyvsp[0].data)->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr / expr");
                  }
                  (yyval.data) = temp;

                  if(temp->data_type == 1) out << "\t\tidiv" << endl;
                }
#line 2043 "y.tab.cpp"
    break;

  case 87: /* arithmetic_expr: expression '+' expression  */
#line 668 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ((yyvsp[-2].data)->value.int_value + (yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)(yyvsp[-2].data)->value.int_value + (yyvsp[0].data)->value.double_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value + (double)(yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value + (yyvsp[0].data)->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr + expr");
                  }
                  (yyval.data) = temp;

                  if(temp->data_type == 1) out << "\t\tiadd" << endl;
                }
#line 2073 "y.tab.cpp"
    break;

  case 88: /* arithmetic_expr: expression '-' expression  */
#line 694 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ((yyvsp[-2].data)->value.int_value - (yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)(yyvsp[-2].data)->value.int_value - (yyvsp[0].data)->value.double_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value - (double)(yyvsp[0].data)->value.int_value);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((yyvsp[-2].data)->value.double_value - (yyvsp[0].data)->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr - expr");
                  }
                  (yyval.data) = temp;

                  if(temp->data_type == 1) out << "\t\tisub" << endl;
                }
#line 2103 "y.tab.cpp"
    break;

  case 89: /* literal_constant: INT_LITERAL  */
#line 721 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 1;
                  data->value.int_value = (yyvsp[0].integer_value);
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\tsipush " << (yyvsp[0].integer_value) << endl;
                  (yyval.data) = data;
                }
#line 2116 "y.tab.cpp"
    break;

  case 90: /* literal_constant: REAL_LITERAL  */
#line 730 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 2;
                  data->value.double_value = (yyvsp[0].double_value);
                  data->id_type = 4;
                  (yyval.data) = data;
                }
#line 2128 "y.tab.cpp"
    break;

  case 91: /* literal_constant: BOOL_LITERAL  */
#line 738 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 3;
                  data->value.bool_value = (yyvsp[0].boolean_value);
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\t" << ((yyvsp[0].boolean_value) ? "iconst_1" : "iconst_0") << endl;
                  (yyval.data) = data;
                }
#line 2141 "y.tab.cpp"
    break;

  case 92: /* literal_constant: STRING_LITERAL  */
#line 747 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 4;
                  data->value.string_value = *(yyvsp[0].string_value);
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\tldc \"" << *(yyvsp[0].string_value) << "\"" << endl;
                  (yyval.data) = data;
                }
#line 2154 "y.tab.cpp"
    break;

  case 93: /* variable_type: INT  */
#line 757 "parser.y"
                    { (yyval.data_type) = 1; }
#line 2160 "y.tab.cpp"
    break;

  case 94: /* variable_type: FLOAT  */
#line 758 "parser.y"
                      { (yyval.data_type) = 2; }
#line 2166 "y.tab.cpp"
    break;

  case 95: /* variable_type: BOOL  */
#line 759 "parser.y"
                     { (yyval.data_type) = 3; }
#line 2172 "y.tab.cpp"
    break;

  case 96: /* variable_type: STRING  */
#line 760 "parser.y"
                       { (yyval.data_type) = 4; }
#line 2178 "y.tab.cpp"
    break;


#line 2182 "y.tab.cpp"

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

#line 764 "parser.y"


void yyerror(string s) {
  cout << "Error line: " << linenum  << " (" << s  << ')' << endl;
  exit(1);
}

void checkDataType(identifierData data, int type){
  if (type != data.data_type) yyerror("Incompatible data type");
}

void checkIdentifierType(identifierData data, int type){
  if (type != data.id_type) yyerror("Incompatible identifier type");
}

void checkParameters(identifierData* data){
  if (params[params.size() - 1].size() != data->value.arguments.size()) { 
    yyerror("Parameter amount doesn't match");
  }
  for (int i = 0; i < data->value.arguments.size(); i++) {
    if (params[params.size() - 1].at(i).data_type != data->value.arguments[i].data_type) yyerror("Parameter type does not match"); 
  }
}

void create(string id, identifierData data, int id_type){
  int result = tableList[top_index].insert(id, data.data_type, id_type, data.value, true);
  if (result == -1) yyerror(id + " already exists");
}

void createWithTypes(string id, int data_type, int id_type){
  values* temp = new values();
  int result = tableList[top_index].insert(id, data_type, id_type, *temp, false);
  if (result == -1) yyerror(id + " already exists");
}

void createFunction(string id, int id_type){
  identifierData* temp = new identifierData();
  int result = tableList[top_index].insert(id, temp->data_type, id_type, temp->value, temp->initialized);
  if (result == -1) yyerror(id + " already exists");
}

void createArray(string id, int type, int size){
  int result = tableList[top_index].insert(id, type, size);
  if (result == -1) yyerror(id + " already exists");
}

identifierData* fetch(string id) {
  identifierData *result = NULL;
  for (int i = top_index; i >= 0; i--) {
    if (tableList[i].doesExist(id)) return tableList[i].lookup(id);
  }
  if (result == NULL) yyerror(id + " does not exist");
  return result;
}

void push()
{
  tableList.push_back(SymbolTable());
  top_index++;
}

bool pop()
{
  if (tableList.size() <= 0) return false;
  tableList.pop_back();
  top_index--;
  return true;
}

void dump()
{
  cout << endl << "**************************************************" << endl << endl;
  for (int i = top_index; i >= 0; i--) {
    cout << "Index: " << i << endl;
    tableList[i].dump();
  }
  cout << "**************************************************" << endl << endl;
}

void addArgument(string id, int data_type)
{
  identifierData* temp = new identifierData();
  temp->data_type = data_type;
  tableList[top_index - 1].addArgument(id, *temp);
}

void beginParam(){
  params.push_back(vector<identifierData>());
}

void endParam(){
  params.pop_back();
}

void addParam(identifierData data){
  params[params.size() - 1].push_back(data);
}

int checkScope(string id) {
  for(int i = top_index; i >= 0; i--) {
    if(tableList[i].doesExist(id)) {
      if(i == 0) return -1; /* Global variable detected */
      else return tableList[i].id_map[id].index; /* Local variable */
    }
  }
  return -2;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  string filename;
  filename = string(argv[1]);
  filename = filename.substr(0, filename.find("."));
  filename += ".jasm";
  out.open(filename);
  yyparse();
  return 0;
}
