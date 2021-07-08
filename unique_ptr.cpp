template<class T>
class unique_ptr
{
public:
	explicit unique_ptr() :m_ptr(nullptr) {}
	unique_ptr(T* p) : m_ptr(p){}
	~unique_ptr() 
	{
		if (m_ptr != nullptr)
			delete m_ptr; 
	}
	unique_ptr(const unique_ptr& p) 
	{
		this->m_ptr = p.m_ptr;
	}
	unique_ptr(const unique_ptr&& p)
	{
		this->m_ptr = p.m_ptr;
		p.m_ptr = nullptr;
	}

	T* operator*()
	{
		return *(this->m_ptr);
	}

	void reset(T* p) 
	{
		if (*this)
			m_ptr = nullptr;
		m_ptr = p;
	}

	T* release()
	{
		T* p = m_ptr;
		m_ptr = nullptr;
		return p;
	}
private:
	T* m_ptr;
};
