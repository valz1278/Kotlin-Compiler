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
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

extern int linenum;
int top_index = -1;
vector<SymbolTable> tableList;
vector<vector<identifierData>> params;
void yyerror(string s);
void push();
bool pop();
void dump();
void beginParam();
void endParam();
void addParam(identifierData data);
void addArgument(string id, int data_type);
void create(string id, identifierData data, int id_type);
void createWithTypes(string id, int data_type, int id_type); 
void createFunction(string id, int id_type); 
void createArray(string id, int type, int size);
void checkDataType(identifierData data, int type);
void checkIdentifierType(identifierData data, int type);
void checkParameters(identifierData* data);
identifierData* fetch(string id);

#line 98 "y.tab.cpp"

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
  YYSYMBOL_simple_stmt = 78,               /* simple_stmt  */
  YYSYMBOL_conditional_stmt = 79,          /* conditional_stmt  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_else_statement = 81,            /* else_statement  */
  YYSYMBOL_loop_stmt = 82,                 /* loop_stmt  */
  YYSYMBOL_while_loop = 83,                /* while_loop  */
  YYSYMBOL_for_loop = 84,                  /* for_loop  */
  YYSYMBOL_assign_expr = 85,               /* assign_expr  */
  YYSYMBOL_assign_var_type = 86,           /* assign_var_type  */
  YYSYMBOL_variable = 87,                  /* variable  */
  YYSYMBOL_constant = 88,                  /* constant  */
  YYSYMBOL_array = 89,                     /* array  */
  YYSYMBOL_invocation = 90,                /* invocation  */
  YYSYMBOL_91_3 = 91,                      /* $@3  */
  YYSYMBOL_comma_separated_expressions = 92, /* comma_separated_expressions  */
  YYSYMBOL_93_4 = 93,                      /* $@4  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_bool_expr = 95,                 /* bool_expr  */
  YYSYMBOL_arithmetic_expr = 96,           /* arithmetic_expr  */
  YYSYMBOL_literal_constant = 97,          /* literal_constant  */
  YYSYMBOL_variable_type = 98              /* variable_type  */
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
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

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
       0,   109,   109,   109,   111,   111,   121,   123,   123,   123,
     125,   125,   127,   127,   127,   129,   131,   131,   131,   133,
     135,   136,   139,   141,   141,   143,   143,   143,   143,   145,
     145,   147,   167,   168,   169,   170,   171,   174,   174,   176,
     177,   180,   181,   184,   184,   186,   187,   190,   191,   194,
     196,   198,   199,   200,   201,   204,   205,   208,   210,   210,
     212,   212,   213,   214,   217,   218,   219,   220,   221,   222,
     223,   226,   247,   268,   289,   310,   331,   352,   364,   376,
     389,   405,   429,   453,   477,   502,   510,   518,   526,   536,
     537,   538,   539
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
  "function", "$@2", "simple_stmt", "conditional_stmt", "if_statement",
  "else_statement", "loop_stmt", "while_loop", "for_loop", "assign_expr",
  "assign_var_type", "variable", "constant", "array", "invocation", "$@3",
  "comma_separated_expressions", "$@4", "expression", "bool_expr",
  "arithmetic_expr", "literal_constant", "variable_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    29,     7,     4,   -61,   -61,   -61,   -15,    -9,   -61,
      58,    69,    77,    41,    -9,   -25,    -9,   -61,   -61,   -61,
     -61,   -22,   -22,   -61,   -61,   -61,   -61,    45,   226,    67,
     -61,    37,   -61,   -30,   101,    52,   -61,   -61,   -61,   -61,
     -61,   -50,   -61,   -61,   -61,   -61,    67,    67,    67,   -61,
     167,   -61,   -61,   -61,   -61,    71,   -61,    53,    59,    60,
     226,    66,   -61,    67,   198,   -61,    82,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    63,
     226,   -61,   101,   -61,   -25,   -61,    67,     8,   -61,    43,
      43,    43,    43,   182,   198,    43,    43,    25,    25,   -61,
     -61,   -61,   -61,   -61,   133,    64,    96,   -61,    20,    72,
      67,    67,    67,    67,    67,   -61,    80,   133,   -61,   -61,
     114,   -61,   -61,   -61,   -61,    79,    67,    67,   144,   149,
     167,   167,   167,   149,   -61,   -61,     0,   -61,    67,   167,
      17,   121,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    92,
     120,    67,   130,   167,   124,   112,     0,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     3,     4,     1,     2,     0,     0,     5,
       0,     0,     0,     0,     0,    11,     9,    12,    13,    14,
      29,     0,    51,     6,     7,    10,     8,     0,     0,     0,
      55,     0,    52,    53,    18,    21,    91,    90,    89,    92,
      50,    65,    87,    86,    88,    85,     0,     0,     0,    68,
      49,    69,    70,    66,    56,     0,    54,     0,     0,    17,
       0,     0,    58,     0,    77,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    18,    20,    11,    30,    63,     0,    64,    72,
      74,    73,    76,    79,    78,    71,    75,    83,    84,    81,
      82,    57,    19,    16,     0,     0,    60,    67,     0,     0,
       0,     0,     0,    36,     0,    26,     0,    24,    25,    27,
      37,    28,    43,    44,    59,     0,     0,     0,     0,     0,
      33,    34,    35,     0,    22,    23,     0,    38,    63,    31,
       0,     0,    40,    39,    46,    45,    42,    41,    61,     0,
       0,     0,     0,    32,     0,     0,     0,    48,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   165,   -61,   -61,   -61,    -8,   -13,   -61,   -61,    87,
     -61,   -61,   -60,    61,   -61,   -61,   -61,   -16,   -61,   -61,
     -61,   -61,   -61,   -61,   127,   153,   -61,   -61,   -61,   -61,
     -61,    38,   -61,   -29,   -61,   -61,   -61,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,     9,    13,    14,    15,    35,    58,
      59,    61,   115,   116,   117,    16,    27,   118,   119,   120,
     137,   121,   122,   123,    30,    31,    17,    18,    19,    49,
      86,   105,   125,   106,    51,    52,    53,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    85,    25,   108,    62,    83,    24,     5,    26,    63,
      11,    12,    67,    68,    69,    70,    10,    64,    65,    66,
       1,    67,    68,    69,    70,   102,    11,    12,    29,    55,
     111,   112,     4,   113,    87,    28,    29,     8,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      71,    72,    84,    73,    74,    75,    76,    77,    78,    71,
      72,    20,    73,    74,    75,    76,    77,    78,   107,   142,
      41,   104,    21,   144,    77,    78,   146,   149,   126,   127,
      22,   129,   130,   131,   132,   133,    67,    68,    69,    70,
      75,    76,    77,    78,    23,    29,   157,   139,   140,    34,
      67,    68,    69,    70,    57,    42,    43,    44,    45,    60,
      80,    46,    79,   143,    81,    47,    82,   145,    84,   124,
     147,    48,   153,   101,    71,    72,   128,    73,    74,    75,
      76,    77,    78,   134,   136,   138,   108,    88,    71,    72,
     158,    73,    74,    75,    76,    77,    78,   141,   150,    32,
     151,   -62,   108,    67,    68,    69,    70,   109,    54,   110,
      56,   152,   154,   111,   112,   155,   113,   156,     6,   103,
     114,    67,    68,    69,    70,    33,   148,     0,   135,   111,
     112,     0,   113,     0,     0,    84,    67,    68,    69,    70,
       0,    71,    72,     0,    73,    74,    75,    76,    77,    78,
       0,    84,    67,    68,    69,    70,     0,     0,     0,    71,
      72,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    37,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
      39
};

