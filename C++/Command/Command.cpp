#include <vector>
#include <string>
using namespace std;
//行为对象基类
class Command
{
public:
	virtual void execute()=0;

	Command();
	~Command();
};
//把行为封装成对象 可以做为参数传递，作为对象存储，序列化
class  ConcreteCommand1:public Command
{
	string arg;
public:
	 ConcreteCommand1(const string & a):arg(a){}
	~ ConcreteCommand1();
	void execute() override
	{
		cout<< "#1 process..."<<arg<<endl;
	}
};

class  ConcreteCommand2:public Command
{
	string arg;
public:
	 ConcreteCommand2(const string & a):arg(a){}
	~ ConcreteCommand2();
	void execute() override
	{
		cout<< "#2 process..."<<arg<<endl;
	}
};
//命令组合类
class MacroCommand:public Command
{
	vector<Command*> commands;
public:
	MacroCommand();
	~MacroCommand();

	void addCommand(Command *c){commands.push_back(c);}
	void execute() override{
		for (auto &c : commands)
		{
			c->execute();
		}
	}
};

int main(int argc, char const *argv[])
{
	//创建两个命令
	ConcreteCommand1 command1(receiver,"Arg ###");
	ConcreteCommand2 command2(receiver,"Arg $$$");
	//构造一个命令组合
	MacroCommand macro;
	macro.addCommand(&command1);
	macro.addCommand(&command2);

	macro.execute();
	
	return 0;
}
