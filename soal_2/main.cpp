#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

struct Buku
{
  int id;
  std::string judul;
  std::string penulis;
  std::string tahun;
  std::string isbn;
};

void showItem(std::vector<Buku> &daftar_buku);
void findItem(std::vector<Buku> &daftar_buku);
void addItem(std::vector<Buku> &daftar_buku);
void deleteItem(std::vector<Buku> &daftar_buku);

int main(int argc, char const *argv[])
{
  std::vector<Buku> daftar_buku;

  bool is_continue = true;
  int command = 0;

  while (is_continue)
  {
    std::cout << "Daftar menu: " << std::endl;
    std::cout << "1. Lihat daftar buku" << std::endl;
    std::cout << "2. Cari buku" << std::endl;
    std::cout << "3. Tambah buku " << std::endl;
    std::cout << "4. Hapus buku " << std::endl;
    std::cout << "9. Keluar" << std::endl;
    std::cout << std::endl;
    std::cout << "Silahkan pilih menu : ";
    std::cin >> command;

    std::cin.ignore();
    std::cout << std::endl;

    switch (command)
    {
    case 1:
      showItem(daftar_buku);
      break;
    case 2:
      findItem(daftar_buku);
      break;
    case 3:
      addItem(daftar_buku);
      break;
    case 4:
      deleteItem(daftar_buku);
      break;
    case 9:
      is_continue = false;
      break;
    default:
      std::cout << "Opsi tidak valid" << std::endl;
      break;
    }
  }

  return 0;
}

void showItem(std::vector<Buku> &daftar_buku)
{
  std::cout << "Daftar Buku : " << std::endl;
  std::cout << std::left;
  std::cout << std::setw(5) << "Id";
  std::cout << std::setw(25) << "Judul";
  std::cout << std::setw(25) << "Penulis";
  std::cout << std::setw(10) << "Tahun";
  std::cout << std::setw(10) << "ISBN";
  std::cout << std::endl;

  std::cout << std::setfill('-') << std::setw(65) << "" << std::endl;
  std::cout << std::setfill(' ');

  if (daftar_buku.empty())
  {
    std::cout << "Daftar buku kosong" << std::endl;
  }
  else
  {
    for (int i = 0; i < daftar_buku.size(); i++)
    {
      std::cout << std::left;
      std::cout << std::setw(5) << daftar_buku[i].id;
      std::cout << std::setw(25) << daftar_buku[i].judul;
      std::cout << std::setw(25) << daftar_buku[i].penulis;
      std::cout << std::setw(10) << daftar_buku[i].tahun;
      std::cout << std::setw(10) << daftar_buku[i].isbn;
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "Tekan enter untuk kembali." << std::endl;
  std::cin.get();
  std::cout << std::endl;
}

void findItem(std::vector<Buku> &daftar_buku)
{
  int find_by;
  bool should_continue;

  while (!should_continue)
  {
    std::cout << "Menu pencarian:" << std::endl;
    std::cout << "1. Judul" << std::endl;
    std::cout << "2. ISBN" << std::endl;
    std::cout << "9. Batal" << std::endl;
    std::cout << "Cari berdasarkan:";
    std::cin >> find_by;

    std::cin.ignore();

    switch (find_by)
    {
    case 1:
    case 2:
    case 9:
      should_continue = true;
      break;
    default:
      std::cout << "Opsi tidak ditemukan" << std::endl;
      std::cout << std::endl;
      break;
    }
  }

  if (find_by == 9)
  {
    std::cout << std::endl;
    return;
  }

  std::string find_input;
  std::cout << "Masukkan ";
  std::cout << ((find_by == 1) ? "judul" : "ISBN") << ":";
  std::getline(std::cin, find_input);

  std::vector<Buku> filter_buku;

  for (Buku buku : daftar_buku)
  {
    size_t compare_str;

    switch (find_by)
    {
    case 1:
      compare_str = buku.judul.find(find_input);
      break;
    case 2:
      compare_str = buku.isbn.find(find_input);
      break;

    default:
      break;
    }

    if (compare_str != std::string::npos)
    {
      filter_buku.push_back(buku);
    }
  }

  if (!(filter_buku.empty()))
  {
    std::cout << std::endl;
    showItem(filter_buku);
  }
  else
  {
    std::cout << "Buku dengan ";
    std::cout << ((find_by == 1) ? "judul " : "ISBN ");
    std::cout << find_input;
    std::cout << " tidak ditemukan" << std::endl;

    std::cout << "Tekan enter untuk kembali." << std::endl;
    std::cin.get();
    std::cout << std::endl;
  }
}

void addItem(std::vector<Buku> &daftar_buku)
{
  std::string judul;
  std::string penulis;
  std::string tahun;
  std::string isbn;

  std::cout << "Tambah buku baru" << std::endl;

  std::cout << "Judul Buku : ";
  std::getline(std::cin, judul);

  std::cout << "Penulis : ";
  std::getline(std::cin, penulis);

  std::cout << "Tahun : ";
  std::cin >> tahun;

  std::cout << "ISBN : ";
  std::cin >> isbn;

  daftar_buku.push_back({(int)daftar_buku.size() + 1,
                         judul,
                         penulis,
                         tahun,
                         isbn});

  std::cout << std::endl;
  std::cout << "Buku berhasil ditambahkan." << std::endl;
  std::cout << std::endl;
}

void deleteItem(std::vector<Buku> &daftar_buku)
{
  int id;
  std::cout << "Masukkan Id buku yang ingin dihapus" << std::endl;
  std::cout << "Id : ";
  std::cin >> id;

  auto remove_data = std::remove_if(daftar_buku.begin(), daftar_buku.end(),
                                    [&id](const Buku &buku)
                                    {
                                      return buku.id == id;
                                    });

  if (remove_data != daftar_buku.end())
  {
    daftar_buku.erase(remove_data, daftar_buku.end());
    std::cout << "Buku dengan no index ";
    std::cout << id;
    std::cout << " berhasil dihapus.";
  }
  else
  {
    std::cout << "Index tidak ditemukan" << std::endl;
  }

  std::cout << std::endl;
}