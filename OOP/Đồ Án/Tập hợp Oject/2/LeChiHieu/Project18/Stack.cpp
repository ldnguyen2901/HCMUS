#include "Stack.h"

Stack::Stack() //khỏi tao Stack rỗng
{
	Top = NULL;
}

Stack::~Stack() //Hàm hủy Stack
{
	while (!IsEmpty())
	{
		Node* p = Top;
		Top = p->Next;
		delete p;
	}
}

int Stack::IsEmpty() // kiểm tra Stack có rỗng không
{
	if (Top == NULL)
		return 1; // rỗng trả về 1
	else return 0; // không rỗng trả về 0
}

Node* Stack::newNode(Data x) // tạo nút mới kế thừa từ lớp Stack với dữ liệu string
{
	Node* n = new Node();
	n->Info = x;
	n->Next = NULL;
	return n;
}

void Stack::Push(Data x) //thêm phần tử vào Stack
{
	Node* n = newNode(x);
	if (IsEmpty()) // nếu Stack rỗng, đỉnh sẽ mang giá trị nút n
	{
		Top = n;
	}
	else
	{
		n->Next = Top; // nếu Stack không rỗng, tăng Top lên và đỉnh Top sẽ mang giá trị nút n
		Top = n;
	}
}

int Stack::Pop(Data& x) // lấy dữ liệu tại Top và xóa dữ liệu tại Top
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		Node* n = Top;
		x = n->Info;
		Top = n->Next;
		delete n;
	}
	return 1;
}

Node* Stack::GetTop() //truy vấn đến dữ liệu tại Top (kiểu dữ liệu string)
{
	return Top;
}
