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
        // : capacity(capacity), length(0), buf(new unsigned char[capacity]{0})
        this->capacity = capacity;
        this->length   = 0;
        this->buf      = new unsigned char[capacity]{0};
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
    auto buffer  = Buffer(10);
    buffer.write(97);
    auto buffer2 = buffer;

    buffer.write(65);

    std::cout << buffer << std::endl;
    std::cout << buffer2 << std::endl;

    return 0;
}

/*
  Buffer(2/10)[97,65,0,0,0,0,0,0,0,0,]
  Buffer(1/10)[97,65,0,0,0,0,0,0,0,0,]
  free(): double free detected in tcache 2
  build.sh：行 12: 14171 已放弃               （核心已转储） ./buffer
*/

// error for the reason that memory has been deleted twice!