# BÀI 13 CLASS

## 1. CLASS

- Kiểu dữ liệu tự định nghĩa.

- Phạm vi truy cập:

+ public:

+ private: tính đóng gói và tính trừu tượng

+ protected: tính kế thừa 

- **Cách khai báo CLass**: 
```cpp
#include <iostream>
using namespace std;

class TenLop {
private:
    // Các thuộc tính riêng tư
    int thuocTinh1;
    int thuocTinh2;

public:
    // Constructor
    TenLop(int thamSo1, int thamSo2) {
        thuocTinh1 = thamSo1;
        thuocTinh2 = thamSo2;
    }

    // Phương thức để thiết lập giá trị
    void setThuocTinh1(int giaTri) {
        thuocTinh1 = giaTri;
    }

    void setThuocTinh2(int giaTri) {
        thuocTinh2 = giaTri;
    }

    // Phương thức để lấy giá trị
    int getThuocTinh1() {
        return thuocTinh1;
    }

    int getThuocTinh2() {
        return thuocTinh2;
    }

    // Phương thức hiển thị thông tin
    void hienThi() {
        cout << "Thuoc tinh 1: " << thuocTinh1 << ", Thuoc tinh 2: " << thuocTinh2 << endl;
    }
};

int main() {
    // Tạo một đối tượng từ lớp TenLop
    TenLop doiTuong(10, 20);

    // Gọi phương thức của đối tượng
    doiTuong.hienThi();

    // Thay đổi giá trị thuộc tính và hiển thị lại
    doiTuong.setThuocTinh1(30);
    doiTuong.setThuocTinh2(40);
    doiTuong.hienThi();

    return 0;
}
```

### Giải thích:
1. **`class TenLop`**: Khai báo một lớp với tên là `TenLop`.
2. **Thuộc tính (`thuocTinh1`, `thuocTinh2`)**: Được khai báo trong phần `private`, nghĩa là chỉ có thể truy cập thông qua các phương thức của lớp.
3. **Phương thức (`setThuocTinh1`, `getThuocTinh1`, `hienThi`)**: Được khai báo trong phần `public`, nghĩa là có thể truy cập từ bên ngoài lớp.
4. **Constructor**: Phương thức đặc biệt có cùng tên với lớp, được gọi khi một đối tượng của lớp được tạo ra để khởi tạo giá trị ban đầu cho các thuộc tính.

## 2. Cách thức truy cập thuộc tinh và phương thức trong class:

### 2.1. **Truy cập các thuộc tính và phương thức công khai (public)**

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int myVar;  // Thuộc tính công khai

    void myMethod() {  // Phương thức công khai
        cout << "Phương thức công khai được gọi" << endl;
    }
};

int main() {
    MyClass obj;  // Tạo đối tượng của lớp MyClass
    obj.myVar = 10;  // Truy cập thuộc tính công khai
    cout << "Giá trị của myVar: " << obj.myVar << endl;

    obj.myMethod();  // Gọi phương thức công khai

    return 0;
}
```

### 2.2. **Truy cập các thuộc tính và phương thức riêng tư (private)**
Các thuộc tính và phương thức `private` không thể được truy cập trực tiếp từ bên ngoài lớp. Phải sử dụng các phương thức công khai để truy cập hoặc thay đổi giá trị.

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int myVar;  // Thuộc tính riêng tư

public:
    void setMyVar(int value) {  // Phương thức công khai để thiết lập giá trị
        myVar = value;
    }

    int getMyVar() {  // Phương thức công khai để lấy giá trị
        return myVar;
    }

    void display() {  // Phương thức công khai khác
        cout << "Giá trị của myVar: " << myVar << endl;
    }
};

int main() {
    MyClass obj;  // Tạo đối tượng của lớp MyClass
    obj.setMyVar(20);  // Thiết lập giá trị thông qua phương thức công khai
    cout << "Giá trị của myVar: " << obj.getMyVar() << endl;  // Lấy giá trị thông qua phương thức công khai

    obj.display();  // Gọi phương thức công khai khác

    return 0;
}
```

