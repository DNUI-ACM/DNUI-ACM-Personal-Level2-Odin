#include<cstdio>
#include<cstdlib>
#ifndef Odin_VECTOR
#define Odin_VECTOR
 template<typename Object>
 class Vector
 {
	class Reverse_Iterator
    {
    private:
        Object* A;
    public:
        Reverse_Iterator(Object* W = (void*)0) : A(W) {}
        bool operator !=(const Reverse_Iterator & L) const
        {
            return A != L.A;
        }
        bool operator ==(const Reverse_Iterator & L) const
        {
            return A == L.A;
        }
        Object operator *()
        {
            return *A;
        }
        Reverse_Iterator operator ++()
        {
            return --A;
        }
        Reverse_Iterator operator ++(int)
        {
            Object* tmp = A;
            --A;
            return tmp;
        }
        Reverse_Iterator operator --()
        {
            return ++A;
        }
        Reverse_Iterator operator --(int)
        {
            Object* K = A;
            ++A;
            return K;
        }
        Reverse_Iterator operator +=(int L)
        {
            return A -= L;
        }
        Reverse_Iterator operator -=(int L)
        {
            return A += L;
        }
        Reverse_Iterator operator +(int L)
        {
            return A - L;
        }
        Reverse_Iterator operator -(int L)
        {
            return A + L;
        }
    };
	
	
		private:
        int theSize;
        int theCapacity;
        Object* Objects; 
		public:
		Vector()
		:theSize(0)
		,theCapacity(8)
		{
			Objects = new Object[theCapacity];
		}
	
	    explicit Vector(int a) 
	    :theSize(a)
		,theCapacity(2 * a)
	    {
		    Objects = new Object[theCapacity];
	    }

		Vector(int Y, Object Q)
		:theSize(Y)
		,theCapacity(2 * Y)
		{
			Objects = new Object[theCapacity];
			for(int i = 0; i < Y; i++)
				Objects[i] = Q;
		}
	
	    Vector(const Vector& V)
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
	
	    Vector &operator =(const Vector& Q)
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

		bool operator !=(const Vector& Q)
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

		bool operator ==(const Vector& Q)
		{
			return !(*this != 	Q);
		}
	
	    Object & operator [](int W)
        {
             return Objects[W];      
        }
    
        const Object & operator [](int W) const
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
	 	void resize(int Z, Object E)
		{
			if(Z <= theSize)
			{
				theSize = Z;
				reserve(2 * Z);
			}
			else
			{
				reserve(2 * Z);
				for(int i = theSize; i < Z; i++)
					Objects[i] = E;
				theSize = Z;
			}
		}
	
	    void reserve(int newCapacity)
	    {
	    	if(newCapacity > theCapacity)	    	
	    	{
	    		Object* qwe = Objects;
	    		Objects =new Object[newCapacity];
	    		for(int i = 0; i < theSize; i++)
	    		Objects[i] = qwe[i];
	    		delete[] qwe;	
	    	 } 
	    }

	    bool empty () const
        {
            return theSize == 0;
        }
    
        int size () const
        {
        	return theSize;
	    }
	
	    int Capacity () const
        {
        	return theCapacity;
	    }
		
	
	    void push_back (Object 	E)
	    {
	     	if(theCapacity == theSize)
	    	reserve(2 * theCapacity);
	    	Objects[theSize++] = E;
	    } 

		void push_back(const Object* A)
		{
	     	if(theCapacity == theSize)
	    	reserve(2 * theCapacity);
	    	Objects[theSize++] = *A;
	    }
	
	    void pop_back()
	    {
	    	if(theSize == 0)
			  exit(1);
	    	theSize--; 
	    }

	    Object& front()
		{
			return *begin();
		}

		Object& back()
		{
			Object* M = end();
			return *(--M);
		}
		Object& at(int I)
		{
			if(I < 0 || I > theSize)
			  exit(1);
			return Objects[I];
		}

		const Object& back() const
		{
			return *(--end());
		}

		Object* erase(int S)
		{
			if(theSize == 0)
			  exit(1);
			theSize--;
			for(int i = S; i < theSize; i++)
				Objects[i] = Objects[i+1];
			return begin()+S;
		}

		Object* erase(Object* M)
		{
			if(theSize == 0)
			  exit(1);
			theSize--;
			for(Object* i = M; i != end(); i++)
				*i = *(i + 1);
			return M;
		}

		

		Object* begin()
		{
			return Objects;
		}

		Object* begin() const
		{
			return Objects;
		}

		// Object* cbegin() const noexcept
		// {
		// 	return Objects;
		// }

	    Object* end()
		{
			return Objects + theSize;
		}

		Object* end() const
		{
			return Objects + theSize;
		}

		// Object* cend() const noexcept
		// {
		// 	return Objects + theSize;
		// }
	
		Reverse_Iterator rbegin()
		{
			return Objects + theSize - 1;
		}

		const Reverse_Iterator rbegin() const
		{
			return Objects + theSize - 1;
		}

		// const Reverse_Iterator crbegin() const noexcept
		// {
		// 	return Objects + theSize - 1;
		// }

		Reverse_Iterator rend()
		{
			return Objects - 1;
		}

		const Reverse_Iterator rend() const
		{
			return Objects - 1;
		}

		// const Reverse_Iterator crend() const noexcept
		// {
		// 	return Objects - 1;
		// }

		Object* data()
		{
			return Objects;
		}

		void swap(Vector & S)
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

		void clear()
		{
			theSize = 0;
		}

	 	void assign(int S,const Object& QWE )
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

		void shrink_to_fit()
		{
			theCapacity = theSize + 1;
			Object* D = Objects;
			Object* V = new Object[theCapacity];
			for(int i = 0; i < theSize; i++)
				V[i] = Objects[i];
			Objects = V;
			delete[] D;
		}

		Object* insert(Object* I,const Object& N)
		{
			theSize++;
			if( theSize > theCapacity)
			{
				theCapacity = (theCapacity * 2);
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