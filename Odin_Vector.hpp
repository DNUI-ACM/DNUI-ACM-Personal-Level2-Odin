#include<stdio.h>
#define yuliu 4
#ifndef Odin_VECTOR
#define Odin_VECTOR
 template<typename Object>
 class Vector
 {
	class Reverse_Iterator//逆迭代器
    {
    private:
        Object* A;//逆迭代器指针
    public:
        Reverse_Iterator(Object* W = (void*)0) : A(W) {}
        bool operator !=(const Reverse_Iterator & L) const//逆迭代器重载 ！=
        {
            return A != L.A;
        }
        bool operator ==(const Reverse_Iterator & L) const//逆迭代器重载 ==
        {
            return A == L.A;
        }
        Object operator *()//逆迭代器重载 *
        {
            return *A;
        }
        Reverse_Iterator operator ++()//逆迭代器重载 前置++
        {
            return --A;
        }
        Reverse_Iterator operator ++(int)//逆迭代器重载 后置++
        {
            Object* tmp = A;
            --A;
            return tmp;
        }
        Reverse_Iterator operator --()//逆迭代器重载 前置--
        {
            return ++A;
        }
        Reverse_Iterator operator --(int)//逆迭代器重载 后置--
        {
            Object* K = A;
            ++A;
            return K;
        }
        Reverse_Iterator operator +=(int L)//逆迭代器重载 +=
        {
            return A -= L;
        }
        Reverse_Iterator operator -=(int L)//逆迭代器重载 -=
        {
            return A += L;
        }
        Reverse_Iterator operator +(int L)//逆迭代器重载 +
        {
            return A - L;
        }
        Reverse_Iterator operator -(int L)//逆迭代器重载 -
        {
            return A + L;
        }
    };
	
	
	private:
        int theSize;//数量 
        int theCapacity;//空间 
        Object* Objects; //指针 	
	public:
		vector()//默认构造
		{
			theSize  = 0;
			theCapacity = yuliu;
			Objects = new Object[theCapacity];
		}
	
	    explicit Vector(int a) //构造函数
	    
	    {
			theSize = a;
			theCapacity = a + yuliu;
		    Objects = new Object[theCapacity];
	    }

		vector(int Y, Object Q)//构造长度初始为 Y 初始化为 Q 的函数
		{
			theSize = Y;
			theCapacity = Y + yuliu;
			Objects = new Object[theCapacity];
			for(int i = 0; i < Y; i++)
				Objects[i] = Q;
		}
	
	    Vector(const Vector& V)//拷贝构造
	    :theSize(0)
	    ,theCapacity(0)
	    ,Objects((void*)0)
	    {
	    	*this = V;
	    }
		

	    ~Vector() //析构 
	    {
	    	delete[ ] Objects;
	    }
	
	    Vector &operator =(const Vector& Q)//重载 =
	    {
		    if(*this != Q)
		    {
		    	delete [] Objects;
		    	theSize = Q.theSize;
		    	theCapacity = Q.theCapacity;
		    	Objects = new Object[theCapacity];
		    	for(int i = 0; i < Q.theSize; i++)
		    	 Objects[i]	= Q.Objects[i];
		     } 
		     return *this;
	    }

		bool operator !=(const Vector& Q)//重载 !=
	    {
			if(theSize != Q.theSize)
				return 1;
			if(theCapacity != Q.theCapacity)
				return 1;
		    for(int i = 0; i < Q.theSize; i++)
			    if( Objects[i]	!= Q.Objects[i])
				   return 1;
			return 0;
	    }

		bool operator ==(const Vector& Q)//重载 ==
		{
			return !(*this != 	Q);
		}
	
	    Object & operator [](int W)//重载【】（非常量） 
        {
             return Objects[W];      
        }
    
        const Object & operator [](int W) const //重载【】（常量）
        {
            return Objects[W];
        }
	  
	    void resize(int newSize)//改变数量大小 
	    {
		    if(newSize <= theSize)
		    return;
		    else
		    {
	    		reserve(2 * newSize + 1);
	    		theSize = newSize;
		    } 
		}
	 	void resize(int Z, Object E)//改变数量大小并且全初始化为 E
		{
			if(Z <= theSize)
			{
				theSize = Z;
				reserve(2 * Z);
				return;
			}
			reserve(2 * Z);
			for(int i = theSize; i < Z; i++)
				Objects[i] = E;
			theSize = Z;
		}
	
	    void reserve(int newCapacity)//改变空间大小
	    {
	    	if(newCapacity <= theCapacity)
	    	return;
	    	else
	    	{
	    		Object* qwe = Objects;
	    		Objects =new Object[newCapacity];
	    		for(int i = 0; i < theSize; i++)
	    		Objects[i] = qwe[i];
	    		delete[] qwe;	
	    	 } 
	    }

	    bool empty () const//是否为空 
        {
            return size() == 0;
        }
    
        int size () const//长度判断大小 
        {
        	return theSize;
	    }
	
	    int Capacity () const//空间判断大小 
        {
        	return theCapacity;
	    }
		
	
	    void push_back (Object 	E)//末尾添加数据
	    {
	     	if(theCapacity == theSize)
	    	reserve(2 * theCapacity + yuliu);
	    	Objects[theSize++] = E;
	    } 

		void push_back(const Object* A)//末尾添加指针所指向的数据
		{
	     	if(theCapacity == theSize)
	    	reserve(2 * theCapacity + yuliu);
	    	Objects[theSize++] = *A;
	    }
	
	    void pop_back()//删除末尾数据
	    {
	    	if(theSize == 0)
			{
				printf("访问越界\n");
				return;
			}
	    	theSize--; 
	    }

	    Object& front()//访问vector第一个元素
		{
			return *begin();
		}

		Object& back()//访问vector最后一个元素
		{
			Object* M = end();
			return *(--M);
		}
		Object& at(int I)//访问vector第 I 个元素
		{
			if(I < 0 || I > theSize)
			{
				printf("访问越界\n");
				return;
			}
			return Objects[I];
		}

		const Object& back() const//读取vector最后一个元素
		{
			return *(--end());
		}

		Object* erase(int S)//删除第 S 位元素
		{
			if(theSize == 0)
			{
				printf("访问越界\n");
				return;
			}
			theSize--;
			for(int i = S; i < theSize; i++)
				Objects[i] = Objects[i+1];
			return begin()+S;
		}

		Object* erase(Object* M)//删除指针所指向的元素
		{
			if(theSize == 0)
			{
				printf("访问越界\n");
				return;
			}
			theSize--;
			for(Object* i = M; i != end(); i++)
				*i = *(i + 1);
			return M;
		}

		vector(Object* A, Object* B)//从vector A中删除所有vector B中的元素
		{
			theSize = 0;
			theCapacity = 4;
			Objects = new Object[theCapacity];
			while(A != B)
			{
				push_back(A);
				A++;
			}
		}

		Object* begin()//访问vector的首地址
		{
			return Objects;
		}

		Object* begin() const//读取vector的首地址
		{
			return Objects;
		}

		// Object* cbegin() const noexcept//求vector的首地址并查看是否存在
		// {
		// 	return Objects;
		// }

	    Object* end()//访问vector的尾地址
		{
			return Objects + theSize;
		}

		Object* end() const//读取vector的尾地址
		{
			return Objects + theSize;
		}

		// Object* cend() const noexcept//求vector的尾地址并查看是否存在
		// {
		// 	return Objects + theSize;
		// }
	
		Reverse_Iterator rbegin()//用逆迭代器访问vector的首地址
		{
			return Objects + theSize - 1;
		}

		const Reverse_Iterator rbegin() const//用逆迭代器读取vector的首地址
		{
			return Objects + theSize - 1;
		}

		// const Reverse_Iterator crbegin() const noexcept//用逆迭代器求vector的首地址并查看是否存在
		// {
		// 	return Objects + theSize - 1;
		// }

		Reverse_Iterator rend()//用逆迭代器访问vector的尾地址
		{
			return Objects - 1;
		}

		const Reverse_Iterator rend() const//用逆迭代器读取vector的尾地址
		{
			return Objects - 1;
		}

		// const Reverse_Iterator crend() const noexcept//用逆迭代器求vector的尾地址并查看是否存在
		// {
		// 	return Objects - 1;
		// }

		Object* data()//访问当前元素所存数据
		{
			return Objects;
		}

		void swap(Vector & S)//与另一项交换内容
		{
			Object* A = Objects;
			Objects = S.Objects;
			S.Objects = A;
			int B = theSize;
			theSize=S.theSize;
			S.theSize=B;
			int C=theCapacity;
			theCapacity=S.theCapacity;
			S.theCapacity=C;
		}

		void clear()//清空vector
		{
			while(theSize)
			{
				pop_back();
			}
		}

	 	void assign(int S,const Object& QWE )//拷贝vector
		{
			if(theSize < S)
			{
				int i = 0;
				for(; i < theSize; i++)
					Objects[i] = QWE;
				for(; i < S; i++)
					push_back(QWE);
			}
			else
			{
				theSize = S;
				for(int i = 0; i < theSize; i++)
					Objects[i] = QWE;
			}
		}

		void shrink_to_fit()//释放未使用内存
		{
			theCapacity = theSize + 1;
			Object* D = Objects;
			Object* V = new Object[theCapacity];
			for(int i = 0; i < theSize; i++)
				V[i] = Objects[i];
			Objects = V;
			delete[] D;
		}

		Object* insert(Object* I,const Object& N)//向 I 所指向的位置添加元素 N
		{
			theSize++;
			if( theSize > theCapacity)
			{
				theCapacity = (theCapacity * 2 + yuliu);
				Object* A = Objects;
				Object* B = new Object[theCapacity];
				for(int i = 0;i < theSize; i++)
					B[i] = Objects[i];
				Objects = B;
				delete[] A;
			}
			
			for(Object* i = end() - 1; i != I; i--)
				*i = *(i - 1);
			*I = N;
			return I;
		}
    
};
#endif