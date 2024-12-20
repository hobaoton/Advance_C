# BÀI 3: POINTER

## 1. Tổng quan về Pointer

- **Khái niệm**: Con trỏ (pointer) là một biến đặc biệt trong ngôn ngữ lập trình C, chứa địa chỉ bộ nhớ của một đối tượng khác như biến, hàm, hoặc mảng. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt và hiệu quả hơn.

- **Cách khai báo**: Con trỏ được khai báo bằng cách sử dụng dấu `*` trước tên biến:
```c
int *ptr;       // Con trỏ đến kiểu int
char *ptr_char; // Con trỏ đến kiểu char
float *ptr_float; // Con trỏ đến kiểu float
```

- **Lấy địa chỉ của một biến**: Để lấy địa chỉ của một biến, sử dụng toán tử `&`:
```c
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
```

- **Truy cập giá trị thông qua con trỏ**: Để truy cập giá trị của biến mà con trỏ trỏ tới, sử dụng toán tử `*` (dereference):
```c
int y = *ptr_x;  // y sẽ bằng giá trị của x
```

- **Kích thước của con trỏ**: Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch. Sử dụng `sizeof()` để kiểm tra kích thước của con trỏ:
```c
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
}
```

- **Ví dụ minh họa**
Ví dụ về các nội dung trên.
```c
#include <stdio.h>

int main() {
    int test = 5;   // address: 0x01
                    // value:   5
    int *ptr = &test;  // address: 0xf1
                       // value: 0x01

    printf("Địa chỉ của con trỏ: %p\n", ptr);// Lấy giá trị địa chỉ con trỏ
    printf("Địa chỉ mà con trỏ đang trỏ tới: %p\n", &ptr); // Lấy địa chỉ mà con trỏ đang trỏ tới
    printf("Giá trị tại địa chỉ con trỏ đang trỏ tới: %d\n", *ptr); // Lấy giá trị tại địa chỉ con trỏ đang trỏ tới

    return 0;
}
```

- **Con trỏ và mảng**: Đối với một mảng, địa chỉ mà con trỏ trỏ đến là vị trí phần tử đầu tiên trong mảng. Khi khai báo, ta chỉ cần gán tên mảng cho con trỏ:
```c
#include <stdio.h>

int main() {
    uint16_t arr[] = {5, 8, 7};
    uint16_t *ptr = arr;  // giá trị ptr = &arr[0] = 0xa0; *ptr = arr[0] = 5;
                          // (ptr + 1) = &arr[1] = 0xa2;   *(ptr + 1) = arr[1] = 8;

    printf("Giá trị phần tử đầu tiên: %d\n", *ptr);
    printf("Giá trị phần tử thứ hai: %d\n", *(ptr + 1));
    printf("Giá trị phần tử thứ ba: %d\n", *(ptr + 2));

    return 0;
}
```

- **Kích thước con trỏ**: Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính. Trên hệ thống 32-bit, kích thước con trỏ thường là 4 byte, trong khi trên hệ thống 64-bit, kích thước con trỏ thường là 8 byte.

- **Mục đích của dữ liệu khai báo cho con trỏ**: Dữ liệu khai báo cho con trỏ phục vụ vào mục đích đọc dữ liệu tại vị trí mà con trỏ đang trỏ đến. Điều này giúp đảm bảo rằng con trỏ được sử dụng đúng cách và tránh các lỗi truy cập bộ nhớ.

## 2. Void Pointer

- **Void Pointer**: Con trỏ void (void pointer) là một con trỏ có thể trỏ tới bất kỳ kiểu dữ liệu nào. Điều này có nghĩa là con trỏ void không có kiểu dữ liệu cụ thể, và do đó, nó có thể được sử dụng để trỏ tới bất kỳ địa chỉ bộ nhớ nào mà không cần biết trước kiểu dữ liệu của giá trị tại địa chỉ đó.

- **Khai báo**: Con trỏ void được khai báo bằng cách sử dụng từ khóa `void` trước dấu `*`.
  ```c
  void *ptr_void;
  ```

- **Đặc điểm**:
    - Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, giúp nó rất linh hoạt trong việc quản lý bộ nhớ và xử lý dữ liệu.
    - Không thể truy cập trực tiếp giá trị mà con trỏ void trỏ tới mà không chuyển đổi nó sang kiểu dữ liệu cụ thể.

