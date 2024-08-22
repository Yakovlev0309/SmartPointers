
namespace shared
{
    template <typename T>
    class SharedPtr
    {
    private:
        T *pointer;

    public:
        SharedPtr(T *pointer) : pointer(pointer) {}

        int use_count() const
        {
            // ...
            return 0;
        }
    };

    template <typename T>
    SharedPtr<T> make_shared()
    {
        return SharedPtr(new T);
    }
}
