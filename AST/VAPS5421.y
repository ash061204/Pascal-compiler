%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<limits.h>
    #include<string.h>
    #include<ctype.h>
    #include "graph.c"
    extern FILE *yyin;
    int yylex();
    int ex (nodeType *p, int flag);
	/* function prototype to create a node for an operation */ 
	nodeType *opr(int oper, int nops, ...);
	/* function prototype to create a node for an identifier */
	nodeType *id(char *identifier);
	/* function prototype to create a node for a constat */
	nodeType *con(char *value);

%}

%union{
    int ival;
    nodeType *nPtr;
    char string[100];
} 

%left OR
%left AND
%right NOT
%left MOD
%left PLUS MINUS '-'
%left MUL DIV
%right UMINUS
%token PROG NUL DOWNTO UMINUS PROGRAM SC TYPE EQ OF COMMENT COLON BEG READ OB CB WRITE COMMA FOR ASSIGN DO
%token  VAR NOTEQ LT GT GTEQ LTEQ PLUS MINUS MUL DIV MOD AND OR NOT IF THEN ELSE END DOT INT REAL CHAR BOOLEAN TO WHILE ARRAY OPENBRAC CLOSEBRAC OPENPARA CLOSEPARA
%token <string> ARR ID INT_LITERAL STRING CHAR_LITERAL REAL_LITERAL BOOLEAN_LITERAL
%type <nPtr> var_dec_sec main_prog_block var_dec_list var_dec id_list stmt_block stmt read_stmt write_stmt write_param conditional_stmt loop_stmt assign_stmt expr term factor
%type <nPtr> bool_expr read_id read_list value program e v
%%

start : program {ex($1, 0);}
      ;

program : PROGRAM program_name SC var_dec_sec main_prog_block {$$ = opr(PROG, 2, $4, $5);}
        ;

program_name : ID
             ;

var_dec_sec : VAR var_dec_list SC {$$ = $2;}
            ;

var_dec_list : var_dec {$$ = $1;}
             | var_dec_list SC var_dec {$$ = opr(';', 2, $1, $3);}
             ;

var_dec : id_list COLON type {$$ = $1;}
        ;

id_list : ID {$$ = id($1);}
        | id_list COMMA ID  {$$ = opr(',', 2, $1, id($3));}
        | ARR {$$ = id($1);}
        ;

type : INT 
     | REAL
     | CHAR
     | BOOLEAN
     | ARRAY OPENBRAC value DOT DOT value CLOSEBRAC OF type
     ;

main_prog_block : BEG stmt_block END DOT {$$=$2;}
                ;
stmt_block : stmt {$$ = opr(';', 1, $1);}
           | stmt stmt_block {$$ = opr(';', 2, $1, $2);}
           ;
stmt :  read_stmt SC {$$ = $1;}
     |  write_stmt SC {$$ = $1;}
     |  loop_stmt SC {$$ = $1;}
     |  assign_stmt SC {$$ = $1;}
     | conditional_stmt SC {$$ = $1;}
     ;

assign_stmt :  ARR ASSIGN expr {$$ = opr('=', 2, id($1), $3);}
            |  ID ASSIGN expr {$$ = opr('=', 2, id($1), $3);}

expr : expr PLUS term {$$ = opr('+', 2, $1, $3);}
     | expr MINUS term {$$ = opr('-', 2, $1, $3);}
     | term {$$ = $1;}
     ;
term : term MUL factor  {$$ = opr('*', 2, $1, $3);}
     | term DIV factor  {$$ = opr('/', 2, $1, $3);}
     | term MOD factor  {$$ = opr('%', 2, $1, $3);}
     | factor {$$ = $1;}
    
     ;

factor :  ID {$$ = id($1);}
       | value {$$ = $1;}
       |  OB expr CB {$$ = $2;}
       | ARR {$$ = id($1);}
        | MINUS factor %prec UMINUS {$$=opr('-',1,$2);}
       ;

value : INT_LITERAL {$$ = con($1);}
      | REAL_LITERAL {$$ = con($1);}
      | BOOLEAN_LITERAL {$$ = con($1);}
      | CHAR_LITERAL {$$ = con($1);}
      | STRING {$$ = con($1);}
      ;
