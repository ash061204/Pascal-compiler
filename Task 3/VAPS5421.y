%{
    #include<math.h>
    #include<string.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include <stdbool.h>
    #include "symbol_table.h"
    #include "shared_var.h"
    int yo=0;
    int checking=0;
    struct symbolTable table[1000];
    char final_dec_var[1000][50];
    char declared_var[1000][50];
    char declared_type[1000][50];
    int counter=0;
    int count=0;
    int i_value[1000];
    char varLater[1000][50];
    int float_value[1000]={0.0};
   char char_value[1000];
    
    int int_value[1000]={0};
    int initialised[1000] ={0};
    void checkMulDec();
    void printTable();
    void assignType();
    void checkBeforeDec();
     void findId(char* name);
     char* findType(char* variableName);
      float fans = 0.0;
      int ians = 0;
    int x=0;
    void printTable() {
 printf("Symbol Table:\n");
 printf("%d\n",i);
         printf("%-15s %-40s %s\n", "Line Number", "Lexeme", "Token");
         for (int j = 0; j <i; j++) {
                printf("%-15d %-40s %s\n", table[j].line_number, table[j].lexeme, table[j].token);
    }
}
void checkMulDec()
{
   //printf("checking mul dec\n");
  for(int ff=0;ff<1000;ff++)
     char_value[ff]='@';
 for(int j=0;j<i;j++ )
 {
    if(strcasecmp(table[j].lexeme,"BEGIN")==0 ||strcmp(table[j].lexeme,"begin")==0 || strcmp(table[j].lexeme,"Begin")==0  )
        {yo=j;break;}
    if(strcmp(table[j].token,"IDENTIFIER")==0)
    {
        strcpy(declared_var[count],table[j].lexeme);
        i_value[count]=j;
        count++;
    }
 }
 for (int l = 0; l < count; ++l) {
        for (int m = l + 1; m < count; ++m) {
            if (strcasecmp(declared_var[l], declared_var[m]) == 0) {
                printf("Multiple declarations of a varible named %s\n", declared_var[l]);
                checking=1;
                break; 
            }
        }
    }

}
void assignType()
{
        //printf("assigning types to the var\n");
        for(int j=1;j<count;j++)
        {
            int yup=0;
            for(int l=i_value[j];l<i;l++)
            {
                int start,final;
                 if(strcasecmp(table[l].lexeme,"array")==0)
                 {
                    yup=1;
                    //strcpy(final_dec_var[counter], declared_var[j]);
                    //char_value[counter]='$';
                       //counter++;

                    start=atoi(table[l+2].lexeme);
                    final=atoi(table[l+5].lexeme);
                    for(int k=start;k<=final;k++)
                    {
                     char concatenated_string[100];
                    sprintf(concatenated_string, "%s[%d]", declared_var[j], k);
                    strcpy(final_dec_var[counter], concatenated_string);
                       counter++;
                    }

                 }  
                if(strcmp(table[l].lexeme,";")==0)
                {
                    if(yup==1)
                    {
                            for(int k=counter-final;k<counter;k++)
                            {
                                strcpy(declared_type[k],table[l-1].lexeme);
                                
                            }
                            break;
                    }
                    else{
                    strcpy(final_dec_var[counter],declared_var[j]);
                    strcpy(declared_type[counter],table[l-1].lexeme);
                    counter++;
                    break;
                    }
                }
            }
        }

   // for(int k=0;k<counter;k++)
   // {
     //   printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf(" %d ",int_value[k]);printf("%c ",char_value[k]);printf("%f \n",float_value[k]);
   // }
        
}
int isIdPresent(char* name)
{
    int xx=0;
     for (int k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0)
        xx=1;
     }
     if(xx==1)
        return 1;
    else
        return 0;
}
void findId(char* name)
{
    //printf(name);
    int xx=0;
     for (int k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0)
        xx=1;
     }
     if(xx==0)
     {
         printf("Undeclared variable %s\n",name);
    checking=1;
     }
}
void checkBeforeDec()
{
    int c=0;
        for(int j=yo;j<i;j++)
        {
            if(strcasecmp(table[j].token,"IDENTIFIER")==0)
            {
                strcpy(varLater[c],table[j].lexeme);
                c++;
            }
        }
    for(int j=0;j<c;j++)
   {
    bool hehe=false;
           for(int l=0;l<counter;l++)
           {
                if(strcasecmp(varLater[j],final_dec_var[l])==0)
                {
                    hehe=true;
                    break;
                }
           }
           if(hehe==false)
           {
            printf("Undeclared variable %s",varLater[j]);
            checking=1;
            printf("\n");
           }
   }
}
float getrealVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return float_value[k];
       }
     }
     return 0.0;
}
int getintVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return int_value[k];
       }
     }
     return 0;
}
void initialize(char* name)
{
     for(int k=0;k<counter;k++)
     {
        if(strcasecmp(final_dec_var[k],name)==0)
            initialised[k]=1;
     }
}
int checkIn(char* name)
{
    for(int k=0;k<counter;k++)
     {
        if(strcasecmp(final_dec_var[k],name)==0)
           return initialised[k];
     }
}
void insertintValue(char* name, int ival)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            int_value[k]=ival;
        

       }
     }
}
void insertcharValue(char* name, char cval)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            char_value[k]=cval;
        

       }
     }
}
void insertrealValue(char* name, float fval)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            float_value[k]=fval;
        

       }
     }
}
char getcharVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return char_value[k];
       }
     }
     return '\0';
}
char* findType(char* name) {
  
    int k;
    for (k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0) {
    

            // Check if the lowercase_type contains specific keywords and return the corresponding type
            if (strcasecmp(declared_type[k], "integer") == 0) {
                return "int";
            } else if (strcasecmp(declared_type[k], "real") == 0 ) {
                return "real";
            } else if (strcasecmp(declared_type[k], "Char") == 0 ) {
                return "char";
            } else if (strcasecmp(declared_type[k], "boolean") == 0 ) {
                return "bool";
            } else {
                // If no specific type is matched, return the original declared type
                return declared_type[k];
            }
        }
    }
    printf("Undeclared variable %s\n",name);
    checking=1;
    return NULL;
}
    extern FILE *yyin;

