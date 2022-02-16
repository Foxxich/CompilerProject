#pragma once
#include "Data.hpp"
#include "Defs.hpp"
#include "Memory.hpp"

/*
 * Common functionality of all loops
 */
void prepare_conditions()
{
	cmds.push_back("SWAP " + reg_map[5]);
    cmds.push_back("RESET " + reg_map[0]);
    cmds.push_back("ADD " + reg_map[6]);
    cmds.push_back("SUB " + reg_map[5]);
	cmds.push_back("addr");//place for next part of condition
}

/****Function to generate code to check if v1 equals v2 ***/
void *condition_eq(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="EQ";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
    prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Function to generate code to check if v1 not equals v2 ***/
void *condition_neq(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="NEQ";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
    prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Function to generate code to check if v1 is less than v2 ***/
void *condition_le(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="LE";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
    prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Function to generate code to check if v1 is greater then v2 ***/
void *condition_ge(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="GE";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
    prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Function to generate code to check if v1 is less equal than v2 ***/
void *condition_leq(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="LEQ";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
    prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Function to generate code to check if v1 is greater equal then v2 ***/
void *condition_geq(var *v1,var *v2, int lineNumber)
{
	cond_label cond;
	cond.name="GEQ";//set name
	cond.prev_index=cmds.size()-1;
	load_var(v1,v2,lineNumber);
	prepare_conditions();
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****If function***/
void if_block()
{
	long long commandListSize=cmds.size()-1;
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long step=commandListSize-if_start.next_index+1;
	if(if_start.name=="EQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
	}
	else if(if_start.name=="NEQ")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
	}
	else if(if_start.name=="LE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
	}
	else if(if_start.name=="GE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JNEG " + std::to_string(step+1));
	}
	else if(if_start.name=="LEQ")
	{

		cmds[if_start.next_index]="JPOS " + std::to_string(step);
	}
	else if(if_start.name=="GEQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
	}
}

/****If function finish***/
void endif_block()
{
	long long commandListSize=cmds.size()-1;
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long step=commandListSize-if_start.next_index+1;
	cmds.insert(cmds.begin()+if_start.next_index+1, "JUMP " + std::to_string(step));
}

/****Else function***/
void else_block()
{
	long long commandListSize=cmds.size()-1;
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	cond_label cond;
	cond.name=if_start.name;
	cond.prev_index=commandListSize;
	cond.next_index=commandListSize;
	long long step=commandListSize-if_start.next_index+2;
	if(if_start.name=="EQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
		cond.next_index=commandListSize+1;
	}
	else if(if_start.name=="NEQ")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cond.next_index=commandListSize;
	}
	else if(if_start.name=="LE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
		cond.next_index=commandListSize+1;
	}
	else if(if_start.name=="GE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JNEG " + std::to_string(step+1));
		cond.next_index=commandListSize+1;
	}
	else if(if_start.name=="LEQ")
	{

		cmds[if_start.next_index]="JPOS " + std::to_string(step);
		cond.next_index=commandListSize;
	}
	else if(if_start.name=="GEQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
		cond.next_index=commandListSize;
	}
	cond_go_from.push_back(cond);
}

/****While function***/
void while_block()
{
	long long commandListSize=cmds.size()-1;
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long step=commandListSize-if_start.next_index+2;

	long long revert=(commandListSize-if_start.prev_index)*(-1);
	cmds.push_back("JUMP " + std::to_string(revert));
	if(if_start.name=="EQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
	}
	else if(if_start.name=="NEQ")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
	}
	else if(if_start.name=="LE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JPOS " + std::to_string(step+1));
	}
	else if(if_start.name=="GE")
	{
		cmds[if_start.next_index]="JZERO " + std::to_string(step);
		cmds.insert(cmds.begin()+if_start.next_index,"JNEG " + std::to_string(step+1));
	}
	else if(if_start.name=="LEQ")
	{

		cmds[if_start.next_index]="JPOS " + std::to_string(step);
	}
	else if(if_start.name=="GEQ")
	{
		cmds[if_start.next_index]="JNEG " + std::to_string(step);
	}
}

/****Repeat function***/
void repeat_block()
{
	cond_label cond;
	cond.name="LEQ";
	cond.prev_index=cmds.size()-1;
	cond.next_index=cmds.size()-1;
	cond_go_from.push_back(cond);
}