- **Ví dụ sử dụng con trỏ void**
```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    void *ptr_void;
    int a = 5;
    ptr_void = &a;
    printf("Địa chỉ: %p \n Địa chỉ: %d \n Giá trị: %d\n", ptr_void, ptr_void, *(int*)ptr_void); // ép kiểu dữ liệu về int
  
    double b = 3.14;
    ptr_void = &b;
    printf("Địa chỉ: %p \n Địa chỉ: %d \n Giá trị: %0.2f", ptr_void, ptr_void, *(double*)ptr_void); // ép kiểu dữ liệu về double
    
    char c = 'c';
    ptr_void = &c;
    printf("\nĐịa chỉ: %p\n Địa chỉ: %d \n Giá trị: %c ", ptr_void, ptr_void, *(char*)ptr_void); // ép kiểu dữ liệu về char
    
    char arr[] = "hello ho bao ton";
    ptr_void = arr; // vị trí pointer trỏ đến vị trí phần tử đầu tiên trong mảng
    for (int i = 0; i < sizeof(arr); i++) {
        ptr_void = &arr[i];
        printf("\nGiá trị: %c", *(char*)(ptr_void + 1));
    }

    void *ptr1[] = {&a, &b, &c, arr}; // mảng con trỏ với giá trị là địa chỉ các đối tượng
    printf("ptr1[0] = %d\n", *(int*)ptr1[0]);
    printf("ptr1[1] = %f\n", *(double*)ptr1[1]);
    printf("ptr1[2] = %c\n", *(char*)ptr1[2]);
    for (int i = 0; i < sizeof(arr); i++) {
        printf("ptr1[%d] = %c\n", i, *(char*)(ptr1[3] + i)); 
        printf("ptr1[%d] = %p\n", i, (ptr1[3] + i));   
    }
    return 0;
}
```

- **Ứng dụng của con trỏ void**
    - **Quản lý bộ nhớ động**: Con trỏ void thường được sử dụng trong các hàm quản lý bộ nhớ động như `malloc`, `calloc`, và `realloc` để trả về địa chỉ của vùng nhớ được cấp phát mà không cần biết trước kiểu dữ liệu.
    EX: 
    ```c
        int *a;
        a = (int*)malloc(sizeof(int) * n);
    ```
    - **Hàm tổng quát**: Con trỏ void có thể được sử dụng trong các hàm tổng quát để xử lý các kiểu dữ liệu khác nhau mà không cần viết lại mã cho từng kiểu dữ liệu cụ thể.

## 3. Function Pointer

- **Con Trỏ Hàm**:Con trỏ hàm là một biến lưu trữ địa chỉ của một hàm. Cho phép gọi hàm thông qua con trỏ, truyền hàm như là một đối số cho một hàm khác, hoặc lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu. 

- **Khai báo con trỏ hàm**: Con trỏ hàm phải có cùng kiểu dữ liệu trả về và cùng kiểu dữ liệu tham số với hàm mà nó trỏ tới.
  ```c
  void (*ptr)(int, int);
  ```