static const yytype_int16 yycheck[] =
{
      29,    61,    15,     3,    54,    60,    14,     0,    16,    59,
      35,    36,     4,     5,     6,     7,    25,    46,    47,    48,
      16,     4,     5,     6,     7,    80,    35,    36,    58,    59,
      30,    31,     3,    33,    63,    57,    58,    52,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      42,    43,    52,    45,    46,    47,    48,    49,    50,    42,
      43,     3,    45,    46,    47,    48,    49,    50,    60,   129,
       3,    84,     3,   133,    49,    50,   136,    60,    58,    59,
       3,   110,   111,   112,   113,   114,     4,     5,     6,     7,
      47,    48,    49,    50,    53,    58,   156,   126,   127,    54,
       4,     5,     6,     7,     3,    38,    39,    40,    41,    57,
      57,    44,    41,   129,    55,    48,    56,   133,    52,    55,
     136,    54,   151,    60,    42,    43,    54,    45,    46,    47,
      48,    49,    50,    53,    20,    56,     3,    55,    42,    43,
     156,    45,    46,    47,    48,    49,    50,     3,    27,    22,
      58,    55,     3,     4,     5,     6,     7,    24,    31,    26,
      33,    41,    32,    30,    31,    41,    33,    55,     3,    82,
      37,     4,     5,     6,     7,    22,   138,    -1,   117,    30,
      31,    -1,    33,    -1,    -1,    52,     4,     5,     6,     7,
      -1,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      -1,    52,     4,     5,     6,     7,    -1,    -1,    -1,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    23,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    62,    63,     3,     0,    62,    64,    52,    65,
      25,    35,    36,    66,    67,    68,    76,    87,    88,    89,
       3,     3,     3,    53,    66,    67,    66,    77,    57,    58,
      85,    86,    85,    86,    54,    69,    12,    23,    28,    34,
      98,     3,    38,    39,    40,    41,    44,    48,    54,    90,
      94,    95,    96,    97,    85,    59,    85,     3,    70,    71,
      57,    72,    54,    59,    94,    94,    94,     4,     5,     6,
       7,    42,    43,    45,    46,    47,    48,    49,    50,    41,
      57,    55,    56,    98,    52,    73,    91,    94,    55,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    60,    98,    70,    67,    92,    94,    60,     3,    24,
      26,    30,    31,    33,    37,    73,    74,    75,    78,    79,
      80,    82,    83,    84,    55,    93,    58,    59,    54,    94,
      94,    94,    94,    94,    53,    74,    20,    81,    56,    94,
      94,     3,    73,    78,    73,    78,    73,    78,    92,    60,
      27,    58,    41,    94,    32,    41,    55,    73,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    64,    63,    65,    66,    66,    66,
      67,    67,    68,    68,    68,    69,    70,    70,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    75,    75,    77,
      76,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    87,    87,    87,    87,    88,    88,    89,    91,    90,
      93,    92,    92,    92,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    98,
      98,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     3,     2,     2,     1,
       2,     0,     1,     1,     1,     3,     3,     1,     0,     3,
       2,     0,     4,     2,     1,     1,     1,     1,     1,     0,
       6,     3,     6,     2,     2,     2,     1,     1,     2,     3,
       3,     2,     2,     1,     1,     3,     3,     9,     9,     2,
       2,     2,     3,     3,     4,     3,     4,     6,     0,     5,
       0,     4,     1,     0,     3,     1,     1,     4,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 111 "parser.y"
                             { push(); }
#line 1317 "y.tab.cpp"
    break;

  case 5: /* class_declaration: CLASS ID $@1 class_block  */
#line 113 "parser.y"
                  {
                    identifierData* temp = fetch("main");
                    if(temp->id_type != 3) yyerror("main is not a function");
                    dump();
                    pop();
                  }
#line 1328 "y.tab.cpp"
    break;

  case 19: /* argument: ID ':' variable_type  */
#line 133 "parser.y"
                               { createWithTypes(*(yyvsp[-2].string_value), (yyvsp[0].data_type), 1); addArgument(*(yyvsp[-2].string_value), (yyvsp[0].data_type)); }
#line 1334 "y.tab.cpp"
    break;

  case 20: /* return_type: ':' variable_type  */
#line 135 "parser.y"
                                { tableList[top_index - 1].setReturnType((yyvsp[0].data_type)); }
#line 1340 "y.tab.cpp"
    break;

  case 21: /* return_type: %empty  */
#line 136 "parser.y"
              { tableList[top_index - 1].setReturnType(6); }
#line 1346 "y.tab.cpp"
    break;

  case 29: /* $@2: %empty  */
#line 145 "parser.y"
                   { createFunction(*(yyvsp[0].string_value), 3); push();}
#line 1352 "y.tab.cpp"
    break;

  case 30: /* function: FUN ID $@2 formal_arguments return_type block  */
#line 145 "parser.y"
                                                                                         { dump(); pop();}
#line 1358 "y.tab.cpp"
    break;

  case 31: /* simple_stmt: ID '=' expression  */
#line 148 "parser.y"
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
            }