conditional_stmt : IF bool_expr THEN BEG stmt_block END {$$ = opr(IF,2, $2, opr(THEN, 1, $5));}
                 | IF bool_expr THEN BEG stmt_block END ELSE BEG stmt_block END {$$ = opr(IF, 3, $2, opr(THEN, 1, $5), opr(ELSE, 1, $9));}
                 | IF v THEN BEG stmt_block END {$$ = opr(IF,2, $2, opr(THEN, 1, $5));}
                 | IF v THEN BEG stmt_block END ELSE BEG stmt_block END {$$ = opr(IF, 3, $2, opr(THEN, 1, $5), opr(ELSE, 1, $9));}
                 ; 




bool_expr: expr EQ expr {$$ = opr(EQ, 2, $1, $3);}
         | expr NOTEQ expr {$$ = opr(NOTEQ, 2, $1, $3);}
         | expr LT expr {$$ = opr(LT, 2, $1, $3);}
         |expr GT expr {$$ = opr(GT, 2, $1, $3);}
         | expr LTEQ expr {$$ = opr(LTEQ, 2, $1, $3);}
         | expr GTEQ expr {$$ = opr(GTEQ, 2, $1, $3);}
         | OB bool_expr CB  {$$ = $2;}
         | NOT bool_expr {$$=opr(NOT,1,$2);}
         | bool_expr AND bool_expr {$$ = opr(AND, 2, $1, $3);}
         | bool_expr OR bool_expr  {$$ = opr(OR, 2, $1, $3);}
          | v OR v {$$ = opr(OR, 2, $1, $3);}
         | v AND v {$$ = opr(AND, 2, $1, $3);}
         | bool_expr OR v {$$ = opr(OR, 2, $1, $3);}
        | v OR bool_expr {$$ = opr(OR, 2, $1, $3);}
        | v AND bool_expr {$$ = opr(AND, 2, $1, $3);}
        | bool_expr AND v {$$ = opr(AND, 2, $1, $3);}
        | NOT v {$$=opr(NOT,1,$2);}
        | expr EQ e {$$ = opr(EQ, 2, $1, $3);}
        ;
e : NOT expr {$$=opr(NOT,1,$2);}
v : ID {$$ = id($1);}
    | OB ID CB {$$ = id($2);}
    | ARR {$$ = id($1);}
    | OB ARR CB {$$ = id($2);}
    ;   
         ;


loop_stmt :  WHILE bool_expr DO BEG stmt_block END {$$ = opr(WHILE, 2, $2, opr(DO, 1, $5));}
            |  WHILE v DO BEG stmt_block END {$$ = opr(WHILE, 2, $2, opr(DO, 1, $5));}
          | FOR ID ASSIGN expr TO expr DO BEG stmt_block END {$$ = opr(FOR, 3, opr('=', 2, id($2), $4), opr(LTEQ, 2,id($2),$6), opr(DO, 1, $9));}
          |  FOR ID ASSIGN expr DOWNTO expr DO BEG stmt_block END {$$ = opr(FOR, 3, opr('=', 2, id($2), $4), opr(GTEQ, 2,id($2),$6), opr(DO, 1, $9));}
          | FOR ARR ASSIGN expr TO expr DO BEG stmt_block END {$$ = opr(FOR, 3, opr('=', 2, id($2), $4), opr(LTEQ, 2,id($2),$6), opr(DO, 1, $9));}
          |  FOR ARR ASSIGN expr DOWNTO expr DO BEG stmt_block END {$$ = opr(FOR, 3, opr('=', 2, id($2), $4), opr(GTEQ, 2,id($2),$6), opr(DO, 1, $9));}
          ;

read_stmt : READ OB read_list CB {$$ = opr(READ, 1, $3);}
          ;
read_list : read_id {$$=$1;}
            | read_id COMMA read_list {$$ = opr(',', 2, $1, $3);}
            ;
read_id : ID {$$ = id($1);}
        | ARR {$$ = id($1);}
        ;
write_stmt :  WRITE OB write_param CB {$$ = opr(WRITE, 1, $3);}
              ;  

write_param : ID {$$ = id($1);}
            | value {$$ = $1;}
            | ID COMMA write_param {$$ = opr(',', 2, id($1), $3);}
            |ARR {$$ = id($1);}
            ;

%%

void yyerror()
{
    //printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main()
{
    yyin = fopen("input.txt","r");
    yyparse();
    //printTable();
    return 0;
}

nodeType *con(char *value)
{
    
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
    if(value[0]=='"')
    {
        strcpy(p->con.value, "string");
    }
    else
	   strcpy(p->con.value, value);
    //printf("The copied value %s\n", p->con.value);
	return p;
}
nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}

