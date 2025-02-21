#include <iostream>
#include <iomanip>

struct Mahasiswa
{
  std::string nim;
  std::string nama;
  int nilai;
  char grade;
  std::string status;
};

int main(int argc, char const *argv[])
{
  const size_t data_size = 10;
  Mahasiswa data_mahasiswa[data_size];
  int num_of_data = 0;

  bool is_continue = true;
  bool should_add_data = true;

  while (is_continue)
  {
    if (should_add_data)
    {
      std::string nim;
      std::string nama;
      int nilai;

      std::cout << "Masukkan data\n";

      std::cout << "NIM : ";
      std::cin >> nim;

      std::cout << "Nama : ";
      std::cin >> nama;

      std::cout << "Nilai : ";
      std::cin >> nilai;

      char grade;
      std::string status;
      if (nilai >= 80)
      {
        grade = 'A';
        status = "Lulus";
      }
      else if (nilai < 80 && nilai >= 70)
      {
        grade = 'B';
        status = "Lulus";
      }
      else if (nilai < 70 && nilai >= 60)
      {
        grade = 'C';
        status = "Lulus";
      }
      else if (nilai < 60 && nilai >= 50)
      {
        grade = 'D';
        status = "Mengulang";
      }
      else
      {
        grade = 'E';
        status = "Tidak Lulus";
      }

      data_mahasiswa[num_of_data] = {nim, nama, nilai, grade, status};
      num_of_data++;
    }

    char user_state;

    std::cout << "\n";
    std::cout << "Ingin tambah lagi? [Y/T] : ";
    std::cin >> user_state;
    std::cout << "\n";

    switch (user_state)
    {
    case 'Y':
      is_continue = true;
      should_add_data = true;
      break;
    case 'T':
      is_continue = false;
      should_add_data = false;
      break;
    default:
      std::cout << "Opsi tidak valid." << '\n';
      is_continue = true;
      should_add_data = false;
      break;
    }
  }

  std::cout << "OUTPUT : " << '\n';
  std::cout << std::left;
  std::cout << std::setw(10) << "NIM";
  std::cout << std::setw(25) << "Nama";
  std::cout << std::setw(10) << "Nilai";
  std::cout << std::setw(10) << "Grade";
  std::cout << std::setw(10) << "Status";
  std::cout << '\n';

  std::cout << std::setfill('-') << std::setw(65) << "" << '\n';
  std::cout << std::setfill(' ');

  for (int i = 0; i < num_of_data; i++)
  {
    std::cout << std::left;
    std::cout << std::setw(10) << data_mahasiswa[i].nim;
    std::cout << std::setw(25) << data_mahasiswa[i].nama;
    std::cout << std::setw(10) << data_mahasiswa[i].nilai;
    std::cout << std::setw(10) << data_mahasiswa[i].grade;
    std::cout << std::setw(10) << data_mahasiswa[i].status;
    std::cout << '\n';
  }

  return 0;
}
