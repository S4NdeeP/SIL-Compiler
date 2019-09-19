%{
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
%}

%union  {struct Tnode* x;
	}

%token <x> INT_VAL ID READ WRITE IF ELSE ENDIF WHILE ENDWHILE THEN DO DECL ENDDECL INT_TYPE BOOL_TYPE BOOL_VAL BEG END RETURN MAIN
%nonassoc '&'
%nonassoc '{' '}'
%nonassoc '[' ']'
%nonassoc '(' ')'
%right <x> '='
%left <x> AND OR NOT
%left <x> EQ NE
%left <x> LT LE GT GE 
%left <x> '+' '-'
%left <x> '*' '/' '%'
%left UMINUS
%type <x> program stmt_list stmt expr error type g_id g_id_list g_decl_list g_decl g_decl_block f_def_list f_def main_block arg_list 
%type <x> l_id l_id_list l_decl_list l_decl l_decl_block body arg arg_id arg_id_list expr_list ret_stmt
%%

program:	g_decl_block f_def_list main_block
			{fclose(fp);
			}
		;
g_decl_block: 	DECL g_decl_list ENDDECL
			{$$=$2;
			 fp=fopen("a.sim","w");
			}
		;
g_decl_list:	 
		|g_decl_list g_decl
		;

g_decl:		type g_id_list ';'
		;

g_id_list: 	g_id_list ',' g_id
		|g_id
		;

g_id:		ID
			{if(Glookup($1->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,$1->name);
			 	 exit(0);
				}
			 Ginstall($1->name,Type,NULL,1);
			} 
		|ID '[' INT_VAL ']'
			{if(Glookup($1->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,$1->name);
			 	 exit(0);
				}
			 Ginstall($1->name,Type,NULL,$3->value);
			}
		|ID 
			{FuncRetType=Type;
			}
		'(' arg_list ')'
			{if(Glookup($1->name)!=NULL)
				{printf("Line %d: function %s already declared \n",yylineno,$1->name);
			 	 exit(0);
				}
			 Ginstall($1->name,FuncRetType,arg_head,0);
			 arg_head=NULL;
			 arg_tail=NULL;
			 add_function($1->name);
			}
		;

f_def_list:	
		|f_def_list f_def
		;

f_def:		type ID 
			{current_func=Glookup($2->name);
			 if(current_func->type!=Type)
				{printf("Line %d: function %s return type mismatch \n",yylineno,$2->name);
			  	 exit(0);
				}
			  
			}
		'(' arg_list ')'
			 {if(current_func==NULL)
				{printf("Line %d: function %s not declared \n",yylineno,$2->name);
			  	 exit(0);
				}
			  check_arg_match(arg_head,Glookup($2->name)->arg_list);
			  function_set_status($2->name);
			 }

		'{' l_decl_block 
			{Linstall_arg(Glookup($2->name)->arg_list);
			}		
		body '}'
			 {generate_code_function($11);
			  free_local_decl_list();
			  free_arg_decl_list();
			  l_sp=0;
			 }
			
		;

		;

arg_list:	
		|arg
		|arg_list ';' arg
		;

arg:		type arg_id_list
		;

arg_id_list: 	arg_id_list ',' arg_id
		|arg_id
		;

arg_id:		ID
			{if(Arglookup($1->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,$1->name);
			 	 exit(0);
				}
			 Arginstall($1->name,Type,0);
			} 
		|'&' ID
			{if(Arglookup($2->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,$2->name);
			 	 exit(0);
				}
			 Arginstall($2->name,Type,1);
			 $$=$2;
			} 
		;
		
main_block :	INT_TYPE MAIN '(' ')' '{' l_decl_block body '}'
			{current_func=NULL;
			 generate_code_main($7);
			 Lhead=NULL;
			 l_sp=0;
			}
		;

body : 		BEG stmt_list ret_stmt END
			{struct Tnode* dum=allocate(0,0,0,NULL,-1);
	 		 dum->ptr2=$3;
	 		 dum->ptr1=$2;
			 $$=dum;
			}
		;

ret_stmt:	RETURN expr ';'
			{built_tree_return($1,$2);
			 $$=$1;
			}
		;

