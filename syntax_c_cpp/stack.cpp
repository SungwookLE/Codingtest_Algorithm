/**
 * @brief Queue practice
 * @date 2023-01-02
 */

#include <iostream>
#include <algorithm>

template <typename T>
class Monitor
{
public:
    void print(T *data, int length)
    {

        std::cout << "Data: ";
        for (int i = 0; i < length; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void address(T *data)
    {
        std::cout << "Mem: " << data << std::endl;
    }
};

template <typename T>
class Container
{
public:
    Container()
    {
        ptr = new T[1]{
            0,
        };
        index = -1;
    }

    int size()
    {
        return index + 1;
    }

    void resize(int _size)
    {
        T *new_ptr = new T[_size]{
            0,
        };
        std::copy(this->ptr, this->ptr + index + 1, new_ptr);

        delete[] this->ptr;
        this->ptr = new_ptr;
    }

    T front()
    {
        return this->ptr[0];
    }

    T back()
    {
        return this->ptr[index];
    }

    ~Container()
    {
        delete[] this->ptr;
    }

    int *get_index()
    {
        return &this->index;
    }

    T *get_ptr()
    {
        return this->ptr;
    }

private:
    T *ptr;
    int index;
};

template <typename T>
class Stack : public Container<T>, public Monitor<T>
{

public:
    Stack()
    {
    }

    void push(T _d)
    {
        *this->get_index() += 1;
        this->resize(this->size());
        this->get_ptr()[*this->get_index()] = _d;
    }

    T pop()
    {
        T res = Container<T>::get_ptr()[*Container<T>::get_index()];
        *Container<T>::get_index() -= 1;
        Container<T>::resize(Container<T>::size());

        return res;
    }

    void print()
    {
        Monitor<T>::print(this->get_ptr(), this->size());
    }

    void address()
    {
        Monitor<T>::address(this->get_ptr());
    }

private:
    T *get()
    {
        return this->get_ptr();
    }
};

int main()
{
    Stack<int> handler;

    handler.push(7);
    handler.push(8);
    handler.push(9);
    handler.push(10);
    handler.print();
    handler.address();
    std::cout << handler.front() << std::endl;
    std::cout << handler.back() << std::endl;
    std::cout << handler.pop() << std::endl;
    handler.print();
    handler.address();
}