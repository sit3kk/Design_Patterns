#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

/*
The Interpreter design pattern is used to define a representation for a language's grammar and 
provides an interpreter that uses this representation to interpret sentences in the language. 
It's useful for easily defining interpreters for various small languages or specialized 
grammars.

Key Elements of the Interpreter Pattern:
- Context: Contains information that's global to the interpreter.
- AbstractExpression: Declares an abstract Interpret operation, which is common to all nodes 
  in the abstract syntax tree.
- TerminalExpression: Implements the Interpret operation for terminal symbols in the grammar.
- NonterminalExpression: One type of node in the abstract syntax tree that represents 
  non-terminal symbols in the grammar. It maintains instances of AbstractExpression to represent 
  each child in the abstract syntax tree.
- Client: Builds the abstract syntax tree representing a particular sentence in the language 
  that the grammar defines. The tree is assembled from instances of the NonterminalExpression 
  and TerminalExpression classes.
*/

// 'Context' class containing the global information
class Context {
public:
    std::unordered_map<std::string, bool> variables;
};

// 'AbstractExpression' interface
class AbstractExpression {
public:
    virtual ~AbstractExpression() {}
    virtual bool interpret(Context& context) const = 0;
};

// 'TerminalExpression' class
class TerminalExpression : public AbstractExpression {
private:
    std::string variableName;

public:
    explicit TerminalExpression(std::string variableName) 
        : variableName(std::move(variableName)) {}

    bool interpret(Context& context) const override {
        return context.variables[variableName];
    }
};

// 'NonterminalExpression' class
class NonterminalExpression : public AbstractExpression {
private:
    std::shared_ptr<AbstractExpression> leftExpression;
    std::shared_ptr<AbstractExpression> rightExpression;

public:
    NonterminalExpression(std::shared_ptr<AbstractExpression> left, 
                          std::shared_ptr<AbstractExpression> right) 
        : leftExpression(std::move(left)), rightExpression(std::move(right)) {}

    bool interpret(Context& context) const override {
        return leftExpression->interpret(context) && rightExpression->interpret(context);
    }
};

// Client code
int main() {
    Context context;
    context.variables["X"] = true;
    context.variables["Y"] = false;

    auto x = std::make_shared<TerminalExpression>("X");
    auto y = std::make_shared<TerminalExpression>("Y");
    auto expression = std::make_shared<NonterminalExpression>(x, y);

    bool result = expression->interpret(context);
    std::cout << "The result is " << (result ? "true" : "false") << std::endl;

    return 0;
}
