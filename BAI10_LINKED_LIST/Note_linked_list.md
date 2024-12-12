# DANH SÁCH LIÊN KẾT LINKED_LIST

## 1. Khái niệm

- **Danh sách liên kết (linked list)**: là một cấu trúc dữ liệu bao gồm 1 chuỗi các phần tử, trong đó mỗi phần tử chứa giá trị và con trỏ trỏ đến giá trị tiếp theo trong chuỗi.

- **Phần tử (Node)**: Mỗi phần tử trong danh sách liên kết được gọi là một "node". Node có địa chỉ bất kì, được cấp phát động. Mỗi node chứa hai thành phần chính:
  - **Dữ liệu (Data)**: Giá trị của phần tử. Có thể là số thực, số nguyên, chuỗi ,kí tự và cả Structm Union
  - **Con trỏ (Pointer)**: Trỏ đến phần tử tiếp theo trong danh sách. Khi khai báo là con trỏ NULL

- **Đầu danh sach (Head)**: Con trỏ trỏ đến phần tử đầu tiên trong danh sách liên kết. Nếu danh sách rỗng, head sẽ trỏ đến NULL.

- **Cuối danh sách (Tail)**: Phần tử cuối cùng trong danh sách liên kết có con trỏ trỏ đến NULL, cho biết đât là phần tử cuối cùng.

## 2. Cách khởi tạo
    ``` c
    struct Node {
        int data;
        struct Node* next;
    } Node;
    ```

## 3. Thao tác với Node

### 3.1 Thêm Node vào đầu list

**Định nghĩa hàm**
```c
void push_back(Sinh_Vien **head, int ID, char arr[]) {
    Sinh_Vien *new_Node = createNode(ID, arr);
    if (*head == NULL) {
        *head = new_Node;
    }
    Sinh_Vien *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_Node;
    new_Node->next = NULL;
}
```
**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.
   - `int ID`: ID của sinh viên mới.
   - `char arr[]`: Một mảng chứa thông tin của sinh viên.

**Tạo một nút mới**:
   - `Sinh_Vien *new_Node = createNode(ID, arr);`
   - Dòng này tạo một nút mới với ID và thông tin được cung cấp bằng cách sử dụng hàm `createNode`.

**Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { *head = new_Node; }`
   - Nếu danh sách rỗng (head là NULL), nút mới sẽ trở thành đầu của danh sách.

**Duyệt đến cuối danh sách**:
   - `Sinh_Vien *p = *head;`
     - Một con trỏ `p` được khởi tạo để trỏ đến đầu của danh sách.
   - `while (p->next != NULL) { p = p->next; }`
     - Vòng lặp này duyệt qua danh sách cho đến khi nó đến nút cuối cùng (nơi `p->next` là NULL).

**Thêm nút mới vào cuối danh sách**:
   - `p->next = new_Node;`
     - Con trỏ `next` của nút cuối cùng được đặt thành nút mới.
   - `new_Node->next = NULL;`
     - Con trỏ `next` của nút mới được đặt thành NULL, chỉ ra rằng nó bây giờ là nút cuối cùng trong danh sách.


### 3.2 Thêm Node vào cuối list

**Định nghĩa hàm**
```c
void push_front(Sinh_Vien **head, int ID, char arr[]) {
    Sinh_Vien *new_Node = createNode(ID, arr);
    new_Node->next = *head;
    *head = new_Node;
}
```
**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.
   - `int ID`: ID của sinh viên mới.
   - `char arr[]`: Một mảng chứa thông tin của sinh viên.

**Tạo một nút mới**:
   - `Sinh_Vien *new_Node = createNode(ID, arr);`
   - Dòng này tạo một nút mới với ID và thông tin được cung cấp bằng cách sử dụng hàm `createNode`.

**Liên kết nút mới với danh sách hiện tại**:
   - `new_Node->next = *head;`
   - Con trỏ `next` của nút mới được đặt thành đầu của danh sách hiện tại.

**Cập nhật đầu danh sách**:
   - `*head = new_Node;`
   - Đầu của danh sách được cập nhật để trỏ đến nút mới.


### 3.3 Thêm Node vào vị trí bất kì trong list

**Định nghĩa hàm**
```c
void insert(Sinh_Vien **head, int ID, char arr[], int position) {
    Sinh_Vien *new_Node = createNode(ID, arr);
    if (*head == NULL) {
        *head = new_Node;
    }
    Sinh_Vien *p = *head;
    int k = 0;
    while (p != NULL && k != position - 1) {
        p = p->next;
        k++;
    }
    new_Node->next = p->next;
    p->next = new_Node;
}
```

**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.
   - `int ID`: ID của sinh viên mới.
   - `char arr[]`: Một mảng chứa thông tin của sinh viên.
   - `int position`: Vị trí mà nút mới sẽ được chèn vào.

**Tạo một nút mới**:
   - `Sinh_Vien *new_Node = createNode(ID, arr);`
   - Dòng này tạo một nút mới với ID và thông tin được cung cấp bằng cách sử dụng hàm `createNode`.

**Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { *head = new_Node; }`
   - Nếu danh sách rỗng (head là NULL), nút mới sẽ trở thành đầu của danh sách.

**Duyệt đến vị trí chèn**:
   - `Sinh_Vien *p = *head;`
   - Một con trỏ `p` được khởi tạo để trỏ đến đầu của danh sách.
   - `int k = 0;`
   - Biến đếm `k` được khởi tạo để theo dõi vị trí hiện tại trong danh sách.
   - `while (p != NULL && k != position - 1) { p = p->next; k++; }`
   - Vòng lặp này duyệt qua danh sách cho đến khi nó đến vị trí chèn (position - 1).