#line 1382 "y.tab.cpp"
    break;

  case 32: /* simple_stmt: ID '[' expression ']' '=' expression  */
#line 167 "parser.y"
                                                   { identifierData* temp = fetch(*(yyvsp[-5].string_value)); if ((yyvsp[-3].data)->value.i_val >= temp->array_size || (yyvsp[-3].data)-> value.i_val < 0) yyerror("Given index is not within range"); if (temp->value.arguments[0].data_type != (yyvsp[0].data)->data_type) yyerror("Data type doesn't match"); }
#line 1388 "y.tab.cpp"
    break;

  case 39: /* if_statement: IF expression simple_stmt  */
#line 176 "parser.y"
                                              { checkDataType(*(yyvsp[-1].data), 3); }
#line 1394 "y.tab.cpp"
    break;

  case 40: /* if_statement: IF expression block  */
#line 177 "parser.y"
                                        { checkDataType(*(yyvsp[-1].data), 3); }
#line 1400 "y.tab.cpp"
    break;

  case 45: /* while_loop: WHILE expression simple_stmt  */
#line 186 "parser.y"
                                           { checkDataType(*(yyvsp[-1].data), 3); }
#line 1406 "y.tab.cpp"
    break;

  case 46: /* while_loop: WHILE expression block  */
