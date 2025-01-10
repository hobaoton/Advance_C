# BÀI 19 NAME SPACE & CẤP PHÁT ĐỘNG TRONG C++
## 1. NAME SPACE
- **Namespace**: là tính năng được sử dụng để nhóm các định danh (tên biến, hàm, lớp,...) lại với nhau nhằm tránh xung đột tên khi chương trình trở nên phức tạp hoặc khi sử dụng các thư viện khác nhau có thể có các định dạng trùng lặp.
- **Mục đích**: 
    + Tránh xung đột tên khi các dự án lớn hoặc thêm nhiều thư viện khác nhau trong cùng một chương trình, rất dễ xảy ra xung đột nếu các thành phần có cùng tên. `Namespace` cho phép phân biệt các định dạng bằng cách đặt chúng trong các không gian tên khác nhau.
    + Tổ chức mã nguồn thành cách nhóm logic, giúp mã nguồn dễ đọc, dễ bảo trì và dễ tái sử dụng.
    + `Namespace` cho phép mở rộng hoặc tái sử dụng mã nguồn mà không sợ ảnh hưởng đến các phần khác của chương trình hoặc các thư viện bên ngoài.
    + `Namespace` giúp xác định phạm vi của các định danh, nghĩa là các phạm vị chỉ được truy cập trong phạm vi của `namespace`, trừ khi được chỉ định rõ ràng.

- Khác với `struct`, `union`, `class` được gọi là kiểu dữ liệu người dùng tự định nghĩa ra, tuy nhiên `namespace` chỉ là tên để nhóm các định danh lại với nhau.

## 2. KHAI BÁO NAMESPACE

- **Khai báo namespace**
```cpp
    namespace NamespaceName {
    // Các khai báo như biến, hàm, lớp, v.v.
}
```
**Ví dụ**
```cpp
    namespace MyNamespace {
    int myVariable = 10;

    void myFunction() {
        // Code here
    }
}

```
- **Namespace lồng nhau**
```cpp
namespace OuterNamespace {
    namespace InnerNamespace {
        void innerFunction() {
            // Code here
        }
    }
}

```

- **Namespace không khai báo tên (Anonymous namespace)**: Dùng để hạn chế phạm vi của các định danh trong tệp nguồn cụ thể, giúp chúng không thể được truy cập từ tệp khác.
```cpp
namespace {
    int hiddenVariable = 42;
}
```

- **Khai báo Namespace trong file header**: khi khai báo `namespace` trong file header thì cũng chỉ cần khai báo các biến, hàm,.. trong `namespace` mà ko khởi tạo.
```cpp
#ifndef FILEC_HPP
#define FILEC_HPP

namespace fileC {
    void display (int id);
}

#endif
```



## 3. CÁCH THỨC TRUY CẬP NAMESPACE

### 3.1 **Truy cập thông qua toán tử phạm vi `::`**:
   - Sử dụng toán tử phạm vi để truy cập các thành phần trong namespace.
   ```cpp
   MyNamespace::myFunction();
   ```

### 3.2 **Sử dụng từ khóa `using`**:
   - Từ khóa `using` cho phép sử dụng trực tiếp các phần tử trong `namespace` mà không cần phải gọi toán tử `::` mỗi khi truy cập.
   
    - **Chú ý:** Chỉ nên sử dụng từ khóa `using` khi thành phần trong `namespace` là duy nhất nghĩa là không bị trùng với các đối tượng khác trong chương trình chính và trong các `namespace` khác.

   - **`using namespace` toàn bộ namespace**:
     ```cpp
     using namespace MyNamespace;
     myFunction();  // Không cần chỉ định MyNamespace::
     ```
   
   - **`using` một thành phần cụ thể**:
     ```cpp
     using MyNamespace::myFunction;
     myFunction();  // Chỉ dùng cho hàm myFunction từ MyNamespace
     ```

### 3.3 **Alias (bí danh) namespace**:
   - Tạo bí danh cho một namespace để dễ dàng sử dụng, đặc biệt khi tên namespace dài.
   ```cpp
   namespace MN = MyNamespace;
   MN::myFunction();  // Sử dụng bí danh MN để gọi hàm
   ```

### 3.4 Ví dụ tổng hợp:

```cpp
#include <iostream>

namespace A {
    const char *str = "Hello from A";

    void display() {
        std::cout << str << std::endl;
    }
}

namespace B {
    const char *str = "Hello from B";

    void display() {
        std::cout << str << std::endl;
    }
}

int main() {
    // Truy cập thông qua toán tử phạm vi
    std::cout << A::str << std::endl;
    A::display();

    // Truy cập thông qua từ khóa using
    using namespace B;
    std::cout << str << std::endl;  // Truy cập trực tiếp không cần B::
    display();

    return 0;
}
```

## 4. NAME SPACE MỞ RỘNG
- **Namespace mở rộng** cho phép định nghĩa hoặc thêm nội dung mới vào một `namespace` đã tồn tại mà không cần phải định nghĩa lại toàn bộ. Điều này hữu ích khi muốn tổ chức mã nguồn theo từng phần riêng biệt hoặc mở rộng một `namespace` chuẩn hoặc do bạn định nghĩa trước đó.

- **Cách sử dụng namespace mở rộng** có thể mở rộng một `namespace` bằng cách khai báo lại cùng tên `namespace` đó ở một nơi khác trong mã của bạn và thêm vào các định nghĩa mới.

- **Ví dụ về namespace mở rộng**
+ **Khai báo và định nghĩa ban đầu:**
```cpp
namespace MyNamespace {
    void func1() {
        // Code cho func1
    }
}
```

