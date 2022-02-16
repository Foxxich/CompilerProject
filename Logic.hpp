#pragma once
#include "Data.hpp"
#include "Defs.hpp"
#include "Memory.hpp"
#include "Loops.hpp"
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

/*
 * Function used for addition of two numbers
 * V1 is in register a
 * V2 is in register g
 * Result is saved to register f
 */
void *func_plus( var *v1, var *v2, int lineNumber)
{
	load_var(v1,v2,lineNumber);
	cmds.push_back("RESET " + reg_map[5]);
	cmds.push_back("ADD " + reg_map[6]);
	cmds.push_back("SWAP " + reg_map[5]);
	v1->type=_EXPRESSION;
}

/*
 * Function used for addition of two numbers
 * V1 is in register a
 * V2 is in register g
 * Result is saved to register f
 * Program resets f, swaps a with g, does subtraction and later saves result to f
 */
void *func_minus( var *v1, var *v2, int lineNumber)
{
	load_var(v1,v2,lineNumber);
	cmds.push_back("RESET " + reg_map[5]);
	cmds.push_back("SWAP " + reg_map[6]);
	cmds.push_back("SUB " + reg_map[6]);
	cmds.push_back("SWAP " + reg_map[5]);
	v1->type=_EXPRESSION;

}

/*
 * Function used for multiplying of two numbers
 * V1 is in register a
 * V2 is in register g
 * Result is saved to register f
 */
void *func_times( var *v1, var *v2, int lineNumber)
{
	load_var(v1,v2,lineNumber);
    cmds.push_back("RESET h"); //FREE SPACE FOR FLAG
    cmds.push_back("RESET c");
    //FLAG A SIGN AND NEGATE IF NEED
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[6]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("JNEG 4");// JUMP IF A neg
    cmds.push_back("INC h");
    cmds.push_back("SWAP c");
    cmds.push_back("JUMP 6");
    cmds.push_back("DEC h");
    cmds.push_back("SWAP c");
    cmds.push_back("SUB c");
    cmds.push_back("SWAP c");
    cmds.push_back("RESET a");
    //FLAG B SIGN AND NEGATE IF NEED
    cmds.push_back("SWAP b");
    cmds.push_back("JNEG 4");// JUMP IF A neg
    cmds.push_back("INC h");
    cmds.push_back("SWAP b");
    cmds.push_back("JUMP 6");
    cmds.push_back("DEC h");
    cmds.push_back("SWAP b");
    cmds.push_back("SUB b");
    cmds.push_back("SWAP b");
    cmds.push_back("RESET a");
    cmds.push_back("ADD b");
    cmds.push_back("SUB c");
    cmds.push_back("JNEG 2");
    cmds.push_back("JUMP 4");
    cmds.push_back("SWAP c");
    cmds.push_back("SWAP b");
    cmds.push_back("SWAP c");
    cmds.push_back("RESET a");
    cmds.push_back("RESET d");
    cmds.push_back("RESET e");
    cmds.push_back("DEC e");
    cmds.push_back("SWAP b");
    cmds.push_back("JZERO 27");
    cmds.push_back("SWAP b");
    cmds.push_back("SWAP c");
    cmds.push_back("JZERO 24");
    cmds.push_back("SWAP c");
    cmds.push_back("ADD c");
    cmds.push_back("SHIFT e");
    cmds.push_back("INC e");
    cmds.push_back("INC e");
    cmds.push_back("SHIFT e");
    cmds.push_back("SUB c");
    cmds.push_back("JNEG 2"); //LAST BIT WAS 1
    cmds.push_back("JUMP 5"); //LAST BIT WAS 0
    cmds.push_back("RESET a");
    cmds.push_back("SWAP d");
    cmds.push_back("ADD b");
    cmds.push_back("SWAP d"); // HOLDS SUM
    cmds.push_back("RESET a");
    cmds.push_back("SWAP b");
    cmds.push_back("SHIFT e");
    cmds.push_back("SWAP b");
    cmds.push_back("DEC e");
    cmds.push_back("DEC e");
    cmds.push_back("SWAP c");
    cmds.push_back("SHIFT e");
    cmds.push_back("SWAP c");
    cmds.push_back("JUMP -24");
    cmds.push_back("SWAP c");
    cmds.push_back("SWAP d");
    cmds.push_back("SWAP h");
    cmds.push_back("JZERO 3");
    cmds.push_back("SWAP h");
    cmds.push_back("JUMP 5");
    cmds.push_back("SWAP h");
    cmds.push_back("SWAP d");
    cmds.push_back("RESET a");
    cmds.push_back("SUB d");
    cmds.push_back("SWAP " + reg_map[5]);

	v1->type=_EXPRESSION;

}

/*
 * Function used for division of two numbers
 * V1 is in register a
 * V2 is in register g
 * Result is saved to register f
 */
