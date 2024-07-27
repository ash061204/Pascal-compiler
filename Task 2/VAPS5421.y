%{
    #include<math.h>
    #include<string.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    void printTable();
    int x=0;
    extern FILE *yyin;

%}
%left OR
%left AND
%right NOT
%left MOD
%left PLUS MINUS '-'
%left MUL DIV
%right UMINUS
%token DOWNTO UMINUS PROGRAM ID SC TYPE EQ ARR OF COMMENT COLON BEG READ OB CB WRITE STRING COMMA FOR ASSIGN DO INT_LITERAL REAL_LITERAL BOOLEAN_LITERAL CHAR_LITERAL
%token VAR NOTEQ LT GT GTEQ LTEQ PLUS MINUS MUL DIV MOD AND OR NOT IF THEN ELSE END DOT INT REAL CHAR BOOLEAN TO WHILE ARRAY OPENBRAC CLOSEBRAC OPENPARA CLOSEPARA

%%

start : program { printf("Valid Input!\n"); }
      ;

program : PROGRAM program_name SC var_dec_sec main_prog_block
        ;

program_name : ID
             ;

var_dec_sec : VAR var_dec_list SC
            ;

var_dec_list : var_dec
             | var_dec_list SC var_dec
             ;

var_dec : id_list COLON type
        ;

id_list : ID 
        | id_list COMMA ID
        | arr
        ;

type : INT 
     | REAL
     | CHAR
     | BOOLEAN
     | ARRAY OPENBRAC value DOT DOT value CLOSEBRAC OF type
     ;

main_prog_block : BEG stmt_block SC END DOT
                ;
stmt_block : stmt 
           | stmt_block SC stmt 
           |
           ;
stmt :  read_stmt 
     |  write_stmt 
     |  loop_stmt 
     |  assign_stmt 
     | conditional_stmt 
     ;

assign_stmt :  arr ASSIGN expr 
            |  ID ASSIGN expr 

expr : expr PLUS factor
     | expr MINUS factor
     |  expr MUL factor
     | expr DIV factor
     | expr MOD factor
     | factor
     | '-' expr
     ;

factor :  ID 
       | value 
       |  OB expr CB 
       | arr
       | MINUS factor %prec UMINUS 
       ;

value : INT_LITERAL
      | REAL_LITERAL 
      | BOOLEAN_LITERAL
      | CHAR_LITERAL 
      | STRING
      ;

conditional_stmt : IF bool_expr THEN BEG stmt_block SC END 
                 | IF bool_expr THEN BEG stmt_block SC END ELSE BEG stmt_block SC END 
                 ;
bool_expr: expr rel_op expr
         | OB expr rel_op expr CB
         | NOT bool_expr
         | bool_expr AND bool_expr
         | bool_expr OR bool_expr
         | OB bool_expr OR bool_expr CB
         | OB bool_expr AND bool_expr CB
         | BOOLEAN
         ;
rel_op : EQ 
       | NOTEQ 
       | LT 
       | GT 
       | LTEQ 
       | GTEQ 
       ;

loop_stmt : WHILE bool_expr DO stmt 
          |  WHILE bool_expr DO BEG stmt_block SC END 
          | FOR assign_stmt TO expr DO stmt
          | FOR assign_stmt TO expr DO BEG stmt_block SC END 
          | FOR assign_stmt DOWNTO expr DO stmt
          |  FOR assign_stmt DOWNTO expr DO BEG stmt_block SC END
          ;

read_stmt : READ OB read_list CB 
          ;
read_list : read_id | read_id COMMA read_list ;
read_id : ID | arr ;
arr :  ID OPENBRAC expr CLOSEBRAC | ARRAY OPENBRAC value DOT DOT value CLOSEBRAC ;
write_stmt :  WRITE OB write_param CB 
              ;  

write_param : ID 
            | value 
            | ID COMMA write_param
            | arr
            ;

%%
void yyerror()
{
    printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main()
{
printf("Enter your input:\n");
      char fName[25];
  scanf("%s",fName);
      FILE *file = fopen(fName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Initialize Flex
    yyin = file;

    yyparse();
   // printTable();
    return 0;
}