+ **Mở rộng namespace sau này:**
```cpp
namespace MyNamespace {
    void func2() {
        // Code cho func2
    }
}
```

+ **Sử dụng các hàm trong namespace:**
```cpp
#include <iostream>

namespace MyNamespace {
    void func1() {
        std::cout << "Func1 in MyNamespace" << std::endl;
    }
}

namespace MyNamespace {
    void func2() {
        std::cout << "Func2 in MyNamespace" << std::endl;
    }
}

int main() {
    MyNamespace::func1(); // Gọi func1
    MyNamespace::func2(); // Gọi func2
    return 0;
}
```

- **Một số lưu ý**:
    + `Namespace` mở rộng phải có cùng tên với `namespace` gốc.
    + Không nên mở rộng các `namespace` tiêu chuẩn như `std` với nội dung tùy chỉnh (điều này là không hợp lệ và gây lỗi biên dịch).
    + `Namespace` mở rộng thường được sử dụng trong các tệp header để thêm các khai báo hoặc định nghĩa liên quan đến một phần của chương trình.

## 5. NAMESPACE STD
- `Namespace std` (viết tắt của Standard) là không gian tên chuẩn được định nghĩa trong thư viện chuẩn của C++ (Standard Library). Mọi thành phần chuẩn như các hàm, lớp, và đối tượng đều nằm trong namespace này để tránh xung đột tên với các định nghĩa kháC.

- Khi khai báo `using namespace std` nghĩa là yêu cầu truy cập đến `namspace std` mà không cần sử dụng đến toán tử truy câp `::`.

## 6. CẤP PHÁT ĐỘNG TRONG C++

### 6.1 `new` - Cấp Phát Bộ Nhớ Động

`new` được dùng để cấp phát bộ nhớ (địa chỉ) cho một đối tượng hoặc mảng trong thời gian chạy. Nó thực hiện hai nhiệm vụ chính:
- Cấp phát một vùng nhớ đủ lớn để chứa đối tượng hoặc mảng.
- Gọi constructor để khởi tạo đối tượng (nếu có).

- **Cú pháp:**
- Cấp phát cho một đối tượng đơn lẻ:
  ```cpp
  int* ptr = new int;           // Cấp phát bộ nhớ cho một số nguyên
  *ptr = 5;                     // Gán giá trị cho vùng nhớ
  ```

- Cấp phát và khởi tạo một đối tượng:
  ```cpp
  int* ptr = new int(5);        // Cấp phát và khởi tạo với giá trị 5
  ```

- Cấp phát cho một mảng:
  ```cpp
  int* arr = new int[10];       // Cấp phát bộ nhớ cho mảng 10 phần tử
  ```

- Cấp phát cho một đối tượng phức tạp:
  ```cpp
  class MyClass {
      int a;
  public:
      MyClass(int x) : a(x) {}
  };

  MyClass* obj = new MyClass(10);  // Gọi constructor với tham số
  ```

### 6.2 `delete` - Giải Phóng Bộ Nhớ Động

`delete` được dùng để giải phóng bộ nhớ đã được cấp phát bằng `new`. Nó thực hiện hai nhiệm vụ chính:
- Gọi destructor (nếu có) để dọn dẹp tài nguyên của đối tượng.
- Giải phóng vùng nhớ trả về cho hệ thống.

- **Cú pháp:**
- Giải phóng một đối tượng đơn lẻ:
  ```cpp
  delete ptr;     // Giải phóng bộ nhớ của một biến
  ```

- Giải phóng một mảng:
  ```cpp
  delete[] arr;   // Giải phóng bộ nhớ của một mảng
  ```

### Lưu ý quan trọng:

1. **Khớp giữa `new` và `delete`**: 
   - Mỗi vùng nhớ được cấp phát bằng `new` phải được giải phóng bằng `delete`.
   - Mỗi vùng nhớ được cấp phát bằng `new[]` phải được giải phóng bằng `delete[]`.

2. **Constructor và Destructor**:
   - Khi sử dụng `new`, constructor của đối tượng sẽ được gọi để khởi tạo đối tượng.
   - Khi sử dụng `delete`, destructor của đối tượng sẽ được gọi để dọn dẹp tài nguyên trước khi bộ nhớ được giải phóng.

3. **Rò rỉ bộ nhớ (Memory Leak)**:
   - Nếu bạn quên gọi `delete` hoặc `delete[]`, bộ nhớ sẽ không được giải phóng và có thể gây ra rò rỉ bộ nhớ, làm giảm hiệu suất của chương trình.

4. **An toàn kiểu dữ liệu**:
   - `new` và `delete` an toàn hơn so với `malloc` và `free` vì chúng tự động gọi constructor/destructor và không yêu cầu ép kiểu.

### Ví dụ:

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor called!" << endl; }
    ~MyClass() { cout << "Destructor called!" << endl; }
};

int main() {
    // Cấp phát bộ nhớ cho một đối tượng
    MyClass* obj = new MyClass();
    
    // Giải phóng bộ nhớ cho đối tượng
    delete obj;

    // Cấp phát bộ nhớ cho mảng đối tượng
    MyClass* arr = new MyClass[3];

    // Giải phóng bộ nhớ cho mảng
    delete[] arr;

    return 0;
}
```

**Kết quả:**
```
Constructor called!
Destructor called!
Constructor called!
Constructor called!
Constructor called!
Destructor called!
Destructor called!
Destructor called!
```

### Kết luận:
- `new` và `delete` cung cấp cơ chế quản lý bộ nhớ động mạnh mẽ, linh hoạt, phù hợp với các đặc điểm hướng đối tượng của C++.
- Sử dụng chúng đúng cách giúp tránh rò rỉ bộ nhớ và đảm bảo hiệu năng của chương trình.