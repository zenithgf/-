#include <map>
#include <stack>

using namespace std;
//总表达式基类(AbstractExpression)
class  Expression
{
public:
	virtual int interpreter(map<char,int>)=0;//获得表达式值或经过运算后获取表达式值
	virtual ~ Expression();
};

//变量表达式  叶子节点(TerminalExpression)
class VarExpression:public Expression
{
	char key;//变量名
public:
	VarExpression(const char& key){
		this->key = key;
	}
	int interpreter(std::map<char,int> var)override{
		return var[key];
	}
	~VarExpression();
};

//符号表达式(NonterminalExpression)
class SymbolExpression : public Expression
{
	//运算符左右两个参数
protected:
	Expression* left;//符号左边的变量
	Expression* right;//符号右边的变量
public:
	SymbolExpression(Expression* left,Expression* right):left(left),right(right){

	}
	~SymbolExpression();
};

//加法运算
class AddExpression:public SymbolExpression
{
public:
	AddExpression(Expression* left,Expression* right):SymbolExpression(left,right){

	}

	int interpreter(map<char,int>var) override{
		return left->interpreter(var)+right->interpreter(var);
	}
	~AddExpression();
	
};

//减法运算
class SubExpression:public SymbolExpression
{
public:
	SubExpression(Expression* left,Expression* right):SymbolExpression(left,right){

	}

	int interpreter(map<char,int>var) override{
		return left->interpreter(var)-right->interpreter(var);
	}
	~SubExpression();
};

Expression* analyse(string expStr){
	stack<Expression*> expStack;
	Expression* left = nullptr;
	Expression* right = nullptr;
	for (int i = 0; i < expStr.size(); ++i)
	{
		swithch(expStr[i]){
				case '+':
					//加法运算
					left = expStack.top();//取出栈顶元素放入left 变量
					right = new VarExpression(expStr[++i]);//把i的后一个元素放入right 变量
					expStack.push(new AddExpression(left,right));//把整个加法表达式(左子树)放入栈中
					break;
				case '-':
					//减法运算
					left = expStack.top();//取出栈顶 加法表达式 放入 left
					right = new VarExpression(expStr[++i]);//把i后一个元素放入right
					expStack.push(new SubExpression(left,right));//把左子树放入栈中
					break;
				default:
					//变量表达式
					expStack.push(new VarExpression(expStr[i]));
		}
	}
	Expression* expression = expStack.top();//取栈顶 拿到整个表达式
	return expression;
}

void release(Expression* expression){
	//释放表达式树的节点内存...
}

int main(int argc, char const *argv[])
{
	string expStr = "a+b-c+d";
	map<char, int> var;
	var.insert(make_pair('a',5));
	var.insert(make_pair('b',2));
	var.insert(make_pair('c',1));
	var.insert(make_pair('d',6));

	Expression* expression = analyse(expStr);

	int result = expression->interpreter(var);

	cout<<result<<endl;

	release(expression);

	return 0;
}

