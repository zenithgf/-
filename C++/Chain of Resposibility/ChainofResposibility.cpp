enum class RequestType
{
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3,	
};
//请求者 基类
class Reqest
{
	string description;
	RequestType reqType;
public:
	Reqest(const string & desc,RequestType type):description(desc),reqType()
	RequestType getReqType() const {return reqType;}
	const string& getDescription() const {return description;}
	~Reqest();
	
};
//处理者、接收者 基类
class ChainHandler
{
	ChainHandler* nextChain;
	//发送请求给下一个接收者
	void sendReqestToNextHandler(const Reqest & req){
		if (nextChain!=nullptr)
			nextChain->handle(req);
	}
protected:
	virtual bool canHandleRequest(const Reqest & req)=0;//运行时判断当前接收者是否能处理这个请求
	virtual void processRequest(const Reqest & req)=0;//运行时具体处理这个请求
public:
	ChainHandler(){nextChain = nullptr;}//初始化时 把链表设为空指针
	~ChainHandler();
	//设置当前链的下一一个链节点
	void setNextChain(ChainHandler *next){ nextChain = next; }
	//当前链的处理逻辑，当前链如果能够处理就处理请求，不能转给下一个节点处理
	void handle(const Reqest & req)
	{
		if (canHandleRequest(req))
		
			processRequest(req);
		else
			sendReqestToNextHandler(req); 
	}
};

class Handler1:public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER1;//判断当前请求类型是否为Handler1类型
	}
	void processRequest(const Reqest & req) override
	{
		cout << "Handler1 is handle reqest:" << req.getDescription() << endl;
	}
public:
	Handler1();
	~Handler1();
};

class Handler2:public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER2;//判断当前请求类型是否为Handler2类型
	}
	void processRequest(const Reqest & req) override
	{
		cout << "Handler2 is handle reqest:" << req.getDescription() << endl;
	}
public:
	Handler2();
	~Handler2();
};

class Handler3:public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req) override
	{
		return req.getReqType() == RequestType::REQ_HANDLER3;//判断当前请求类型是否为Handler3类型
	}
	void processRequest(const Reqest & req) override
	{
		cout << "Handler3 is handle reqest:" << req.getDescription() << endl;
	}
public:
	Handler3();
	~Handler3();
};

int main(int argc, char const *argv[])
{
	//创建处理器，构成处理器链表
	Handler1 h1;
	Handler2 h2;
	Handler3 h3;
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);
	//创建一个处理类型为HANDLER3的请求对象
	Reqest req("process task ...",RequestType::REQ_HANDLER3);
	//处理器处理请求对象
	h1.handle(req);
	
	return 0;
}