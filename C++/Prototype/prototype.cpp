

//相当于Prototype
class ISplitter{
public:
    virtual void split()=0;//接口稳定

    virtual ISplitter* clone()=0;//通过克隆自己来创建对象

    virtual ~ISplitter(){}

};

//具体类
//相当于ConcretePrototype1
class BinarySplitter : public ISplitter{
public:
    virtual ISplitter* clone(){
        return new BinarySplitter(*this);//用拷贝构造函数克隆自己,拷贝构造函数要写正确
    }
};
//相当于ConcretePrototype2
class TxtSplitter: public ISplitter{
public:
    virtual ISplitter* clone(){
        return new TxtSplitter(*this);//用拷贝构造函数克隆自己,拷贝构造函数要写正确
    }
};

class PictureSplitter: public ISplitter{
public:
    virtual ISplitter* clone(){
        return new  PictureSplitter(*this);//用拷贝构造函数克隆自己,拷贝构造函数要写正确
    }    
};

class VideoSplitter: public ISplitter{
public:
    virtual ISplitter* clone(){
        return new VideoSplitter(*this);//用拷贝构造函数克隆自己,拷贝构造函数要写正确
    }    
};
//相当于Client
class MainForm : public Form
{
    ISplitter*  prototype;//工厂

public:
    
    MainForm(ISplitter*  prototype){
        this->prototype=prototype;
    }
    //相当于Operation()
    void Button1_Click(){
        
        ISplitter * splitter=
            prototype->clone(); //克隆原型,原型对象不能直接使用,必须通过克隆创建一个新对象来使用
        
        splitter->split();

    }
};