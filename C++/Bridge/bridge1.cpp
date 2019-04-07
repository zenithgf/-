class Messager{
public:
	//业务函数
	virtual void Login(string username,string password)=0;
	virtual void SendMessage(string messager)=0;
	virtual void SendPicture(Image image)=0;
	//实现函数
	virtual void PlaySound()=0;
	virtual void DrawShape()=0;
	virtual void WriteText()=0;
	virtual void Connect()=0;

	virtual ~Messager(){}
};

//一个变化方向是平台实现

class PCMessagerBase : public Messager
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

class MobileMessageBase:public Messager
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

//另一个变化方向是业务抽象
class PCMessagerLite:public PCMessagerBase
{
public:
	PCMessagerLite();
	~PCMessagerLite();

	virtual void Login(string username,string password){
		PCMessagerBase::Connect();
		//.............
	}
	virtual void SendMessage(string message){
		PCMessagerBase::WriteText();
		//........
	}
	virtual void SendPicture(Image image){

		PCMessagerBase::DrawShape();
		//........
	}
	
};

class PCMessagerPerfect:public PCMessagerBase
{
public:
	PCMessagerPerfect();
	~PCMessagerPerfect();

	virtual void Login(string username,string password){
		PCMessagerBase::PlaySound();
		//*******
		PCMessagerBase::Connect();
		//.......
	}
	virtual void SendMessage(string message){
		PCMessagerBase::PlaySound();
		//*******
		PCMessagerBase::WriteText();
		//.......
	}
	virtual void SendPicture(Image image){
		PCMessagerBase::PlaySound();
		//********
		PCMessagerBase::DrawShape();
		//........
	}
};

class MobileMessagerLite:public MobileMessagerBase
{
public:
	MobileMessagerLite();
	~MobileMessagerLite();

	virtual void Login(string username,string password){
		MobileMessagerBase::Connect();
		//.............
	}
	virtual void SendMessage(string message){
		MobileMessagerBase::WriteText();
		//........
	}
	virtual void SendPicture(Image image){

		MobileMessagerBase::DrawShape();
		//........
	}
	
};

class MobileMessagerPerfect:public MobileMessagerBase
{
public:
	MobileMessagerPerfect();
	~MobileMessagerPerfect();

	virtual void Login(string username,string password){
		MobileMessagerBase::PlaySound();
		//*******
		MobileMessagerBase::Connect();
		//.......
	}
	virtual void SendMessage(string message){
		MobileMessagerBase::PlaySound();
		//*******
		MobileMessagerBase::WriteText();
		//.......
	}
	virtual void SendPicture(Image image){
		MobileMessagerBase::PlaySound();
		//********
		MobileMessagerBase::DrawShape();
		//........
	}
};

void Process(){
	//编译时装配
	Messager *m= new MobileMessagerPerfect();
}






