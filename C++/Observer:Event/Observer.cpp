//观察者模式改造前
class FileSplitter{
	string m_filePath;
	int m_fileNumber;

	ProgressBar* m_progressBar;//通知控件；此处不符合依赖倒置原则，mainform 和ProgressBar是高层，filesplitter是低层，ProgressBar不能依赖filesplitter，它容易发生变化

public:
	FileSplitter(const string& filePath,int fileNumber,ProgressBar* progressBar):
	m_filePath(filePath),
	m_fileNumber(fileNumber),
	m_progressBar(progressBar){

	}
	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for(int i=0; i< m_fileNumber; i++){
			//...

			if(m_progressBar != nullptr){
				m_progressBar->setValue((i+1)/m_fileNumber);

			}
		}
	}
};

class MainForm:public Form
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar;	//progressBar和界面是一体的可以紧耦合
public:
	MainForm();
	~MainForm();

	void Button1_Click(){
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		FileSplitter splitter(filePath,number,progressBar);

		splitter.split();
	}
	
};