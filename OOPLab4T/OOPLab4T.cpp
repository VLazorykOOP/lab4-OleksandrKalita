#include <iostream>

using namespace std;

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
  // Створюємо вектор з розміром 5
  VectorUShort v1(5);

  // Виводимо вектор
  cout << "v1: " << v1 << endl;

  // Ініціалізуємо вектор
  v1[0] = 10;
  v1[1] = 20;
  v1[2] = 30;
  v1[3] = 40;
  v1[4] = 50;

  // Виводимо вектор
  cout << "v1: " << v1 << endl;

  // Копіюємо вектор
  VectorUShort v2 = v1;

  // Виводимо вектор
  cout << "v2: " << v2 << endl;

  // Перевіряємо, чи всі елементи не є нулем
  if (!v1) {
    cout << "v1 містить нульові елементи" << endl;
  } else {
    cout << "v1 не містить нульових елементів" << endl;
  }

  // Виконуємо побітову операцію заперечення над вектором
  VectorUShort v3 = ~v1;

  // Виводимо вектор
  cout << "v3: " << v3 << endl;

  // Виконуємо операцію унарного мінуса над вектором
  VectorUShort v4 = -v1;

  // Виводимо вектор
  cout << "v4: " << v4 << endl;

  // Додаємо вектори
  VectorUShort v5 = v1 + v2;

  // Виводимо вектор
  cout << "v5: " << v5 << endl;

  // Віднімаємо вектори
  VectorUShort v6 = v1 - v2;

  // Виводимо вектор
  cout << "v6: " << v6 << endl;

  // Множимо вектор на число
  VectorUShort v7 = v1 * 3;

  // Виводимо вектор
  cout << "v7: " << v7 << endl;

  // Ділимо вектор на число
  VectorUShort v8 = v1 / 2;

  // Виводимо вектор
  cout << "v8: " << v8 << endl;

  // Збільшуємо кожен елемент вектора на 1
  ++v1;

  // Виводимо вектор
  cout << "v1: " << v1 << endl;
    // Зменшуємо кожен елемент вектора на 1
  --v1;

  // Виводимо вектор
  cout << "v1: " << v1 << endl;

  // Постфіксний інкремент
  VectorUShort v9 = v1++;

  // Виводимо вектори
  cout << "v1: " << v1 << endl;
  cout << "v9: " << v9 << endl;

  // Префіксний декремент
  VectorUShort v10 = --v1;

  // Виводимо вектори
  cout << "v1: " << v1 << endl;
  cout << "v10: " << v10 << endl;

  // Перевіряємо декілька елементів за допомогою оператора []
  cout << "v1[0]: " << v1[0] << endl;
  cout << "v1[2]: " << v1[2] << endl;

  // Використовуємо метод size для отримання розміру вектора
  cout << "Розмір вектора v1: " << v1.size() << endl;

  return 0;
}
