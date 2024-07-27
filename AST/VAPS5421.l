%{
     #include "header.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    int line = 1;
    int i=0;
    struct symbolTable 
{
    int line_number;
    char lexeme[100]; 
    char token[100];  
};
struct symbolTable table[1000];
%}
LETTER [a-zA-Z]
DIGIT [0-9]
UNDERSCORE [_]
NEWLINE [\n]
SPACE [' ']
TAB ['\t']
NUM {DIGIT}+(\.{DIGIT}+)?
STRING \"[ ]*([^\"\n]*)[ ]*\"
VAR {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

%x SLC
%%
"\n" {line++;}
{SPACE} {;}
{TAB} {;}

"//" {BEGIN(SLC);}
<SLC>.  {}
<SLC>\n {  line++;BEGIN(INITIAL);}
\.     { strcpy(yylval.string, yytext);table[i].line_number = line;
         strcpy(table[i].lexeme, yytext);
         strcpy(table[i].token, "SEPERATOR");
         i++; return DOT; }

[p|P][r|R][o|O][g|G][r|R][a|A][m|M] {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return PROGRAM;}
[o|O][f|F] { strcpy(yylval.string, yytext);table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return OF;}
[t|T][o|O] { strcpy(yylval.string, yytext);table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return TO;}
[d|D][o|O][w|W][n|N][t|T][o|O] {strcpy(yylval.string, yytext); table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return DOWNTO;}
[i|I][f|F] { strcpy(yylval.string, yytext);table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return IF;}
[t|T][h|H][e|E][n|N] { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return THEN;}
[e|E][l|L][s|S][e|E] {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ELSE;}
                                 
                              
[v|V][a|A][r|R]             {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return VAR;}
[i|I][n|N][t|T][e|E][g|G][e|E][r|R]            {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return INT;}
[r|R][e|E][a|A][l|L]          {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return REAL;}
[b|B][o|O][o|O][l|L][e|E][a|A][n|N] { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BOOLEAN;}
[c|C][h|H][a|A][r|R]          {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return CHAR;}
[f|F][o|O][r|R]             { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return FOR;}
[d|D][o|O]               {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return DO;}
[w|W][h|H][i|I][l|L][e|E]       {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WHILE;}
[a|A][r|R][r|R][a|A][y|Y]       { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ARRAY;}
[a|A][n|N][d|D]            { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return AND;}
[o|O][r|R]                { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return OR;}
[n|N][o|O][t|T]             { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return NOT;}
[b|B][e|E][g|G][i|I][n|N]       { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BEG;}
[e|E][n|N][d|D]            {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return END;}
[r|R][e|E][a|A][d|D]          { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return READ;}
[w|W][r|R][i|I][t|T][e|E]      {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WRITE;}
{DIGIT}+                  {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "INT_LITERAL");
                                 
                                i++;return INT_LITERAL;}
{DIGIT}+\.{DIGIT}+        {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "REAL_LITERAL");
                                 
                                i++;return REAL_LITERAL;}

{VAR}                         {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ID;}  
{VAR}(\[{DIGIT}+\]|\[{VAR}\])      {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ARR;}                                
\'{LETTER}\'                         {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "CHAR_LITERAL");
                                 
                                i++;return CHAR_LITERAL;}
{STRING}                      {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "STRING");
                                 return STRING; }
":"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COLON;}
";"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return SC;}
","     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COMMA;}
"+"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return PLUS;}
"-"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MINUS;}
"*"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MUL;}
"/"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 i++;return DIV;}
"%"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MOD;}
"="     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return EQ;}
"<"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LT;}
">"     {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GT;}
"<="    {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LTEQ;}
">="    {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GTEQ;}
"<>"    {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return NOTEQ;}
":="    {strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return ASSIGN;}
"\("    { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OB;}
"\)"    {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CB;}
"\["    {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENBRAC;}
"\]"    { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CLOSEBRAC;}
"\{"    { strcpy(yylval.string, yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENPARA;}
"\}"    {strcpy(yylval.string, yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                printf(yytext ); 
                                i++;return CLOSEPARA;}
[$|@|`|~|#|^|&]      { ECHO;printf("\n");yyerror(); }
%%
void printTable() {
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