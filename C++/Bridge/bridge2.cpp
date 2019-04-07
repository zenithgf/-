//使用桥模式后
//相当于Abstraction
class Messager{
protected:
	MessagerImp* messager;//new PCMessagerBase();或MobileMessagerBase();
public:
	Messager(){
		messager = new MessagerImp();
	}
	//下面相当于Operation()
	virtual void Login(string username,string password)=0;
	virtual void SendMessage(string messager)=0;
	virtual void SendPicture(Image image)=0;
	virtual ~Messager(){}
};
//相当于Implementor
class MessagerImp{
public:
	//下面相当于OperationImp()
	virtual void PlaySound()=0;
	virtual void DrawShape()=0;
	virtual void WriteText()=0;
	virtual void Connect()=0;

	virtual ~MessagerImp(){}
};

//平台实现
//相当于ConcreteImplementorA
class PCMessagerBase : public MessagerImp
{
public:
	PCMessagerBase();
	~PCMessagerBase();

	virtual void PlaySound(){
		//*********
	}
	virtual void DrawShape(){
		//********
	}
	virtual void Connect(){
		//********
	}
};
//相当于ConcreteImplementorB
class MobileMessageBase:public MessagerImp
{
public:
	MobileMessageBase();
	~MobileMessageBase();

	virtual void PlaySound(){
		//======
	}
	virtual void DrawShape(){
		//======
	}
	virtual void WriteText(){
		//======
	}
	virtual void  Connect(){
		//======
	}
};

//业务抽象
//相当于RefinedAbstraction
class MessagerLite : public Messager
{
public:
	MessagerLite(){
		messager = new Messager();
	}
	~MessagerLite();

	virtual void Login(string username,string password){
		messager->Connect();
		//.............
	}
	virtual void SendMessage(string message){
		messager->WriteText();
		//........
	}
	virtual void SendPicture(Image image){

		messager->DrawShape();
		//........
	}
	
};
//相当于RefinedAbstraction
class MessagerPerfect : public Messager
{
	
public:
	MessagerPerfect(){
		messager = new Messager();
	}
	~MessagerPerfect();

	virtual void Login(string username,string password){
		messager->PlaySound();
		//*******
		messager->Connect();
		//.......
	}
	virtual void SendMessage(string message){
		messager->PlaySound();
		//*******
		messager->WriteText();
		//.......
	}
	virtual void SendPicture(Image image){
		messager->PlaySound();
		//********
		messager->DrawShape();
		//........
	}
};


void Process(){
	//运行时装配
	MessagerImp* mImp = new PCMessagerImp();
	Messager* m = new Messager(mImp); 
}