/****Until function***/
void until_block()
{
	long long commandListSize=cmds.size()-1;
	cond_label repeat_ending=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	cond_label repeat_beginning=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long step=(commandListSize-repeat_beginning.next_index-1)*(-1);
	if(repeat_ending.name=="EQ")
	{
		cmds[repeat_ending.next_index]="JNEG " + std::to_string(step);
		cmds.insert(cmds.begin()+repeat_ending.next_index,"JPOS " + std::to_string(step+1));
	}
	else if(repeat_ending.name=="NEQ")
	{
		cmds[repeat_ending.next_index]="JZERO " + std::to_string(step);
	}
	else if(repeat_ending.name=="LE")
	{
		cmds[repeat_ending.next_index]="JPOS " + std::to_string(step);
	}
	else if(repeat_ending.name=="GE")
	{
		cmds[repeat_ending.next_index]="JNEG " + std::to_string(step);
	}
	else if(repeat_ending.name=="LEQ")
	{
		cmds[repeat_ending.next_index]="JPOS " + std::to_string(step);
		cmds.insert(cmds.begin()+repeat_ending.next_index,"JZERO " + std::to_string(step+1));
	}
	else if(repeat_ending.name=="GEQ")
	{
		cmds[repeat_ending.next_index]="JNEG " + std::to_string(step);
		cmds.insert(cmds.begin()+repeat_ending.next_index,"JZERO " + std::to_string(step+1));
	}
}

/****For to***/
void for_to_block(std::string name, var *v1, var *v2, int lineNumber)
{
	variable iter;
	iter.name=name;
	iter.value=v1->value;
	iter.type=_VAR;
	iterators.push_back(iter);
	put_iterator(iter.name,lineNumber);
	put_iterator(iter.name+"temp",lineNumber);
	var *var_to_add;
	var_to_add=new var;
	var_to_add->name=iter.name;
	var_to_add->value=(long long)0;
	var_to_add->type=_VAR;
	var *loop_limit;
	loop_limit=new var;
	loop_limit->name=iter.name+"temp";
	loop_limit->value=(long long)0;
	loop_limit->type=_VAR;
	assign(var_to_add,v1,lineNumber);
	assign(loop_limit,v2,lineNumber);
	condition_leq(var_to_add,loop_limit,lineNumber);
	for_label label;
	label.name=name;
	label.start=v1->value;
	label.start=v2->value;
	label.code_offset=cmds.size()-1;
	for_go_from.push_back(label);
}

/****For down to***/
void for_downto_block(std::string name, var *v1, var *v2, int lineNumber)
{
	variable iter;
	iter.name=name;
	iter.value=v1->value;
	iter.type=_VAR;
	iterators.push_back(iter);
	put_iterator(iter.name,lineNumber);
	put_iterator(iter.name+"temp",lineNumber);
	var *var_to_add;
	var_to_add=new var;
	var_to_add->name=iter.name;
	var_to_add->value=(long long)0;
	var_to_add->type=_VAR;
	var *loop_limit;
	loop_limit=new var;
	loop_limit->name=iter.name+"temp";
	loop_limit->value=(long long)0;
	loop_limit->type=_VAR;
	assign(var_to_add,v1,lineNumber);
	assign(loop_limit,v2,lineNumber);
	condition_geq(var_to_add,loop_limit,lineNumber);
	for_label label;
	label.name=name;
	label.start=v1->value;
	label.start=v2->value;
	label.code_offset=cmds.size()-1;
	for_go_from.push_back(label);
}

/****For end***/
void endfor_to_block()
{
	variable iter=iterators[iterators.size()-1];
	iterators.pop_back();
	int i=get_symbol(iter.name);
    //reset a
    cmds.push_back("RESET " + reg_map[0]);
	generateConstances(instr_vector[i].position);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("LOAD " + reg_map[1]);
    cmds.push_back("INC " + reg_map[0]);
    cmds.push_back("STORE " + reg_map[1]);
    //save flag with b
	instr_vector.pop_back();
	instr_vector.pop_back();
	long long commandListSize=cmds.size()-1;
	for_label for_start=for_go_from[for_go_from.size()-1];
	for_go_from.pop_back();
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long jump=commandListSize-if_start.prev_index;
	long long pre=if_start.next_index;
	cmds[pre]="JPOS " + std::to_string(commandListSize-if_start.next_index+2);
	cmds.push_back("JUMP "+ std::to_string(jump*(-1)));
}

/****For down to end***/
void endfor_downto_block()
{
	variable iter=iterators[iterators.size()-1];
	iterators.pop_back();
	int i=get_symbol(iter.name);
    //reset a
    cmds.push_back("RESET " + reg_map[0]);
	generateConstances(instr_vector[i].position);
    cmds.push_back("SWAP " + reg_map[1]);
    cmds.push_back("LOAD " + reg_map[1]);
    cmds.push_back("DEC " + reg_map[0]);
    cmds.push_back("STORE " + reg_map[1]);
    //save flag with b
	instr_vector.pop_back();
	instr_vector.pop_back();
	long long commandListSize=cmds.size()-1;
	for_label for_start=for_go_from[for_go_from.size()-1];
	for_go_from.pop_back();
	cond_label if_start=cond_go_from[cond_go_from.size()-1];
	cond_go_from.pop_back();
	long long jump=commandListSize-if_start.prev_index;
	long long pre=if_start.next_index;
	cmds[pre]="JNEG " + std::to_string(commandListSize-if_start.next_index+2);
	cmds.push_back("JUMP "+ std::to_string(jump*(-1)));
}

