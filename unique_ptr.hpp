#include <iostream>

namespace unique
{
    template <typename T>
    class UniquePtr
    {
    private:
        T *pointer;

        UniquePtr(const UniquePtr<T> &other) = delete;
        UniquePtr& operator=(const UniquePtr<T> &other) = delete;

    public:
        UniquePtr(T *pointer) : pointer(pointer)
        {
            std::cout << "UniquePtr constructor" << std::endl;
        }
        ~UniquePtr()
        {
            std::cout << "UniquePtr destructor" << std::endl;
        }

        T *get()
        {
            return pointer;
        }

        void release()
        {
            delete pointer;
        }
    };

    template <typename T, typename ...Args>
    UniquePtr<T> make_unique(Args... args)
    {
        return UniquePtr<T>(new T(args...));
    }
}
