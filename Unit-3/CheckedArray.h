using namespace std;

class CheckedArray
{
private:
    int *myArray{nullptr};
    int *mSize{nullptr};

public:
    // fill the value of the array w/ 10 0's
    CheckedArray();
    // Overloaded constructor which will initialize the array to size and fill it with 0's
    CheckedArray(int size);
    ~CheckedArray();
    bool initilize(int size, int val = 0);
    int at(int index) const;
    void set(int index, int value);
};


