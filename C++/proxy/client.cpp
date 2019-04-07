class ISubject{
public:
	virtual void process();	
};

class RealSubject:public ISubject
{
public:
	RealSubject();
	~RealSubject();
	virtual void process(){
		//......
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