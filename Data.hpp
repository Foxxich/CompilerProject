#pragma once
#include "Defs.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>

int codeErrors=0;
long long offset=0;
int tableErrors = 0;

/*
 * Function is used for creating and initializing symbol
 */
void put_symbol(std::string name, long long size, long long startPosition, symbol_name type)
{
	instr ptr;
	ptr.name=name;
	ptr.size=size;
	ptr.startPosition=startPosition;
	ptr.isModified=false;
	ptr.position=offset;
	offset=offset+size;
	ptr.type=type;
	instr_vector.push_back(ptr);
}

/*
 * Function is used for getting symbol
 * If symbol exists, return i
 * Other less -1
 */
int get_symbol(std::string name)
{
	for(int i=0;i<instr_vector.size();i++)
	{
		if(instr_vector[i].name==name)
		{
			return i;
		}
	}
	return -1;
}

/*
 * Function is used for creating and initializing var
 */
void put_var( std::string name, int line )
{
	int s=-1;
	s = get_symbol (name);
	if (s == -1)
	{
		put_symbol(name,1,1,VARIABLE);
	}
	else 
	{ 
		std::cout << name << " second declaration in " << line << "line;\n";
		tableErrors=tableErrors+1;
	}
}

/*
 * Function is used for creating and initializing iterator
 */
void put_iterator(std::string name, int line)
{
	int s=-1;
	s = get_symbol (name);
	if (s == -1)
	{
		put_symbol(name,1,1,ITER);
	}
	else 
	{ 
		std::cout << name << " second declaration in " << line << "line;\n";
		tableErrors=tableErrors+1;
	}
}

/*
 * Function is used for creating and initializing array
 */
void put_in_array(std::string name, long long startPosition,long long lastIndex, int line)
{
	int s=-1;
	s=get_symbol(name);
	if (startPosition > lastIndex || s != -1)
	{
		std::cout << name << "Incorrect array bounds in " << line << "line;\n";
		tableErrors=tableErrors+1;
	}
	else
	{
		put_symbol(name, (lastIndex - (startPosition - 1)), startPosition, ARRAY);
	}
}

/*
 * Function is used for returning the 0 position of asset with given name
 */
int array_offset(std::string name)
{
	int s = get_symbol (name);
	return instr_vector[s].startPosition;
}

/*
 * Function is used for initializing of constant var
 */
var *function_number(long long int value, int line)
{
	var *new_element;
	new_element=new var;
	new_element->value=value;
	new_element->type=VAL;
	new_element->modified = false;
	return new_element;
}

/*
 * Function is used for initializing of var
 */
var *function_pidentifier(std::string name, int line)
{
	var *new_element;
	new_element=new var;
	new_element->name=name;
	new_element->value=(long long)0;
	new_element->type=_VAR;
	new_element->modified = false;
	return new_element;
}

/*
 * Function is used for initializing of array var with index
 */
var *function_pidentifier_array(std::string name, std::string code_offset, int lieno)
{
	var *new_element;
	new_element=new var;
	new_element->name=name;
	new_element->type=_ARRAY_INDEX;
	new_element->value=(long long )1;
	new_element->modified = false;
	new_element->code_offset=code_offset;
	return new_element;

}

/*
 * Function is used for initializing of var
 */
var *function_pidentifier(std::string name, long long code_offset, int line)
{
	var *new_element;
	new_element=new var;
	new_element->name=name;
	new_element->code_offset="";
	new_element->type=_ARRAY; 
	new_element->modified = false;
	new_element->value=code_offset;
	return new_element;

}