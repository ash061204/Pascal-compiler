%{
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
%type <lexeme> read_id write_param factor assign_stmt bool_expr value expr arr rel_op term loop_stmt e v
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

main_prog_block : BEG {checkMulDec();assignType();} stmt_block SC END DOT
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

value : INT_LITERAL {$$ = $1;}
      | REAL_LITERAL {$$ = $1;}
      | BOOLEAN_LITERAL {$$ = $1;}
      | CHAR_LITERAL {$$ = $1;}
      | STRING {$$=$1;}
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
read_id : ID  {$$ = $1;sprintf(tac[str++], "Read %s", $1);}
        | ARR {$$ = $1;sprintf(tac[str++], "Read %s", $1);}
        ;
arr :  ID OPENBRAC expr CLOSEBRAC | ARRAY OPENBRAC value DOT DOT value CLOSEBRAC ;
write_stmt :  WRITE OB write_param CB 
              ;  

write_param : ID { sprintf(tac[str++], "Write %s", $1); }
            | STRING { sprintf(tac[str++], "Write %s", $1); }
            | ID { sprintf(tac[str++], "Write %s", $1); } COMMA write_param 
            | ARR { sprintf(tac[str++], "Write %s", $1); }
            ;

%%
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