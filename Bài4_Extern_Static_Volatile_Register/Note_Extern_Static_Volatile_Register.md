# BÀI 5 Extern- Static- Volatile- Register
## 1. Extern 
### 1.1.Khai báo biến `extern`**:
   ```c
   // File1.c
   int a = 10; // Định nghĩa biến a

   // File2.c
   extern int a; // Khai báo biến a
   ```

### 1.2. Khai báo hàm `extern`**:
   ```c
   // File1.c
   void display() {
       printf("Hello, World!\n");
   }

   // File2.c
   extern void display(); // Khai báo hàm display
   ```

### 1.3. Lưu ý khi sử dụng `extern`
- **Không định nghĩa lại**: Khi sử dụng `extern`, chỉ khai báo biến hoặc hàm mà không định nghĩa lại chúng.
- **Liên kết các tệp**: Các tệp chứa khai báo `extern` và định nghĩa thực tế phải được liên kết với nhau khi biên dịch. Ví dụ:
```bash
  gcc File1.c File2.c -o output
  ```

### 1.4. Ứng dụng của `extern`
- **Chia sẻ biến và hàm giữa các tệp**: `extern` cho phép chia sẻ các biến và hàm giữa các tệp khác nhau trong cùng một dự án.
- **Thiết kế thư viện**: `extern` thường được sử dụng trong thiết kế thư viện để khai báo các hàm và biến mà thư viện cung cấp.

### 1.5. Ví dụ chi tiết
Giả sử có hai tệp nguồn: `main.c` và `utils.c`.

**main.c**:
```c
#include <stdio.h>

// Khai báo biến extern
extern int count;

// Khai báo hàm extern
extern void increment();

int main() {
    count = 0;
    increment();
    printf("Count: %d\n", count);
    return 0;
}
```

**utils.c**:
```c
#include <stdio.h>

// Định nghĩa biến
int count;

// Định nghĩa hàm
void increment() {
    count++;
}
```

Khi biên dịch, cần liên kết cả hai tệp lại với nhau:
```bash
gcc main.c utils.c -o program
```

Khi chạy gõ lệnh `./program` trong TERMINAL

Kết quả khi chạy chương trình `program` sẽ là:
```
Count: 1
```

## 2. Static

### 2.1. Static local variables

#### 2.1.1 Đặc điểm của biến cục bộ tĩnh
- **Thời gian sống**: Khác với các biến cục bộ thông thường, biến cục bộ tĩnh được tạo ra chỉ một lần và giữ nguyên giá trị của nó giữa các lần gọi hàm. Điều này có nghĩa là giá trị của biến sẽ được bảo toàn ngay cả khi hàm kết thúc và được gọi lại sau đó.
- **Phạm vi**: Biến cục bộ tĩnh chỉ có thể truy cập được trong phạm vi của hàm nơi nó được khai báo, giống như các biến cục bộ thông thường.
- **Khởi tạo**: Biến cục bộ tĩnh chỉ được khởi tạo một lần, lần đầu tiên hàm được gọi. Nếu không được khởi tạo cụ thể, chúng sẽ tự động được khởi tạo với giá trị 0.

#### 2.1.2. Ví dụ
Dưới đây là một ví dụ minh họa về cách biến cục bộ tĩnh hoạt động:

```c
#include <stdio.h>

void countCalls() {
    static int count = 0; // Biến cục bộ tĩnh
    count++;
    printf("Hàm được gọi %d lần\n", count);
}

int main() {
    countCalls(); // Output: Hàm được gọi 1 lần
    countCalls(); // Output: Hàm được gọi 2 lần
    countCalls(); // Output: Hàm được gọi 3 lần
    return 0;
}
```

Trong ví dụ trên, biến `count` là một biến cục bộ tĩnh được khai báo trong hàm `countCalls`. Nó giữ nguyên giá trị của mình giữa các lần gọi hàm, do đó mỗi lần hàm được gọi, giá trị của `count` sẽ tăng lên.

#### 2.1.3. Lưu trữ trong bộ nhớ
- **Biến cục bộ tĩnh** được lưu trữ trong phân vùng dữ liệu (data segment) của bộ nhớ, không phải trong stack. Do đó thời gian sống của chúng kéo dài hơn so với các biến cục bộ thông thường.
- Nếu biến cục bộ tĩnh được khởi tạo với giá trị khác 0, nó sẽ được lưu trữ trong phân vùng dữ liệu đã khởi tạo (Data).
- Nếu biến cục bộ tĩnh được khởi tạo với giá trị 0 hoặc không được khởi tạo, nó sẽ được lưu trữ trong phân vùng BSS (Block Started by Symbol).

- **Chú ý** có thể khai báo 1 biến static cho nhiều chương trình khác nhau. Và ko gây ra xung đột khi thực hiện chương trình
```c
void count()
{
    static int a = 5;
    printf("a = %d", a++);
}

void count1()
{
    static int a = 0;
}
```
### 2.2 Static global variables

