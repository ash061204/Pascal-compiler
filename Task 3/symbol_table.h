// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

struct symbolTable {
    // Define your symbol table structure here
    int line_number;
    char lexeme[100]; 
    char token[100];  
};

extern struct symbolTable table[10000];

#endif  // SYMBOL_TABLE_H
