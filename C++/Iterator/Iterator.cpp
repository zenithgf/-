//迭代器基类
//使用模版函数，模版函数是编译型多态，虚函数是运行时多态(因为有函数指针表) 模版函数优于虚函数，因为虚函数有查找指针表的开销。

template<typename T>
class Iterator
{
public:
	virtual void first()=0;//获取第一个元素
	virtual void next()=0;//获取下一个元素 只支持前向不支持反向迭代
	virtual bool isDone() const = 0;//遍历到头
	virtual T& current() = 0;//获取当前元素
}；
//集合类 相当于Aggregate
template<typename T>
class MyCollection
{
public:
	MyCollection();
	~MyCollection();
	//相当于CreateIterator()
	Iterator<T> GetIterator(){
		//...创建并返回一个迭代器
	}	
};
//具体集合类的迭代器
template<typename T>
class  CollectionIterator:public Iterator<T>
{
	MyCollection<T> mc;
public:
	 CollectionIterator(const MyCollection<T> & c):mc(c){}
	~ CollectionIterator();

	void first() override{

	}	
	void next() override{

	}
	bool isDone() const override{

	}
	T& current() override{

	}
};

void MyAlgorithm(){
	MyCollection<int> mc;

	Iterator<int> iter= mc.GetIterator();

	for (iter.first(); !iter.isDone(); iter.next())
	{
		cout << iter.current() << endl;
	}
}