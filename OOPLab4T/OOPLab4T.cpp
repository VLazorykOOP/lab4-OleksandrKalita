class VectorUShort {
private:
    unsigned short* data;
    int num;     
    int State;     
    
public:
    VectorUShort() {
        data = nullptr;    
        num = 0;         
        State = 0;        
    }
    
    VectorUShort(int n) {
        data = new unsigned short[n];
        num = 0;         
        State = 0; 
        for (int i = 0; i < n; i++) {
            data[i] = 0; 
        } 
    }
    VectorUShort(int n, int e) {
        data = new unsigned short[n]; 
        num = 0;         
        State = 0;            
        for (int i = 0; i < n; i++) {
            data[i] = e; 
        }
    }
    
     VectorUShort(const VectorUShort& other) {
        num = other.num;     
        State = other.State;
        
        data = new unsigned short[num];
        
        for (int i = 0; i < num; i++) {
            data[i] = other.data[i];
        }
    }
    
    ~VectorUShort() {
        delete[] data;
    }
    

    int size() const {
        return num;
    }
    

    unsigned short& operator[](int index) {
        return data[index];
    }
    
    const unsigned short& operator[](int index) const {
        return data[index];
    }
    
    void setState(int s) {
        State = s;
    }
    
    int getState() const {
        return State;
    }
};

int main() {

    return 0;
}