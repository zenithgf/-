/***
结构化程序设计方法
***/
//程序库开发人员
class Library{

public:
    void Step1(){//稳定不需要修改
        //...
    }

    void Step3(){//稳定不需要修改
        //...
    }

    void Step5(){//稳定不需要修改
        //...
    }
};
//应用程序开发人员
class Application{
public:
    bool Step2(){//经常改变，需要重新编译
        //...
    }

    void Step4(){//经常改变，需要重新编译
        //...
    }
};

int main()
{
    Library lib();
    Application app();
    //算法的框架流程稳定但由应用程序开发人员编写
    lib.Step1();

    if (app.Step2()){
        lib.Step3();
    }

    for (int i = 0; i < 4; i++){
        app.Step4();
    }

    lib.Step5();

}