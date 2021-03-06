class Counter
{
public:
	Counter() : m_count(0) {}
	~Counter(){}
	void operator++()
	{
		++m_count;
	}

	void operator--()
	{
		--m_count;
	}

	unsigned int GetCounter() const
	{
		return m_count;
	}
private:
	unsigned int m_count;
};

template<class T>
class Shared_ptr
{
public:
	Shared_ptr() : m_ptr(nullptr) {}
	explicit Shared_ptr(T* p)
	{
		m_ptr = p;
		m_counter = new Counter();
		if (m_ptr)
			++(*m_counter);
	}
	Shared_ptr(const Shared_ptr& p)
	{
		m_ptr = p.m_ptr;
		m_counter = p.m_counter;
		++(*m_counter);
	}
	~Shared_ptr()
	{
		--(*m_counter);
		if (m_counter->GetCounter() == 0)
		{
			delete m_counter;
			delete m_ptr;
		}

	}
	T* operator*()
	{
		return *(this->m_ptr);
	}

	void reset(T* p) noexcept
	{
		if (*this)
			m_ptr = nullptr;
		m_ptr = p;
	}

private:
	T* m_ptr;
	Counter* m_counter;
};