### 2.3. **Truy cập thông qua con trỏ và toán tử `->`**
Khi sử dụng con trỏ để trỏ đến một đối tượng, bạn sử dụng toán tử `->` để truy cập các thành viên của lớp.

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int myVar;

    void myMethod() {
        cout << "Phương thức được gọi thông qua con trỏ" << endl;
    }
};

int main() {
    MyClass obj;
    MyClass* ptr = &obj;  // Tạo con trỏ trỏ đến đối tượng

    ptr->myVar = 30;  // Truy cập thuộc tính qua con trỏ
    cout << "Giá trị của myVar: " << ptr->myVar << endl;

    ptr->myMethod();  // Gọi phương thức qua con trỏ

    return 0;
}
```

## 3. CONTRUCTOR

**Constructor** được khởi tạo trong `public` (hàm tạo) là một loại phương thức đặc biệt trong một lớp (class) được gọi tự động khi một đối tượng của lớp được tạo ra. Mục đích chính của constructor là khởi tạo giá trị ban đầu cho các thuộc tính của đối tượng hoặc thực hiện các thao tác thiết lập cần thiết.

### Đặc điểm của Constructor:
1. **Tên Method trùng tên Class**: Constructor có tên giống với tên lớp.
2. **Không có kiểu trả về**: Constructor không có kiểu trả về, kể cả `void`.
3. **Tự động được gọi**: Khi một đối tượng được tạo, constructor sẽ tự động được gọi mà không cần gọi trực tiếp.
4. **Có thể có tham số**: Constructor có thể nhận tham số để khởi tạo giá trị cho các thuộc tính.

### Các loại Constructor trong C++:
1. **Default Constructor (Constructor mặc định)**:
   - Không có tham số.
   - Được trình biên dịch tự động tạo nếu không có constructor nào khác được định nghĩa.

   ```cpp
   class MyClass {
   public:
       MyClass() {  // Default constructor
           cout << "Default constructor được gọi" << endl;
       }
   };
   ```

2. **Parameterized Constructor (Constructor có tham số)**:
   - Có tham số và dùng để khởi tạo các thuộc tính với các giá trị cụ thể.

   ```cpp
   class MyClass {
   private:
       int x;
   public:
       MyClass(int a) {  // Parameterized constructor
           x = a;
           cout << "Parameterized constructor được gọi với giá trị: " << x << endl;
       }
   };
   ```

3. **Copy Constructor (Constructor sao chép)**:
   - Dùng để tạo một đối tượng mới từ một đối tượng hiện có.

   ```cpp
   class MyClass {
   private:
       int x;
   public:
       MyClass(int a) : x(a) {}
       MyClass(const MyClass &obj) {  // Copy constructor
           x = obj.x;
           cout << "Copy constructor được gọi" << endl;
       }
   };
   ```

### Ví dụ cụ thể về Constructor:

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int a;
    int b;

public:
    // Constructor có tham số
    MyClass(int x, int y) {
        a = x;
        b = y;
        cout << "Constructor có tham số được gọi" << endl;
    }

    // Phương thức hiển thị giá trị
    void display() {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    // Tạo đối tượng với constructor có tham số
    MyClass obj(10, 20);
    obj.display();

    return 0;
}
```

### Kết quả:
```
Constructor có tham số được gọi
a: 10, b: 20
```

## 4. DESTRUCTOR

**Destructor** được khởi tạo trong `public` (hàm hủy) là một phương thức đặc biệt trong lập trình hướng đối tượng (OOP) trong C++. Nó được sử dụng để thực hiện các tác vụ dọn dẹp khi một đối tượng của lớp bị hủy, chẳng hạn như giải phóng bộ nhớ, đóng file, hoặc thực hiện các thao tác khác khi đối tượng không còn cần thiết nữa.(hủy các object)

