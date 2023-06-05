#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>

#define LR_table_action_col_size 38

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

    slr_grammar.L.push_back("CODE");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("VDECL");
    vePointer->push_back("CODE");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("CODE");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("FDECL");
    vePointer->push_back("CODE");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("CODE");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("CDECL");
    vePointer->push_back("CODE");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("CODE");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("");//입실론
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("VDECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("vtype");
    vePointer->push_back("id");
    vePointer->push_back("semi");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("VDECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("vtype");
    vePointer->push_back("ASSIGN");
    vePointer->push_back("semi");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ASSIGN");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("id");
    vePointer->push_back("assign");
    vePointer->push_back("RHS");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("RHS");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("EXPR");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("RHS");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("literal");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("RHS");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("character");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("RHS");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("boolstr");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("EXPR_");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("EXPR_");
    vePointer->push_back("addsub");
    vePointer->push_back("EXPR");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("EXPR_");
    vePointer->push_back("multdiv");
    vePointer->push_back("EXPR");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR_");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("lparen");
    vePointer->push_back("EXPR");
    vePointer->push_back("rparen");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR_");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("id");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("EXPR_");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("num");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("FDECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("vtype");
    vePointer->push_back("id");
    vePointer->push_back("lparen");
    vePointer->push_back("ARG");
    vePointer->push_back("rparen");
    vePointer->push_back("lbrace");
    vePointer->push_back("BLOCK");
    vePointer->push_back("RETURN");
    vePointer->push_back("rbrace");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ARG");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("vtype");
    vePointer->push_back("id");
    vePointer->push_back("MOREARGS");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ARG");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("asdf");//입실론
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("MOREARGS");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("comma");
    vePointer->push_back("vtype");
    vePointer->push_back("id");
    vePointer->push_back("MOREARGS");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("MOREARGS");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("asdf");//입실론
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("BLOCK");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("STMT");
    vePointer->push_back("BLOCK");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("BLOCK");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("asdf");//입실론
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("STMT");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("VDECL");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("STMT");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("ASSIGN");
    vePointer->push_back("semi");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("STMT");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("if");
    vePointer->push_back("lparen");
    vePointer->push_back("COND");
    vePointer->push_back("rparen");
    vePointer->push_back("lbrace");
    vePointer->push_back("BLOCK");
    vePointer->push_back("rbrace");
    vePointer->push_back("ELSE");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("STMT");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("while");
    vePointer->push_back("lparen");
    vePointer->push_back("COND");
    vePointer->push_back("rparen");
    vePointer->push_back("lbrace");
    vePointer->push_back("BLOCK");
    vePointer->push_back("rbrace");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("COND");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("boolstr");
    vePointer->push_back("comp");
    vePointer->push_back("COND");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("COND");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("boolstr");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ELSE");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("else");
    vePointer->push_back("lbrace");
    vePointer->push_back("BLOCK");
    vePointer->push_back("rbrace");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ELSE");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("asdf");//입실론
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("RETURN");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("return");
    vePointer->push_back("RHS");
    vePointer->push_back("semi");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("CDECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("class");
    vePointer->push_back("id");
    vePointer->push_back("lbrace");
    vePointer->push_back("ODECL");
    vePointer->push_back("rbrace");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ODECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("VDECL");
    vePointer->push_back("ODECL");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ODECL");
    vePointer = new std::vector<std::string>;
    vePointer->push_back("FDECL");
    vePointer->push_back("ODECL");
    slr_grammar.R.push_back(*vePointer);

    slr_grammar.L.push_back("ODECL");
    vePointer = new std::vector<std::string>;
    //vePointer->push_back("asdf");
    slr_grammar.R.push_back(*vePointer);
}

void initTerminals(std::vector<std::string>& Terminals) {
    Terminals.push_back("vtype");
    Terminals.push_back("num");
    Terminals.push_back("character");
    Terminals.push_back("boolstr");
    Terminals.push_back("literal");
    Terminals.push_back("id");
    Terminals.push_back("if");
    Terminals.push_back("else");
    Terminals.push_back("while");
    Terminals.push_back("return");
    Terminals.push_back("class");
    Terminals.push_back("addsub");
    Terminals.push_back("multdiv");
    Terminals.push_back("assign");
    Terminals.push_back("comp");
    Terminals.push_back("semi");
    Terminals.push_back("comma");
    Terminals.push_back("lparen");
    Terminals.push_back("rparen");
    Terminals.push_back("lbrace");
    Terminals.push_back("rbrace");
}

void initNon_terminals(std::vector<std::string>& Non_terminals) {
    Non_terminals.push_back("CODE");
    Non_terminals.push_back("VDECL");
    Non_terminals.push_back("ASSIGN");
    Non_terminals.push_back("RHS");
    Non_terminals.push_back("EXPR");
    Non_terminals.push_back("FDECL");
    Non_terminals.push_back("ARG");
    Non_terminals.push_back("MOREARGS");
    Non_terminals.push_back("BLOCK");
    Non_terminals.push_back("STMT");
    Non_terminals.push_back("COND");
    Non_terminals.push_back("ELSE");
    Non_terminals.push_back("RETURN");
    Non_terminals.push_back("CDECL");
    Non_terminals.push_back("ODECL");
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

void printveForStr(std::vector<std::string>& veForStr) {
    for (int i = 0; i < veForStr.size(); i++) {
        std::cout << veForStr.at(i) << " ";
    }
}
void printremaininginputVe(std::vector<std::string>&  inputVe, int i) {
    for (; i < inputVe.size(); i++) {
        std::cout << inputVe.at(i) << " ";
    }
}


int main(int argc, char** argv) {

    std::string Start_symbol = "CODE";
    SLRgrammar slr_grammar;
    initSLRGrammar(slr_grammar);
    std::vector<std::string> Terminals, Non_terminals;
    initTerminals(Terminals);
    initNon_terminals(Non_terminals);

    std::string LR_table_action_stand[LR_table_action_col_size] = { "vtype",   "id",   "semi",   "assign",   "literal",   "character",   "boolstr",   "addsub",   "multdiv",   "lparen",   "rparen",   "num",   "lbrace",   "rbrace",   "comma",   "if",   "while",   "comp",   "else",   "return",   "class",   "$",   "CODE",   "VDECL",   "ASSIGN",   "RHS",   "EXPR",   "EXPR_",   "FDECL",   "ARG",   "MOREARGS",   "BLOCK",   "STMT",   "COND",   "ELSE",   "RETURN",   "CDECL",   "ODECL" };
    char LR_table_action[84][LR_table_action_col_size] =
    {
        //vtype   id   semi   assign   literal   character   boolstr   addsub   multdiv   lparen   rparen   num   lbrace   rbrace   comma   if   while   comp   else   return   class   $   CODE   VDECL   ASSIGN   RHS   EXPR   EXPR_   FDECL   ARG   MOREARGS   BLOCK   STMT   COND   ELSE   RETURN   CDECL   ODECL
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//0
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'a', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 's', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//10
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 's', 's', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 's', 's', 's', 'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//20
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 's', 's', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'r', 'r', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'r', 'r', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//30
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//40
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'r', 'x', 'x', 'x', 'x', 'r', 'r', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 's', 's', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 's', 's', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},//50
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 's', 'x', 'x', 's', 's', 's', 'x', 'x', 's', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 's', 's', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 's', 's', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 's', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'s', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 's', 's', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 's', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'r', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'r', 'x', 'r', 'r', 'x', 'x', 'r', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}
    };
    int LR_table_state[84][LR_table_action_col_size] =
    {
        //+  *  (  ) id  $ E'  E  T  F
        {2 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7 ,3 ,3 ,1 ,-1,-1,-1,-1,4 ,-1,-1,-1,-1,-1,-1,-1,5 ,-1},
        {-1,8 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7 ,3 ,10,1 ,-1,-1,-1,-1,4 ,-1,-1,-1,-1,-1,-1,-1,5 ,-1},
        {6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7 ,3 ,11,1 ,-1,-1,-1,-1,4 ,-1,-1,-1,-1,-1,-1,-1,5 ,-1},
        {-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,14,15,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {4 ,4 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4 ,-1,4 ,4 ,-1,-1,4 ,4 ,4 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,26,-1,-1,21,22,23,-1,-1,25,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1 ,19,20,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {5 ,5 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 ,-1,5 ,5 ,-1,-1,5 ,5 ,5 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {29,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1},
        {6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,30},
        {-1,-1,6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,7 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,8 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,9 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,11,-1,-1,-1,-1,33,34,-1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,26,-1,-1,-1,-1,-1,-1,-1,25,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,35,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,15,-1,-1,-1,-1,15,15,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,16,-1,-1,-1,-1,16,16,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,37,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,39},
        {6 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,40},
        {-1,26,-1,-1,-1,-1,-1,-1,-1,25,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,41,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,26,-1,-1,-1,-1,-1,-1,-1,25,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1,-1,-1,46,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,-1,-1,-1,-1,-1,-1,-1},
        {33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,12,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,13,-1,-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,14,-1,-1,-1,-1,14,14,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {2 ,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,51,52,-1,-1,23,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,47,48,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {54,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,56,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1},
        {2 ,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,51,52,-1,-1,23,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,57,48,-1,-1,-1,-1,-1},
        {24,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24,-1,24,24,-1,-1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,58,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,59,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,60,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,61,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,26,-1,-1,21,22,23,-1,-1,25,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,63,20,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,-1,25,25,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,64,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,-1,-1,-1,46,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,67,-1,-1,-1,-1,-1,-1,-1},
        {17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,17,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,69,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,70,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,71,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,72,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,73,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,74,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {2 ,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,51,52,-1,-1,23,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,75,48,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {2 ,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,51,52,-1,-1,23,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,76,48,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,78,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {31,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,31,31,-1,80,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,79,-1,-1,-1},
        {27,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,27,-1,27,27,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {26,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26,-1,26,26,-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,81,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {2 ,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,-1,51,52,-1,-1,23,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,82,48,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,83,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {30,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,-1,30,30,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };


    std::vector<std::string> inputStr;//{ {"id + id * id * id + id"} };
    std::vector<std::string> inputVe;
    std::vector<std::string> temp_inputVe;
    


    //std::cout << argv[1];
    std::string line;
    //std::ifstream file("input.txt"); // example.txt 파일을 연다. 없으면 생성. //argv[1]
    std::ifstream file(argv[1]);

    if (file.is_open()) {
        while (getline(file, line)) {
            //std::cout << line << std::endl;
            temp_inputVe = split(line, ' ');
            for (int k = 0; k < temp_inputVe.size(); k++) {
                inputVe.push_back(temp_inputVe.at(k));
            }
        }
        file.close(); // 파일 닫기. 
    }
    else {
        std::cout << "파일을 열 수 없습니다." << std::endl;
    }
    inputVe.push_back("$");

    for (int i = 0; i < inputVe.size(); i++) {
        //std::cout << inputVe.at(i) << std::endl;
    }

    
    /*
    //test1
    std::vector<std::string> inputVe;
    //vtype id semi
    inputVe.push_back("vtype");
    inputVe.push_back("id");
    inputVe.push_back("semi");
    inputVe.push_back("$");
    */
    int currentState = 0;
    int action_char = '0';
    int action_int = 0;
    std::vector<int> stForState;
    stForState.push_back(0);
    std::vector<std::string> veForStr;

    std::string nextstr;
    int i = 0;
    printveForStr(veForStr);
    printremaininginputVe(inputVe, i);
    std::cout << "\n";
    while (true) {
        currentState = stForState.back();
        nextstr = inputVe.at(i);
        //veForStr.push_back(nextstr);
        action_char = LR_table_action[currentState][indexOf(nextstr, LR_table_action_stand)];
        action_int = LR_table_state[currentState][indexOf(nextstr, LR_table_action_stand)];
        //std::cout << (char)action_char << ' ' << action_int << "\n";
        //std::cout << currentState << ' ' << indexOf(nextstr, LR_table_action_stand) << "\n";
        
        //std::cout << "\n";
        //printf("%c\n", action_char);
        if (action_char == 's') {
            i++;
            veForStr.push_back(nextstr);
            stForState.push_back(action_int);
        }
        else if (action_char == 'r') {
            reduceVeForStrThingBy(slr_grammar, veForStr, action_int);
            reduceStForStateThingBy(slr_grammar, stForState, action_int);
            printveForStr(veForStr);
            printremaininginputVe(inputVe, i);
            std::cout << "\n";
            currentState = stForState.back();
            action_int = LR_table_state[currentState][indexOf(veForStr.back(), LR_table_action_stand)];
            stForState.push_back(action_int);
        }
        else if (action_char == 'a') {
            std::cout << "CODE";
            std::cout << "\n";
            std::cout << "성공\n";
            break;
        }
        else if (action_char == 'x') {
            printveForStr(veForStr);
            std::cout << "|";
            printremaininginputVe(inputVe, i);
            std::cout << "\n";
            std::cout << "파싱 불가능";
            std::cout << "\n";
            std::cout << "실패\n";
            break;
        }
    }
   

    std::cout << "프로그램종료\n";

    return 0;
}