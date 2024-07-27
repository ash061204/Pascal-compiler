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
#line 1 "VAPS5421.y"

    #include<math.h>
    #include<string.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include "symbol_table.h"
    #include "shared_var.h"
    #define MAX_OPERANDS 3
    void printTable();
    void checkMulDec();
    void assignType();
    extern FILE *yyin;
    char tac[1000][500];
     int iflabel = 0;
     int whilelabel=0;
     int forlabel=0;
     int str=0;
    int tempVariable = 0;
     int yo=1;
     int num[1000];
     int bool_val[1000]={0};
    int counter=0;
    int count=0;
    typedef struct
     {
    char lhs[20];       // lhs
    char op[4];         // operator
    char operand1[20];  // first operand
    char operand2[20];  // seccond operand
    } Expression;
   void tokenize_expression(char* expression, Expression* expr) {
    char* token = strtok(expression, " =+-*/");

    if (token != NULL) {
        strcpy(expr->lhs, token);  // Copy LHS
    }

    token = strtok(NULL, " "); // Skip '='
    token = strtok(NULL, " ");
    
    if (token != NULL) {
        if (strcasecmp(token, "not") == 0) {
            strcpy(expr->op, "not");  // Unary operator "not"
            token = strtok(NULL, " "); // Move to the operand after "not"
        } else {
            if (token[0] == '-') {
                strcpy(expr->op, "-");  // Copy operator
                strcpy(expr->operand1, token + 1);  // Remove unary minus from first operand
                token = strtok(NULL, " "); // Move to the second operand
            } else {
                strcpy(expr->operand1, token);  // Copy first operand
                token = strtok(NULL, " ");  // Copy operator
                if (token != NULL) {
                    strcpy(expr->op, token);  
                    token = strtok(NULL, " "); // Move to the second operand
                } else {
                    strcpy(expr->op, "");  // Set operator to empty if not provided
                }
            }
        }
    }

    if (token != NULL) {
        strcpy(expr->operand2, token);  // Copy second operand
    } else {
        strcpy(expr->operand2, "");  // Set second operand to empty if not provided
    }
}
    struct symbolTable table[1000];
    char final_dec_var[1000][50];
    char declared_var[1000][50];
    char declared_type[1000][50];
    int i_value[1000];
    char varLater[1000][50];
    float float_value[1000]={0.0};
    char char_value[1000];
    int int_value[1000]={0};
    int initialised[1000] ={0};

    int isVariable(const char *str) 
    {
            if (isalpha(str[0]))
            {
                for (int i = 1; str[i] != '\0'; i++)
                {
                    if (!isalnum(str[i]) && str[i] != '_') 
                    {
                        return 0;  // Not a valid variable name
                    }
                }
                return 1;  // Valid variable name
            }
            return 0;  // Not starting with alphabet
    }
    int isInteger(const char *str)
    {
    if (str[0] == '-' || isdigit(str[0])) {
        for (int i = 1; str[i] != '\0'; i++) {
            if (!isdigit(str[i])) {
                return 0;  // Not an integer
            }
        }
        return 1;  // Integer
    }
    return 0;  // Not starting with digit or '-'
}
int isFloat(const char *str)
 {
            char *endptr;
            strtod(str, &endptr);
            if (*endptr == '\0') 
            {
                return 1;  // Float
            }
            return 0;  // Not a float
}
void setType(char* name, char* type)
{
    for(int l=0;l<counter;l++)
    {
         if(strcasecmp(final_dec_var[l],name)==0)
            strcpy(declared_type[l],type);
    }
}
int isChar(const char *str) 
{
    if (strlen(str) == 3 && str[0] == '\'' && str[2] == '\'')
    {
        return 1;  // Character
    }
    return 0;  // Not a character
}
void findId(char* name)
{
    int xx=0;
     for (int k = 0; k < counter; k++)
      {
        if (strcasecmp(final_dec_var[k], name) == 0)
        xx=1;
      }
}
void checkMulDec()
{
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
                    exit(1); 
                    break; 
                }
            }
        }
}
void assignType()
{
        for(int j=1;j<count;j++)
        {
            int yup=0;
            for(int l=i_value[j];l<i;l++)
            {
                int start,final;
                 if(strcasecmp(table[l].lexeme,"array")==0)
                 {
                    yup=1;
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
}
char* findType(char* name)
 {int k;
    for (k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0) 
        {
             if (strcasecmp(declared_type[k], "integer") == 0 || strcmp(declared_type[k], "Integer") == 0) {
                return "int";
            } else if (strcasecmp(declared_type[k], "real") == 0 || strcmp(declared_type[k], "Real") == 0) {
                return "real";
            } else if (strcasecmp(declared_type[k], "Char") == 0 || strcmp(declared_type[k], "char") == 0) {
                return "char";
            } else if (strcasecmp(declared_type[k],"bool")==0 || strcmp(declared_type[k], "boolean") == 0 || strcmp(declared_type[k], "Boolean") == 0) {
                return "bool";
            } else {
               return declared_type[k];
            }
        }
    }
    return NULL;
}
char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", id);
        char result[100]; 
         char st[20]; // Make sure this array is large enough to hold the converted string
        sprintf(st, "%d", id);
         strcpy(result, "T"); // Copy str1 to result
        strcat(result, st); 
        strcpy(final_dec_var[counter++],result);
        return temp;
    }
 int gencode(char* lhs, char* op, char* rhs){
         num[str]=5;
         sprintf(tac[str++], "\nT%d = %s %s %s", tempVariable, lhs, op, rhs);
        return tempVariable;
    }
void assignment(char* lhs, char* rhs){
        num[str]=3;
        sprintf(tac[str++], "\n%s = %s",lhs, rhs);
    }
 void conditional_jump(char* cond, int label,int check){
            if(check==1)
            {
            num[str]=4;
            sprintf(tac[str++], "If %s goto I%d", cond, label);
            }
            else if(check==2)
            {
            num[str]=5;
            sprintf(tac[str++],"If not %s goto W%d", cond, label);
            }
            else if(check==3)
            {
            sprintf(tac[str++],"If %s goto F%d", cond, label);
            }
 }
 void for_jump(char* cond, int label,int check,char* expr){
    if(check==1)
    {
        num[str]=6;
       sprintf(tac[str++],"If %s > %s goto F%d", cond,expr, label);
    }
    else if(check==2)
    {
        num[str]=6;
        sprintf(tac[str++],"If %s < %s goto F%d", cond,expr, label);
    }
}
 void unconditional_jump(int label,int check){
    if(check==1)
    {
            num[str]=2;
            sprintf(tac[str++],"goto I%d", label);
    }
    else if(check==2)
    {
        num[str]=2;
        sprintf(tac[str++],"goto W%d", label);
    }
     else if(check==3)
     {
        num[str]=2;
        sprintf(tac[str++],"goto F%d", label);
     }
}
char *trimit(char *s1) {
        char *end;
        while (isspace((unsigned char)*s1))
        {s1++;}
        if (*s1 == 0) 
        { return s1; }
        end = s1 + strlen(s1) - 1;
        while (end > s1 && isspace((unsigned char)*end))
        { end--; }
        *(end + 1) = '\0';
   return s1;
}
int getboolVal(char* name)
{
     for(int k=0;k<counter;k++)
     {
       if(strcasecmp(final_dec_var[k],name)==0)
       { return bool_val[k]; }
     }
     return 0;
}
void insertboolVal(char*name, int val)
{
    for(int lm=0;lm<counter;lm++)
    {
        if(strcasecmp(final_dec_var[lm],name)==0)
        {
            bool_val[lm]=val;
            initialised[lm]=1;
            break;
        }
    }
}
float getrealVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       if(strcasecmp(final_dec_var[k],name)==0)
       {  return float_value[k]; }
     }
     return 0.0;
}
int getintVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       if(strcasecmp(final_dec_var[k],name)==0)
       {return int_value[k];}
     }
     return 0;
}
char getcharVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       if(strcasecmp(final_dec_var[k],name)==0)
       { return char_value[k]; }
     }
     return '\0';
}
void insertintValue(char* name, int val)
{
    for(int lm=0;lm<counter;lm++)
    {
        if(strcasecmp(final_dec_var[lm],name)==0)
        {
            int_value[lm]=val;
            initialised[lm]=1;
            break;
        }
    }
}
void insertrealValue(char* name, float val)
{
    for(int lm=0;lm<counter;lm++)
    {
        if(strcasecmp(final_dec_var[lm],name)==0)
        {
            float_value[lm]=val;
            initialised[lm]=1;
            break;
        }
    }
}
void insertcharValue(char* name, char cval)
{
     for(int k=0;k<counter;k++)
    {
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            char_value[k]=cval;
            initialised[k]=1;
       }
     }
}
void modifyArridx(char *op1, const char *index)
{
                        int yy=getintVal(index);
                        char *start = strchr(op1, '[');
                         char *end = strchr(op1, ']');
                        if (start != NULL && end != NULL && end > start) 
                        {
                        sprintf(start + 1, "%d", yy); 
                        strcat(start + strlen(start), "]");
                      }
}
void isArray(char *op1)
{
               char *start = strchr(op1, '[');
               char *end = strchr(op1, ']');
               if (start != NULL && end != NULL && end > start) 
               {
                    int length = end - (start + 1);
                    char index[length + 1];
                    strncpy(index, start + 1, length);
                    index[length] = '\0'; 
                    if(isVariable(index))
                    {
                       modifyArridx(op1,index);
                    }
                }
}
int checktrueornot(char* op, char *op1, char *op2)
{
     int checktype=0;
    int x;float y;char z;int b;
    int x1;float y1;char z1;int b1;
        if (isInteger(op1)) 
        {
                x = atoi(op1);
                checktype=1;
        }
        else if (isFloat(op1))
         {
                y = atof(op1);
                checktype=2;
        } 
        else if (isChar(op1))
        {
                z=op[1];
                checktype=3;
        } 
        else
        {
            isArray(op1);
                char r[50]; 
                strcpy(r, findType(op1));
                if(strcmp(r,"int")==0)
                {
                    checktype=1;
                    x=getintVal(op1);
                }
                else if(strcmp(r,"real")==0)
                {
                    checktype=2;
                    y=getrealVal(op1);
                }
                else if(strcmp(r,"char")==0)
                {
                    checktype=3;
                    z=getcharVal(op1);
                }
                else if(strcmp(r,"boolean")==0)
                {
                        checktype=4;
                        b=getboolVal(op1);

                }
        }
        if (isInteger(op2)) 
        {
                x1 = atoi(op2);
                checktype=1;
        }
        else if (isFloat(op2))
         {
                 y1 = atof(op2);
                checktype=2;
        } 
        else if (isChar(op2))
        {
                z1=op2[1];
                checktype=3;
        } 
         else
        {
               isArray(op2);
                char r[50];
                strcpy(r, findType(op2));
                if(strcmp(r,"int")==0)
                {
                    checktype=1;
                    x1=getintVal(op2);
                }
                else if(strcmp(r,"real")==0)
                {
                    checktype=2;
                    y1=getrealVal(op2);
                }
                else if(strcmp(r,"char")==0)
                {
                    checktype=3;
                   z1=getcharVal(op2);
                }
                else if(strcmp(r,"boolean")==0)
                {
                        checktype=4;
                        b1=getboolVal(op1);

                }
        }
        if(strcmp(op,">")==0)
        {
                if(checktype==1)
                {
                    if(x>x1)
                    { return 1;}
                    else 
                    { return 0;}
                 }
                else if(checktype==2)
                {
                    if(y>y1)
                    return 1;
                    else 
                    return 0;
                   
                }
                else if(checktype==3)
                {
                    if(z>z1)
                         return 1;
                    else 
                        return 0;
                }
        }
        else if(strcmp(op,"<")==0)
        {
                if(checktype==1)
                {
                    if(x<x1)
                        return 1;
                    else 
                        return 0;
                }
                else if(checktype==2)
                {
                    if(y<y1)
                        return 1;
                    else 
                        return 0;
                }
                else if(checktype==3)
                {
                    if(z<z1)
                        return 1;
                    else 
                        return 0;
                 }
         }
        return 0;
}
void evalTAC(char* lhs, char* op, char *op1, char *op2)
{
    int checktype1=0,checktype2;
    int x;float y;char z;int b;
    int x1;float y1;char z1;int b1;

    if(op1[0]!='\0')
    {
       if (isInteger(op1)) 
        {
                x = atoi(op1);
                checktype1=1;
        }
        else if (isFloat(op1))
         {
                y = atof(op1);
                checktype1=2;
        } 
        else if (isChar(op1))
        {
                z=op[1];
                checktype1=3;
        } 
        else
        {
                isArray(op1);
               
                char r[50]; 
                strcpy(r, findType(op1));
                if(strcmp(r,"int")==0)
                {
                    checktype1=1;
                    x=getintVal(op1);
                }
                else if(strcmp(r,"real")==0)
                {
                    checktype1=2;
                    y=getrealVal(op1);
                }
                else if(strcmp(r,"char")==0)
                {
                    checktype1=3;
                   z=getcharVal(op1);
                }
                else if(strcmp(r,"bool")==0)
                {
                        checktype1=4;
                        b=getboolVal(op1);

                }
                //printf("%s is a variable.\n", rhs);
        }
    }
    else
    {
        if(strcasecmp(op,"and")==0)
        {
                        checktype1=4;
                        b=1;
                        //printf("yoy and");
        }
        else if (strcmp(op,"-")==0)
        {
                    checktype1=1;
                    x=0;
                    //printf("yoy minus");
        }
    }
         if (isInteger(op2))
          {
                x1 = atoi(op2);
                checktype2=1;
          }
          else if (isFloat(op2)) 
          {
                y1 = atof(op2);
                checktype2=2;
           } 
          else if (isChar(op2))
           {
                z1=op2[1];
                checktype2=3;
           } 
           else
            {
                 isArray(op2);
               char r[50];
                strcpy(r, findType(op2));
                if(strcmp(r,"int")==0)
                {
                    checktype2=1;
                    x1=getintVal(op2);
                }
                else if(strcmp(r,"real")==0)
                {
                    checktype2=2;
                    y1=getrealVal(op2);
                }
                else if(strcmp(r,"char")==0)
                {
                   checktype2=3;
                   z1=getcharVal(op2);
                }
                else if(strcmp(r,"bool")==0)
                {
                        checktype2=4;
                        b1=getboolVal(op1);

                }
                //printf("%s is a variable.\n", rhs);
            }
            if(strcmp(op,"+")==0)
            {
                if(checktype1==1 && checktype2==1)
                {
                    insertintValue(lhs,x+x1);
                    setType(lhs,"integer");
                }
                else if(checktype1==1 && checktype2==2)
                {
                    insertrealValue(lhs,x+y1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==1)
                {
                    insertrealValue(lhs,y+x1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    insertrealValue(lhs,y+y1);
                    setType(lhs,"real");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    insertcharValue(lhs,z+z1);
                    setType(lhs,"char");
                }
            }
            else if(strcmp(op,"-")==0)
            {
                if(checktype1==1 && checktype2==1)
                {
                    insertintValue(lhs,x-x1);
                    setType(lhs,"integer");
                }
                else if(checktype1==1 && checktype2==2)
                {
                    insertrealValue(lhs,x-y1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==1)
                {
                    insertrealValue(lhs,y-x1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    insertrealValue(lhs,y-y1);
                    setType(lhs,"real");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    insertcharValue(lhs,z-z1);
                    setType(lhs,"char");
                }
            }
            else if(strcmp(op,"*")==0)
            {
                if(checktype1==1 && checktype2==1)
                {
                    insertintValue(lhs,x*x1);
                    setType(lhs,"integer");
                }
                else if(checktype1==1 && checktype2==2)
                {
                    insertrealValue(lhs,x*y1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==1)
                {
                    insertrealValue(lhs,y*x1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    insertrealValue(lhs,y*y1);
                    setType(lhs,"real");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    insertcharValue(lhs,z*z1);
                    setType(lhs,"char");
                }
            }
            else if(strcmp(op,"/")==0)
            {
                if(checktype1==1 && checktype2==1)
                {
                    insertintValue(lhs,x/x1);
                    setType(lhs,"int");
                }
                else if(checktype1==1 && checktype2==2)
                {
                    insertrealValue(lhs,x/y1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==1)
                {
                    insertrealValue(lhs,y/x1);
                    setType(lhs,"real");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    insertrealValue(lhs,y/y1);
                    setType(lhs,"real");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    insertcharValue(lhs,z/z1);
                    setType(lhs,"char");
                }
            }
            else if(strcmp(op,"%")==0)
            {
                if(checktype1==1 && checktype2==1)
                {
                    insertintValue(lhs,x%x1);
                    setType(lhs,"integer");
                }

            }
            else if(strcmp(op,">")==0)
            {
                if(checktype1==1 && checktype2==1 )
                {
                    if(x>x1)
                    {insertboolVal(lhs,1);}
                    else 
                    {insertboolVal(lhs,0);}
                    setType(lhs,"bool");
                }
                else if((checktype1==2 && checktype2==2 ))
                {
                    if(y>y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if((checktype1==3 && checktype2==3 ))
                {
                    if(z>z1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcmp(op,"<")==0)
            {
               if(checktype1==1 && checktype2==1 )
                {
                    if(x<x1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==2 && checktype2==2 )
                {
                    if(y<y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    if(z<z1)
                        insertboolVal(lhs,1);
                    else 
                         insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcmp(op,">=")==0)
            {
                 if(checktype1==1 && checktype2==1)
                {
                    if(x>=x1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else  if(checktype1==2 && checktype2==2)
                {
                    if(y>=y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else  if(checktype1==3 && checktype2==3)
                {
                    if(z>=z1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcmp(op,"<=")==0)
            {
                 if(checktype1==1 && checktype2==1)
                {
                    if(x<=x1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    if(y<=y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    if(z<=z1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcmp(op,"=")==0)
            {
                 if(checktype1==1 && checktype2==1)
                {
                    if(x==x1)
                             insertboolVal(lhs,1);
                    else 
                            insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    if(y==y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    if(z==z1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcmp(op,"<>")==0)
            {
                 if(checktype1==1 && checktype2==1)
                {
                    if(x!=x1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==2 && checktype2==2)
                {
                    if(y!=y1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
                else if(checktype1==3 && checktype2==3)
                {
                    if(z!=z1)
                        insertboolVal(lhs,1);
                    else 
                        insertboolVal(lhs,0);
                    setType(lhs,"bool");
                }
            }
            else if(strcasecmp(op,"and")==0)
            {
                if(b==1 && b1==1)
                {
                    insertboolVal(lhs,1);setType(lhs,"bool");
                }
                else
                {
                    insertboolVal(lhs,0);setType(lhs,"bool");
                }
             }
            else if(strcasecmp(op,"or")==0)
            {
                if(b==1 || b1==1)
                {
                    insertboolVal(lhs,1);setType(lhs,"bool");
                }
                else
                {
                    insertboolVal(lhs,0);setType(lhs,"bool");
                }
            
            }
}
void label_statement(int label,int check)
{
    if(check==1)
    {
            num[str]=1;
            sprintf(tac[str++],"I%d:", label);
    }
    else if(check==2)
    {
        num[str]=1;
        sprintf(tac[str++],"W%d:", label);
    }
    else if(check==3)
    {
        num[str]=1;
        sprintf(tac[str++],"F%d:", label);
    }
}


#line 1067 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DOWNTO = 258,                  /* DOWNTO  */
    UMINUS = 259,                  /* UMINUS  */
    PROGRAM = 260,                 /* PROGRAM  */
    ID = 261,                      /* ID  */
    SC = 262,                      /* SC  */
    TYPE = 263,                    /* TYPE  */
    EQ = 264,                      /* EQ  */
    ARR = 265,                     /* ARR  */
    OF = 266,                      /* OF  */
    COMMENT = 267,                 /* COMMENT  */
    COLON = 268,                   /* COLON  */
    BEG = 269,                     /* BEG  */
    READ = 270,                    /* READ  */
    OB = 271,                      /* OB  */
    CB = 272,                      /* CB  */
    WRITE = 273,                   /* WRITE  */
    STRING = 274,                  /* STRING  */
    COMMA = 275,                   /* COMMA  */
    FOR = 276,                     /* FOR  */
    ASSIGN = 277,                  /* ASSIGN  */
    DO = 278,                      /* DO  */
    INT_LITERAL = 279,             /* INT_LITERAL  */
    REAL_LITERAL = 280,            /* REAL_LITERAL  */
    BOOLEAN_LITERAL = 281,         /* BOOLEAN_LITERAL  */
    CHAR_LITERAL = 282,            /* CHAR_LITERAL  */
    VAR = 283,                     /* VAR  */
    NOTEQ = 284,                   /* NOTEQ  */
    LT = 285,                      /* LT  */
    GT = 286,                      /* GT  */
    GTEQ = 287,                    /* GTEQ  */
    LTEQ = 288,                    /* LTEQ  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    NOT = 296,                     /* NOT  */
    IF = 297,                      /* IF  */
    THEN = 298,                    /* THEN  */
    ELSE = 299,                    /* ELSE  */
    END = 300,                     /* END  */
    DOT = 301,                     /* DOT  */
    INT = 302,                     /* INT  */
    REAL = 303,                    /* REAL  */
    CHAR = 304,                    /* CHAR  */
    BOOLEAN = 305,                 /* BOOLEAN  */
    TO = 306,                      /* TO  */
    WHILE = 307,                   /* WHILE  */
    ARRAY = 308,                   /* ARRAY  */
    OPENBRAC = 309,                /* OPENBRAC  */
    CLOSEBRAC = 310,               /* CLOSEBRAC  */
    OPENPARA = 311,                /* OPENPARA  */
    CLOSEPARA = 312                /* CLOSEPARA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DOWNTO 258
#define UMINUS 259
#define PROGRAM 260
#define ID 261
#define SC 262
#define TYPE 263
#define EQ 264
#define ARR 265
#define OF 266
#define COMMENT 267
#define COLON 268
#define BEG 269
#define READ 270
#define OB 271
#define CB 272
#define WRITE 273
#define STRING 274
#define COMMA 275
#define FOR 276
#define ASSIGN 277
#define DO 278
#define INT_LITERAL 279
#define REAL_LITERAL 280
#define BOOLEAN_LITERAL 281
#define CHAR_LITERAL 282
#define VAR 283
#define NOTEQ 284
#define LT 285
#define GT 286
#define GTEQ 287
#define LTEQ 288
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define MOD 293
#define AND 294
#define OR 295
#define NOT 296
#define IF 297
#define THEN 298
#define ELSE 299
#define END 300
#define DOT 301
#define INT 302
#define REAL 303
#define CHAR 304
#define BOOLEAN 305
#define TO 306
#define WHILE 307
#define ARRAY 308
#define OPENBRAC 309
#define CLOSEBRAC 310
#define OPENPARA 311
#define CLOSEPARA 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 996 "VAPS5421.y"

    char* lexeme;

#line 1238 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '-'  */
  YYSYMBOL_DOWNTO = 4,                     /* DOWNTO  */
  YYSYMBOL_UMINUS = 5,                     /* UMINUS  */
  YYSYMBOL_PROGRAM = 6,                    /* PROGRAM  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_SC = 8,                         /* SC  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_ARR = 11,                       /* ARR  */
  YYSYMBOL_OF = 12,                        /* OF  */
  YYSYMBOL_COMMENT = 13,                   /* COMMENT  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_BEG = 15,                       /* BEG  */
  YYSYMBOL_READ = 16,                      /* READ  */
  YYSYMBOL_OB = 17,                        /* OB  */
  YYSYMBOL_CB = 18,                        /* CB  */
  YYSYMBOL_WRITE = 19,                     /* WRITE  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_INT_LITERAL = 25,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 26,              /* REAL_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 27,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 28,              /* CHAR_LITERAL  */
  YYSYMBOL_VAR = 29,                       /* VAR  */
  YYSYMBOL_NOTEQ = 30,                     /* NOTEQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GTEQ = 33,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 34,                      /* LTEQ  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_MUL = 37,                       /* MUL  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_MOD = 39,                       /* MOD  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_THEN = 44,                      /* THEN  */
  YYSYMBOL_ELSE = 45,                      /* ELSE  */
  YYSYMBOL_END = 46,                       /* END  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_INT = 48,                       /* INT  */
  YYSYMBOL_REAL = 49,                      /* REAL  */
  YYSYMBOL_CHAR = 50,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 51,                   /* BOOLEAN  */
  YYSYMBOL_TO = 52,                        /* TO  */
  YYSYMBOL_WHILE = 53,                     /* WHILE  */
  YYSYMBOL_ARRAY = 54,                     /* ARRAY  */
  YYSYMBOL_OPENBRAC = 55,                  /* OPENBRAC  */
  YYSYMBOL_CLOSEBRAC = 56,                 /* CLOSEBRAC  */
  YYSYMBOL_OPENPARA = 57,                  /* OPENPARA  */
  YYSYMBOL_CLOSEPARA = 58,                 /* CLOSEPARA  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_start = 60,                     /* start  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_program_name = 62,              /* program_name  */
  YYSYMBOL_var_dec_sec = 63,               /* var_dec_sec  */
  YYSYMBOL_var_dec_list = 64,              /* var_dec_list  */
  YYSYMBOL_var_dec = 65,                   /* var_dec  */
  YYSYMBOL_id_list = 66,                   /* id_list  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_main_prog_block = 68,           /* main_prog_block  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_stmt_block = 70,                /* stmt_block  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_assign_stmt = 72,               /* assign_stmt  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_conditional_stmt = 76,          /* conditional_stmt  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_v = 79,                         /* v  */
  YYSYMBOL_value = 80,                     /* value  */
  YYSYMBOL_maybe_else_block = 81,          /* maybe_else_block  */
  YYSYMBOL_82_4 = 82,                      /* $@4  */
  YYSYMBOL_bool_expr = 83,                 /* bool_expr  */
  YYSYMBOL_e = 84,                         /* e  */
  YYSYMBOL_rel_op = 85,                    /* rel_op  */
  YYSYMBOL_loop_stmt = 86,                 /* loop_stmt  */
  YYSYMBOL_87_5 = 87,                      /* $@5  */
  YYSYMBOL_88_6 = 88,                      /* $@6  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_90_8 = 90,                      /* $@8  */
  YYSYMBOL_read_stmt = 91,                 /* read_stmt  */
  YYSYMBOL_read_list = 92,                 /* read_list  */
  YYSYMBOL_read_id = 93,                   /* read_id  */
  YYSYMBOL_arr = 94,                       /* arr  */
  YYSYMBOL_write_stmt = 95,                /* write_stmt  */
  YYSYMBOL_write_param = 96,               /* write_param  */
  YYSYMBOL_97_9 = 97                       /* $@9  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
       2,     2,     2,     2,     2,     3,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  1012,  1012,  1015,  1018,  1021,  1024,  1025,  1028,  1031,
    1032,  1033,  1036,  1037,  1038,  1039,  1040,  1043,  1043,  1045,
    1046,  1047,  1049,  1050,  1051,  1052,  1053,  1056,  1057,  1059,
    1065,  1071,  1073,  1079,  1085,  1091,  1095,  1096,  1097,  1098,
    1099,  1106,  1106,  1111,  1111,  1117,  1118,  1119,  1120,  1123,
    1124,  1125,  1126,  1127,  1131,  1132,  1132,  1138,  1142,  1146,
    1150,  1154,  1155,  1159,  1163,  1167,  1171,  1175,  1179,  1183,
    1188,  1193,  1194,  1195,  1196,  1197,  1198,  1201,  1201,  1206,
    1206,  1213,  1213,  1222,  1222,  1234,  1236,  1236,  1237,  1238,
    1240,  1240,  1241,  1244,  1245,  1246,  1246,  1247
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
  "\"end of file\"", "error", "\"invalid token\"", "'-'", "DOWNTO",
  "UMINUS", "PROGRAM", "ID", "SC", "TYPE", "EQ", "ARR", "OF", "COMMENT",
  "COLON", "BEG", "READ", "OB", "CB", "WRITE", "STRING", "COMMA", "FOR",
  "ASSIGN", "DO", "INT_LITERAL", "REAL_LITERAL", "BOOLEAN_LITERAL",
  "CHAR_LITERAL", "VAR", "NOTEQ", "LT", "GT", "GTEQ", "LTEQ", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE",
  "END", "DOT", "INT", "REAL", "CHAR", "BOOLEAN", "TO", "WHILE", "ARRAY",
  "OPENBRAC", "CLOSEBRAC", "OPENPARA", "CLOSEPARA", "$accept", "start",
  "program", "program_name", "var_dec_sec", "var_dec_list", "var_dec",
  "id_list", "type", "main_prog_block", "$@1", "stmt_block", "stmt",
  "assign_stmt", "expr", "term", "factor", "conditional_stmt", "$@2",
  "$@3", "v", "value", "maybe_else_block", "$@4", "bool_expr", "e",
  "rel_op", "loop_stmt", "$@5", "$@6", "$@7", "$@8", "read_stmt",
  "read_list", "read_id", "arr", "write_stmt", "write_param", "$@9", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,     5,    69,  -143,  -143,   103,  -143,    86,     4,   107,
      63,    75,   125,  -143,    11,  -143,  -143,  -143,   255,   183,
       4,   238,   129,    24,  -143,  -143,   255,  -143,  -143,  -143,
    -143,  -143,   255,   -29,   127,  -143,  -143,    92,  -143,  -143,
    -143,  -143,  -143,    87,  -143,  -143,   118,   132,   130,   133,
       8,   209,   209,   153,  -143,  -143,  -143,  -143,  -143,  -143,
      70,  -143,   255,   255,  -143,   255,   255,   255,   115,   183,
     255,   255,    55,     6,     0,    -2,    41,   232,   209,   275,
      88,   112,    56,    79,    91,  -143,   127,   127,  -143,  -143,
    -143,   183,   122,   -15,   -15,  -143,  -143,   154,   155,   158,
    -143,  -143,   157,   255,   255,    23,    43,   266,    52,    50,
    -143,  -143,   131,  -143,  -143,  -143,  -143,  -143,   255,   209,
     209,  -143,   209,   209,  -143,  -143,  -143,   136,  -143,   141,
     139,  -143,    55,   159,  -143,    21,    90,  -143,  -143,  -143,
     255,  -143,   -15,  -143,  -143,   145,   148,    24,  -143,  -143,
     145,   148,    24,   174,   179,  -143,  -143,   183,  -143,     6,
    -143,  -143,   -15,    36,    36,    24,    24,   143,  -143,   187,
     191,    24,    24,  -143,  -143,   192,   204,   201,    24,    24,
     207,   105,   124,   238,   210,   211,   138,  -143,  -143,  -143,
     152,   171,   176,  -143,  -143,   177,   208,    24,   217,   185,
    -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,     0,     0,
       9,     0,     0,     6,     0,    11,    17,     3,     0,     0,
       5,     0,     0,    21,    36,    39,     0,    53,    49,    50,
      51,    52,     0,     0,    31,    35,    37,     0,     7,    12,
      13,    14,    15,     0,     8,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    25,    26,    24,    22,    23,
       0,    40,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    29,    30,    32,    33,
      34,     0,     0,    28,    27,    88,    89,     0,    86,    93,
      97,    94,     0,     0,     0,    36,    39,     0,     0,     0,
      68,    58,    71,    72,    73,    74,    76,    75,     0,     0,
       0,    43,     0,     0,    41,    79,    77,     0,    20,     0,
       0,    85,     0,     0,    92,     0,     0,    46,    48,    61,
       0,    69,    57,    63,    66,    62,    65,    21,    67,    59,
      64,    60,    21,     0,     0,    18,    91,     0,    87,     0,
      83,    81,    70,     0,     0,    21,    21,     0,    96,     0,
       0,     0,    21,    44,    42,     0,     0,     0,    21,    21,
       0,     0,     0,     0,     0,     0,     0,    80,    78,    16,
       0,     0,    54,    84,    82,     0,     0,    21,     0,     0,
      56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -143,  -143,   212,  -143,    44,  -143,
    -143,  -142,   -82,   180,   -17,    32,   -18,  -143,  -143,  -143,
     -49,   -19,    76,  -143,   -44,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,   101,  -143,  -143,  -143,    82,  -143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     9,    12,    13,    14,    44,    17,
      23,    53,    54,    55,    79,    34,    35,    56,   152,   147,
      80,    36,   173,   195,    81,   141,   118,    57,   154,   153,
     170,   169,    58,    97,    98,    15,    59,   102,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    33,   128,    82,   103,   163,    62,    63,    83,    60,
     164,    10,     4,    99,    61,    46,   -45,   100,     1,    47,
      62,    63,   -45,   175,   176,    21,   101,    64,   108,   110,
     180,    46,    22,   109,   111,    47,   184,   185,   -45,   -45,
      48,   137,   -45,    49,   171,   160,    50,    88,    89,    90,
      92,   172,   104,    93,    94,   198,    62,    63,    11,   -47,
     107,   138,    95,   -45,   -45,   -47,    96,    51,   139,     6,
     143,   145,   129,   148,   150,   144,   146,    52,   149,   151,
     125,   -47,   -47,   -47,   -47,   -47,   135,   136,    85,   128,
     122,   123,   119,   120,    86,    87,   119,   120,    46,   128,
     128,   142,    47,   126,   128,    62,    63,    48,   128,   128,
      49,     7,    46,    50,   161,     8,    47,   128,    18,   122,
     123,    48,    16,   162,    49,    62,    63,    50,   119,   120,
      19,    46,   121,    20,    51,    47,    45,   127,   167,    68,
      48,    70,    69,    49,    52,    46,    50,    72,    51,    47,
      73,   187,   122,   123,    48,    71,   124,    49,    52,    46,
      50,    84,    91,    47,    65,    66,    67,    51,    48,   130,
     188,    49,   131,   140,    50,   134,   132,    52,    46,   -95,
     159,    51,    47,   155,   192,   119,   157,    48,   122,   165,
      49,    52,    46,    50,   166,    51,    47,   156,   193,   177,
     181,    48,   178,    27,    49,    52,   179,    50,    28,    29,
      30,    31,   182,   183,    51,   186,    75,   194,   190,   191,
      76,   -55,   196,   197,    52,   199,    77,   189,    51,    27,
      74,   200,    38,   158,    28,    29,    30,    31,    52,   105,
     174,   168,     0,   106,     0,    32,     0,     0,     0,    77,
       0,    78,    27,     0,     0,     0,     0,    28,    29,    30,
      31,     0,    24,     0,     0,     0,    25,     0,    32,     0,
       0,     0,    26,     0,    78,    27,   112,     0,     0,     0,
      28,    29,    30,    31,    85,   112,    39,    40,    41,    42,
       0,    32,    43,     0,     0,     0,   113,   114,   115,   116,
     117,    62,    63,     0,     0,   113,   114,   115,   116,   117,
      62,    63
};

static const yytype_int16 yycheck[] =
{
      19,    18,    84,    52,     4,   147,    35,    36,    52,    26,
     152,     7,     7,     7,    32,     7,    18,    11,     6,    11,
      35,    36,    24,   165,   166,    14,    20,    56,    77,    78,
     172,     7,    21,    77,    78,    11,   178,   179,    40,    41,
      16,    18,    44,    19,     8,    24,    22,    65,    66,    67,
      69,    15,    52,    70,    71,   197,    35,    36,    54,    18,
      77,    18,     7,    40,    41,    24,    11,    43,    18,     0,
     119,   120,    91,   122,   123,   119,   120,    53,   122,   123,
      24,    40,    41,    40,    41,    44,   103,   104,    18,   171,
      40,    41,    40,    41,    62,    63,    40,    41,     7,   181,
     182,   118,    11,    24,   186,    35,    36,    16,   190,   191,
      19,     8,     7,    22,    24,    29,    11,   199,    55,    40,
      41,    16,    15,   140,    19,    35,    36,    22,    40,    41,
      55,     7,    44,     8,    43,    11,     7,    46,   157,    47,
      16,    23,    55,    19,    53,     7,    22,    17,    43,    11,
      17,    46,    40,    41,    16,    23,    44,    19,    53,     7,
      22,     8,    47,    11,    37,    38,    39,    43,    16,    47,
      46,    19,    18,    42,    22,    18,    21,    53,     7,    21,
      21,    43,    11,    47,    46,    40,    47,    16,    40,    15,
      19,    53,     7,    22,    15,    43,    11,    56,    46,    56,
       8,    16,    15,    20,    19,    53,    15,    22,    25,    26,
      27,    28,     8,    12,    43,     8,     7,    46,     8,     8,
      11,    45,    45,    15,    53,     8,    17,   183,    43,    20,
      50,    46,    20,   132,    25,    26,    27,    28,    53,     7,
     164,   159,    -1,    11,    -1,    36,    -1,    -1,    -1,    17,
      -1,    42,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,     7,    -1,    -1,    -1,    11,    -1,    36,    -1,
      -1,    -1,    17,    -1,    42,    20,    10,    -1,    -1,    -1,
      25,    26,    27,    28,    18,    10,    48,    49,    50,    51,
      -1,    36,    54,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    60,    61,     7,    62,     0,     8,    29,    63,
       7,    54,    64,    65,    66,    94,    15,    68,    55,    55,
       8,    14,    21,    69,     7,    11,    17,    20,    25,    26,
      27,    28,    36,    73,    74,    75,    80,    80,    65,    48,
      49,    50,    51,    54,    67,     7,     7,    11,    16,    19,
      22,    43,    53,    70,    71,    72,    76,    86,    91,    95,
      73,    75,    35,    36,    56,    37,    38,    39,    47,    55,
      23,    23,    17,    17,    72,     7,    11,    17,    42,    73,
      79,    83,    79,    83,     8,    18,    74,    74,    75,    75,
      75,    47,    80,    73,    73,     7,    11,    92,    93,     7,
      11,    20,    96,     4,    52,     7,    11,    73,    79,    83,
      79,    83,    10,    30,    31,    32,    33,    34,    85,    40,
      41,    44,    40,    41,    44,    24,    24,    46,    71,    80,
      47,    18,    21,    97,    18,    73,    73,    18,    18,    18,
      42,    84,    73,    79,    83,    79,    83,    78,    79,    83,
      79,    83,    77,    88,    87,    47,    56,    47,    92,    21,
      24,    24,    73,    70,    70,    15,    15,    80,    96,    90,
      89,     8,    15,    81,    81,    70,    70,    56,    15,    15,
      70,     8,     8,    12,    70,    70,     8,    46,    46,    67,
       8,     8,    46,    46,    46,    82,    45,    15,    70,     8,
      46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    69,    68,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    77,    76,    78,    76,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    81,    82,    81,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    85,    85,    85,    85,    85,    87,    86,    88,
      86,    89,    86,    90,    86,    91,    92,    92,    93,    93,
      94,    94,    95,    96,    96,    97,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     0,     6,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     3,     1,
       2,     0,     6,     0,     6,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     4,     0,    10,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     0,     8,     0,
       8,     0,    10,     0,    10,     4,     1,     3,     1,     1,
       4,     7,     4,     1,     1,     0,     4,     1
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
  case 2: /* start: program  */
#line 1012 "VAPS5421.y"
                {  }
#line 2473 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 1043 "VAPS5421.y"
                      {checkMulDec();assignType();}
#line 2479 "y.tab.c"
    break;

  case 27: /* assign_stmt: ARR ASSIGN expr  */
#line 1056 "VAPS5421.y"
                               {assignment((yyvsp[-2].lexeme), (yyvsp[0].lexeme));}
#line 2485 "y.tab.c"
    break;

  case 28: /* assign_stmt: ID ASSIGN expr  */
#line 1057 "VAPS5421.y"
                              {assignment((yyvsp[-2].lexeme), (yyvsp[0].lexeme));}
#line 2491 "y.tab.c"
    break;

  case 29: /* expr: expr PLUS term  */
#line 1059 "VAPS5421.y"
                     {
                            int a = gencode((yyvsp[-2].lexeme), "+", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2502 "y.tab.c"
    break;

  case 30: /* expr: expr MINUS term  */
#line 1065 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "-", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2513 "y.tab.c"
    break;

  case 31: /* expr: term  */
#line 1071 "VAPS5421.y"
            {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2519 "y.tab.c"
    break;

  case 32: /* term: term MUL factor  */
#line 1073 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "*", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2530 "y.tab.c"
    break;

  case 33: /* term: term DIV factor  */
#line 1079 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "/", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2541 "y.tab.c"
    break;

  case 34: /* term: term MOD factor  */
#line 1085 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "%", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2552 "y.tab.c"
    break;

  case 35: /* term: factor  */
#line 1091 "VAPS5421.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2558 "y.tab.c"
    break;

  case 36: /* factor: ID  */
#line 1095 "VAPS5421.y"
             {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2564 "y.tab.c"
    break;

  case 37: /* factor: value  */
#line 1096 "VAPS5421.y"
               {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2570 "y.tab.c"
    break;

  case 38: /* factor: OB expr CB  */
#line 1097 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 2576 "y.tab.c"
    break;

  case 39: /* factor: ARR  */
#line 1098 "VAPS5421.y"
             {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2582 "y.tab.c"
    break;

  case 40: /* factor: MINUS factor  */
#line 1099 "VAPS5421.y"
                                    {
                            int a = gencode("", "-", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 2593 "y.tab.c"
    break;

  case 41: /* $@2: %empty  */
#line 1106 "VAPS5421.y"
                                      {
                        conditional_jump((yyvsp[-1].lexeme), iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    }
#line 2603 "y.tab.c"
    break;

  case 43: /* $@3: %empty  */
#line 1111 "VAPS5421.y"
                                 {
                        conditional_jump((yyvsp[-1].lexeme), iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    }
#line 2613 "y.tab.c"
    break;

  case 45: /* v: ID  */
#line 1117 "VAPS5421.y"
       {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2619 "y.tab.c"
    break;

  case 46: /* v: OB ID CB  */
#line 1118 "VAPS5421.y"
               {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 2625 "y.tab.c"
    break;

  case 47: /* v: ARR  */
#line 1119 "VAPS5421.y"
          {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2631 "y.tab.c"
    break;

  case 48: /* v: OB ARR CB  */
#line 1120 "VAPS5421.y"
                {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 2637 "y.tab.c"
    break;

  case 49: /* value: INT_LITERAL  */
#line 1123 "VAPS5421.y"
                    {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2643 "y.tab.c"
    break;

  case 50: /* value: REAL_LITERAL  */
#line 1124 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2649 "y.tab.c"
    break;

  case 51: /* value: BOOLEAN_LITERAL  */
#line 1125 "VAPS5421.y"
                        {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2655 "y.tab.c"
    break;

  case 52: /* value: CHAR_LITERAL  */
#line 1126 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 2661 "y.tab.c"
    break;

  case 53: /* value: STRING  */
#line 1127 "VAPS5421.y"
               {(yyval.lexeme)=(yyvsp[0].lexeme);}
#line 2667 "y.tab.c"
    break;

  case 54: /* maybe_else_block: BEG stmt_block SC END  */
#line 1131 "VAPS5421.y"
                                         {label_statement(iflabel++,1);}
#line 2673 "y.tab.c"
    break;

  case 55: /* $@4: %empty  */
#line 1132 "VAPS5421.y"
                                         {unconditional_jump(iflabel + 1,1);label_statement(iflabel++,1);}
#line 2679 "y.tab.c"
    break;

  case 56: /* maybe_else_block: BEG stmt_block SC END $@4 ELSE BEG stmt_block SC END  */
#line 1132 "VAPS5421.y"
                                                                                                                                      {
                        label_statement(iflabel++,1);
                    }
#line 2687 "y.tab.c"
    break;

  case 57: /* bool_expr: expr rel_op expr  */
#line 1138 "VAPS5421.y"
                            {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2696 "y.tab.c"
    break;

  case 58: /* bool_expr: NOT bool_expr  */
#line 1142 "VAPS5421.y"
                         {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2705 "y.tab.c"
    break;

  case 59: /* bool_expr: bool_expr AND bool_expr  */
#line 1146 "VAPS5421.y"
                                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2714 "y.tab.c"
    break;

  case 60: /* bool_expr: bool_expr OR bool_expr  */
#line 1150 "VAPS5421.y"
                                  {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2723 "y.tab.c"
    break;

  case 61: /* bool_expr: OB bool_expr CB  */
#line 1154 "VAPS5421.y"
                            {(yyval.lexeme)=(yyvsp[-1].lexeme);}
#line 2729 "y.tab.c"
    break;

  case 62: /* bool_expr: v OR v  */
#line 1155 "VAPS5421.y"
                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2738 "y.tab.c"
    break;

  case 63: /* bool_expr: v AND v  */
#line 1159 "VAPS5421.y"
                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2747 "y.tab.c"
    break;

  case 64: /* bool_expr: bool_expr OR v  */
#line 1163 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2756 "y.tab.c"
    break;

  case 65: /* bool_expr: v OR bool_expr  */
#line 1167 "VAPS5421.y"
                         {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2765 "y.tab.c"
    break;

  case 66: /* bool_expr: v AND bool_expr  */
#line 1171 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2774 "y.tab.c"
    break;

  case 67: /* bool_expr: bool_expr AND v  */
#line 1175 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2783 "y.tab.c"
    break;

  case 68: /* bool_expr: NOT v  */
#line 1179 "VAPS5421.y"
                {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2792 "y.tab.c"
    break;

  case 69: /* bool_expr: expr EQ e  */
#line 1183 "VAPS5421.y"
                    {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2801 "y.tab.c"
    break;

  case 70: /* e: NOT expr  */
#line 1188 "VAPS5421.y"
             {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 2810 "y.tab.c"
    break;

  case 77: /* $@5: %empty  */
#line 1201 "VAPS5421.y"
                                {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump((yyvsp[-1].lexeme), whilelabel,2);
                }
#line 2820 "y.tab.c"
    break;

  case 78: /* loop_stmt: WHILE bool_expr DO $@5 BEG stmt_block SC END  */
#line 1205 "VAPS5421.y"
                                         {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
#line 2826 "y.tab.c"
    break;

  case 79: /* $@6: %empty  */
#line 1206 "VAPS5421.y"
                              {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump((yyvsp[-1].lexeme), whilelabel,2);
                   
                    
                }
#line 2838 "y.tab.c"
    break;

  case 80: /* loop_stmt: WHILE v DO $@6 BEG stmt_block SC END  */
#line 1212 "VAPS5421.y"
                                         {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
#line 2844 "y.tab.c"
    break;

  case 81: /* $@7: %empty  */
#line 1213 "VAPS5421.y"
                                       {
                   label_statement(forlabel++,3);
                    for_jump((yyvsp[-3].lexeme), forlabel,1,(yyvsp[-1].lexeme));
                }
#line 2853 "y.tab.c"
    break;

  case 82: /* loop_stmt: FOR assign_stmt TO expr DO $@7 BEG stmt_block SC END  */
#line 1216 "VAPS5421.y"
                                        {int a = gencode((yyvsp[-8].lexeme), "+", "1");
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode((yyvsp[-8].lexeme), "-", "1");
                            char* tempVar1 = genTempVariable(b);
                            (yyval.lexeme) = tempVar1;tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));}
#line 2864 "y.tab.c"
    break;

  case 83: /* $@8: %empty  */
#line 1222 "VAPS5421.y"
                                            {
                    label_statement(forlabel++,3);
                     for_jump((yyvsp[-3].lexeme), forlabel,2,(yyvsp[-1].lexeme));
                    
                }
#line 2874 "y.tab.c"
    break;

  case 84: /* loop_stmt: FOR assign_stmt DOWNTO expr DO $@8 BEG stmt_block SC END  */
#line 1226 "VAPS5421.y"
                                        {int a = gencode((yyvsp[-8].lexeme), "-", "1");
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode((yyvsp[-8].lexeme), "+", "1");
                            char* tempVar1 = genTempVariable(b);
                            (yyval.lexeme) = tempVar1;tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));}
#line 2885 "y.tab.c"
    break;

  case 88: /* read_id: ID  */
#line 1237 "VAPS5421.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);sprintf(tac[str++], "Read %s", (yyvsp[0].lexeme));}
#line 2891 "y.tab.c"
    break;

  case 89: /* read_id: ARR  */
#line 1238 "VAPS5421.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);sprintf(tac[str++], "Read %s", (yyvsp[0].lexeme));}
#line 2897 "y.tab.c"
    break;

  case 93: /* write_param: ID  */
#line 1244 "VAPS5421.y"
                 { sprintf(tac[str++], "Write %s", (yyvsp[0].lexeme)); }
#line 2903 "y.tab.c"
    break;

  case 94: /* write_param: STRING  */
#line 1245 "VAPS5421.y"
                     { sprintf(tac[str++], "Write %s", (yyvsp[0].lexeme)); }
#line 2909 "y.tab.c"
    break;

  case 95: /* $@9: %empty  */
#line 1246 "VAPS5421.y"
                 { sprintf(tac[str++], "Write %s", (yyvsp[0].lexeme)); }
#line 2915 "y.tab.c"
    break;

  case 97: /* write_param: ARR  */
#line 1247 "VAPS5421.y"
                  { sprintf(tac[str++], "Write %s", (yyvsp[0].lexeme)); }
#line 2921 "y.tab.c"
    break;


#line 2925 "y.tab.c"

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

#line 1250 "VAPS5421.y"

void yyerror()
{
    printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
     {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yyparse();
    int numInstructions=0;
    for (int i = 0; tac[i][0] != '\0'; i++) 
    {
        numInstructions++;
        
    }
     for (int i = 0; i < numInstructions; i++)
     {
        char temp[50];
        strcpy(temp, tac[i]);
        if(num[i]==0 && temp[0]=='R') // read statement
        {
            char secondPart[50];        
            char *ptr = strchr(temp, ' ');
            if (ptr != NULL) 
            {
                strcpy(secondPart, ptr + 1); 
                isArray(secondPart);
                char des[20];           
                strcpy(des, findType(secondPart));
                if(strcmp(des,"int")==0)
                {
                    int random;
                    scanf("%d", &random);
                    insertintValue(secondPart,random);
                }
                else if(strcmp(des,"real")==0)
                {
                    float random;
                    scanf("%f", &random);
                    insertrealValue(secondPart,random);
                }
                else if(strcmp(des,"char")==0)
                {
                    char random;
                    scanf(" %c", &random); 
                    insertcharValue(secondPart,random);
                }
            }      
            else  
            {
                        printf("No second part found in the string.\n");
            }   
        }
        else if(num[i]==0 && temp[0]=='W' && temp[6]=='"') // printing string
        {
                    const char* first_quote = strchr(temp, '"');
                    if (first_quote == NULL) 
                    {
                        printf("No double quotes found.\n");
                        return 1;
                    }
                    const char* second_quote = strchr(first_quote + 1, '"');
                    if (second_quote == NULL)
                    {
                        printf("No closing double quote found.\n");
                        return 1;
                    }
                    size_t length = second_quote - first_quote - 1;
                    char message[length + 1];
                    strncpy(message, first_quote + 1, length);
                    message[length] = '\0';
                    printf("%s\n",message);
        }
        else if(num[i]==0 && temp[0]=='W') //printing variables
        { 
                    char secondPart[20];
                    char *ptr = strchr(temp, ' ');
                    if (ptr != NULL) 
                    {
                        strcpy(secondPart, ptr + 1); 
                        isArray(secondPart);
                    }
                    else 
                    {
                        printf("No second part found in the string.\n");
                    }
                    char des[20];
                    strcpy(des, findType(secondPart));
                    if(strcmp(des,"int")==0)
                        printf("%d\n",getintVal(secondPart));
                    else if(strcmp(des,"real")==0)
                        printf("%.2f\n",getrealVal(secondPart));
                    else if(strcmp(des,"char")==0)
                        printf("%c\n",getcharVal(secondPart));
        }
        else if(num[i]==3)  //assignment part
        {
            char *lhs, *rhs;
            lhs = strtok(temp, "=");
            rhs = strtok(NULL, "=");
            lhs = trimit(lhs);
            rhs = trimit(rhs);
                    isArray(lhs);
            char r[50];
            if (isInteger(rhs))
            {
                        int hehe = atoi(rhs);
                        char ty[50];
                        strcpy(ty,findType(lhs));
                        //printf(ty);
                        if(strcmp(ty,"int")==0)
                            insertintValue(lhs,hehe);
                        else if(strcmp(ty,"real")==0)
                        {
                            float f=hehe;
                            insertrealValue(lhs,f);
                        }
                        else if(strcmp(ty,"bool")==0)
                        {
                            insertboolVal(lhs,hehe);
                        }
            }
            else if (isFloat(rhs))
            {
                        float hehe = atof(rhs);
                        insertrealValue(lhs,hehe);
            } 
            else if (isChar(rhs))
            {
                        char hehe=rhs[1];
                        insertcharValue(lhs,hehe);
            } 
            else 
                {       
                            isArray(rhs);
                            strcpy(r, findType(rhs));
                            if(strcmp(r,"int")==0)
                            {
                                char s[50];
                                strcpy(s,findType(lhs));
                                if(strcmp(s,"int")==0)
                                {
                                    int yy=getintVal(rhs);
                                    insertintValue(lhs,yy);
                                }
                                else if(strcmp(s,"real")==0)
                                {
                                    int yy=getintVal(rhs);
                                    float f=yy;
                                    insertrealValue(lhs,f);
                                }
                            }
                            else if(strcmp(r,"real")==0)
                            {
                                float yy=getrealVal(rhs);
                                insertrealValue(lhs,yy);
                            }
                            else if(strcmp(r,"char")==0)
                            {
                                char yy=getcharVal(rhs);
                                insertcharValue(lhs,yy);
                            }
               }
        }
        else if(num[i]==6) // for loop
        {
                        char op1[20];  // Operand 1
                        char op[3];    // Operator
                        char op2[20];  // Operand 2
                        char label[20]; // Label
                        char *token = strtok(temp, " "); // Skip the "If"
                        token = strtok(NULL, " ");  // Get the comparison operator
                        if (token != NULL) 
                        {
                            strcpy(op1, token);  // Store the first operand
                        }
                        token = strtok(NULL, " ");  // Get the comparison operator
                        if (token != NULL) {
                            strcpy(op, token);  // Store the comparison operator
                        }
                        token = strtok(NULL, " ");  // Get the second operand
                        if (token != NULL) {
                            strcpy(op2, token);  // Store the second operand
                        }
                        token = strtok(NULL, "");  // Get the rest of the string (including spaces)
                        if (token != NULL)
                        {
                            // Check if the token starts with "goto"
                            if (strncmp(token, "goto", 4) == 0) {
                                // If it does, extract the label after "goto"
                                strcpy(label, token + 5); // Skip "goto " and copy the rest to label
                            } else {
                                // If it doesn't, directly copy the token to label
                                strcpy(label, token);
                            }
                        }
            evalTAC("help",op,op1,op2);
            int vv=checktrueornot(op,op1,op2);
           if(vv==1)
            {
                    for(int y=i+1;y<numInstructions;y++)
                    {
                        if (strstr(tac[y], label) != NULL)
                         {
                            i=y;
                            break;
                        }
                    }
             }
        }
       else if(num[i]==5 && tac[i][0] != 'I' ) // a=b+c form
        {
            Expression expr;
            tokenize_expression(temp, &expr);
            strcpy(expr.lhs,trimit(expr.lhs));
            evalTAC(expr.lhs,expr.op,expr.operand1,expr.operand2);
        }
        else if(num[i]==5 && tac[i][0] == 'I') // if while and if 
        {
                char label1[4], label2[4];
                char *token = strtok(temp, " ");
                while (token != NULL) 
                {
                    if (strncmp(token, "T", 1) == 0) 
                    {
                        strcpy(label1, token); // Copy T label
                    } else if (strncmp(token, "W", 1) == 0 ) {
                        strcpy(label2, token); // Copy W or I label
                    }
                    token = strtok(NULL, " ");
                }
                int see=getboolVal(label1);
                if(see!=1)
                {
                    for(int y=i+1;y<numInstructions;y++)
                    {
                        if (strstr(tac[y], label2) != NULL)
                        {
                            i=y;
                            break;
                        }
                    }
                }
        }
       else if(num[i]==4)  
       {
                char label1[4] = "", label2[4] = "";
                char *token = strtok(temp, " ");
                int gotoFound = 0; // Flag to indicate if "goto" is found
    
                while (token != NULL) {
                    if (strcmp(token, "If") == 0) {
                        token = strtok(NULL, " "); // Move to the next token after "If"
                        continue; // Skip processing "If"
                    }
                    if (gotoFound) {
                        strcpy(label2, token); // Copy the label after "goto"
                        break; // Stop processing
                    }
                    if (strcmp(token, "goto") == 0) {
                        gotoFound = 1; // Set flag to indicate "goto" is found
                    } else if (label1[0] == '\0') {
                        strcpy(label1, token); // Copy the first label
                    }
                    token = strtok(NULL, " ");
                }
            
           
            int see=getboolVal(label1);
             //printf("%d\n",see);
            if(see==1)
            {
                for(int y=i+1;y<numInstructions;y++)
                {
                    if (strstr(tac[y], label2) != NULL)
                    {
                            i=y;
                            break;
                    }
                }
            }
       }
       else if(num[i]==2)
       {
        
                char* label = strstr(tac[i], " ");
                if (label != NULL) 
                {
                    label++; 
                } 
                else 
                {
                    //printf("Label not found in statement %d\n", i+1);
                }
                if(label[0]=='W' )
                {
                    for(int y=0;y<numInstructions;y++)
                        {
                            if (strstr(tac[y], label) != NULL) 
                            {
                                    i=y-2;
                                    break;
                            }
                        }
                }
                if(label[0]=='F' )
                    {
                            for(int y=0;y<numInstructions;y++)
                                {
                                    if (strstr(tac[y], label) != NULL) 
                                    {
                                            i=y;
                                            break;
                                    }
                                }
                    }
                if(label[0]=='I')
                {
                            for(int y=i+1;y<numInstructions;y++)
                                {
                                    if (strstr(tac[y], label) != NULL) 
                                    {
                                            i=y;
                                            break;
                                    }
                                }
                }
            
       }
       
    }
    printf("Symbol Table:\n");

    // Print top border
    printf("+-----------------+----------------------------------------+----------+\n");
    // Print column headers
    printf("| %-15s | %-38s | %-8s |\n", "Variable", "Type", "Value");
    // Print header-row separator
    printf("+-----------------+----------------------------------------+----------+\n");

    // Print table rows
    for (int j = 0; j < counter; j++) {
        if (initialised[j] == 1 && final_dec_var[j][0] != 'T') {
            printf("| %-15s | %-38s | ", final_dec_var[j], declared_type[j]);

            if (strcasecmp(declared_type[j], "integer") == 0 || strcmp(declared_type[j], "Integer") == 0) {
                printf("%-8d", int_value[j]);
            } else if (strcasecmp(declared_type[j], "real") == 0 || strcmp(declared_type[j], "Real") == 0) {
                printf("%-8.2f", float_value[j]);
            } else if (strcasecmp(declared_type[j], "char") == 0) {
                printf("%-8c", char_value[j]);
            }
            else if (strcasecmp(declared_type[j], "boolean") == 0 || strcmp(declared_type[j], "Boolean") == 0)
            {
                printf("%-8d", bool_val[j]);
            }
            printf(" |\n");
        }
    }

    // Print bottom border
    printf("+-----------------+----------------------------------------+----------+\n");
   fclose(file);
    return 0;
}
