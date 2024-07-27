%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern FILE* yyin;
int line = 1;
enum keywords {PROGRAM=1,TYPE,IF,THEN, ELSE, INT, REAL, BOOLEAN, CHAR,VAR,FOR, DO, TO, WHILE, ARRAY, AND, OR, NOT, BEG, END, OF, READ, WRITE, DIVOP};
enum operators {PLUS=100, MINUS, MUL, DIV, MOD, EQ, LT, GT, LTEQ, GTEQ, NOTEQ, ASSIGN};
enum seperators {COLON=200, SC, COMMA, OB, CB, OPENPARA, CLOSEPARA, OPENBRAC, CLOSEBRAC, DOT,NL};
enum literals {INT_LITERAL=400, REAL_LITERAL,BOOLEAN_LITERAL,CHAR_LITERAL, ID, STRING, ARR };
enum unknown {UNKNOWN=500};
%}

LETTER [a-zA-Z]
DIGIT [0-9]
UNDERSCORE [_]
NEWLINE [\n]
SPACE [' ']
TAB ['\t']
NUM {DIGIT}+(\.{DIGIT}+)?
STRING \"[ ]*([^\"\n]*)[ ]*\"|['][ ]*([^\"\n]*)[ ]*[']
VAR {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

%x SLC
%%
{NEWLINE} {line++;}
{SPACE} {;}
{TAB} {;}
"//" {BEGIN(SLC);}
<SLC>.  {}
<SLC>\n { line++;BEGIN(INITIAL);}
[p|P][r|R][o|O][g|G][r|R][a|A][m|M] {return PROGRAM;}
[o|O][f|F] {return OF;}
[t|T][o|O] {return TO;}
[i|I][f|F] {return IF;}
[t|T][h|H][e|E][n|N] {return THEN;}
[e|E][l|L][s|S][e|E] {return ELSE;}
[t|T][y|Y][p|P][e|E] {return TYPE;}
[v|V][a|A][r|R]            {return VAR;}
[i|I][n|N][t|T]|[i|I][n|N][t|T][e|E][g|G][e|E][r|R]             {return INT;}
[r|R][e|E][a|A][l|L]          {return REAL;}
[b|B][o|O][o|O][l|L][e|E][a|A][n|N] {return BOOLEAN;}
[c|C][h|H][a|A][r|R]          {return CHAR;}
[f|F][o|O][r|R]            {return FOR;}
[d|D][o|O]               {return DO;}
[w|W][h|H][i|I][l|L][e|E]       {return WHILE;}
[a|A][r|R][r|R][a|A][y|Y]       {return ARRAY;}
[a|A][n|N][d|D]             {return AND;}
[o|O][r|R]               {return OR;}
[n|N][o|O][t|T]             {return NOT;}
[b|B][e|E][g|G][i|I][n|N]       {return BEG;}
[e|E][n|N][d|D]            {return END;}
[r|R][e|E][a|A][d|D]         {return READ;}
[w|W][r|R][i|I][t|T][e|E]      {return WRITE;}
"-"?{DIGIT}+                  {return INT_LITERAL;}
"-"?{DIGIT}+\.{DIGIT}+        {return REAL_LITERAL;}
[t|T][r|R][u|U][e|E]         {return BOOLEAN_LITERAL;}
[f|F][a|A][l|L][s|S][e|E]     {return BOOLEAN_LITERAL;}
[d|D][i|I][v|V]    {return DIVOP;}
\'{LETTER}\'                         {return CHAR_LITERAL;}
{VAR}                         {return ID;}
{STRING}                      {return STRING; }
":"     {return COLON;}
";"     {return SC;}
","     {return COMMA;}
"."     {return DOT;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
"%"     {return MOD;}
"="     {return EQ;}
"<"     {return LT;}
">"     {return GT;}
"<="    {return LTEQ;}
">="    {return GTEQ;}
"<>"    {return NOTEQ;}
":="    {return ASSIGN;}
"\("    {return OB;}
"\)"    {return CB;}
"\["    {return OPENBRAC;}
"\]"    {return CLOSEBRAC;}
"\{"    {return OPENPARA;}
"\}"    {return CLOSEPARA;}
%%
struct symbolTable 
{
    int line_number;
    char lexeme[100]; 
    char token[100];  
};
int main(){
    //printf("hello");
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
    int str = yylex();
    int i=0;
    struct symbolTable table[1000];
    while(str){
        switch(str){
            case 1 ... 99: {
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                i++;
                                break;
                           }
            case 100 ... 199:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                i++;
                                break;
                             }
            case 200 ... 299:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                i++;
                                break;
                             }
            case INT_LITERAL:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "INT_LITERAL");
                                i++;
                                break;
                             }
            case REAL_LITERAL:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "REAL_LITERAL");
                                i++;
                                break;
                             }
            case BOOLEAN_LITERAL:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "BOOLEAN_LITERAL");
                                i++;
                                break;
                             }
            case CHAR_LITERAL:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "CHAR_LITERAL");
                                i++;
                                break;
                             }
            case ID:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                break;
                             }
            case STRING:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "STRING");
                                i++;
                                break;
                             }
            case ARR:{
                                table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "ARRAY");
                                i++;
                                break;
                             }
           
        }
        str = yylex();
    }
     printf("Symbol Table:\n");
         printf("%-15s %-40s %s\n", "Line Number", "Lexeme", "Token");
         for (int j = 0; j <i; j++) {
                printf("%-15d %-40s %s\n", table[j].line_number, table[j].lexeme, table[j].token);
    }
}
int yywrap()
{
	return 1;
}