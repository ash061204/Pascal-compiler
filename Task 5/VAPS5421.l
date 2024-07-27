%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "y.tab.h"
    #include "symbol_table.h"
    #include "shared_var.h"
    int i=0;
    int line=1;
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

[p|P][r|R][o|O][g|G][r|R][a|A][m|M] { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return PROGRAM;}
[o|O][f|F] { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return OF;}
[t|T][o|O] {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return TO;}
[d|D][o|O][w|W][n|N][t|T][o|O] {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return DOWNTO;}
[i|I][f|F] { yylval.lexeme = strdup(yytext); table[i].line_number = line;
                 strcpy(table[i].lexeme, yytext);
                 strcpy(table[i].token, "KEYWORD");
                  
                 i++;return IF;}
[t|T][h|H][e|E][n|N] {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return THEN;}
[e|E][l|L][s|S][e|E] { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ELSE;}
                                 
                              
[v|V][a|A][r|R]             { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return VAR;}
[i|I][n|N][t|T][e|E][g|G][e|E][r|R]            {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return INT;}
[r|R][e|E][a|A][l|L]          { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return REAL;}
[b|B][o|O][o|O][l|L][e|E][a|A][n|N] {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BOOLEAN;}
[c|C][h|H][a|A][r|R]          {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return CHAR;}
[f|F][o|O][r|R]             {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return FOR;}
[d|D][o|O]               { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return DO;}
[w|W][h|H][i|I][l|L][e|E]       { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WHILE;}
[a|A][r|R][r|R][a|A][y|Y]       {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return ARRAY;}
[a|A][n|N][d|D]            { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return AND;}
[o|O][r|R]                {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return OR;}
[n|N][o|O][t|T]             {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return NOT;}
[b|B][e|E][g|G][i|I][n|N]       {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return BEG;}
[e|E][n|N][d|D]            {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return END;}
[r|R][e|E][a|A][d|D]          {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return READ;}
[w|W][r|R][i|I][t|T][e|E]|[w|W][r|R][i|I][t|T][e|E][l|L][n|N]      { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "KEYWORD");
                                 
                                i++;return WRITE;}
{DIGIT}+                  {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "INT_LITERAL");
                                 
                                i++;return INT_LITERAL;}
{DIGIT}+\.{DIGIT}+        {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "REAL_LITERAL");
                                 
                                i++;return REAL_LITERAL;}
[t|T][r|R][u|U][e|E]          {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "BOOLEAN_LITERAL");
                                 
                                i++;return BOOLEAN_LITERAL;}
[f|F][a|A][l|L][s|S][e|E]       {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "BOOLEAN_LITERAL"); 
                                i++;return BOOLEAN_LITERAL;}

{VAR}                         {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ID;}  
{VAR}(\[{DIGIT}+\]|\[{VAR}\])      {yylval.lexeme= strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                 
                                strcpy(table[i].token, "IDENTIFIER");
                                i++;
                                return ARR;}                                 
\'{LETTER}\'                         {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "CHAR_LITERAL");
                                 
                                i++;return CHAR_LITERAL;}
{STRING}                      {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "STRING");
                                 return STRING; }
":"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COLON;}
";"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return SC;}
","     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return COMMA;}
"+"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return PLUS;}
"-"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MINUS;}
"*"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MUL;}
"/"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 i++;return DIV;}
"%"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return MOD;}
"="     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return EQ;}
"<"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LT;}
">"     {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GT;}
"<="    {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return LTEQ;}
">="    {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return GTEQ;}
"<>"    {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return NOTEQ;}
":="    {yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "OPERATOR");
                                 
                                i++;return ASSIGN;}
"\("    { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OB;}
"\)"    { yylval.lexeme = strdup(yytext);table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CB;}
"\["    {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENBRAC;}
"\]"    {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return CLOSEBRAC;}
"\{"    {yylval.lexeme = strdup(yytext); table[i].line_number = line;
                                strcpy(table[i].lexeme, yytext);
                                strcpy(table[i].token, "SEPERATOR");
                                 
                                i++;return OPENPARA;}
"\}"    { yylval.lexeme = strdup(yytext);table[i].line_number = line;
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