#line 187 "parser.y"
                                     { checkDataType(*(yyvsp[-1].data), 3); }
#line 1412 "y.tab.cpp"
    break;

  case 47: /* for_loop: FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' simple_stmt  */
#line 190 "parser.y"
                                                                      { checkIdentifierType(*fetch(*(yyvsp[-6].string_value)), 1); }
#line 1418 "y.tab.cpp"
    break;

  case 48: /* for_loop: FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' block  */
#line 191 "parser.y"
                                                                { checkIdentifierType(*fetch(*(yyvsp[-6].string_value)), 1); }
#line 1424 "y.tab.cpp"
    break;

  case 49: /* assign_expr: '=' expression  */
#line 194 "parser.y"
                            { (yyval.data) = (yyvsp[0].data);}
#line 1430 "y.tab.cpp"
    break;

  case 50: /* assign_var_type: ':' variable_type  */
#line 196 "parser.y"
                                   { (yyval.data_type) = (yyvsp[0].data_type);}
#line 1436 "y.tab.cpp"
    break;

  case 51: /* variable: VAR ID  */
#line 198 "parser.y"
                 { createWithTypes(*(yyvsp[0].string_value), 1, 1);}
#line 1442 "y.tab.cpp"
    break;

  case 52: /* variable: VAR ID assign_expr  */
#line 199 "parser.y"
                             { create(*(yyvsp[-1].string_value), *(yyvsp[0].data), 1);}
#line 1448 "y.tab.cpp"
    break;

  case 53: /* variable: VAR ID assign_var_type  */
