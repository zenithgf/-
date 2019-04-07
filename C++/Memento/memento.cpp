//备忘录。用来保存原发器的状态
class Memento{
	string state;
	//...
public:
	Memento(const string & s):state(s){}	
	string getState() const {return state;}
	void setState(const string & s){state = s;}
};
//需要保存状态的对象
class Originator
{
	string state;
	//...
public:
	Originator(){}

	~Originator();
	//创建备忘录
	Memento createMomento(){
		Memento m(state);//相当于实现深拷贝(原发对象比较简单没有一层层嵌套的指针和对象)和序列化对象(原发对象比较复杂包含很多指针和对象)
		return m;
	}
	void setMomento(const Memento & m){
		state = m.getState();
	}
};
//相当于Caretaker
int main(int argc, char const *argv[])
{
	Originator originator;

	//存储到备忘录
	Memento men = originator.createMomento();
	//....改变orginator状态

	//从备忘录中恢复
	originator.setMomento(memento);

	return 0;
}