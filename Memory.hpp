#pragma once
#include "Data.hpp"
#include "Defs.hpp"
#include <string>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

/****Function used for getting command of finishing the generating of assembly code ***/
void finish()
{
	cmds.push_back("HALT");
}

/****Function used for generating constant value, from given from c ***/
/*
 * Here is optimization for every c < 16, we generate in 'easy way';
 * Other less program gets binary from decimal c and with usage of
 * increments, decreases and shifts we represent c in decimal in assembly code
 */
void generateConstances(long long c)
{
	cmds.push_back("RESET a");
	cmds.push_back("RESET c" );
	bool negative = false;
    if (c < 0) 
	{
		negative = true;
	}
    if (abs(c) < 16) {
        if (negative) 
		{
			for (long long i = 0; i > c; i--) {
				cmds.push_back("DEC a");
			}
		} else {
			for (long long i = 0; i < c; i++) {
				cmds.push_back("INC a");
			}
		} 
    } else {
        long long binary[64];
        long long i = 0;
        while (c != 0) {
            binary[i] = abs(c % 2);
            c /= 2;
            i++;
        }
        i--;
        cmds.push_back("INC c");
        for (; i > 0; i--) {
            if (binary[i] == 1) {
                if (negative) cmds.push_back("DEC a");
                else cmds.push_back("INC a");
            }
            cmds.push_back("SHIFT c");
        }
        if (binary[i] == 1) {
            if (negative) cmds.push_back("DEC a");
            else cmds.push_back("INC a");
        }
        cmds.push_back("RESET c");
    }
}


