%{
    #include<math.h>
    #include<string.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    void printTable();
   
    extern FILE *yyin;
     int iflabel = 0;
     int whilelabel=0;
     int forlabel=0;
    int tempVariable = 0;

    char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 't';
        snprintf(temp, 10, "t%d", id);
        return temp;
    }

    int gencode(char* lhs, char* op, char* rhs){
        printf("t%d = %s %s %s \n", tempVariable, lhs, op, rhs);
        return tempVariable;
    }

    void assignment(char* lhs, char* rhs){
        printf("%s = %s \n", lhs, rhs);
    }
void conditional_jump(char* cond, int label,int check){
    if(check==1)
    printf("If %s goto I%d\n", cond, label);
    else if(check==2)
    printf("If not %s goto W%d\n", cond, label);
    else if(check==3)
    printf("If %s goto F%d\n", cond, label);
}
void for_jump(char* cond, int label,int check,char* expr){
    if(check==1)
    printf("If %s > %s goto F%d\n", cond,expr, label);
    else if(check==2)
    printf("If %s < %s goto F%d\n", cond,expr, label);
}

void unconditional_jump(int label,int check){
    if(check==1)
    printf("goto I%d\n", label);
    else if(check==2)
     printf("goto W%d\n", label);
     else if(check==3)
     printf("goto F%d\n", label);
}

void label_statement(int label,int check){
    
    if(check==1)
    printf("I%d:\n", label);
    else if(check==2)
    printf("W%d:\n", label);
    else if(check==3)
    printf("F%d:\n", label);
}

%}
%union{
    char* lexeme;
} 

%left OR
%left AND
%right NOT
%left MOD
%left PLUS MINUS '-'
%left MUL DIV
%right UMINUS
%token <lexeme> DOWNTO UMINUS PROGRAM ID SC TYPE EQ ARR OF COMMENT COLON BEG READ OB CB WRITE STRING COMMA FOR ASSIGN DO INT_LITERAL REAL_LITERAL BOOLEAN_LITERAL CHAR_LITERAL
%token <lexeme> VAR NOTEQ LT GT GTEQ LTEQ PLUS MINUS MUL DIV MOD AND OR NOT IF THEN ELSE END DOT INT REAL CHAR BOOLEAN TO WHILE ARRAY OPENBRAC CLOSEBRAC OPENPARA CLOSEPARA
%type <lexeme> factor assign_stmt bool_expr value expr arr rel_op term loop_stmt e v
%%

start : program {  }
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

assign_stmt :  ARR ASSIGN expr {assignment($1, $3);}
            |  ID ASSIGN expr {assignment($1, $3);}

expr : expr PLUS term{
                            int a = gencode($1, "+", $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
     | expr MINUS term {
                            int a = gencode($1, "-", $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
     | term {$$ = $1;}
     ;
term : term MUL factor {
                            int a = gencode($1, "*", $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
     | term DIV factor {
                            int a = gencode($1, "/", $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
     | term MOD factor {
                            int a = gencode($1, "%", $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
     | factor {$$ = $1;}
    
     ;

factor :  ID {$$ = $1;}
       | value {$$ = $1;}
       |  OB expr CB {$$ = $2;}
       | ARR {$$ = $1;}
        | MINUS factor %prec UMINUS {
                            int a = gencode("", "-", $2);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;
                        }
       ;

value : INT_LITERAL {$$ = $1;}
      | REAL_LITERAL {$$ = $1;}
      | BOOLEAN_LITERAL {$$ = $1;}
      | CHAR_LITERAL {$$ = $1;}
      | STRING
      ;
conditional_stmt : IF bool_expr THEN  {
                        conditional_jump($2, iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    } stmt_block maybe_else_block
                    | IF v THEN  {
                        conditional_jump($2, iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    } stmt_block maybe_else_block
                 ;
v : ID {$$ = $1;}
    | OB ID CB {$$ = $2;}
    | ARR {$$ = $1;}
    | OB ARR CB {$$ = $2;}
    ;
maybe_else_block : BEG stmt_block SC END {label_statement(iflabel++,1);}
                 | BEG stmt_block SC END {unconditional_jump(iflabel + 1,1);label_statement(iflabel++,1);} ELSE BEG stmt_block SC END {
                        label_statement(iflabel++,1);
                    }
                 ;


bool_expr: expr rel_op expr {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | NOT bool_expr {int a = gencode("", $1, $2);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | bool_expr AND bool_expr {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | bool_expr OR bool_expr {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | OB bool_expr CB  {$$=$2;}
          | v OR v {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | v AND v {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
         | bool_expr OR v {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
        | v OR bool_expr {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
        | v AND bool_expr {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
        | bool_expr AND v {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
        | NOT v {int a = gencode("", $1, $2);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
        | expr EQ e {int a = gencode($1, $2, $3);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
                            ;
e : NOT expr {int a = gencode("", $1, $2);
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;}
    ;
         
rel_op : EQ 
       | NOTEQ 
       | LT 
       | GT 
       | LTEQ 
       | GTEQ 
       ;

loop_stmt :  WHILE bool_expr DO {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump($2, whilelabel,2);
                   
                    
                } BEG stmt_block SC END  {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
                |  WHILE v DO {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump($2, whilelabel,2);
                   
                    
                } BEG stmt_block SC END  {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
          | FOR assign_stmt TO expr DO {
                   label_statement(forlabel++,3);
                    for_jump($2, forlabel,1,$4);
                } BEG stmt_block SC END {int a = gencode($2, "+", "1");
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;assignment($2, $$);unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode($2, "-", "1");
                            char* tempVar1 = genTempVariable(b);
                            $$ = tempVar1;tempVariable++;assignment($2, $$);}
          |  FOR assign_stmt DOWNTO expr DO {
                    label_statement(forlabel++,3);
                     for_jump($2, forlabel,2,$4);
                    
                } BEG stmt_block SC END {int a = gencode($2, "-", "1");
                            char* tempVar = genTempVariable(a);
                            $$ = tempVar;
                            tempVariable++;assignment($2, $$);unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode($2, "+", "1");
                            char* tempVar1 = genTempVariable(b);
                            $$ = tempVar1;tempVariable++;assignment($2, $$);}
          ;

read_stmt : READ OB read_list CB 
          ;
read_list : read_id | read_id COMMA read_list ;
read_id : ID | ARR ;
arr :  ID OPENBRAC expr CLOSEBRAC | ARRAY OPENBRAC value DOT DOT value CLOSEBRAC ;
write_stmt :  WRITE OB write_param CB 
              ;  

write_param : ID 
            | value 
            | ID COMMA write_param
            | ARR
            ;

%%
void yyerror()
{
    printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yyparse();
   // printTable();
   fclose(file);
    return 0;
}