l_decl_block: 	DECL l_decl_list ENDDECL
			{$$=$2;
			}
		;
l_decl_list:	 
		|l_decl_list l_decl
		;

l_decl:		type l_id_list ';'
		;

l_id_list: 	l_id_list ',' l_id
		|l_id
		;

l_id:		ID
			{if(Llookup($1->name)!=NULL||Arglookup($1->name)!=NULL)
				{printf("Line %d: variable %s already declared \n",yylineno,$1->name);
			 	 exit(0);
				}
			 Linstall($1->name,Type);
			} 
		;
 
type: 		INT_TYPE
			{Type=1;
			}
		|BOOL_TYPE
			{Type=2;
			}
		;

stmt_list:	 stmt_list stmt
	 		{struct Tnode* dum=allocate(0,0,0,NULL,-1);
	 		 dum->ptr2=$2;
	 		 dum->ptr1=$1;
			 $$=dum;
			}
		 |
			{$$=NULL;
			}
		;

stmt:		ID '=' expr ';'
		 	{built_tree_assign_op('n',$1,NULL,$2,$3);
			 $$=$2;
			}
		|ID '[' expr ']' '=' expr ';'
		 	{built_tree_assign_op('a',$1,$3,$5,$6);
			 $$=$5;
			}
		|READ '(' ID ')' ';'	
			{$$=$1;
			 built_tree_read('n',$1,$3,NULL);
			}
		|READ '(' ID '[' expr ']' ')' ';'	
			{$$=$1;
			 built_tree_read('a',$1,$3,$5);
			}
		|WRITE '(' expr ')' ';'
			{built_tree_write($1,$3);
			 $$=$1;
			}
		|IF '(' expr ')' THEN stmt_list ENDIF ';'
			{built_tree_stmt('i',$1,$3,$6,NULL);
			 $$=$1;
			}
		|IF '(' expr ')' THEN stmt_list ELSE stmt_list ENDIF ';'
			{built_tree_stmt('e',$1,$3,$6,$8);
			 $$=$1;
			}
		|WHILE '(' expr ')' DO stmt_list ENDWHILE ';'
			{built_tree_stmt('w',$1,$3,$6,NULL);
			 $$=$1;
			}
		| error ';'
		;

expr_list:	
			{$$=NULL;
			}
		|expr
			{$$=$1;
			}
		|expr_list ',' expr
			{$3->ptr3=$1;
			 $$=$3;
			}
		;
	
expr:		expr '+' expr	
			{built_tree_bin_op('a',$1,$2,$3);
			 $$=$2;
			}
		|expr '*' expr	
			{built_tree_bin_op('a',$1,$2,$3);
			 $$=$2;
			}
		|expr '-' expr	
			{built_tree_bin_op('a',$1,$2,$3);
			 $$=$2;
			}
		|expr '/' expr	
			{built_tree_bin_op('a',$1,$2,$3);
			 $$=$2;
			}
		|expr '%' expr	
			{built_tree_bin_op('a',$1,$2,$3);
			 $$=$2;
			}
		|'-' expr
			{built_tree_un_op('a',$1,$2);
			 $$=$1;
			}
		 %prec UMINUS
		|'(' expr ')'
			{$$=$2;}
		|expr LT expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr LE expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr GT expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr GE expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr EQ expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr NE expr	
			{built_tree_bin_op('r',$1,$2,$3);
			 $$=$2;
			}
		|expr AND expr	
			{built_tree_bin_op('l',$1,$2,$3);
			 $$=$2;
			}
		|expr OR expr	
			{built_tree_bin_op('l',$1,$2,$3);
			 $$=$2;
			}
		|NOT expr	
			{built_tree_un_op('l',$1,$2);
			 $$=$1;
			}
		|INT_VAL
		 	{$$=$1;}
		|BOOL_VAL
		 	{$$=$1;}
		|ID '[' expr ']'
			{built_tree_id('a',$1,$3);
			 $$=$1;
			}
		|ID	
			{built_tree_id('n',$1,NULL);
			 $$=$1;
			}
		|ID '(' expr_list ')'
			{built_tree_function($1,$3);
			 $$=$1;
			}
		;

%%

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