**Chèn nút mới vào vị trí cụ thể**:
   - `new_Node->next = p->next;`
   - Con trỏ `next` của nút mới được đặt thành con trỏ `next` của nút hiện tại.
   - `p->next = new_Node;`
   - Con trỏ `next` của nút hiện tại được đặt thành nút mới.


### 3.4 Xóa Node ở đầu danh sách

**Định nghĩa hàm**
```c
void pop_front(Sinh_Vien **head) 
{ 
    if (*head == NULL) { return; } 
    Sinh_Vien *temp = *head; 
    *head = temp->next; 
    free(temp);
}
```
**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.

 **Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { return; }`
   - Nếu danh sách rỗng (head là NULL), hàm sẽ kết thúc và không làm gì cả.

**Lưu trữ nút đầu tiên**:
   - `Sinh_Vien *temp = *head;`
   - Một con trỏ `temp` được khởi tạo để trỏ đến nút đầu tiên của danh sách.

**Cập nhật đầu danh sách**:
   - `*head = temp->next;`
   - Đầu của danh sách được cập nhật để trỏ đến nút tiếp theo sau nút đầu tiên.

**Giải phóng bộ nhớ của nút đầu tiên**:
   - `free(temp);`
   - Nút đầu tiên được giải phóng khỏi bộ nhớ.


### 3.5 Xóa Node ở cuối danh sách

**Định nghĩa hàm**
```c
void pop_back(Sinh_Vien **head) {
    if (*head == NULL) { return; }
    if ((*head)->next == NULL) { *head = NULL; }

    Sinh_Vien *p = *head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}
```

**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.

**Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { return; }`
   - Nếu danh sách rỗng (head là NULL), hàm sẽ kết thúc và không làm gì cả.

**Kiểm tra xem danh sách chỉ có một nút**:
   - `if ((*head)->next == NULL) { *head = NULL; }`
   - Nếu danh sách chỉ có một nút, nút đó sẽ bị xóa và head sẽ được đặt thành NULL.

**Duyệt đến nút kế cuối**:
   - `Sinh_Vien *p = *head;`
   - Một con trỏ `p` được khởi tạo để trỏ đến đầu của danh sách.
   - `while (p->next->next != NULL) { p = p->next; }`
   - Vòng lặp này duyệt qua danh sách cho đến khi nó đến nút kế cuối (nơi `p->next->next` là NULL).

**Xóa nút cuối cùng**:
   - `free(p->next);`
   - Nút cuối cùng được giải phóng khỏi bộ nhớ.
   - `p->next = NULL;`
   - Con trỏ `next` của nút kế cuối được đặt thành NULL, chỉ ra rằng nó bây giờ là nút cuối cùng trong danh sách.


### 3.6 Xóa node ở vị trí bất kì

**Định nghĩa hàm**
```c
void delete_list(Sinh_Vien **head, int position) {
    if (*head == NULL) { return; }

    Sinh_Vien *p = *head;
    int k = 0;
    while (p->next->next != 0 && k != position - 2) {
        p = p->next;
        k++;
    }
    Sinh_Vien *i = p->next->next;
    //free(p->next);
    p->next = i;
}
```
**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.
   - `int position`: Vị trí của nút sẽ bị xóa.

**Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { return; }`
   - Nếu danh sách rỗng (head là NULL), hàm sẽ kết thúc và không làm gì cả.

**Duyệt đến vị trí trước nút cần xóa**:
   - `Sinh_Vien *p = *head;`
   - Một con trỏ `p` được khởi tạo để trỏ đến đầu của danh sách.
   - `int k = 0;`
   - Biến đếm `k` được khởi tạo để theo dõi vị trí hiện tại trong danh sách.
   - `while (p->next->next != 0 && k != position - 2) { p = p->next; k++; }`
   - Vòng lặp này duyệt qua danh sách cho đến khi nó đến vị trí trước nút cần xóa (position - 2).

**Xóa nút tại vị trí cụ thể**:
   - `Sinh_Vien *i = p->next->next;`
   - Một con trỏ `i` được khởi tạo để trỏ đến nút sau nút cần xóa.
   - `//free(p->next);`
   - Dòng này bị chú thích, nhưng nếu được kích hoạt, nó sẽ giải phóng bộ nhớ của nút cần xóa.
   - `p->next = i;`
   - Con trỏ `next` của nút hiện tại được đặt thành nút sau nút cần xóa, do đó loại bỏ nút cần xóa khỏi danh sách.


### 3.7 Kiếm tra Node có rỗng hay không

**Định nghĩa**
```c
bool empty(Sinh_Vien **head) {
    if (*head == NULL) {
        printf("danh sach rong\n");
        return true;
    } else {
        printf("danh sach co gia tri\n");
        return false;
    }
}
```

**Tham số của hàm**:
   - `Sinh_Vien **head`: Một con trỏ kép trỏ đến đầu của danh sách liên kết.

**Kiểm tra xem danh sách có rỗng không**:
   - `if (*head == NULL) { printf("danh sach rong\n"); }`
   - Nếu danh sách rỗng (head là NULL), hàm sẽ in ra thông báo "danh sach rong".
   - `else { printf("danh sach co gia tri\n"); }`
   - Nếu danh sách không rỗng, hàm sẽ in ra thông báo "danh sach co gia tri".




