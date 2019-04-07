enum NetworkState
{
	Network_Open,
	Network_Close,
	Network_Connect,
	//如果此次添加一个新状态，则下面操作行为要添加if else判断。违法开闭原则。	
};

class NetworkProcessor{
	NetworkState state;
public:
	//对象的行为根据状态的不同发生变化
	void Operation1(){
		if(state==Network_Open){
			//********
			state = Network_Close;
		}
		else if (state == Network_Close)
		{
			//.........
			state = Network_Connect;
		}
		else if (state == Network_Connect)
		{
			//$$$$$$$$$$
			state = Network_Open;
		}
	}

	public void Operation2(){
		if (state == Network_Open)
		{
			//********
			state = Network_Connect;
		}
		else if (state == Network_Close)
		{
			//......
			state = Network_Open;
		}
		else if (state == Network_Connect)
		{
			//$$$$$$$$$$
			state = Network_Close;
		}
	}
	public void Operation3(){

	}
}