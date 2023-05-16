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
    
    // Конструктор с параметрами
    VectorUShort(int n, unsigned short val) {
        data = new unsigned short[n];   
        num = n;                       
        State = 0;            
        for (int i = 0; i < n; i++) {
            data[i] = val; 
        }
    }
    
    // Деструктор
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