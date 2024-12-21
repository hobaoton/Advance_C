# Bài 7: Struct và Union

## 1. Struct
- Struct được sử dụng để định nghĩa một kiểu dữ liệu tùy chỉnh, chứa một tập hợp các thuộc tính hoặc biến có kiểu dữ liệu khác nhau.

**Cú pháp:** khơi tạo struct có 2 cách
- Cách 1:
```c
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
// khi khới tạo giá trị mang kiểu dữ liệu 
struct TenStruct bien1, bien2;
```
**Ví dụ:**
```c
struct Point {
    int x;
    int y;
};

int main(){
    struct Point lan1{8, 9};
}
```

- Cách 2 sử dụng từ khóa typedef và tên struct nằm ở cuối.
```c
typedef struct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
} tenStruct;
// khởi tạo phần tử thuộc kiểu struct
    tenStruct bien1, bien2
```
**Ví dụ**
```c
typedef struct {
    char ten[30];
    float diem;
    int id;
} SinhVien;

SinhVien sv1{"hobaoton", 8, 22145490};
```

**Thành Viên (Member):** Mỗi biến trong `struct` được gọi là một thành viên hoặc trường. Trong ví dụ `struct SinhVien`, `ten[]` `diem` và `id` là các thành viên của `SinhVien`.

**Địa chỉ của Struct**: là địa chỉ của thành phần đầu tiên, như trong `struct SinhVien` là vị trí mảng `ten[]` đồng nghĩa với vị trí phần tử đầu tiên trong mảng `ten[]`.

**Truy xuất dữ liệu trong Struct**
```c
struct SinhVien sv1 = {"hobaoton", 8, 22145490};
```
Để truy cập các thành viên, sử dụng toán tử `.`:
```c
printf("ten: %s diem: %f id: $d\n", sv1.ten, sv1.diem, sv1.id);
```

**Sử Dụng Tham Số Trong Hàm:**
- Có thể truyền một biến thuộc kiểu `struct` như một tham số cho một hàm.
```c
void printPoint(struct SinhVien p) {
    printf("(%f, %d)\n", p.diem, p.id);
}
```

**Truyền Con Trỏ đến Struct:**
- Có thể truyền con trỏ đến `struct` như một tham số cho một hàm, cho phép thay đổi giá trị của `struct` bên trong hàm.
```c
void updatePoint(struct SinhVien* p, float newX, int newY) {
    p->diem = newX;
    p->id = newY;
}
```

**Kích thước của struct**:
Kích thước của một `struct` phụ thuộc vào các thành viên của nó và cách chúng được sắp xếp trong bộ nhớ. Kích thước phụ thuộc vào việc căn chỉnh (alignment) và đệm (padding) mà trình biên dịch áp dụng để tối ưu hóa truy cập bộ nhớ.

- **Ví Dụ Cụ Thể**
cấu trúc `SinhVien`:
```c
typedef struct {
    char ten[30];
    float diem;
    int id;
} SinhVien;
```
- **Tính Toán Kích Thước**
1. **`char ten[30]`**: Mảng ký tự có kích thước 30 bytes.
2. **`float diem`**: Biến kiểu `float` có kích thước 4 bytes.
3. **`int id`**: Biến kiểu `int` có kích thước 4 bytes.

- **Căn Chỉnh và Đệm**: Trình biên dịch có thể thêm các padding để đảm bảo rằng các thành viên được căn chỉnh đúng cách trong bộ nhớ. Ví dụ, nếu `float` và `int` yêu cầu căn chỉnh 4-byte, trình biên dịch có thể thêm các padding để đảm bảo rằng các thành viên này bắt đầu tại địa chỉ chia hết cho 4.

- **Tính Toán Kích Thước Thực Tế**
Giả sử trình biên dịch thêm các byte đệm để căn chỉnh các thành viên:
- `char ten[30]`: 30 bytes
- Padding: 2 bytes (để căn chỉnh `float` tại địa chỉ chia hết cho 4)
- `float diem`: 4 bytes
- `int id`: 4 bytes

Tổng kích thước của `struct` sẽ là:
```c
30 (ten) + 2 (padding) + 4 (diem) + 4 (id) = 40 bytes
```
- **Sử Dụng `sizeof` Để Kiểm Tra Kích Thước**
Bạn có thể sử dụng toán tử `sizeof` để kiểm tra kích thước của một `struct` trong C:
```c
#include <stdio.h>
typedef struct {
    char ten[30];
    float diem;
    int id;
} SinhVien;

int main() {
    printf("Kích thước của struct SinhVien: %zu bytes\n", sizeof(SinhVien));
    return 0;
}
```

## 2. Union
- **union** là một kiểu dữ liệu tương tự như struct, nhưng có một điểm khác biệt quan trọng: tất cả các thành viên trong union chia sẻ cùng một vùng bộ nhớ. Điều này có nghĩa là union chỉ sử dụng đủ bộ nhớ để lưu trữ thành viên có kích thước lớn nhất. 

- **Khai báo union**
- Cách 1:
```c
union UnionName {
    int intValue;
    float floatValue;
    char charValue;
};
```
- Cách 2:
```c
typedef union {
    int intValue;
    float floatValue;
    char charValue;
} UnionName;
```
- **Tính chất của union**
1. **Kích thước bộ nhớ**: Kích thước của một union là kích thước của thành viên lớn nhất, không phải tổng kích thước của tất cả các thành viên như struct.
2. **Chia sẻ vùng nhớ**: Việc thay đổi giá trị của một thành viên sẽ ảnh hưởng đến giá trị của các thành viên khác.

- **Ví dụ**
```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 220.5;
    printf("data.f = %f\n", data.f);

    // Ghi đè giá trị, dữ liệu cũ bị ảnh hưởng
    data.str[0] = 'H';
    data.str[1] = 'i';
    data.str[2] = '\0';
    printf("data.str = %s\n", data.str);

    // Giá trị của i và f sẽ không còn đúng do dùng chung vùng nhớ
    printf("data.i (invalid) = %d\n", data.i);
    printf("data.f (invalid) = %f\n", data.f);

    return 0;
}
```

- **Output của ví dụ**:
```plaintext
data.i = 10
data.f = 220.500000
data.str = Hi
data.i (invalid) = 1852400175
data.f (invalid) = 1234567890.000000
```
## 3. Ứng dung Union và Struct

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;


int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

		Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
	
    
    return 0;
}
```
- **Giải thích**: Mục đích của việc sử dụng `union` trong chương trình này là để đảm bảo rằng bất kỳ thay đổi nào trong các thành viên của `struct` cũng sẽ được phản ánh ngay lập tức trong mảng `frame[]`, và ngược lại. Điều này có nghĩa là khi thay đổi giá trị của các thành viên trong `struct`, các thay đổi này sẽ tự động được cập nhật trong mảng `frame[]` mà không cần phải thực hiện thêm bất kỳ thao tác nào.



