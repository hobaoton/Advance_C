
# BÀI 6 GOTO- SETJMP
## 1. GOTO

Trong ngôn ngữ lập trình C, `goto` là một lệnh điều khiển cho phép chương trình nhảy đến một nhãn (label) được định nghĩa trong mã nguồn. Cú pháp của `goto` như sau:

```c
goto label;
...
label:
    // code to execute
```
- **Đặc điểm khi sử dụng** `goto`:
1. **Đơn giản hóa mã nguồn**:
   - Trong một số trường hợp phức tạp, `goto` có thể giúp đơn giản hóa mã nguồn bằng cách tránh việc lồng nhau quá nhiều của các câu lệnh điều kiện hoặc vòng lặp.
2. **Thoát khỏi nhiều vòng lặp lồng nhau**:
   - `goto` có thể được sử dụng để thoát khỏi nhiều vòng lặp lồng nhau một cách nhanh chóng và dễ dàng, thay vì phải sử dụng nhiều lệnh `break` hoặc `return`.
   ```c
      for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
           if (someCondition) {
               goto endLoops;
           }
       }
   }
   endLoops:
   ```

- **Ví dụ**
```c
#include <stdio.h>

int main ()
{
    int key = 0;

    main_menu:
    do {
        printf("Nhap cac tuy chon\n");
        printf ("1...\n");
        printf ("2...\n");
        printf ("3...\n");
        scanf ("%d", &key);
    }while (key!=1);

    switch (key){
        case 1:
            printf("Nhap cac tuy chon\n");
            printf ("4...\n");
            printf ("5: ket thuc chung trinh\n");
            printf ("6: quay lai\n");
            scanf ("%d", &key);

            switch (key){
                case 4:

                case 5:
                    goto exit_program;
                case 6:
                    goto main_menu;

            }  
            break;
        case 2:
    }

    exit_program:
    return 0;
}
```
## 2. SETJMP (thu viện setjmp.h)

- **Thư viện `setjmp.h`**: trong C cung cấp các hàm `setjmp` và `longjmp` để thực hiện việc lưu và khôi phục trạng thái của chương trình, cho phép nhảy không điều kiện trong chương trình. Đây là một công cụ mạnh mẽ để xử lý ngoại lệ và khôi phục từ các lỗi trong chương trình.

- **Hàm `setjmp`**
    + **Cú pháp**: `int setjmp(jmp_buf env);`
    + **Chức năng**: Lưu trạng thái hiện tại của chương trình vào biến `env` và trả về giá trị 0 nếu được gọi lần đầu tiên. Nếu `longjmp` được gọi sau đó, `setjmp` sẽ trả về giá trị được truyền vào `longjmp`.

- **Hàm `longjmp`**
    + **Cú pháp**: `void longjmp(jmp_buf env, int val);`
    + **Chức năng**: Khôi phục trạng thái đã lưu trong `env` và tiếp tục thực thi từ vị trí mà `setjmp` đã được gọi, trả về giá trị `val`.

### Ví dụ
Dưới đây là một ví dụ minh họa cách sử dụng `setjmp` và `longjmp`:

```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf; // jmp_buf: là kiểu dữ liệu được định nghĩa sẵng trong thư viện setjmp.h
             // biến buf: được khai báo kiểu dữ liệu jmp_buf để lưu giá trị hiện tại của chương trình


int exception;

#define TRY if((exception = setjmp(buf)) == 0)
#define CATCH(x) if((exception = setjmp(buf)) == x)
#define THROW(x) longjmp(buf, x)

int main ()
{
    exception = setjmp(buf); // lưu trữ vị trí hiện tại của nó là vị trí mà dòng hiện tại đang đứng
    // exceptio = 0          // lần đầu tiên gọi hàm setjmp thì mặc định trả về số 0
    
    TRY
    {
        printf ("exception = %d\n", exception);
    } CATCH(1)
    {
        printf ("exception = %d\n", exception);
    }
    
    //longjmp(buf, 2); // khi gặp longjmp thì mặc định nhảy về vị trí setjmp
                     // giá tri lúc này setjmp(buf) == giá trị được truyền vào khi goi hàm longjmp
                     // không được truyền số 0
                     // longjmp và setjmp phải đồng bộ nhau biên mang kiểu dữ liệu jmp_buf 
    THROW(1);
    return 0;
}
```

- Ứng dụng xử lý lỗi ngoại lệ chương trình, debug chương trình.