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
    

    VectorUShort& operator++() {
        for (int i = 0; i < num; i++) {
            ++data[i];
        }
        return *this;
    }
    
    VectorUShort operator++(int) {
        VectorUShort temp(*this);
        operator++();
        return temp;
    }

    VectorUShort& operator--() {
        for (int i = 0; i < num; i++) {
            --data[i];
        }
        return *this;
    }
    
    VectorUShort operator--(int) {
        VectorUShort temp(*this);
        operator--();
        return temp;
    }

    bool operator!() const {
        return (num == 0);
    }

    VectorUShort operator~() const {
        VectorUShort result(*this);
        for (int i = 0; i < num; i++) {
            result.data[i] = ~data[i];
        }
        return result;
    }

    VectorUShort operator-() {
        VectorUShort result(*this);
        for (int i = 0; i < num; i++) {
            result.data[i] = -result.data[i];
        }
        return result;
    }

    VectorUShort& operator=(const VectorUShort& v) {
        if (this == &v) {
            return *this;
        }

        delete[] data;
        num = v.num;
        data = new unsigned short[num];
        for (int i = 0; i < num; i++) {
            data[i] = v.data[i];
        }
        State = v.State;

        return *this;
    }

    VectorUShort& operator+=(const VectorUShort& other) {
        if (num == other.num) {
            for (int i = 0; i < num; i++) {
                values[i] += other.values[i];
            }
        }
        return *this;
    }

    VectorUShort& operator-=(const VectorUShort& other) {
        if (num == other.num) {
            for (int i = 0; i < num; i++) {
                values[i] -= other.values[i];
            }
        }
        return *this;
    }

    VectorUShort& operator*=(const unsigned short& scalar) {
        for (int i = 0; i < num; i++) {
            values[i] *= scalar;
        }
        return *this;
    }

    VectorUShort& operator/=(const unsigned short& scalar) {
        if (scalar != 0) {
            for (int i = 0; i < num; i++) {
                values[i] /= scalar;
            }
        }
        return *this;
    }
    
};

int main() {

    return 0;
}