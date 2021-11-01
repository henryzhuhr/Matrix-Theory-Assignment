template <class T> struct SingleNode
{
    T              data;
    SingleNode<T>* next = NULL;
};

template <class T> class LinearList_Interface
{
  public:
    virtual ~LinearList_Interface(){};

  public:
    virtual void SetMaxLength(const int maxLength = -1) = 0;
    virtual int  GetMaxLength() const                   = 0;

  public:
    /**
     * @brief Travel this Iterator and print it
     *
     */
    virtual void Travel()                                     = 0;
    virtual bool Append(const T data)                         = 0;
    virtual bool Insert(const T data, const int index)        = 0;
    virtual bool GetDataByIndex(T& data, const int index = 0) = 0;
    virtual bool Remove(const int index = 0)                  = 0;
    virtual bool Clear()                                      = 0;
};