%}
%union{
    struct{
        char type[10];
       
        union{
            int ival;
            float fval;
            char cval;
        }v;
    }t;
}
%union{
    char *strval;
}
%left OR
%left AND
%right NOT
%left EQ NOTEQ LT GT LTEQ GTEQ
%left PLUS MINUS '-'
%left MUL DIV MOD
%right UMINUS
%token DOWNTO UMINUS PROGRAM SC TYPE EQ OF COMMENT COLON BEG READ OB CB WRITE STRING COMMA FOR ASSIGN DO INT_LITERAL REAL_LITERAL  CHAR_LITERAL
%token VAR NOTEQ LT GT GTEQ LTEQ PLUS MINUS MUL DIV MOD AND OR NOT IF THEN ELSE END DOT INT REAL CHAR BOOLEAN TO WHILE ARRAY OPENBRAC CLOSEBRAC OPENPARA CLOSEPARA
%token <strval> ID ARR
%type <strval> factor assign_stmt expr 
%%

start : program 
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

main_prog_block : BEG {checkMulDec();assignType();} stmt_block SC END DOT
                ;
stmt_block : stmt 
           | stmt_block SC stmt 
           ;
stmt :  read_stmt 
     |  write_stmt 
     |  loop_stmt 
     |  assign_stmt 
     | conditional_stmt 
     ;

