%{
struct Tnode
	{int type;
	 int nodetype;//opr 3,read 4, write 5, id 2,constant 1, void 0, 6 if,7 while, 8 rel op,9 log op,10 assign op, 11 func
	 char op;
	 char* name;
	 int value;
	 struct Arg *arg_list;
	 struct Gsymbol *Gentry;
	 struct Lsymbol *Lentry; 
	 struct Tnode *ptr1,*ptr2,*ptr3;
	};


void yyerror(char *);
struct Tnode* allocate(int type,int nodetype,char op,char* name,int value);	
#include "y.tab.h"
#include<string.h>
%}

LETTER	[a-zA-Z]
NUM	[0-9]
%%
[\n]				{yylineno++;
				}
[ \t]				;
"//".*				;
{NUM}+				{yylval.x=allocate(1,1,0,NULL,atoi(yytext));
				 return INT_VAL;
				}
true				{yylval.x=allocate(2,1,0,NULL,1);
				 return BOOL_VAL;
				}
false				{yylval.x=allocate(2,1,0,NULL,0);
				 return BOOL_VAL;
				}
[-+*/=%]			{yylval.x=allocate(0,3,*yytext,NULL,-1);
				 return *yytext;
				}
"<"				{yylval.x=allocate(0,8,'a',NULL,-1);
				 return LT;
				}
"<="				{yylval.x=allocate(0,8,'b',NULL,-1);
				 return LE;
				}
">"				{yylval.x=allocate(0,8,'c',NULL,-1);
				 return GT;
				}
">="				{yylval.x=allocate(0,8,'d',NULL,-1);
				 return GE;
				}
"=="				{yylval.x=allocate(0,8,'e',NULL,-1);
				 return EQ;
				}
"!="				{yylval.x=allocate(0,8,'f',NULL,-1);
				 return NE;
				}
AND				{yylval.x=allocate(0,9,'a',NULL,-1);
				 return AND;
				}
OR				{yylval.x=allocate(0,9,'b',NULL,-1);
				 return OR;
				}
NOT				{yylval.x=allocate(0,9,'c',NULL,-1);
				 return NOT;
				}
[{}();,\[\]&]			return *yytext;
decl				return DECL;
enddecl				return ENDDECL;
begin				return BEG;
end				return END;
main				return MAIN;
return				{yylval.x=allocate(0,12,0,NULL,-1);
				 return RETURN;
				}
integer				return INT_TYPE;
boolean				return BOOL_TYPE;
read				{yylval.x=allocate(0,4,0,NULL,-1);
				 return READ;
				}
write				{yylval.x=allocate(0,5,0,NULL,-1);
				 return WRITE;
				}
if				{yylval.x=allocate(0,6,0,NULL,-1);
				 return IF;
				}
then				{return THEN;
				}
else				{return ELSE;
				}
endif				{return ENDIF;
				}
while				{yylval.x=allocate(0,7,0,NULL,-1);
				 return WHILE;
				}
do				{return DO;
				}
endwhile			{return ENDWHILE;
				}
{LETTER}+({LETTER}|{NUM})*	{
				 char *temp=malloc(yyleng+1);
				 strcpy(temp,yytext);
				 yylval.x=allocate(0,2,0,temp,-1);
				 return ID;
				}	 		
.				printf("Invalid character");
%%

struct Tnode* allocate(int type,int nodetype,char op,char* name,int value)
	{struct Tnode* x=malloc(sizeof(struct Tnode));
	 x->type=type;
	 x->nodetype=nodetype;
	 x->op=op;
	 x->name=name;
	 x->value=value;
	 x->ptr3=NULL;
	 x->ptr2=NULL;
	 x->ptr1=NULL;
	 x->arg_list=NULL;
	 x->Gentry=NULL;
	 x->Lentry=NULL;
	 return x;
	}

int yywrap()
	 {return 1;
	 }

int main(int argc, char *argv[])
	{yyin=fopen(argv[1],"r");
	 yyparse();
	 fclose(yyin);
	 return 0;
	}
