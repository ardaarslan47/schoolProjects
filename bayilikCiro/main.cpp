#include "bayilik.h"

int main()
{
    std::ifstream read;
    std::ofstream write;

    bayi bayiListesi[BAYI_SAYISI];
    read.open("bayiler.dat");
    if (!read)
    {
        std::cout << "Dosya Bulunamadi";
        return -1;
    }
    

    bayiListesi->etkinlestir(read);

    read.close();
    read.clear();

    read.open("bayi_ciro.dat");
    if (!read)
    {
        std::cout << "Dosya Bulunamadi";
        return -1;
    }

    bayiListesi->verileriAl(read);

    bayiListesi->yillikCiroHesapla();

    read.close();
    read.clear();

    std::string raporDosyasi;
    std::cout << "Raporun yazilacagi dosyanin adini giriniz: ";
    std::cin >> raporDosyasi;

    write.open(raporDosyasi.c_str());
    if (!write)
    {
        std::cout << "Dosya Bulunamadi";
        return -1;
    }

    bayiListesi->raporYaz(write);
    bayiListesi->enYuksekCiro(write);

    write.close();

    return 0;
}