/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "p.y"

#include <stdio.h>
#include<string.h>
#include<stdlib.h>


struct Tnode
	{int type;
	 int nodetype;//opr 3,read 4, write 5, id 2,constant 1, void 0, 6 if,7 while, 8 rel op,9 log op,10 assign op, 11 func, 12 return
	 char op;
	 char* name;
	 int value;
	 struct Arg *arg_list;
	 struct Gsymbol *Gentry;
	 struct Lsymbol *Lentry; 
	 struct Tnode *ptr1,*ptr2,*ptr3;
	};

struct Arg
	{char *name; // Name of the Identifier
	 int type; // TYPE can be INTEGER or BOOLEAN
	 int ref; // 0 for non reference, 1 for reference
	 struct Arg* next;
	};

struct Gsymbol 
	{char *name; // Name of the Identifier
	 int type; // TYPE can be INTEGER or BOOLEAN
	 int size; // Size field for arrays
	 int binding; // Address of the Identifier in Memory
	 struct Arg *arg_list;
	 struct Gsymbol *next; // Pointer to next Symbol Table Entry
	};

struct Lsymbol 
	{char *name; // Name of the Identifier
	 int type; // TYPE can be INTEGER or BOOLEAN
	 int binding; // Address of the Identifier in Memory
	 struct Lsymbol *next; // Pointer to next Symbol Table Entry
	};

struct Function
	{char* name;
	 int label;
	 int status;
	 struct Function* next;
	};


void built_tree_bin_op(char op_type,struct Tnode* oprnd1,struct Tnode* opr,struct Tnode* oprnd2); 
void built_tree_un_op(char op_type,struct Tnode* opr,struct Tnode* oprnd); 
void built_tree_id(char id_type,struct Tnode* id,struct Tnode* expr); 
void built_tree_stmt(char cnstrt_type,struct Tnode* construct,struct Tnode* expr,struct Tnode* stmt_list1,struct Tnode* stmt_list2); 
void built_tree_assign_op(char op_type,struct Tnode* id,struct Tnode* index,struct Tnode* op,struct Tnode* value);
void built_tree_read(char read_type,struct Tnode* read,struct Tnode* id,struct Tnode* index);
void built_tree_write(struct Tnode* write,struct Tnode* expr);
void built_tree_function(struct Tnode* id,struct Tnode* expr_list);
void built_tree_return(struct Tnode* ret,struct Tnode* expr);

void Ginstall(char* name,int type,struct Arg* arg_list,int size); 
struct Gsymbol *Glookup(char* name);
struct Gsymbol *Ghead=NULL;

void Linstall(char* name,int type);
void Linstall_arg(struct Arg* arg_list); 
struct Lsymbol *Llookup(char* name);
void free_local_decl_list();
struct Lsymbol *Lhead=NULL;

struct Arg *create_Arg(char* name,int type,int ref);
struct Arg *Arglookup(char* name);
void Arginstall(char* name,int type,int ref);
void free_arg_decl_list();
void print_arg_list(struct Arg* head);
struct Arg *arg_head=NULL;
struct Arg *arg_tail=NULL;

void print_expr_list(struct Tnode* head);

void check_bool(struct Tnode* x);
void check_arith(struct Tnode* x);
void check_void(struct Tnode* x);
void check_arg_match(struct Arg* arg_list_1,struct Arg* arg_list_2);

int generate_code_function(struct Tnode* x);
int generate_code_main(struct Tnode* x);
int create_SIM(struct Tnode* x);

void yyerror(char *);
int yylex(void);

void add_function(char* name);
int function_set_status(char* name);
int function_lookup(char* name);
struct Function *function_head=NULL;

struct Tnode* reverse_expr_list(struct Tnode* head);
void free_expr_list(struct Tnode* head);
	 

extern yylineno;
FILE* fp=NULL;

int Type,FuncRetType;
int reg_last=0;
int label_last=0;
const int REG_NUM=8;

int g_sp=0,l_sp=0;
struct Gsymbol* current_func=NULL;
struct Tnode* allocate(int type,int nodetype,char op,char* name,int value);


/* Line 268 of yacc.c  */
#line 185 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     ID = 259,
     READ = 260,
     WRITE = 261,
     IF = 262,
     ELSE = 263,
     ENDIF = 264,
     WHILE = 265,
     ENDWHILE = 266,
     THEN = 267,
     DO = 268,
     DECL = 269,
     ENDDECL = 270,
     INT_TYPE = 271,
     BOOL_TYPE = 272,
     BOOL_VAL = 273,
     BEG = 274,
     END = 275,
     RETURN = 276,
     MAIN = 277,
     NOT = 278,
     OR = 279,
     AND = 280,
     NE = 281,
     EQ = 282,
     GE = 283,
     GT = 284,
     LE = 285,
     LT = 286,
     UMINUS = 287
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define ID 259
#define READ 260
#define WRITE 261
#define IF 262
#define ELSE 263
#define ENDIF 264
#define WHILE 265
#define ENDWHILE 266
#define THEN 267
#define DO 268
#define DECL 269
#define ENDDECL 270
#define INT_TYPE 271
#define BOOL_TYPE 272
#define BOOL_VAL 273
#define BEG 274
#define END 275
#define RETURN 276
#define MAIN 277
#define NOT 278
#define OR 279
#define AND 280
#define NE 281
#define EQ 282
#define GE 283
#define GT 284
#define LE 285
#define LT 286
#define UMINUS 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 114 "p.y"
struct Tnode* x;
	


