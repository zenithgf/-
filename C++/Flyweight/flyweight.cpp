class Font{
private:
	//unique object key
	string key;	

	//object state	
	//....
public:
	Font(const string& key){
		//...
	}
};

//一个对象大小的测算 使用size of ;(1.各种数据类型大小	2.考虑字节对齐3.虚函数表指针大小 32位4byte 64位8byte)

class  FontFactory
{
private:
	map<string, Font*> fontPool;//定义一个对象池
public:
	FontFactory();
	~ FontFactory();
	//返回出去的共享对象一定是只读的，不可以被修改的。
	Font* GetFont(const string& key){
		map<string, Font*>::iterator item=fontPool.find(key);//用迭代器查找字体对象

		if (item!=footPool.end())
		{	//到尾部之前找到字体对象
			return fontPool[key];
		}else{//到尾部没找到字体对象，创建字体
			Font* font = new Font(key);
			fontPool[key]=font;
			return font;
		}
	}
	void clear(){

	}
	
};