assign_stmt :  ARR {if(isIdPresent($1)==1){findId($1);strcpy($<t.type>$, findType($1));} } ASSIGN expr { if(isIdPresent($1)==1) {if (strcmp(findType($1),$<t.type>4)!=0 && !(strcmp(findType($1),"bool")==0 && strcmp($<t.type>4,"int")==0 && !(strcmp(findType($1),"real")==0 && strcmp($<t.type>4,"int")==0)) ) { printf("Type mismatch: Assigning %s to %s for variable %s not possible\n",$<t.type>4,findType($1),$1);  checking=1;}
                else
                {
                    char name[50];
                    strcpy(name, $1);
                    //printf("\n");
                    //printf(name);
                    //printf("\n");
                    strcpy($<t.type>1,findType($1));
                    //printf($<t.type>1);printf("\n");printf("hoho\n");
                   if (strcmp($<t.type>1,"real")==0) 
                   {
                    if (strcmp($<t.type>4,"int")==0)
                    {
                        $<t.v.fval>1 = 1.0*$<t.v.ival>4;
                    initialize(name);
                    insertrealValue(name,$<t.v.fval>1);
                    }
                    else{
                    $<t.v.fval>1 = $<t.v.fval>4;
                    initialize(name);
                    insertrealValue(name,$<t.v.fval>1);}
                   }
                    else if (strcmp($<t.type>1,"int")==0)
                    {
                        //printf("entered int\n");
                    $<t.v.ival>1 = $<t.v.ival>4;
                   //printf("\n");
                    //printf(name);
                    //printf("\n");
                    initialize(name);
                    insertintValue(name,$<t.v.ival>1);
                   // printf("%d \n",$<t.v.ival>1);
                    }
                    else if (strcmp($<t.type>1,"char")==0)
                    {
                     $<t.v.cval>1 = $<t.v.cval>4;
                     initialize(name);
                     insertcharValue(name,$<t.v.cval>1);
                    }
                    else if (strcmp($<t.type>1,"bool")==0)
                    {
                     //printf("entered int\n");
                    $<t.v.ival>1 = $<t.v.ival>4;
                    initialize(name);
                    insertintValue(name,$<t.v.ival>1);
                   // printf("%d \n",$<t.v.ival>1);
                     
                    }
                }
}
            }
            |  ID {if(isIdPresent($1)==1){findId($1);strcpy($<t.type>$, findType($1));} } ASSIGN expr { if(isIdPresent($1)==1) {if (strcmp(findType($1),$<t.type>4)!=0 && !(strcmp(findType($1),"bool")==0 && strcmp($<t.type>4,"int")==0) && !(strcmp(findType($1),"real")==0 && strcmp($<t.type>4,"int")==0) ) { printf("Type mismatch: Assigning %s to %s for variable %s not possible\n",$<t.type>4,findType($1),$1);  checking=1;}
                else
                {
                    char name[50];
                    strcpy(name, $1);
                    //printf("\n");
                    //printf(name);
                    //printf("\n");
                    strcpy($<t.type>1,findType($1));
                    //printf($<t.type>1);printf("\n");printf("hoho\n");
                   if (strcmp($<t.type>1,"real")==0) 
                   {
                    if (strcmp($<t.type>4,"int")==0)
                    {
                        $<t.v.fval>1 = 1.0*$<t.v.ival>4;
                    initialize(name);
                    insertrealValue(name,$<t.v.fval>1);
                    }
                    else
                    {
                    $<t.v.fval>1 = $<t.v.fval>4;
                    initialize(name);
                    insertrealValue(name,$<t.v.fval>1);}
                   }
                    else if (strcmp($<t.type>1,"int")==0)
                    {
                        //printf("entered int\n");
                    $<t.v.ival>1 = $<t.v.ival>4;
                   //printf("\n");
                    //printf(name);
                    //printf("\n");
                    initialize(name);
                    insertintValue(name,$<t.v.ival>1);
                   // printf("%d \n",$<t.v.ival>1);
                    }
                    else if (strcmp($<t.type>1,"char")==0)
                    {
                     $<t.v.cval>1 = $<t.v.cval>4;
                     initialize(name);
                     insertcharValue(name,$<t.v.cval>1);
                    }
                    else if (strcmp($<t.type>1,"bool")==0)
                    {
                     //printf("entered int\n");
                    $<t.v.ival>1 = $<t.v.ival>4;
                    initialize(name);
                    insertintValue(name,$<t.v.ival>1);
                   // printf("%d \n",$<t.v.ival>1);
                     
                    }
                }
}
            }
            ;