#line 200 "parser.y"
                                 { createWithTypes(*(yyvsp[-1].string_value), (yyvsp[0].data_type), 1);}
#line 1454 "y.tab.cpp"
    break;

  case 54: /* variable: VAR ID assign_var_type assign_expr  */
#line 201 "parser.y"
                                             { checkDataType(*(yyvsp[0].data), (yyvsp[-1].data_type)); create(*(yyvsp[-2].string_value), *(yyvsp[0].data), 1);}
#line 1460 "y.tab.cpp"
    break;

  case 55: /* constant: VAL ID assign_expr  */
#line 204 "parser.y"
                             { create(*(yyvsp[-1].string_value), *(yyvsp[0].data), 2); }
#line 1466 "y.tab.cpp"
    break;

  case 56: /* constant: VAL ID assign_var_type assign_expr  */
#line 205 "parser.y"
                                             { checkDataType(*(yyvsp[0].data), (yyvsp[-1].data_type)); create(*(yyvsp[-2].string_value), *(yyvsp[0].data), 2);}
#line 1472 "y.tab.cpp"
    break;

  case 57: /* array: VAR ID assign_var_type '[' INT_LITERAL ']'  */
#line 208 "parser.y"
                                                   { createArray(*(yyvsp[-4].string_value), (yyvsp[-3].data_type), (yyvsp[-1].integer_value));}
#line 1478 "y.tab.cpp"
    break;

  case 58: /* $@3: %empty  */
#line 210 "parser.y"
                   { checkIdentifierType(*fetch(*(yyvsp[-1].string_value)), 3); beginParam(); }
#line 1484 "y.tab.cpp"
    break;

  case 59: /* invocation: ID '(' $@3 comma_separated_expressions ')'  */
#line 210 "parser.y"
                                                                                                          { checkParameters(fetch(*(yyvsp[-4].string_value))); (yyval.data) = fetch(*(yyvsp[-4].string_value)); endParam(); }
#line 1490 "y.tab.cpp"
    break;

  case 60: /* $@4: %empty  */
#line 212 "parser.y"
                                         { addParam(*(yyvsp[0].data)); }
#line 1496 "y.tab.cpp"
    break;

  case 62: /* comma_separated_expressions: expression  */
#line 213 "parser.y"
                                         { addParam(*(yyvsp[0].data)); }
#line 1502 "y.tab.cpp"
    break;

  case 64: /* expression: '(' expression ')'  */
#line 217 "parser.y"
                                { (yyval.data) = (yyvsp[-1].data); }
#line 1508 "y.tab.cpp"
    break;

  case 65: /* expression: ID  */
#line 218 "parser.y"
                  { (yyval.data) = fetch(*(yyvsp[0].string_value)); }
#line 1514 "y.tab.cpp"
    break;

  case 67: /* expression: ID '[' expression ']'  */
#line 220 "parser.y"
                                    { identifierData *temp = fetch(*(yyvsp[-3].string_value)); if(temp->data_type != 5) yyerror(*(yyvsp[-3].string_value) + " is not an array"); if((yyvsp[-1].data)->value.i_val >= temp->array_size || (yyvsp[-1].data)->value.i_val < 0) yyerror("Index out of range"); (yyval.data) = new identifierData(); (yyval.data)->data_type = temp->data_type;}
#line 1520 "y.tab.cpp"
    break;

  case 71: /* bool_expr: expression '<' expression  */
#line 227 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val < (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((float)(yyvsp[-2].data)->value.i_val < (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val < (float)(yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val < (yyvsp[0].data)->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            (yyval.data) = temp;
          }
#line 1545 "y.tab.cpp"
    break;

  case 72: /* bool_expr: expression LE expression  */
#line 248 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val <= (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((float)(yyvsp[-2].data)->value.i_val <= (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val <= (float)(yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val <= (yyvsp[0].data)->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            (yyval.data) = temp;
          }
