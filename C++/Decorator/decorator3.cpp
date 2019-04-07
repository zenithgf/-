//业务操作
//Component类
class Stream{
	public:
		virtual char Read(int number)=0;
		virtual void Seek(int position)=0;
		virtual void Write(char data)=0;

		virtual ~Stream(){}
};
//ConcreteComponent类
class FileStream:public Stream
{
public:
	FileStream();
	~FileStream();
	
	virtual char Read(int number){
		//读文件流
	}
	virtual void Seek(int position){
		//定位文件流
	}
	virtual void Write(char data){
		//写文件流
	}
};
//ConcreteComponent类
class NetworkStream:public Stream
{
public:
	NetworkStream();
	~NetworkStream();

	virtual char Read(int number){
		//读网络流
	}
	virtual void Seek(int position){
		//定位网络流
	}
	virtual void Write(char data){
		//写网络流
	}
	
};
//ConcreteComponent类
class MemoryStream:public Stream
{
public:
	MemoryStream();
	~MemoryStream();

	virtual char Read(int number){
		//读内存流
	}
	virtual void Seek(int position){
		//定位内存流
	}
	virtual void Write(char data){
		//写内存流
	}

};
//扩展操作
//Decorator类
//一般既使用继承又使用组合的类设计 基本都是使用了Decorator设计模式
class DecoratorStream:public Stream
{
protected:
	Stream* stream;//...代码来两个类中有重复就要提升到上层类
	DecoratorStream(Stream* stm):stream(stm){

	}
	~DecoratorStream();
	
};





//加密
class CryptoStream:public DecoratorStream
{
public:
	CryptoStream(Stream* stm):DecoratorStream(stm){

	}
	~CryptoStream();

	//要遵守接口规范所以要继承Stream
	virtual char Read(int number){
		//额外的加密操作...
		stream->Read(number);//读文件流 动态特质
	}
	virtual void Seek(int position){
		//额外的加密操作...
		stream->Seek(position);//定位文件流
		//额外的加密操作...
	}
	virtual void Write(byte data){
		//额外的加密操作...
		stream->Write(data);//写文件流
		//额外的加密操作...
	}
};

//缓存
class BufferedStream:public DecoratorStream
{
public:
	BufferedStream(Stream* stm):DecoratorStream(stm){

	}
	~BufferedStream();
	//.......
	
};



void Process(){
	//运行时装配 编译时不需要有加密文件 缓存文件 加密缓冲文件 那些类,运行时把他们装配出来。
	FileStream* s1=new FileStream();
	//CryptoFile
	CryptoStream* s2=new CryptoStream(s1);
	//BufferedFile
	BufferedStream* s3=new BufferedStream(s1);
	//CryptoBufferedFile
	BufferedStream* s4=new BufferedStream(s2);



}



