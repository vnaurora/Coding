


class PerThreadSingleton
{
public:
    ~PerThreadSingleton() {};
    static PerThreadSingleton* GetInstance()
    {
        if (!mInstance)
        {
            mInstance = new PerThreadSingleton();
        }
        return mInstance;
    }
    
    void Increase()
    {
        mValue++;
    }

    int GetValue()
    {
        return mValue;
    }
private:
    PerThreadSingleton()
    {
        mValue = 0;
    }
    int mValue;

    static __declspec(thread) PerThreadSingleton* mInstance;
};

PerThreadSingleton* PerThreadSingleton::mInstance = nullptr;