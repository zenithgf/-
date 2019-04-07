//使用visitor模式的情况
#include <iostream>
using namespace std;

class Visitor;
//要添加行为的类
class Element
{
public:
	virtual void accept(Visitor& Visitor)=0;//第一次多态辨析

	virtual ~Element(){}
};
//要添加行为的子类
class ElementA:public Element
{
public:
	void accept(Visitor &Visitor) override{
		visitor.visitElementA(*this);//第二次多态辨析
	}
	
};

class ElementB:public Element
{
public:
	void accept(Visitor &Visitor) override{
		visitor.visitElementB(*this);
	}
	
};
//把行为封装到Visitor中与具体的类绑定 (Visitor稳定的前提是Element的子类必须确定)
class Visitor
{
public:
	virtual void visitElementA(ElementA& element)=0;
	virtual void visitElementB(ElementB& element)=0;
	~Visitor();
};

//==================================
//扩展
//在Visitor子类中为相应类实现要添加的具体行为
class Visitor1 : public Visitor
{
public:
	void visitElementA(ElementA& element)override{
		cout <<"Visitor1 is processing ElementA"<<endl;
	}
	void visitElementB(ElementB& element)override{
		cout <<"Visitor1 is processing ElementB"<<endl;
	}
};
//扩展
class Visitor2 : public Visitor
{
public:
	void visitElementA(ElementA& element)override{
		cout <<"Visitor2 is processing ElementA"<<endl;
	}
	void visitElementB(ElementB& element)override{
		cout <<"Visitor2 is processing ElementB"<<endl;
	}
};

//=============================

int main(int argc, char const *argv[])
{
	Visitor2 visitor;
	ElementB elementB;
	elementB.accept(visitor);// double dispatch 两次派遣

	ElementA elementA;
	elementA.accept(visitor);
	return 0;
}