/* Line 293 of yacc.c  */
#line 290 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 302 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,    23,     2,
      28,    29,    42,    40,    47,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    12,    15,    19,    23,    25,
      27,    32,    33,    39,    40,    43,    44,    45,    46,    59,
      60,    62,    66,    69,    73,    75,    77,    80,    89,    94,
      98,   102,   103,   106,   110,   114,   116,   118,   120,   122,
     125,   126,   131,   139,   145,   154,   160,   169,   180,   189,
     192,   193,   195,   199,   203,   207,   211,   215,   219,   222,
     226,   230,   234,   238,   242,   246,   250,   254,   258,   261,
     263,   265,   270,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    56,    65,    -1,    14,    51,    15,
      -1,    -1,    51,    52,    -1,    73,    53,    46,    -1,    53,
      47,    54,    -1,    54,    -1,     4,    -1,     4,    26,     3,
      27,    -1,    -1,     4,    55,    28,    61,    29,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    73,     4,    58,    28,
      61,    29,    59,    24,    68,    60,    66,    25,    -1,    -1,
      62,    -1,    61,    46,    62,    -1,    73,    63,    -1,    63,
      47,    64,    -1,    64,    -1,     4,    -1,    23,     4,    -1,
      16,    22,    28,    29,    24,    68,    66,    25,    -1,    19,
      74,    67,    20,    -1,    21,    77,    46,    -1,    14,    69,
      15,    -1,    -1,    69,    70,    -1,    73,    71,    46,    -1,
      71,    47,    72,    -1,    72,    -1,     4,    -1,    16,    -1,
      17,    -1,    74,    75,    -1,    -1,     4,    30,    77,    46,
      -1,     4,    26,    77,    27,    30,    77,    46,    -1,     5,
      28,     4,    29,    46,    -1,     5,    28,     4,    26,    77,
      27,    29,    46,    -1,     6,    28,    77,    29,    46,    -1,
       7,    28,    77,    29,    12,    74,     9,    46,    -1,     7,
      28,    77,    29,    12,    74,     8,    74,     9,    46,    -1,
      10,    28,    77,    29,    13,    74,    11,    46,    -1,     1,
      46,    -1,    -1,    77,    -1,    76,    47,    77,    -1,    77,
      40,    77,    -1,    77,    42,    77,    -1,    77,    41,    77,
      -1,    77,    43,    77,    -1,    77,    44,    77,    -1,    41,
      77,    -1,    28,    77,    29,    -1,    77,    39,    77,    -1,
      77,    38,    77,    -1,    77,    37,    77,    -1,    77,    36,
      77,    -1,    77,    35,    77,    -1,    77,    34,    77,    -1,
      77,    33,    77,    -1,    77,    32,    77,    -1,    31,    77,
      -1,     3,    -1,    18,    -1,     4,    26,    77,    27,    -1,
       4,    -1,     4,    28,    76,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   137,   142,   143,   146,   149,   150,   153,
     160,   168,   167,   182,   183,   187,   195,   204,   186,   217,
     218,   219,   222,   225,   226,   229,   236,   246,   254,   262,
     268,   272,   273,   276,   279,   280,   283,   292,   295,   300,
     307,   311,   315,   319,   323,   327,   331,   335,   339,   343,
     347,   349,   352,   358,   362,   366,   370,   374,   378,   383,
     385,   389,   393,   397,   401,   405,   409,   413,   417,   421,
     423,   425,   429,   433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "ID", "READ", "WRITE", "IF",
  "ELSE", "ENDIF", "WHILE", "ENDWHILE", "THEN", "DO", "DECL", "ENDDECL",
  "INT_TYPE", "BOOL_TYPE", "BOOL_VAL", "BEG", "END", "RETURN", "MAIN",
  "'&'", "'{'", "'}'", "'['", "']'", "'('", "')'", "'='", "NOT", "OR",
  "AND", "NE", "EQ", "GE", "GT", "LE", "LT", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "';'", "','", "$accept", "program", "g_decl_block",
  "g_decl_list", "g_decl", "g_id_list", "g_id", "$@1", "f_def_list",
  "f_def", "$@2", "$@3", "$@4", "arg_list", "arg", "arg_id_list", "arg_id",
  "main_block", "body", "ret_stmt", "l_decl_block", "l_decl_list",
  "l_decl", "l_id_list", "l_id", "type", "stmt_list", "stmt", "expr_list",
  "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    38,   123,   125,    91,    93,    40,    41,
      61,   278,   279,   280,   281,   282,   283,   284,   285,   286,
      43,    45,    42,    47,    37,   287,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    54,    56,    56,    58,    59,    60,    57,    61,
      61,    61,    62,    63,    63,    64,    64,    65,    66,    67,
      68,    69,    69,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     3,     1,     1,
       4,     0,     5,     0,     2,     0,     0,     0,    12,     0,
       1,     3,     2,     3,     1,     1,     2,     8,     4,     3,
       3,     0,     2,     3,     3,     1,     1,     1,     1,     2,
       0,     4,     7,     5,     8,     5,     8,    10,     8,     2,
       0,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     4,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    13,     0,     1,     0,     3,    37,    38,
       5,     0,    37,    14,     2,     0,     9,     0,     8,     0,
      15,     0,     0,     6,     0,     0,     0,     0,    19,     7,
       0,    19,    10,     0,    20,     0,     0,     0,    12,     0,
      25,     0,    22,    24,    31,     0,    16,    21,    26,     0,
       0,    40,     0,     0,    23,    30,    32,     0,     0,    27,
       0,    36,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    17,    33,     0,    49,     0,     0,     0,
       0,     0,     0,    69,    72,    70,     0,     0,     0,     0,
      28,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    68,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,    51,    59,
      67,    66,    65,    64,    63,    62,    61,    60,    53,    55,
      54,    56,    57,    18,     0,     0,    43,    45,    40,    40,
      71,    73,     0,     0,     0,     0,     0,    52,    42,     0,
      40,     0,     0,    44,     0,    46,    48,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    17,    18,    22,     6,    13,
      26,    53,    91,    33,    34,    42,    43,    14,    52,    71,
      45,    50,    56,    62,    63,    35,    58,    72,   127,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
      35,   -95,    64,   -95,    57,   -95,    53,   -95,   -95,   -95,
     -95,    89,   120,   -95,   -95,   107,    30,   231,   -95,   115,
     -95,   155,   131,   -95,    89,   145,   147,   175,   110,   -95,
     193,   110,   -95,   -22,   -95,    -2,   218,    14,   -95,   110,
     -95,   255,   236,   -95,   -95,   241,   -95,   -95,   -95,    -2,
      75,   -95,   240,   267,   -95,   -95,   -95,   289,    41,   -95,
     218,   -95,   249,   -95,   251,    31,   270,   271,   272,   273,
      22,   282,   -95,   -95,   -95,   289,   -95,    22,    22,   299,
      22,    22,    22,   -95,   266,   -95,    22,    22,    22,   157,
     -95,   241,   -95,    44,   172,    39,    96,   112,   128,    22,
      22,   144,   213,   -95,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,   -95,   279,   276,
     -95,    22,   259,   261,   296,   297,    62,    12,   202,   -95,
     213,   213,   -24,   -24,   246,   246,   246,   246,    66,    66,
     -95,   -95,   -95,   -95,    22,    80,   -95,   -95,   -95,   -95,
     -95,   -95,    22,   187,   280,   265,   257,   202,   -95,   268,
     -95,   269,   274,   -95,   275,   -95,   -95,   277,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -95,   -95,   287,   -95,   -95,   -95,
     -95,   -95,   -95,   281,   278,   -95,   264,   -95,   225,   -95,
     258,   -95,   -95,   -95,   244,     2,   -94,   -95,   -95,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -12