expr : expr PLUS term {
            //printf("expr + term\n");
            //printf($<t.type>1);
            //printf($<t.type>3);
            if (((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "real")==0 ))) {
                printf("Error:Char and real addition not possible\n");
                checking=1;
            }
            if ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "char")==0 ))
            {
                printf("Error:Char and char addition not possible\n");
                checking=1;
            }
            if (((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "int")==0 )))
            {
                 printf("Error:Char and int addition not possible\n");
                checking=1;
            }
            if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "real")==0 )) {
                $<t.v.fval>$ = $<t.v.fval>1 + $<t.v.fval>3 ;
                fans = $<t.v.fval>$ ; 
                strcpy($<t.type>$, "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "int")==0 )) {
                $<t.v.fval>$ = $<t.v.fval>1 + $<t.v.ival>3 ;

                fans = $<t.v.fval>$ ;
                strcpy($<t.type>$, "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "real")==0 )) {
                $<t.v.fval>$ = $<t.v.ival>1 + $<t.v.fval>3 ;

                fans = $<t.v.fval>$ ;
                strcpy($<t.type>$, "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "int")==0 )) {
                $<t.v.ival>$ = $<t.v.ival>1 + $<t.v.ival>3 ;
                ians = $<t.v.ival>$;
                //printf("hello");
                strcpy($<t.type>$, "int");
               // printf($<t.type>$);
                //printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
            }
        }
     | expr MINUS term {
    if (((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "real")==0 ))) {
                printf("Error:Char and real subtraction not possible\n");
                checking=1;
            }
            if ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "char")==0 ))
            {
                printf("Error:Char and char subtraction not possible\n");
                checking=1;
            }
            if (((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "int")==0 )))
            {
                 printf("Error:Char and int subtraction not possible\n");
                checking=1;
            }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "real")==0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 - $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ; 
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "int")==0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 - $<t.v.ival>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "real")==0 )) {
        $<t.v.fval>$ = $<t.v.ival>1 - $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "int")==0 )) {
        $<t.v.ival>$ = $<t.v.ival>1 - $<t.v.ival>3 ;
        ians = $<t.v.ival>$;
        strcpy($<t.type>$, "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
}
     | term { strcpy($<t.type>$, $<t.type>1);
           // printf("expr->term\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp($<t.type>1,"int")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>1; 
                   // printf("hello%d\n", $<t.v.ival>$);
                   // printf("value printf");
                }
                 else if (strcmp($<t.type>1,"real")==0) 
                {
                    $<t.v.fval>$ = $<t.v.fval>1; 
                } 
                else if (strcmp($<t.type>1,"char")==0)
                 {
                    $<t.v.cval>$ = $<t.v.cval>1; 
                 } 
     }
     ;
