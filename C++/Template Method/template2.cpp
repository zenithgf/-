//程序库开发人员
class Library{
public:
    //稳定 template method 算法流程稳定，改由框架开发人员编写
    void Run(){
        
        Step1();

        if (Step2()) { //支持变化 ==> 虚函数的多态调用
            Step3(); 
        }

        for (int i = 0; i < 4; i++){
            Step4(); //支持变化 ==> 虚函数的多态调用
        }

        Step5();

    }
    virtual ~Library(){ }//基类必须写析构函数,并且写成虚函数,防止子类析构函数会重载和调用

protected:
    
    void Step1() { //稳定
        //.....
    }
    void Step3() {//稳定
        //.....
    }
    void Step5() { //稳定
        //.....
    }

    virtual bool Step2() = 0;//变化
    virtual void Step4() =0; //变化
};

//应用程序开发人员
class Application : public Library {
protected:
    virtual bool Step2(){
        //... 子类重写实现
    }

    virtual void Step4() {
        //... 子类重写实现
    }
};




int main()
    {
        Library* pLib=new Application();
        lib->Run();//lib中的算法流程去调用 application中的算法步骤 就是晚绑定

        delete pLib;
    }
}