#### 2.2.1. Đặc điểm của biến `static` toàn cục
- **Phạm vi**: Biến `static` toàn cục chỉ có thể truy cập được trong tệp nguồn nơi nó được khai báo. Điều này có nghĩa là nó không thể được truy cập từ các tệp nguồn khác, ngay cả khi sử dụng từ khóa `extern`.
- **Thời gian sống**: Biến `static` toàn cục tồn tại trong suốt thời gian chạy của chương trình, từ khi chương trình bắt đầu cho đến khi kết thúc.
- **Khởi tạo**: Biến `static` toàn cục được khởi tạo một lần duy nhất khi chương trình bắt đầu. Nếu không được khởi tạo cụ thể, nó sẽ tự động được khởi tạo với giá trị 0.

#### 2.2.2. Ví dụ

**file1.c**:
```c
#include <stdio.h>

static int count = 0; // Biến static toàn cục

void increment() {
    count++;
    printf("Count: %d\n", count);
}
```

**main.c**:
```c
#include <stdio.h>

// extern int count; // Không thể truy cập biến static toàn cục từ tệp khác

void increment();

int main() {
    increment(); // Output: Count: 1
    increment(); // Output: Count: 2
    return 0;
}
```

Trong ví dụ trên, biến `count` được khai báo là `static` toàn cục trong `file1.c`. Nó chỉ có thể truy cập được trong `file1.c` và không thể truy cập từ `main.c`. Hàm `increment` được sử dụng để tăng giá trị của `count` và in ra giá trị hiện tại.

#### 2.2.3. Lợi ích của biến `static` toàn cục
- **Bảo mật**: Giúp bảo vệ biến khỏi việc truy cập và thay đổi từ các tệp nguồn khác, tăng cường tính bảo mật và tính toàn vẹn của dữ liệu.
- **Quản lý bộ nhớ**: Biến `static` toàn cục được khởi tạo một lần và tồn tại trong suốt thời gian chạy của chương trình, giúp quản lý bộ nhớ hiệu quả hơn.

## 3. Volatile

### 3.1. Đặc điểm của biến `volatile`
- **Không tối ưu hóa**: Trình biên dịch sẽ không tối ưu hóa các truy cập đến biến `volatile`, đảm bảo rằng mỗi lần truy cập đều thực sự đọc hoặc ghi vào bộ nhớ.
- **Thay đổi bất ngờ**: Biến `volatile` có thể thay đổi bởi các yếu tố bên ngoài như phần cứng, các luồng khác, hoặc các tín hiệu.

### 3.2 Sử dụng `volatile`
- **Biến phần cứng**: Khi làm việc với các thanh ghi phần cứng hoặc các cổng I/O.
  ```c
  volatile int *port = (int *)0x1234; // Địa chỉ của một cổng I/O
  ```
- **Biến chia sẻ giữa các luồng**: Khi một biến được truy cập bởi nhiều luồng trong lập trình đa luồng.
  ```c
  volatile int flag = 0;
  ```

### 3.3 Ví dụ
Dưới đây là một ví dụ về cách sử dụng từ khóa `volatile`:

```c
#include <stdio.h>
#include <stdbool.h>

volatile bool flag = false;

void interruptHandler() {
    flag = true; // Biến flag có thể được thay đổi bởi một ngắt
}

int main() {
    while (!flag) {
        // Chờ cho đến khi flag được thay đổi bởi ngắt
    }
    printf("Flag has been set!\n");
    return 0;
}
```

Trong ví dụ trên, biến `flag` được khai báo là `volatile` vì nó có thể được thay đổi bởi một hàm ngắt (interrupt handler). Trình biên dịch sẽ không tối ưu hóa vòng lặp `while (!flag)`, đảm bảo rằng giá trị của `flag` được kiểm tra mỗi lần lặp.

### 3.4. Mục đích `volatile`
- **Đảm bảo tính chính xác**: Đảm bảo rằng giá trị của biến luôn được đọc từ bộ nhớ, không phải từ bộ nhớ đệm của CPU.
- **Tương thích với phần cứng**: Hữu ích khi làm việc với các thiết bị phần cứng mà giá trị của biến có thể thay đổi bất ngờ.

## 4. Register

### 4.1. Đặc điểm của biến `register`
- **Tốc độ truy cập nhanh**: Biến `register` có thể được truy cập nhanh hơn so với các biến lưu trữ trong bộ nhớ chính, vì các thanh ghi của CPU có tốc độ truy cập nhanh hơn.
- **Không có địa chỉ**: Không thể lấy địa chỉ của một biến `register` bằng cách sử dụng toán tử `&`, vì biến này không có địa chỉ bộ nhớ cụ thể.

### 4.2. Ví dụ
Dưới đây là một ví dụ về cách sử dụng từ khóa `register`:

```c
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    register int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 200000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```

Trong ví dụ trên, biến `i` được khai báo là `register`, yêu cầu trình biên dịch lưu trữ biến này trong một thanh ghi của CPU để tăng tốc độ truy cập.

### 4.3 Sử dụng `register`
- **Vòng lặp**: Khi có một biến được sử dụng nhiều lần trong một vòng lặp, việc khai báo biến đó là `register` có thể giúp tăng hiệu suất.
- **Biến tạm thời**: Các biến tạm thời được sử dụng trong các phép tính toán học hoặc logic phức tạp có thể được khai báo là `register` để tăng tốc độ xử lý.

