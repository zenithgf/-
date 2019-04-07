class House {
public:
	void Init(){
		this->BuildPart1();

		for (int i = 0; i < 4; ++i)
		{
			this->BuildPart2();
		}

		bool flag=this->BuildPart3();

		if (flag)
		{
			this->BuildPart4();
		}

		this->BuildPart5();
	}

	virtual ~House(){}
protected:
	virtual void BuildPart1()=0;
	virtual void BuildPart2()=0;
	virtual void BuildPart3()=0;
	virtual void BuildPart4()=0;
	virtual void BuildPart5()=0;
};

class StoneHouse:public House
{
public:
	StoneHouse();
	~StoneHouse();
protected:
	virtual void BuildPart1(){

	}
	virtual void BuildPart2(){

	}
	virtual void BuildPart3(){

	}
	virtual void BuildPart4(){

	}
	virtual void BuildPart5(){
		
	}

};