static const yytype_int16 yytable[] =
{
      93,    94,    40,    96,    97,    98,    11,    38,    15,   101,
     102,   103,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    41,   126,   128,    39,    83,    84,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      85,   151,    64,    46,   145,    65,    66,    67,    68,     1,
      86,    69,    57,    87,   155,   156,    21,    77,   -11,   152,
      39,    78,    70,    88,     5,   121,   164,   153,   122,    12,
       9,   119,     7,     8,     9,   157,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   150,
      55,     8,     9,    16,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   154,   114,   115,
     116,    20,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   123,     8,     9,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   124,    19,    25,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   125,    27,    28,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   129,    30,    31,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    32,   117,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    36,   120,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    44,   158,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    64,    48,
      51,    65,    66,    67,    68,    59,    64,    69,   162,    65,
      66,    67,    68,   160,   161,    69,    64,    23,    24,    65,
      66,    67,    68,    49,   167,    69,   112,   113,   114,   115,
     116,    60,    99,    61,   100,    74,    75,    76,    79,    80,
      81,    82,    90,    95,   143,   146,   144,   147,   148,   159,
     149,    29,    37,    54,   163,   165,   118,    47,    73,    92,
     166,     0,     0,   168
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-95))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      77,    78,     4,    80,    81,    82,     4,    29,     6,    86,
      87,    88,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    23,    99,   100,    46,     3,     4,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      18,    29,     1,    29,   121,     4,     5,     6,     7,    14,
      28,    10,    50,    31,   148,   149,    26,    26,    28,    47,
      46,    30,    21,    41,     0,    26,   160,   144,    29,    16,
      17,    27,    15,    16,    17,   152,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    27,
      15,    16,    17,     4,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    27,    42,    43,
      44,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    29,    16,    17,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    29,    22,    28,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    29,     3,    28,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    29,    29,    28,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    27,    46,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    24,    46,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    14,    46,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     1,     4,
      19,     4,     5,     6,     7,    25,     1,    10,    11,     4,
       5,     6,     7,     8,     9,    10,     1,    46,    47,     4,
       5,     6,     7,    47,     9,    10,    40,    41,    42,    43,
      44,    24,    26,     4,    28,    46,    47,    46,    28,    28,
      28,    28,    20,     4,    25,    46,    30,    46,    12,    29,
      13,    24,    31,    49,    46,    46,    91,    39,    60,    75,
      46,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    49,    50,    51,     0,    56,    15,    16,    17,
      52,    73,    16,    57,    65,    73,     4,    53,    54,    22,
       4,    26,    55,    46,    47,    28,    58,     3,    28,    54,
      29,    28,    27,    61,    62,    73,    24,    61,    29,    46,
       4,    23,    63,    64,    14,    68,    29,    62,     4,    47,
      69,    19,    66,    59,    64,    15,    70,    73,    74,    25,
      24,     4,    71,    72,     1,     4,     5,     6,     7,    10,
      21,    67,    75,    68,    46,    47,    46,    26,    30,    28,
      28,    28,    28,     3,     4,    18,    28,    31,    41,    77,
      20,    60,    72,    77,    77,     4,    77,    77,    77,    26,
      28,    77,    77,    77,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    46,    66,    27,
      46,    26,    29,    29,    29,    29,    77,    76,    77,    29,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    25,    30,    77,    46,    46,    12,    13,
      27,    29,    47,    77,    27,    74,    74,    77,    46,    29,
       8,     9,    11,    46,    74,    46,    46,     9,    46
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 134 "p.y"
    {fclose(fp);
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 138 "p.y"
    {(yyval.x)=(yyvsp[(2) - (3)].x);
			 fp=fopen("a.sim","w");
			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 154 "p.y"
    {if(Glookup((yyvsp[(1) - (1)].x)->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,(yyvsp[(1) - (1)].x)->name);
			 	 exit(0);
				}
			 Ginstall((yyvsp[(1) - (1)].x)->name,Type,NULL,1);
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 161 "p.y"
    {if(Glookup((yyvsp[(1) - (4)].x)->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,(yyvsp[(1) - (4)].x)->name);
			 	 exit(0);
				}
			 Ginstall((yyvsp[(1) - (4)].x)->name,Type,NULL,(yyvsp[(3) - (4)].x)->value);
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 168 "p.y"
    {FuncRetType=Type;
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 171 "p.y"
    {if(Glookup((yyvsp[(1) - (5)].x)->name)!=NULL)
				{printf("Line %d: function %s already declared \n",yylineno,(yyvsp[(1) - (5)].x)->name);
			 	 exit(0);
				}
			 Ginstall((yyvsp[(1) - (5)].x)->name,FuncRetType,arg_head,0);
			 arg_head=NULL;
			 arg_tail=NULL;
			 add_function((yyvsp[(1) - (5)].x)->name);
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 187 "p.y"
    {current_func=Glookup((yyvsp[(2) - (2)].x)->name);
			 if(current_func->type!=Type)
				{printf("Line %d: function %s return type mismatch \n",yylineno,(yyvsp[(2) - (2)].x)->name);
			  	 exit(0);
				}
			  
			}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 195 "p.y"
    {if(current_func==NULL)
				{printf("Line %d: function %s not declared \n",yylineno,(yyvsp[(2) - (6)].x)->name);
			  	 exit(0);
				}
			  check_arg_match(arg_head,Glookup((yyvsp[(2) - (6)].x)->name)->arg_list);
			  function_set_status((yyvsp[(2) - (6)].x)->name);
			 }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 204 "p.y"
    {Linstall_arg(Glookup((yyvsp[(2) - (9)].x)->name)->arg_list);
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 207 "p.y"
    {generate_code_function((yyvsp[(11) - (12)].x));
			  free_local_decl_list();
			  free_arg_decl_list();
			  l_sp=0;
			 }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 230 "p.y"
    {if(Arglookup((yyvsp[(1) - (1)].x)->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,(yyvsp[(1) - (1)].x)->name);
			 	 exit(0);
				}
			 Arginstall((yyvsp[(1) - (1)].x)->name,Type,0);
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 237 "p.y"
    {if(Arglookup((yyvsp[(2) - (2)].x)->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,(yyvsp[(2) - (2)].x)->name);
			 	 exit(0);
				}
			 Arginstall((yyvsp[(2) - (2)].x)->name,Type,1);
			 (yyval.x)=(yyvsp[(2) - (2)].x);
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 247 "p.y"
    {current_func=NULL;
			 generate_code_main((yyvsp[(7) - (8)].x));
			 Lhead=NULL;
			 l_sp=0;
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 255 "p.y"
    {struct Tnode* dum=allocate(0,0,0,NULL,-1);
	 		 dum->ptr2=(yyvsp[(3) - (4)].x);
	 		 dum->ptr1=(yyvsp[(2) - (4)].x);
			 (yyval.x)=dum;
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 263 "p.y"
    {built_tree_return((yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x));
			 (yyval.x)=(yyvsp[(1) - (3)].x);
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 269 "p.y"
    {(yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 284 "p.y"
    {if(Llookup((yyvsp[(1) - (1)].x)->name)!=NULL||Arglookup((yyvsp[(1) - (1)].x)->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,(yyvsp[(1) - (1)].x)->name);
			 	 exit(0);
				}
			 Linstall((yyvsp[(1) - (1)].x)->name,Type);
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 293 "p.y"
    {Type=1;
			}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 296 "p.y"
    {Type=2;
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 301 "p.y"
    {struct Tnode* dum=allocate(0,0,0,NULL,-1);
	 		 dum->ptr2=(yyvsp[(2) - (2)].x);
	 		 dum->ptr1=(yyvsp[(1) - (2)].x);
			 (yyval.x)=dum;
			}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 307 "p.y"
    {(yyval.x)=NULL;
			}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 312 "p.y"
    {built_tree_assign_op('n',(yyvsp[(1) - (4)].x),NULL,(yyvsp[(2) - (4)].x),(yyvsp[(3) - (4)].x));
			 (yyval.x)=(yyvsp[(2) - (4)].x);
			}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 316 "p.y"
    {built_tree_assign_op('a',(yyvsp[(1) - (7)].x),(yyvsp[(3) - (7)].x),(yyvsp[(5) - (7)].x),(yyvsp[(6) - (7)].x));
			 (yyval.x)=(yyvsp[(5) - (7)].x);
			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 320 "p.y"
    {(yyval.x)=(yyvsp[(1) - (5)].x);
			 built_tree_read('n',(yyvsp[(1) - (5)].x),(yyvsp[(3) - (5)].x),NULL);
			}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 324 "p.y"
    {(yyval.x)=(yyvsp[(1) - (8)].x);
			 built_tree_read('a',(yyvsp[(1) - (8)].x),(yyvsp[(3) - (8)].x),(yyvsp[(5) - (8)].x));
			}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 328 "p.y"
    {built_tree_write((yyvsp[(1) - (5)].x),(yyvsp[(3) - (5)].x));
			 (yyval.x)=(yyvsp[(1) - (5)].x);
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 332 "p.y"
    {built_tree_stmt('i',(yyvsp[(1) - (8)].x),(yyvsp[(3) - (8)].x),(yyvsp[(6) - (8)].x),NULL);
			 (yyval.x)=(yyvsp[(1) - (8)].x);
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 336 "p.y"
    {built_tree_stmt('e',(yyvsp[(1) - (10)].x),(yyvsp[(3) - (10)].x),(yyvsp[(6) - (10)].x),(yyvsp[(8) - (10)].x));
			 (yyval.x)=(yyvsp[(1) - (10)].x);
			}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 340 "p.y"
    {built_tree_stmt('w',(yyvsp[(1) - (8)].x),(yyvsp[(3) - (8)].x),(yyvsp[(6) - (8)].x),NULL);
			 (yyval.x)=(yyvsp[(1) - (8)].x);
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 347 "p.y"
    {(yyval.x)=NULL;
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 350 "p.y"
    {(yyval.x)=(yyvsp[(1) - (1)].x);
			}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 353 "p.y"
    {(yyvsp[(3) - (3)].x)->ptr3=(yyvsp[(1) - (3)].x);
			 (yyval.x)=(yyvsp[(3) - (3)].x);
			}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 359 "p.y"
    {built_tree_bin_op('a',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 363 "p.y"
    {built_tree_bin_op('a',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 367 "p.y"
    {built_tree_bin_op('a',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 371 "p.y"
    {built_tree_bin_op('a',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 375 "p.y"
    {built_tree_bin_op('a',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 379 "p.y"
    {built_tree_un_op('a',(yyvsp[(1) - (2)].x),(yyvsp[(2) - (2)].x));
			 (yyval.x)=(yyvsp[(1) - (2)].x);
			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 384 "p.y"
    {(yyval.x)=(yyvsp[(2) - (3)].x);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 386 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 390 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 394 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 398 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 402 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 406 "p.y"
    {built_tree_bin_op('r',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 410 "p.y"
    {built_tree_bin_op('l',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 414 "p.y"
    {built_tree_bin_op('l',(yyvsp[(1) - (3)].x),(yyvsp[(2) - (3)].x),(yyvsp[(3) - (3)].x));
			 (yyval.x)=(yyvsp[(2) - (3)].x);
			}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 418 "p.y"
    {built_tree_un_op('l',(yyvsp[(1) - (2)].x),(yyvsp[(2) - (2)].x));
			 (yyval.x)=(yyvsp[(1) - (2)].x);
			}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 422 "p.y"
    {(yyval.x)=(yyvsp[(1) - (1)].x);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 424 "p.y"
    {(yyval.x)=(yyvsp[(1) - (1)].x);}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 426 "p.y"
    {built_tree_id('a',(yyvsp[(1) - (4)].x),(yyvsp[(3) - (4)].x));
			 (yyval.x)=(yyvsp[(1) - (4)].x);
			}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 430 "p.y"
    {built_tree_id('n',(yyvsp[(1) - (1)].x),NULL);
			 (yyval.x)=(yyvsp[(1) - (1)].x);
			}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 434 "p.y"
    {built_tree_function((yyvsp[(1) - (4)].x),(yyvsp[(3) - (4)].x));
			 (yyval.x)=(yyvsp[(1) - (4)].x);
			}
    break;



/* Line 1806 of yacc.c  */
#line 2198 "y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 439 "p.y"


void built_tree_return(struct Tnode* ret,struct Tnode* expr)
	{if(current_func==NULL)
		{if(expr->type!=1)
			{printf("Line %d: function: %s return call mismatch\n",yylineno,current_func->name);
			 exit(0);
			}
		}
	 else if(current_func->type!=expr->type)
		{printf("Line %d: function: %s return call mismatch\n",yylineno,current_func->name);
		 exit(0);
		}
	 else
	 	ret->ptr2=expr;
	}

void built_tree_function(struct Tnode* id,struct Tnode* expr_list)
	{void check_func_call(struct Arg* arg_list,struct Tnode* expr_list);
	 if(Glookup(id->name)==NULL)
			{printf("Line %d: function %s not declared\n",yylineno,id->name);
			 exit(0);
			}

	 id->nodetype=11;
	 id->type=Glookup(id->name)->type;
	 check_func_call(Glookup(id->name)->arg_list,expr_list);
	 id->ptr2=expr_list;
	}

struct Tnode* insert_expr(struct Tnode* head,struct Tnode* x)
	{if(head==NULL)
		head=x;
	 else
		{x->ptr3=head;
		 head=x;
		}
	 return head;
	}

struct Tnode* reverse_expr_list(struct Tnode* head)
 	{struct Tnode* insert_expr(struct Tnode* head,struct Tnode* x);
 	 struct Tnode *i,*x;
	 struct Tnode *new_head=NULL;

	 i=head;
	 
	 while(i!=NULL)
		{x=allocate(i->type,i->nodetype,i->op,i->name,i->value);
		 x->ptr1=i->ptr1;
		 x->ptr2=i->ptr2;
		 x->ptr3=NULL;
		 x->Lentry=i->Lentry;
		 x->Gentry=i->Gentry;
		 x->arg_list=i->arg_list;
		 new_head=insert_expr(new_head,x);
		 i=i->ptr3;
		}
	 return new_head;
	}

void free_expr_list(struct Tnode* head)
	{struct Tnode *i,*t;
	 while(i!=NULL)
		{t=i;
		 i=i->ptr3;
		 free(t);
		}
	}

void check_func_call(struct Arg* arg_list,struct Tnode* expr_list)
	{int check_variable(struct Tnode* expr);

	 expr_list=reverse_expr_list(expr_list);

	 struct Tnode* expr_i=expr_list;
	 struct Arg* arg_i=arg_list;

	 while((arg_i!=NULL)&&(expr_i!=NULL))
		{if(arg_i->type!=expr_i->type)
			break;
			
		 if(arg_i->ref&&!check_variable(expr_i))
			break;
			
		 arg_i=arg_i->next;
		 expr_i=expr_i->ptr3;
		}
	 
	 if(arg_i!=NULL||expr_i!=NULL)
		{printf("Line %d: function call doesnt match declaration\n",yylineno);
		 exit(0);
		}

//	 free_expr_list(expr_list);
	}

int check_variable(struct Tnode* expr)
	{if(expr->nodetype!=2)
			{printf("Line %d: expression cannot be passed as reference\n",yylineno);
			 exit(0);
			}
	 return 1;
	}

void built_tree_write(struct Tnode* write,struct Tnode* expr)
	{check_arith(expr);
	 write->ptr2=expr;
	 write->type=0;
	}

void built_tree_read(char read_type,struct Tnode* read,struct Tnode* id,struct Tnode* index)
	{switch(read_type)
		{case 'a':id->Gentry=Glookup(id->name);
			  if(id->Gentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
			  id->type=id->Gentry->type;
			  check_arith(id);
		 	  check_arith(index);
			  id->ptr2=index;
			  read->ptr2=id;
			  read->type=0;
			  break;
		 case 'n':id->Gentry=Glookup(id->name);
			  id->Lentry=Llookup(id->name);
			  if(id->Gentry==NULL&&id->Lentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
			  id->type=(id->Lentry!=NULL)?id->Lentry->type:id->Gentry->type;
			  check_arith(id);
		 	  read->ptr2=id;
			  read->type=0;
			  break;
		}
	}

void built_tree_assign_op(char op_type,struct Tnode* id,struct Tnode* index,struct Tnode* op,struct Tnode* value)
	{int type1,type2;
	 op->nodetype=10;
	 switch(op_type)
		{case 'n':id->Gentry=Glookup(id->name);
		 	  id->Lentry=Llookup(id->name);
	 	 	  if(id->Gentry==NULL&&id->Lentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
		 	  type1=(id->Lentry!=NULL)?id->Lentry->type:id->Gentry->type;
			  type2=value->type;
			  if(type1!=type2)
				{printf("Line %d: type mismatch, assignment operator =\n",yylineno);
				 exit(0);
				}
		 	  op->ptr1=id;
			  op->ptr2=value;
			  op->type=0;
			  break;
		 case 'a':id->Gentry=Glookup(id->name);
		 	  if(id->Gentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
		 	  type1=id->Gentry->type;
			  type2=value->type;
			  check_arith(index);
			  if(type1!=type2)
				{printf("Line %d: type mismatch, assignment operator =\n",yylineno);
				 exit(0);
				}
		 	  op->ptr1=id;
			  id->ptr2=index;
			  op->ptr2=value;
			  op->type=0;
			  break;
		}
	}

void built_tree_stmt(char cnstrt_type,struct Tnode* cnstrt,struct Tnode* expr,struct Tnode* stmt_list1,struct Tnode* stmt_list2)
	{switch(cnstrt_type)
		{case 'i':check_bool(expr);
			  check_void(stmt_list1);
			  cnstrt->ptr1=expr;
			  cnstrt->ptr2=stmt_list1;
			  cnstrt->type=0;
			  break;
		 case 'e':check_bool(expr);
			  check_void(stmt_list1);
			  check_void(stmt_list2);
			  cnstrt->ptr1=expr;
			  cnstrt->ptr2=stmt_list1;
			  cnstrt->ptr3=stmt_list2;
			  cnstrt->type=0;
			  break;
		 case 'w':check_bool(expr);
			  check_void(stmt_list1);
			  cnstrt->ptr1=expr;
			  cnstrt->ptr2=stmt_list1;
			  cnstrt->type=0;
		}
	}

void built_tree_id(char id_type,struct Tnode* id,struct Tnode* expr)
	{switch(id_type)
		{case 'a':id->Gentry=Glookup(id->name);
			  if(id->Gentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
		 	  id->type=id->Gentry->type;
		 	  id->ptr2=expr;
			  break;
		 case 'n':id->Gentry=Glookup(id->name);
		 	  id->Lentry=Llookup(id->name);
	 	 	  if(id->Gentry==NULL&&id->Lentry==NULL)
				{printf("Line %d: variable %s not declared \n",yylineno,id->name);
			 	 exit(0);
				}
		 	  id->type=(id->Lentry!=NULL)?id->Lentry->type:id->Gentry->type;
		 	  break;	
		}
	}

void built_tree_un_op(char op_type,struct Tnode* opr,struct Tnode* oprnd)
	{switch(op_type)
		{case 'a':check_arith(oprnd);
	 		  opr->type=1;
			  break;
		 case 'l':check_bool(oprnd);
	 		  opr->type=2;
			  break;
	 	}
	 opr->ptr2=oprnd;
	}

void built_tree_bin_op(char op_type,struct Tnode* oprnd1,struct Tnode* opr,struct Tnode* oprnd2)
	{switch(op_type)
		{case 'a':check_arith(oprnd1);
	 		  check_arith(oprnd2);
	 		  opr->type=1;
			  break;
		 case 'r':check_arith(oprnd1);
	 		  check_arith(oprnd2);
	 		  opr->type=2;
			  break;
	 	 case 'l':check_bool(oprnd1);
	 		  check_bool(oprnd2);
	 		  opr->type=2;
			  break;
	 	}
	 opr->ptr1=oprnd1;
	 opr->ptr2=oprnd2;
	}

void check_void(struct Tnode* x)
	{switch(x->type)
		{case 1:printf("Line %d: expected void, got integer\n",yylineno);
		 	exit(0);
			break;
		 case 2:printf("Line %d: expected void, got boolean\n",yylineno);
		 	exit(0);
			break;
		}
	}

void check_arith(struct Tnode* x)
	{switch(x->type)
		{case 0:printf("Line %d: expected integer, got void\n",yylineno);
		 	exit(0);
			break;
		 case 2:printf("Line %d: expected integer, got boolean\n",yylineno);
		 	exit(0);
			break;
		}
	}

void check_bool(struct Tnode* x)
	{switch(x->type)
		{case 0:printf("Line %d: expected boolean, got void\n",yylineno);
		 	exit(0);
			break;
		 case 1:printf("Line %d: expected boolean, got integer\n",yylineno);
		 	exit(0);
			break;
		}
	}

void check_arg_match(struct Arg* arg_list_1,struct Arg* arg_list_2)
	{int arg_cmp(struct Arg* arg1,struct Arg* arg2);
	 struct Arg* i =arg_list_1;
	 struct Arg* j =arg_list_2;
	 while(i!=NULL&&j!=NULL)
		{if(arg_cmp(i,j)!=0)
			{break;
			}
		 i=i->next;
		 j=j->next;
		}

	 if(i!=NULL||j!=NULL)
		{printf("Line %d: argument mismatch\n",yylineno);
		 exit(0);
		}	 	
	}

int arg_cmp(struct Arg* arg1,struct Arg* arg2)
	{return ((strcmp(arg1->name,arg2->name)!=0)||(arg1->ref!=arg2->ref)||(arg1->type!=arg2->type));
	}

struct Function* create_function(char* name,int label,int status)
	{struct Function* x=malloc(sizeof(struct Function));
	 x->name=name;
	 x->label=label;
	 x->status=status;
	 return x;
	}

void add_function(char* name)
	{struct Function* create_function(char* name,int label,int status);
	 if(function_head==NULL)
		{struct Function* f=create_function(name,0,0);
	 	 function_head=f;
		}
	 else
		{struct Function* f=create_function(name,function_head->label+1,0);
	 	 struct Function* t=function_head;
		 function_head=f;
		 f->next=t;
		}
	}

int function_set_status(char* name)
	{struct Function* i;
	 for(i=function_head;i!=NULL;i=i->next)
		{if(strcmp(name,i->name)==0)
			{if(i->status==0)
				i->status=1;
			 else
				{printf("Line %d: multiple function definitions for function:%s\n",yylineno,i->name);
			 	 exit(0);
				}
			}
				
		}
	}

int function_lookup(char* name)
	{struct Function* i;
	 for(i=function_head;i!=NULL;i=i->next)
		{if(strcmp(name,i->name)==0)
			return (i->label);
		}
	}

struct Gsymbol *create_Gnode(char* name,int type,int size,struct Arg* arg_list,int binding)
	{struct Gsymbol* x=malloc(sizeof(struct Gsymbol));
	 x->name=malloc(strlen(name));
	 strcpy(x->name,name);
	 x->type=type;
	 x->size=size;
	 x->binding=binding;
	 x->arg_list=arg_list;
	 x->next=NULL;
	 return x;
	}

struct Gsymbol *Glookup(char* name)
	{struct Gsymbol *i;
	 for(i=Ghead;i!=NULL;i=i->next)
		{if(strcmp(name,i->name)==0)
			break;
		}
	 return i;
	}

void Ginstall(char* name,int type,struct Arg* arg_list,int size)
	{struct Gsymbol *create_Gnode(char* name,int type,int size,struct Arg* arg_list,int binding);
	 if(Ghead==NULL)
		{struct Gsymbol *node=create_Gnode(name,type,size,arg_list,0); 
	 	 Ghead=node;
		 g_sp=Ghead->binding+Ghead->size-1;
		}
	 else
		{struct Gsymbol *node=create_Gnode(name,type,size,arg_list,Ghead->binding+Ghead->size); 
	 	 struct Gsymbol *temp;
		 temp=Ghead;
		 Ghead=node;
		 node->next=temp;
	 	 g_sp=Ghead->binding+Ghead->size-1;
		}
	}

struct Lsymbol *create_Lnode(char* name,int type,int binding)
	{struct Lsymbol* x=malloc(sizeof(struct Lsymbol));
	 x->name=malloc(strlen(name));
	 strcpy(x->name,name);
	 x->type=type;
	 x->binding=binding;
	 x->next=NULL;
	 return x;
	}

struct Lsymbol *Llookup(char* name)
	{struct Lsymbol *i;
	 for(i=Lhead;i!=NULL;i=i->next)
		{if(strcmp(name,i->name)==0)
			break;
		}
	 return i;
	}

void Linstall_arg(struct Arg* arg_list)
	{struct Lsymbol *create_Lnode(char* name,int type,int binding);
	 int i=-3;
	 struct Arg* j=arg_list;
	 while(j!=NULL)
		{if(Lhead==NULL)
			{struct Lsymbol *node=create_Lnode(j->name,j->type,i--); 
		 	 Lhead=node;
			}
		 else
			{struct Lsymbol *node=create_Lnode(j->name,j->type,i--); 
		 	 struct Lsymbol *temp;
			 temp=Lhead;
			 Lhead=node;
			 node->next=temp;
			}
		 j=j->next;
		}
	}

void Linstall(char* name,int type)
	{struct Lsymbol *create_Lnode(char* name,int type,int binding);
	 if(Lhead==NULL)
		{struct Lsymbol *node=create_Lnode(name,type,1+REG_NUM);
		 l_sp=1; 
	 	 Lhead=node;
		}
	 else
		{struct Lsymbol *node=create_Lnode(name,type,l_sp=Lhead->binding+1); 
	 	 struct Lsymbol *temp;
		 temp=Lhead;
		 Lhead=node;
		 node->next=temp;
		 l_sp++;
		}
	}

void free_local_decl_list()
	{struct Lsymbol *i=Lhead,*temp;
	 while(i!=NULL)
		{temp=i;
		 i=i->next;
		 free(temp);
		}
	 Lhead=NULL;
	}

void free_arg_decl_list()
	{struct Arg *i=arg_head,*temp;
	 while(i!=NULL)
		{temp=i;
		 i=i->next;
		 free(temp);
		}
	 arg_head=NULL;
	 arg_tail=NULL;
	}

void print_arg_list(struct Arg* head)
	{struct Arg *i=head;
	 printf("\nArg list (name,type):");
	 while(i!=NULL)
		{printf("(%s,%d) ",i->name,i->type);
		 i=i->next;
		}
	}

void print_expr_list(struct Tnode* head)
	{struct Tnode *i=head;
	 printf("\nExpr list (nodetype,type): ");
	 while(i!=NULL)
		{printf("(%d,%d) ",i->nodetype,i->type);
		 i=i->ptr3;
		}
	}

struct Arg *create_Arg(char* name,int type,int ref)
	{struct Arg* x=malloc(sizeof(struct Arg));
	 x->name=malloc(strlen(name));
	 strcpy(x->name,name);
	 x->type=type;
	 x->ref=ref;
	 x->next=NULL;
	}

struct Arg *Arglookup(char* name)
	{struct Arg *i;
	 for(i=arg_head;i!=NULL;i=i->next)
		{if(strcmp(name,i->name)==0)
			break;
		}
	 return i;
	}

void Arginstall(char* name,int type,int ref)
	{struct Arg *create_Arg(char* name,int type,int ref);
	 if(arg_head==NULL)
		{struct Arg *node=create_Arg(name,type,ref); 
	 	 arg_head=node;
		 arg_tail=node;
		}
	 else
		{struct Arg *node=create_Arg(name,type,ref); 
	 	 arg_tail->next=node;
		 arg_tail=node;
		}
	}

int assign_label()
	{return(label_last++);
	}

void store(int reg)
	{fprintf(fp,"PUSH R%d\n",reg);
	}

int assign_reg()
	{void store(int reg);
	 if(reg_last>=REG_NUM)
	 	store(reg_last%REG_NUM);
	 return ((reg_last++)%REG_NUM);
	}

void restore(int reg)
	{fprintf(fp,"POP R%d\n",reg);
	}

void free_reg()
	{void restore(int reg);
	 reg_last--;
	 if(reg_last>=REG_NUM)
		restore(reg_last%REG_NUM);	
	}


int create_SIM(struct Tnode* x)
	{int assign_reg();
	 int assign_label();
	 void free_reg();
	 int create_SIM_CONST(struct Tnode* x);
	 int create_SIM_Variable(struct Tnode* x);
	 int create_SIM_read(struct Tnode* x);
	 int create_SIM_write(struct Tnode* x);
	 int create_SIM_if(struct Tnode* x);
	 int create_SIM_while(struct Tnode* x);
	 int create_SIM_assignment(struct Tnode* x);
	 int create_SIM_bin_op(char op,char opr_class,struct Tnode* x);
	 int create_SIM_un_minus(struct Tnode* x);
	 int create_SIM_arith_operation(struct Tnode* x);
	 int create_SIM_relational_operation(struct Tnode* x);
	 int create_SIM_logical_operation(struct Tnode* x);
	 int create_SIM_dummy(struct Tnode* x);
	 int create_SIM_function_call(struct Tnode* x);
	 int create_SIM_return(struct Tnode* x);
	 if(x!=NULL)
		{switch(x->nodetype)
			{case 0 : return create_SIM_dummy(x);
			 case 1 : return create_SIM_CONST(x); 
			 case 2 : return create_SIM_Variable(x);
			 case 3 : return create_SIM_arith_operation(x);
			 case 4 : return create_SIM_read(x);
			 case 5 : return create_SIM_write(x);
			 case 6 : return create_SIM_if(x);
			 case 7 : return create_SIM_while(x);
			 case 8 : return create_SIM_relational_operation(x);
			 case 9 : return create_SIM_logical_operation(x);
			 case 10: return create_SIM_assignment(x);
			 case 11: return create_SIM_function_call(x);
			 case 12: return create_SIM_return(x);
			}
		}
	}

int generate_code_function(struct Tnode* x)
	{int func_label=function_lookup(current_func->name);
	 fprintf(fp,"F%d:\n",func_label);
	 fprintf(fp,"PUSH BP\n");
	 fprintf(fp,"MOV BP,SP\n");

	 int k;
	 for(k=0;k<REG_NUM;++k)
		 fprintf(fp,"PUSH R%d\n",k);

	 int reg_1=assign_reg();
	 int reg_2=assign_reg();
	 fprintf(fp,"MOV R%d,SP\n",reg_1);
	 fprintf(fp,"MOV R%d,%d\n",reg_2,l_sp);
	 fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
	 fprintf(fp,"MOV SP,R%d\n",reg_1);
	 free_reg();
	 free_reg();
	 create_SIM(x);
	 fprintf(fp,"\n");
	}

int generate_code_main(struct Tnode* x)
	{fprintf(fp,"START\n");
	 fprintf(fp,"MOV SP,%d\n",g_sp);
	 fprintf(fp,"MOV BP,%d\n",g_sp);
	 int reg_1=assign_reg();
	 int reg_2=assign_reg();
	 fprintf(fp,"MOV R%d,SP\n",reg_1);
	 fprintf(fp,"MOV R%d,%d\n",reg_2,l_sp);
	 fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
	 fprintf(fp,"MOV SP,R%d\n",reg_1);
	 free_reg();
	 free_reg();
	 create_SIM(x);
	 fprintf(fp,"HALT\n");
	}

int create_SIM_function_call(struct Tnode* x)
	{int func_label=function_lookup(x->name);
	 struct Tnode *i=x->ptr2;
	 int arg_count=0;
	 while(i!=NULL)
		{int reg=create_SIM(i);
		 fprintf(fp,"PUSH R%d\n",reg);
		 arg_count++;
		 free_reg();
		 i=i->ptr3;
		}

	 fprintf(fp,"PUSH R0\n");
	 fprintf(fp,"CALL F%d\n",func_label);
	 int reg_1=assign_reg();
	 fprintf(fp,"POP R%d\n",reg_1);

	 int reg_2=assign_reg();

	 struct Arg* arg_list_i=Glookup(x->name)->arg_list;
	 struct Tnode* expr_list=reverse_expr_list(x->ptr2);


	 struct Tnode* expr_list_i=expr_list;

	 int t=0;
	 while(arg_list_i!=NULL)
		{fprintf(fp,"POP R%d\n",reg_2);
		 if(arg_list_i->ref)
			{if(expr_list_i->Lentry!=NULL)
			 	{int reg_3=assign_reg();
				 int reg_4=assign_reg();
				 fprintf(fp,"MOV R%d,%d\n",reg_3,expr_list_i->Lentry->binding);
				 fprintf(fp,"MOV R%d,BP\n",reg_4);
				 fprintf(fp,"ADD R%d,R%d\n",reg_3,reg_4);
				 fprintf(fp,"MOV [R%d],R%d\n",reg_3,reg_2);
				 free_reg();
				 free_reg();
				}
			  else
			 	fprintf(fp,"MOV [%d],R%d\n",expr_list_i->Gentry->binding,reg_2);
			}
		 arg_list_i=arg_list_i->next;
		 expr_list_i=expr_list_i->ptr3;
		}
	 
	 free_reg();
//	 free_expr_list(expr_list);

	 return reg_1;
	}

int create_SIM_return(struct Tnode* x)
	{if(current_func==NULL)
		return 0;
	 int reg_1=create_SIM(x->ptr2);
	 int reg_2=assign_reg();
	 int reg_3=assign_reg();
	 fprintf(fp,"MOV R%d,-2\n",reg_2);
	 fprintf(fp,"MOV R%d,BP\n",reg_3);
 	 fprintf(fp,"ADD R%d,R%d\n",reg_2,reg_3);
	 fprintf(fp,"MOV [R%d],R%d\n",reg_2,reg_1); 

	 fprintf(fp,"MOV R%d,%d\n",reg_2,REG_NUM);
 	 fprintf(fp,"ADD R%d,R%d\n",reg_2,reg_3);
	 fprintf(fp,"MOV SP,R%d\n",reg_2);

	 int k;
	 for(k=REG_NUM-1;k>=0;--k)
		 fprintf(fp,"POP R%d\n",k);

	 fprintf(fp,"POP BP\n"); 	 
	 fprintf(fp,"RET\n");
	 free_reg();
	 free_reg();
	 free_reg();
	}

int create_SIM_dummy(struct Tnode* x)
	{create_SIM(x->ptr1);
	 create_SIM(x->ptr2);
	}

int create_SIM_bin_op(char op,char opr_class,struct Tnode* x)
	{int reg_1=create_SIM(x->ptr1);
	 int reg_2=create_SIM(x->ptr2);
	 switch(opr_class)
		{case 'a': switch(op)
				{case '+': fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case '-': fprintf(fp,"SUB R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case '*': fprintf(fp,"MUL R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case '/': fprintf(fp,"DIV R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case '%': fprintf(fp,"MOD R%d,R%d\n",reg_1,reg_2);
	 				   break;
				}
			   break;
		 case 'r': switch(op)
				{case 'a': fprintf(fp,"LT R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case 'b': fprintf(fp,"LE R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case 'c': fprintf(fp,"GT R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case 'd': fprintf(fp,"GE R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case 'e': fprintf(fp,"EQ R%d,R%d\n",reg_1,reg_2);
	 				   break;
				 case 'f': fprintf(fp,"NE R%d,R%d\n",reg_1,reg_2);
	 				   break;
				}
			   break;
		}
	 free_reg();
	 return reg_1;
	}

int create_SIM_AND(struct Tnode* x)
	{int label_1=assign_label();
	 int reg_1=create_SIM(x->ptr1);
	 fprintf(fp,"JZ R%d,L%d\n",reg_1,label_1);
	 int reg_2=create_SIM(x->ptr2);
	 fprintf(fp,"MOV R%d,R%d\n",reg_1,reg_2);
	 fprintf(fp,"L%d:\n",label_1);
	 free_reg();
	 return reg_1;
	}

int create_SIM_OR(struct Tnode* x)
	{int label_1=assign_label();
	 int reg_1=create_SIM(x->ptr1);
	 fprintf(fp,"JNZ R%d,L%d\n",reg_1,label_1);
	 int reg_2=create_SIM(x->ptr2);
	 fprintf(fp,"MOV R%d,R%d\n",reg_1,reg_2);
	 fprintf(fp,"L%d:\n",label_1);
	 free_reg();
	 return reg_1;
	}

int create_SIM_NOT(struct Tnode* x)
	{int label_1=assign_label();
	 int label_2=assign_label();
	 int reg_1=create_SIM(x->ptr2);
	 fprintf(fp,"JZ R%d,L%d\n",reg_1,label_1);
	 fprintf(fp,"MOV R%d,0\n",reg_1);
	 fprintf(fp,"JMP L%d\n",label_2);
	 fprintf(fp,"L%d:\n",label_1);
	 fprintf(fp,"MOV R%d,1\n",reg_1);
	 fprintf(fp,"L:%d\n",label_2);
    	 return reg_1;
	 }
					  
int create_SIM_un_minus(struct Tnode* x)
	{int reg_1=create_SIM(x->ptr2);
	 int reg_2=assign_reg();
	 fprintf(fp,"MOV R%d,-1\n",reg_2);
	 fprintf(fp,"MUL R%d,R%d\n",reg_1,reg_2);
	 free_reg();
	 return reg_1;
	}

int create_SIM_CONST(struct Tnode* x)
	{int reg=assign_reg();
	 fprintf(fp,"MOV R%d,%d\n",reg,x->value);
	 return reg;
	}

int create_SIM_Variable(struct Tnode* x)
	{if(x->ptr2==NULL)
		{int reg=assign_reg();
		 if(x->Lentry!=NULL)
		 	{int reg_1=assign_reg();
			 int reg_2=assign_reg();
			 fprintf(fp,"MOV R%d,%d\n",reg_1,x->Lentry->binding);
			 fprintf(fp,"MOV R%d,BP\n",reg_2);
			 fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
			 fprintf(fp,"MOV R%d,[R%d]\n",reg,reg_1);
			 free_reg();
			 free_reg();
			}
		 else
		 	fprintf(fp,"MOV R%d,[%d]\n",reg,x->Gentry->binding);
		 return reg;
	 	}
	  else
		{int reg_1=create_SIM(x->ptr2);
		 int reg_2=assign_reg();
		 fprintf(fp,"MOV R%d,%d\n",reg_2,x->Gentry->binding);
		 fprintf(fp,"ADD R%d,R%d\n",reg_2,reg_1);
		 fprintf(fp,"MOV R%d,[R%d]\n",reg_1,reg_2);
		 free_reg();
		 return reg_1;
		}
	}

int create_SIM_read(struct Tnode* x)
	{int reg=assign_reg();
	 fprintf(fp,"IN R%d\n",reg);
	 if(x->ptr2->ptr2==NULL)
		{if(x->ptr2->Lentry!=NULL)
			{int reg_1=assign_reg();
			 int reg_2=assign_reg();
			 fprintf(fp,"MOV R%d,%d\n",reg_1,x->ptr2->Lentry->binding);
			 fprintf(fp,"MOV R%d,BP\n",reg_2);
			 fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
			 fprintf(fp,"MOV [R%d],R%d\n",reg_1,reg);
			 free_reg();
			 free_reg();
			}
		 else
			fprintf(fp,"MOV [%d],R%d\n",x->ptr2->Gentry->binding,reg);
		}
	  else
		{int reg_1=create_SIM(x->ptr2->ptr2);
		 int reg_2=assign_reg();
		 fprintf(fp,"MOV R%d,%d\n",reg_2,x->ptr2->Gentry->binding);
		 fprintf(fp,"ADD R%d,R%d\n",reg_2,reg_1);
		 fprintf(fp,"MOV [R%d],R%d\n",reg_2,reg);	    
	    	 free_reg();
		 free_reg();
	 	}
	 free_reg();
	}

int create_SIM_write(struct Tnode* x)
	{int reg=create_SIM(x->ptr2);
	 fprintf(fp,"OUT R%d\n",reg);
	 free_reg();
	}

int create_SIM_if(struct Tnode* x)
	{if(x->ptr3==NULL)
		{int reg=create_SIM(x->ptr1);
		 int label_1=assign_label();
		 fprintf(fp,"JZ R%d,L%d\n",reg,label_1);
		 create_SIM(x->ptr2);
		 fprintf(fp,"L%d:\n",label_1);
		 free_reg();
		 }
	 else
		 {int reg=create_SIM(x->ptr1);
		  int label_1=assign_label();
		  int label_2=assign_label();
		  fprintf(fp,"JZ R%d,L%d\n",reg,label_1);
		  create_SIM(x->ptr2);
		  fprintf(fp,"JMP L%d\n",label_2);
		  fprintf(fp,"L%d:\n",label_1);
		  create_SIM(x->ptr3);
		  fprintf(fp,"L%d:\n",label_2);
		  free_reg();
		 }
	}	

int create_SIM_while(struct Tnode* x)
	{int label_1=assign_label();
	 int label_2=assign_label();
	 fprintf(fp,"L%d:\n",label_1);
	 int reg=create_SIM(x->ptr1);
	 fprintf(fp,"JZ R%d,L%d\n",reg,label_2);
	 create_SIM(x->ptr2);
	 fprintf(fp,"JMP L%d\n",label_1);
	 fprintf(fp,"L%d:\n",label_2);
	 free_reg();
	}

int create_SIM_assignment(struct Tnode* x)
	{int reg=create_SIM(x->ptr2);
	 if(x->ptr1->ptr2==NULL)
		{if(x->ptr1->Lentry!=NULL)
			{int reg_1=assign_reg();
			 int reg_2=assign_reg();
			 fprintf(fp,"MOV R%d,%d\n",reg_1,x->ptr1->Lentry->binding);
			 fprintf(fp,"MOV R%d,BP\n",reg_2);
			 fprintf(fp,"ADD R%d,R%d\n",reg_1,reg_2);
			 fprintf(fp,"MOV [R%d],R%d\n",reg_1,reg);
			 free_reg();
			 free_reg();
			}
		 else
			fprintf(fp,"MOV [%d],R%d\n",x->ptr1->Gentry->binding,reg);
		}
	 else
		{int reg_1=create_SIM(x->ptr1->ptr2);
		 int reg_2=assign_reg();
		 fprintf(fp,"MOV R%d,%d\n",reg_2,x->ptr1->Gentry->binding);
		 fprintf(fp,"ADD R%d,R%d\n",reg_2,reg_1);
		 fprintf(fp,"MOV [R%d],R%d\n",reg_2,reg);	    
		 free_reg();
		 free_reg();
		}
 	 free_reg();
	}

int create_SIM_arith_operation(struct Tnode* x)
	{if(x->op=='-'&&x->ptr1==NULL)
		return create_SIM_un_minus(x);
	 return create_SIM_bin_op(x->op,'a',x);
	}

int create_SIM_relational_operation(struct Tnode* x)
	{return create_SIM_bin_op(x->op,'r',x);
	}

int create_SIM_logical_operation(struct Tnode* x)
	{int create_SIM_AND(struct Tnode* x);
	 int create_SIM_OR(struct Tnode* x);
	 int create_SIM_NOT(struct Tnode* x);

	 switch(x->op)
		{case 'a':return create_SIM_AND(x);
			  break;
		 case 'b':return create_SIM_OR(x);
			  break;
		 case 'c':return create_SIM_NOT(x);
			  break;
		}
	}

void yyerror(char *s)
	 {fprintf(stderr,"Line %d: %s\n",yylineno,s);
	  exit(0);
	 }