### Đặc điểm của Destructor:
1. **Tên giống với tên lớp, nhưng có thêm dấu `~` ở đầu**: Destructor có tên giống với tên lớp nhưng có dấu `~` đứng trước (ví dụ, nếu tên lớp là `MyClass`, destructor sẽ có tên là `~MyClass`).
2. **Không có tham số**: Destructor không nhận tham số nào.
3. **Không có kiểu trả về**: Destructor không có kiểu trả về, kể cả `void`.
4. **Tự động được gọi**: Destructor được tự động gọi khi:
   - Đối tượng đi ra khỏi phạm vi (scope).
   - Đối tượng bị xóa bằng từ khóa `delete`.
   - Chương trình kết thúc.

### Công dụng của Destructor:
- **Giải phóng bộ nhớ hoặc tài nguyên**: Giải phóng bộ nhớ đã cấp phát động (dynamic memory) hoặc tài nguyên khác như file, kết nối mạng, v.v.
- **Dọn dẹp**: Thực hiện các thao tác cần thiết để đảm bảo rằng tất cả tài nguyên được dọn dẹp đúng cách khi đối tượng không còn cần thiết.

### Ví dụ về Destructor:

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    // Constructor
    MyClass() {
        cout << "Constructor được gọi" << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor được gọi" << endl;
    }

    // Phương thức hiển thị
    void display() {
        cout << "Phương thức display được gọi" << endl;
    }
};

int main() {
    MyClass obj;  // Tạo một đối tượng của MyClass
    obj.display();  // Gọi phương thức display

    // Khi đối tượng obj đi ra khỏi phạm vi, destructor sẽ tự động được gọi.
    return 0;
}
```

### Kết quả:
```
Constructor được gọi
Phương thức display được gọi
Destructor được gọi
```

### Ví dụ với cấp phát bộ nhớ động:

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int* ptr;

public:
    // Constructor
    MyClass(int value) {
        ptr = new int(value);  // Cấp phát bộ nhớ động
        cout << "Constructor được gọi, giá trị được cấp phát là: " << *ptr << endl;
    }

    // Destructor
    ~MyClass() {
        delete ptr;  // Giải phóng bộ nhớ
        cout << "Destructor được gọi, bộ nhớ đã được giải phóng" << endl;
    }

    // Phương thức hiển thị giá trị
    void display() {
        cout << "Giá trị: " << *ptr << endl;
    }
};

int main() {
    MyClass obj(100);  // Tạo đối tượng với giá trị khởi tạo
    obj.display();  // Hiển thị giá trị

    // Destructor sẽ tự động được gọi khi obj đi ra khỏi phạm vi
    return 0;
}
```

### Kết quả:
```
Constructor được gọi, giá trị được cấp phát là: 100
Giá trị: 100
Destructor được gọi, bộ nhớ đã được giải phóng
```

## 5. STATIC TRONG CLASS

### 5.1. Static property

**Static property** (thuộc tính tĩnh) trong C++ là một thành viên của class mà tất cả các đối tượng (instance) của class đó chia sẻ chung. Điều này có nghĩa là chỉ có **một bản sao** của thuộc tính static tồn tại trong suốt vòng đời của chương trình, bất kể có bao nhiêu đối tượng của class được tạo ra.

**Đặc điểm của Static Property:**
1. **Thuộc về class, không thuộc về instance**: Static property không phải là thành phần của bất kỳ instance cụ thể nào. Chúng tồn tại độc lập với các instance và được dùng chung giữa tất cả các instance của class.
2. **Khởi tạo một lần**: Static property được khởi tạo một lần và duy nhất trong phân vùng bộ nhớ tĩnh (data hoặc BSS segment) khi chương trình bắt đầu chạy. (cấp phát địa chỉ ban đầu dưới dang toàn cục)
3. **Truy cập thông qua class hoặc instance**: Bạn có thể truy cập static property bằng cách sử dụng tên class hoặc thông qua một instance của class.

**Cú pháp khai báo và sử dụng Static Property:**
```cpp
class MyClass {
public:
    static int staticVar;  // Khai báo static property
};

// Định nghĩa và khởi tạo static property ngoài class
int MyClass::staticVar = 0;

int main() {
    // Truy cập static property thông qua class
    MyClass::staticVar = 10;

    // Truy cập static property thông qua một instance
    MyClass obj;
    obj.staticVar = 20;

    std::cout << MyClass::staticVar << std::endl;  // Kết quả: 20
    return 0;
}
```

