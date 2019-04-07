class ISubject{
public:
	virtual void process();	
};

class RealSubject:public ISubject
{
public:
	RealSubject();
	~RealSubject();
	
};
//proxy的设计
class SubjectProxy:public ISubject
{
	RealSubject* realSubject;//此处可以不放
public:
	SubjectProxy();
	~SubjectProxy();
	virtual void process(){
		//对RealSubject的一种间接访问
		//可以做RealSubject 的安全控制，性能提升，分布式访问等
	}
	
};


class ClientApp
{
	ISubject*	subject;
public:
	ClientApp(){
		subject=new RealSubject(); //因为安全控制或分布式的原因 根本拿不到这个对象
	}
	~ClientApp();

	void DoTask(){
		//...
		subject->process();
		//...
	}
	
};