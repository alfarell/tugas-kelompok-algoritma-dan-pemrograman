#include <iostream>

struct Node
{
  int data;
  Node *next;
};

class Stack
{
private:
  Node *top;

public:
  Stack()
  {
    top = nullptr;
  }

  ~Stack()
  {
    while (!isEmpty())
    {
      pop();
    }
  }

  void push(int data)
  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;

    std::cout << std::endl;
    std::cout << "Data " << data << " berhasil ditambahkan ke stack." << std::endl;
  }

  int pop()
  {
    if (isEmpty())
    {
      std::cout << std::endl;
      std::cout << "Stack kosong, tidak dapat melakukan pop." << std::endl;
      return -1;
    }

    Node *temp = top;
    int poppedData = temp->data;
    top = top->next;
    delete temp;

    std::cout << std::endl;
    std::cout << "Data " << poppedData << " berhasil dihapus dari stack." << std::endl;

    return poppedData;
  }

  int peek()
  {
    if (isEmpty())
    {
      std::cout << std::endl;
      std::cout << "Stack kosong, tidak ada data untuk dilihat." << std::endl;
      return -1;
    }

    return top->data;
  }

  bool isEmpty()
  {
    return top == nullptr;
  }

  void display()
  {
    if (isEmpty())
    {
      std::cout << std::endl;
      std::cout << "Stack kosong." << std::endl;
      return;
    }

    Node *temp = top;

    std::cout << std::endl;
    std::cout << "Isi stack: ";

    while (temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main()
{
  Stack stack;
  int data;

  bool is_continue = true;
  int command = 0;

  while (is_continue)
  {
    std::cout << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Peek" << std::endl;
    std::cout << "4. Cek kosong" << std::endl;
    std::cout << "5. Tampilkan stack" << std::endl;
    std::cout << "9. Keluar" << std::endl;
    std::cout << "Pilih menu: ";
    std::cin >> command;
    std::cin.ignore();

    switch (command)
    {
    case 1:
      std::cout << std::endl;
      std::cout << "Masukkan data yang ingin ditambahkan: ";
      std::cin >> data;
      stack.push(data);
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      std::cout << std::endl;
      std::cout << "Data di puncak stack: " << stack.peek() << std::endl;
      break;
    case 4:
      std::cout << std::endl;
      std::cout << (stack.isEmpty() ? "Stack kosong." : "Stack tidak kosong.") << std::endl;
      break;
    case 5:
      stack.display();
      break;
    case 9:
      is_continue = false;
      break;
    default:
      std::cout << std::endl;
      std::cout << "Opsi tidak valid." << std::endl;
    }
  }

  return 0;
}