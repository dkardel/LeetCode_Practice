#pragma once
namespace dsa
{
	template <typename T>
	class shared_ptr;

	template <typename T>
	class T_Ptr
	{
	private:
		friend class shared_ptr<T>;
		T* ptr;
		unsigned int ref_count;
		T_Ptr(T* _ptr):ptr(_ptr), ref_count(1){}

		~T_Ptr()
		{
			std::cout << "{Destructor : Decrementing ref count, cur value : " << ref_count << std::endl;
			--ref_count;
			if (ref_count <= 0)
			{
				std::cout << "Destructoring : Deleteing underlying Object." << std::endl;
				if (ptr)
					delete ptr;
				ref_count = 0;
			}
		}
	};

	template <typename T>
	class shared_ptr
	{
	private:
		T_Ptr<T>* p_T_ptr;
	public:
		shared_ptr<T>(T* _ptr):p_T_ptr(new T_Ptr<T>(_ptr)){}
		T* get() { return p_T_ptr->ptr; }
		int use_count() const { return p_T_ptr->ref_count; }
		void swap(const shared_ptr<T>& other)
		{
			T_Ptr<T>* tmp = this->p_T_ptr;
			this->p_T_ptr = other.p_T_ptr;
			other.p_T_ptr = tmp;
		}
		shared_ptr<T>(const shared_ptr<T>& other)
		{
			p_T_ptr = other.p_T_ptr;
			p_T_ptr->ref_count += 1;
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& other)
		{
			if(p_T_ptr)
				delete p_T_ptr;
			p_T_ptr = other.p_T_ptr;
			p_T_ptr->ref_count += 1;
			return *this;
		}
		T operator*()
		{
			return *(p_T_ptr->ptr);
		}
		~shared_ptr<T>()
		{
			if (p_T_ptr)
				delete p_T_ptr;
		}
	};

	template <typename T>
	shared_ptr<T> make_shared(T&& ref)
	{
		static shared_ptr<T> sp(new T(ref));
		return sp;
	}
	template <typename T>
	shared_ptr<T> make_shared(T& ref)
	{
		static shared_ptr<T> sp(&ref);
		return sp;
	}

	template <typename T>
	shared_ptr<T> make_shared(std::initializer_list<T> lst)
	{
		static shared_ptr<T> sp(new T(lst));
		return sp;
	}
}
