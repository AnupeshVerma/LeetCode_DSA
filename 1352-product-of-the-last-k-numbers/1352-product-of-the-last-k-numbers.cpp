class ProductOfNumbers {
private:
    vector<int>stream;
    int size;
public:
    ProductOfNumbers() {
        stream.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            stream = {1};
            size = 0;
        }
        else {
            stream.push_back(stream[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k > size)
            return 0;
        
        return stream[size] / stream[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */