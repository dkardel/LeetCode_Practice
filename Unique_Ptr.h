#include<exception>
namespace dsa
{
	template<class T>
	class unique_ptr
	{
	private:
		T* ptr = nullptr;
		void __cleanup__()
		{
			if (ptr != nullptr)
				delete ptr;
		}
	public:
		unique_ptr():ptr(nullptr){}
		unique_ptr(T* ptr):ptr(ptr){}

		unique_ptr(const unique_ptr& obj) = delete;
		unique_ptr& operator=(const unique_ptr& obj) = delete;

		unique_ptr(unique_ptr&& dyingObj)
		{
			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}
		void operator=(unique_ptr&& dyingObj)
		{
			__cleanup__();
			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}
		T* operator->()
		{
			return this->ptr;
		}
		T& operator*()
		{
			return *ptr;
		}

		T* get()const { return ptr; }
		T* release()
		{
			T* temp = ptr;
			ptr = 0;
			return temp;
		}

		void reset(T* newP)
		{
			delete ptr;
			ptr = newP;
		}
		void reset()
		{
			delete ptr;
			ptr = 0;
		}
		~unique_ptr()
		{
			__cleanup__();
		}
			
	};

	template<class T>
	class unique_ptr <T[]>
	{
	private:
		T* ptr = nullptr;
		void __cleanup__()
		{
			if (ptr != nullptr)
				delete[] ptr;
		}
	public:
		unique_ptr() :ptr(nullptr) {}
		unique_ptr(T* ptr) :ptr(ptr) {}

		unique_ptr(const unique_ptr& obj) = delete;
		unique_ptr& operator=(const unique_ptr& obj) = delete;

		unique_ptr(unique_ptr&& dyingObj)
		{
			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}
		void operator=(unique_ptr&& dyingObj)
		{
			__cleanup__();
			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}
		T* operator ->()
		{
			return this->ptr;
		}
		T& operator* ()
		{
			return *(this->ptr);
		}
		T& operator[](int index)
		{
			if (index < 0)
			{
				throw(new std::exception("Negative index exception"));
			}
			return this->prt[index];
		}
		~unique_ptr()
		{
			__cleanup__();
		}
	};
}
