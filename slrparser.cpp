#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

#define LR_table_action_col_size 10

std::vector<std::string> split(std::string str, char Delimiter) {
	std::istringstream iss(str);             // istringstream에 str을 담는다.
	std::string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

	std::vector<std::string> result;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
	}

	return result;
}

class SLRgrammar {
public:
	std::vector<std::string> L;
	std::vector<std::vector<std::string>> R;
};

void initSLRGrammar(SLRgrammar& slr_grammar) {
	std::vector<std::string>* vePointer;
	
	
	slr_grammar.L.push_back("E_");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("E");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("E");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("E");
	vePointer->push_back("+");
	vePointer->push_back("T");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("E");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("T");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("T");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("T");
	vePointer->push_back("*");
	vePointer->push_back("F");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("T");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("F");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("F");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("(");
	vePointer->push_back("E");
	vePointer->push_back(")");
	slr_grammar.R.push_back(*vePointer);

	slr_grammar.L.push_back("F");
	vePointer = new std::vector<std::string>;
	vePointer->push_back("id");
	slr_grammar.R.push_back(*vePointer);
}

void initTerminals(std::vector<std::string>& Terminals) {
	Terminals.push_back("(");
	Terminals.push_back(")");
	Terminals.push_back("id");
	Terminals.push_back("+");
	Terminals.push_back("*"); 
	
}

void initNon_terminals(std::vector<std::string>& Non_terminals) {
	Non_terminals.push_back("E_");
	Non_terminals.push_back("E");
	Non_terminals.push_back("T");
	Non_terminals.push_back("F");
}

int indexOf(std::string nextstr, std::string LR_table_action[LR_table_action_col_size]) {
	for (int i = 0; i < LR_table_action_col_size; i++) {
		if (nextstr.compare(LR_table_action[i]) == 0) {
			return i;
		}
	}
}

void reduceVeForStrThingBy(SLRgrammar slr_grammar, std::vector<std::string>& veForStr, int action_int) {
	for (int i = 0; i < slr_grammar.R.at(action_int).size(); i++) {
		veForStr.pop_back();
	}
	veForStr.push_back(slr_grammar.L.at(action_int));
}

void reduceStForStateThingBy(SLRgrammar slr_grammar, std::vector<int>& veForint, int action_int) {
	for (int i = 0; i < slr_grammar.R.at(action_int).size(); i++) {
		veForint.pop_back();
	}
}


int main() {
	std::string inputStr = "id + id * id * id + id";
	inputStr += " $";
	std::vector<std::string> inputVe = split(inputStr, ' ');
	
	std::string Start_symbol = "E_";

	SLRgrammar slr_grammar;
	initSLRGrammar(slr_grammar);
	std::vector<std::string> Terminals, Non_terminals;
	initTerminals(Terminals);
	initNon_terminals(Non_terminals);

	std::string LR_table_action_stand[10] = { (std::string)"+",(std::string)"*",(std::string)"(",(std::string)")",(std::string)"id",(std::string)"$",(std::string)"E_",(std::string)"E",(std::string)"T",(std::string)"F" };
	char LR_table_action[12][10] =
	{
//+    *    (    )    id   $   E'   E    T    F
{'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x'},
{'s', 'x', 'x', 'x', 'x', 'a', 'x', 'x', 'x', 'x'},
{'r', 's', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'},
{'r', 'r', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'},
{'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x'},
{'r', 'r', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'},
{'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x'},
{'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x'},
{'s', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x'},
{'r', 's', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'},
{'r', 'r', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'},
{'r', 'r', 'x', 'r', 'x', 'r', 'x', 'x', 'x', 'x'}
	};
	int LR_table_state[12][10] =
	{
		//+  *  (  ) id  $ E'  E  T  F
		{-1,-1, 4,-1, 5,-1,-1, 1, 2, 3} ,
		{ 6,-1,-1,-1,-1,-1,-1,-1,-1,-1} ,
		{ 2, 7,-1, 2,-1, 2,-1,-1,-1,-1} ,
		{ 4, 4,-1, 4,-1, 4,-1,-1,-1,-1} ,
		{-1,-1, 4,-1, 5,-1,-1, 8, 2, 3} ,
		{ 6, 6,-1, 6,-1, 6,-1,-1,-1,-1} ,
		{-1,-1, 4,-1, 5,-1,-1,-1, 9, 3} ,
		{-1,-1, 4,-1, 5,-1,-1,-1,-1,10} ,
		{ 6,-1,-1,11,-1,-1,-1,-1,-1,-1} ,
		{ 1, 7,-1, 1,-1, 1,-1,-1,-1,-1} ,
		{ 3, 3,-1, 3,-1, 3,-1,-1,-1,-1} ,
		{ 5, 5,-1, 5,-1, 5,-1,-1,-1,-1}
	};

	int currentState = 0;
	int action_char = '0';
	int action_int = 0;
	std::vector<int> stForState;
	stForState.push_back(0);
	std::vector<std::string> veForStr;

	std::string nextstr;
	int i = 0;
	while (true) {
		currentState = stForState.back();
		nextstr = inputVe.at(i);
		//veForStr.push_back(nextstr);
		action_char = LR_table_action[currentState][indexOf(nextstr, LR_table_action_stand)];
		action_int = LR_table_state[currentState][indexOf(nextstr, LR_table_action_stand)];
		if (action_char == 's') {
			i++;
			veForStr.push_back(nextstr);
			stForState.push_back(action_int);
		}
		else if (action_char == 'r') {
			reduceVeForStrThingBy(slr_grammar, veForStr, action_int);
			reduceStForStateThingBy(slr_grammar, stForState, action_int);
			currentState = stForState.back();
			action_int = LR_table_state[currentState][indexOf(veForStr.back(), LR_table_action_stand)];
			stForState.push_back(action_int);
		}
		else if (action_char == 'a') {
			std::cout << "성공";
			break;
		}
		else if (action_char == 'x') {
			std::cout << "실패";
			break;
		}
		//stackForStr.push_back(inputVe.at(i));

	}

	
	/*
	int currentState = 0;
	int action_char = '0';
	int action_int = 0;

	std::vector<std::string> stackForStr;
	std::string nextstr;
	int i = 0;
	while (true) {
		nextstr = inputVe.at(i);
		action_char = LR_table_action[currentState][indexOf(nextstr, LR_table_action)];
		action_int  =  LR_table_state[currentState][indexOf(nextstr, LR_table_action)];
		if(action_char == 's') {
			stackForStr.push_back(nextstr);
			currentState = action_int;
		}
		else if (action_char == 'r') {
		}
		else{

		}
		//stackForStr.push_back(inputVe.at(i));

	}
	*/

	return 0;
}