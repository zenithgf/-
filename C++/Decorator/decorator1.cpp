//没有使用装饰者模式的情况,为了扩展功能，子类泛滥
//业务操作
class Stream{
	public:
		virtual char Read(int number)=0;
		virtual void Seek(int position)=0;
		virtual void Write(char data)=0;

		virtual ~Stream(){}
};
//下面三个是主体操作
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
//后面都是扩展操作
//加密
class CryptoFileStream:public FileStream
{
public:
	CryptoFileStream();
	~CryptoFileStream();
	virtual char Read(int number){
		//额外的加密操作...
		FileStream::Read(number);//读文件流  静态特质
	}
	virtual void Seek(int position){
		//额外的加密操作...
		FileStream::Seek(position);//定位文件流
		//额外的加密操作...
	}
	virtual void Write(byte data){
		//额外的加密操作...
		FileStream::Write(data);//写文件流
		//额外的加密操作...
	}
};
class CryptoNetworkStream:public NetworkStream
{
public:
	CryptoNetworkStream();
	~CryptoNetworkStream();
	virtual char Read(int number){
		//额外的加密操作...
		NetworkStream::Read(number);//读网络流
	}
	virtual void Seek(int position){
		//额外的加密操作...
		NetworkStream::Seek(position);//定位网络流
		//额外的加密操作...
	}
	virtual void Write(byte data){
		//额外的加密操作...
		NetworkStream::Write(data);//写网络流
		//额外的加密操作...
	}
	
};
class CryptoMemoryStream:public MemoryStream
{
public:
	CryptoMemoryStream();
	~CryptoMemoryStream();

	virtual char Read(int number){
		//额外的加密操作...
		MemoryStream::Read(number);//读内存流
	}
	virtual void Seek(int position){
		//额外的加密操作...
		MemoryStream::Seek(position);//定位内存流
		//额外的加密操作...
	}
	virtual void Write(byte data){
		//额外的加密操作...
		MemoryStream::Write(data);//写内存流
		//额外的加密操作...
	}
	
};
//缓存
class BufferedFileStream:public FileStream
{
public:
	BufferedFileStream();
	~BufferedFileStream();
	
};
class BufferedNetworkStream:public NetworkStream
{
public:
	BufferedNetworkStream();
	~BufferedNetworkStream();
	
};
class BufferedMemoryStream:public MemoryStream
{
public:
	BufferedMemoryStream();
	~BufferedMemoryStream();
	
};

class CryptoBufferedFileStream:public FileStream
{
public:
	CryptoBufferedFileStream();
	~CryptoBufferedFileStream();

	virtual char Read(int number){
		//额外的加密操作...
		//额外的缓冲操作...
		FileStream::Read(number);//读文件流
	}
	virtual void Seek(int position){
		//额外的加密操作...
		//额外的缓冲操作...
		FileStream::Seek(position);//定位文件流
		//额外的加密操作...
		//额外的缓冲操作...
	}
	virtual void Write(byte data){
		//额外的加密操作...
		//额外的缓冲操作...
		FileStream::Write(data);//写文件流
		//额外的加密操作...
		//额外的缓冲操作...
	}
};

void Process(){
	//编译时装载
	CryptoFileStream *fs1 = new CryptoFileStream();

	BufferedFileStream *fs2 = new BufferedFileStream();

	CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream();
}


