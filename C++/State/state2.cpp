//对比策略模式看看异同
//策略模式是改变一个行为
//状态模式可以改变多个行为
//相当于State
class NetworkState{//把状态封装为一个抽象基类
private:
	NetworkState* pNext;
public:
	//把状态影响的行为都改变成状态的虚函数，再子类中去实现变化
	//相当于Handle()
	virtual void Operation1()=0;
	virtual void Operation2()=0;
	virtual void Operation3()=0;

	virtual ~NetworkState(){}
};
//扩展状态
//相当于ConcreteStateA
class OpenState:public NetworkState
{
	static NetworkState* m_instance;//使用singlton模式封装具体的状态
public:
	static NetworkState* getInstance(){
		if (m_instance == nullptr)
		{
			m_instance = new OpenState();
		}
		return m_instance;
	}

	void Operation1(){
		//******
		pNext = CloseState::getInstance();
	}

	void Operation2(){
		//.......
		pNext = ConnectState::getInstance();
	}

	void Operation3(){
        //$$$$$$$$
        pNext = OpenState::getInstance();
	}

	OpenState();
	~OpenState();
	
};
//相当于ConcreteStateB
class CloseState:public NetworkState
{
public:
	CloseState();
	~CloseState();
};

class WaitState:public NetworkState
{
public:
	WaitState();
	~WaitState();
};

//当状态调用者不用做任何修改，只要新增新的状态子类就行了。
//相当于Context
class NetworkProcessor
{
	NetworkState* pState;
public:
	NetworkProcessor(NetworkState* pState){
		this->pState = pState;
	}
	~NetworkProcessor();
	//相当于Request()
	void Operation1(){
		//....收集参数给到pState->Operation1()
		pState->Operation1();//虚函数实质上是一个运行时的if else//相当于state->Handle()
		pState=pState->pNext;//pNext会在pState->Operation1()中被修改，然后在此处赋给pState
		//....
	}

	void Operation2(){
		//...收集参数
		pState->Operation2();
		pState= pState->pNext;
		//...
	}

	void Operation3(){
		//...收集参数
		pState->Operation3();
		pState = pState->pNext;
		//...
	}
	
};