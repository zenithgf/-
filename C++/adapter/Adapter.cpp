//目标接口(新接口)
class ITarget
{
public:
	 virtual void process()=0;
};
//遗留接口(老接口)
class  IAdaptee
{
public:
	 virtual void foo(int data)=0;
	 virtual int bar()=0;
};
//遗留类型
class OldClass:public IAdaptee
{
public:
	OldClass();
	~OldClass();
	//...
	
};
//对象适配器 把老接口转换成新接口
class Adapter:public ITarget
{//继承
protected:
	IAdaptee* pAdaptee;//组合
public:
	Adapter();
	~Adapter();

	virtual void process(){
		int data=pAdaptee->bar();
		pAdaptee->foo(data);
	}
	
};

//类适配器 无灵活性定死在OldClass上
class Adapter:public ITarget,protected OldClass{//多继承
	//protected 和privat 继承是实现继承 只复用函数实现不继承函数
public:
	Adapter();
	~Adapter();
	
};

//把老的对象传入适配器中变成新的对象，用新对象函数代替老对象函数
int main(){
	IAdaptee* pAdaptee=new OldClass();

	ITarget* pTarget=new Adapter(pAdaptee);
	pTarget->process();
}


//STL 框架中的例子 stack和queue都即是接口又是实现 包含了旧的对象 来转换它的接口。 (适配器模式的一个变种)
class  stack{
	deqeue* container;
	
};
class  queue{
	deqeue* container;
	
};



