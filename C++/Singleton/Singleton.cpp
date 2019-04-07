class Singleton{
private:
	Singleton();//构造函数
	Singleton(const Singleton& other);//拷贝构造函数
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance=nullptr;

//线程非安全版本(单线程下可以用)
Singleton* Singleton::getInstance(){
	if(m_instance==nullptr){
		m_instance = new Singleton();//多线程情况下此行会被执行多次以创建多个对象。
	}
	return m_instance;
}

//线程安全版本,（多线程下使用）（如果是读操作不需要加锁,写操作和创建才需要加锁，）所以锁的代价过高,在高并发场景下不适用
Singleton* Singleton::getInstance(){
	Lock lock;
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}
	return m_instance;//锁到此出会被析构函数自动释放
}

//双检查锁,但由于内存读写reorder不安全
Singleton* Singleton::getInstance(){
	if (m_instance==nullptr)
	{
		Lock lock;
		if (m_instance==nullptr)//此处检查是否为空防止两个线程抢进来
		{
			m_instance = new Singleton();//指令层面上正常步骤:1.给m_instance分配内存空间2.执行构造器生成对象3.把指针赋给m_instance内存地址
			//当做编译器优化时,可能产生内存recoder错误：1.m_instance分配内存空间2.把指针赋给m_instance3.执行构造器生成对象
			//这样导致其中一个线程误以为m_instance不为空，误以为已经生成对象。直接返回。产生recorder错误。
		}
	}
	return m_instance;
}

//c++ 11版本之后的跨平台实现(volatile)（把变量m_instance声明为volatile，使编译器不对它进行优化，不做recorder操作）
std::atomic<Singleton*> Singleton::m_instance;//声明一个原子对象
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance(){
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);//从m_instance上获取一个内存变量
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence（内存屏障）阻止对这个内存变量进行编译器优化
	if(tmp == nullptr){
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std:memory_order_relaxed);//获取内存变量
		if (tmp == nullptr)
		{
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);//释放内存fence
			m_instance.store(tmp,std::memory_order_relaxed);//把值存回内存变量
		}
	}
	return tmp;
}







