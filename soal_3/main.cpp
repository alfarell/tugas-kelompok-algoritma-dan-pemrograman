#include <iostream>

void fahrenheitToCelcius()
{
  int fahrenheit;
  std::cout << "Masukkan suhu fahrenheit : ";
  std::cin >> fahrenheit;

  int toCelcius = (fahrenheit - 32) * 5 / 9;
  std::cout << fahrenheit << " Fahrenheit ke Celcius = " << toCelcius;
  std::cout << std::endl
            << std::endl;
}

void celciusToFahrenheit()
{
  int celcius;
  std::cout << "Masukkan suhu celcius : ";
  std::cin >> celcius;

  int toFahrenheit = (celcius * 9 / 5) + 32;
  std::cout << celcius << " Celcius ke Fahrenheit = " << toFahrenheit;
  std::cout << std::endl
            << std::endl;
}

int main(int argc, char const *argv[])
{
  bool is_continue = true;
  int command = 0;

  while (is_continue)
  {
    std::cout << "Pilih konversi suhu: " << std::endl;
    std::cout << "1. Fahrenheit ke Celcius" << std::endl;
    std::cout << "2. Celcius ke Fahrenheit" << std::endl;
    std::cout << "9. Keluar" << std::endl;
    std::cout << std::endl;
    std::cout << "Silahkan pilih menu : ";
    std::cin >> command;

    std::cin.ignore();
    std::cout << std::endl;

    switch (command)
    {
    case 1:
      fahrenheitToCelcius();
      break;
    case 2:
      celciusToFahrenheit();
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
