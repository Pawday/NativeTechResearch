#include <cstdint>
#include <iostream>


template<typename Type>
class RefCounter
{
    Type *ptr;
    uint32_t refCnt = 0;

public:

    RefCounter(Type *val)
    {
        this->ptr = val;
    }

    RefCounter()
    {
        this->ptr = new Type;
    }

    void IncRef()
    {
        this->refCnt++;
    }

    void DecRef()
    {
        this->refCnt--;
        if (this->refCnt == 0) delete this->ptr;
    }

    uint32_t GetRefCount()
    {
        return this->refCnt;
    }

    Type *GetPtr() const
    {
        return this->ptr;
    }
};

template<typename Type>
class SharedPtr
{
    RefCounter<Type> *refCounter;
    
    void FreeCounterIfNoRefs()
    {
        if (this->refCounter->GetRefCount() == 0)
            delete this->refCounter;
    }
    
public:

    SharedPtr(Type *val)
    {
        this->refCounter = new RefCounter<Type>(val);
        this->refCounter->IncRef();
    }

    SharedPtr()
    {
        this->refCounter = new RefCounter<Type>();
        this->refCounter->IncRef();
    }
    
    SharedPtr(SharedPtr<Type> &other)
    {
        this->refCounter = other.refCounter;
        this->refCounter->IncRef();
    }

    SharedPtr &operator=(SharedPtr const &other)
    {
        if (&this->refCounter == &other.refCounter) return *this;

        this->refCounter->DecRef();
        this->FreeCounterIfNoRefs();

        this->refCounter = other.refCounter;
        this->refCounter->IncRef();

        return *this;
    }

    Type& operator*()
    {
        return this->refCounter->GetPtr()[0];
    };

    Type* operator->()
    {
        return this->refCounter->GetPtr();
    };

    ~SharedPtr()
    {
        this->refCounter->DecRef();
        this->FreeCounterIfNoRefs();
    }


    RefCounter<Type> *GetRefCounter()
    {
        return this->refCounter;
    }

};


struct LifeTimeLogger
{
	static uint32_t counter;
	uint32_t id;
	LifeTimeLogger()
	{
		counter++;
		this->id = counter;
		std::cout << "Created #" << counter << '\n';
	}

	
	~LifeTimeLogger()
	{
		std::cout << "Destroed #" << counter << '\n';
	}
};

uint32_t LifeTimeLogger::counter = 0;

int main()
{
    std::cout << "Entry" << std::endl;
    SharedPtr<LifeTimeLogger> loggerPFirst;

    std::cout << "loggerPFirst refs: " << loggerPFirst.GetRefCounter()->GetRefCount() << std::endl;

    {
        std::cout << "Scope start" << std::endl;
        auto newP = loggerPFirst;

        std::cout << "loggerPFirst refs: " << loggerPFirst.GetRefCounter()->GetRefCount() << std::endl;
        std::cout << "newP refs: " << newP.GetRefCounter()->GetRefCount() << std::endl;
        std::cout << "Scope end" << std::endl;
    }

    std::cout << "loggerPFirst refs: " << loggerPFirst.GetRefCounter()->GetRefCount() << std::endl;

    std::cout << "End" << std::endl;
    return 0;

}