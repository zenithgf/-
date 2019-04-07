/***
*使用观察者模式后，支持多个观察者对象通知的观察者模式
***/
//相当于Observer
class IProgress
{
public:
	IProgress();
	//相当于Update
	virtual void DoProgress(float value)=0;

	virtual ~IProgress();
	
};

//是订阅者 进度条等界面类依赖它 相当于把subject和ConcreteSubject合二为一
class FileSplitter{
	string m_filePath;
	int m_fileNumber;

	//ProgressBar* m_progressBar;//通知控件；
	List<IProgress*> m_iprogressList;//抽象通知机制,不再紧耦合一个界面类，可以独立编译，放到任何系统类型的界面中

public:
	FileSplitter(const string& filePath,int fileNumber):
	m_filePath(filePath),
	m_fileNumber(fileNumber){

	}
	//相当于Attach
	void addIProgress(IProgress* iprogress){
		m_iprogressList.add(iprogress);
	}
	//相当于Detach
	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}


	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for(int i=0; i< m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i+1)/progressValue;
			onProgress(progressValue);	//发送通知
		}
	}
protected:
	//相当于Notify
	virtual void onProgress(float value){
		List<IProgress*>::Iterator itor=m_iprogressList.begin();
		while(itor != m_iprogressList.end()){
			(*itor)->DoProgress(value);//更新进度条
			itor++;
		}
	}
};

//c++ 支持多继承方案，好的多继承方法是:主继承一个类，副继承多个接口或抽象类。(不要多继承多个实体类)
//相当于ConcreteObserver
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

		ConsoleNotifier cn;
		FileSplitter splitter(filePath,number);
		//支持两个观察者
		splitter.addIProgress(this);
		splitter.addIProgress(&cn);

		splitter.split();

		splitter.removeIProgress(this);
		splitter.removeIProgress(&cn);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}

};
//相当于ConcreteObserver
class ConsoleNotifier:public IProgress
{
public:
	ConsoleNotifier();
	~ConsoleNotifier();

	virtual void DoProgress(float value){
		cout << ".";
	}
	
};