/****Function used for reading needed var, with var's name and needed line ***/
void read(var *name, int lineNumber)
{
    // reset a register
	cmds.push_back("RESET " + reg_map[0]);
    //  check if given var type is var
	if(name->type==_VAR)
	{
		int i=get_symbol(name->name);
		generateConstances(instr_vector[i].position);
		instr_vector[i].isModified=true;
	}
    //  check if given var type is index of array
	else if(name->type==_ARRAY_INDEX)
	{
		cmds.push_back("RESET " + reg_map[6]);
		int i=get_symbol(name->name);
		int code_offset=get_symbol(name->code_offset);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
        //  load value saved depending on array index
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(name->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[6]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[5]);
	}
    //  check if given var type is array
	else if(name->type==_ARRAY)
	{
		int i=get_symbol(name->name);
		int code_offset=name->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
		generateConstances(code_offset);
	}
	cmds.push_back("RESET " + reg_map[1]);
	cmds.push_back("SWAP " + reg_map[1]);
	cmds.push_back("LOAD " + reg_map[1]);
	cmds.push_back("GET");
	cmds.push_back("STORE " + reg_map[1]);

}
void write(var *current, int lineNumber)
{
    //  reset a, b registers
	cmds.push_back("RESET " + reg_map[0]);
	cmds.push_back("RESET " + reg_map[1]);
    //  check if given var type is value
	if(current->type==VAL)
	{
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(current->value);
	}
    //  check if given var type is var
	else if(current->type==_VAR)
	{
		int i=get_symbol(current->name);
		if(i==-1 || instr_vector[i].isModified == false)
		{
			std::cout << "Undeclared variable " << current->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[1]);
		cmds.push_back("LOAD " + reg_map[1]);
        //  load b
	}
    //  check if given var type is array
	else if(current->type==_ARRAY)
	{
		int i=get_symbol(current->name);
		int code_offset=current->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(code_offset);
		cmds.push_back("SWAP " + reg_map[1]);
		cmds.push_back("LOAD " + reg_map[1]);
        //  load b
	}
    //  check if given var type is index of array
	else if(current->type==_ARRAY_INDEX)
	{
        //  reset a register
		cmds.push_back("RESET " + reg_map[6]);
		int i=get_symbol(current->name);
		int code_offset=get_symbol(current->code_offset);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(current->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[6]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[5]);
		cmds.push_back("SWAP " + reg_map[1]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("LOAD " + reg_map[1]);
        //  load b
	}
    //  write result
	cmds.push_back("PUT");
}

/****Function used for getting assigning given var, with parameters variable, expr and needed line ***/
/*
 * We assign variable to the expression
 */
void assign(var *variable, var *expr, int lineNumber)
{
    //  reset a register
	cmds.push_back("RESET " + reg_map[0]);
    //  check if given var type is var
	if(variable->type==_VAR)
	{
        //  reset g register
		cmds.push_back("RESET " + reg_map[6]);
		int i=get_symbol(variable->name);
		generateConstances(instr_vector[i].position);
		if(instr_vector[i].type == 2 && instr_vector[i].isModified == true)
		{
			std::cout << "Incorrect modification " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		instr_vector[i].isModified=true;
		if(instr_vector[i].type==1)
		{
			std::cout << "Incorrect array " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
        //  result to g register
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("RESET " + reg_map[0]);
	}
    //  check if given var type is index of array
	else if(variable->type==_ARRAY)
	{
        //  reset g register
		cmds.push_back("RESET " + reg_map[6]);
		int i=get_symbol(variable->name);
		if(instr_vector[i].type==0)
		{
			std::cout << "Incorrect usage of variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		int code_offset=variable->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
		generateConstances(code_offset);
        //  result to g register
		cmds.push_back("SWAP " + reg_map[6]);
	}
    //  check if given var type is index of array
	else if(variable->type==_ARRAY_INDEX)
	{	
		cmds.push_back("RESET " + reg_map[6]);
		int i=get_symbol(variable->name);
		int code_offset = get_symbol(variable->code_offset);
		if(instr_vector[i].type==0 || code_offset==-1)
		{
			std::cout << "Incorrect usage of variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("INC " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("DEC " + reg_map[0]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(variable->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[4]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[6]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[4]);
        //  result to g register
		cmds.push_back("SWAP " + reg_map[6]);
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
	}
    //  check if given expr type is expression
	if(expr->type==_EXPRESSION)
	{
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[5]);
		cmds.push_back("STORE " + reg_map[6]);
        //  store to g register
	}
    //  check if given expr type is value
	else if(expr->type==VAL)
	{
		generateConstances(expr->value);
		cmds.push_back("STORE " + reg_map[6]);
        //  store to g register
	}
    //  check if given expr type is var
	else if(expr->type==_VAR)
	{
		int newi=get_symbol(expr->name);
		if(newi==-1 || instr_vector[newi].isModified==false || instr_vector[newi].type==1)
		{
			std::cout << "Undeclared variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		generateConstances(instr_vector[newi].position);
		cmds.push_back("SWAP " + reg_map[1]);
		cmds.push_back("LOAD " + reg_map[1]);
		cmds.push_back("STORE " + reg_map[6]);
        //  store to g register
	}
    //  check if given expr type is index of array
	else if(expr->type==_ARRAY_INDEX)
	{
		cmds.push_back("RESET " + reg_map[4]);
		int i=get_symbol(expr->name);
		if(instr_vector[i].type==0)
		{
			std::cout << "Incorrect usage of variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		int code_offset=get_symbol(expr->code_offset);
		if(code_offset==-1)
		{
			std::cout << "Incorrect usage of variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[4]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(expr->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[4]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[5]);
		cmds.push_back("SWAP " + reg_map[1]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("LOAD " + reg_map[1]);
		cmds.push_back("STORE " + reg_map[6]);
        //  store to g register
		
	}
    //  check if given expr type is array
	else if(expr->type==_ARRAY)
	{
		cmds.push_back("RESET " + reg_map[5]);
		int i=get_symbol(expr->name);
		if(instr_vector[i].type==0)
		{
			std::cout << "Incorrect usage of variable " << variable->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
		int code_offset=expr->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(code_offset);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("LOAD " + reg_map[5]);
		cmds.push_back("STORE " + reg_map[6]);
        //  store to g register
	}
}

/****Function used for loading given var, with parameters v_1, v_2 and needed line ***/
void load_var(var *v1, var *v2, int lineNumber)
{
	cmds.push_back("RESET " + reg_map[0]);
    //  check if given v1 type is var
	if(v1->type==_VAR)
	{
		int i=get_symbol(v1->name);
		if(i==-1)
		{
			std::cout << "Incorrect variable " << v1->name << " in " << lineNumber << " line;\n";
			codeErrors=codeErrors+1;
		}
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("LOAD " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
        //  store to g register
	}
    //  check if given v1 type is val
	else if(v1->type==VAL)
	{
		generateConstances(v1->value);
		cmds.push_back("RESET " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
        //  swap to g register
	}
    //  check if given v1 type is index of array
	else if(v1->type==_ARRAY_INDEX)
	{
		cmds.push_back("RESET " + reg_map[4]);
		int i=get_symbol(v1->name);
		int code_offset=get_symbol(v1->code_offset);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[4]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(v1->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[4]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("LOAD " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
        //  swap to g register
	}
    //  check if given v1 type is array
	else if(v1->type=_ARRAY)
	{
		int i=get_symbol(v1->name);
		int code_offset=v1->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(code_offset);
		cmds.push_back("RESET " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
		cmds.push_back("LOAD " + reg_map[6]);
		cmds.push_back("SWAP " + reg_map[6]);
        //  swap to g register
	}
	cmds.push_back("RESET " + reg_map[0]);
    //  check if given v2 type is var
	if(v2->type==_VAR)
	{
		int i=get_symbol(v2->name);
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("RESET " + reg_map[5]);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("LOAD " + reg_map[5]);
        //  load f register
	}
    //  check if given v2 type is val
	else if(v2->type==VAL)
	{
		generateConstances(v2->value);
	}
    //  check if given v2 type is index of array
	else if(v2->type==_ARRAY_INDEX)
	{
		cmds.push_back("RESET " + reg_map[4]);
		int i=get_symbol(v2->name);
		int code_offset=get_symbol(v2->code_offset);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[i].position);
		cmds.push_back("SWAP " + reg_map[4]);
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(instr_vector[code_offset].position);
		cmds.push_back("RESET " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("LOAD " + reg_map[7]);
		cmds.push_back("SWAP " + reg_map[7]);
		cmds.push_back("RESET " + reg_map[0]);
		int array=array_offset(v2->name);
		generateConstances(array);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[0]);
		cmds.push_back("ADD " + reg_map[4]);
		cmds.push_back("ADD " + reg_map[7]);
		cmds.push_back("SUB " + reg_map[5]);
		cmds.push_back("RESET " + reg_map[5]);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("LOAD " + reg_map[5]);
        //  load f register
	}
    //  check if given v2 type is array
	else if(v2->type=_ARRAY)
	{
		int i=get_symbol(v2->name);
		int code_offset=v2->value-instr_vector[i].startPosition;
		code_offset=instr_vector[i].position+code_offset;
        //  reset a register
		cmds.push_back("RESET " + reg_map[0]);
		generateConstances(code_offset);
		cmds.push_back("RESET " + reg_map[5]);
		cmds.push_back("SWAP " + reg_map[5]);
		cmds.push_back("LOAD " + reg_map[5]);
        //  load f register
	}
}