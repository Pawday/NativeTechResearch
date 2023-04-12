#include <iostream>


class BasicObject
{
    static uint32_t id;
    uint32_t _objID;


    void InitObject()
    {
        this->_objID = id;
        id++;
    }

public:

    BasicObject()
    {
        InitObject();
        std::cout << "BasicObject with id #" << _objID << " created" << '\n';
    }

    BasicObject(const BasicObject &other)
    {
        InitObject();
        std::cout << "BasicObject with id #" << _objID << " copied from BasicObject with id #" << other._objID << '\n';
    }

    ~BasicObject()
    {
        std::cout << "BasicObject with id #" << _objID << " destroyed" << '\n';
    }

};

uint32_t BasicObject::id = 0;

BasicObject basicObj()
{
    std::cout << "basicObj() call begin" << std::endl;
    return BasicObject{};
}

int main()
{
    std::cout << "Entry" << std::endl;
    BasicObject basicObjInstance;


    {
        std::cout << "Start scope 1" << std::endl;
        BasicObject object = basicObjInstance;
        std::cout << "End scope 1" << std::endl;
    }

    {
        std::cout << "Start scope 2" << std::endl;
        auto formFunction = basicObj();
        std::cout << "End scope 2" << std::endl;
    }

    std::cout << "Exit" << std::endl;
    return 0;
}

