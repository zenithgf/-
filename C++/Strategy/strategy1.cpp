//结构化设计模式
//违背开放封闭原则，扩展需要更改源代码，代码复用性不高
//if-else方式
enum TaxBase {
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax       //更改
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        
        if (tax == CN_Tax){
            //CN***********
        }
        else if (tax == US_Tax){
            //US***********
        }
        else if (tax == DE_Tax){
            //DE***********
        }
        else if (tax == FR_Tax){  //更改
            //...
        }

        //....
     }
    
};