- **Ví dụ về con trỏ hàm**: 
```c
#include <stdio.h>

// Hàm cộng hai số nguyên
void sum(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

// Hàm trừ hai số nguyên
void subtract(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

// Hàm tính toán, nhận con trỏ hàm làm tham số
void calculator(void (*ptr)(int, int), int a, int b) {
    ptr(a, b);
}

int main(int argc, char const *argv[]) {
    // Khai báo và gán con trỏ hàm
    void (*ptr)(int, int) = sum; // Con trỏ hàm trỏ tới hàm sum
    ptr(2, 3); // Gọi hàm sum thông qua con trỏ hàm

    void (*ptr1)(int, int) = &subtract; // Con trỏ hàm trỏ tới hàm subtract
    ptr1(10, 3); // Gọi hàm subtract thông qua con trỏ hàm

    // In địa chỉ của hàm subtract
    printf("%p\n", *ptr1);
    printf("%p\n", ptr1);
    printf("%p\n", &subtract);

    // Mảng con trỏ hàm
    void (*fptr[])(int, int) = {sum, subtract};
    fptr[0](5, 25); // Gọi hàm sum thông qua mảng con trỏ hàm
    fptr[1](36, 7); // Gọi hàm subtract thông qua mảng con trỏ hàm

    // Truyền con trỏ hàm trực tiếp vào hàm calculator
    calculator(sum, 9, 15);
    calculator(subtract, 9, 15);

    return 0;
}
```
- **Giải thích**
    - **Khai báo con trỏ hàm**:
   ```c
   void (*ptr)(int, int) = sum;
   ```
   Con trỏ hàm `ptr` được khai báo để trỏ tới hàm `sum`. Con trỏ hàm phải có cùng kiểu dữ liệu trả về và cùng kiểu dữ liệu tham số với hàm mà nó trỏ tới.

    - **Gọi hàm thông qua con trỏ hàm**:
   ```c
   ptr(2, 3);
   ```
   Gọi hàm `sum` thông qua con trỏ hàm `ptr`.

    - **Mảng con trỏ hàm**:
   ```c
   void (*fptr[])(int, int) = {sum, subtract};
   ```
   Khai báo một mảng con trỏ hàm `fptr` chứa địa chỉ của các hàm `sum` và `subtract`.

    - **Truyền con trỏ hàm vào hàm khác**:
   ```c
   calculator(sum, 9, 15);
   ```
   Truyền con trỏ hàm `sum` trực tiếp vào hàm `calculator`.

## 4. Pointer to Constant

- **Pointer to Constant (con trỏ hằng)**: Con trỏ hẳng (pointer to constant) là một con trỏ mà giá trị tại địa chỉ nó trỏ tới không thể thay đổi thông qua con trỏ. Tuy nhiên, địa chỉ mà hằng con trỏ trỏ tới có thể thay đổi. Điều này có nghĩa là bạn có thể thay đổi địa chỉ mà con trỏ trỏ tới, nhưng không thể thay đổi giá trị tại địa chỉ đó thông qua con trỏ. (chỉ cho phép đọc giá trị tại vị trí trỏ tới không cho phép thay đổi giá trị)

- **Khai báo con trỏ hằng**: Con trỏ hằng được khai báo bằng cách sử dụng từ khóa `const` trước kiểu dữ liệu của con trỏ.
  ```c
  const int *ptr;
  hoặc int const *ptr;
  ```

- **Ví dụ về hằng con trỏ**
```c
#include <stdio.h>

int main() {
    int value1 = 10;
    int value2 = 20;
    const int *ptr = &value1; // Con trỏ hằng trỏ tới biến value1

    printf("Giá trị của value1: %d\n", *ptr);

    // Thử thay đổi giá trị tại địa chỉ mà hằng con trỏ trỏ tới (sẽ gây lỗi)
    // *ptr = 15; // Lỗi: không thể thay đổi giá trị thông qua hằng con trỏ
    // muốn thay đối giá trị phải thay đổi trực tiếp trên biến gốc
    // Thay đổi địa chỉ mà hằng con trỏ trỏ tới
    ptr = &value2;
    printf("Giá trị của value2: %d\n", *ptr);

    return 0;
}
```

## 5 Constant to Pointer

- **Hằng con trỏ**: Hằng con trỏ (constant pointer) là một con trỏ mà địa chỉ nó trỏ tới không thể thay đổi sau khi được khởi tạo. Điều này có nghĩa là khi hằng con trỏ được khởi tạo, nó sẽ luôn trỏ tới một địa chỉ bộ nhớ và không thể trỏ tới địa chỉ khác. Tuy nhiên, giá trị tại địa chỉ mà hằng con trỏ trỏ tới có thể thay đổi. 

- **Khai báo hằng con trỏ**: hằng con trỏ được khai báo bằng cách sử dụng từ khóa `const` trước kiểu dữ liệu của con trỏ.
  ```c
  int *const ptr;
  ```