#line 1570 "y.tab.cpp"
    break;

  case 73: /* bool_expr: expression EQ expression  */
#line 269 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val == (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val == (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.b_val = ((yyvsp[-2].data)->value.b_val == (yyvsp[0].data)->value.b_val);
            }
            else if((yyvsp[-2].data)->data_type == 4 && (yyvsp[0].data)->data_type == 4) {
              temp->value.b_val = ((yyvsp[-2].data)->value.s_val == (yyvsp[0].data)->value.s_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr == expr");
            }
            (yyval.data) = temp;
          }
#line 1595 "y.tab.cpp"
    break;

  case 74: /* bool_expr: expression GE expression  */
#line 290 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val >= (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((float)(yyvsp[-2].data)->value.i_val >= (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val >= (float)(yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val >= (yyvsp[0].data)->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr >= expr");
            }
            (yyval.data) = temp;
          }
#line 1620 "y.tab.cpp"
    break;

  case 75: /* bool_expr: expression '>' expression  */
#line 311 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val > (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((float)(yyvsp[-2].data)->value.i_val > (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val > (float)(yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val > (yyvsp[0].data)->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr > expr");
            }
            (yyval.data) = temp;
          }
#line 1645 "y.tab.cpp"
    break;

  case 76: /* bool_expr: expression NE expression  */
#line 332 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
              temp->value.b_val = ((yyvsp[-2].data)->value.i_val != (yyvsp[0].data)->value.i_val);
            }
            else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
              temp->value.b_val = ((yyvsp[-2].data)->value.d_val != (yyvsp[0].data)->value.d_val);
            }
            else if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.b_val = ((yyvsp[-2].data)->value.b_val != (yyvsp[0].data)->value.b_val);
            }
            else if((yyvsp[-2].data)->data_type == 4 && (yyvsp[0].data)->data_type == 4) {
              temp->value.b_val = ((yyvsp[-2].data)->value.s_val != (yyvsp[0].data)->value.s_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr != expr");
            }
            (yyval.data) = temp;
          }
#line 1670 "y.tab.cpp"
    break;

  case 77: /* bool_expr: '!' expression  */
#line 353 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[0].data)->data_type == 3) {
              temp->value.b_val = !((yyvsp[0].data)->value.b_val);
            }
            else {
              yyerror("Incompatible type for !expr");
            }
            (yyval.data) = temp;
          }
#line 1686 "y.tab.cpp"
    break;

  case 78: /* bool_expr: expression '&' expression  */
#line 365 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.b_val = (yyvsp[-2].data)->value.b_val && (yyvsp[0].data)->value.b_val;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            (yyval.data) = temp;
          }
#line 1702 "y.tab.cpp"
    break;

  case 79: /* bool_expr: expression '|' expression  */
#line 377 "parser.y"
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if((yyvsp[-2].data)->data_type == 3 && (yyvsp[0].data)->data_type == 3) {
              temp->value.b_val = (yyvsp[-2].data)->value.b_val || (yyvsp[0].data)->value.b_val;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            (yyval.data) = temp;
          }
#line 1718 "y.tab.cpp"
    break;

  case 80: /* arithmetic_expr: '-' expression  */
#line 390 "parser.y"
                {
                  identifierData* temp = new identifierData();
                    if((yyvsp[0].data)->data_type == 1) {
                    *temp = *(yyvsp[0].data);
                    temp->value.i_val = -1 * temp->value.i_val;
                  }
                  else if((yyvsp[0].data)->data_type == 2) {
                    *temp = *(yyvsp[0].data);
                    temp->value.d_val = -1 * temp->value.d_val;
                  }
                  else {
                    yyerror("Incompatible type for -expr");
                  }
                  (yyval.data) = temp;
                }
#line 1738 "y.tab.cpp"
    break;

  case 81: /* arithmetic_expr: expression '*' expression  */
