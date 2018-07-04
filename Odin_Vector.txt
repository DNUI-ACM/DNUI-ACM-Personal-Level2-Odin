#include<stdio.h>
#define yuliu 3
#ifndef Odin_VECTOR
#define Odin_VECTOR
 template<typename Object>
 class Vector
 {
	private:
        int theSize;//数量 
        int theCapacity;//空间 
        Object* Objects; //指针 	
	public:
	
	    explicit Vector(int a = 0) //构造 
	    :theSize(a)
	    ,theCapacity(a+yuliu)
	    {
		    Objects = new Object[theCapacity];
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
	
	    Vector &operator = (const Vector& Q)//重载 =
	    {
		    if(this != Q)
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
	
	    Object& operator[] (int W)//重载【】（非常量） 
        {
             return Objects[W];      
        }
    
        const Object& operator[] (int W) const //重载【】（常量）
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

	    bool isEmpty () const//是否为空 
        {
            return size() == 0;
        }
    
        int size () const//vector判断大小 
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
	    	reserve(2 * theCapacity + 1);
	    	Objects[theSize++] = E;
	    } 
	
	    void pop_back()//删除末尾数据
	    {
	    	if(theSize > 0)
	    	theSize--; 
	    }
	
	    void swap(Vector & R, Vector & A)
	    {
		    Vector B;
		    B = R;
	    	R = A;
	    	A = B;
	    }
    
};
#endif