- **Ví dụ về hằng con trỏ**
```c
#include <stdio.h>

int a = 5;
int b = 10;
int const *ptr = &a; // Con trỏ hằng trỏ tới biến a
int *ptr1 = &a;
const char *st1 = "hello";
const char *st2 = "world";

int *const cptr = &b; // Hằng con trỏ trỏ tới biến b

int main(int argc, char const *argv[]) {
    *ptr1 = 15;
    printf("%p\n%d\n", ptr, *ptr);
    ptr = &b;
    printf("%p\n%d\n", ptr, *ptr);

    printf("%p\n%d\n", cptr, *cptr);
    return 0;
    // cptr = &a; // Lỗi: không thể thay đổi địa chỉ của con trỏ hằng
    // printf("%p\n%d\n", cptr, *cptr);
}
```

- **Giải thích chi tiết**
    **Khai báo hằng con trỏ**:
   ```c
   int *const cptr = &b;
   ```
   Con trỏ `cptr` được khai báo là hằng con trỏ trỏ tới biến `b`. Điều này có nghĩa là `cptr` không thể trỏ tới địa chỉ khác sau khi được khởi tạo.

    **Thay đổi giá trị tại địa chỉ mà hằng con trỏ trỏ tới**:
   ```c
   *ptr1 = 15;
   ```
   Giá trị tại địa chỉ mà con trỏ `ptr1` trỏ tới có thể thay đổi, nhưng địa chỉ mà con trỏ `cptr` trỏ tới không thể thay đổi.

## 6. Null Pointer

- **Null Pointer**: Null pointer (con trỏ null) là một con trỏ không trỏ tới bất kỳ địa chỉ nào trong bộ nhớ. Nó thường được sử dụng để chỉ ra rằng con trỏ không được khởi tạo hoặc không trỏ tới bất kỳ đối tượng nào. 

- **Khai báo null pointer**: Null pointer được khai báo bằng cách gán giá trị `NULL` cho con trỏ.
  ```c
  int *ptr = NULL;
  ```

- **Ví dụ về null pointer**
```c
#include <stdio.h>

int main() {
    int *ptr = NULL; // Khai báo con trỏ null

    if (ptr == NULL) {
        printf("Con trỏ ptr không trỏ tới bất kỳ địa chỉ hợp lệ nào.\n");
    }

    // Thử truy cập giá trị tại địa chỉ mà con trỏ null trỏ tới (sẽ gây lỗi)
    // printf("%d\n", *ptr); // Lỗi: không thể dereference con trỏ null

    return 0;
}
```
## 7. Pointer to Pointer

- **Con Trỏ Trỏ Tới Con Trỏ (pointer to pointer)**:Con trỏ trỏ tới con trỏ (pointer to pointer) là một con trỏ mà giá trị của nó là địa chỉ của một con trỏ khác. Cho phép tạo ra các cấp độ con trỏ khác nhau, giúp quản lý và thao tác với các con trỏ một cách linh hoạt hơn.

- **Khai báo con trỏ trỏ tới con trỏ**: Con trỏ trỏ tới con trỏ được khai báo bằng cách sử dụng hai dấu `*` trước tên biến.
  ```c
  int **ptr;
  ```

- **Ví dụ về con trỏ trỏ tới con trỏ**
```c
#include <stdio.h>

int main() {
    int value = 10;
    int *ptr = &value;  // Con trỏ trỏ tới biến value
    int **ptr_to_ptr = &ptr;  // Con trỏ trỏ tới con trỏ ptr

    // In giá trị của biến value thông qua con trỏ ptr
    printf("Giá trị của value: %d\n", *ptr);

    // In giá trị của biến value thông qua con trỏ trỏ tới con trỏ ptr_to_ptr
    printf("Giá trị của value thông qua con trỏ trỏ tới con trỏ: %d\n", **ptr_to_ptr);

    // In địa chỉ của biến value
    printf("Địa chỉ của value: %p\n", (void*)&value);

    // In địa chỉ mà con trỏ ptr trỏ tới (địa chỉ của biến value)
    printf("Địa chỉ mà con trỏ ptr trỏ tới: %p\n", (void*)ptr);

    // In địa chỉ của con trỏ ptr
    printf("Địa chỉ của con trỏ ptr: %p\n", (void*)&ptr);

    // In địa chỉ mà con trỏ trỏ tới con trỏ ptr_to_ptr trỏ tới (địa chỉ của con trỏ ptr)
    printf("Địa chỉ mà con trỏ trỏ tới con trỏ ptr_to_ptr trỏ tới: %p\n", (void*)ptr_to_ptr);

    return 0;
}
```
