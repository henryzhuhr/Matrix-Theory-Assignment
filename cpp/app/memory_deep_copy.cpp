#include <iostream>
#include <string>

#ifndef BUFFER_H
#define BUFFER_H
class Buffer
{
  private:
    unsigned char* buf;
    int            capacity;
    int            length;

  public:
    explicit Buffer(int capacity)
    {
        this->capacity = capacity;
        this->length   = 0;
        this->buf      = new unsigned char[capacity]{0};
    }
    Buffer(Buffer& buffer)
    {
        this->capacity = buffer.capacity;
        this->length   = buffer.length;
        this->buf      = new unsigned char[buffer.capacity];
        std::copy(buffer.buf, buffer.buf + buffer.capacity, this->buf);
    }
    Buffer& operator=(Buffer const& buffer)
    {
        if (this != &buffer)
        {
            this->capacity = buffer.capacity;
            this->length   = buffer.length;
            delete[] this->buf;
            this->buf = new unsigned char[buffer.capacity];
            std::copy(buffer.buf, buffer.buf + buffer.capacity, this->buf);
        }
        return *this;
    }
    ~Buffer() { delete[] buf; }

  public:
    int GetLength() { return length; }
    int GetCapacity() { return capacity; }

  public:
    friend std::ostream& operator<<(std::ostream& os, Buffer& buffer);

  public:
    bool write(unsigned char value)
    {
        if (length == capacity)
            return false;
        buf[length++] = value;
        return true;
    }
};
std::ostream& operator<<(std::ostream& os, Buffer& buffer)
{
    os << "Buffer(" << buffer.length << "/" << buffer.capacity << ")[";
    for (int i = 0; i < buffer.capacity; i++)
    {
        os << (int)buffer.buf[i] << ",";
    }
    os << "]";
    return os;
}

#endif

int main(int argc, char const* argv[])
{
    auto buffer = Buffer(10);
    buffer.write(97);
    auto buffer2 = buffer;

    buffer.write(65);

    std::cout << "buffer:  " << buffer << std::endl;
    std::cout << "buffer2: " << buffer2 << std::endl;

    return 0;
}
