#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Component
{
public:
	virtual void process()=0;

	Component();
	~Component();
};
//树节点
class Composite:public Component
{
	string name;
	list<Component*> elements;
public:
	Composite(const string & s);name(s){}
	~Composite();

	void add(Component* element){
		element.push_back(element);
	}
	void remove(Component* element){
		elements.remove(element);
	}

	void process(){
		//process current node

		//process leaf nodes 把树形结构的访问封装在了数据类型的内部，而不是暴露给外部访问
		for (auto &e : elements)
			e->process();//多态调用 此处是一对多的关系
	}
};
//叶子节点
class  Leaf:public Component
{
	string name;
public:
	 Leaf(string s):name(s){}
	~ Leaf();

	void process(){
		//process current node
	}
};
//客户程序 
void Invoke(Component & c){
	//...
	c.process();//多态调用 此处是一对一的关系
	//...
}

int main(int argc, char const *argv[])
{
	Composite root("root");
	Composite treeNode1("treeNode1");
	Composite treeNode2("treeNode2");
	Composite treeNode3("treeNode3");
	Composite treeNode4("treeNode4");
	Leaf leaf1("left1");
	Leaf leaf2("left2");

	root.add(&treeNode1);
	treeNode1.add(&treeNode2);
	treeNode2.add(&leaf1);

	root.add(&treeNode3);
	treeNode3.add(&treeNode4);
	treeNode4.add(&leaf2);

	//不管处理根节点 叶节点 树节点 都一样，具有一致性。
	process(root);
	process(leaf2);
	process(treeNode3);

	return 0;
}
