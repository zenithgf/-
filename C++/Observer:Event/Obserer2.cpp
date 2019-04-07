//使用观察者模式后，支持单个观察者对象通知的观察者模式
class IProgress
{
public:
	IProgress();

	virtual void DoProgress(float value)=0;

	virtual ~IProgress();
	
};

class FileSplitter{
	string m_filePath;
	int m_fileNumber;

	//ProgressBar* m_progressBar;//通知控件；
	IProgress* m_iprogress;//抽象通知机制,不再紧耦合一个界面类，可以独立编译，放到任何系统类型的界面中

public:
	FileSplitter(const string& filePath,int fileNumber,IProgress* iprogress):
	m_filePath(filePath),
	m_fileNumber(fileNumber),
	m_iprogress(iprogress){

	}
	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for(int i=0; i< m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i+1)/progressValue;
			onProgress(progressValue);	
		}
	}
protected:
	virtual void onProgress(float value){
		if(m_iprogress != nullptr){
			m_iprogress->DoProgress(value);//更新进度条
		}
	}
};

//c++ 支持多继承方案，好的多继承方法是:主继承一个类，副继承多个接口或抽象类。(不要多继承多个实体类)
class MainForm:public Form,public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar;
public:
	MainForm();
	~MainForm();

	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		//输出到控制台
		ConsoleNotifier cn;
		FileSplitter splitter(filePath,number,&cn);

		//输出到进度条面板
		//FileSplitter splitter(filePath,number,this);

		splitter.split();
	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

class ConsoleNotifier:public IProgress
{
public:
	ConsoleNotifier();
	~ConsoleNotifier();

	virtual void DoProgress(float value){
		cout << ".";
	}
	
};