#line 406 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ((yyvsp[-2].data)->value.i_val * (yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)(yyvsp[-2].data)->value.i_val * (yyvsp[0].data)->value.d_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val * (double)(yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val * (yyvsp[0].data)->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr * expr");
                  }
                  (yyval.data) = temp;
                }
#line 1766 "y.tab.cpp"
    break;

  case 82: /* arithmetic_expr: expression '/' expression  */
#line 430 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ((yyvsp[-2].data)->value.i_val / (yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)(yyvsp[-2].data)->value.i_val / (yyvsp[0].data)->value.d_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val / (double)(yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val / (yyvsp[0].data)->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr / expr");
                  }
                  (yyval.data) = temp;
                }
#line 1794 "y.tab.cpp"
    break;

  case 83: /* arithmetic_expr: expression '+' expression  */
#line 454 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ((yyvsp[-2].data)->value.i_val + (yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)(yyvsp[-2].data)->value.i_val + (yyvsp[0].data)->value.d_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val + (double)(yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val + (yyvsp[0].data)->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr + expr");
                  }
                  (yyval.data) = temp;
                }
#line 1822 "y.tab.cpp"
    break;

  case 84: /* arithmetic_expr: expression '-' expression  */
#line 478 "parser.y"
                {
                  identifierData* temp = new identifierData();
                  if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ((yyvsp[-2].data)->value.i_val - (yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 1 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)(yyvsp[-2].data)->value.i_val - (yyvsp[0].data)->value.d_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val - (double)(yyvsp[0].data)->value.i_val);
                  }
                  else if((yyvsp[-2].data)->data_type == 2 && (yyvsp[0].data)->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((yyvsp[-2].data)->value.d_val - (yyvsp[0].data)->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr - expr");
                  }
                  (yyval.data) = temp;
                }
#line 1850 "y.tab.cpp"
    break;

  case 85: /* literal_constant: INT_LITERAL  */
#line 503 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 1;
                  data->value.i_val = (yyvsp[0].integer_value);
                  data->id_type = 4;
                  (yyval.data) = data;
                }
#line 1862 "y.tab.cpp"
    break;

  case 86: /* literal_constant: REAL_LITERAL  */
#line 511 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 2;
                  data->value.d_val = (yyvsp[0].double_value);
                  data->id_type = 4;
                  (yyval.data) = data;
                }
#line 1874 "y.tab.cpp"
    break;

  case 87: /* literal_constant: BOOL_LITERAL  */
#line 519 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 3;
                  data->value.b_val = (yyvsp[0].boolean_value);
                  data->id_type = 4;
                  (yyval.data) = data;
                }
#line 1886 "y.tab.cpp"
    break;

  case 88: /* literal_constant: STRING_LITERAL  */
#line 527 "parser.y"
                {
                  identifierData* data = new identifierData();
                  data->data_type = 4;
                  data->value.s_val = *(yyvsp[0].string_value);
                  data->id_type = 4;
                  (yyval.data) = data;
                }
#line 1898 "y.tab.cpp"
    break;

  case 89: /* variable_type: INT  */
#line 536 "parser.y"
                    { (yyval.data_type) = 1; }
#line 1904 "y.tab.cpp"
    break;

  case 90: /* variable_type: FLOAT  */
#line 537 "parser.y"
                      { (yyval.data_type) = 2; }
#line 1910 "y.tab.cpp"
    break;

  case 91: /* variable_type: BOOL  */
#line 538 "parser.y"
                     { (yyval.data_type) = 3; }
#line 1916 "y.tab.cpp"
    break;

  case 92: /* variable_type: STRING  */
#line 539 "parser.y"
                       { (yyval.data_type) = 4; }
#line 1922 "y.tab.cpp"
    break;


#line 1926 "y.tab.cpp"

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

#line 543 "parser.y"


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
    if (tableList[i].doesExist(id)) result = tableList[i].lookup(id);
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

int main(void) {
    yyparse();
    return 0;
}
