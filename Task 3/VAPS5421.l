%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    #include <stdbool.h>
    #include "symbol_table.h"
    #include "shared_var.h"
    int i=0;

    int line = 1;
   
 
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
{NEWLINE} {line++;}
{SPACE} {;}
{TAB} {;}
"//" {BEGIN(SLC);}
<SLC>.  {}
<SLC>\n {  line++;BEGIN(INITIAL);}
\.     { table[i].line_number = line;
         strcpy(table[i].lexeme, yytext);
         strcpy(table[i].token, "SEPERATOR");
         i++; return DOT; }

[p|P][r|R][o|O][g|G][r|R][a|A][m|M] { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return PROGRAM;}
[o|O][f|F] { table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return OF;}
[t|T][o|O] { table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return TO;}
[d|D][o|O][w|W][n|N][t|T][o|O] { table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return DOWNTO;}
[i|I][f|F] { table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return IF;}
[t|T][h|H][e|E][n|N] { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return THEN;}
[e|E][l|L][s|S][e|E] { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ELSE;}
                                 
                              
[v|V][a|A][r|R]             { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return VAR;}
[i|I][n|N][t|T][e|E][g|G][e|E][r|R]            { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return INT;}
[r|R][e|E][a|A][l|L]          { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return REAL;}
[b|B][o|O][o|O][l|L][e|E][a|A][n|N] { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BOOLEAN;}
[c|C][h|H][a|A][r|R]          { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return CHAR;}
[f|F][o|O][r|R]             { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return FOR;}
[d|D][o|O]               { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return DO;}
[w|W][h|H][i|I][l|L][e|E]       { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WHILE;}
[a|A][r|R][r|R][a|A][y|Y]       { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ARRAY;}
[a|A][n|N][d|D]            { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return AND;}
[o|O][r|R]                { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return OR;}
[n|N][o|O][t|T]             { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return NOT;}
[b|B][e|E][g|G][i|I][n|N]       { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BEG;}
[e|E][n|N][d|D]            { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return END;}
[r|R][e|E][a|A][d|D]          { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return READ;}
[w|W][r|R][i|I][t|T][e|E]|[w|W][r|R][i|I][t|T][e|E][l|L][n|N]      { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WRITE;}
{DIGIT}+                  {yylval.t.v.ival=atoi(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "INT_LITERAL");
                                 
                                i++;return INT_LITERAL;}
{DIGIT}+\.{DIGIT}+        {yylval.t.v.fval=atof(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "REAL_LITERAL");
                                 
                                i++;return REAL_LITERAL;}

{VAR}                         {yylval.strval = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ID;}   
{VAR}(\[{DIGIT}+\]|\[{VAR}\])      {yylval.strval = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ARR;}                 
\'{LETTER}\'                         {yylval.t.v.cval=yytext[0];table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "CHAR_LITERAL");
                                 
                                i++;return CHAR_LITERAL;}
{STRING}                      {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "STRING");
                                 return STRING; }
":"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COLON;}
";"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return SC;}
","     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COMMA;}
"+"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return PLUS;}
"-"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MINUS;}
"*"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MUL;}
"/"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 i++;return DIV;}
"%"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MOD;}
"="     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return EQ;}
"<"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LT;}
">"     {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GT;}
"<="    {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LTEQ;}
">="    {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GTEQ;}
"<>"    {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return NOTEQ;}
":="    {table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return ASSIGN;}
"\("    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OB;}
"\)"    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CB;}
"\["    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENBRAC;}
"\]"    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CLOSEBRAC;}
"\{"    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENPARA;}
"\}"    { table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                
                                i++;return CLOSEPARA;}
[$|@|`|~|#|^|&]      { ECHO;printf("\n");yyerror(); }
%%

int yywrap()
{
    return 1;
}