term : term MUL factor {
    // Subtraction
    // Similar code for subtraction
    if (((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "real")==0 ))) {
                printf("Error:Char and real multiplication not possible\n");
                checking=1;
            }
            if ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "char")==0 ))
            {
                printf("Error:Char and char multiplication not possible\n");
                checking=1;
            }
            if (((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "int")==0 )))
            {
                 printf("Error:Char and int multiplication not possible\n");
                checking=1;
            }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "real")==0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 * $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ; 
        strcpy($<t.type>$, "real");
       // printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "int")==0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 * $<t.v.ival>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "real")==0 )) {
        $<t.v.fval>$ = $<t.v.ival>1 * $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "int")==0 )) {
        $<t.v.ival>$ = $<t.v.ival>1 * $<t.v.ival>3 ;
        ians = $<t.v.ival>$;
        strcpy($<t.type>$, "int");
    //printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
}
     | term DIV factor {
    // Subtraction
    if (((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "real")==0 ))) {
                printf("Error:Char and real division not possible\n");
                checking=1;
            }
            if ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "char")==0 ))
            {
                printf("Error:Char and char division not possible\n");
                checking=1;
            }
            if (((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "char")==0 )) || ((strcmp($<t.type>1 , "char")==0 && strcmp($<t.type>3 , "int")==0 )))
            {
                 printf("Error:Char and int division not possible\n");
                checking=1;
            }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "real")==0 )) {
        if( $<t.v.fval>3==0.0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        $<t.v.fval>$ = $<t.v.fval>1 / $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ; 
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp($<t.type>1 , "real")==0 && strcmp($<t.type>3 , "int")==0 )) {
        if( $<t.v.ival>3==0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        $<t.v.fval>$ = $<t.v.fval>1 / $<t.v.ival>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "real")==0 )) {
        if( $<t.v.fval>3==0.0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        $<t.v.fval>$ = $<t.v.ival>1 / $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ;
        strcpy($<t.type>$, "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "int")==0 )) {
        if( $<t.v.ival>3==0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        $<t.v.ival>$ = $<t.v.ival>1 / $<t.v.ival>3 ;
        ians = $<t.v.ival>$;
        strcpy($<t.type>$, "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
        }
    }
}
     | term MOD factor {
    // Modulus
    if (strcmp($<t.type>1 , "real")==0 || strcmp($<t.type>3 , "real")==0 ) {
        printf("Error:Modulus operator cannot be applied to real numbers\n"); checking=1;
    }
    else if ($<t.v.ival>3 == 0) {
        printf("Error:Division by zero\n");
          checking=1;
    }
   else if ((strcmp($<t.type>1 , "int")==0 && strcmp($<t.type>3 , "int")==0 )) {
        $<t.v.ival>$ = $<t.v.ival>1 / $<t.v.ival>3 ;
        ians = $<t.v.ival>$;
        strcpy($<t.type>$, "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
    else
    {
        printf("Error:Type should be int for Modulus operation\n");
      checking=1;
    }
    
}
     | factor { strcpy($<t.type>$, $<t.type>1);
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp($<t.type>1,"int")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>1; 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp($<t.type>1,"real")==0) 
                {
                    $<t.v.fval>$ = $<t.v.fval>1; 
                } 
                else if (strcmp($<t.type>1,"char")==0)
                 {
                    $<t.v.cval>$ = $<t.v.cval>1; 
                 } 
                 else if (strcmp($<t.type>1,"bool")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>1; 
                 } 
     }
      
     ;

factor :   ID { if(isIdPresent($1)==1){strcpy($<t.type>$, findType($1));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp($<t.type>$,"real")==0)
                {
                   $<t.v.fval>$=getrealVal($1);
                   int val=checkIn($1);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                    printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                    //printf("yo\n");
                    $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     $<t.v.cval>$=getcharVal($1);
                      int val=checkIn($1);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                         printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
}
 }
       | value {
        strcpy($<t.type>$,$<t.type>1); 
        // printf($<t.type>$);printf("factor\n");
                 if (strcmp($<t.type>1,"int")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>1; 
                   // printf("hello%d\n", $<t.v.ival>$);
                   // printf("value printf");
                }
                 else if (strcmp($<t.type>1,"real")==0) 
                {
                    $<t.v.fval>$ = $<t.v.fval>1; 
                } 
                else if (strcmp($<t.type>1,"char")==0)
                 {
                    $<t.v.cval>$ = $<t.v.cval>1; 
                 } 
            } 
       | ARR {if(isIdPresent($1)==1){strcpy($<t.type>$, findType($1));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp($<t.type>$,"real")==0)
                {
                     int val=checkIn($1);
                   $<t.v.fval>$=getrealVal($1);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                     printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                     int val=checkIn($1);
                    //printf("yo\n");
                    $<t.v.ival>$=getintVal($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                       printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     int val=checkIn($1);
                     $<t.v.cval>$=getcharVal($1);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
       }
       }
       | OB expr CB { strcpy($<t.type>$, $<t.type>2);
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp($<t.type>2,"int")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>2; 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp($<t.type>2,"real")==0) 
                {
                    $<t.v.fval>$ = $<t.v.fval>2; 
                } 
                else if (strcmp($<t.type>2,"char")==0)
                 {
                    $<t.v.cval>$ = $<t.v.cval>2; 
                 } 
                 else if (strcmp($<t.type>2,"bool")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>2; 
                 }
     }
      
       |  MINUS factor %prec UMINUS { strcpy($<t.type>$, $<t.type>2);
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp($<t.type>2,"int")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>2; 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp($<t.type>2,"real")==0) 
                {
                    $<t.v.fval>$ = $<t.v.fval>2; 
                } 
                else if (strcmp($<t.type>2,"char")==0)
                 {
                    $<t.v.cval>$ = $<t.v.cval>2; 
                 } 
                 else if (strcmp($<t.type>2,"bool")==0)
                 {
                    $<t.v.ival>$ = $<t.v.ival>2; 
                 }
     }
       ;

value : INT_LITERAL {strcpy($<t.type>$,"int"); $<t.v.ival>$=$<t.v.ival>1;}
      | REAL_LITERAL {strcpy($<t.type>$,"real");$<t.v.fval>$=$<t.v.fval>1;}
      | CHAR_LITERAL {strcpy($<t.type>$,"char");$<t.v.cval>$=$<t.v.cval>1;}
      | STRING
      ;

conditional_stmt : IF bool_expr THEN BEG stmt_block SC END 
                 | IF bool_expr THEN BEG stmt_block SC END ELSE BEG stmt_block SC END 
                 | IF v THEN BEG stmt_block SC END {if (strcmp($<t.type>2,"bool")!=0 ) {printf("Error: Variable type must be boolean in conditional statement\n");checking=1;} }
                 | IF v THEN BEG stmt_block SC END ELSE BEG stmt_block SC END {if (strcmp($<t.type>2,"bool")!=0 ) {printf("Error: Variable type must be boolean in conditional statement\n");checking=1;} }
                 ;
bool_expr: expr rel_op expr  {if (strcmp($<t.type>1,$<t.type>3)!=0) {printf("Type %s doesn't match with %s\n",$<t.type>1,$<t.type>3);checking=1;}  }
         | OB bool_expr CB 
         | NOT bool_expr
         | bool_expr AND bool_expr
         | bool_expr OR bool_expr
         | v OR v {if (strcmp($<t.type>1,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}
          if (strcmp($<t.type>3,"bool")!=0) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}   }
         | v AND v {if (strcmp($<t.type>1,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}
          if (strcmp($<t.type>3,"bool")!=0) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}   }
         | bool_expr OR v {if (strcmp($<t.type>3,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
        | v OR bool_expr {if (strcmp($<t.type>1,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
        | v AND bool_expr {if (strcmp($<t.type>1,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
        | bool_expr AND v {if (strcmp($<t.type>3,"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
        | NOT v {if (strcmp($<t.type>2,"bool")!=0) {printf("Error: Variable must be boolean\n in conditional statement");checking=1;} }
        | expr EQ NOT expr {if (strcmp($<t.type>1,$<t.type>4)!=0) {printf("Error:Type %s doesn't match type %s\n",$<t.type>1,$<t.type>4);checking=1;}  }
          ;
v : ID  {if(isIdPresent($1)==1){strcpy($<t.type>$, findType($1));
               
                if(strcmp($<t.type>$,"real")==0)
                {
                   $<t.v.fval>$=getrealVal($1);
                   int val=checkIn($1);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                    printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                    $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     $<t.v.cval>$=getcharVal($1);
                      int val=checkIn($1);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                         printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
}
 }
    | OB ID CB  {if(isIdPresent($2)==1){strcpy($<t.type>$, findType($2));
                
                if(strcmp($<t.type>$,"real")==0)
                {
                   $<t.v.fval>$=getrealVal($2);
                   int val=checkIn($2);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                    printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                    $<t.v.ival>$=getintVal($2);
                     int val=checkIn($2);
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     $<t.v.cval>$=getcharVal($2);
                      int val=checkIn($2);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                         printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($2);
                     int val=checkIn($2);
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
    | ARR  {if(isIdPresent($1)==1){strcpy($<t.type>$, findType($1));
                if(strcmp($<t.type>$,"real")==0)
                {
                   $<t.v.fval>$=getrealVal($1);
                   int val=checkIn($1);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                    printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                    //printf("yo\n");
                    $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     $<t.v.cval>$=getcharVal($1);
                      int val=checkIn($1);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                         printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($1);
                     int val=checkIn($1);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($1);printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
    | OB ARR CB {if(isIdPresent($2)==1){strcpy($<t.type>$, findType($2));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp($<t.type>$,"real")==0)
                {
                   $<t.v.fval>$=getrealVal($2);
                   int val=checkIn($2);
                    if($<t.v.fval>$==0.0 && val==0)
                    {
                    printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp($<t.type>$,"int")==0)
                {
                    //printf("yo\n");
                    $<t.v.ival>$=getintVal($2);
                     int val=checkIn($2);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"char")==0)
                {
                     $<t.v.cval>$=getcharVal($2);
                      int val=checkIn($2);
                     if($<t.v.cval>$=='@' && val==0)
                    {
                         printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp($<t.type>$,"bool")==0)
                {
                     $<t.v.ival>$=getintVal($2);
                     int val=checkIn($2);
                     //printf("yo\n");
                     if($<t.v.ival>$==0 && val==0)
                    {
                        printf("Variable ");printf($2);printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
    ;

rel_op : EQ 
       | NOTEQ 
       | LT 
       | GT 
       | LTEQ 
       | GTEQ 
       ;

loop_stmt :  WHILE bool_expr DO BEG stmt_block SC END 
            | WHILE v DO BEG stmt_block SC END {if (strcmp($<t.type>2,"bool")!=0 ) {printf("Error:Variable must be boolean type\n");checking=1;} }
          | FOR assign_stmt TO expr DO BEG stmt_block SC END 
          |  FOR assign_stmt DOWNTO expr DO BEG stmt_block SC END
          ;

read_stmt : READ OB read_list CB 
          ;
read_list : read_id | read_id COMMA read_list ;
read_id : ID {
                    char name[50];
                    strcpy(name, $1);
                    initialize(name);}
| ARR {
                    char name[50];
                    strcpy(name, $1);
                    initialize(name);}
 ;
arr :  ARR| ARRAY OPENBRAC value DOT DOT value CLOSEBRAC ;
write_stmt :  WRITE OB write_param CB 
              ;  

write_param : list
            | STRING 
            ;
list : ID
    | ID COMMA list
    |arr COMMA list
    | arr
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
     checkBeforeDec();
     //printTable();
    if(checking==0)
        printf("Semantically correct!\n");
    fclose(file);
    return 0;
}