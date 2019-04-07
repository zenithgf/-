/***
*工厂模式改造前
***/
//MainForm1.cpp
class MainForm : public Form
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;

public:
    void Button1_Click(){


        
        ISplitter * splitter=
            new BinarySplitter();//依赖具体类
        
        splitter->split();

    }
};

//FileSplitter1.cpp
class ISplitter{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};

class BinarySplitter : public ISplitter{
};

class TxtSplitter: public ISplitter{
};

class PictureSplitter: public ISplitter{
};

class VideoSplitter: public ISplitter{
};