void *func_div(var *v1, var *v2, int lineNumber)
{
	load_var(v1,v2,lineNumber);
    cmds.push_back("RESET " + reg_map[2]);
    cmds.push_back("RESET " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[7]);//FREE SPACE FOR FLAG
    cmds.push_back("RESET " + reg_map[5]);
    cmds.push_back("JZERO " + std::to_string(61));// JUMP IF A 0
    cmds.push_back("JPOS " + std::to_string(5));// JUMP IF A pos
    cmds.push_back("DEC " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[2]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[2]);
    cmds.push_back("SWAP " + reg_map[2]);
    cmds.push_back("SWAP " + reg_map[6]);
    cmds.push_back("JZERO " + std::to_string(53));// JUMP IF A 0
    cmds.push_back("RESET " + reg_map[6]);
    cmds.push_back("JPOS " + std::to_string(6));
    cmds.push_back("INC " + reg_map[6]);
    cmds.push_back("INC " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[4]);
    cmds.push_back("RESET " + reg_map[3]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("JPOS " + std::to_string(3));
    cmds.push_back("INC " + reg_map[3]);
    cmds.push_back("JUMP " + std::to_string(-6));
    cmds.push_back("DEC " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JNEG " + std::to_string(42));// JUMP IF A neg
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("INC " + reg_map[0]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("ADD " + reg_map[4]);
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[1]);
    cmds.push_back("SUB " + reg_map[2]);
    cmds.push_back("JNEG " + std::to_string(12));
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("JNEG " + std::to_string(-20));
    cmds.push_back("JZERO " + std::to_string(-21));
    cmds.push_back("DEC " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JNEG " + std::to_string(3));
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JUMP " + std::to_string(-10));
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("SWAP " + reg_map[7]);
    cmds.push_back("JZERO " + std::to_string(8));// JUMP IF A 0
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("JZERO " + std::to_string(2));
    cmds.push_back("DEC " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("JUMP " + std::to_string(2));
    cmds.push_back("SWAP " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[5]);
    cmds.push_back("JUMP " + std::to_string(3));

    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SWAP " + reg_map[5]);
	v1->type=_EXPRESSION;
}

/*
 * Function used for modulo of two numbers
 * V1 is in register a
 * V2 is in register g
 * Result is saved to register f
 */
void *func_mod(var *v1, var *v2, int lineNumber)
{
	load_var(v1,v2,lineNumber);
    cmds.push_back("RESET " + reg_map[2]);
    cmds.push_back("RESET " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[7]);
    cmds.push_back("RESET " + reg_map[5]);
    cmds.push_back("JZERO " + std::to_string(61));// JUMP IF A 0
    cmds.push_back("JPOS " + std::to_string(5));// JUMP IF A pos
    cmds.push_back("DEC " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[2]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[2]);
    cmds.push_back("SWAP " + reg_map[2]);
    cmds.push_back("SWAP " + reg_map[6]);
    cmds.push_back("JZERO " + std::to_string(53));// JUMP IF A 0
    cmds.push_back("RESET " + reg_map[6]);
    cmds.push_back("JPOS " + std::to_string(6));
    cmds.push_back("INC " + reg_map[6]);
    cmds.push_back("INC " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[4]);
    cmds.push_back("RESET " + reg_map[3]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("JPOS " + std::to_string(3));
    cmds.push_back("INC " + reg_map[3]);
    cmds.push_back("JUMP " + std::to_string(-6));
    cmds.push_back("DEC " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JNEG " + std::to_string(42));
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("INC " + reg_map[0]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("ADD " + reg_map[4]);
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[1]);
    cmds.push_back("SUB " + reg_map[2]);
    cmds.push_back("JNEG " + std::to_string(12));// JUMP IF A neg
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[2]);
    cmds.push_back("SHIFT " + reg_map[3]);
    cmds.push_back("SUB " + reg_map[1]);
    cmds.push_back("JNEG " + std::to_string(-20));
    cmds.push_back("JZERO " + std::to_string(-21));
    cmds.push_back("DEC " + reg_map[3]);
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JNEG " + std::to_string(3));
    cmds.push_back("SWAP " + reg_map[3]);
    cmds.push_back("JUMP " + std::to_string(-10));
    cmds.push_back("SWAP " + reg_map[4]);
    cmds.push_back("SWAP " + reg_map[7]);
    cmds.push_back("JZERO " + std::to_string(8));
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SUB " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("JZERO " + std::to_string(2));
    cmds.push_back("DEC " + reg_map[1]);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("JUMP " + std::to_string(2));
    cmds.push_back("SWAP " + reg_map[7]);
    cmds.push_back("SWAP " + reg_map[5]);
    cmds.push_back("JUMP " + std::to_string(3));
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("SWAP " + reg_map[5]);
	cmds.push_back("SWAP " + reg_map[1]);
	cmds.push_back("JZERO " + std::to_string(20));
	cmds.push_back("SWAP " + reg_map[1]);
	cmds.push_back("SWAP " + reg_map[7]);
	cmds.push_back("JZERO " + std::to_string(11));
	cmds.push_back("SWAP " + reg_map[6]);
	cmds.push_back("JZERO " + std::to_string(5));
	cmds.push_back("RESET " + reg_map[0]);
	cmds.push_back("ADD " + reg_map[2]);
	cmds.push_back("SUB " + reg_map[1]);
	cmds.push_back("JUMP " + std::to_string(11));
	cmds.push_back("RESET " + reg_map[0]);
	cmds.push_back("ADD " + reg_map[1]);
	cmds.push_back("SUB " + reg_map[2]);
	cmds.push_back("JUMP " + std::to_string(8));
	cmds.push_back("SWAP " + reg_map[6]);
    cmds.push_back("INC " + reg_map[6]);
	cmds.push_back("JZERO " + std::to_string(4));// JUMP IF A 0
	cmds.push_back("RESET " + reg_map[0]);
	cmds.push_back("SUB " + reg_map[1]);
	cmds.push_back("JUMP " + std::to_string(2));
	cmds.push_back("SWAP " + reg_map[1]);
	cmds.push_back("SWAP " + reg_map[5]);
	cmds.push_back("DEC " + reg_map[6]);
	v1->type=_EXPRESSION;
}