**Giải thích:**
1. **Khai báo static property**: `static int staticVar;` trong class.
2. **Định nghĩa và khởi tạo**: Static property phải được định nghĩa và khởi tạo bên ngoài class (ngoại trừ khi nó là một hằng số nguyên hoặc liệt kê - `const static`).
3. **Truy cập**: Có thể truy cập `staticVar` bằng cách dùng `MyClass::staticVar` hoặc `obj.staticVar`.

**Lợi ích của Static Property:**
1. **Chia sẻ dữ liệu**: Static property cho phép tất cả các instance của class chia sẻ chung một dữ liệu, hữu ích trong các trường hợp cần quản lý trạng thái dùng chung như bộ đếm, cấu hình chung, hoặc caching.
2. **Không cần tạo instance**: Có thể truy cập và sử dụng static property mà không cần phải tạo bất kỳ instance nào của class.

**Lưu ý:**
- Static property không thể được khởi tạo trực tiếp bên trong class (trừ khi là `const static`).
- Nếu cần các phép toán phức tạp cho việc khởi tạo, bạn có thể sử dụng một hàm static hoặc một khối `static` trong file định nghĩa.

**Ví dụ với `const static`:**
```cpp
class MyClass {
public:
    static const int staticConstVar = 100;  // Khởi tạo trực tiếp trong class
};
```

### 5.2. Static method

**Static method** (phương thức tĩnh) trong C++ là một hàm thành viên của class nhưng không hoạt động trên instance cụ thể nào của class. Thay vào đó, nó thuộc về class và có thể được gọi mà không cần tạo instance của class.

**Đặc điểm của Static Method:**
1. **Không cần instance**: Static method có thể được gọi trực tiếp thông qua tên class mà không cần tạo object.
2. **Không thể truy cập non-static members**: Static method không thể trực tiếp truy cập các thuộc tính hoặc phương thức không static của class, vì chúng không có ngữ cảnh (context) của một instance cụ thể.
3. **Có thể truy cập static members**: Static method có thể truy cập các thuộc tính và phương thức static khác của class.

**Cú pháp khai báo và sử dụng Static Method:**
```cpp
class MyClass {
public:
    static void staticMethod() {
        std::cout << "Static method called" << std::endl;
    }

    static int staticVar;

    static void setStaticVar(int value) {
        staticVar = value;
    }

    static int getStaticVar() {
        return staticVar;
    }
};

// Định nghĩa và khởi tạo static property
int MyClass::staticVar = 0;

int main() {
    // Gọi static method trực tiếp thông qua class
    MyClass::staticMethod();

    // Gọi static method để thay đổi static property
    MyClass::setStaticVar(10);
    std::cout << "StaticVar: " << MyClass::getStaticVar() << std::endl;

    return 0;
}
```

**Giải thích:**
1. **Khai báo static method**: `static void staticMethod();` trong class.
2. **Định nghĩa static method**: Định nghĩa giống như các phương thức thông thường, chỉ cần thêm từ khóa `static` trong khai báo.
3. **Gọi static method**: Có thể gọi `MyClass::staticMethod()` mà không cần tạo object của `MyClass`.

**Lợi ích của Static Method:**
1. **Không cần tạo instance**: Static method rất hữu ích khi bạn muốn thực hiện một thao tác không phụ thuộc vào dữ liệu cụ thể của object.
2. **Truy cập các thành phần static**: Static method có thể truy cập và thao tác với các thành phần static của class, giúp quản lý trạng thái hoặc dữ liệu dùng chung.

**Lưu ý:**
- Static method không có con trỏ `this`, vì chúng không được gọi trên một instance cụ thể.
- Có thể sử dụng static method để thực hiện các thao tác tiện ích (utility functions) hoặc quản lý trạng thái chung cho toàn bộ class.

### Ví dụ :
```cpp
class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << "Sum: " << Math::add(5, 3) << std::endl;  // Kết quả: 8
    return 0;
}
```