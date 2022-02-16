#pragma once
#include "Data.hpp"
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

std::vector<std::string> cmds;
enum symbol_name {VARIABLE,ARRAY,ITER};

//here is defined structure of instruction
struct instr
{
    std::string name;
    long long int size;
    long long int startPosition;
    bool isModified;
    long long int position;
    symbol_name type;
};

typedef struct instr instr;

std::vector<instr> instr_vector;
//enum with types of variables
enum var_type
{
    VAL,
    _VAR,
    _ARRAY,
    _ARRAY_INDEX,
    _EXPRESSION
};

//here is defined structure of variable
struct variable
{
    std::string name;
    std::string code_offset;
    long long value;
    bool modified;
    var_type type;
};
typedef struct variable var;

std::vector<variable>iterators;
//here is defined structure of label of conditions
struct cond_label
{
    std::string name;
    long long prev_index;
    long long next_index;
};
typedef struct cond_label cond_label;
std::vector<cond_label> cond_go_from;

//here is defined structure of label for
struct for_label
{
	std::string name;
	long long start;
	long long end;
	long long code_offset;

};
typedef struct for_label for_label;
std::vector<for_label> for_go_from;

//Prepare map with registers
std::map <int, std::string> reg_map;
void registers()
{
	reg_map.insert({0, "a"});
	reg_map.insert({1, "b"});
	reg_map.insert({2, "c"});
	reg_map.insert({3, "d"});
	reg_map.insert({4, "e"});
	reg_map.insert({5, "f"});
	reg_map.insert({6, "g"});
	reg_map.insert({7, "h"});

	cond_label go_to;
	cond_go_from.push_back(go_to);
	for_label for_label;
	for_go_from.push_back(for_label);
}